#include <header.h>


int* placer(int x, int y /*HEXA ETAT JOUEUR ACTUEL*/)
{


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
		tab[x]=tab[x+1]
	}
	else print
break;

    default: printf("erreur");
}
return tab;
} 

struct slot getSlot(int x, int y)
{
    int i,j;
    struct slot slot;
    for(i=0; i<SIZE; i++)
    {
        for(j=0; j<SIZE; j++)
        {
            if((matrice_jeu[i][j].x == x) && (matrice_jeu[i][j].y == y))
            {
                slot = matrice_jeu[i][j];
            }
        }
    }
    return slot;
}