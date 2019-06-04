#ifndef AUDIOHELPER_HPP
#define AUDIOHELPER_HPP
#include <allegro5/allegro_audio.h>
#include <string>


class AudioHelper {
private:
	AudioHelper() = default;
public:
	static float BGMVolume;
	static float SFXVolume;
	static ALLEGRO_SAMPLE_ID PlayAudio(const std::string& audio);
	static ALLEGRO_SAMPLE_ID PlayBGM(const std::string& audio);
	static void StopBGM(ALLEGRO_SAMPLE_ID sample);
};
#endif // AUDIOHELPER_HPP
