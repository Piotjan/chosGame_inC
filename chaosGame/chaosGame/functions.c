#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "SDL.h"

#include "display.h"

int random(int maxValue)
{
	int value = rand();
	value = value % maxValue;
	return value;
}

int whichButton(int mouseX, int mouseY)
{
	int buttons[12][4] = {
		//{x1, x2, y1, y2}
		{95, 105, 85, 95},		//"+" Points
		{95, 105, 120, 130},	//"-" Points
		{170, 180, 160, 170},	//"+" Iterations
		{170, 180, 195, 205},	//"-" Iterations
		{11, 69, 246, 269},		//1/3
		{71, 129, 246, 269},	//1/2
		{131, 189, 246, 269},	//2/3
		{11, 189, 311, 334},	//1. rest
		{11, 189, 336, 359},	//2. rest
		{11, 189, 361, 384},	//3. rest
		{20, 75, 435, 460},		//"Add"
		{110, 165, 435, 460}	//"Clear"
	};

	for (int i = 0; i < 12; i++)
	{
		if (mouseX >= buttons[i][0] && mouseX <= buttons[i][1] && mouseY >= buttons[i][2] && mouseY <= buttons[i][3])
			return i;
	}
	return 12;
}

void setMiddlePoints(int points, int pointsCords[13][6])
{
	for (int i = 0; i < points-1; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (pointsCords[i][j] > pointsCords[i+1][j])
				pointsCords[i+points][j] = pointsCords[i][j] - (pointsCords[i][j] - pointsCords[i+1][j]) / 2;
			else
				pointsCords[i+points][j] = pointsCords[i][j] + (pointsCords[i+1][j] - pointsCords[i][j]) / 2;
		}
	}

	pointsCords[(points * 2) - 1][0] = pointsCords[0][0] - (pointsCords[0][0] - pointsCords[points-1][0]) / 2;
	pointsCords[(points * 2) - 1][1] = pointsCords[0][1] + (pointsCords[points - 1][1] - pointsCords[0][1]) / 2;
}

void setNeighbourhood(int points, int pointsCords[13][6], bool restriction3)
{
		if (restriction3)
		{
			for (int i = 0; i < points; i++)
			{
				pointsCords[i][5] = (2 * i) + 1;
				pointsCords[i + points][5] = (2 * i) + 2;
			}
			pointsCords[2 * points][5] = 0;
		}
		else
		{
			for (int i = 0; i < points; i++)
			{
				pointsCords[i][5] = i + 1;
			}
			pointsCords[points][5] = 0;
		}
}

void setStart(SDL_Renderer* renderer, int points, int pointsCords[13][6], bool restrictions[3])
{
	clearDisplay(renderer);
	//ustawienie wspó³rzêdnych punktów startowych
	switch (points)
	{
	case 2:
	{
		pointsCords[0][0] = 600;
		pointsCords[0][1] = 1;		//A
		pointsCords[1][0] = 600;
		pointsCords[1][1] = 498;	//B
		pointsCords[12][0] = 0;
		pointsCords[12][1] = 0;
		break;
	}
	case 3:
	{
		pointsCords[0][0] = 600;
		pointsCords[0][1] = 1;		//A
		pointsCords[1][0] = 889;
		pointsCords[1][1] = 498;	//B
		pointsCords[2][0] = 311;
		pointsCords[2][1] = 498;	//C
		pointsCords[12][0] = 0;
		pointsCords[12][1] = 0;
		break;
	}
	case 4:
	{
		pointsCords[0][0] = 600;
		pointsCords[0][1] = 1;		//A
		pointsCords[1][0] = 849;
		pointsCords[1][1] = 255;	//B
		pointsCords[2][0] = 600;
		pointsCords[2][1] = 498;	//C
		pointsCords[3][0] = 351;
		pointsCords[3][1] = 255;	//D
		pointsCords[12][0] = 0;
		pointsCords[12][1] = 0;
		break;
	}
	case 5:
	{
		pointsCords[0][0] = 600;
		pointsCords[0][1] = 1;		//A
		pointsCords[1][0] = 850;
		pointsCords[1][1] = 180;	//B
		pointsCords[2][0] = 767;
		pointsCords[2][1] = 498;	//C
		pointsCords[3][0] = 434;
		pointsCords[3][1] = 498;	//D
		pointsCords[4][0] = 328;
		pointsCords[4][1] = 180;		//E
		pointsCords[12][0] = 0;
		pointsCords[12][1] = 0;
		break;
	}
	case 6:
	{
		pointsCords[0][0] = 742;
		pointsCords[0][1] = 2;		//A
		pointsCords[1][0] = 890;
		pointsCords[1][1] = 250;	//B
		pointsCords[2][0] = 745;
		pointsCords[2][1] = 498;	//C
		pointsCords[3][0] = 455;
		pointsCords[3][1] = 498;	//D
		pointsCords[4][0] = 310;
		pointsCords[4][1] = 250;	//E
		pointsCords[5][0] = 455;
		pointsCords[5][1] = 2;		//F
		pointsCords[12][0] = 0;
		pointsCords[12][1] = 0;
	}
	default: break;
	}	
	if (restrictions[1])
		setNeighbourhood(points, pointsCords, restrictions[2]);
}

void setActive(int pointsCords[13][6], int startPoint, float distance)
{
	for (int i = 0; i < 2; i++)
	{
		if (pointsCords[startPoint][i] > pointsCords[12][i])
			pointsCords[12][i] = pointsCords[12][i] - (pointsCords[12][i] - pointsCords[startPoint][i]) * distance;
		else
			pointsCords[12][i] = pointsCords[12][i] + (pointsCords[startPoint][i] - pointsCords[12][i]) * distance;
	}
	for (int i=2;i<5;i++)
	{
		pointsCords[12][i] = pointsCords[startPoint][i];
	}
}

bool ifNeighbour(int current, int last, int pointsCords[13][6])
{
	if (pointsCords[current][5] == pointsCords[last][5] + 1 || pointsCords[current][5] == pointsCords[last][5] - 1)
		return true;
	else if (pointsCords[current + 1][5] == 0 && pointsCords[last][5] == 1)
		return true;
	else if ((pointsCords[last + 1][5] == 0 && pointsCords[current][5] == 1))
		return true;
	else
		return false;
}

void apply(SDL_Renderer* renderer, int iterations, int points, float distance, bool restrictions[3], int pointsCords[13][6])
{
	if (pointsCords[12][0] == 0)
	{
		for (int i = 0; i < 2; i++)
		{
			pointsCords[12][i] = pointsCords[0][i] - ((pointsCords[points-1][i] - pointsCords[0][i]) * distance);
		}

		for (int i = 2; i < 5; i++)
		{
			pointsCords[12][i] = pointsCords[12][i];
		}
		drawPixel(renderer, pointsCords[12][0], pointsCords[12][1], pointsCords[12][2], pointsCords[12][3], pointsCords[12][4]);
	}
	int restrictedRandom;
	int last = 1;
	for (int i = 0; i < iterations; i++)
	{
		if (restrictions[0])
		{
			do
			{
				restrictedRandom = random(points);
			} while (restrictedRandom == last);

		}
		else
		{
			restrictedRandom = random(points);
		}
		
		if (restrictions[1])
		{
			while (ifNeighbour(restrictedRandom, last, pointsCords))
			{
				restrictedRandom = random(points);
			}
		}
		setActive(pointsCords, restrictedRandom, distance);
		last = restrictedRandom;
		drawPixel(renderer, pointsCords[12][0], pointsCords[12][1], pointsCords[12][2], pointsCords[12][3], pointsCords[12][4]);
	}
}

void action(int option, int* points, int* iterations, float* distance, bool restrictions[3], SDL_Renderer* renderer, int pointCords[13][6])
{
	switch (option)
	{
	//"+" Points
	case 0:
	{
		if (*points < 6)
		{
			*points = *points + 1;
			changeNumber(renderer, 1, *points);
			setStart(renderer, *points, pointCords, restrictions);
			if (restrictions[2])
				setMiddlePoints(*points, pointCords);
		}
		break;
	}
	//"-" Points
	case 1: 
	{
		if (*points > 2)
		{
			*points = *points - 1;
			changeNumber(renderer, 1, *points);
			setStart(renderer, *points, pointCords, restrictions);
			if (restrictions[2])
				setMiddlePoints(*points, pointCords);
		}
		break;
	}
	//"+" Iterations
	case 2:
	{
		if (*iterations < 10000)
		{
			*iterations = *iterations + 1000;
			changeNumber(renderer, 2, *iterations);
		}		
		break;
	}
	//"-" Iterations
	case 3:
	{
		if (*iterations > 1000)
		{
			*iterations = *iterations - 1000;
			changeNumber(renderer, 2, *iterations);
		}
		break;
	}
	//1/3
	case 4:
	{
		backlightDistance(renderer, 1);
		clearDisplay(renderer);
		*distance = 0.33;
		break;
	}
	//1/2
	case 5:
	{
		backlightDistance(renderer, 2);
		clearDisplay(renderer);
		*distance = 0.5;
		break;
	}
	//2/3
	case 6:
	{
		backlightDistance(renderer, 3);
		clearDisplay(renderer);
		*distance = 0.66;
		break;
	}
	//rest 1
	case 7:
	{
		backlightRestriction(renderer, 1, restrictions[0], !restrictions[0], restrictions[1]);
		restrictions[0] = !restrictions[0];
		break;
	}
	//rest 2
	case 8:
	{
		backlightRestriction(renderer, 2, restrictions[1], restrictions[0], restrictions[2]);
		restrictions[1] = !restrictions[1];
		
		if (restrictions[1])
			setNeighbourhood(*points, pointCords, restrictions[2]);
		break;
	}
	//rest 3
	case 9:
	{
		backlightRestriction(renderer, 3, restrictions[2], restrictions[1], !restrictions[2]);
		restrictions[2] = !restrictions[2];
		if (restrictions[2])
		{
			setMiddlePoints(*points, pointCords);
		}
		if (restrictions[1])
			setNeighbourhood(*points, pointCords, restrictions[2]);
		break;
	}
	//Add
	case 10:
	{
		if(restrictions[2])
			apply(renderer, *iterations, (*points)*2, *distance, restrictions, pointCords);
		else
			apply(renderer, *iterations, *points, *distance, restrictions, pointCords);
		
		break;
	}
	//Clear
	case 11: 
	{
		clearDisplay(renderer);
		break;
	}
	default: break;
	}
}

bool getMouse(SDL_Renderer* renderer, int* points, int* iterations, float* distance, int restrictions[3], int pointsCords[13][6])
{
	if (SDL_Init(SDL_INIT_EVENTS))
	{
		printf("SDL_EVENTS cannot be initialized");
		return true;
	}

	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case(SDL_QUIT):
		return true;
	case(SDL_MOUSEBUTTONDOWN):
	{
		action(whichButton(event.button.x, event.button.y), points, iterations, distance, restrictions,  renderer, pointsCords);
		return false;
	}
	default:
		return false;
	}
}