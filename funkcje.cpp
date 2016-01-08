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
void klocekT(char tablica[PLANSZA_X][PLANSZA_Y],int pozycja[4][2], int x, int y, char znak,int *obrot)
{
	if(pozycja[0][0]!=0)
		czyszczenie(tablica, pozycja);
	switch (*obrot)
	{
	case 0:
		if(tablica[x-1][y] == ' ' && tablica[x+1][y] == ' ')
		{
			//1
			tablica[x][y] = znak;
			pozycja[0][0] = x;
			pozycja[0][1] = y;
			//2
			tablica[x][y - 1] = znak;
			pozycja[1][0] = x;
			pozycja[1][1] = y - 1;
			//3
			tablica[x - 1][y] = znak;
			pozycja[2][0] = x - 1;
			pozycja[2][1] = y;
			//4
			tablica[x + 1][y] = znak;
			pozycja[3][0] = x + 1;
			pozycja[3][1] = y;
		}
		else
		{
			*obrot = 3;
			klocekT(tablica, pozycja, x, y, znak, obrot);
		}
		break;
	case 1:
		if (tablica[x][y + 1] == ' ')
		{
			//1
			tablica[x][y] = znak;
			pozycja[0][0] = x;
			pozycja[0][1] = y;
			//2
			tablica[x][y - 1] = znak;
			pozycja[1][0] = x;
			pozycja[1][1] = y - 1;
			//3
			tablica[x][y + 1] = znak;
			pozycja[2][0] = x;
			pozycja[2][1] = y + 1;
			//4
			tablica[x + 1][y] = znak;
			pozycja[3][0] = x + 1;
			pozycja[3][1] = y;
		}
		else
		{
			*obrot=0;
			klocekT(tablica, pozycja, x, y, znak, obrot);
		}
		break;
	case 2:
		if (tablica[x-1][y] == ' ')
		{
			//1
			tablica[x][y] = znak;
			pozycja[0][0] = x;
			pozycja[0][1] = y;
			//2
			tablica[x - 1][y] = znak;
			pozycja[1][0] = x - 1;
			pozycja[1][1] = y;
			//3
			tablica[x][y + 1] = znak;
			pozycja[2][0] = x;
			pozycja[2][1] = y + 1;
			//4
			tablica[x + 1][y] = znak;
			pozycja[3][0] = x + 1;
			pozycja[3][1] = y;
		}
		else
		{
			*obrot = 1;
			klocekT(tablica, pozycja, x, y, znak, obrot);
		}
		break;
	case 3:
		if (tablica[x][y-1] == ' ')
		{
			//1
			tablica[x][y] = znak;
			pozycja[0][0] = x;
			pozycja[0][1] = y;
			//2
			tablica[x - 1][y] = znak;
			pozycja[1][0] = x - 1;
			pozycja[1][1] = y;
			//3
			tablica[x][y + 1] = znak;
			pozycja[2][0] = x;
			pozycja[2][1] = y + 1;
			//4
			tablica[x][y - 1] = znak;
			pozycja[3][0] = x;
			pozycja[3][1] = y - 1;
		}
		else
		{
			*obrot = 2;
			klocekT(tablica, pozycja, x, y, znak, obrot);
		}
		break;
	}
}
void klocekL(char tablica[PLANSZA_X][PLANSZA_Y], int pozycja[4][2], int x, int y, char znak, int *obrot)
{
	if (pozycja[0][0] != 0)
		czyszczenie(tablica, pozycja);

	switch (*obrot)
	{
	case 0:
		if (tablica[x - 1][y] == ' ' && tablica[x + 1][y] == ' ' && tablica[x + 1][y - 1] == ' ')
		{
			//1
			tablica[x][y] = znak;
			pozycja[0][0] = x;
			pozycja[0][1] = y;
			//2
			tablica[x - 1][y] = znak;
			pozycja[1][0] = x - 1;
			pozycja[1][1] = y;
			//3
			tablica[x + 1][y] = znak;
			pozycja[2][0] = x + 1;
			pozycja[2][1] = y;
			//4
			tablica[x + 1][y - 1] = znak;
			pozycja[3][0] = x + 1;
			pozycja[3][1] = y - 1;
		}
		else
		{
			*obrot = 3;
			klocekL(tablica, pozycja, x, y, znak, obrot);
		}
		break;
	case 1:
		if (tablica[x][y - 1] == ' ' && tablica[x][y + 1] == ' ' && tablica[x + 1][y + 1] == ' ')
		{
			//1
			tablica[x][y] = znak;
			pozycja[0][0] = x;
			pozycja[0][1] = y;
			//2
			tablica[x][y - 1] = znak;
			pozycja[1][0] = x;
			pozycja[1][1] = y - 1;
			//3
			tablica[x][y + 1] = znak;
			pozycja[2][0] = x;
			pozycja[2][1] = y + 1;
			//4
			tablica[x + 1][y + 1] = znak;
			pozycja[3][0] = x + 1;
			pozycja[3][1] = y + 1;
		}
		else
		{
			*obrot = 0;
			klocekL(tablica, pozycja, x, y, znak, obrot);
		}
		break;
	case 2:
		if (tablica[x+1][y] == ' ' && tablica[x-1][y + 1] == ' ' && tablica[x-1][y] == ' ')
		{
			//1
			tablica[x][y] = znak;
			pozycja[0][0] = x;
			pozycja[0][1] = y;
			//2
			tablica[x + 1][y] = znak;
			pozycja[1][0] = x + 1;
			pozycja[1][1] = y;
			//3
			tablica[x - 1][y] = znak;
			pozycja[2][0] = x - 1;
			pozycja[2][1] = y;
			//4
			tablica[x - 1][y + 1] = znak;
			pozycja[3][0] = x - 1;
			pozycja[3][1] = y + 1;
		}
		else
		{
			*obrot = 1;
			klocekL(tablica, pozycja, x, y, znak, obrot);
		}
		break;
	case 3:
		if (tablica[x - 1][y-1] == ' ' && tablica[x][y + 1] == ' ' && tablica[x][y - 1] == ' ')
		{
			//1
			tablica[x][y] = znak;
			pozycja[0][0] = x;
			pozycja[0][1] = y;
			//2
			tablica[x][y + 1] = znak;
			pozycja[1][0] = x;
			pozycja[1][1] = y + 1;
			//3
			tablica[x][y-1] = znak;
			pozycja[2][0] = x;
			pozycja[2][1] = y-1;
			//4
			tablica[x - 1][y - 1] = znak;
			pozycja[3][0] = x - 1;
			pozycja[3][1] = y - 1;
		}
		else
		{
			*obrot = 2;
			klocekL(tablica, pozycja, x, y, znak, obrot);
		}
		break;
	}
}
void klocekJ(char tablica[PLANSZA_X][PLANSZA_Y], int pozycja[4][2], int x, int y, char znak, int *obrot)
{
	if (pozycja[0][0] != 0)
		czyszczenie(tablica, pozycja);

	switch (*obrot)
	{
	case 0:
		if (tablica[x - 1][y] == ' ' && tablica[x + 1][y] == ' ' && tablica[x - 1][y - 1] == ' ')
		{
			//1
			tablica[x][y] = znak;
			pozycja[0][0] = x;
			pozycja[0][1] = y;
			//2
			tablica[x + 1][y] = znak;
			pozycja[1][0] = x + 1;
			pozycja[1][1] = y;
			//3
			tablica[x - 1][y] = znak;
			pozycja[2][0] = x - 1;
			pozycja[2][1] = y;
			//4
			tablica[x - 1][y - 1] = znak;
			pozycja[3][0] = x - 1;
			pozycja[3][1] = y - 1;
		}
		else
		{
			*obrot = 3;
			klocekJ(tablica, pozycja, x, y, znak, obrot);
		}
		break;
	case 1:
		if (tablica[x][y - 1] == ' ' && tablica[x][y + 1] == ' ' && tablica[x + 1][y - 1] == ' ')
		{
			//1
			tablica[x][y] = znak;
			pozycja[0][0] = x;
			pozycja[0][1] = y;
			//2
			tablica[x][y + 1] = znak;
			pozycja[1][0] = x;
			pozycja[1][1] = y + 1;
			//3
			tablica[x][y - 1] = znak;
			pozycja[2][0] = x;
			pozycja[2][1] = y - 1;
			//4
			tablica[x + 1][y - 1] = znak;
			pozycja[3][0] = x + 1;
			pozycja[3][1] = y - 1;
		}
		else
		{
			*obrot = 0;
			klocekJ(tablica, pozycja, x, y, znak, obrot);
		}
		break;
	case 2:
		if (tablica[x - 1][y] == ' ' && tablica[x + 1][y + 1] == ' ' && tablica[x + 1][y] == ' ')
		{
			//1
			tablica[x][y] = znak;
			pozycja[0][0] = x;
			pozycja[0][1] = y;
			//2
			tablica[x + 1][y] = znak;
			pozycja[1][0] = x + 1;
			pozycja[1][1] = y;
			//3
			tablica[x - 1][y] = znak;
			pozycja[2][0] = x - 1;
			pozycja[2][1] = y;
			//4
			tablica[x + 1][y + 1] = znak;
			pozycja[3][0] = x + 1;
			pozycja[3][1] = y + 1;
		}
		else
		{
			*obrot = 1;
			klocekJ(tablica, pozycja, x, y, znak, obrot);
		}
		break;
	case 3:
		if (tablica[x][y - 1] == ' ' && tablica[x - 1][y + 1] == ' ' && tablica[x][y+1] == ' ')
		{
			//1
			tablica[x][y] = znak;
			pozycja[0][0] = x;
			pozycja[0][1] = y;
			//2
			tablica[x][y - 1] = znak;
			pozycja[1][0] = x;
			pozycja[1][1] = y - 1;
			//3
			tablica[x][y + 1] = znak;
			pozycja[2][0] = x;
			pozycja[2][1] = y + 1;
			//4
			tablica[x - 1][y + 1] = znak;
			pozycja[3][0] = x - 1;
			pozycja[3][1] = y + 1;
		}
		else
		{
			*obrot = 2;
			klocekJ(tablica, pozycja, x, y, znak, obrot);
		}
		break;
	}
}
void klocekI(char tablica[PLANSZA_X][PLANSZA_Y], int pozycja[4][2], int x, int y, char znak, int *obrot)
{
	if (pozycja[0][0] != 0)
		czyszczenie(tablica, pozycja);

	switch (*obrot)
	{
	case 0:
	case 2:
		if (tablica[x - 1][y] == ' ' && tablica[x + 1][y] == ' ' && tablica[x + 2][y] == ' ')
		{
			//1
			tablica[x][y] = znak;
			pozycja[0][0] = x;
			pozycja[0][1] = y;
			//2
			tablica[x + 1][y] = znak;
			pozycja[1][0] = x + 1;
			pozycja[1][1] = y;
			//3
			tablica[x - 1][y] = znak;
			pozycja[2][0] = x - 1;
			pozycja[2][1] = y;
			//4
			tablica[x + 2][y] = znak;
			pozycja[3][0] = x + 2;
			pozycja[3][1] = y;
		}
		else
		{
			*obrot = 3;
			klocekI(tablica, pozycja, x, y, znak, obrot);
		}
		break;
	case 1:
	case 3:
		if (tablica[x][y - 1] == ' ' && tablica[x][y + 1] == ' ' && tablica[x][y + 2] == ' ')
		{
			//1
			tablica[x][y] = znak;
			pozycja[0][0] = x;
			pozycja[0][1] = y;
			//2
			tablica[x][y + 1] = znak;
			pozycja[1][0] = x;
			pozycja[1][1] = y + 1;
			//3
			tablica[x][y - 1] = znak;
			pozycja[2][0] = x;
			pozycja[2][1] = y - 1;
			//4
			tablica[x][y +2] = znak;
			pozycja[3][0] = x;
			pozycja[3][1] = y + 2;
		}
		else
		{
			*obrot = 0;
			klocekI(tablica, pozycja, x, y, znak, obrot);
		}
		break;
	}
}
void klocekO(char tablica[PLANSZA_X][PLANSZA_Y], int pozycja[4][2], int x, int y, char znak, int *obrot)
{
	if (pozycja[0][0] != 0)
		czyszczenie(tablica, pozycja);

			//1
			tablica[x][y] = znak;
			pozycja[0][0] = x;
			pozycja[0][1] = y;
			//2
			tablica[x + 1][y] = znak;
			pozycja[1][0] = x + 1;
			pozycja[1][1] = y;
			//3
			tablica[x + 1][y+1] = znak;
			pozycja[2][0] = x + 1;
			pozycja[2][1] = y + 1;
			//4
			tablica[x][y+1] = znak;
			pozycja[3][0] = x;
			pozycja[3][1] = y+1;
}
void klocekS(char tablica[PLANSZA_X][PLANSZA_Y], int pozycja[4][2], int x, int y, char znak, int *obrot)
{
	if (pozycja[0][0] != 0)
		czyszczenie(tablica, pozycja);

	switch (*obrot)
	{
	case 0:
	case 2:
		if (tablica[x - 1][y+1] == ' ' && tablica[x + 1][y] == ' ' && tablica[x][y + 1] == ' ')
		{
			//1
			tablica[x][y] = znak;
			pozycja[0][0] = x;
			pozycja[0][1] = y;
			//2
			tablica[x + 1][y] = znak;
			pozycja[1][0] = x + 1;
			pozycja[1][1] = y;
			//3
			tablica[x - 1][y + 1] = znak;
			pozycja[2][0] = x - 1;
			pozycja[2][1] = y + 1;
			//4
			tablica[x][y + 1] = znak;
			pozycja[3][0] = x;
			pozycja[3][1] = y + 1;
		}
		else
		{
			*obrot = 3;
			klocekS(tablica, pozycja, x, y, znak, obrot);
		}
		break;
	case 1:
	case 3:
		if (tablica[x][y - 1] == ' ' && tablica[x+1][y] == ' ' && tablica[x + 1][y + 1] == ' ')
		{
			//1
			tablica[x][y] = znak;
			pozycja[0][0] = x;
			pozycja[0][1] = y;
			//2
			tablica[x+1][y + 1] = znak;
			pozycja[1][0] = x + 1;
			pozycja[1][1] = y + 1;
			//3
			tablica[x][y - 1] = znak;
			pozycja[2][0] = x;
			pozycja[2][1] = y - 1;
			//4
			tablica[x + 1][y] = znak;
			pozycja[3][0] = x + 1;
			pozycja[3][1] = y;
		}
		else
		{
			*obrot = 0;
			klocekS(tablica, pozycja, x, y, znak, obrot);
		}
		break;
	}
}
void klocekZ(char tablica[PLANSZA_X][PLANSZA_Y], int pozycja[4][2], int x, int y, char znak, int *obrot)
{
	if (pozycja[0][0] != 0)
		czyszczenie(tablica, pozycja);

	switch (*obrot)
	{
	case 0:
	case 2:
		if (tablica[x + 1][y + 1] == ' ' && tablica[x - 1][y] == ' ' && tablica[x][y + 1] == ' ')
		{
			//1
			tablica[x][y] = znak;
			pozycja[0][0] = x;
			pozycja[0][1] = y;
			//2
			tablica[x - 1][y] = znak;
			pozycja[1][0] = x - 1;
			pozycja[1][1] = y;
			//3
			tablica[x + 1][y + 1] = znak;
			pozycja[2][0] = x + 1;
			pozycja[2][1] = y + 1;
			//4
			tablica[x][y + 1] = znak;
			pozycja[3][0] = x;
			pozycja[3][1] = y + 1;
		}
		else
		{
			*obrot = 3;
			klocekZ(tablica, pozycja, x, y, znak, obrot);
		}
		break;
	case 1:
	case 3:
		if (tablica[x][y - 1] == ' ' && tablica[x - 1][y + 1] == ' ' && tablica[x - 1][y] == ' ')
		{
			//1
			tablica[x][y] = znak;
			pozycja[0][0] = x;
			pozycja[0][1] = y;
			//2
			tablica[x - 1][y + 1] = znak;
			pozycja[1][0] = x - 1;
			pozycja[1][1] = y + 1;
			//3
			tablica[x][y - 1] = znak;
			pozycja[2][0] = x;
			pozycja[2][1] = y - 1;
			//4
			tablica[x - 1][y] = znak;
			pozycja[3][0] = x - 1;
			pozycja[3][1] = y;
		}
		else
		{
			*obrot = 0;
			klocekZ(tablica, pozycja, x, y, znak, obrot);
		}
		break;
	}
}
void klocekI2(char tablica[PLANSZA_X][PLANSZA_Y], int pozycja[4][2], int x, int y, char znak, int *obrot)
{
	switch (*obrot)
	{
	case 0:
	case 2:
		if (tablica[x - 1][y] == ' ' && tablica[x + 1][y] == ' ' && tablica[x + 2][y] == ' ')
		{
			//1
			//tablica[x][y] = znak;
			pozycja[0][0] = x;
			pozycja[0][1] = y;
			//2
			//tablica[x + 1][y] = znak;
			pozycja[1][0] = x + 1;
			pozycja[1][1] = y;
			//3
			//tablica[x - 1][y] = znak;
			pozycja[2][0] = x - 1;
			pozycja[2][1] = y;
			//4
			//tablica[x + 2][y] = znak;
			pozycja[3][0] = x + 2;
			pozycja[3][1] = y;
		}
		else
		{
			*obrot = 3;
			klocekI(tablica, pozycja, x, y, znak, obrot);
		}
		break;
	case 1:
	case 3:
		if (tablica[x][y - 1] == ' ' && tablica[x][y + 1] == ' ' && tablica[x][y + 2] == ' ')
		{
			//1
			//tablica[x][y] = znak;
			pozycja[0][0] = x;
			pozycja[0][1] = y;
			//2
			//tablica[x][y + 1] = znak;
			pozycja[1][0] = x;
			pozycja[1][1] = y + 1;
			//3
			//tablica[x][y - 1] = znak;
			pozycja[2][0] = x;
			pozycja[2][1] = y - 1;
			//4
			//tablica[x][y + 2] = znak;
			pozycja[3][0] = x;
			pozycja[3][1] = y + 2;
		}
		else
		{
			*obrot = 0;
			klocekI(tablica, pozycja, x, y, znak, obrot);
		}
		break;
	}
}
void czyszczenie(char tablica[PLANSZA_X][PLANSZA_Y], int pozycja[4][2], char znak)
{
	for (int i = 0; i < 4; i++)
		tablica[pozycja[i][0]][pozycja[i][1]] = znak;
}

bool kolizja(char tablica[PLANSZA_X][PLANSZA_Y],int pozycja[4][2],int x, int y)
{
	char znak = tablica[pozycja[0][0]][pozycja[0][1]];
	czyszczenie(tablica, pozycja);
	for (int i = 0; i < 4; i++)
	{
		if ((tablica[pozycja[i][0] + x][pozycja[i][1] + y] != ' '))
		{
			czyszczenie(tablica, pozycja, znak);
			return true;
		}
	}
	czyszczenie(tablica, pozycja, znak);
	return false;
}
void przesuniecie(char tablica[PLANSZA_X][PLANSZA_Y], int pozycja[4][2],int *pozycja_x, int x)
{
	if (!kolizja(tablica, pozycja, x, 0))
	{
		czyszczenie(tablica, pozycja);
		*pozycja_x += x;
	}
}
void sprawdz(char tablica[PLANSZA_X][PLANSZA_Y], int *punkty, int etap, int *poprzednie)
{
	int zbicie = 0;
	int zapelnienie = 0;
	for (int i = 1; i < PLANSZA_Y-1; i++)
	{
		for (int j = 1; j < PLANSZA_X-1 && tablica[j][i] != ' '; j++)
			zapelnienie++;
		if (zapelnienie == PLANSZA_X - 2)
		{
			for (int j = 1; j < PLANSZA_X - 1; j++)
				tablica[j][i] = ' ';
			
			for (int k = i; k > 1; k--)
			{
				for (int j = 1; j < PLANSZA_X - 1; j++)
					tablica[j][k] = tablica[j][k - 1];
			}
			zbicie++;
		}
		zapelnienie = 0;
	}
	switch (zbicie)
	{
	case 4:
		if (*poprzednie == 4)
			(*punkty) += 1200*(etap + 1);
		else
		{
			(*punkty) += 800 * (etap + 1);
		}
		break;
	case 3:
		(*punkty) += 400 * (etap + 1);
		break;
	case 2:
		(*punkty) += 200 * (etap + 1);
		break;
	case 1:
		(*punkty) += 100 * (etap + 1);
		break;
	}
	*poprzednie = zbicie;
}
void klocki(int klocek, char tablica[PLANSZA_X][PLANSZA_Y], int pozycja[4][2], int pozycja_x, int pozycja_y, int *obrot)
{
	switch (klocek)
	{
	case 0:
		klocekI(tablica, pozycja, pozycja_x, pozycja_y, 'b', obrot);
		break;
	case 1:
		klocekZ(tablica, pozycja, pozycja_x, pozycja_y, 'g', obrot);
		break;
	case 2:
		klocekS(tablica, pozycja, pozycja_x, pozycja_y, 'c', obrot);
		break;
	case 3:
		klocekL(tablica, pozycja, pozycja_x, pozycja_y, 'n', obrot);
		break;
	case 4:
		klocekJ(tablica, pozycja, pozycja_x, pozycja_y, 'p', obrot);
		break;
	case 5:
		klocekT(tablica, pozycja, pozycja_x, pozycja_y, 'r', obrot);
		break;
	case 6:
		klocekO(tablica, pozycja, pozycja_x, pozycja_y, 'z', obrot);
		break;
	}
}
void nowa_gra(char tablica[PLANSZA_X][PLANSZA_Y], int *punkty, int *etap, int *poprzednie,double *czas, double *odliczanie, double *czas_gry, int *t2, int *t1,int *klocek, int *obrot,int *next_klocek)
{
	for (int i = 0; i < PLANSZA_X; i++)
	{
		for (int j = 0; j < PLANSZA_Y; j++)
		{
			if (i == 0 || i == PLANSZA_X - 1)
				tablica[i][j] = 's';
			else if (j == 0 || j == PLANSZA_Y - 1)
				tablica[i][j] = 's';
			else
				tablica[i][j] = ' ';
		}
	}
	*punkty = *etap = *poprzednie =*obrot = *czas_gry = 0;
	*czas = CZAS_OPADANIA;
	*odliczanie = CZAS_ETAPU;
	*klocek = rand() % 7;
	*next_klocek = rand() % 7;
	*t1 = *t2 = SDL_GetTicks();
}
void zapisz_gre(char tablica[PLANSZA_X][PLANSZA_Y], int *punkty, int *etap, int *poprzednie, double *czas, double *odliczanie, double *czas_gry, int *t2, int *t1, int *klocek, int *obrot, int *next_klocek, int pozycje[4][2], int * pozycja_x, int* pozycja_y, int *zapisz)
{
	(*zapisz)++;
	FILE *plik_z;
	plik_z = fopen("zapisz.txt", "w");
	for (int i = 0; i < PLANSZA_X; i++)
	{
		for (int j = 0; j < PLANSZA_Y; j++)
		{
			fputc(tablica[i][j],plik_z);
		}
		fputc('\n', plik_z);
	}
	fprintf(plik_z, "pozycjaX:%d\npozycjaY:%d", *pozycja_x, *pozycja_y);
	fprintf(plik_z, "k1:%d,%d\nk2:%d,%d\nk4:%d,%d\nk3:%d,%d\n", pozycje[0][0], pozycje[0][1], pozycje[1][0], pozycje[1][1], pozycje[2][0], pozycje[2][1], pozycje[3][0], pozycje[3][1]);
	fprintf(plik_z, "Punkty:%d\nEtap:%d\nPoprzednie:%d\nObrot:%d\nCzasgry:%f\n", *punkty, *etap, *poprzednie, *obrot, *czas_gry);
	fprintf(plik_z, "Czas:%f\n",*czas);
	fprintf(plik_z, "Odliczanie:%f\n", *odliczanie);
	fprintf(plik_z, "Klocek:%d\n", *klocek);
	fprintf(plik_z, "Nastepny:%d\n", *next_klocek);
	fprintf(plik_z, "Zapis:%d\n", *zapisz);
	fclose(plik_z);
}
void wczytaj_gre(char tablica[PLANSZA_X][PLANSZA_Y], int *punkty, int *etap, int *poprzednie, double *czas, double *odliczanie, double *czas_gry, int *t2, int *t1, int *klocek, int *obrot, int *next_klocek,int pozycje[4][2],int * pozycja_x, int* pozycja_y, int *zapisz)
{
	FILE *plik_z;
	plik_z = fopen("zapisz.txt", "r");
	for (int i = 0; i < PLANSZA_X; i++)
	{
		for (int j = 0; j < PLANSZA_Y; j++)
		{
			tablica[i][j]=fgetc(plik_z);
		}
		fgetc(plik_z);
	}
	fscanf(plik_z, "pozycjaX:%d\npozycjaY:%d", pozycja_x, pozycja_y);
	fscanf(plik_z, "k1:%d,%d\nk2:%d,%d\nk4:%d,%d\nk3:%d,%d\n", &pozycje[0][0], &pozycje[0][1], &pozycje[1][0], &pozycje[1][1], &pozycje[2][0], &pozycje[2][1], &pozycje[3][0], &pozycje[3][1]);
	fscanf(plik_z, "Punkty:%d\nEtap:%d\nPoprzednie:%d\nObrot:%d\nCzasgry:%f\n", punkty, etap, poprzednie, obrot, czas_gry);
	fscanf(plik_z, "Czas:%f\n", czas);
	fscanf(plik_z, "Odliczanie:%f\n", odliczanie);
	fscanf(plik_z, "Klocek:%d\n", klocek);
	fscanf(plik_z, "Nastepny:%d\n", next_klocek);
	fscanf(plik_z, "Zapis:%d\n", zapisz);
	fclose(plik_z);
}