//#include <ncurses.h>
#include "header.h"

void initallegro(){
    //allegro init
    lancerToutAllegro(800,600);
    //init score to 2 for each player
    int score=2;
    //create bitmaps
    BITMAP *page;
    BITMAP *tableau;
    BITMAP *black;
    BITMAP *white;
    //load images
    page=create_bitmap(SCREEN_W,SCREEN_H);
    tableau=chargerImage("images/tableau.bmp");
    white=chargerImage("images/jeton_blanc.bmp");
    black=chargerImage("images/jeton_noir.bmp");
    //change screen color
    clear_to_color(screen, makecol(38,51,111));


    textout_ex(screen,//Specify bitmap on the screen
             font,//Use a default font
             "Black Player :",//Specify the text to display
             50,//X-coordinate for text
             120,//Y-coordinate for text
             makecol(255,255,255),//Color text
             makecol( 38,51,111) );//Put color behind text

    textout_ex(screen,font,"Kevin",50,140,makecol(255,255,255),makecol( 38,51,111));
    textprintf_ex(screen, font, 50, 160, makecol(255, 255, 255),-1, "Points : %d", score);


    textout_ex(screen,font,"White Player :",650,120,makecol(255,255,255),makecol( 38,51,111));
    textout_ex(screen,font,"Dylan",650,140,makecol(255,255,255),makecol( 38,51,111));
    textprintf_ex(screen, font, 650, 160, makecol(255, 255, 255),-1, "Points : %d", score);
    //init tableau and 4 start boxes
    // the first case is located in 200,100 ( X,Y) and each case are separated by 50px;

    blit(tableau,screen,0,0,192,92,SCREEN_W,SCREEN_H);
    blit(black,screen,0,0,404,254,SCREEN_W,SCREEN_H);
    blit(black,screen,0,0,354,304,SCREEN_W,SCREEN_H);
    blit(white,screen,0,0,404,304,SCREEN_W,SCREEN_H);
    blit(white,screen,0,0,354,254,SCREEN_W,SCREEN_H);
    show_mouse(screen);
}

int main(int argc , char *argv[])
{


    int lin,col; // get the input of the user for test
    int tour=0; // loop change for player change
    int i,j;
    struct player *p1,*p2;
    p1 = (struct player *)malloc(sizeof(struct player));
    p2 = (struct player *)malloc(sizeof(struct player));

    p1->state=1;
    p2->state=2;
    p2->point=0;
    p2->point=0;

    initslot();
    creationGrille();


    initallegro();

    while(1){
    //updateGrid(0b10010011);
    printf("ligne :");
    scanf("%d",&lin);
    printf("colonne :");
    scanf("%d",&col);
    printf("%d,%d\n",lin,col);
    if(tour==0%2){
            placer(lin,col,p1);
    }
    else {
            placer(lin,col,p2);
    }

    getScore(p1,p2);
    printf("\n Player 1 : %d \n Player 2 : %d\n",p1->point,p2->point);
    tour ++;
    updateBlock();
    }
    return 0;
}
END_OF_MAIN();
