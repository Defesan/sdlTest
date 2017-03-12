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

bool init(SDL_Window** win, SDL_Surface** surface);
void shutdown(SDL_Window* win, SDL_Surface* surface);

int main(int argc, char* argv[])
{
	SDL_Window* window = NULL;

	SDL_Surface* screenSurface = NULL;

	if(!init(&window, &screenSurface))
	{
		return 1;	
	}
	
	SDL_Rect subRect;
	subRect.x = 120;
	subRect.y = 140;
	subRect.h = 100;
	subRect.w = 100;
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
	SDL_UpdateWindowSurface(window);
	SDL_Delay(2000);
	SDL_FillRect(screenSurface, &subRect, SDL_MapRGB(screenSurface->format, 0xFF, 0, 0));
	SDL_UpdateWindowSurface(window);
	SDL_Delay(1000);
	

	shutdown(window);
	window = NULL;
	
	
	return 0;
}

//I know, it's ugly. But technically, I'm just passing a pointer to a memory location that will hold a pointer to an object.
//Now that I've got a better grip on what's going on, I realize that this is actually not the worst way to do this, if you 
//want to initialize objects outside of the function they're declared in. Or, in fact, to change what they point to.
bool init(SDL_Window** win, SDL_Surface** surface)
{
	bool success = true;
	
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "Error initializing SDL: " << SDL_GetError() << std::endl;
		success = false;
	}
	else
	{
		*win = SDL_CreateWindow("Init Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
		if(win == NULL)
		{
			std::cerr << "Error initializing window: " << SDL_GetError() << std::endl;
			success = false;
		}
		else
		{
			*surface = SDL_GetWindowSurface(*win);
		}
	}
	return success;
}


//In this case, however, we aren't modifying the pointers, just the objects.
void shutdown(SDL_Window* win)
{
	SDL_DestroyWindow(win);
	SDL_Quit();

}
