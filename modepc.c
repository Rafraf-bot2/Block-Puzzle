#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <fmod/fmod.h>
#include <time.h>
#include "partie.h"
#include "pieces.h"
#include "initialisations.h"
#include "sons.h"
#include "conditions.h"

void pc_pose(int matrice[11][11],int tab_piece_jouable[4],int *gp,int *b,SDL_Surface *ecran,int mode_jeu,int *compteur)
{
    int i=1,j,x;
    int h=1;
    while (*b==1 && h<=3)
    {
        x=28;
    for(i=1;i<=3;i++)
    {
        if(i!=*gp && tab_piece_jouable[i]<x)
        {
            x=tab_piece_jouable[i];
            *gp=i;
        }
    }
    i=1;
     while(i<=10 && *b==1)
     {
        j=1;
        while(j<=10 && *b==1)
        {
          *b=piece_posable(tab_piece_jouable[*gp],matrice,i,j);
          j=j+1;
        }
          i=i+1;
     }
     if(*b==0)
     {
        *compteur=ajout_score_piece_posee(*compteur,tab_piece_jouable[*gp]);
        tab_piece_jouable[*gp]=0;
        Remplir_piece_jouable(ecran,tab_piece_jouable,mode_jeu);
     }
     else
     h=h+1;
     }
}
