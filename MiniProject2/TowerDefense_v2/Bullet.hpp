#ifndef BULLET_HPP
#define BULLET_HPP
#include "Sprite.hpp"
#include "Collider.hpp"
#include "Enemy.hpp"
#include "Turret.hpp"
#include <random>

class PlayScene;
class Enemy;
class Turret;
class Bullet : public Engine::Sprite {
protected:
	float speed;
	float damage;
	Turret* parent;
	PlayScene* getPlayScene();
	virtual void OnExplode(Enemy* enemy);
public:
	Enemy* Target = nullptr;
	explicit Bullet(std::string img, float speed, float damage, Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent);
	void Update(float deltaTime) override;
};
#endif // BULLET_HPP
