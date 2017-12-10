/*
Authors : Flavien Pechere
          Hadrien Vinay
          Arnaud Goguel
*/
#include "header.h"

//display menu allegro
void initMenu(BITMAP *page, BITMAP *menu)
{
    blit(menu,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    // clear_to_color(screen, makecol(38,51,111));
    // textout_ex(screen,font,"Player vs Player",0,0,makecol(255,255,255),makecol( 38,51,111));
    show_mouse(screen);

}

//return selected case to play
int menuChoice()
{
    // play player vs player
    if(mouse_x>60 && mouse_x<240 && mouse_y>320 && mouse_y<365 && mouse_b&1)
    {
        return 1;
    }
    // play player vs ia
    if(mouse_x>330 && mouse_x<500 && mouse_y>320 && mouse_y<365 && mouse_b&1)
    {
        return 2;
    }
    // ia vs ia
    if(mouse_x>540 && mouse_x<790 && mouse_y>320 && mouse_y<365 && mouse_b&1)
    {
        return 3;
    }
    if(mouse_x>10 && mouse_x<100 && mouse_y>545 && mouse_y<600 && mouse_b&1){
        return 4;
    }
    if(mouse_x>290 && mouse_x<530 && mouse_y>500 && mouse_y<540 && mouse_b&1){
        return 5;
    }

}

//return ia level
int chooseIaLevel()
{
   // play easy ia
    if(mouse_x>60 && mouse_x<240 && mouse_y>320 && mouse_y<365 && mouse_b&1)
    {
        return 1;
    }
    // play medium ia
    else if(mouse_x>330 && mouse_x<500 && mouse_y>320 && mouse_y<365 && mouse_b&1)
    {
        return 2;
    }
    // play hard ia
    else if(mouse_x>540 && mouse_x<790 && mouse_y>320 && mouse_y<365 && mouse_b&1)
    {
        return 3;
    }
    else return 0;
}

//update all element on our grid
void initallegro(BITMAP *page,BITMAP *scorep1,BITMAP *scorep2,BITMAP *infos,BITMAP *timer, BITMAP *tableau,BITMAP *white,BITMAP *black)
{

    //change screen color
    clear_to_color(screen, makecol(38,51,111));
    clear_to_color(scorep1, makecol(38,51,111));
    clear_to_color(scorep2, makecol(200,51,1));
    clear_to_color(infos, makecol(38,51,111));
    clear_to_color(timer, makecol(38,51,111));

    //black player infos
    textout_ex(screen,//Specify bitmap on the screen
               font,//Use a default font
               "Black Player :",//Specify the text to display
               50,//X-coordinate for text
               120,//Y-coordinate for text
               makecol(255,255,255),//Color text
               makecol( 38,51,111) );//Put color behind text

    textout_ex(screen,font,"Player 1",50,140,makecol(255,255,255),makecol( 38,51,111));

    //white player
    textout_ex(screen,font,"White Player :",650,120,makecol(255,255,255),makecol( 38,51,111));
    textout_ex(screen,font,"Player 2",650,140,makecol(255,255,255),makecol( 38,51,111));

    //init tableau and 4 start boxes
    // the first case is located in 200,100 ( X,Y) and each case are separated by 50px;
    blit(tableau,screen,0,0,192,92,SCREEN_W,SCREEN_H);
    //blit(black,screen,0,0,404,254,SCREEN_W,SCREEN_H);
    //blit(black,screen,0,0,354,304,SCREEN_W,SCREEN_H);
    //blit(white,screen,0,0,404,304,SCREEN_W,SCREEN_H);
    //blit(white,screen,0,0,354,254,SCREEN_W,SCREEN_H);
    show_mouse(screen);
}

//convert mouse_x and mouse_y in integer (0,0) or (7,6) ...
int getMouseUser(struct player *player)
{
    double x,y;
    int good=0;
    //get the x,y coord on the grid when the user click
    x=(mouse_x-200)/50;
    y=(mouse_y-100)/50;
    printf("%d , %d\n",x,y);
    trunc(x);
    trunc(y);
    //return if the mouv is valid or not (0 for invalid and 1 for valid)
    good = placer(y,x,player,0);
    return good;
}
