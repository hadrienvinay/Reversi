//#include <ncurses.h>
#include "header.h"

int main(int argc , char *argv[]) {

int mouv[2];
int one;
int two;
initslot();
creationGrille();
//updateGrid(0b10010011);
gets(mouv);
one=mouv[0];
two=mouv[1];
printf("%d,%d",mouv[0],mouv[1]);
updateBlock(1,1);

return 0;
}
