#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "GameEngine.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Sprite.hpp"
#include "Turret.hpp"

class Turret;
class PlayScene;
class Bullet;
class Enemy : public Engine::Sprite {
protected:
 	std::vector<Engine::Point> path;
	float speed;
	float hp;
	int money;
	PlayScene* getPlayScene();
	virtual void OnExplode();
public:
	std::list<Turret*> lockedTurrets;
	std::list<Bullet*> lockedBullets;
	Enemy(std::string img, float x, float y, float radius, float speed, float hp, int money);
 	void Hit(float damage);
	void UpdatePath(const std::vector<std::vector<int>>& mapDistance);
	void Update(float deltaTime) override;
	void Draw() const override;
};
#endif // ENEMY_HPP
