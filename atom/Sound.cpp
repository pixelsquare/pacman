#include "Sound.h"
using namespace SoundLib::Library;

Sound::Sound() { this->mute = false; }

Sound::~Sound() { }

Sound* sound = new Sound;
void Sound::Play(LPCSTR name) {
	if(!sound->mute) PlaySound(name, NULL, SND_ASYNC|SND_FILENAME);
}

void Sound::PlayLoop(LPCSTR name) {
	if(!sound->mute) PlaySound(name, NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}

void Sound::Stop() {
	if(!sound->mute) PlaySound(NULL, 0, 0);
}

void Sound::Mute(bool Mute) {
	sound->mute = Mute;
}