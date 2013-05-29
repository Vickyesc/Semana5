#ifndef SUPERBLOCK_H
#define SUPERBLOCK_H

#include "block.h"

class superBlock: public Block
{
    public:
        superBlock();
         superBlock(float x, float y, int width, int height,
              SDL_Surface *image, SDL_Surface *screen,Dot *dot);
        void logic();
        int time;
        virtual ~superBlock();
    protected:
    private:
};

#endif // SUPERBLOCK_H
