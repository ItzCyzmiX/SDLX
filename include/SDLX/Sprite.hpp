#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_shape.h>
#include <SDL2/SDL_image.h>
#include <SDLX/Rect.hpp>

class Sprite {
    public:
        
        float x;
        float y;
        float width;
        float height;

        int red = 255; 
        int green = 255;
        int blue = 255;
        
        float hitbox_offsetY, hitbox_offsetX;
        
        float angle = 0;
        
        Sprite(const char* p_imgFile, SDL_Renderer* r);
        
        Sprite(const char* p_imgFile, SDL_Renderer* r, float p_x, float p_y, float p_width, float p_height);

		void kill();

        void draw(SDL_Renderer* r);

        void drawHitbox(SDL_Renderer* r);
        
        void setHitbox(float p_x, float p_y, float p_width, float p_height);
        
        void setHitbox(float p_x, float p_y, float p_width, float p_height, int color[3]);

		bool collideSprite(Sprite spr);

		bool collideRect(Rect rect);

		void hitboxUpdate();
        
        void setDest(float p_x, float p_y, float p_width, float p_height);

        void setSource(float p_x, float p_y, float p_width, float p_height);
        
        void scaleBy(float p_scaleByW, float p_scaleByH);

        void setScale(float p_scaleW, float p_scaleH);

        void rotateBy(float p_rotateBy);

        void setRotation(float p_rotation);
        
        void setRotationPoint(float x, float y);
        
        void setRotationPointToCenter();
        
        void setPos(float p_x, float p_y);
        
        void moveBy(float p_x, float p_y);

		float getRotation();

		bool isKilled() {return killed;};
        
    private:

		bool killed = false;
	
        bool changedSrc = false;
        bool changedDest = false;
            
        const char * imgFile;

        SDL_Texture * texture = NULL;
        
        SDL_Point rotationPoint;

        SDL_Rect srcRect;
        SDL_Rect destRect;
        SDL_Rect hitbox;
        
};

#endif /* SPRITE_HPP */

