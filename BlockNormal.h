#ifndef BLOCKNORMAL_H
#define BLOCKNORMAL_H

#include "block.h"


class BlockNormal : public Block
{
    public:
        BlockNormal();
        BlockNormal(float x, float y, int width, int height,
              SDL_Surface *image, SDL_Surface *screen,
              Dot *dot);
        void logic();

        virtual ~BlockNormal();
    protected:
    private:
};

#endif // BLOCKNORMAL_H
