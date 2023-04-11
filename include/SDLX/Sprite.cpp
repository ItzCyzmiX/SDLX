#include <SDLX/Sprite.hpp>
#include <iostream>

using namespace std;

Sprite::Sprite(const char* p_imgFile, SDL_Renderer* r) {

    imgFile = p_imgFile;
    
    SDL_Surface * surf = NULL;
    
    surf = IMG_Load(imgFile);

    texture = SDL_CreateTextureFromSurface(r, surf);
    
    if (surf == NULL || texture == NULL) {cout << "Error creating sprite! \nError: " << SDL_GetError();}
    
    SDL_FreeSurface(surf);

}

Sprite::Sprite(const char* p_imgFile, SDL_Renderer* r, float p_x, float p_y, float p_width, float p_height) {
    
    imgFile = p_imgFile;
    
    SDL_Surface * surf = NULL;
    
    surf = IMG_Load(imgFile);

    texture = SDL_CreateTextureFromSurface(r, surf);
    
    if (surf == NULL || texture == NULL) {cout << "Error creating sprite! \nError: " << SDL_GetError();}
    
    SDL_FreeSurface(surf);
    
    Sprite::setDest(p_x, p_y, p_width, p_height);

}

void Sprite::kill() {
	if (!killed) {
		SDL_DestroyTexture(texture);
		killed = true;
	} else {
		cout << "Sprite is already killed!\n";	
	}
}

void Sprite::draw(SDL_Renderer* r) {
    
    if (changedDest && changedSrc) {
        
        destRect.x = x;
        destRect.y = y;
        destRect.w = width;
        destRect.h = height;
        
        SDL_RenderCopyEx(r, texture, &srcRect, &destRect, angle, &rotationPoint, SDL_FLIP_NONE);
    }
    if (changedDest && !changedSrc) {
        
        destRect.x = x;
        destRect.y = y;
        destRect.w = width;
        destRect.h = height;
        
        SDL_RenderCopyEx(r, texture, NULL, &destRect, angle, &rotationPoint, SDL_FLIP_NONE);
    }
    if (!changedDest && changedSrc) {
        
        SDL_RenderCopyEx(r, texture, &srcRect, NULL, angle, &rotationPoint, SDL_FLIP_NONE);
    } 
}

void Sprite::setDest(float p_x, float p_y, float p_width, float p_height) {
    x = p_x;
    y = p_y;
    width = p_width;
    height = p_height;   

    destRect.x = x;
    destRect.y = y;
    destRect.w = width;
    destRect.h = height;
    
    changedDest = true;
}

void Sprite::setSource(float p_x, float p_y, float p_width, float p_height) {
    srcRect.x = p_x;
    srcRect.y = p_y;
    srcRect.w = p_width;
    srcRect.h = p_height;
    
    changedSrc = true;
}

void Sprite::setHitbox(float p_x, float p_y, float p_width, float p_height) {
    hitbox_offsetX = p_x;
    hitbox_offsetY = p_y;    

    hitbox.x = x +  hitbox_offsetX;
    hitbox.y = y + hitbox_offsetY;;
    
    hitbox.w = p_width;
    hitbox.h = p_height; 
    
    red = 255;
    green = 255;
    blue = 255;
    
}

void Sprite::setHitbox(float p_x, float p_y, float p_width, float p_height, int color[3]) {

    hitbox.w = p_width;
    hitbox.h = p_height; 

    hitbox_offsetX = p_x;
    hitbox_offsetY = p_y;    

    hitbox.x = x +  hitbox_offsetX;
    hitbox.y = y + hitbox_offsetY;
    
    red = color[0];
    green = color[1];
    blue = color[2];
    
}

void Sprite::drawHitbox(SDL_Renderer* r) {
    hitbox.x = x + hitbox_offsetX;
    hitbox.y = y + hitbox_offsetY;
    
    SDL_SetRenderDrawColor(r, red, green, blue, 255);
    SDL_RenderFillRect(r, &hitbox);
}

bool Sprite::collideSprite(Sprite spr) {
	if (SDL_HasIntersection(&spr.hitbox, &hitbox)) {
		return true;
	}
	else {
		return false;
	}
}

bool Sprite::collideRect(Rect rect) {
	if (SDL_HasIntersection(&hitbox, &rect.rect)) {
		return true;
	}
	else {
		return false;
	}
}

void Sprite::scaleBy(float p_scaleByW, float p_scaleByH) {
    width += p_scaleByW;
    height += p_scaleByH;
}

void Sprite::setScale(float p_scaleW, float p_scaleH) {
    width = p_scaleW;
    height = p_scaleH;
}

float Sprite::getRotation() {
	return angle;
}

void Sprite::rotateBy(float p_rotateBy) {
    angle += p_rotateBy;
    
}

void Sprite::setRotation(float p_rotation) {
    angle = p_rotation; 
}

void Sprite::setRotationPoint(float p_x, float p_y) {
    rotationPoint.x = x + p_x;
    rotationPoint.y = y + p_y;
}

void Sprite::setRotationPointToCenter() {
    rotationPoint.x = width/2;
    rotationPoint.y = height/2;   
}

void Sprite::setPos(float p_x, float p_y) {
    x = p_x;
    y = p_y;
}

void Sprite::moveBy(float p_x, float p_y) {
    x += p_x;
    y += p_y;
}

void Sprite::hitboxUpdate() {
	hitbox.x = x + hitbox_offsetX;
	hitbox.y = y + hitbox_offsetY;
}
