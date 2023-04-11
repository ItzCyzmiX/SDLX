#include <SDLX/Window.hpp>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
using namespace std;

Window::Window(const char* title, int wi, int h, bool resize = false) {
    if (SDL_INIT_EVERYTHING < 0) {
        cout << "Failed Initilasing SDL! \nError:" << SDL_GetError() << "\n";
        error = true;
        quit();
    }

	if (TTF_Init() < 0) {
		cout << "Failed Initilasing the TTF library!\nError: " << SDL_GetError() << "\n";
	}

	if (IMG_Init < 0) {
		cout << "Failed Initilasing the IMG library!\nError: " << SDL_GetError() << "\n";
	}
	    
    createWindow(title, wi, h, resize);
    
};

void Window::beginDrawing() {
	SDL_RenderClear(this->r);
	SDL_SetRenderDrawColor(this->r, 255, 255, 255, 255);	
};

void Window::endDrawing() {
	SDL_SetRenderDrawColor(this->r, this->bgColor[0], this->bgColor[1], this->bgColor[2], 255);
	SDL_RenderPresent(this->r);		
};

void Window::setBgColor(int newColor[3]) {
	for (int i; i < 3; i++) {
		this->bgColor[i] = newColor[i];
	}	
};

void Window::setScreenSize(int w, int h) {
	this->screenWidth = w;
	this->screenHeight = h;	
};

void Window::createWindow(const char* title, int wi, int h, bool resize) {
	setScreenSize(wi, h);

	if (!resize) {
		w = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
	} else {
		w = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);	
	}
	
	if (w == NULL) {
		cout << "Failed to create window \n ERROR: " << SDL_GetError() << "\n";
	}
	
	r = SDL_CreateRenderer(w, -1, SDL_RENDERER_ACCELERATED);

	if (r == NULL) {
		cout << "Failed to create renderer \n ERROR: " << SDL_GetError() << "\n";
	}

};

bool Window::checkClose() {
    SDL_Event e;
    
    while(SDL_PollEvent(&e)){
        if(e.type == SDL_QUIT) {
            this->running = false;
            return true;
        }
    }
    return false;
};

SDL_Renderer* Window::getRenderer() {
	return this->r;
};

SDL_Window* Window::getWindow(){
	return this->w;
};

bool Window::checkError() {
	if (this->error) cout << "Error: " << SDL_GetError() << "\n";
	return this->error;
};

void Window::quit() {
	SDL_DestroyWindow(this->w);
	SDL_DestroyRenderer(this->r);
	SDL_Quit();
};
