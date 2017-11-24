//#include <ncurses.h>
#include "header.h"

int main(int argc , char *argv[])
{
    //allegro init
    lancerToutAllegro(800,600);

    //create bitmaps
    BITMAP *page;
    BITMAP *tableau;
    //load images
    page=create_bitmap(SCREEN_W,SCREEN_H);
    tableau=chargerImage("images/tableau.bmp");
    /*textout_ex(screen,//Specify bitmap on the screen
             font,//Use a default font
             "HELLO WORLD",//Specify the text to display
             20,//X-coordinate for text
             30,//Y-coordinate for text
             makecol(255,255,0),//Color text yellow
             makecol( 255,0,0) );//Put red behind text
             */
    blit(tableau,screen,0,0,0,100,SCREEN_W,SCREEN_H);
    show_mouse(screen);

    int lin,col; // get the input of the user for test
    int tour=0; // loop change for player change
    int i,j;
    struct player *p1,*p2;
    p1 = (struct player *)malloc(sizeof(struct player));
    p2 = (struct player *)malloc(sizeof(struct player));

    p1->state=1;
    p2->state=2;
    initslot();
    creationGrille();

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
