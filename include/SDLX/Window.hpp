#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL2/SDL.H>
#include <stdio.h>
#include <iostream>

class Window {
    public:

        bool running = true;
        int screenWidth;
        int screenHeight;

        int bgColor[3] = {50, 50, 50}; 

        Window(const char* title, int wi, int h, bool resize);

        void beginDrawing();

        void endDrawing();

        void setScreenSize(int w, int h);

        void setBgColor(int newColor[3]);
        
        bool checkClose();

        bool checkError();

        void quit();

        SDL_Renderer* getRenderer();

        SDL_Window* getWindow();

    private:
        SDL_Renderer* r;
        SDL_Window* w;
        bool error = false;
        
        void createWindow(const char* title,int wi, int h, bool resize);
};


#endif /* WINDOW_HPP */

