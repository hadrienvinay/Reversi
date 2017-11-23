//#include <ncurses.h>
#include "header.h"

int main(int argc , char *argv[])
{
    int one,two;
    struct player *p1,*p2;
    p1 = (struct player *)malloc(sizeof(struct player));
    p2 = (struct player *)malloc(sizeof(struct player));

    p1->state=1;
    p2->state=2;
    initslot();
    creationGrille();
    while(1){
    //updateGrid(0b10010011);
    scanf("%d",&one);
    scanf("%d",&two);
    printf("%d,%d\n",one,two);
    placer(two-1,one-1,p1);
    updateBlock();
    }
    return 0;
}
