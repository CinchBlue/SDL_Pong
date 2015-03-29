//============================================================================
// Name        : TestPong.cpp
// Author      : Austin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Common.h"
#include "SDL_image.h"
#include "Event_Queue.h"
#include "Event_Sender.h"
#include "Event_Receiver.h"
#include "Texture_Pool.h"

const std::string WINDOW_NAME = "TestPong";

Texture_Pool tpool;

int main(int argc, char* argv[])
{
	bool done = false;

	//Start SDL
	SDL_Init(SDL_INIT_VIDEO);

	//Create window
	g_window = SDL_CreateWindow("TestPong", 20, 20, 1200, 800, SDL_WINDOW_RESIZABLE);
	g_renderer = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	tpool.load_texture("pong_wall.png");

	SDL_Texture* wall_image = tpool.get_texture("pong_wall.png");

	SDL_Rect wall1;
	wall1.x = 100;
	wall1.y = 100;
	wall1.w = 100;
	wall1.h = 32;

	Event_Queue event_queue;

	while (!done)
	{
		SDL_Event event;

		//Set renderer color to black
		SDL_SetRenderDrawColor(g_renderer, 0, 0, 0, 255);
		//Use renderer to refresh screen to black
		SDL_RenderClear(g_renderer);

		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
				case SDL_QUIT:
					done = true;
					break;
				case SDL_KEYDOWN:
					if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
						done = true;
						break;
				default:
					break;
			}
		}

		SDL_RenderCopy(g_renderer, wall_image, NULL, &wall1);

		SDL_RenderPresent(g_renderer);



	}

	SDL_DestroyWindow(g_window);
	SDL_DestroyRenderer(g_renderer);

	return 0;
}
