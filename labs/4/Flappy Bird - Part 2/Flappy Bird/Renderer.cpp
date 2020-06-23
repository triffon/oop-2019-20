#include "SDL.h"
#include "SDL_image.h"
#include "Renderer.h"
#include "Model.h"

SDL_Texture* Renderer::createTexture(const std::string& path)
{
	return IMG_LoadTexture(renderer, "image.jpg");
}

void Renderer::init()
{
	renderer = SDL_CreateRenderer(window, -1, 0);
}

void Renderer::createWindow()
{
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("SDL2 Displaying Image",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, (int)resolution.x, (int)resolution.y, 0);
}

void Renderer::clear()
{
	SDL_RenderClear(renderer);
}

void Renderer::present()
{
	SDL_RenderPresent(renderer);
}

void Renderer::renderTexture(SDL_Texture* texture, SDL_Rect& dst)
{
	SDL_Rect dest = dst;
	dest.x -= offset.x;
	dest.y -= offset.y;
	dest.w *= scale.x;
	dest.h *= scale.y;
	SDL_RenderCopy(renderer, texture, NULL, &dest);
}

void Renderer::renderModel(Model* model)
{
	Vec2D pos = model->getPosition();
	Vec2D size = model->getSize();
	SDL_Rect dst{ (int)pos.x, (int)pos.y, (int)size.x, (int)size.y };
	renderTexture(model->getTexture(), dst);
}

void Renderer::drawRect(const SDL_Rect& rect)
{
	auto dest = rect;
	dest.x -= offset.x;
	dest.y -= offset.y;
	dest.w *= scale.x;
	dest.h *= scale.y;
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &dest);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
}
