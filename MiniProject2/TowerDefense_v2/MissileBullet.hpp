#ifndef MISSILEBULLET_HPP
#define MISSILEBULLET_HPP
#include "Bullet.hpp"
class MissileBullet : public Bullet {
protected:
	const float rotateRadian = 2 * ALLEGRO_PI;
	std::list<Bullet*>::iterator lockedBulletIterator;
public:
	explicit MissileBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent);
	void Update(float deltaTime) override;
	void OnExplode(Enemy* enemy) override;
};
#endif // MISSILEBULLET_HPP
