#include <iostream>
#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>
#include <sdl2/SDL_ttf.h>
#include "src/sdlcore/SDLCore.h"
#include "src/sdlcore/SDLWindow.h"
#include "src/sdlcore/SDLRenderer.h"

void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, SDL_Rect dst,
	SDL_Rect *clip)
{
	SDL_RenderCopy(ren, tex, clip, &dst);
}

void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y,
	SDL_Rect *clip)
{
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;

	if (clip != nullptr)
	{
		dst.w = clip->w;
		dst.h = clip->h;
	}
	else
	{
		SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
	}

	renderTexture(tex, ren, dst, clip);
}


int main()
{
	SDLCore::SDLCore core;

	auto window = core.createWindow("Test", std::make_pair(640, 480), std::make_pair(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED),
		true, true);

	auto renderer = core.createRenderer(window);

    // init sdl_image to use png
    if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
    {
        std::cout << "IMG_Init Error: " << IMG_GetError() << std::endl;
        return 1;
    }

    if (TTF_Init() != 0)
    {
        std::cout << "TTF_Init Error: " << TTF_GetError() << std::endl;
        return 1;
    }

    SDL_Texture* texture = IMG_LoadTexture(renderer->getRenderer(), "texture.png");

    if (texture == nullptr)
    {
        std::cout << "IMG_LoadTexture Error: " << IMG_GetError() << std::endl;
    }

	SDL_Event e;
	bool quit = false;
	while (!quit)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}

		SDL_RenderClear(renderer->getRenderer());
		renderTexture(texture, renderer->getRenderer(), 0, 0, nullptr);
		SDL_RenderPresent(renderer->getRenderer());
	}

	SDL_DestroyTexture(texture);

	// Texture is stored in VRAM, processed via GPU, no direct access
	// Surfaces can be directly accessed (pixel-based)

	return 0;
}