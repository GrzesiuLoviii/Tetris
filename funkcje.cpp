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
		if (tablica[x + 1][y] != ' ' && tablica[x - 2][y] == ' ')
		{
			x--;
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
		//else if (tablica[x + 1][y] != ' ' && tablica[x - 2][y] != ' ')
			//klocekT(tablica, pozycja, x, y, znak, 3);
		else
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
		break;
	case 1:
		if (tablica[x][y + 1] != ' ' && tablica[x][y - 2] == ' ')
		{
			y--;
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
		//else if (tablica[x][y+1] != ' ' && tablica[x][y-2] != ' ')
			//klocekT(tablica, pozycja, x, y, znak, 0);
		else
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
		break;
	case 2:
		if (tablica[x-1][y] != ' ' && tablica[x+2][y] == ' ')
		{
			x++;
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
		//else if (tablica[x-1][y] != ' ' && tablica[x+2][y] != ' ')
		//	klocekT(tablica, pozycja, x, y, znak, 1);
		else
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
		break;
	case 3:
		if (tablica[x][y-1] != ' ' && tablica[x][y+2] == ' ')
		{
			y++;
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
		//else if (tablica[x][y-1] != ' ' && tablica[x][y+2] != ' ')
		//	klocekT(tablica, pozycja, x, y, znak, 2);
		else
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
		//1
		tablica[x][y] = znak;
		pozycja[0][0] = x;
		pozycja[0][1] = y;
		//2
		tablica[x+1][y] = znak;
		pozycja[1][0] = x+1;
		pozycja[1][1] = y;
		//3
		tablica[x-1][y] = znak;
		pozycja[2][0] = x-1;
		pozycja[2][1] = y;
		//4
		tablica[x - 1][y + 1] = znak;
		pozycja[3][0] = x - 1;
		pozycja[3][1] = y + 1;
		break;
	case 3:
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
		if (tablica[x - 1][y] == ' ' && tablica[x + 1][y] == ' ' && tablica[x + 1][y - 1] == ' ')
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
		break;
	case 1:
		if (tablica[x][y - 1] == ' ' && tablica[x][y + 1] == ' ' && tablica[x + 1][y + 1] == ' ')
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
		break;
	case 2:
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
		break;
	case 3:
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
		if (tablica[x - 1][y] == ' ' && tablica[x + 1][y] == ' ' && tablica[x + 1][y - 1] == ' ')
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
		break;
	case 1:
		if (tablica[x][y - 1] == ' ' && tablica[x][y + 1] == ' ' && tablica[x + 1][y + 1] == ' ')
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
		break;
	case 2:
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
		break;
	case 3:
		//1
		tablica[x][y] = znak;
		pozycja[0][0] = x;
		pozycja[0][1] = y;
		//2
		tablica[x][y-1] = znak;
		pozycja[1][0] = x;
		pozycja[1][1] = y-1;
		//3
		tablica[x][y+1] = znak;
		pozycja[2][0] = x;
		pozycja[2][1] = y+1;
		//4
		tablica[x - 1][y + 1] = znak;
		pozycja[3][0] = x - 1;
		pozycja[3][1] = y + 1;
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
void sprawdz(char tablica[PLANSZA_X][PLANSZA_Y])
{
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
				
		}
		zapelnienie = 0;

	}

}