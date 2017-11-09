#include "header.h"
#define SIZE 2

void creationGrille(){
int i,j;
char num = '1';
char car='A';
char grille[SIZE][SIZE]={[0 ... SIZE-1][0 ... SIZE-1] = '0'};

for(i=0;i<SIZE+1;i++){
    for(j=0;j<SIZE+1;j++){
        if(i==0 && j==0){
        printf(" ");
        }
        else if(i==0){
        printf("%c",car);
        car++;
        }
        else if(j==0){
            printf("%c",num);
            num++;
        }
        else {
        printf("N");
        }
        printf(" ");
    }
printf("\n");
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


