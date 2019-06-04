#ifndef PLANE_HPP
#define PLANE_HPP
#include <allegro5/bitmap.h>
#include <memory>
#include <vector>

#include "Sprite.hpp"

class PlayScene;

class Plane : public Engine::Sprite {
protected:
	PlayScene* getPlayScene();
	const float timeSpanLight = 1;
	const float timeSpanShockwave = 1;
	const float shockWaveRadius = 180;
	const float minScale = 1.0f / 8;
	const float maxScale = 8;
	int stage;
	float timeTicks;
	float scale;
	std::vector<std::shared_ptr<ALLEGRO_BITMAP>> bmps;
	std::shared_ptr<ALLEGRO_BITMAP> shockwave;
public:
	Plane();
	void Update(float deltaTime) override;
	void Draw() const override;
};
#endif // PLANE_HPP
