#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

struct player{
char nom[20];
int point;
int time;
};

//server.c functions
void initServer();

//grille.c functions
void creationGrille();
void udpateGrille();


#endif // HEADER_H_INCLUDED
