#include <stdio.h>
#include <string.h>
#include "SDL.h"
#include "SDL_ttf.h"

#include "functions.h"

SDL_Renderer* createDisplay(SDL_Window* window)
{
	if (TTF_Init())
	{
		printf("SDL_ttf cannot be initialized");
		return NULL;
	}
	SDL_Renderer* rendForDisp = NULL;
	SDL_CreateWindowAndRenderer(1000, 500, 0, &window, &rendForDisp);
	SDL_SetRenderDrawColor(rendForDisp, 255, 255, 255, 0);
	SDL_RenderDrawLine(rendForDisp, 200, 0, 200, 500);

	SDL_Color col_white;
	col_white.r = 255;
	col_white.g = 255;
	col_white.b = 255;
	col_white.a = 255;
	TTF_Font* font = TTF_OpenFont("CalibriRegular.ttf", 16);
	if (!font)
	{
		printf("Couldn't load font");
		return NULL;
	}

	SDL_Surface* text = TTF_RenderUTF8_Blended(font, "Points", col_white);
	SDL_Texture* textOnDisp = SDL_CreateTextureFromSurface(rendForDisp, text);
	SDL_Rect dest;

	//Tytu³
	TTF_Font* title = TTF_OpenFont("CalibriRegular.ttf", 22);
	text = TTF_RenderUTF8_Blended(title, "CHAOS GAME", col_white);
	textOnDisp = SDL_CreateTextureFromSurface(rendForDisp, text);
	dest.x = 35;
	dest.y = 25;
	SDL_QueryTexture(textOnDisp, NULL, NULL, &dest.w, &dest.h);
	SDL_RenderCopy(rendForDisp, textOnDisp, NULL, &dest);

	//Points i okolice
	text = TTF_RenderUTF8_Blended(font, "Points", col_white);
	textOnDisp = SDL_CreateTextureFromSurface(rendForDisp, text);
	dest.x = 10;
	dest.y = 100;
	SDL_QueryTexture(textOnDisp, NULL, NULL, &dest.w, &dest.h);
	SDL_RenderCopy(rendForDisp, textOnDisp, NULL, &dest);

	SDL_RenderDrawLine(rendForDisp, 65, 95, 65, 120);
	SDL_RenderDrawLine(rendForDisp, 65, 95, 85, 95);
	SDL_RenderDrawLine(rendForDisp, 85, 95, 85, 120);
	SDL_RenderDrawLine(rendForDisp, 65, 120, 85, 120);
	SDL_RenderDrawLine(rendForDisp, 95, 90, 105, 90);
	SDL_RenderDrawLine(rendForDisp, 100, 85, 100, 95);
	SDL_RenderDrawLine(rendForDisp, 95, 125, 105, 125);

	text = TTF_RenderUTF8_Blended(font, "2", col_white);
	textOnDisp = SDL_CreateTextureFromSurface(rendForDisp, text);
	dest.x = 71;
	dest.y = 101;
	SDL_QueryTexture(textOnDisp, NULL, NULL, &dest.w, &dest.h);
	SDL_RenderCopy(rendForDisp, textOnDisp, NULL, &dest);

	//Iteration i okolice
	text = TTF_RenderUTF8_Blended(font, "Iterations", col_white);
	textOnDisp = SDL_CreateTextureFromSurface(rendForDisp, text);
	dest.x = 10;
	dest.y = 175;
	SDL_QueryTexture(textOnDisp, NULL, NULL, &dest.w, &dest.h);
	SDL_RenderCopy(rendForDisp, textOnDisp, NULL, &dest);

	SDL_RenderDrawLine(rendForDisp, 90, 170, 90, 195);
	SDL_RenderDrawLine(rendForDisp, 90, 170, 160, 170);
	SDL_RenderDrawLine(rendForDisp, 160, 170, 160, 195);
	SDL_RenderDrawLine(rendForDisp, 90, 195, 160, 195);
	SDL_RenderDrawLine(rendForDisp, 170, 165, 180, 165);
	SDL_RenderDrawLine(rendForDisp, 175, 160, 175, 170);
	SDL_RenderDrawLine(rendForDisp, 170, 200, 180, 200);

	text = TTF_RenderUTF8_Blended(font, "1000", col_white);
	textOnDisp = SDL_CreateTextureFromSurface(rendForDisp, text);
	dest.x = 92;
	dest.y = 175;
	SDL_QueryTexture(textOnDisp, NULL, NULL, &dest.w, &dest.h);
	SDL_RenderCopy(rendForDisp, textOnDisp, NULL, &dest);

	//Distance
	text = TTF_RenderUTF8_Blended(font, "Distance:", col_white);
	textOnDisp = SDL_CreateTextureFromSurface(rendForDisp, text);
	dest.x = 10;
	dest.y = 225;
	SDL_QueryTexture(textOnDisp, NULL, NULL, &dest.w, &dest.h);
	SDL_RenderCopy(rendForDisp, textOnDisp, NULL, &dest);

	SDL_RenderDrawLine(rendForDisp, 10, 245, 190, 245);
	SDL_RenderDrawLine(rendForDisp, 190, 245, 190, 270);
	SDL_RenderDrawLine(rendForDisp, 10, 245, 10, 270);
	SDL_RenderDrawLine(rendForDisp, 10, 270, 190, 270);

	SDL_SetRenderDrawColor(rendForDisp, 0, 255, 0, 0);
	SDL_RenderDrawLine(rendForDisp, 70, 245, 70, 270);
	SDL_RenderDrawLine(rendForDisp, 130, 245, 130, 270);
	SDL_RenderDrawLine(rendForDisp, 70, 245, 130, 245);
	SDL_RenderDrawLine(rendForDisp, 70, 270, 130, 270);
	SDL_SetRenderDrawColor(rendForDisp, 255, 255, 255, 0);

	text = TTF_RenderUTF8_Blended(font, "1/3", col_white);
	textOnDisp = SDL_CreateTextureFromSurface(rendForDisp, text);
	dest.x = 30;
	dest.y = 251;
	SDL_QueryTexture(textOnDisp, NULL, NULL, &dest.w, &dest.h);
	SDL_RenderCopy(rendForDisp, textOnDisp, NULL, &dest);

	text = TTF_RenderUTF8_Blended(font, "1/2", col_white);
	textOnDisp = SDL_CreateTextureFromSurface(rendForDisp, text);
	dest.x = 90;
	SDL_QueryTexture(textOnDisp, NULL, NULL, &dest.w, &dest.h);
	SDL_RenderCopy(rendForDisp, textOnDisp, NULL, &dest);

	text = TTF_RenderUTF8_Blended(font, "2/3", col_white);
	textOnDisp = SDL_CreateTextureFromSurface(rendForDisp, text);
	dest.x = 150;
	SDL_QueryTexture(textOnDisp, NULL, NULL, &dest.w, &dest.h);
	SDL_RenderCopy(rendForDisp, textOnDisp, NULL, &dest);

	//Restrictions
	text = TTF_RenderUTF8_Blended(font, "Restrictions:", col_white);
	textOnDisp = SDL_CreateTextureFromSurface(rendForDisp, text);
	dest.x = 10;
	dest.y = 290;
	SDL_QueryTexture(textOnDisp, NULL, NULL, &dest.w, &dest.h);
	SDL_RenderCopy(rendForDisp, textOnDisp, NULL, &dest);

	SDL_RenderDrawLine(rendForDisp, 10, 310, 190, 310);
	SDL_RenderDrawLine(rendForDisp, 190, 310, 190, 385);
	SDL_RenderDrawLine(rendForDisp, 10, 310, 10, 385);
	SDL_RenderDrawLine(rendForDisp, 10, 385, 190, 385);
	SDL_RenderDrawLine(rendForDisp, 10, 335, 190, 335);
	SDL_RenderDrawLine(rendForDisp, 10, 360, 190, 360);

	text = TTF_RenderUTF8_Blended(font, "Without repeat recent", col_white);
	textOnDisp = SDL_CreateTextureFromSurface(rendForDisp, text);
	dest.x = 15;
	dest.y = 316;
	SDL_QueryTexture(textOnDisp, NULL, NULL, &dest.w, &dest.h);
	SDL_RenderCopy(rendForDisp, textOnDisp, NULL, &dest);

	text = TTF_RenderUTF8_Blended(font, "No neighbours", col_white);
	textOnDisp = SDL_CreateTextureFromSurface(rendForDisp, text);
	dest.y = 341;
	SDL_QueryTexture(textOnDisp, NULL, NULL, &dest.w, &dest.h);
	SDL_RenderCopy(rendForDisp, textOnDisp, NULL, &dest);

	text = TTF_RenderUTF8_Blended(font, "Points on middle of side", col_white);
	textOnDisp = SDL_CreateTextureFromSurface(rendForDisp, text);
	dest.y = 366;
	SDL_QueryTexture(textOnDisp, NULL, NULL, &dest.w, &dest.h);
	SDL_RenderCopy(rendForDisp, textOnDisp, NULL, &dest);

	//Add
	text = TTF_RenderUTF8_Blended(font, "Add", col_white);
	textOnDisp = SDL_CreateTextureFromSurface(rendForDisp, text);
	dest.x = 35;
	dest.y = 441;
	SDL_QueryTexture(textOnDisp, NULL, NULL, &dest.w, &dest.h);
	SDL_RenderCopy(rendForDisp, textOnDisp, NULL, &dest);
	SDL_RenderDrawLine(rendForDisp, 20, 435, 75, 435);
	SDL_RenderDrawLine(rendForDisp, 20, 435, 20, 460);
	SDL_RenderDrawLine(rendForDisp, 75, 435, 75, 460);
	SDL_RenderDrawLine(rendForDisp, 20, 460, 75, 460);

	//Clear
	text = TTF_RenderUTF8_Blended(font, "Clear", col_white);
	textOnDisp = SDL_CreateTextureFromSurface(rendForDisp, text);
	dest.x = 122;
	SDL_QueryTexture(textOnDisp, NULL, NULL, &dest.w, &dest.h);
	SDL_RenderCopy(rendForDisp, textOnDisp, NULL, &dest);
	SDL_RenderDrawLine(rendForDisp, 110, 435, 165, 435);
	SDL_RenderDrawLine(rendForDisp, 110, 435, 110, 460);
	SDL_RenderDrawLine(rendForDisp, 165, 435, 165, 460);
	SDL_RenderDrawLine(rendForDisp, 110, 460, 165, 460);

	SDL_RenderPresent(rendForDisp);
	SDL_FreeSurface(text);
	text = NULL;
	SDL_DestroyTexture(textOnDisp);
	TTF_CloseFont(font);
	TTF_CloseFont(title);
	return rendForDisp;
}

void changeNumber(SDL_Renderer* fieldRend, int field, int toDisplay)
{
	//clean field
	SDL_SetRenderDrawColor(fieldRend, 255, 255, 255, 0);
	SDL_Rect destCleaner;
	SDL_Rect dest;

	if (field == 1)
	{
		destCleaner.x = 66;
		destCleaner.y = 96;
		destCleaner.w = 18;
		destCleaner.h = 23;
		dest.x = 71;
		dest.y = 101;
	}
	else
	{
		destCleaner.x = 91;
		destCleaner.y = 171;
		destCleaner.w = 69;
		destCleaner.h = 24;
		dest.x = 92;
		dest.y = 175;
	}

	SDL_Surface* cleaner = SDL_CreateRGBSurface(0, 69, 24, 32, 0, 0, 0, 0);
	SDL_Texture* cleanerTexture = SDL_CreateTextureFromSurface(fieldRend, cleaner);
	SDL_RenderCopy(fieldRend, cleanerTexture, NULL, &destCleaner);
	


	if (TTF_Init())
	{
		printf("SDL_ttf cannot be initialized");
		return NULL;
	}
	TTF_Font* font = TTF_OpenFont("CalibriRegular.ttf", 16);

	SDL_Color col_white;
	col_white.r = 255;
	col_white.g = 255;
	col_white.b = 255;
	col_white.a = 255;

	char myString[6];
	sprintf(&myString, "%d", toDisplay);

	SDL_Surface* text = TTF_RenderUTF8_Blended(font, &myString, col_white);
	SDL_Texture* textOnDisp = SDL_CreateTextureFromSurface(fieldRend, text);
	SDL_QueryTexture(textOnDisp, NULL, NULL, &dest.w, &dest.h);
	SDL_RenderCopy(fieldRend, textOnDisp, NULL, &dest);

	SDL_FreeSurface(cleaner);
	SDL_DestroyTexture(cleanerTexture);

	SDL_RenderPresent(fieldRend);
	SDL_DestroyTexture(textOnDisp);
	SDL_FreeSurface(text);
	TTF_CloseFont(font);
}

void clearDisplay(SDL_Renderer* dispRend)
{
	SDL_Rect dest;
	dest.x = 201;
	dest.y = 0;
	dest.w = 799;
	dest.h = 500;
	SDL_Surface* cleaner = SDL_CreateRGBSurface(0, 799, 500, 32, 0, 0, 0, 0);
	SDL_Texture* cleanerTexture = SDL_CreateTextureFromSurface(dispRend, cleaner);
	SDL_RenderCopy(dispRend, cleanerTexture, NULL, &dest);

	SDL_RenderPresent(dispRend);
	SDL_FreeSurface(cleaner);
	SDL_DestroyTexture(cleanerTexture);
}

void drawPixel(SDL_Renderer* rend, int x, int y, int r, int g, int b)
{
	SDL_SetRenderDrawColor(rend, r, g, b, 0);
	SDL_RenderDrawPoint(rend, x, y);
	SDL_RenderPresent(rend);
}

void backlightDistance(SDL_Renderer* renderer, int option)
{
	SDL_Rect rect;
	rect.w = 61;
	rect.h = 26;
	rect.y = 245;
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
	SDL_RenderDrawLine(renderer, 10, 245, 190, 245);
	SDL_RenderDrawLine(renderer, 190, 245, 190, 270);
	SDL_RenderDrawLine(renderer, 10, 245, 10, 270);
	SDL_RenderDrawLine(renderer, 10, 270, 190, 270);
	SDL_RenderDrawLine(renderer, 70, 245, 70, 270);
	SDL_RenderDrawLine(renderer, 130, 245, 130, 270);

	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
	switch (option)
	{
	case 1: rect.x = 10; break;
	case 2: rect.x = 70; break;
	case 3: rect.x = 130; break;
	}
	SDL_RenderDrawRect(renderer, &rect);
	SDL_RenderPresent(renderer);
}

void backlightRestriction(SDL_Renderer* renderer, int option, bool current, bool prev, bool next)
{
	SDL_Rect rect;
	rect.x = 10;
	rect.w = 181;
	rect.h = 26;
	switch (option)
	{
	case 1: rect.y = 310; break;
	case 2: rect.y = 335; break;
	case 3: rect.y = 360; break;
	}
	if (!current)
	{
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);;
		SDL_RenderDrawRect(renderer, &rect);
	}
	else
	{
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		SDL_RenderDrawRect(renderer, &rect);
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
		if (prev == current)
			SDL_RenderDrawLine(renderer, 10, rect.y, 190, rect.y);
		if (current == next)
			SDL_RenderDrawLine(renderer, 10, rect.y + 25, 190, rect.y + 25);
	}
	SDL_RenderPresent(renderer);
}