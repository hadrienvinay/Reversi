
#include "header.h"

int niveau_medium(struct player *player)
{
    int i=0;
    int j=0;
    int cpt1=0;
    int cpt2=0;
    int cpt3=0;
    int var;
    int canPlay=0;
    int boucle;
    int x,y;

    struct slot *slot;
    slot=(struct slot *)malloc(sizeof(struct slot));

    //struct slot markSlot;

    boucle=rand()%4;
    /*IF THE SLOT IS EMPTY WE CAN PLAY*/
    switch(boucle){
        case 0:
            for(i=0;i<SIZE;i++)
            {
                for(j=0;j<SIZE;j++)
                {
                    if(canPlay==0)
                    {
                        x=i;
                        y=j;
                        slot=getSlot(x,y);
                        if(slot->state == 0){
                            if(isAble(x,y,player)){
                                cpt1=verticalCheck(x,y,player);
                                cpt2=horizontalCheck(x,y,player);
                                cpt3=diagonalCheck(x,y,player);     //we count the number of ennemi slot that we can get
                                canPlay=cpt1+cpt2+cpt3;
                            }
                            else {
                                printf("IA can't play on that slot... sorry ! --> X = %d -- Y = %d\n",x,y);
                                printf("Content of the slot : %d\n", slot->state);
                            }
                        }
                    }
                }
            }
            break;

            case 1:
            for(i=SIZE-1;i>=0;i--)
            {
                for(j=SIZE-1;j>=0;j--)
                {
                    if(canPlay==0)
                    {
                        x=i;
                        y=j;
                        slot=getSlot(x,y);
                        if(slot->state == 0){
                            if(isAble(x,y,player)){
                                cpt1=verticalCheck(x,y,player);
                                cpt2=horizontalCheck(x,y,player);
                                cpt3=diagonalCheck(x,y,player);     //we count the number of ennemi slot that we can get
                                canPlay=cpt1+cpt2+cpt3;
                            }
                            else {
                                printf("IA can't play on that slot... sorry ! --> X = %d -- Y = %d\n",x,y);
                                printf("Content of the slot : %d\n", slot->state);
                            }
                        }
                    }
                }
            }
            break;

            case 2:
            for(i=0;i<SIZE;i++)
            {
                for(j=SIZE-1;j>=0;j--)
                {
                    if(canPlay==0)
                    {
                        x=i;
                        y=j;
                        slot=getSlot(x,y);
                        if(slot->state == 0){
                            if(isAble(x,y,player)){
                                cpt1=verticalCheck(x,y,player);
                                cpt2=horizontalCheck(x,y,player);
                                cpt3=diagonalCheck(x,y,player);     //we count the number of ennemi slot that we can get
                                canPlay=cpt1+cpt2+cpt3;
                            }
                            else {
                                printf("IA can't play on that slot... sorry ! --> X = %d -- Y = %d\n",x,y);
                                printf("Content of the slot : %d\n", slot->state);
                            }
                        }
                    }
                }
            }
            break;

            case 3:
            for(i=SIZE-1;i>=0;i--)
            {
                for(j=0;j<SIZE;j++)
                {
                    if(canPlay==0)
                    {
                        x=i;
                        y=j;
                        slot=getSlot(x,y);
                        if(slot->state == 0){
                            if(isAble(x,y,player)){
                                cpt1=verticalCheck(x,y,player);
                                cpt2=horizontalCheck(x,y,player);
                                cpt3=diagonalCheck(x,y,player);     //we count the number of ennemi slot that we can get
                                canPlay=cpt1+cpt2+cpt3;
                            }
                            else {
                                printf("IA can't play on that slot... sorry ! --> X = %d -- Y = %d\n",x,y);
                                printf("Content of the slot : %d\n", slot->state);
                            }
                        }
                    }
                }
            }
            break;
    }
    var = placer(slot->x,slot->y,player,canPlay);
   //free(powerSlot);
   //free(slot);
   return var;
}

int niveau_hard(struct player *player)
{

    int i=0;
    int j=0;
    int var;
    int x,y;
    int cpt1=0;
    int cpt2=0;
    int cpt3=0;
    int handPower=0;
    int maxHandPower=0;
    int canPlay;

    struct slot *powerSlot;
    struct slot *slot;
    slot=(struct slot *)malloc(sizeof(struct slot));
    powerSlot=(struct slot *)malloc(sizeof(struct slot));

    //struct slot markSlot;


    /*IF THE SLOT IS EMPTY WE CAN PLAY*/
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            x=i;
            y=j;
            handPower=0;
            slot=getSlot(x,y);
            if(slot->state == 0){
                if(isAble(x,y,player)){
                    cpt1=verticalCheck(x,y,player);
                    cpt2=horizontalCheck(x,y,player);
                    cpt3=diagonalCheck(x,y,player);
                    handPower=cpt1+cpt2+cpt3;       //we count the number of ennemi slot that we can get

                }
                else {
                    printf("IA can't play on that slot... sorry ! --> X = %d -- Y = %d\n",x,y);
                    printf("Content of the slot : %d\n", slot->state);
                }
            }
            if(handPower>maxHandPower){         //it compare that to the best hand we can make

                maxHandPower=handPower;
                powerSlot=getSlot(x,y);
            }
        }
    }
    printf("MAXHANDPOWER= %d",maxHandPower);
    if (maxHandPower==0) canPlay=1;
    else canPlay=0;
   var = placer(powerSlot->x,powerSlot->y,player, canPlay);
   //free(powerSlot);
   //free(slot);
   return var;
}




/*We check horizontaly the slot we can eat*/
int verticalCheck(int x, int y, struct player *player)
{

    struct slot *checkSlot;
    int i=x;
    int j=y;
    int burn=0; //if slot changes color
    int mark1 = 0;
    int mark2 = 0;
    int totmark=0;

    checkSlot=(struct slot *)malloc(sizeof(struct slot));
    printf("vertical check\n");

    while(i >= 0 && burn == 0){     //We check from x to x--

        if(i!=0)
        {
            i--;
            checkSlot=getSlot(i,j);
            printf("checkslot state i--: %d\n",i+1);
            if(checkSlot->state != 0 && checkSlot->state != 3 && checkSlot->state != player->state){

                mark1++;
                //printf("mark: %d\n",mark);
            }
            else burn=1;
        }
        else i--;
        /*else{

            checkSlot=getSlot(i,j);
            printf("checkslot state i--: %d\n",j+1);
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark1++;
                //printf("mark: %d\n",mark);
            }
            else burn=1;
        }*/
    }

    if(burn==0 || checkSlot->state != player->state) mark1=0;
    /*if(burn == 1 && mark != 0){

        mark++;
        for(i=x; i>x-mark; i--){

        checkSlot=getSlot(i,j);
        checkSlot->state=player->state;  //we change the state of the slot that has been token
        }
    }*/


    i=x;
    j=y;
    burn=0; //if slot changes color

    while(i < SIZE && burn == 0){       //We check from x to x++

        if(i!=SIZE)
        {
            i++;
            checkSlot=getSlot(i,j);
            printf("checkslot state i++: %d\n",i+1);
            if(checkSlot->state != 0 && checkSlot->state != 3 && checkSlot->state != player->state){

                mark2++;
                //printf("mark: %d\n",mark);
            }
            else burn=1;
        }
        else i++;
        /*else{

            checkSlot=getSlot(i,j);
            printf("checkslot state i++: %d\n",j+1);
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark2++;
                //printf("mark: %d\n",mark);
            }
            else burn=1;
        }*/
    }
    if(burn==0 || checkSlot->state != player->state) mark2=0;

    totmark=mark1+mark2;
    //free(checkSlot);
    return totmark;
}

/*We check verticaly the slot we can eat*/
int horizontalCheck(int x, int y, struct player *player)
{

    struct slot *checkSlot;
    int i=x;
    int j=y;
    int burn=0; //if slot changes color
    int mark1 = 0;
    int mark2 = 0;
    int totmark = 0;

    printf("Horizontal check\n");
    checkSlot=(struct slot *)malloc(sizeof(struct slot));


    while(j >= 0 && burn == 0){     //We check from y to y--

        if(j!=0)
        {
            j--;
            checkSlot=getSlot(i,j);
            printf("checkslot state j--: %d\n",j+1);
            if(checkSlot->state != 0 && checkSlot->state != 3 && checkSlot->state != player->state){

                mark1++;
                //printf("mark: %d\n",mark);
            }
            else burn=1;
        }
        else j--;
        /*else{

            checkSlot=getSlot(i,j);
            printf("checkslot state j--: %d\n",j+1);
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark1++;
                //printf("mark: %d\n",mark);
            }
            else burn=1;
        }*/

    }
    if(burn==0 || checkSlot->state != player->state) mark1=0;

    i=x;
    j=y;
    burn=0; //if slot changes color

    while(j < SIZE && burn == 0){   //We check from y to y++

        if(j!=SIZE)
        {
            j++;
            checkSlot=getSlot(i,j);
            printf("checkslot state j++: %d\n",j+1);
            if(checkSlot->state != 0 && checkSlot->state != 3 && checkSlot->state != player->state){

                mark2++;
                //printf("mark: %d\n",mark);
            }
            else burn=1;
        }
        else j++;
        /*else{

            checkSlot=getSlot(i,j);
            printf("checkslot state j++: %d\n",j+1);
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark2++;
                //printf("mark: %d\n",mark);
            }
            else burn=1;
        }*/

    }
    if(burn==0 || checkSlot->state != player->state) mark2=0;

    totmark=mark1+mark2;
    //free(checkSlot);
    return totmark;
}

/*We check diagonaly the slot we can eat*/
int diagonalCheck(int x, int y, struct player *player)
{

    struct slot *checkSlot;
    int i=x;
    int j=y;
    int burn=0; //if slot changes color
    int mark1 = 0;
    int mark2 = 0;
    int mark3 = 0;
    int mark4 = 0;
    int totmark = 0;
    int canPlay=1;

    printf("Diagonal check\n");
    checkSlot=(struct slot *)malloc(sizeof(struct slot));

    while(j >= 0 && i >= 0 && burn == 0){     //we check from x,y to x--,y--

        if(j!=0 && i!=0)
        {
            j--;
            i--;
            checkSlot=getSlot(i,j);
            printf("checkslot state i--: %d et j--: %d\n",i+1,j+1);
            if(checkSlot->state != 0 && checkSlot->state != 3 && checkSlot->state != player->state){

                mark1++;
                //printf("mark: %d\n",mark);
            }
            else burn=1;
        }
        else {j--; i--;}
        /*
        else{

            checkSlot=getSlot(i,j);
            printf("checkslot state i--: %d et j--: %d\n",i+1,j+1);
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark1++;
                //printf("mark: %d\n",mark);
            }
            else burn=1;
        }*/

    }
    if(burn==0 || checkSlot->state != player->state) mark1=0;


    i=x;
    j=y;
    burn=0; //if slot changes color

    while(i < SIZE && j < SIZE && burn == 0){       //we check from x,y to x++,y++

        if(j!=SIZE && i!=SIZE)
        {
            j++;
            i++;
            checkSlot=getSlot(i,j);
            printf("checkslot state i++: %d et j++: %d\n",i+1,j+1);
            if(checkSlot->state != 0 && checkSlot->state != 3 && checkSlot->state != player->state){

                mark2++;
                //printf("mark: %d\n",mark);
            }
            else burn=1;
        }
                else {j++; i++;}

        /*
        else{

            checkSlot=getSlot(i,j);
            printf("checkslot state i++: %d et j++: %d\n",i+1,j+1);
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark2++;
                //printf("mark: %d\n",mark);
            }
            else burn=1;
        }*/

    }
    if(burn==0 || checkSlot->state != player->state) mark2=0;

    i=x;
    j=y;
    burn=0; //if slot changes color


    while(i >= 0 && j < SIZE && burn == 0){     //we check from x,y to x--,y++


        if(i!=0 && j!=SIZE)
        {
            j++;
            i--;
            checkSlot=getSlot(i,j);
            printf("checkslot state i--: %d et j++: %d\n",i+1,j+1);
            if(checkSlot->state != 0 && checkSlot->state != 3 && checkSlot->state != player->state){

                mark3++;
                //printf("mark: %d\n",mark);
            }
            else burn=1;
        }
        else {j++; i--;}

        /*
        else{

            checkSlot=getSlot(i,j);
            //printf("checkslot state i--: %d et j++: %d\n",i+1,j+1);
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark3++;
                //printf("mark: %d\n",mark);
            }
            else burn=1;
        }*/

    }
    if(burn==0 || checkSlot->state != player->state) mark3=0;

    i=x;
    j=y;
    burn=0; //if slot changes color


    while(j >= 0 && i < SIZE && burn == 0){     //we check from x,y to x++,y--

        if(j!=0 && i!=SIZE)
        {
            j--;
            i++;
            checkSlot=getSlot(i,j);
            printf("checkslot state i++: %d et j--: %d\n",i+1,j+1);
            if(checkSlot->state != 0 && checkSlot->state != 3 && checkSlot->state != player->state){

                mark4++;
                //printf("mark: %d\n",mark);
            }
            else burn=1;
        }
        else {j--; i++;}

        /*
        else{

            checkSlot=getSlot(i,j);
            printf("checkslot state i++: %d et j--: %d\n",i+1,j+1);
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark4++;
                //printf("mark: %d\n",mark);
            }
            else burn=1;
        }*/

    }
    if(burn==0 || checkSlot->state != player->state) mark4=0;

    totmark=mark1+mark2+mark3+mark4;
    //free(checkSlot);
    return totmark;
}

/*CHECK IF THERE IS AT LEAST ONE ENNEMY SLOT AUROUND*/
int iaIsAble(int x, int y)
{

    int isAble=0;
    struct slot *slot;
    slot=(struct slot *)malloc(sizeof(struct slot));
    slot=getSlot(x+1,y);
    if(slot->state != 0 && slot->state != 2){

        isAble=1;
    }

    slot=getSlot(x-1,y);
    if(slot->state != 0 && slot->state != 2){

        isAble=1;
    }

    slot=getSlot(x,y+1);
    if(slot->state != 0 && slot->state != 2){

        isAble=1;
    }

    slot=getSlot(x,y-1);
    if(slot->state != 0 && slot->state != 2){

        isAble=1;
    }

    slot=getSlot(x+1,y+1);
    if(slot->state != 0 && slot->state != 2){

        isAble=1;
    }

    slot=getSlot(x-1,y-1);
    if(slot->state != 0 && slot->state != 2){

        isAble=1;
    }

    slot=getSlot(x+1,y-1);
    if(slot->state != 0 && slot->state != 2){

        isAble=1;
    }

    slot=getSlot(x-1,y+1);
    if(slot->state != 0 && slot->state != 2){

        isAble=1;
    }
    //free(slot);
    return isAble;
}

