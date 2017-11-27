#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <allegro.h>
#include <winalleg.h>
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
void updateBlock(BITMAP *screen,BITMAP *white,BITMAP *black,BITMAP *red,BITMAP *none);
void updateGrid(int number);
void creationGrille();
void udpateGrille();
void getScore(struct player *player1,struct player *player2);
void placeBlock(int x,int y,BITMAP *screen,BITMAP *color);
int redBox(BITMAP *screen,BITMAP *red,struct player *player);

//placement.c functions
int placer(int x, int y, struct player *player, int canPlay);
void horizontalChange(int x, int y, struct player *player);
void verticalChange(int x, int y, struct player *player);
void diagonalChange(int x, int y, struct player *player);
int isAble(int x, int y, struct player *player);
struct slot *getSlot(int x, int y);

//ia.c
int niveau_boss(struct player *player);
int niveau_hard(struct player *player);
int niveau_medium(struct player *player);
int horizontalCheck(int x, int y, struct player *player);
int verticalCheck(int x, int y, struct player *player);
int diagonalCheck(int x, int y, struct player *player);
int iaIsAble(int x, int y);



#endif // HEADER_H_INCLUDED
