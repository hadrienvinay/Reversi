//#include <ncurses.h>
#include "header.h"

int main(int argc , char *argv[])
{
    int lin,col;

    int one,two,i,j;
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
    placer(lin,col,p1);

    updateBlock();
    }
    return 0;
}
