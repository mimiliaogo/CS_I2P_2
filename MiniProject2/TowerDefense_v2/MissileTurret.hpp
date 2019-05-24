#ifndef MISSILETURRET_HPP
#define MISSILETURRET_HPP
#include "PlayScene.hpp"
#include "Bullet.hpp"
#include "Turret.hpp"

class PlayScene;
class MissileTurret: public Turret {
public:
	static const int Price;
    MissileTurret(float x, float y);
    void CreateBullet() override;
};
#endif // MISSILETURRET_HPP
