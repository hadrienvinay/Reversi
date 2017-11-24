#include "header.h"


int placer(int x, int y, struct player *player)
{
    struct slot *slot = getSlot(x,y);
    //struct slot markSlot;


    /*IF THE SLOT IS EMPTY WE CAN PLAY*/
    if(slot->state == 0){

        if(isAble(x,y,player)){
            horizontalCheck(x,y,player);
            verticalCheck(x,y,player);
            diagonalCheck(x,y,player);
            return 1;
        }
        else {
            printf("You can't play on that slot... sorry !\n");
            return 0;
        }


    }
      /*IF THE SLOT IS NOT EMPTY WE ASK AGAIN*/
    else {
            printf("Your slot is not empty... sorry !\n");
            return 0;
        }



/*
switch(dir)
{
case "w":
	if(tab[x+1] != NULL)
	{
		tab[x+1]=tab[x];
		tab[x]=tab[x-1];
	}
	else printf("size error");
break;

case "b":
	if(tab[x-1] != NULL)
	{
		tab[x-1]=tab[x];
		tab[x]=tab[x+1];
	}
	else print("");
break;

    default: printf("erreur");
}
*/
}

/*We check horizontaly the slot we can eat*/
void horizontalCheck(int x, int y, struct player *player)
{

    struct slot *checkSlot;
    int i=x;
    int j=y;
    int burn=0; //if slot changes color
    int mark = 0;

    printf("horizontal check\n");

    while(i >= 0 && burn == 0){     //We check from x to x--

        i--;
        checkSlot=getSlot(i,j);
        printf("checkslot state i--: %d\n",i+1);
        if(checkSlot->state != 0 && checkSlot->state != player->state){

            mark++;
            printf("mark: %d\n",mark);
        }
        else burn=1; //if we are on checkSlot.state == player.state or on an empty slot

    }
    if(burn == 1 && mark != 0){

        mark++;
        for(i=x; i>x-mark; i--){

        checkSlot=getSlot(i,j);
        checkSlot->state=player->state;  //we change the state of the slot that has been token
        }
    }

    i=x;
    j=y;
    burn=0; //if slot changes color
    mark = 0;

    while(i < SIZE && burn == 0){       //We check from x to x++

        i++;
        checkSlot=getSlot(i,j);
        printf("checkslot state i++: %d\n",i+1);
        if(checkSlot->state != 0 && checkSlot->state != player->state){

            mark++;
            printf("mark: %d\n",mark);
        }
        else burn=1;

    }
    if(burn == 1 && mark != 0){

        mark++;
        for(i=x; i<x+mark; i++){

        checkSlot=getSlot(i,j);
        checkSlot->state=player->state;       //we change the state of the slot that has been token
        }
    }
}

/*We check verticaly the slot we can eat*/
void verticalCheck(int x, int y, struct player *player)
{

    struct slot *checkSlot;
    int i=x;
    int j=y;
    int burn=0; //if slot changes color
    int mark = 0;

    printf("Vertical check\n");


    while(j >= 0 && burn == 0){     //We check from y to y--

        j--;
        checkSlot=getSlot(i,j);
        printf("checkslot state j--: %d\n",j+1);
        if(checkSlot->state != 0 && checkSlot->state != player->state){

            mark++;
            printf("mark: %d\n",mark);
        }
        else burn=1;

    }
    if(burn == 1 && mark != 0){

        mark++;
        for(j=y; j>y-mark; j--){

        checkSlot=getSlot(i,j);
        checkSlot->state=player->state;       //we change the state of the slot that has been token
        }
    }

    i=x;
    j=y;
    burn=0; //if slot changes color
    mark = 0;

    while(j < SIZE && burn == 0){   //We check from y to y++

        j++;
        checkSlot=getSlot(i,j);
        printf("checkslot state j++: %d\n",j+1);
        if(checkSlot->state != 0 && checkSlot->state != player->state){

            mark++;
            printf("mark: %d\n",j);
        }
        else burn=1;

    }
    if(burn == 1 && mark != 0){

        mark++;
        for(j=y; j<y+mark; j++){

        checkSlot=getSlot(i,j);
        checkSlot->state=player->state;       //we change the state of the slot that has been token
        }
    }
}

/*We check diagonaly the slot we can eat*/
void diagonalCheck(int x, int y, struct player *player)
{

    struct slot *checkSlot;
    int i=x;
    int j=y;
    int burn=0; //if slot changes color
    int mark = 0;

    printf("Diagonal check\n");

    while(j >= 0 && i >= 0 && burn == 0){     //we check from x,y to x--,y--

        j--;
        i--;
        checkSlot=getSlot(i,j);
        printf("checkslot state i--: %d et j--: %d\n",i+1,j+1);
        if(checkSlot->state != 0 && checkSlot->state != player->state){

            mark++;
            printf("mark: %d\n",mark);
        }
        else burn=1;

    }
    if(burn == 1 && mark != 0){

        mark++;
        for(i=x; i>x-mark; i--){
            for(j=y; j=y-mark; j--){

                checkSlot=getSlot(i,j);
                checkSlot->state=player->state;       //we change the state of the slot that has been token
            }
        }
    }

    i=x;
    j=y;
    burn=0; //if slot changes color
    mark = 0;

    while(i < SIZE && j < SIZE && burn == 0){       //we check from x,y to x++,y++

        i++;
        j++;
        checkSlot=getSlot(i,j);
        printf("checkslot state i++: %d et j++: %d\n",i+1,j+1);
        if(checkSlot->state != 0 && checkSlot->state != player->state){

            mark++;
            printf("mark: %d\n",mark);
        }
        else burn=1;

    }
    if(burn == 1 && mark != 0){

        mark++;
        for(i=x; i<x+mark; i++){
            for(j=y; j<y+mark; j++){

                checkSlot=getSlot(i,j);
                checkSlot->state=player->state;       //we change the state of the slot that has been token
            }
        }
    }

    i=x;
    j=y;
    burn=0; //if slot changes color
    mark = 0;


    while(i >= 0 && j < SIZE && burn == 0){     //we check from x,y to x--,y++

        i--;
        j++;
        checkSlot=getSlot(i,j);

        printf("checkslot state i--: %d et j++: %d\n",i+1,j+1);
        if(checkSlot->state != 0 && checkSlot->state != player->state){

            mark++;
            printf("mark: %d\n",mark);
        }
        else burn=1;

    }
    if(burn == 1 && mark != 0 && checkSlot->state == player->state){

        i=x;
        j=y;
        mark++;
        printf("onrentre dans le if, i= %d, j=%d, mark=%d",i+1,j+1,mark);
        while(mark!=0)
        {
            printf("premier tour de boucle, i= %d, j=%d, mark=%d",i+1,j+1,mark);
            checkSlot=getSlot(i,j);
            checkSlot->state=player->state;       //we change the state of the slot that has been token
            i--;
            j++;
            mark--;
        }
    }
    else {
    //soit il ne peux pas jouer soit on fait ça:
        i=x;
        j=y;
        checkSlot=getSlot(i,j);
            checkSlot->state=player->state;
    }

    i=x;
    j=y;
    burn=0; //if slot changes color
    mark = 0;


    while(j >= 0 && i < SIZE && burn == 0){     //we check from x,y to x++,y--

        j--;
        i++;
        checkSlot=getSlot(i,j);
        printf("checkslot state i++: %d et j--: %d\n",i+1,j+1);
        if(checkSlot->state != 0 && checkSlot->state != player->state){

            mark++;
            printf("mark: %d\n",mark);
        }
        else burn=1;

    }
    if(burn == 1 && mark != 0){

        mark++;
        for(i=x; i<x+mark; i++){
            for(j=y; j>y-mark; j--){

                checkSlot=getSlot(i,j);
                checkSlot->state=player->state;       //we change the state of the slot that has been token
            }
        }
    }
}

/*CHECK IF THERE IS AT LEAST ONE ENNEMY SLOT AUROUND*/
int isAble(int x, int y, struct player *player)
{

    int isAble=0;
    struct slot *slot;

    slot=getSlot(x+1,y);
    if(slot->state != 0 && slot->state != player->state){

        isAble=1;
    }

    slot=getSlot(x-1,y);
    if(slot->state != 0 && slot->state != player->state){

        isAble=1;
    }

    slot=getSlot(x,y+1);
    if(slot->state != 0 && slot->state != player->state){

        isAble=1;
    }

    slot=getSlot(x,y-1);
    if(slot->state != 0 && slot->state != player->state){

        isAble=1;
    }

    slot=getSlot(x+1,y+1);
    if(slot->state != 0 && slot->state != player->state){

        isAble=1;
    }

    slot=getSlot(x-1,y-1);
    if(slot->state != 0 && slot->state != player->state){

        isAble=1;
    }

    slot=getSlot(x+1,y-1);
    if(slot->state != 0 && slot->state != player->state){

        isAble=1;
    }

    slot=getSlot(x-1,y+1);
    if(slot->state != 0 && slot->state != player->state){

        isAble=1;
    }

    return isAble;
}

struct slot *getSlot(int x, int y)
{
    int i,j;
    struct slot *slot;
    for(i=0; i < SIZE; i++)
    {
        for(j=0; j < SIZE; j++)
        {
            if((matrice[i][j]->x == x) && (matrice[i][j]->y == y))
            {
                slot = matrice[i][j];
            }
        }
    }
    return slot;
}
