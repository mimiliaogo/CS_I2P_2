#ifndef LASERTURRET_HPP
#define LASERTURRET_HPP
#include "PlayScene.hpp"
#include "Bullet.hpp"
#include "Turret.hpp"

class PlayScene;
class LaserTurret: public Turret {
public:
	static const int Price;
    LaserTurret(float x, float y);
    void CreateBullet() override;
};
#endif // LASERTURRET_HPP
