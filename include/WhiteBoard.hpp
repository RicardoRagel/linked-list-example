#ifndef WHITEBOARD_H
#define WHITEBOARD_H

#include <iostream>
#include "SDL.h"
#include <SDL2/SDL_ttf.h>

class WhiteBoard
{
    public:
        // Constructor
        WhiteBoard();

        // Destructor
        ~WhiteBoard();

        // Create and open the windows
        bool open(int win_w, int win_h, int win_x = SDL_WINDOWPOS_UNDEFINED, int win_y = SDL_WINDOWPOS_UNDEFINED);

        // Close and destroy the windows
        void close();

        // Get window widht and height
        int getW();
        int getH();

        // Draw a new node at x, y
        void drawNode(int x, int y);

        // Draw tag
        void drawTag(int x, int y, std::string text);

        // Draw a new arrow from x1, y1 to x2, y2
        void drawArrow(int x1, int y1, int x2, int y2);
    
    private:
        SDL_Window *screen; // window handler
        SDL_Renderer *renderer; // window renderer handler
        int win_x_, win_y_, win_w_, win_h_; // window properties
        int node_radius_ {5};   // pxs

        void drawPoint(int x, int y, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
        void drawCircle(int x, int y, int radius, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
        void fillCircle(int x, int y, int radius, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
};

#endif