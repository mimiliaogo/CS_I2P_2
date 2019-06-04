#include <allegro5/base.h>
#include <random>
#include <string>

#include "Point.hpp"
#include "TankEnemy.hpp"

TankEnemy::TankEnemy(int x, int y) : Enemy("play/enemy-3.png", x, y, 20, 20, 100, 50),
head("play/enemy-3-head.png", x, y), targetRotation(0) {
}
void TankEnemy::Draw() const {
	Enemy::Draw();
	head.Draw();
}
void TankEnemy::Update(float deltaTime) {
	Enemy::Update(deltaTime);
	head.Position = Position;
	// Choose arbitrary one.
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_real_distribution<> dist(0.0f, 4.0f);
	float rnd = dist(rng);
	if (rnd < deltaTime) {
		// Head arbitrary rotation.
		std::uniform_real_distribution<> distRadian(-ALLEGRO_PI, ALLEGRO_PI);
		targetRotation = distRadian(rng);
	}
	head.Rotation = (head.Rotation + deltaTime * targetRotation) / (1 + deltaTime);
}
