#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include "Note.h"
class Melody
{
private:
	int freq;
	int channels;
	int secondForOne;
	SDL_AudioFormat format;
	SDL_AudioCallback callback;
	Channel* chan;
	int countOfChannels;
public:
	Melody(Channel* c,int n);
	~Melody();
	void play();
};