#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Text {
	public:

		Text(SDL_Renderer* r, const char* fontFile, int fontSize, const char* msg, float p_x, float p_y ,int p_color[3]);
		
		void draw(SDL_Renderer* r);

		void setColor(int p_color[3]);

		void setRotation(float p_angle);

		void setRotationPoint(float p_x, float p_y);

		void setRotationPointToCenter();

		void rotateBy(float p_angle);
	
		void setPos(float p_x, float p_y);

		float getRotation();

		void kill();

		bool isKilled() {return killed;};
		
	private:

		bool killed = false;

		float x, y;
		
		float angle = 0;

		SDL_Point rotationPoint;

		SDL_Rect textRect;

		SDL_Texture * textTexture = NULL;

		SDL_Surface * textSurf = NULL;

		SDL_Color color;
		
};
