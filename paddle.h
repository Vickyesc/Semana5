#ifndef PADDLE_H
#define PADDLE_H

#include "block.h"


class Paddle : public Block
{
    public:
        Paddle();

        virtual ~Paddle();
        void handleInput();

    protected:
    private:
};

#endif // PADDLE_H
