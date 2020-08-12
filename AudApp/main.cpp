#include <iostream>
#include "Melody.h"
using namespace std;
#undef main

int main()
{
	Note notes[20] = { {G,QUARTER}, {G,QUARTER}, {G,QUARTER}, {C2,HEX}, {B,HEX}, {A,HEX},
	{G,HEX},{F,QUARTER},{D2,QUARTER}, {F,HALF}, {E,QUARTER}, {E,QUARTER},{E,QUARTER},
	{A,HEX},{G,HEX},{F,HEX},{E,HEX},{D,QUARTER},{A,QUARTER},{D,QUARTER} };
	Melody melody(notes, 20);

	melody.play();

	return 0;
}/*{G,QUARTER}, {G,QUARTER}, {G,QUARTER}, {C2,HEX}, {B,HEX}, {A,HEX},
	{G,HEX},{F,QUARTER},{D2,QUARTER}, {F,HALF}, {E,QUARTER}, {E,QUARTER},{E,QUARTER},
	{A,HEX},{G,HEX},{F,HEX},{E,HEX},{D,QUARTER},{A,QUARTER},{D,QUARTER}*/
	
	
	
	//{B,QUARTER}, {E2,QUARTER},{B,QUARTER}, {C2,EIGHTH},{D2,EIGHTH},
	//{D2,QUARTER},{A,QUARTER},{B,HALF}, {B,EIGHTH},{E2,EIGHTH},{B,EIGHTH},{C2,EIGHTH},
	//{D2,EIGHTH},{D2,EIGHTH},{C2,EIGHTH},{B,EIGHTH},{C2,EIGHTH},{D2,EIGHTH},{C2,EIGHTH},
	//{A,EIGHTH},{B,HALF}