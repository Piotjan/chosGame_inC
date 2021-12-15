/**@file*/
#ifndef FUNCIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdbool.h>
#include "SDL.h"

/**Funkcja generuje pseudolosową liczbę
@param[in] maxValue maksymalna wartość, jaka może zostaś wylosowana
@result wylosowana liczba
*/
int random(int maxValue);

/**Funkcja określa, który przycisk został wybrany przez użytkownika
@param[in] mouseX współrzędne X kursora
@param[in] mouseY współrzędne Y kursora
@result liczba infomrująca, który przycisk zostal wybrany
*/
int whichButton(int mouseX, int mouseY);

/**Funkcja wyznacza i przypisuje współrzędne punktom znajdującym się w połowie odległości między bazowymi punktami startowymi
@param[in] points zmienna przekazująca informację, ile punktów poczatkowych jest obacnie wybranych
@param[in][out] pointsCords tablica z danymi punktów początkowych (współrzędne, kolor, sąsiedztwo)
*/
void setMiddlePoints(int points, int pointsCords[13][6]);

/**Funkcja ustala, które z punktów startowych sąsiadują ze sobą
@param[in] points zmienna przekazująca informację, ile punktów poczatkowych jest obacnie wybranych
@param[in][out] pointsCords tablica z danymi punktów początkowych (współrzędne, kolor, sąsiedztwo)
@param[in] restriction3 zmienna informująca, czy poza głównymi punktami startowymi, wyznaczone są równiez te w połowie odległości między nimi
*/
void setNeighbourhood(int points, int pointsCords[13][6], bool restriction3);

/**Funkcja przypisuje współrzene poszczególnym punktom startowym, w zależności od wyboru użytkownika
@param renderer wskażnik na strukturę biblioteki SDL konfigurującą wyświetlanie w istniejącym oknie
@param[in] points zmienna wskazująca ilość punktów startowych wybranych przez użytkownika
@param[out] pointsCords tablica z danymi punktów początkowych (współrzędne, kolor, sąsiedztwo)
@param[in] restrictions tablica z obostrzeniami, co do wyznaczania punktów początkowych oraz punktu aktywnego, wybranych przez użytkownika
*/
void setStart(SDL_Renderer* renderer, int points, int pointsCords[13][6], bool restrictions[3]);

/**Funkcja wyznacza współrzedne nowego punktu
@param[in][out] pointsCords tablica z danymi punktów początkowych (współrzędne, kolor, sąsiedztwo)
@param[in] startPoint zmienna przekazuje informacje, który z punktów startowych ma być wykorzystany podczas obliczeń
*/
void setActive(int pointsCords[13][6], int startPoint, float distance);

/**Funkcja sprawdza, czy nowo wylosowany punkt nie znajduje się w sąsiedztwie z poprzednim
@param[in] current numer nowo wylosowanego punktu
@param[in] last numer poprezdniego punktu
@param[in] pointsCords tablica z danymi punktów początkowych (współrzędne, kolor, sąsiedztwo)
@result informacja, czy punkty ze sobą sąsiadują
*/
bool ifNeighbour(int current, int last, int pointsCords[13][6]);

/**Funkcja przekazuje odpowiednie dane, potrzbne do narysowania nowego punktu
@param renderer wskażnik na strukturę biblioteki SDL konfigurującą wyświetlanie w istniejącym oknie
@param[in] iterations zmienna wskazuje, ile punktów należy narysować
@param[in] points zmienna wskazuje, ile punktów początkowych wybrał użytkownik
@param distance wskaźnik na zmienną z informacją, w jakiej odległości od punktu początkowego ma zostać ustanowiony nowy punkt
@param[in] restrictions tablica z obostrzeniami, co do wyznaczania punktów początkowych oraz punktu aktywnego, wybranych przez użytkownika
@param[in] pointsCords tablica z danymi punktów początkowych (współrzędne, kolor, sąsiedztwo)
*/
void apply(SDL_Renderer* renderer, int iterations, int points, float distance, bool restrictions[3], int pointsCords[13][6]);

/**Funkcja koordynuje działanie programu. Inicjuje kolejnoość wykonywania poszczególnych funkcji w zależności od wyboru użytkownika
@param[in] option zmienna przekazująca, który z przyciskow wybrał użytkownik
@param points wskaźnik na zmienną określającą ilość punktów początkowych wybraną przez użytkownika
@param iterations wskaźnik na zmienną określającą, ile punktów należy dodać
@param distance wskaźnik na zmienną z informacją, w jakiej odległości od punktu początkowego ma zostać ustanowiony nowy punkt
@param[in][out] restrictions tablica z obostrzeniami, co do wyznaczania punktów początkowych oraz punktu aktywnego, wybranych przez użytkownika
@param renderer wskażnik na strukturę biblioteki SDL konfigurującą wyświetlanie w istniejącym oknie
@param pointCords tablica z danymi punktów początkowych (współrzędne, kolor, sąsiedztwo)
*/
void action(int option, int* points, int* iterations, float* distance, bool restrictions[3], SDL_Renderer* renderer, int pointCords[13][6]);

/**Funkcja sprawdza aktywność myszy, poczym zwraca informaję, czy program ma dzialać dalej
@param renderer wskażnik na strukturę biblioteki SDL konfigurującą wyświetlanie w istniejącym oknie
@param points wskaźnik na zmienną określającą ilość punktów początkowych wybraną przez użytkownika
@param iterations wskaźnik na zmienną określającą, ile punktów należy dodać
@param distance wskaźnik na zmienną z informacją, w jakiej odległości od punktu początkowego ma zostać ustanowiony nowy punkt
@param restrictions tablica z obostrzeniami, co do wyznaczania punktów początkowych oraz punktu aktywnego, wybranych przez użytkownika
@param pointCords tablica z danymi punktów początkowych (współrzędne, kolor, sąsiedztwo)
@result informacja, czy użytkwonik wybrał zkończenie programu
*/
bool getMouse(SDL_Renderer* renderer, int* points, int* iterations, float* distance, bool restrictions[3], int pointsCords[13][6]);

#endif