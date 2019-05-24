#include <allegro5/allegro.h>
#include "IObject.hpp"
#include "IControl.hpp"
#include "IScene.hpp"

namespace Engine {
	void IScene::Terminate() {
		Clear();
	}
	void IScene::Draw() const {
		al_clear_to_color(al_map_rgb(0, 0, 0));
		Group::Draw();
	}
}
