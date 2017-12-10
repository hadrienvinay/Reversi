#include "header.h"

void initslot()
{
    int i,j;
    struct slot *newslot,*nextslot;
    newslot = (struct slot *)malloc(sizeof(struct slot));
    nextslot = (struct slot *)malloc(sizeof(struct slot));

    for(i=0; i<SIZE; i++)
    {
        for(j=0; j<SIZE; j++)
        {
            newslot->next=NULL;
            newslot->x=i;
            newslot->y=j;
            newslot->state=0;

            //init of black case
            if((i==SIZE/2-1 && j==SIZE/2-1) || (i==SIZE/2 && j==SIZE/2))
            {
                newslot->state=2;
            }
            //init of white case
            else if((i==SIZE/2 && j==SIZE/2-1) || (i==SIZE/2-1 && j==SIZE/2))
            {
                newslot->state=1;
                //newslot->slot=chargerImage("images/black.bmp");
            }
            //else other case are empty
            else
            {
                newslot->state=0;
            }
            matrice[i][j]=newslot;
            //printf("%d\n",matrice[i][j]->state);
            newslot->next = (struct slot *)malloc(sizeof(struct slot));
            newslot = newslot->next;
        }
    }
}

void creationGrille()
{
    int i,j;
    char num = '0';
    char car='0';

    for(i=-1; i<SIZE; i++)
    {
        for(j=-1; j<SIZE; j++)
        {
            if(i==-1 && j==-1)
            {
                printf(" ");
            }
            else if(i==-1)
            {
                printf("%c",car);
                car++;
            }
            else if(j==-1)
            {
                printf("%c",num);
                num++;
            }
            else
            {
                printf("%d",matrice[i][j]->state);
            }
            printf(" ");
        }
        printf("\n");
    }

}

void placeBlock(int x,int y,BITMAP *screen,BITMAP *color)
{
    x=(x*50)+104;
    y=(y*50)+204;
    draw_sprite(screen,color,y,x);
    //blit(color,screen,0,0,y,x,SCREEN_W,SCREEN_H);
}

void updateBlock(BITMAP *screen,BITMAP *white, BITMAP *black,BITMAP *red, BITMAP *none)
{

    char num = '0';
    char car='0';
    int i,j;

    for(i=-1; i<SIZE; i++)
    {
        for(j=-1; j<SIZE; j++)
        {
            if(i==-1 && j==-1)
            {
                printf(" ");
            }
            else if(i==-1)
            {
                printf("%c",car);
                car++;
            }
            else if(j==-1)
            {
                printf("%c",num);
                num++;
            }
            else
            {
                printf("%d",matrice[i][j]->state);

                if(matrice[i][j]->state==1)
                {
                    placeBlock(i,j,screen,black);
                }
                else if(matrice[i][j]->state==2)
                {
                    placeBlock(i,j,screen,white);
                }
                else if(matrice[i][j]->state==3)
                {
                    placeBlock(i,j,screen,red);
                }
            }
            printf(" ");
        }
        printf("\n");
    }
}

//get the actual score of the two player
void getScore(struct player *player1,struct player *player2)
{
    int i,j;
    player1->point=0;
    player2->point=0;
    int compteur=0;
    int compteurWhite=0;
    int compteurBlack=0;

    for(i=0; i<SIZE; i++)
    {
        for(j=0; j<SIZE; j++)
        {
            if(matrice[i][j]->state==1)
            {
                player1->point++;
                compteurBlack++;
            }
            if(matrice[i][j]->state==2)
            {
                player2->point++;
                compteurWhite++;

            }
            if(matrice[i][j]->state==0)
            {
                compteur++;
            }
        }
    }
    if(compteur==0 || compteurBlack==0 || compteurWhite==0){
        player1->playing=1;
        player2->playing=1;
    }

}

int redBox(BITMAP *screen,BITMAP *red,struct player *player)
{
    int i,j;
    int cpt1;
    int cpt2;
    int cpt3;
    int handPower;
    struct slot *slot=(struct slot *)malloc(sizeof(struct slot));


    for(i=0; i<SIZE; i++)
    {
        for(j=0; j<SIZE; j++)
        {
            slot=getSlot(i,j);
            if(slot->state==3) {
                    slot->state=0;
            }
        }
    }

    for(i=0; i<SIZE; i++)
    {
        for(j=0; j<SIZE; j++)
        {
            slot=getSlot(i,j);
            if(isAble(i,j,player) && slot->state==0)
            {
                cpt1=verticalCheck(i,j,player);
                cpt2=horizontalCheck(i,j,player);
                cpt3=diagonalCheck(i,j,player);
                handPower=cpt1+cpt2+cpt3;
                if(handPower!=0) placeBlock(i,j,screen,red);

            }

        }
    }
    //if (handPower==0) allegro_message("You can not play... hit P to pass"); //POUR LE MODE MANUEL
    return handPower;
}



//update 4block in the grid with one byte
void updateGrid(int number,int loop)
{
    int i,j;
    int case1,case2,case3,case4;
    case1 = number & 0b11000000;
    case2 = number & 0b00110000;
    case3 = number & 0b00001100;
    case4 = number & 0b00000011;

    switch(case1)
    {
    case 0b11000000:
        case1=0b00000011;
        break;
    case 0b10000000:
        case1=0b00000010;
        break;
    case 0b01000000:
        case1=0b00000001;
        break;
    case 0b00000000:
        case1=0b00000000;
        break;
    }

    switch(case2)
    {
    case 0b00110000:
        case2=0b00000011;
        break;
    case 0b00100000:
        case2=0b00000010;
        break;
    case 0b00010000:
        case2=0b00000001;
        break;
    case 0b00000000:
        case2=0b00000000;
        break;
    }

    switch(case3)
    {
    case 0b00001100:
        case3=0b00000011;
        break;
    case 0b00001000:
        case3=0b00000010;
        break;
    case 0b00000100:
        case3=0b00000001;
        break;
    case 0b00000000:
        case3=0b00000000;
        break;
    }

    gridBlock[loop]=case1;
    gridBlock[loop+1]=case2;
    gridBlock[loop+2]=case3;
    gridBlock[loop+3]=case4;

    printf("\n");
    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            printf("%d ",gridBlock[loop]);
            loop++;
        }
        printf("\n");
    }


}


