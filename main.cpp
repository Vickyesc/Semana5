/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redistributed without written permission.*/

//The headers
#include "SDL.h"
#include "SDL_image.h"
#include "Timer.h"
#include "Particle.h"
#include "Dot.h"
#include <string>
#include <cstdlib>
#include "block.h"
#include "BlockSlow.h"
#define PI 3.14159265
#include <list>
#include "paddle.h"
#include "ZombieBlocks.h"
#include "superBlock.h"
#include "ghostBlock.h"


using namespace std;

//The surfaces

const int SCREEN_BPP = 32;

//The frame rate
const int FRAMES_PER_SECOND = 60;

//The surfaces
SDL_Surface *screen = NULL;

//The event structure
SDL_Event event;

bool init()
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        return false;
    }

    //Set the window caption
    SDL_WM_SetCaption( "Semana 5", NULL );

    //Seed random
    srand( SDL_GetTicks() );

    //If everything initialized fine
    return true;
}

void clean_up()
{
    SDL_Quit();
}

int main( int argc, char* args[] )
{
    //Timer myTimer;

    //Timer startStop = TTF_RenderText_Solid( font, "Press S to start or stop the timer", textColor );
    //Timer pauseMessage = TTF_RenderText_Solid( font, "Press P to pause or unpause the timer", textColor );

    //Quit flag
    bool quit = false;

    //The frame rate regulator
    Timer fps;

    //Initialize
    if( init() == false )
    {
        return 1;
    }

    //The dot that will be used
    Dot myDot(screen);


    SDL_Surface *block_image = load_image("block.png");
    SDL_Surface *blockslow_image = load_image("blockslow.png");
    SDL_Surface *blocklower_image = load_image("blocklower.png");
    SDL_Surface *blocksuper_image = load_image("superBlock.png");
    SDL_Surface *blockghost_image = load_image("ghostBlock.png");

    Paddle *lower = new Paddle((float)SCREEN_WIDTH/2,(float)SCREEN_HEIGHT-10,100,25,blocklower_image,screen,&myDot,&event);

    Block *block = new Block(100,100,103,53,block_image,screen,&myDot);
    Block *block2 = new BlockSlow(100,150,103,53,blockslow_image,screen,&myDot);
    Block *block3 = new superBlock(100,200,103,53,blocksuper_image,screen,&myDot);
    Block *block4 = new Block(250,150,103,53,block_image,screen,&myDot);
    Block *block5 = new ZombieBlocks(400,100,103,53,block_image,screen,&myDot);
    Block *block6 = new Block(400,150,103,53,block_image,screen,&myDot);
    Block *block7 = new Block(400,200,103,53,block_image,screen,&myDot);
    Block *block8 = new ZombieBlocks(250,20,103,53,block_image,screen,&myDot);
    Block *block9 = new ghostBlock(250,275,103,53,blockghost_image,screen,&myDot);

    block2->life =3;


    list < Block* > block_list;
    block_list.push_back(block);
    block_list.push_back(block2);
    block_list.push_back(block3);
    block_list.push_back(block4);
    block_list.push_back(block5);
    block_list.push_back(block6);
    block_list.push_back(block7);
    block_list.push_back(block8);
    block_list.push_back(block9);




    //While the user hasn't quit
    while( quit == false )
    {

        //Start the frame timer
        fps.start();

        //While there's events to handle
        while( SDL_PollEvent( &event ) )
        {
            //Handle events for the dot
            myDot.handle_input();

            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }
        }

        //Move the dot
        myDot.move();
        lower->handleInput();
        lower->logic();

        list <Block*>::iterator block_iterator = block_list.begin();

        while(block_iterator != block_list.end()){

            Block* block_temp= *block_iterator;
            block_temp->logic();

            if(block_temp->life <=0){
                block_list.erase(block_iterator);
                block_iterator--;
            }
            block_iterator++;

        }


/*
        if (block != 0){
        block->logic();
        if (block->life <= 0){
            delete block;
            block = 0;
        }
        }
        if (block2 != 0){
        block2->logic();
        if (block2->life <= 0){
            delete block2;
            block2 = 0;
        }
        } */


        //Fill the screen white
        SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );

        //Show the dot on the screen
        myDot.show();
        lower->show();

         block_iterator = block_list.begin();
        while(block_iterator != block_list.end()){

            Block* block_temp= *block_iterator;
            block_temp->show();
            block_iterator++;

        }



        //Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }

        //Cap the frame rate
        if( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
        {
            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
        }
    }

    //Clean up
    clean_up();

    return 0;
}
