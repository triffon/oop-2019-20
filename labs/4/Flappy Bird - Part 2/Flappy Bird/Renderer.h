#pragma once
#include <string>
#include "Util.h"

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Texture;
struct SDL_Rect;
class Model;

class Renderer
{
	SDL_Window* window;
	SDL_Renderer* renderer;
	Vec2D offset;
	Vec2D scale;
	Vec2D resolution;
public:
	Renderer() : offset({ 0,0 }), resolution({1280, 768}), scale({ 1,1 }) {}
	SDL_Texture* createTexture(const std::string& path);
	void init();
	void createWindow();
	void clear();
	void present();
	void renderTexture(SDL_Texture* tex, SDL_Rect& dst);
	void renderModel(Model* model);

	void drawRect(const SDL_Rect& rect);
	void setOffset(const Vec2D& offset) { this->offset = offset; }
	void setScale(const Vec2D& scale) { this->scale = scale; }

	Vec2D getOffset() { return offset; }
	Vec2D getResolution() { return resolution; }
};

