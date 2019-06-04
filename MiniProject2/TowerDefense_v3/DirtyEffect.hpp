#ifndef DIRTYEFFECT_HPP
#define DIRTYEFFECT_HPP
#include <string>

#include "Sprite.hpp"

class PlayScene;

class DirtyEffect : public Engine::Sprite {
protected:
	float timeSpan;
	float alpha;
	PlayScene* getPlayScene();
public:
	DirtyEffect(std::string img, float timeSpan, float x, float y);
	void Update(float deltaTime) override;
};
#endif // DIRTYEFFECT_HPP
