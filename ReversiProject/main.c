//#include <ncurses.h>
#include "header.h"

int main(int argc , char *argv[])
{
    //allegro setup graphic
    lancerToutAllegro(800,600);
    //random setup
    srand(time(NULL));
    //create bitmaps
    //our all page
    BITMAP *page=NULL;
    BITMAP *menu=NULL;
    BITMAP *menuIa=NULL;
    //buffer for scores and infos
    BITMAP *scorep1=NULL;
    BITMAP *scorep2=NULL;
    BITMAP *infos=NULL;
    BITMAP *tableau=NULL;
    BITMAP *black=NULL;
    BITMAP *white=NULL;
    BITMAP *red=NULL;
    BITMAP *none=NULL;
    //menu variable
    int menuchoice=0;
    int menuIachoice=0;
    int difficulty=0;
    int tab_hex[16];
    int i=0;
    int j=0;
    int loop = 0;
    int jouer = 0;

    if(jouer==0)
    {

        //set bitmap size for menu
        page=create_bitmap(SCREEN_W,SCREEN_H);
        //menu=chargerImage("");
        menu=chargerImage("images/menuPLAYER0.bmp");

        initMenu(page,menu);
        int tour=0; // loop change for player change
        //int i,j;
        int end=0;
        int endloop=0;
        int validMouv=0;
        int temp=0;
        struct player *p1,*p2;
        p1 = (struct player *)malloc(sizeof(struct player));
        p2 = (struct player *)malloc(sizeof(struct player));

        while(!key[KEY_ESC])
        {
            menuchoice=menuChoice();

            switch(menuchoice)
            {

            case 2:

                //load images and set bitmap size
                scorep1=create_bitmap(100,20);
                scorep2=create_bitmap(100,20);
                infos=create_bitmap(200,20);
                tableau=chargerImage("images/tableau.bmp");
                white=chargerImage("images/jeton_blanc.bmp");
                black=chargerImage("images/jeton_noir.bmp");
                red=chargerImage("images/jeton_rouge.bmp");
                none=chargerImage("images/jeton_none.bmp");



                p1->state=1;
                p2->state=2;
                p2->point=0;
                p2->point=0;
                p2->point=0;
                p2->point=0;

                initslot();
                //console show matrice
                creationGrille();

                initallegro(page,scorep1,scorep2,infos,tableau,white,black);
                for(i=0; i<16; i++)
                {
                    tab_hex[i]=0xAA;
                    updateGrid(tab_hex[i],loop);
                    loop=loop+4;
                }

                for(i=0; i<SIZE; i++)
                {
                    for(j=0; j<SIZE; j++)
                    {
                        int indice=i*SIZE+j;
                        matrice[i][j]->state=gridBlock[indice];
                    }
                }
                updateBlock(screen,white,black,red,none);
                redBox(screen,red,p1);
                while(!key[KEY_Q])
                {
                    // update our bitmap for infos and score
                    //clear_bitmap(scorep1);
                    //clear_bitmap(scorep2);
                    //clear_bitmap(infos);

                    validMouv=0;
                    //updateGrid(0b10010011);
                    if(key[KEY_P])
                    {

                        if(tour==0) tour=1;
                        else if(tour==1) tour=0;
                        Sleep(1000);
                    }

                    if(tour==0)
                    {

                        if(mouse_b&1)
                        {
                            validMouv = getMouseUser(p1);
                            if(validMouv==1)
                            {
                                clear(screen);
                                initallegro(page,scorep1,scorep2,infos,tableau,white,black);
                                redBox(screen,red,p2);
                                updateBlock(screen,white,black,red,none);
                                tour++;
                            }
                        }
                    }
                    if(tour==1)
                    {
                        //if (redBox(screen,red,p2)==0) allegro_message("You can not play... hit P to pass"); //POUR LE MODE MANUEL
                        if(mouse_b&1)
                        {
                            validMouv = getMouseUser(p2);
                            if(validMouv==1)
                            {
                                clear(screen);
                                initallegro(page,scorep1,scorep2,infos,tableau,white,black);
                                redBox(screen,red,p1);
                                updateBlock(screen,white,black,red,none);
                                tour=0;
                            }
                        }
                    }


                    getScore(p1,p2);
                    textprintf_ex(scorep1, font, 0, 0, makecol(255, 255, 255),-1, "Points : %d", p1->point);
                    textprintf_ex(scorep2, font, 0, 0, makecol(255, 255, 255),-1, "Points : %d", p2->point);
                    if(tour==0)
                    {
                        textout_ex(infos,font,"Playing : Black ",0,0,makecol(255,255,255),makecol( 38,51,111));
                    }
                    else
                    {
                        textout_ex(infos,font,"Playing : White ",0,0,makecol(255,255,255),makecol( 38,51,111));
                    }
                    if(p1->playing==1)
                    {

                        Sleep(4000);
                        printf(" \n\nPlayer 1 : %d ---- Player 2 : %d",p1->point,p2->point);
                        return 0;
                    }
                    //blit(scorep1,screen,0,0,50,160,SCREEN_W,SCREEN_H);
                    //blit(scorep2,screen,0,0,650,160,SCREEN_W,SCREEN_H);
                    //blit(infos,screen,0,0,300,50,SCREEN_W,SCREEN_H);
                }
                break;


            case 1:
                    Sleep(500);
                    clear(screen);
                    menuIa=chargerImage("images/menuIA0.bmp");
                    while(menuIachoice==0){
                    initMenu(page,menuIa);
                    menuIachoice=chooseIaLevel();
                    }
                    //load images and set bitmap size
                    scorep1=create_bitmap(100,20);
                    scorep2=create_bitmap(100,20);
                    infos=create_bitmap(200,20);
                    tableau=chargerImage("images/tableau.bmp");
                    white=chargerImage("images/jeton_blanc.bmp");
                    black=chargerImage("images/jeton_noir.bmp");
                    red=chargerImage("images/jeton_rouge.bmp");
                    none=chargerImage("images/jeton_none.bmp");

                    p1->state=1;
                    p2->state=2;
                    p2->point=0;
                    p2->point=0;
                    p2->point=0;
                    p2->point=0;

                    initslot();
                    creationGrille();

                    initallegro(page,scorep1,scorep2,infos,tableau,white,black);
                    updateBlock(screen,white,black,red,none);
                    redBox(screen,red,p1);
                    while(!key[KEY_Q])
                    {
                        // update our bitmap for infos and score
                        //clear_bitmap(scorep1);
                        //clear_bitmap(scorep2);
                        //clear_bitmap(infos);

                        validMouv=0;
                        //updateGrid(0b10010011);
                        if(key[KEY_P])
                        {

                            if(tour==0) tour=1;
                            else if(tour==1) tour=0;
                            Sleep(1000);
                        }

                        if(tour==0)
                        {

                            if(mouse_b&1)
                            {
                                validMouv = getMouseUser(p1);
                                if(validMouv==1)
                                {
                                    clear(screen);
                                    initallegro(page,scorep1,scorep2,infos,tableau,white,black);
                                    //blit(scorep1,screen,0,0,50,160,SCREEN_W,SCREEN_H);
                                    //blit(scorep2,screen,0,0,650,160,SCREEN_W,SCREEN_H);
                                    //blit(infos,screen,0,0,300,50,SCREEN_W,SCREEN_H);

                                    updateBlock(screen,white,black,red,none);
                                    tour++;
                                }
                            }
                        }
                        if(tour==1)
                        {
                            if(menuIachoice==1)
                            {
                                validMouv = niveau_medium(p2);
                            }
                            else if(menuIachoice==2)
                            {
                                validMouv = niveau_hard(p2);
                            }
                            else if(menuIachoice==3)
                            {
                                validMouv = niveau_boss(p2);
                            }
                            if(validMouv==1)
                            {
                                Sleep(1000);
                                clear(screen);
                                initallegro(page,scorep1,scorep2,infos,tableau,white,black);
                                updateBlock(screen,white,black,red,none);
                                tour=0;
                                redBox(screen,red,p1);
                            }
                            else
                            {
                                //allegro_message("ia ne peut pas jouer... a ton tour!");
                                tour=0;
                                Sleep(1500);
                            }


                        }


                        getScore(p1,p2);
                        textprintf_ex(scorep1, font, 0, 0, makecol(255, 255, 255),-1, "Points : %d", p1->point);
                        textprintf_ex(scorep2, font, 0, 0, makecol(255, 255, 255),-1, "Points : %d", p2->point);
                        if(tour==0)
                        {
                            textout_ex(infos,font,"Playing : Black ",0,0,makecol(255,255,255),makecol( 38,51,111));
                        }
                        else
                        {
                            textout_ex(infos,font,"Playing : White ",0,0,makecol(255,255,255),makecol( 38,51,111));
                        }
                        //blit(scorep1,screen,0,0,50,160,SCREEN_W,SCREEN_H);
                        //blit(scorep2,screen,0,0,650,160,SCREEN_W,SCREEN_H);
                        //blit(infos,screen,0,0,300,50,SCREEN_W,SCREEN_H);
                        if(p1->playing==1)
                        {

                            Sleep(4000);
                            printf(" \n\nPlayer 1 : %d ---- Player 2 : %d",p1->point,p2->point);
                            return 0;
                        }
                        printf("\n%d",menuIachoice);

                    }


                break;

            case 3:

                //load images and set bitmap size
                scorep1=create_bitmap(100,20);
                scorep2=create_bitmap(100,20);
                infos=create_bitmap(200,20);
                tableau=chargerImage("images/tableau.bmp");
                white=chargerImage("images/jeton_blanc.bmp");
                black=chargerImage("images/jeton_noir.bmp");
                red=chargerImage("images/jeton_rouge.bmp");
                none=chargerImage("images/jeton_none.bmp");


                p1->state=1;
                p2->state=2;
                p2->point=0;
                p2->point=0;
                p2->point=0;
                p2->point=0;

                initslot();
                creationGrille();

                initallegro(page,scorep1,scorep2,infos,tableau,white,black);
                updateBlock(screen,white,black,red,none);
                while(!key[KEY_Q])
                {
                    // update our bitmap for infos and score
                    //clear_bitmap(scorep1);
                    //clear_bitmap(scorep2);
                    //clear_bitmap(infos);

                    validMouv=0;
                    //updateGrid(0b10010011);
                    if(key[KEY_P])
                    {

                        if(tour==0) tour=1;
                        else if(tour==1) tour=0;
                        Sleep(1000);
                    }

                    if(tour==0)
                    {
                        validMouv = niveau_hard(p1);
                        if(validMouv==1)
                        {
                            Sleep(500);
                            //clear(screen);
                            //initallegro(page,scorep1,scorep2,infos,tableau,white,black);
                            updateBlock(screen,white,black,red,none);
                            tour++;
                        }
                    }
                    if(tour==1)
                    {
                        validMouv = niveau_boss(p2);
                        if(validMouv==1)
                        {
                            Sleep(500);
                            //clear(screen);
                            //initallegro(page,scorep1,scorep2,infos,tableau,white,black);
                            updateBlock(screen,white,black,red,none);
                            tour=0;
                        }
                        else
                        {
                            //allegro_message("ia ne peut pas jouer... a ton tour!");
                            tour=0;
                            Sleep(1500);
                        }


                    }


                    getScore(p1,p2);
                    textprintf_ex(scorep1, font, 0, 0, makecol(255, 255, 255),-1, "Points : %d", p1->point);
                    textprintf_ex(scorep2, font, 0, 0, makecol(255, 255, 255),-1, "Points : %d", p2->point);
                    if(tour==0)
                    {
                        textout_ex(infos,font,"Playing : Black ",0,0,makecol(255,255,255),makecol( 38,51,111));
                    }
                    else
                    {
                        textout_ex(infos,font,"Playing : White ",0,0,makecol(255,255,255),makecol( 38,51,111));
                    }
                    //blit(scorep1,screen,0,0,50,160,SCREEN_W,SCREEN_H);
                    //blit(scorep2,screen,0,0,650,160,SCREEN_W,SCREEN_H);
                    //blit(infos,screen,0,0,300,50,SCREEN_W,SCREEN_H);
                    if(p1->playing==1)
                    {

                        Sleep(4000);
                        printf(" \n\nPlayer 1 : %d ---- Player 2 : %d",p1->point,p2->point);
                        return 0;
                    }

                }
                break;

            }
            //blit(scorep1,screen,0,0,50,160,SCREEN_W,SCREEN_H);
            //blit(scorep2,screen,0,0,650,160,SCREEN_W,SCREEN_H);
            //blit(infos,screen,0,0,300,50,SCREEN_W,SCREEN_H);


        }
    }


    return 0;
}
END_OF_MAIN();
