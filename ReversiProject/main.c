//#include <ncurses.h>
#include "header.h"

void initallegro(BITMAP *page,BITMAP *scorep1,BITMAP *scorep2,BITMAP *infos, BITMAP *tableau,BITMAP *white,BITMAP *black){

    //change screen color
    clear_to_color(screen, makecol(38,51,111));
    clear_to_color(scorep1, makecol(38,51,111));
    clear_to_color(scorep2, makecol(200,51,1));
    clear_to_color(infos, makecol(38,51,111));

    //black player infos
    textout_ex(screen,//Specify bitmap on the screen
             font,//Use a default font
             "Black Player :",//Specify the text to display
             50,//X-coordinate for text
             120,//Y-coordinate for text
             makecol(255,255,255),//Color text
             makecol( 38,51,111) );//Put color behind text

    textout_ex(screen,font,"Kevin",50,140,makecol(255,255,255),makecol( 38,51,111));

    //white player
    textout_ex(screen,font,"White Player :",650,120,makecol(255,255,255),makecol( 38,51,111));
    textout_ex(screen,font,"Dylan",650,140,makecol(255,255,255),makecol( 38,51,111));

    //init tableau and 4 start boxes
    // the first case is located in 200,100 ( X,Y) and each case are separated by 50px;
    blit(tableau,screen,0,0,192,92,SCREEN_W,SCREEN_H);
    blit(black,screen,0,0,404,254,SCREEN_W,SCREEN_H);
    blit(black,screen,0,0,354,304,SCREEN_W,SCREEN_H);
    blit(white,screen,0,0,404,304,SCREEN_W,SCREEN_H);
    blit(white,screen,0,0,354,254,SCREEN_W,SCREEN_H);
    show_mouse(screen);
}

int getMouseUser(struct player *player){
    int x,y;
    int good=0;
    //get the x,y coord on the grid when the user click
    x=(mouse_x-200)/50;
    y=(mouse_y-100)/50;
    printf("%d , %d\n",x,y);
    //return if the mouv is valid or not (0 for invalid and 1 for valid)
    good = placer(y,x,player);
    return good;
}

int main(int argc , char *argv[])
{
    lancerToutAllegro(800,600);

    //create bitmaps
    //our all page
    BITMAP *page=NULL;
    //buffer for scores and infos
    BITMAP *scorep1=NULL;
    BITMAP *scorep2=NULL;
    BITMAP *infos=NULL;
    BITMAP *tableau=NULL;
    BITMAP *black=NULL;
    BITMAP *white=NULL;


     //load images
    page=create_bitmap(SCREEN_W,SCREEN_H);
    scorep1=create_bitmap(100,20);
    scorep2=create_bitmap(100,20);
    infos=create_bitmap(200,20);
    tableau=chargerImage("images/tableau.bmp");
    white=chargerImage("images/jeton_blanc.bmp");
    black=chargerImage("images/jeton_noir.bmp");


    int lin,col; // get the input of the user for test
    int tour=0; // loop change for player change
    int i,j;
    int validMouv=0;
    struct player *p1,*p2;
    p1 = (struct player *)malloc(sizeof(struct player));
    p2 = (struct player *)malloc(sizeof(struct player));

    p1->state=1;
    p2->state=2;
    p2->point=0;
    p2->point=0;

    initslot();
    creationGrille();

    initallegro(page,scorep1,scorep2,infos,tableau,white,black);

    while(!key[KEY_ESC]){
    // update our bitmap for infos and score
    clear_bitmap(scorep1);
    clear_bitmap(scorep2);
    clear_bitmap(infos);

    validMouv=0;
    //updateGrid(0b10010011);
    if(tour==0){
        if(mouse_b&1){
            validMouv = getMouseUser(p1);
            if(validMouv==1){
            for(i=0;i<100000000;i++){}
            updateBlock(screen,white,black);
            tour++;
            }
        }
    }
    if(tour==1){
            /*if(mouse_b&1){
            validMouv = getMouseUser(p2);
            if(validMouv==1){
            for(i=0;i<100000000;i++){}
            updateBlock(screen,white,black);
            tour=0;
            }
        }*/
        validMouv = jouer(p2);
        if(validMouv==1){
        for(i=0;i<100000000;i++){}
            updateBlock(screen,white,black);
            tour=0;
        }
    }

    getScore(p1,p2);
    textprintf_ex(scorep1, font, 0, 0, makecol(255, 255, 255),-1, "Points : %d", p1->point);
    textprintf_ex(scorep2, font, 0, 0, makecol(255, 255, 255),-1, "Points : %d", p2->point);
    if(tour==0){
        textout_ex(infos,font,"Playing : Black ",0,0,makecol(255,255,255),makecol( 38,51,111));
    }
    else {
        textout_ex(infos,font,"Playing : White ",0,0,makecol(255,255,255),makecol( 38,51,111));
    }
    blit(scorep1,screen,0,0,50,160,SCREEN_W,SCREEN_H);
    blit(scorep2,screen,0,0,650,160,SCREEN_W,SCREEN_H);
    blit(infos,screen,0,0,300,50,SCREEN_W,SCREEN_H);
    }

    //clear the bitmap page
    clear_bitmap(page);
    return 0;
}
END_OF_MAIN();
