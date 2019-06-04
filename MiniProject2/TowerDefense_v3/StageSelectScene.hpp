#ifndef STAGESELECTSCENE_HPP
#define STAGESELECTSCENE_HPP
#include <allegro5/allegro_audio.h>
#include "IScene.hpp"

class StageSelectScene final : public Engine::IScene {
private:
	ALLEGRO_SAMPLE_INSTANCE* bgmInstance;
public:
	explicit StageSelectScene() = default;
	void Initialize() override;
	void PlayOnClick(int stage);
	void BGMSlideOnValueChanged(float value);
	void SFXSlideOnValueChanged(float value);
};

#endif // STAGESELECTSCENE_HPP
