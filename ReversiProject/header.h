#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#define SIZE 8

//struct of plot
struct slot *matrice[SIZE][SIZE];

struct player{
char nom[20];
int point;
int time;
int playing; // 0 if playing -- 1 ifnot
int state;
};

struct slot{
    int x;
    int y;
    int state; //0:vide  --  1:noir -- 2:blanc
    struct slot *next;
};

//server.c functions
//void initServer();

//grille.c functions
void initslot();
void updateBlock();
void updateGrid(int number);
void creationGrille();
void udpateGrille();
void getScore(struct player *player1,struct player *player2);

//placement.c functions
int placer(int x, int y, struct player *player);
void horizontalChange(int x, int y, struct player *player);
void verticalChange(int x, int y, struct player *player);
void diagonalChange(int x, int y, struct player *player);
void horizontalCheck(int x, int y, struct player *player);
void verticalCheck(int x, int y, struct player *player);
void diagonalCheck(int x, int y, struct player *player);
int isAble(int x, int y, struct player *player);
struct slot *getSlot(int x, int y);


#endif // HEADER_H_INCLUDED
