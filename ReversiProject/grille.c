#include "header.h"

void initslot(){
    int i,j;
    struct slot *newslot,*nextslot;
    newslot = (struct slot *)malloc(sizeof(struct slot));
    nextslot = (struct slot *)malloc(sizeof(struct slot));

    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
            newslot->next=NULL;
            newslot->x=i;
            newslot->y=j;
            newslot->state=0;

            //init of black case
            if((i==SIZE/2-1 && j==SIZE/2-1) || (i==SIZE/2 && j==SIZE/2)){
                newslot->state=2;
            }
            //init of white case
            else if((i==SIZE/2 && j==SIZE/2-1) || (i==SIZE/2-1 && j==SIZE/2)) {
                newslot->state=1;
                //newslot->slot=chargerImage("images/black.bmp");

            }
            //else other case are empty
            else{
                newslot->state=0;
            }
            matrice[i][j]=newslot;
            //printf("%d\n",matrice[i][j]->state);
            newslot->next = (struct slot *)malloc(sizeof(struct slot));
            newslot = newslot->next;
        }
    }

}

void creationGrille(){
int i,j;
char num = '0';
char car='0';

for(i=-1;i<SIZE;i++){
    for(j=-1;j<SIZE;j++){
        if(i==-1 && j==-1){
        printf(" ");
        }
        else if(i==-1){
        printf("%c",car);
        car++;
        }
        else if(j==-1){
            printf("%c",num);
            num++;
        }
        else {
        printf("%d",matrice[i][j]->state);
        }
        printf(" ");
    }
printf("\n");
}

}

void placeBlock(int x,int y,BITMAP *screen,BITMAP *color){
    x=(x*50)+104;
    y=(y*50)+204;
    draw_sprite(screen,color,y,x);
    //blit(color,screen,0,0,y,x,SCREEN_W,SCREEN_H);
}

void updateBlock(BITMAP *screen,BITMAP *white, BITMAP *black){

char num = '0';
char car='0';
int i,j;

    for(i=-1;i<SIZE;i++){
        for(j=-1;j<SIZE;j++){
            if(i==-1 && j==-1){
                printf(" ");
            }
            else if(i==-1){
                printf("%c",car);
                car++;
            }
            else if(j==-1){
                printf("%c",num);
                num++;
            }
            else {
                printf("%d",matrice[i][j]->state);
                if(matrice[i][j]->state==1){
                    placeBlock(i,j,screen,black);
                }
                else if(matrice[i][j]->state==2){
                    placeBlock(i,j,screen,white);
                }
            }
            printf(" ");
        }
    printf("\n");
    }
    printf("affiché");
}

//get the actual score of the two player
void getScore(struct player *player1,struct player *player2){
    int i,j;
    player1->point=0;
    player2->point=0;

    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
                if(matrice[i][j]->state==1){
                   player1->point++;
                }
                if(matrice[i][j]->state==2){
                   player2->point++;

                }
        }
    }

}




//update 4block in the grid with one byte
void updateGrid(int number){
int i,j;
int case1,case2,case3,case4;
char gridBlock[4];
int loop=0;
case1 = number & 0b11000000;
case2 = number & 0b00110000;
case3 = number & 0b00001100;
case4 = number & 0b00000011;

switch(case1){
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

switch(case2){
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

switch(case3){
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

gridBlock[0]=case1;
gridBlock[1]=case2;
gridBlock[2]=case3;
gridBlock[3]=case4;

printf("\n");
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
        printf("%d ",gridBlock[loop]);
        loop++;
        }
        printf("\n");
    }

}


