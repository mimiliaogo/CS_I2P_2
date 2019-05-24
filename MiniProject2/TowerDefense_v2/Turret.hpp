#ifndef TURRET_HPP
#define TURRET_HPP
#include "Sprite.hpp"
#include "PlayScene.hpp"
#include "Enemy.hpp"
#include "Bullet.hpp"

class PlayScene;
class Bullet;
class Enemy;
class Turret: public Engine::Sprite {
protected:
    int price;
    float coolDown;
    float reload = 0;
    float rotateRadian = 2 * ALLEGRO_PI;
    Sprite imgBase;
    std::list<Turret*>::iterator lockedTurretIterator;
    PlayScene* getPlayScene();
    virtual void CreateBullet() = 0;

public:
    bool Enabled = true;
    bool Preview = false;
    Enemy* Target = nullptr;
    Turret(std::string imgBase, std::string imgTurret, float x, float y, float radius, int price, float coolDown);
    void Update(float deltaTime) override;
    void Draw() const override;
	int GetPrice() const;
    // Reference: Design Patterns - Factory Method.
};
#endif // TURRET_HPP
