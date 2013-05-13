#ifndef PARTICLE_H
#define PARTICLE_H

#include "SDL.h"
#include "SDL_image.h"
#include "Utility.h"
#include <string>
#include <cstdlib>

class Particle
{
    private:
    //Offsets
    int x, y;

    //Current frame of animation
    int frame;

    SDL_Surface *screen;

    SDL_Surface *type;
    SDL_Surface *shimmer = NULL;


    public:
    //Constructor
    Particle( int X, int Y , SDL_Surface* screen, SDL_Surface *type);

    //Shows the particle
    void show();

    //Checks if particle is dead
    bool is_dead();
};

#endif // PARTICLE_H
