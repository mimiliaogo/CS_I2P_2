#ifndef WINSCENE_HPP
#define WINSCENE_HPP
#include "IScene.hpp"

class WinScene final : public Engine::IScene {
private:
	float ticks;
public:
	explicit WinScene() = default;
	void Initialize() override;
	void Update(float deltaTime) override;
	void BackOnClick(int stage);
};

#endif // WINSCENE_HPP
