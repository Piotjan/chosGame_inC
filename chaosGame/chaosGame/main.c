#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include "SDL.h"

#include "display.h"
#include"functions.h"

int main(int argc, char* argv[])
{
	int points = 2;
	int iterations = 1000;
	float distance = 0.5;
	bool restrictions[3] = { false, false, false };
	if (SDL_Init(SDL_INIT_VIDEO))
	{
		printf("SDL_INIT_VIDEO cannot be initialized");
		return 1;
	}
	srand(time(NULL));
	SDL_Window* window = NULL;
	SDL_Renderer* mainRend = NULL;
	bool toClose = false;
	mainRend = createDisplay(&window);
	//nadanie kolorów
	int pointsCoordinates[13][6] =
	{
		//{x, y, rmask, gmask, bmask, neighbourhood}
		{600, 1, 0, 255, 0, 1},		//green
		{600, 498, 255, 0, 0, 2},		//red
		{0, 0, 0, 0, 255, 0},		//blue
		{0, 0, 255, 255, 255, 0},	//white
		{0, 0, 255, 140, 0, 0},		//orange
		{0, 0, 128, 0, 128, 0},		//purple
		{0, 0, 255, 255, 0, 0},		//yellow
		{0, 0, 51, 255, 255, 0},	//turkus
		{0, 0, 178, 102, 255, 0},	//lila
		{0, 0, 148, 240, 55, 0},	//another green
		{0, 0, 230, 155, 132, 0},	//skinny
		{0, 0, 72, 176, 255, 0},	//blue as sky
		{0, 0, 0, 0, 0, 0}
	};


	while (!toClose)
	{
		toClose = getMouse(mainRend, &points, &iterations, &distance, restrictions, pointsCoordinates);
	}

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(mainRend);
	SDL_Quit();
	return 0;
}