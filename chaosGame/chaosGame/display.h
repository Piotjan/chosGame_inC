/** @file */

#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdio.h>
#include "SDL.h"

/**Funkcja tworzy ekran aplikacji orazwyświetla na nim elementy interfejsu graficznego
@param[in] window wskaźnik biblioteki SDL przekazujacy informacje dot. okna aplikacji
@result Funkcja zwraca wskażnik na strukturę biblioteki SDL konfigurującą, wyświetlanie w istniejącym oknie
*/
SDL_Renderer* createDisplay(SDL_Window* window);

/** Funkcja odpowiada za zmianę wyświetlanych liczb w polach "Points" oraz "Iterations"
@param[in] fieldRend wskażnik na strukturę biblioteki SDL, konfigurującą wyświetlanie w istniejącym oknie
@param[in] field zmienna wskazująca, które pole należy zmienić
@param[in] toDisplay zmienna przekazującą liczbę do wyświetlenia
*/
void changeNumber(SDL_Renderer* fieldRend, int field, int toDisplay);

/**Funkcja czyszcząca częśc ekranu, na której wyświetlają się figury
@param[in] dispRend wskażnik na strukturę biblioteki SDL konfigurującą, wyświetlanie w istniejącym oknie
*/
void clearDisplay(SDL_Renderer* dispRend);

/**Funkcja odpowiada za renderowanie pixeli we wskazanym miejscu o wybranym kolorze
@param[in, out] rend wskażnik na strukturę biblioteki SDL konfigurującą wyświetlanie w istniejącym oknie
@param[in] x wspólrzędna x, na której ma zostać wyświetlony piksel
@param[in] y wspólrzędna y, na której ma zostać wyświetlony piksel
@param[in] r maska koloru czerownego do formatu RGB
@param[in] g maska koloru zielonego  do formatu RGB
@param[in] b maska koloru niebieskiego do formatu RGB
*/
void drawPixel(SDL_Renderer* rend, int x, int y, int r, int g, int b);

/**Funkcja zmienia kolor obwódki przycisku "Distance" po wybraniu jednego z nich
@param[in] renderer wskażnik na strukturę biblioteki SDL, konfigurującą wyświetlanie w istniejącym oknie
@param[in] option zmienna przekazująca informację, który przycisk został wybrany przez użytkowanika
*/
void backlightDistance(SDL_Renderer* renderer, int option);

/**Funkcja zmienia kolor obwódki przycisku "Restriction" po wybraniu jednego z nich
@param[in] renderer wskażnik na strukturę biblioteki SDL, konfigurującą wyświetlanie w istniejącym oknie
@param[in] option zmienna przekazująca informację, który przycisk został wybrany przez użytkowanika
@param[in] current przekazuje stan wybrane przycisku (włączony/wyłączony)
@param[in] prev przekazuje stan przycisku nad przyciskiem wybranym (włączony/wyłączony)
@param [in] next przekazuje stan przycisku nad przyciskiem wybranym (włączony/wyłączony)
*/
void backlightRestriction(SDL_Renderer* renderer, int option, bool current, bool prev, bool next);

#endif // !DISPLAY_H
