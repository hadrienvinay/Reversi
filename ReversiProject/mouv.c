#include <stdio.h>
#include <stdlib.h>


int* placer(int* tab, int x, int y, int color)
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

default printf("erreur");

return tab;
} 
