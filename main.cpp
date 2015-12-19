#include "funkcje.h"

int main(int argc, char **argv) 
{
	srand(time(NULL));
	char tablica[PLANSZA_X][PLANSZA_Y];
	for (int i = 0; i < PLANSZA_X; i++)
	{
		for (int j = 0; j < PLANSZA_Y; j++)
		{
			if (i == 0 || i==PLANSZA_X-1)
				tablica[i][j] = 's';
			else if (j == 0 || j == PLANSZA_Y-1)
				tablica[i][j] = 's';
			else
				tablica[i][j] = ' ';

		}
	}
	int rc;
	int x, y;
	bool quit = false;
	SDL_Event event;
	SDL_Surface *screen, *szary, *rozowy, *niebieski, *pomaranczowy, *blekit, *zolty, *zielony, *czerwony,
		*figury[7];
	SDL_Texture *scrtex;
	SDL_Window *window;
	SDL_Renderer *renderer;
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		printf("SDL_Init error: %s\n", SDL_GetError());
		return 1;
	}
	rc = SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer);
	if (rc != 0) 
	{
		SDL_Quit();
		printf("SDL_CreateWindowAndRenderer error: %s\n", SDL_GetError());
		return 1;
	};

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	SDL_SetWindowTitle(window, "Szablon do zdania drugiego 2014");
	// wy³¹czenie widocznoœci kursora myszy
	SDL_ShowCursor(SDL_DISABLE);

	screen = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT, 32, 0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);

	scrtex = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,SDL_TEXTUREACCESS_STREAMING,SCREEN_WIDTH, SCREEN_HEIGHT);
	szary = SDL_LoadBMP("./klocek1.bmp");
	if (szary == NULL) {
		printf("SDL_LoadBMP(klocek1.bmp) error: %s\n", SDL_GetError());
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return 1;
	};
	rozowy = SDL_LoadBMP("./klocek5.bmp");
	if (rozowy == NULL) {
		printf("SDL_LoadBMP(klocek5.bmp) error: %s\n", SDL_GetError());
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return 1;
	};
	niebieski = SDL_LoadBMP("./klocek4.bmp");
	if (niebieski == NULL) {
		printf("SDL_LoadBMP(klocek4.bmp) error: %s\n", SDL_GetError());
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return 1;
	};
	pomaranczowy = SDL_LoadBMP("./klocek8.bmp");
	if (pomaranczowy == NULL) {
		printf("SDL_LoadBMP(klocek8.bmp) error: %s\n", SDL_GetError());
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return 1;
	};
	blekit = SDL_LoadBMP("./klocek3.bmp");
	if (blekit == NULL) {
		printf("SDL_LoadBMP(klocek3.bmp) error: %s\n", SDL_GetError());
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return 1;
	};
	zolty = SDL_LoadBMP("./klocek2.bmp");
	if (zolty == NULL) {
		printf("SDL_LoadBMP(klocek2.bmp) error: %s\n", SDL_GetError());
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return 1;
	};
	czerwony = SDL_LoadBMP("./klocek6.bmp");
	if (czerwony == NULL) {
		printf("SDL_LoadBMP(klocek6.bmp) error: %s\n", SDL_GetError());
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return 1;
	};
	zielony = SDL_LoadBMP("./klocek7.bmp");
	if (pomaranczowy == NULL) {
		printf("SDL_LoadBMP(klocek7.bmp) error: %s\n", SDL_GetError());
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return 1;
	};
	figury[6] = SDL_LoadBMP("./kwadrat.bmp");
	if (figury[6] == NULL) {
		printf("SDL_LoadBMP(kwadrat.bmp) error: %s\n", SDL_GetError());
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return 1;
	};
	figury[0] = SDL_LoadBMP("./linia.bmp");
	if (figury[0] == NULL) {
		printf("SDL_LoadBMP(linia.bmp) error: %s\n", SDL_GetError());
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return 1;
	};
	figury[1] = SDL_LoadBMP("./literaZ.bmp");
	if (figury[1] == NULL) {
		printf("SDL_LoadBMP(literaZ.bmp) error: %s\n", SDL_GetError());
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return 1;
	};
	figury[2] = SDL_LoadBMP("./literaS.bmp");
	if (figury[2] == NULL) {
		printf("SDL_LoadBMP(literaS.bmp) error: %s\n", SDL_GetError());
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return 1;
	};
	figury[3] = SDL_LoadBMP("./literaL.bmp");
	if (figury[3] == NULL) {
		printf("SDL_LoadBMP(literaL.bmp) error: %s\n", SDL_GetError());
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return 1;
	};
	figury[4] = SDL_LoadBMP("./literaJ.bmp");
	if (figury[4] == NULL) {
		printf("SDL_LoadBMP(literaJ.bmp) error: %s\n", SDL_GetError());
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return 1;
	};
	figury[5] = SDL_LoadBMP("./literaT.bmp");
	if (figury[5] == NULL) {
		printf("SDL_LoadBMP(literaT.bmp) error: %s\n", SDL_GetError());
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return 1;
	};

	int czarny = SDL_MapRGB(screen->format, 0x00, 0x00, 0x00);
//	int zielony = SDL_MapRGB(screen->format, 0x00, 0xFF, 0x00);
//	int czerwony = SDL_MapRGB(screen->format, 0xFF, 0x00, 0x00);
//	int niebieski = SDL_MapRGB(screen->format, 0x11, 0x11, 0xCC);
	x = 0;
	y = 0;
	double delta = 0;
	int t1, t2;
	double czas = CZAS_OPADANIA;
	t1 = t2 = 0;
	t1 = SDL_GetTicks();
	int pozycja[4][2] = { 0 };
	int pozycja_x = 5;
	int pozycja_y = 2;
	int obrot = 0;
	int klocek = rand()%7;
	int next_klocek = rand() % 7;
	while (!quit) {
		t2 = SDL_GetTicks();
		SDL_FillRect(screen, NULL, czarny);
		delta = (t2 - t1) * 0.001;
		t1 = t2;
		czas -= delta;
		if (x != 0)
		{
			przesuniecie(tablica, pozycja, &pozycja_x, x);
			x = 0;
		}
		if (czas <= 0)
		{
			if (!kolizja(tablica, pozycja, 0, 1))
			{
				czyszczenie(tablica, pozycja);
				czas = CZAS_OPADANIA;
				pozycja_y += 1;
			}
			else
			{
				sprawdz(tablica);
				obrot = 0;
				klocek = next_klocek;
				next_klocek = rand() % 7;
				pozycja[0][0] = 0;
				pozycja_y = 2;
				pozycja_x = 5;
			}
		}
		switch (klocek)
		{
		case 0:
			klocekI(tablica, pozycja, pozycja_x, pozycja_y, 'b', &obrot);
			break;
		case 1:
			klocekZ(tablica, pozycja, pozycja_x, pozycja_y, 'g', &obrot);
			break;
		case 2:
			klocekS(tablica, pozycja, pozycja_x, pozycja_y, 'c', &obrot);
			break;
		case 3:
			klocekL(tablica, pozycja, pozycja_x, pozycja_y, 'n', &obrot);
			break;
		case 4:
			klocekJ(tablica, pozycja, pozycja_x, pozycja_y, 'p', &obrot);
			break;
		case 5:
			klocekT(tablica, pozycja, pozycja_x, pozycja_y, 'r', &obrot);
			break;
		case 6:
			klocekO(tablica, pozycja, pozycja_x, pozycja_y, 'z', &obrot);
			break;
		}
		DrawSurface(screen, figury[next_klocek], 80 + PLANSZA_X*WYMIAR, 20 + 4*WYMIAR);
		x = 0; y = 0;
		for (int i = 0; i < PLANSZA_X; i++)
		{
			for (int j = 0; j < PLANSZA_Y; j++)
			{
				if (tablica[i][j] == 's')
					DrawSurface(screen, szary, 20+i*WYMIAR, 20+j*WYMIAR);
				else if(tablica[i][j]=='r')
					DrawSurface(screen, rozowy, 20 + i*WYMIAR, 20 + j*WYMIAR);
				else if(tablica[i][j]=='n')
					DrawSurface(screen, niebieski, 20 + i*WYMIAR, 20 + j*WYMIAR);
				else if (tablica[i][j] == 'p')
					DrawSurface(screen, pomaranczowy, 20 + i*WYMIAR, 20 + j*WYMIAR);
				else if (tablica[i][j] == 'b')
					DrawSurface(screen, blekit, 20 + i*WYMIAR, 20 + j*WYMIAR);
				else if (tablica[i][j] == 'z')
					DrawSurface(screen, zolty, 20 + i*WYMIAR, 20 + j*WYMIAR);
				else if (tablica[i][j] == 'c')
					DrawSurface(screen, czerwony, 20 + i*WYMIAR, 20 + j*WYMIAR);
				else if (tablica[i][j] == 'g')
					DrawSurface(screen, zielony, 20 + i*WYMIAR, 20 + j*WYMIAR);
			}
		}
		SDL_UpdateTexture(scrtex, NULL, screen->pixels, screen->pitch);
		SDL_RenderCopy(renderer, scrtex, NULL, NULL);
		SDL_RenderPresent(renderer);
		
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE: quit = true; break;
				case SDLK_LEFT: x--; break;
				case SDLK_RIGHT: x++; break;
				case SDLK_UP:
				case SDLK_SPACE:
					obrot++;
					obrot %= 4;
					break;
				case SDLK_p:
					bool pause = true;
					while (pause)
					{
						while (SDL_PollEvent(&event)) {
							switch (event.type) {
							case SDL_KEYDOWN:
								if (event.key.keysym.sym == SDLK_p)
									pause = false;
							}
						}
					}
				}
				break;
			case SDL_QUIT:
				quit = 1;
				break;
			};
		};
	}



	//		DrawScreen(screen, plane, ship, charset, worldTime, delta, vertSpeed);

	/*
	int t1, t2, quit, frames, rc;
	double delta, worldTime, fpsTimer, fps, distance, etiSpeed;
	double czas_kroku = CZAS_OPADANIA;
	// tryb pe³noekranowy
//	rc = SDL_CreateWindowAndRenderer(0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP,
//	                                 &window, &renderer);
	rc = SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer);
	if(rc != 0) {
		SDL_Quit();
		printf("SDL_CreateWindowAndRenderer error: %s\n", SDL_GetError());
		return 1;
		};
	
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	SDL_SetWindowTitle(window, "Szablon do zdania drugiego 2014");


	screen = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT, 32,
	                              0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);

	scrtex = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
	                           SDL_TEXTUREACCESS_STREAMING,
	                           SCREEN_WIDTH, SCREEN_HEIGHT);

	// wy³¹czenie widocznoœci kursora myszy
	SDL_ShowCursor(SDL_DISABLE);

	// wczytanie obrazka cs8x8.bmp
	charset = SDL_LoadBMP("./cs8x8.bmp");
	if(charset == NULL) {
		printf("SDL_LoadBMP(cs8x8.bmp) error: %s\n", SDL_GetError());
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return 1;
		};
	SDL_SetColorKey(charset, true, 0x000000);

	eti = SDL_LoadBMP("./eti.bmp");
	if(eti == NULL) {
		printf("SDL_LoadBMP(eti.bmp) error: %s\n", SDL_GetError());
		SDL_FreeSurface(charset);
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return 1;
		};

	char text[128];
	int czarny = SDL_MapRGB(screen->format, 0x00, 0x00, 0x00);
	int zielony = SDL_MapRGB(screen->format, 0x00, 0xFF, 0x00);
	int czerwony = SDL_MapRGB(screen->format, 0xFF, 0x00, 0x00);
	int niebieski = SDL_MapRGB(screen->format, 0x11, 0x11, 0xCC);

	t1 = SDL_GetTicks();
	
	frames = 0;
	fpsTimer = 0;
	fps = 0;
	quit = 0;
	worldTime = 0;
	distance = 0;
	etiSpeed = 1;
	int x=50, y=50;
	while(!quit) {
		t2 = SDL_GetTicks();

		// w tym momencie t2-t1 to czas w milisekundach,
		// jaki uplyna³ od ostatniego narysowania ekranu
		// delta to ten sam czas w sekundach
		delta = (t2 - t1) * 0.001;
		t1 = t2;
		czas_kroku -= delta;
		if (czas_kroku <= 0)
		{
			if()
			y += WYMIAR;
			czas_kroku = CZAS_OPADANIA;
			
		}
		worldTime += delta;

		distance += etiSpeed * delta;

		SDL_FillRect(screen, NULL, czarny);

//		DrawScreen(screen, plane, ship, charset, worldTime, delta, vertSpeed);

		// naniesienie wyniku rysowania na rzeczywisty ekran
//		SDL_Flip(screen);

		fpsTimer += delta;
		if(fpsTimer > 0.5) {
			fps = frames * 2;
			frames = 0;
			fpsTimer -= 0.5;
			};

		// tekst informacyjny
		/*
		DrawRectangle(screen, 4, 4, SCREEN_WIDTH - 8, 36, czerwony, niebieski);
		sprintf(text, "Szablon drugiego zadania, czas trwania = %.1lf s  %.0lf klatek / s", worldTime, fps);
		DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, 10, text, charset);
		sprintf(text, "Esc - wyjscie, \030 - przyspieszenie, \031 - zwolnienie");
		DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, 26, text, charset);
		
		klocekT(screen,x,y,niebieski);

		SDL_UpdateTexture(scrtex, NULL, screen->pixels, screen->pitch);
//		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, scrtex, NULL, NULL);
		SDL_RenderPresent(renderer);
		
		// obs³uga zdarzeñ (o ile jakieœ zasz³y)
		while(SDL_PollEvent(&event)) {
			switch(event.type) {
				case SDL_KEYDOWN:
					if(event.key.keysym.sym == SDLK_ESCAPE) quit = 1;
					else if(event.key.keysym.sym == SDLK_UP) etiSpeed = 2.0;
					else if(event.key.keysym.sym == SDLK_DOWN) etiSpeed = 0.3;
					else if (event.key.keysym.sym == SDLK_LEFT) x -= WYMIAR;
					else if (event.key.keysym.sym == SDLK_RIGHT) x += WYMIAR;
					break;
				case SDL_KEYUP:
					etiSpeed = 1.0;
					break;
				case SDL_QUIT:
					quit = 1;
					break;
				};
			};
		frames++;
		};

	// zwolnienie powierzchni
	SDL_FreeSurface(charset);
	SDL_FreeSurface(screen);
	SDL_DestroyTexture(scrtex);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();
	return 0;
	*/
return 0;
};
