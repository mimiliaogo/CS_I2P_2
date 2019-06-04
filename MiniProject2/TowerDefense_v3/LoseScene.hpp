#ifndef LOSESCENE_HPP
#define LOSESCENE_HPP
#include "IScene.hpp"

class LoseScene final : public Engine::IScene {
public:
	explicit LoseScene() = default;
	void Initialize() override;
	void BackOnClick(int stage);
};

#endif // LOSESCENE_HPP
