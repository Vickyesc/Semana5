#ifndef DOT_H
#define DOT_H

#include <cmath>
#include "Utility.h"
#include "Particle.h"

#define PI 3.14159265
#define TOTAL_PARTICLES 20


class Dot
{
    private:
    //The offsets

    SDL_Surface *red = NULL;
    SDL_Surface *green = NULL;
    SDL_Surface *blue = NULL;

    SDL_Surface *dot = NULL;


    SDL_Surface *screen;

    //The particles
    Particle *particles[ TOTAL_PARTICLES ];

    public:
        float x, y;

        float angle, velocity;

        const float DOT_WIDTH = 20;
        const float DOT_HEIGHT = 20;

    //Initializes
    Dot(SDL_Surface *screen);

    //Cleans up particles
    ~Dot();

    //Handles keypresses
    void handle_input();

    //Moves the dot
    void move();

    //Shows the particles
    void show_particles();

    //Shows the dot
    void show();
    void ghostDot();
    void superDot();
};

#endif // DOT_H
