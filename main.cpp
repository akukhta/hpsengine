#include <iostream>
#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>
#include <sdl2/SDL_ttf.h>

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
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("SDL_PG", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 832, SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN);

    if (window == nullptr)
    {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Setup renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == nullptr)
    {
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    //Set renderer Size (i.e frame size without upscaling)
    SDL_RenderSetLogicalSize(renderer, 640, 480);

    // init sdl_image to use png
    if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
    {
        std::cout << "IMG_Init Error: " << IMG_GetError() << std::endl;

        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();

        return 1;
    }

    if (TTF_Init() != 0)
    {
        std::cout << "TTF_Init Error: " << TTF_GetError() << std::endl;

        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();

        return 1;
    }

    SDL_Texture* texture = IMG_LoadTexture(renderer, "texture.png");

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

		SDL_RenderClear(renderer);
		renderTexture(texture, renderer, 0, 0, nullptr);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	// Texture is stored in VRAM, processed via GPU, no direct access
	// Surfaces can be directly accessed (pixel-based)

	return 0;
}