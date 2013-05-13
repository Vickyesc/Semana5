#ifndef BLOCK_H
#define BLOCK_H
#include "SDL.h"
#include "SDL_image.h"
#include "Utility.h"
#include "Dot.h"

enum{
        NONE,
        TOP,
        BOT,
        LEFT,
        RIGHT,
        CORNERUL,
        CORNERUR,
        CORNERDL,
        CORNERDR,
        COLLIDING
        };

class Block
{

    public:

        bool isColliding;
        bool wasColliding;
        Block();
        float x, y;
        int life;
        int width,height;
        SDL_Surface *image;
        SDL_Surface *screen;
        Dot *dot;
        Block(float x, float y, int width, int height,
              SDL_Surface *image, SDL_Surface *screen,
              Dot *dot);
        int collisionType();
        bool isPointInside(float pointX, float pointY);
        void show();
        void logic();

        virtual ~Block();
    protected:
    private:
};

#endif // BLOCK_H
