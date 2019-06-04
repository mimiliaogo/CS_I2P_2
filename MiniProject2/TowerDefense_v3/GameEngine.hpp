#ifndef GAMEENGINE_HPP
#define GAMEENGINE_HPP
#include <allegro5/allegro.h>
#include <unordered_map>
#include <string>

#include "Point.hpp"

/// <summary>
/// All general classes are under this namespace for clarity.
/// </summary>
namespace Engine {
	class IScene;
	/// <summary>
	/// The one and only GameEngine for the entire program. Responsible for low-level initialization and window events.
	/// </summary>
	class GameEngine final {
	private:
		// Allegro5 settings, frames per second, screen width, screen height, maximum simultaneous audio samples.
		int fps{}, screenW{}, screenH{}, reserveSamples{};
		// All scenes are stored in hash table for easy access.
		// Reference: Data Structure - Hash table
		std::unordered_map<std::string, IScene*> scenes;
		// The active scene that occupies the game's update, draw and various events.
		IScene* activeScene{};
		// Allegro5 display for window creation.
		ALLEGRO_DISPLAY* display{};
		// Allegro5 event queue.
		ALLEGRO_EVENT_QUEUE* event_queue{};
		// Allegro5 timer to inject update & draw event into the event queue.
		ALLEGRO_TIMER* update_timer{};
		// The window's title text.
		const char* title{};
		// The window's icon.
		const char* icon{};
		// The scene to change to at next update.
		std::string nextScene{};

		/// <summary>
		/// Initialize allegro5 library. Creates game window & event queue,
		/// install peripherals and initialize add-ons.
		/// </summary>
		void initAllegro5();
		/// <summary>
		/// Process events inside the event queue using an infinity loop,
		/// exit when close button clicked.
		/// </summary>
		void startEventLoop();
		/// <summary>
		/// Delegate the update event to the active scene.
		/// </summary>
		/// <param name="deltaTime">Time elapsed since last update, can be used to calculate value changes.</param>
		void update(float deltaTime);
		/// <summary>
		/// Delegate the draw event to the active scene.
		/// </summary>
		void draw() const;
		/// <summary>
		/// Release Allegro5 resources, and free all allocated scenes.
		/// </summary>
		void destroy();
		/// <summary>
		/// Private constructor since this class is a Singleton.
		/// Note: Singleton is a class that will only be instantiated once (single instance).
		/// Reference: Design Patterns - Singleton.
		/// </summary>
		explicit GameEngine() = default;
		/// <summary>
		/// Change to another scene. Must return immediately and stop using anything initialized in
		/// the scene. Since this call destroys everything initialized.
		/// </summary>
		/// <param name="name">The name of the scene you want to change to.</param>
		void changeScene(const std::string& name);
	public:
		// Note: We'll ignore C++11's move constructor, move assignment operator in this project for simplicity.
		/// <summary>
		/// Copy constructor is deleted, no copying allowed.
		/// </summary>
		GameEngine(GameEngine const&) = delete;
		/// <summary>
		/// Copy assignment operator is deleted, no copy assignment allowed.
		/// </summary>
		GameEngine& operator=(GameEngine const&) = delete;
		/// <summary>
		/// Start the game loop until exit, scenes should be added before starting.
		/// </summary>
		/// <param name="firstSceneName">The scene name of the first scene of the game.</param>
		/// <param name="fps">The target frame per seconds of the game.</param>
		/// <param name="screenW">Window screen width.</param>
		/// <param name="screenH">Window screen height.</param>
		/// <param name="reserveSamples">Maximum simultaneous audio samples.</param>
		/// <param name="title">Window's title text.</param>
		/// <param name="icon">Window's icon image path.</param>
		void Start(const std::string& firstSceneName, int fps = 60, int screenW = 800, int screenH = 600, int reserveSamples = 10,
				   const char* title = "Tower Defense (I2P(II)_2019 Mini Project 2))",
				   const char* icon = "icon.png");
		/// <summary>
		/// Add a new scene to the game. Should only be called once for each scene.
		/// Use inline-new when adding scene in order to support polymorphism,
		/// The added scenes will be deleted by GameEngine at game end.
		/// </summary>
		/// <param name="name">The unique name of your scene for later access.</param>
		/// <param name="scene">The pointer to the scene you want to add.</param>
		void AddNewScene(const std::string& name, IScene* scene);
		/// <summary>
		/// Change to another scene. The scene will be changed at next update.
		/// </summary>
		/// <param name="name">The name of the scene you want to change to.</param>
		void ChangeScene(const std::string& name);
		/// <summary>
		/// Get the pointer of the active scene.
		/// </summary>
		/// <returns>Pointer to active scene.</returns>
		IScene* GetActiveScene() const;
		/// <summary>
		/// Get scene by name.
		/// </summary>
		/// <param name="name">The scene's name.</param>
		/// <returns>Pointer to scene.</returns>
		IScene* GetScene(const std::string& name);
		/// <summary>
		/// Get screen size.
		/// </summary>
		/// <returns>Screen size.</returns>
		Point GetScreenSize() const;
		/// <summary>
		/// Get screen width.
		/// </summary>
		/// <returns>Screen width.</returns>
		int GetScreenWidth() const;
		/// <summary>
		/// Get screen height.
		/// </summary>
		/// <returns>Screen height.</returns>
		int GetScreenHeight() const;
		/// <summary>
		/// Get mouse position.
		/// </summary>
		/// <returns>Get mouse position.</returns>
		Point GetMousePosition() const;
		/// <summary>
		/// Get key state.
		/// </summary>
		/// <returns>Returns whether key is down or not.</returns>
		bool IsKeyDown(int keyCode) const;
		/// <summary>
		/// Typical function to retrieve Singleton instance and supports lazy initialization.
		/// </summary>
		/// <returns>The Singleton instance of GameEngine.</returns>
		static GameEngine& GetInstance();
	};
}
#endif // GAMEENGINE_HPP
