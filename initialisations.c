#include <stdio.h>
#include <stdlib.h>

void initial_tab_piece_jouable(int tab_piece_jouable[4])
{
    int i;
    for(i=1;i<=3;i++)
    {
        tab_piece_jouable[i]=0;
    }
}

void initial_matrice_grille(int matrice[11][11])
{
    int i,j;
    for(i=1;i<=10;i++)
    {
        for(j=1;j<=10;j++)
        {
            matrice[i][j]=0;
        }
    }
}

void initial_tab_destru(int tab_destru_l[6],int tab_destru_c[6])
{
    int i;
    for(i=1;i<=5;i++)
    {
        tab_destru_l[i]=0;
        tab_destru_c[i]=0;
    }
}

void initial_matrice_grille2(int matrice2[11][11])
{
    int i,j;
    for(i=1;i<=10;i++)
    {
        for(j=1;j<=10;j++)
        {
            matrice2[i][j]=0;
        }
    }
}

void initial_mat_inter(int matrice[11][11],int intermat[11][11])
{
    int i,j;
    for(i=1;i<=10;i++)
    {
        for(j=1;j<=10;j++)
        {
            intermat[i][j]=matrice[i][j];
        }
    }
}
