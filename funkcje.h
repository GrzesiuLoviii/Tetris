#ifndef funkcje_H
#define funkcje_H

#define _USE_MATH_DEFINES
#include<math.h>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<ctime>
#include<string>

extern "C" {
	//#ifdef BIT64
	//#include"./sdl64/include/SDL.h"
	//#include"./sdl64/include/SDL_main.h"
	//#else
#include"./sdl/include/SDL.h"
#include"./sdl/include/SDL_main.h"
	//#endif
}

using namespace std;

#define SCREEN_WIDTH	400
#define SCREEN_HEIGHT	600
#define CZAS_OPADANIA 0.2
#define WYMIAR 15
#define PLANSZA_X 12
#define PLANSZA_Y 22
#define PRZYSPIESZENIE 0.01
#define ILOSC_ETAPOW 10
#define CZAS_ETAPU 25
#define ILOSC_WYNIKOW 1

// narysowanie napisu txt na powierzchni screen, zaczynaj¹c od punktu (x, y)
// charset to bitmapa 128x128 zawieraj¹ca znaki
void DrawString(SDL_Surface *screen, int x, int y, const char *text, SDL_Surface *charset);
// narysowanie na ekranie screen powierzchni sprite w punkcie (x, y)
// (x, y) to punkt œrodka obrazka sprite na ekranie
void DrawSurface(SDL_Surface *screen, SDL_Surface *sprite, int x, int y);
// rysowanie pojedynczego pixela
void DrawPixel(SDL_Surface *surface, int x, int y, Uint32 color);
// rysowanie linii o d³ugoœci l w pionie (gdy dx = 0, dy = 1) 
// b¹dŸ poziomie (gdy dx = 1, dy = 0)
void DrawLine(SDL_Surface *screen, int x, int y, int l, int dx, int dy, Uint32 color);
// rysowanie prostok¹ta o d³ugoœci boków l i k
void DrawRectangle(SDL_Surface *screen, int x, int y, int l, int k, Uint32 outlineColor, Uint32 fillColor);
void klocekT(char tablica[PLANSZA_X][PLANSZA_Y],int pozycja[4][2], int x, int y, char znak, int *obrot);
void klocekL(char tablica[PLANSZA_X][PLANSZA_Y], int pozycja[4][2], int x, int y, char znak, int *obrot);
void klocekJ(char tablica[PLANSZA_X][PLANSZA_Y], int pozycja[4][2], int x, int y, char znak, int *obrot);
void klocekI(char tablica[PLANSZA_X][PLANSZA_Y], int pozycja[4][2], int x, int y, char znak, int *obrot);
void klocekO(char tablica[PLANSZA_X][PLANSZA_Y], int pozycja[4][2], int x, int y, char znak, int *obrot);
void klocekS(char tablica[PLANSZA_X][PLANSZA_Y], int pozycja[4][2], int x, int y, char znak, int *obrot);
void klocekZ(char tablica[PLANSZA_X][PLANSZA_Y], int pozycja[4][2], int x, int y, char znak, int *obrot);
void czyszczenie(char tablica[PLANSZA_X][PLANSZA_Y], int pozycja[4][2], char znak=' ');
bool kolizja(char tablica[PLANSZA_X][PLANSZA_Y], int pozycja[4][2], int x = 0, int y = 0);
void przesuniecie(char tablica[PLANSZA_X][PLANSZA_Y], int pozycja[4][2], int *pozycja_x, int x);
void sprawdz(char tablica[PLANSZA_X][PLANSZA_Y], int *punkty, int etap, int *poprzednie);
#endif