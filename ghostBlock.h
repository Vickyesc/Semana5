#ifndef GHOSTBLOCK_H
#define GHOSTBLOCK_H

#include "block.h"



class ghostBlock: public Block
{
    public:
        ghostBlock();
        ghostBlock(float x, float y, int width, int height,
              SDL_Surface *image, SDL_Surface *screen,Dot *dot);
        void logic();
        int time;

        virtual ~ghostBlock();
    protected:
    private:
};

#endif // GHOSTBLOCK_H
