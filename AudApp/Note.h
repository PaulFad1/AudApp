#pragma once
enum Sound
{
	C = 261,
	D = 293,
	E = 329,
	F = 349,
	G = 391,
	A = 440,
	B = 493,
	C2 = 523,
	D2 = 587,
	E2 = 659
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
