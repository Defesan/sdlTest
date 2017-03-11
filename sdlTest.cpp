#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>

#include "SDL2/SDL.h"
#include "SDL2/SDL_test_common.h"

#if defined(__IPHONEOS__) || defined(__ANDROID__)
#define HAVE_OPENGLES
#endif

//I need to get this working in Android and Linux, so for now, I am just going to assume that it has SDL and some form of OGL, defaulting to plain OGL if it isn't an android or ios device.

#ifdef HAVE_OPENGLES
#include "SDL_opengles.h"
#else
#include "SDL2/SDL_opengl.h"
#endif

int main(int argc, char* argv[])
{
	SDL_Window* window = NULL;

	SDL_Surface* screenSurface = NULL;

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "Error initializing SDL: " << SDL_GetError() << std::endl;
	}
	else
	{
		window = SDL_CreateWindow("SDL Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
		if(window == NULL)
		{
			std::cerr << "Error initializing window: " << SDL_GetError() << std::endl;
		}
		else
		{	
			SDL_Rect subRect;
			subRect.x = 120;
			subRect.y = 140;
			subRect.h = 100;
			subRect.w = 100;
			screenSurface = SDL_GetWindowSurface(window);
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
			SDL_UpdateWindowSurface(window);
			SDL_Delay(2000);
			SDL_FillRect(screenSurface, &subRect, SDL_MapRGB(screenSurface->format, 0xFF, 0, 0));
			SDL_UpdateWindowSurface(window);
			SDL_Delay(1000);
		}

	}
	SDL_DestroyWindow(window);
	SDL_Quit();
	
	
	
	return 0;
}
