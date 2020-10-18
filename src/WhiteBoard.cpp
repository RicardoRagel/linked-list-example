#include "WhiteBoard.hpp"

WhiteBoard::WhiteBoard()
{
    // SDL windows initialization
    if(SDL_Init(SDL_INIT_VIDEO) != 0) 
    {
        fprintf(stderr, "Could not init SDL: %s\n", SDL_GetError());
        exit(0);
    }
}
WhiteBoard::~WhiteBoard()
{
    close();
}

bool WhiteBoard::open(int win_w, int win_h, int win_x, int win_y)
{
    // Save win properties
    win_x_ = win_x; 
    win_y_ = win_y;
    win_w_ = win_w; 
    win_h_ = win_h;

    // Create window
    screen = SDL_CreateWindow("WhiteBoard", win_x_, win_y_, win_w_, win_h_, 0);
    if(!screen) 
    {
        fprintf(stderr, "Could not create window\n");
        return 1;
    }

    // Draw background
    renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_SOFTWARE);
    if(!renderer) {
        fprintf(stderr, "Could not create renderer\n");
        return 1;
    }
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    TTF_Init();
}

void WhiteBoard::close()
{
    // Close and destroy the window
    SDL_DestroyWindow(screen);
    SDL_Quit();
    TTF_Quit();
}

int WhiteBoard::getW()
{
    return win_w_;
}

int WhiteBoard::getH()
{
    return win_h_;
}

void WhiteBoard::drawNode(int x, int y)
{
    drawCircle(x, y, node_radius_, 0, 0, 0, 255);
    fillCircle(x, y, node_radius_, 0, 0, 0, 255);
    SDL_RenderPresent(renderer);
}

void WhiteBoard::drawTag(int x, int y, std::string text)
{
    TTF_Font* Sans = TTF_OpenFont("DejaVuSerif.ttf", 14); //this opens a font style and sets a size
    SDL_Color Black = {0, 0, 0, 255};
    SDL_Surface* surfaceMessage = TTF_RenderText_Blended(Sans, text.c_str(), Black); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first
    SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage); //now you can convert it into a texture
    SDL_Rect Message_rect; //create a rect
    Message_rect.x = x;  //controls the rect's x coordinate 
    Message_rect.y = y; // controls the rect's y coordinte
    Message_rect.w = surfaceMessage->w; // controls the width of the rect
    Message_rect.h = surfaceMessage->h; // controls the height of the rect
    SDL_RenderCopy(renderer, Message, NULL, &Message_rect); //you put the renderer's name first, the Message, the crop size(you can ignore this if you don't want to dabble with cropping), and the rect which is the size and coordinate of your texture
    SDL_RenderPresent(renderer);
    SDL_FreeSurface(surfaceMessage);
    TTF_CloseFont(Sans);
}

void WhiteBoard::drawArrow(int x1, int y1, int x2, int y2)
{
    printf("Drawing arrow from %d, %d to %d, %d\n", x1, y1, x2, y2);

    // line
    SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);
    if(y2 >= y1)
        SDL_RenderDrawLine(renderer, x1, y1 + node_radius_, x2, y2 - node_radius_);
    else
        SDL_RenderDrawLine(renderer, x1, y1 - node_radius_, x2, y2 + node_radius_);
    
    // triangle at the end of the line
    // if(y2 >= y1)
    // {
    //     int i = 0;
    //     for(int j = y2 - node_radius_; j >= y2 - 2*node_radius_; j--, i++)
    //         SDL_RenderDrawLine(renderer, x2 - i, j, x2 + i, j);
    // }
    // else
    // {
    //     int i = 0;
    //     for(int j = y2 + node_radius_; j <= y2 + 2*node_radius_; j++, i++)
    //         SDL_RenderDrawLine(renderer, x2 - i, j, x2 + i, j);
    // }
    
    SDL_RenderPresent(renderer);
}

void WhiteBoard::drawPoint(int x, int y, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	SDL_RenderDrawPoint(renderer, x, y);
}

void WhiteBoard::drawCircle(int center_x, int center_y, int radius, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	double error = (double)-radius;
	double x = (double)radius - 0.5;
	double y = (double)0.5;
	double cx = center_x - 0.5;
	double cy = center_y - 0.5;

	while (x >= y)
	{
		drawPoint((int)(cx + x), (int)(cy + y), r, g, b, a);
		drawPoint((int)(cx + y), (int)(cy + x), r, g, b, a);

		if (x != 0)
		{
			drawPoint((int)(cx - x), (int)(cy + y), r, g, b, a);
			drawPoint((int)(cx + y), (int)(cy - x), r, g, b, a);
		}

		if (y != 0)
		{
			drawPoint((int)(cx + x), (int)(cy - y), r, g, b, a);
			drawPoint((int)(cx - y), (int)(cy + x), r, g, b, a);
		}

		if (x != 0 && y != 0)
		{
			drawPoint((int)(cx - x), (int)(cy - y), r, g, b, a);
			drawPoint((int)(cx - y), (int)(cy - x), r, g, b, a);
		}

		error += y;
		++y;
		error += y;

		if (error >= 0)
		{
			--x;
			error -= x;
			error -= x;
		}
	}
}

void WhiteBoard::fillCircle(int x, int y, int radius, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	for (double dy = 1; dy <= radius; dy += 1.0)
	{
		double dx = floor(sqrt((2.0 * radius * dy) - (dy * dy)));
		SDL_SetRenderDrawColor(renderer, r, g, b, a);
		SDL_RenderDrawLine(renderer, x - dx, y + dy - radius, x + dx, y + dy - radius);
		SDL_RenderDrawLine(renderer, x - dx, y - dy + radius, x + dx, y - dy + radius);
	}
}