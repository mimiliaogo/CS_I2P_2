#ifndef FIREBULLET_HPP
#define FIREBULLET_HPP
#include "Bullet.hpp"
class FireBullet : public Bullet {
public:
	explicit FireBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent);
	void OnExplode(Enemy* enemy) override;
};
#endif // FIREBULLET_HPP
