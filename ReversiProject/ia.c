#include "header.h"


void jouer()
{
    int i=0;
    int j=0;
    int x,y;
    int cpt1=0;
    int cpt2=0;
    int cpt3=0;
    int handPower=0;
    int maxHandPower=0;
    
    struct slot *powerSlot;
    struct slot *slot;
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
                if(iaIsAble(x,y)){
                    cpt1=verticalCheck(x,y,2);
                    cpt2=horizontalCheck(x,y,2);
                    cpt3=diagonalCheck(x,y,2);
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
      
    horizontalChange(powerSlot->x,powerSlot->y,2);
    verticalChange(powerSlot->x,powerSlot->y,2);
    diagonalChange(powerSlot->x,powerSlot->y,2);


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
        else{
        
            checkSlot=getSlot(i,j);
            printf("checkslot state i--: %d\n",j+1);
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark++;
                printf("mark: %d\n",mark);
            }
            else burn=1;
        }

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
        else{
        
            checkSlot=getSlot(i,j);
            printf("checkslot state i++: %d\n",j+1);
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark++;
                printf("mark: %d\n",mark);
            }
            else burn=1;
        }

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
        else{
        
            checkSlot=getSlot(i,j);
            printf("checkslot state j--: %d\n",j+1);
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark++;
                printf("mark: %d\n",mark);
            }
            else burn=1;
        }

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
        else{
        
            checkSlot=getSlot(i,j);
            printf("checkslot state j++: %d\n",j+1);
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark++;
                printf("mark: %d\n",mark);
            }
            else burn=1;
        }

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
            printf("checkslot state i--: %d et j--: %d\n",i+1,j+1);
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark++;
                printf("mark: %d\n",mark);
            }
            else burn=1;
        }
        else{
        
            checkSlot=getSlot(i,j);
            printf("checkslot state i--: %d et j--: %d\n",i+1,j+1);
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark++;
                printf("mark: %d\n",mark);
            }
            else burn=1;
        }

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
        else{
        
            checkSlot=getSlot(i,j);
            printf("checkslot state i++: %d et j++: %d\n",i+1,j+1);
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark++;
                printf("mark: %d\n",mark);
            }
            else burn=1;
        }

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
        else{
        
            checkSlot=getSlot(i,j);
            printf("checkslot state i--: %d et j++: %d\n",i+1,j+1);
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark++;
                printf("mark: %d\n",mark);
            }
            else burn=1;
        }

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
        else{
        
            checkSlot=getSlot(i,j);
            printf("checkslot state i++: %d et j--: %d\n",i+1,j+1);
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark++;
                printf("mark: %d\n",mark);
            }
            else burn=1;
        }

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

    printf("vertical check\n");
    
    while(i >= 0 && burn == 0){     //We check from x to x--

        if(i!=0)
        {
            i--;
            checkSlot=getSlot(i,j);
            printf("checkslot state i--: %d\n",i+1);
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark1++;
                //printf("mark: %d\n",mark);
            }
            else burn=1;
        }
        else{
        
            checkSlot=getSlot(i,j);
            printf("checkslot state i--: %d\n",j+1);
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark1++;
                //printf("mark: %d\n",mark);
            }
            else burn=1;
        }
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
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark2++;
                //printf("mark: %d\n",mark);
            }
            else burn=1;
        }
        else{
        
            checkSlot=getSlot(i,j);
            printf("checkslot state i++: %d\n",j+1);
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark2++;
                //printf("mark: %d\n",mark);
            }
            else burn=1;
        }
    }
    if(burn==0 || checkSlot->state != player->state) mark2=0;
    
    totmark=mark1+mark2;
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
    
    
    while(j >= 0 && burn == 0){     //We check from y to y--

        if(j!=0)
        {
            j--;
            checkSlot=getSlot(i,j);
            printf("checkslot state j--: %d\n",j+1);
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark1++;
                //printf("mark: %d\n",mark);
            }
            else burn=1;
        }
        else{
        
            checkSlot=getSlot(i,j);
            printf("checkslot state j--: %d\n",j+1);
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark1++;
                //printf("mark: %d\n",mark);
            }
            else burn=1;
        }

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
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark2++;
                //printf("mark: %d\n",mark);
            }
            else burn=1;
        }
        else{
        
            checkSlot=getSlot(i,j);
            printf("checkslot state j++: %d\n",j+1);
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark2++;
                //printf("mark: %d\n",mark);
            }
            else burn=1;
        }

    }
    if(burn==0 || checkSlot->state != player->state) mark2=0;
    
    totmark=mark1+mark2;
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
    
    while(j >= 0 && i >= 0 && burn == 0){     //we check from x,y to x--,y--
            
        if(j!=0 && i!=0)
        {
            j--;
            i--;
            checkSlot=getSlot(i,j);
            printf("checkslot state i--: %d et j--: %d\n",i+1,j+1);
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark1++;
                //printf("mark: %d\n",mark);
            }
            else burn=1;
        }
        else{
        
            checkSlot=getSlot(i,j);
            printf("checkslot state i--: %d et j--: %d\n",i+1,j+1);
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark1++;
                //printf("mark: %d\n",mark);
            }
            else burn=1;
        }

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
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark2++;
                //printf("mark: %d\n",mark);
            }
            else burn=1;
        }
        else{
        
            checkSlot=getSlot(i,j);
            printf("checkslot state i++: %d et j++: %d\n",i+1,j+1);
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark2++;
                //printf("mark: %d\n",mark);
            }
            else burn=1;
        }

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
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark3++;
                //printf("mark: %d\n",mark);
            }
            else burn=1;
        }
        else{
        
            checkSlot=getSlot(i,j);
            //printf("checkslot state i--: %d et j++: %d\n",i+1,j+1);
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark3++;
                //printf("mark: %d\n",mark);
            }
            else burn=1;
        }

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
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark4++;
                //printf("mark: %d\n",mark);
            }
            else burn=1;
        }
        else{
        
            checkSlot=getSlot(i,j);
            printf("checkslot state i++: %d et j--: %d\n",i+1,j+1);
            if(checkSlot->state != 0 && checkSlot->state != player->state){

                mark4++;
                //printf("mark: %d\n",mark);
            }
            else burn=1;
        }

    }
    if(burn==0 || checkSlot->state != player->state) mark4=0;
    
    totmark=mark1+mark2+mark3+mark4;
    return totmark;
}

/*CHECK IF THERE IS AT LEAST ONE ENNEMY SLOT AUROUND*/
int iaIsAble(int x, int y)
{

    int isAble=0;
    struct slot *slot;

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
