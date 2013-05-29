#ifndef BLOCKSLOW_H
#define BLOCKSLOW_H

#include "block.h"


class BlockSlow : public Block
{
    public:
        BlockSlow();
        BlockSlow(float x, float y, int width, int height,
              SDL_Surface *image, SDL_Surface *screen,
              Dot *dot);
        void logic();
        int time;

        virtual ~BlockSlow();
    protected:
    private:
};

#endif // BLOCKSLOW_H
