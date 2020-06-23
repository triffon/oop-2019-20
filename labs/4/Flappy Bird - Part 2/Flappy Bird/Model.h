#pragma once
#include "Util.h"

struct SDL_Texture;
class Renderer;

class Model
{
	Vec2D position;
	Vec2D size;
	SDL_Texture* texture;
public:
	Model();
	Model(SDL_Texture* texture, const Vec2D position, const Vec2D size);

	void addToPosition(const Vec2D& pos);
	void setPosition(const Vec2D& pos);
	void setSize(const Vec2D& size) { this->size = size; }

	const Vec2D& getSize() { return size; }
	const Vec2D& getPosition() { return position; }
	SDL_Texture* getTexture() { return texture; }

	void render(Renderer* renderer);
	void setTexutre(SDL_Texture* tex) { texture = tex; }
};

