#include "header.h"


int placer(int x, int y, struct player *player)
{
    //printf qui ne fait pas bugger le programme wtffff NE PAS TOUCHER
    printf("entre dans placer");
    struct slot *slot = getSlot(x,y);
    //struct slot markSlot;


    /*IF THE SLOT IS EMPTY WE CAN PLAY*/
    if(slot->state == 0){

        if(isAble(x,y,player)){
            horizontalChange(x,y,player);
            verticalChange(x,y,player);
            diagonalChange(x,y,player);
            slot = getSlot(x,y);
            if(slot->state == 0){
                printf("You can't play on that slot... sorry !\n");
                printf("Content of the slot : %d\n", slot->state);
                printf("PLAYER %d\n", player->state);
                return 0;
            }
            else return 1;
        }
        else {
            printf("You can't play on that slot... sorry !\n");
            printf("Content of the slot : %d\n", slot->state);
            printf("PLAYER %d\n", player->state);
            return 0;
        }


    }
      /*IF THE SLOT IS NOT EMPTY WE ASK AGAIN*/
    else {
            printf("Your slot is not empty... sorry !\n");
            return 0;
        }

}

/*We check horizontaly the slot we can eat*/
void verticalChange(int x, int y, struct player *player)
{

    struct slot *checkSlot;
    int i=x;
    int j=y;
    int burn=0; //if slot changes color
    int mark = 0;

    printf("vertical check\n");

    while(i >= 0 && burn == 0){     //We check from x to x--

        if(i!=0)
        {
            i--;
            checkSlot=getSlot(i,j);
            printf("checkslot state i--: %d\n",i+1);
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark++;
                printf("mark: %d\n",mark);
            }
            else burn=1;
        }
        else i--;
        /*else{

            checkSlot=getSlot(i,j);
            printf("checkslot state i--: %d\n",j+1);
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark++;
                printf("mark: %d\n",mark);
            }
            else burn=1;
        }*/

    }
    /*if(burn == 1 && mark != 0){

        mark++;
        for(i=x; i>x-mark; i--){

        checkSlot=getSlot(i,j);
        checkSlot->state=player->state;  //we change the state of the slot that has been token
        }
    }*/
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
            mark--;
        }
    }

    i=x;
    j=y;
    burn=0; //if slot changes color
    mark = 0;

    while(i < SIZE && burn == 0){       //We check from x to x++

        if(i!=SIZE)
        {
            i++;
            checkSlot=getSlot(i,j);
            printf("checkslot state i++: %d\n",i+1);
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark++;
                printf("mark: %d\n",mark);
            }
            else burn=1;
        }
        else i++;
       /* else{

            checkSlot=getSlot(i,j);
            printf("checkslot state i++: %d\n",j+1);
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark++;
                printf("mark: %d\n",mark);
            }
            else burn=1;
        }*/

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
            i++;
            mark--;
        }
    }
}

/*We check verticaly the slot we can eat*/
void horizontalChange(int x, int y, struct player *player)
{

    struct slot *checkSlot;
    int i=x;
    int j=y;
    int burn=0; //if slot changes color
    int mark = 0;

    printf("Horizontal check\n");


    while(j >= 0 && burn == 0){     //We check from y to y--

        if(j!=0)
        {
            j--;
            checkSlot=getSlot(i,j);
            printf("checkslot state j--: %d\n",j+1);
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark++;
                printf("mark: %d\n",mark);
            }
            else burn=1;
        }
        else j--;
       /* else{

            checkSlot=getSlot(i,j);
            printf("checkslot state j--: %d\n",j+1);
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark++;
                printf("mark: %d\n",mark);
            }
            else burn=1;
        }*/

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
            j--;
            mark--;
        }
    }

    i=x;
    j=y;
    burn=0; //if slot changes color
    mark = 0;

    while(j < SIZE && burn == 0){   //We check from y to y++

        if(j!=SIZE)
        {
            j++;
            checkSlot=getSlot(i,j);
            printf("checkslot state j++: %d\n",j+1);
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark++;
                printf("mark: %d\n",mark);
            }
            else burn=1;
        }
        else j++;
        /*else{

            checkSlot=getSlot(i,j);
            printf("checkslot state j++: %d\n",j+1);
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark++;
                printf("mark: %d\n",mark);
            }
            else burn=1;
        }
*/
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
            j++;
            mark--;
        }
    }
}

/*We check diagonaly the slot we can eat*/
void diagonalChange(int x, int y, struct player *player)
{

    struct slot *checkSlot;
    int i=x;
    int j=y;
    int burn=0; //if slot changes color
    int mark = 0;
    int canPlay=1;

    printf("Diagonal check\n");

    while(j >= 0 && i >= 0 && burn == 0){     //we check from x,y to x--,y--

        if(j!=0 && i!=0)
        {
            j--;
            i--;
            checkSlot=getSlot(i,j);
            printf("FIRST checkslot state i--: %d et j--: %d\n",i+1,j+1);
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark++;
                printf("mark: %d\n",mark);
            }
            else burn=1;
        }
        else { j--; i--;}
        /*else{

            checkSlot=getSlot(i,j);
            printf("checkslot state i--: %d et j--: %d\n",i+1,j+1);
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark++;
                printf("mark: %d\n",mark);
            }
            else burn=1;
        }*/

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
            j--;
            mark--;
        }
    }

    i=x;
    j=y;
    burn=0; //if slot changes color
    mark = 0;

    while(i < SIZE && j < SIZE && burn == 0){       //we check from x,y to x++,y++

        if(j!=SIZE && i!=SIZE)
        {
            j++;
            i++;
            checkSlot=getSlot(i,j);
            printf("checkslot state i++: %d et j++: %d\n",i+1,j+1);
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark++;
                printf("mark: %d\n",mark);
            }
            else burn=1;
        }
        else {j++; i++;}
        /*else{

            checkSlot=getSlot(i,j);
            printf("checkslot state i++: %d et j++: %d\n",i+1,j+1);
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark++;
                printf("mark: %d\n",mark);
            }
            else burn=1;
        }*/

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
            i++;
            j++;
            mark--;
        }
    }

    i=x;
    j=y;
    burn=0; //if slot changes color
    mark = 0;


    while(i >= 0 && j < SIZE && burn == 0){     //we check from x,y to x--,y++


        if(i!=0 && j!=SIZE)
        {
            j++;
            i--;
            checkSlot=getSlot(i,j);
            printf("checkslot state i--: %d et j++: %d\n",i+1,j+1);
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark++;
                printf("mark: %d\n",mark);
            }
            else burn=1;
        }
        else {j++; i--;}
       /* else{

            checkSlot=getSlot(i,j);
            printf("checkslot state i--: %d et j++: %d\n",i+1,j+1);
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark++;
                printf("mark: %d\n",mark);
            }
            else burn=1;
        }*/

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

    i=x;
    j=y;
    burn=0; //if slot changes color
    mark = 0;


    while(j >= 0 && i < SIZE && burn == 0){     //we check from x,y to x++,y--

        if(j!=0 && i!=SIZE)
        {
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
        else {j--; i++;}
       /* else{

            checkSlot=getSlot(i,j);
            printf("checkslot state i++: %d et j--: %d\n",i+1,j+1);
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark++;
                printf("mark: %d\n",mark);
            }
            else burn=1;
        }*/

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
            i++;
            j--;
            mark--;
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
