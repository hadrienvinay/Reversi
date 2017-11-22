#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#define SIZE 2

struct player{
char nom[20];
int point;
int time;
};

struct slot 
{
    int x;
    int y;
    int state; //0:vide  --  1:noir -- 2:blanc
};

//server.c functions
void initServer();

//grille.c functions
void creationGrille();
void udpateGrille();


#endif // HEADER_H_INCLUDED
