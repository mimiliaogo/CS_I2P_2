#include <allegro5/allegro.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <chrono>
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>

#include "Allegro5Exception.hpp"
#include "GameEngine.hpp"
#include "IScene.hpp"
#include "LOG.hpp"
#include "Point.hpp"
#include "Resources.hpp"

namespace Engine {
	void GameEngine::initAllegro5() {
		if (!al_init()) throw Allegro5Exception("failed to initialize allegro");

		// Initialize add-ons.
		if (!al_init_primitives_addon()) throw Allegro5Exception("failed to initialize primitives add-on");
		al_init_font_addon();
		// Use the code below if you're using a newer version or Allegro5, the code above is for compatibility.
		//if (!al_init_font_addon()) throw Allegro5Exception("failed to initialize font add-on");
		if (!al_init_ttf_addon()) throw Allegro5Exception("failed to initialize ttf add-on");
		if (!al_init_image_addon()) throw Allegro5Exception("failed to initialize image add-on");
		if (!al_install_audio()) throw Allegro5Exception("failed to initialize audio add-on");
		if (!al_init_acodec_addon()) throw Allegro5Exception("failed to initialize audio codec add-on");
		if (!al_reserve_samples(reserveSamples)) throw Allegro5Exception("failed to reserve samples");
		// Can initialize other add-ons here, such as video, ...
		// Install peripherals.
		if (!al_install_keyboard()) throw Allegro5Exception("failed to install keyboard");
		if (!al_install_mouse()) throw Allegro5Exception("failed to install mouse");

		// Setup game display.
		display = al_create_display(screenW, screenH);
		if (!display) throw Allegro5Exception("failed to create display");
		al_set_window_title(display, title);
		// Set alpha blending mode.
		al_set_blender(ALLEGRO_ADD, ALLEGRO_ALPHA, ALLEGRO_INVERSE_ALPHA);

		// Load and set window icon.
		if (icon) {
			static std::shared_ptr<ALLEGRO_BITMAP> iconReference = Resources::GetInstance().GetBitmap(icon);
			al_set_display_icon(display, iconReference.get());
			LOG(INFO) << "Loaded window icon from: " << icon;
		}

		// Setup update timer.
		update_timer = al_create_timer(1.0f / fps);
		if (!update_timer) throw Allegro5Exception("failed to create timer");

		// Setup event queue.
		event_queue = al_create_event_queue();
		if (!event_queue) throw Allegro5Exception("failed to create event queue");

		// Check how many mouse buttons are supported.
		const unsigned m_buttons = al_get_mouse_num_buttons();
		LOG(INFO) << "There are total " << m_buttons << " supported mouse buttons";

		// Register display, timer, keyboard, mouse events to the event queue.
		al_register_event_source(event_queue, al_get_display_event_source(display));
		al_register_event_source(event_queue, al_get_timer_event_source(update_timer));
		al_register_event_source(event_queue, al_get_keyboard_event_source());
		al_register_event_source(event_queue, al_get_mouse_event_source());
		// Can register other event sources, such as timer, video, ...

		// Start the timer to update and draw the game.
		al_start_timer(update_timer);
	}
	void GameEngine::startEventLoop() {
		bool done = false;
		ALLEGRO_EVENT event;
		int redraws = 0;
		auto timestamp = std::chrono::steady_clock::now();
		while (!done) {
			al_wait_for_event(event_queue, &event);
			switch (event.type) {
			case ALLEGRO_EVENT_DISPLAY_CLOSE:
				// Event for clicking the window close button.
				LOG(VERBOSE) << "Window close button clicked";
				done = true;
				break;
			case ALLEGRO_EVENT_TIMER:
				// Event for redrawing the display.
				if (event.timer.source == update_timer)
					// The redraw timer has ticked.
					redraws++;
				break;
			case ALLEGRO_EVENT_KEY_DOWN:
				// Event for keyboard key down.
				LOG(VERBOSE) << "Key with keycode " << event.keyboard.keycode << " down";
				activeScene->OnKeyDown(event.keyboard.keycode);
				break;
			case ALLEGRO_EVENT_KEY_UP:
				// Event for keyboard key up.
				LOG(VERBOSE) << "Key with keycode " << event.keyboard.keycode << " up";
				activeScene->OnKeyUp(event.keyboard.keycode);
				break;
			case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
				// Event for mouse key down.
				LOG(VERBOSE) << "Mouse button " << event.mouse.button << " down at (" << event.mouse.x << ", " << event.mouse.y << ")";
				activeScene->OnMouseDown(event.mouse.button, event.mouse.x, event.mouse.y);
				break;
			case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
				// Event for mouse key up.
				LOG(VERBOSE) << "Mouse button " << event.mouse.button << " down at (" << event.mouse.x << ", " << event.mouse.y << ")";
				activeScene->OnMouseUp(event.mouse.button, event.mouse.x, event.mouse.y);
				break;
			case ALLEGRO_EVENT_MOUSE_AXES:
				if (event.mouse.dx != 0 || event.mouse.dy != 0) {
					// Event for mouse move.
					LOG(VERBOSE) << "Mouse move to (" << event.mouse.x << ", " << event.mouse.y << ")";
					activeScene->OnMouseMove(event.mouse.x, event.mouse.y);
				}
				else if (event.mouse.dz != 0) {
					// Event for mouse scroll.
					LOG(VERBOSE) << "Mouse scroll at (" << event.mouse.x << ", " << event.mouse.y << ") with delta " << event.mouse.dz;
					activeScene->OnMouseScroll(event.mouse.x, event.mouse.y, event.mouse.dz);
				}
				break;
			case ALLEGRO_EVENT_MOUSE_LEAVE_DISPLAY:
				LOG(VERBOSE) << "Mouse leave display.";
				ALLEGRO_MOUSE_STATE state;
				al_get_mouse_state(&state);
				// Fake mouse out.
				activeScene->OnMouseMove(-1, -1);
				break;
			case ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY:
				LOG(VERBOSE) << "Mouse enter display.";
				break;
			default:
				// Ignore events that we're not interested in.
				break;
			}
			// Can process more events and call callbacks by adding more cases.

			// Redraw the scene.
			if (redraws > 0 && al_is_event_queue_empty(event_queue)) {
				if (redraws > 1)
					LOG(VERBOSE) << redraws - 1 << " frame(s) dropped";
				// Calculate the timeElapsed and update the timestamp.
				auto nextTimestamp = std::chrono::steady_clock::now();
				std::chrono::duration<float> timeElapsed = nextTimestamp - timestamp;
				timestamp = nextTimestamp;
				// Update and draw the next frame.
				update(timeElapsed.count());
				draw();
				redraws = 0;
			}
		}
	}
	void GameEngine::update(float deltaTime) {
		if (!nextScene.empty()) {
			changeScene(nextScene);
			nextScene = "";
		}
		activeScene->Update(deltaTime);
	}
	void GameEngine::draw() const {
		activeScene->Draw();
		al_flip_display();
	}
	void GameEngine::destroy() {
		// Destroy allegro5 window resources.
		al_destroy_timer(update_timer);
		al_destroy_event_queue(event_queue);
		al_destroy_display(display);
		// Free all scenes.
		for (const auto &pair : scenes)
			delete pair.second;
	}
	void GameEngine::changeScene(const std::string& name) {
		if (scenes.count(name) == 0)
			throw std::invalid_argument("Cannot change to a unknown scene.");
		// Terminate the old scene.
		activeScene->Terminate();
		activeScene = scenes[name];
		// Release unused resources.
		Resources::GetInstance().ReleaseUnused();
		// Initialize the new scene.
		activeScene->Initialize();
		LOG(INFO) << "Changed to " << name << " scene";
	}
	void GameEngine::Start(const std::string& firstSceneName, int fps, int screenW, int screenH,
		int reserveSamples, const char* title, const char* icon) {
		LOG(INFO) << "Game Initializing...";
		// Update Allegro5 configs.
		this->fps = fps;
		this->screenW = screenW;
		this->screenH = screenH;
		this->reserveSamples = reserveSamples;
		this->title = title;
		this->icon = icon;
		if (scenes.count(firstSceneName) == 0)
			throw std::invalid_argument("The scene is not added yet.");
		activeScene = scenes[firstSceneName];

		initAllegro5();
		LOG(INFO) << "Allegro5 initialized";
		LOG(INFO) << "Game begin";

		activeScene->Initialize();
		LOG(INFO) << "Game initialized";
		// Draw the first frame.
		draw();
		LOG(INFO) << "Game start event loop";
		// This call blocks until the game is finished.
		startEventLoop();
		LOG(INFO) << "Game Terminating...";
		activeScene->Terminate();
		LOG(INFO) << "Game terminated";
		LOG(INFO) << "Game end";
		destroy();
	}
	void GameEngine::AddNewScene(const std::string& name, IScene* scene) {
		if (scenes.count(name) != 0)
			throw std::invalid_argument("Cannot add scenes with the same name.");
		scenes[name] = scene;
	}
	void GameEngine::ChangeScene(const std::string& name) {
		nextScene = name;
	}
	IScene* GameEngine::GetActiveScene() const {
		return activeScene;
	}
	IScene* GameEngine::GetScene(const std::string& name) {
		if (scenes.count(name) == 0)
			throw std::invalid_argument("Cannot get scenes that aren't added.");
		return scenes[name];
	}
	Point GameEngine::GetScreenSize() const {
		return Point(screenW, screenH);
	}
	int GameEngine::GetScreenWidth() const {
		return screenW;
	}
	int GameEngine::GetScreenHeight() const {
		return screenH;
	}
	Point GameEngine::GetMousePosition() const {
		ALLEGRO_MOUSE_STATE state;
		al_get_mouse_state(&state);
		return Point(state.x, state.y);
	}
	bool GameEngine::IsKeyDown(int keyCode) const {
		ALLEGRO_KEYBOARD_STATE state;
		al_get_keyboard_state(&state);
		return al_key_down(&state, keyCode);
	}
	GameEngine& GameEngine::GetInstance() {
		// The classic way to lazy initialize a Singleton.
		static GameEngine instance;
		return instance;
	}
}
