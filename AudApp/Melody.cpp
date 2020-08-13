#include "Melody.h"
#include <vector>


Uint16 audio_transform(int j, int n)
{
	Uint16 res;

	double time = (double)j / (double)(44100);
	res = (Uint16)(28000 * sin(2 * M_PI * n * time));
	
	return res;
}

Melody::Melody(Channel* c,int n)
{
	SDL_Init(SDL_INIT_AUDIO);
	Mix_Init(MIX_INIT_FLAC | MIX_INIT_MID | MIX_INIT_MP3);
	freq = 44100;
	channels = 2;
	format = AUDIO_F32SYS;
	secondForOne = 8;
	chan = c;
	countOfChannels = n;
}


Melody::~Melody()
{
	//delete[] noteSequence;
}


void Melody::play()
{

	std::vector<float> durationOfMelody(2);
	durationOfMelody[0] = 0;
	durationOfMelody[1] = 0;
	Mix_OpenAudio(freq, MIX_DEFAULT_FORMAT, channels, 2048);
	for (int k = 0; k < countOfChannels; k++) {
		for (int i = 0; i < chan[0].countOfnotes; i++)
		{
			switch (chan[k].notes[i].duration)
			{
			case WHOLE:
				durationOfMelody[k] += secondForOne * freq;
				break;
			case HALF:
				durationOfMelody[k] += (float)secondForOne / 2 * freq;
				break;
			case QUARTER:
				durationOfMelody[k] += (float)secondForOne / 4 * freq;
				break;
			case EIGHTH:
				durationOfMelody[k]+= (float)secondForOne / 8 * freq;
				break;
			case HEX:
				durationOfMelody[k] += (float)secondForOne / 16 * freq;
				break;
			}
		}
	}
	float res;
	if (durationOfMelody[0] >= durationOfMelody[1])
		res = durationOfMelody[0];
	else
		res = durationOfMelody[1];
	std::vector<Uint16*> data_channels(countOfChannels);
	for(int i = 0 ; i < countOfChannels; i++)
	{
		data_channels[i] = new Uint16[(Uint32)res];
	}
	
	for (int k = 0; k < countOfChannels; k++) 
	{
		int start = 0;
		for (int i = 0; i < chan[k].countOfnotes; i++)
		{
			float end;
			switch (chan[k].notes[i].duration)
			{
			case WHOLE:
				end = secondForOne * freq;
				break;
			case HALF:
				end = (float)secondForOne / 2 * freq;
				break;
			case QUARTER:
				end = (float)secondForOne / 4 * freq;
				break;
			case EIGHTH:
				end = (float)secondForOne / 8 * freq;
				break;
			case HEX:
				end = (float)secondForOne / 16 * freq;
				break;
			}
			for (int j = start; j < start + (int)end; j++)
			{
				data_channels[k][j] = audio_transform(j,chan[k].notes[i].sound);
			}
			start += (int)end;
		}
	}
	Mix_Chunk** audio = new Mix_Chunk*[countOfChannels];
	for(int i = 0; i < countOfChannels; i++)
	{
		audio[i] = Mix_QuickLoad_RAW((Uint8*)data_channels[i], res);
		Mix_PlayChannel(-1, audio[i] , 0);
	}
	while (Mix_Playing(-1));

	Mix_CloseAudio();
	Mix_FreeChunk(audio[0]);
	SDL_Quit();
}