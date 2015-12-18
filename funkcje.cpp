#include "funkcje.h"
void DrawString(SDL_Surface *screen, int x, int y, const char *text, SDL_Surface *charset) 
{
	int px, py, c;
	SDL_Rect s, d;
	s.w = 8;
	s.h = 8;
	d.w = 8;
	d.h = 8;
	while (*text) {
		c = *text & 255;
		px = (c % 16) * 8;
		py = (c / 16) * 8;
		s.x = px;
		s.y = py;
		d.x = x;
		d.y = y;
		SDL_BlitSurface(charset, &s, screen, &d);
		x += 8;
		text++;
	};
};

void DrawSurface(SDL_Surface *screen, SDL_Surface *sprite, int x, int y) {
	SDL_Rect dest;
	dest.x = x - sprite->w / 2;
	dest.y = y - sprite->h / 2;
	dest.w = sprite->w;
	dest.h = sprite->h;
	SDL_BlitSurface(sprite, NULL, screen, &dest);
};

void DrawPixel(SDL_Surface *surface, int x, int y, Uint32 color) {
	int bpp = surface->format->BytesPerPixel;
	Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
	*(Uint32 *)p = color;
};

void DrawLine(SDL_Surface *screen, int x, int y, int l, int dx, int dy, Uint32 color) {
	for (int i = 0; i < l; i++) {
		DrawPixel(screen, x, y, color);
		x += dx;
		y += dy;
	};
};
void DrawRectangle(SDL_Surface *screen, int x, int y, int l, int k,
	Uint32 outlineColor, Uint32 fillColor) {
	int i;
	DrawLine(screen, x, y, k, 0, 1, outlineColor);
	DrawLine(screen, x + l - 1, y, k, 0, 1, outlineColor);
	DrawLine(screen, x, y, l, 1, 0, outlineColor);
	DrawLine(screen, x, y + k - 1, l, 1, 0, outlineColor);
	for (i = y + 1; i < y + k - 1; i++)
		DrawLine(screen, x + 1, i, l - 2, 1, 0, fillColor);
};
void klocekT(char tablica[10][20],int pozycja[4][2], int x, int y, char znak)
{
	tablica[x][y] = znak;
	pozycja[0][0] = x;
	pozycja[0][1] = y;
	
	tablica[x][y+1] = znak;
	pozycja[1][0] = x;
	pozycja[1][1] = y+1;

	tablica[x-1][y + 1] = znak;
	pozycja[2][0] = x-1;
	pozycja[2][1] = y + 1;

	tablica[x + 1][y + 1] = znak;
	pozycja[3][0] = x+1;
	pozycja[3][1] = y + 1;
}
void czyszczenie(char tablica[10][20], int pozycja[4][2])
{
	for (int i = 0; i < 4; i++)
		tablica[pozycja[i][0]][pozycja[i][1]] = ' ';
}
void klocekL(SDL_Surface *screen, int x, int y, int color)
{
	DrawRectangle(screen, x, y, WYMIAR, WYMIAR, color, color);
	DrawRectangle(screen, x, y + WYMIAR, WYMIAR, WYMIAR, color, color);
	DrawRectangle(screen, x, y + 2 * WYMIAR, WYMIAR, WYMIAR, color, color);
	DrawRectangle(screen, x + WYMIAR, y + 2 * WYMIAR, WYMIAR, WYMIAR, color, color);
}

bool kolizja(char tablica[10][20],int pozycja[4][2],int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		if((tablica[pozycja[i][0] + x][pozycja[i][1] + y] != ' ') &&)
			return true;
	}
	return false;
}