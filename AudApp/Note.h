#pragma once
enum Sound
{

	A_BIG = 110,
	C_LIT = 130,
	Csh_LIT = 138,
	D_LIT = 146,
	E_LIT = 164,
	F_LIT = 174,
	G_LIT = 196,
	A_LIT = 220,
	B_LIT = 246,
	PAUSE = 0,
	C = 261,
	Csh = 277,
	D = 293,
	E = 329,
	F = 349,
	G = 391,
	A_BEM = 415,
	A = 440,
	B_BEM = 466,
	B = 493,
	C2 = 523,
	C2sh = 554,
	D2 = 587,
	E2 = 659,
	F2 = 698
};


enum Duration
{
	WHOLE,
	HALF,
	QUARTER,
	EIGHTH,
	HEX
};

struct Note
{
	Sound sound;
	Duration duration;
};

struct Channel
{
	Note* notes;
	int countOfnotes;
};