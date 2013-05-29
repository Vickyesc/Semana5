#ifndef ZOMBIEBLOCKS_H
#define ZOMBIEBLOCKS_H

#include "block.h"


class ZombieBlocks : public Block
{
    public:
        ZombieBlocks();
        ZombieBlocks(float x, float y, int width, int height,
              SDL_Surface *image, SDL_Surface *screen,Dot *dot);
        void logic();
        int time;

        virtual ~ZombieBlocks();
    protected:
    private:
};

#endif // ZOMBIEBLOCKS_H
