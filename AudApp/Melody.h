#pragma once
#include <SDL.h>
#include "Note.h"
class Melody
{
private:
	int freq;
	int channels;
	int secondForOne;
	SDL_AudioFormat format;
	SDL_AudioCallback callback;
	Note* noteSequence;
	int countOfnotes;
public:
	Melody(Note* notes, int n);
	~Melody();
	void play();
};

struct AudioData
{
	Uint16* val;
	Uint32 length;
	int i;
};