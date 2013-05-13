#include "block.h"

Block::Block()
{
    //ctor
}

Block::~Block()
{
    //dtor
}

Block::Block(float x, float y, int width, int height,SDL_Surface *image,SDL_Surface *screen, Dot *dot){
this->x = x;
this->y = y;
this->width = width;
this->height = height;
this->screen = screen;
this->image = image;
this->dot = dot;
this->isColliding = false;
this->wasColliding = false;
this->life = 2;
}

void Block::show(){
    if (life > 0){
apply_surface( x, y, image, screen);
    }
}

void Block::logic(){
  //  int dotHeight = dot->y + dot->DOT_HEIGHT;





        int collision = collisionType();
        if(!wasColliding){
        switch(collision){
        case 0:
        break;

        case TOP:
                dot->angle = -dot->angle;
                dot->angle += rand()%10 - 20;
                this->life--;
            break;
        case BOT:
            dot->angle = -dot->angle;
            dot->angle += rand()%10 - 20;
            this->life--;
            break;

        case RIGHT: case LEFT:
            dot->angle = -dot->angle+180;
            dot->angle += rand()%10 - 20;
            this->life--;
            break;
         case CORNERUL:
             dot->velocity = abs(dot->velocity);
             dot->angle = 315;
             dot->angle += rand()%5-10;
             this->life--;
             break;
        case CORNERUR:
            dot->velocity = abs(dot->velocity);
             dot->angle = 225;
             dot->angle += rand()%5-10;
             this->life--;
             break;
        case CORNERDR:
            dot->velocity = abs(dot->velocity);
             dot->angle = 135;
             dot->angle += rand()%5-10;
             this->life--;
             break;
        case CORNERDL:
            dot->velocity = abs(dot->velocity);
             dot->angle = 45;
             dot->angle += rand()%5-10;
             this->life--;
        }

        }

}

bool Block::isPointInside(float pointX, float pointY){
if(    pointX > this->x
       && pointX < this->x+this->width
       && pointY > this->y
       && pointY < this->y + this->height){
       return true;
       }
       return false;
}

int Block::collisionType(){
        // ESQUINA SUPERIOR IZQUIERDA   dot->x                  dot->y
        // ESQUINA SUPERIOR DERECHA     dot->x + DOT_WIDTH      dot->y
        // ESQUINA INFERIOR IZQUIERDA   dot->x                  dot->y + DOT_HEIGHT
        // ESQUINA INFERIOR DERECHA     dot->x + DOT_WIDTH      dot->y + DOT_HEIGHT
        float posX = dot->x;
        float posXMid = dot->x + (dot->DOT_WIDTH/2);
        float posXEnd = dot->x + dot->DOT_WIDTH;
        float posY = dot->y, posYMid = dot->y+ dot->DOT_HEIGHT/2, posYEnd = dot->y + dot->DOT_HEIGHT;

        if(this->isColliding){
            this->wasColliding = true;
        } else {
        this->wasColliding =false;
        }

        this->isColliding = false;
        if (!this->wasColliding){
        if(    isPointInside(posX,posY)
                &&
                isPointInside(posXMid,posY)
                ||
               isPointInside(posXMid,posY)
                &&
                 isPointInside(posXEnd,posY)
                ){
                    this->isColliding = true;
                    return TOP;
        } else if (
                   isPointInside(posX,posYEnd)
                && isPointInside(posXMid,posYEnd)
                ||
                 isPointInside(posXMid,posYEnd)
                && isPointInside(posXEnd,posYEnd)

                ){
                    this->isColliding = true;
                    return BOT;

        }else if (

                  isPointInside(posX,posY)
            &&
                isPointInside(posX,posYMid)
                ||
                 isPointInside(posX,posYMid)
               && isPointInside(posX,posYEnd)

                   ){
                        this->isColliding = true;
                        return LEFT;
        }else if (

                  isPointInside(posXEnd,posY)
                &&
                isPointInside(posXEnd,posYMid)
                ||
                 isPointInside(posXEnd,posYMid)
                && isPointInside(posXEnd,posYEnd)

                   ){
                    this->isColliding = true;
                    return RIGHT;
        }else if (isPointInside(posX,posY)){
        return CORNERUL;
        }else if(isPointInside(posX,posYEnd)){
        return CORNERDL;
        }else if(isPointInside(posXEnd,posY)){
        return CORNERUR;
        }else if(isPointInside(posXEnd,posYEnd)){
        return CORNERDR;
        }

        }

        return 0;
}


