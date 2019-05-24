#ifndef LASERBULLET_HPP
#define LASERBULLET_HPP
#include "Bullet.hpp"
class LaserBullet : public Bullet {
public:
	explicit LaserBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent);
	void OnExplode(Enemy* enemy) override;
};
#endif // LASERBULLET_HPP
