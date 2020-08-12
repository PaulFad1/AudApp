#include "Melody.h"

void audio_callback(void* userdata, Uint8* stream, int streamLength)
{
	AudioData& audio(*(AudioData*)userdata);
	Uint16* buffer = (Uint16*)stream;
	int length;

	length = streamLength / 2;
	length = (length > audio.length ? audio.length : length);
	for (int i = 0; i < length; i++, audio.i++)
	{
		double time = (double)audio.i / (double)(44100);
		buffer[i] = (Uint16)(28000 * sin(2 * M_PI * audio.val[audio.i] * time));

	}

	audio.length -= length;
}

Melody::Melody(Note* notes,int n)
{
	SDL_Init(SDL_INIT_AUDIO);
	freq = 44100;
	channels = 2;
	format = AUDIO_S32SYS;
	secondForOne = 8;
	callback = &audio_callback;
	noteSequence = notes;
	countOfnotes = n;
}


Melody::~Melody()
{
	//delete[] noteSequence;
}


void Melody::play()
{
	SDL_AudioSpec mel;
	SDL_zero(mel);
	mel.freq = freq;
	mel.channels = channels;
	mel.format = format;
	mel.callback = callback;
	AudioData data;
	data.i = 0;
	float durationOfMelody = 0;
	for(int i = 0; i < countOfnotes; i++)
	{
		switch(noteSequence[i].duration)
		{
		case WHOLE:
			durationOfMelody += secondForOne * freq;
			break;
		case HALF:
			durationOfMelody += (float)secondForOne / 2 * freq;
			break;
		case QUARTER:
			durationOfMelody += (float)secondForOne / 4 * freq;
			break;
		case EIGHTH:
			durationOfMelody += (float)secondForOne / 8 * freq;
			break;
		case HEX:
			durationOfMelody += (float)secondForOne / 16 * freq;
			break;
		}
	}
	data.length = (Uint32)durationOfMelody;
	Uint16* val = new Uint16[data.length];
	int start = 0;
	for(int i = 0; i < countOfnotes; i++)
	{
		float end;
		switch (noteSequence[i].duration)
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
		for(int j = start; j < start + (int)end; j++)
		{
			val[j] = (Uint16)noteSequence[i].sound;
		}
		start += (int)end;
	}

	data.val = val;
	
	mel.userdata = &data;
	int device = SDL_OpenAudio(&mel, NULL);

	SDL_PauseAudio(0);
	while (data.length > 0)
	{
		SDL_Delay(100);
	}
	SDL_CloseAudio();
	SDL_Quit();
}