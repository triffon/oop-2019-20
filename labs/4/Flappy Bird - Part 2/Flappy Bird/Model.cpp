#include "SDL.h"
#include "Model.h"
#include "Renderer.h"

Model::Model() : Model(nullptr, { 0,0 }, {0,0})
{
}

Model::Model(SDL_Texture* texture, const Vec2D position, const Vec2D size)
	:texture(texture), position(position), size(size) {}

void Model::addToPosition(const Vec2D& pos)
{
	position += pos;
}

void Model::setPosition(const Vec2D& pos)
{
	position = pos;
}

void Model::render(Renderer* renderer)
{
	SDL_Rect dst = { position.x, position.y, size.x, size.y };
	renderer->renderTexture(texture, dst);
}
