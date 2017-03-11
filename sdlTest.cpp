#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>

#include "SDL2/SDL.h"
#include "SDL_test_common.h"

#if defined(__IPHONEOS__) || defined(__ANDROID__)
#define HAVE_OPENGLES
#endif

//I need to get this working in Android and Linux, so for now, I am just going to assume that it has SDL and some form of OGL, defaulting to plain OGL if it isn't an android or ios device.

#ifdef HAVE_OPENGLES
#include "SDL_opengles.h"
#else
#include "SDL_opengl.h"
#endif

//Now for some ugly file-scoping.
//C++, Y U no proper statics?

static SDLTest_CommonState* state;
static SDL_GLContext* context = NULL;