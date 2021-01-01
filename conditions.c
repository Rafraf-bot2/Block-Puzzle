#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "initialisations.h"
#include "partie.h"
#include "modepc.h"
#include "pieces.h"
#include "sons.h"

/*nous donne la colonne ou on a cliqué*/
int la_colonne(SDL_Rect curseur,int mode_jeu)
{
   if(mode_jeu!=3)
   {
    if(curseur.x>250&&curseur.x<=300)
    return 1;
    else if(curseur.x>300&&curseur.x<=350)
    return 2;
    else if(curseur.x>350&&curseur.x<=400)
    return 3;
    else if(curseur.x>400&&curseur.x<=450)
    return 4;
    else if(curseur.x>450&&curseur.x<=500)
    return 5;
    else if(curseur.x>500&&curseur.x<=550)
    return 6;
    else if(curseur.x>550&&curseur.x<=600)
    return 7;
    else if(curseur.x>600&&curseur.x<=650)
    return 8;
    else if(curseur.x>650&&curseur.x<=700)
    return 9;
    else
    return 10;
   }
   else
   {
    if(curseur.x>0&&curseur.x<=45)
    return 1;
    else if(curseur.x>45&&curseur.x<=90)
    return 2;
    else if(curseur.x>90&&curseur.x<=135)
    return 3;
    else if(curseur.x>135&&curseur.x<=180)
    return 4;
    else if(curseur.x>180&&curseur.x<=225)
    return 5;
    else if(curseur.x>225&&curseur.x<=270)
    return 6;
    else if(curseur.x>270&&curseur.x<=315)
    return 7;
    else if(curseur.x>315&&curseur.x<=360)
    return 8;
    else if(curseur.x>360&&curseur.x<=405)
    return 9;
    else
    return 10;
   }
}

/* nous donne la ligne ou on a cliqué*/
int la_ligne(SDL_Rect curseur,int mode_jeu)
{
   if(mode_jeu!=3)
   {
    if(curseur.y>0&& curseur.y<=50)
    return 1;
    else if(curseur.y>50&& curseur.y<=100)
    return 2;
    else if(curseur.y>100&& curseur.y<=150)
    return 3;
    else if(curseur.y>150&& curseur.y<=200)
    return 4;
    else if(curseur.y>200&& curseur.y<=250)
    return 5;
    else if(curseur.y>250&& curseur.y<=300)
    return 6;
    else if(curseur.y>300&& curseur.y<=350)
    return 7;
    else if(curseur.y>350&& curseur.y<=400)
    return 8;
    else if(curseur.y>400&& curseur.y<=450)
    return 9;
    else
    return 10;
   }
   else
   {
    if(curseur.y>55&& curseur.y<=100)
    return 1;
    else if(curseur.y>100&& curseur.y<=145)
    return 2;
    else if(curseur.y>145&& curseur.y<=190)
    return 3;
    else if(curseur.y>190&& curseur.y<=235)
    return 4;
    else if(curseur.y>235&& curseur.y<=280)
    return 5;
    else if(curseur.y>280&& curseur.y<=325)
    return 6;
    else if(curseur.y>325&& curseur.y<=370)
    return 7;
    else if(curseur.y>370&& curseur.y<=415)
    return 8;
    else if(curseur.y>415&& curseur.y<=460)
    return 9;
    else
    return 10;
   }
}

/*verifie si on peut poser la pièce dans l'emplacement voulu*/
int piece_posable(int num_piece,int matrice[11][11],int i,int j)   /* p=tab_piece_jouable[1ou2ou3]*/   /*i,j : ligne/colonne matrice ou on veut poser*/
{
    int b=0;
    switch(num_piece)
    {
         case 1:
             if (matrice[i][j]!=0) b=1;
             if(b==0)
             {
                 matrice[i][j]=1;
             }
         break;

         case 2:
             if (i==10)              b=1;
             if (matrice[i][j]!=0)   b=1;
             if (matrice[i+1][j]!=0) b=1;
             if(b==0)
             {
                 matrice[i][j]=2;
                 matrice[i+1][j]=2;
             }
         break;

         case 3:
             if (j==10)              b=1;
             if (matrice[i][j]!=0)   b=1;
             if (matrice[i][j+1]!=0) b=1;
             if(b==0)
             {
                 matrice[i][j]=2;
                 matrice[i][j+1]=2;
             }
         break;

         case 4:
             if (i>8)                b=1;
             if (matrice[i][j]!=0)   b=1;
             if (matrice[i+1][j]!=0) b=1;
             if (matrice[i+2][j]!=0) b=1;
             if(b==0)
             {
                 matrice[i][j]=3;
                 matrice[i+1][j]=3;
                 matrice[i+2][j]=3;
             }
         break;

         case 5:
             if (j>8)                b=1;
             if (matrice[i][j]!=0)   b=1;
             if (matrice[i][j+1]!=0) b=1;
             if (matrice[i][j+2]!=0) b=1;
             if(b==0)
             {
                 matrice[i][j]=3;
                 matrice[i][j+1]=3;
                 matrice[i][j+2]=3;
             }
         break;

         case 6:
             if (i==10)              b=1;
             if (j==10)              b=1;
             if (matrice[i][j]!=0)   b=1;
             if (matrice[i+1][j]!=0) b=1;
             if (matrice[i+1][j+1]!=0)b=1;
             if(b==0)
             {
                 matrice[i][j]=4;
                 matrice[i+1][j]=4;
                 matrice[i+1][j+1]=4;
             }
         break;

         case 7:
             if (i==10)              b=1;
             if (j==10)              b=1;
             if (matrice[i][j]!=0)   b=1;
             if (matrice[i][j+1]!=0) b=1;
             if (matrice[i+1][j]!=0) b=1;
             if (b==0)
             {
                 matrice[i][j]=4;
                 matrice[i][j+1]=4;
                 matrice[i+1][j]=4;
             }
         break;

         case 8:
             if (i==10)              b=1;
             if (j==10)              b=1;
             if (matrice[i][j]!=0)   b=1;
             if (matrice[i][j+1]!=0) b=1;
             if (matrice[i+1][j+1]!=0)b=1;
             if (b==0)
             {
                 matrice[i][j]=4;
                 matrice[i][j+1]=4;
                 matrice[i+1][j+1]=4;
             }
         break;

         case 9:
             if (i==10)              b=1;
             if (j==10)              b=1;
             if (matrice[i][j+1]!=0) b=1;
             if (matrice[i+1][j]!=0) b=1;
             if (matrice[i+1][j+1]!=0)b=1;
             if (b==0)
             {
                 matrice[i][j+1]=4;
                 matrice[i+1][j]=4;
                 matrice[i+1][j+1]=4;
             }
         break;

         case 10:
             if (i==10)              b=1;
             if (j==10)              b=1;
             if (matrice[i][j]!=0)  b=1;
             if (matrice[i][j+1]!=0) b=1;
             if (matrice[i+1][j]!=0) b=1;
             if (matrice[i+1][j+1]!=0)b=1;
             if (b==0)
             {
                 matrice[i][j]=5;
                 matrice[i][j+1]=5;
                 matrice[i+1][j]=5;
                 matrice[i+1][j+1]=5;
             }
         break;

         case 11:
             if (i==10)              b=1;
             if (j>8)                b=1;
             if (matrice[i][j+1]!=0) b=1;
             if (matrice[i+1][j]!=0)b=1;
             if (matrice[i+1][j+1]!=0)b=1;
             if (matrice[i+1][j+2]!=0)b=1;
             if (b==0)
             {
                 matrice[i][j+1]=6;
                 matrice[i+1][j]=6;
                 matrice[i+1][j+1]=6;
                 matrice[i+1][j+2]=6;
             }
         break;

         case 12:
             if (i>8)                b=1;
             if (j==10)              b=1;
             if (matrice[i][j]!=0)   b=1;
             if (matrice[i+1][j]!=0)b=1;
             if (matrice[i+1][j+1]!=0)b=1;
             if (matrice[i+2][j]!=0) b=1;
             if (b==0)
             {
                 matrice[i][j]=6;
                 matrice[i+1][j]=6;
                 matrice[i+1][j+1]=6;
                 matrice[i+2][j]=6;
             }
         break;

         case 13:
             if (i==10)              b=1;
             if (j>8)                b=1;
             if (matrice[i][j]!=0)   b=1;
             if (matrice[i][j+1]!=0)b=1;
             if (matrice[i][j+2]!=0) b=1;
             if (matrice[i+1][j+1]!=0)b=1;
             if (b==0)
             {
                 matrice[i][j]=6;
                 matrice[i][j+1]=6;
                 matrice[i][j+2]=6;
                 matrice[i+1][j+1]=6;
             }
         break;

         case 14:
             if (i>8)                b=1;
             if (j==10)              b=1;
             if (matrice[i][j+1]!=0) b=1;
             if (matrice[i+1][j]!=0)b=1;
             if (matrice[i+1][j+1]!=0)b=1;
             if (matrice[i+2][j+1]!=0)b=1;
             if (b==0)
             {
                 matrice[i][j+1]=6;
                 matrice[i+1][j]=6;
                 matrice[i+1][j+1]=6;
                 matrice[i+2][j+1]=6;
             }
         break;

         case 15:
             if (i>7)                b=1;
             if (matrice[i][j]!=0)   b=1;
             if (matrice[i+1][j]!=0) b=1;
             if (matrice[i+2][j]!=0) b=1;
             if (matrice[i+3][j]!=0) b=1;
             if (b==0)
             {
                 matrice[i][j]=7;
                 matrice[i+1][j]=7;
                 matrice[i+2][j]=7;
                 matrice[i+3][j]=7;
             }
         break;

         case 16:
             if (j>7)                b=1;
             if (matrice[i][j]!=0)   b=1;
             if (matrice[i][j+1]!=0) b=1;
             if (matrice[i][j+2]!=0) b=1;
             if (matrice[i][j+3]!=0) b=1;
             if (b==0)
             {
                 matrice[i][j]=7;
                 matrice[i][j+1]=7;
                 matrice[i][j+2]=7;
                 matrice[i][j+3]=7;
             }
         break;

         case 17:
             if (i>6)                b=1;
             if (matrice[i][j]!=0)   b=1;
             if (matrice[i+1][j]!=0) b=1;
             if (matrice[i+2][j]!=0) b=1;
             if (matrice[i+3][j]!=0) b=1;
             if (matrice[i+4][j]!=0) b=1;
             if (b==0)
             {
                 matrice[i][j]=8;
                 matrice[i+1][j]=8;
                 matrice[i+2][j]=8;
                 matrice[i+3][j]=8;
                 matrice[i+4][j]=8;
             }
         break;

         case 18:
             if (j>6)                b=1;
             if (matrice[i][j]!=0)   b=1;
             if (matrice[i][j+1]!=0) b=1;
             if (matrice[i][j+2]!=0) b=1;
             if (matrice[i][j+3]!=0) b=1;
             if (matrice[i][j+4]!=0) b=1;
             if (b==0)
             {
                 matrice[i][j]=8;
                 matrice[i][j+1]=8;
                 matrice[i][j+2]=8;
                 matrice[i][j+3]=8;
                 matrice[i][j+4]=8;
             }
         break;

         case 19:
             if (i>8)               b=1;
             if (j>8)               b=1;
             if (matrice[i][j]!=0)  b=1;
             if (matrice[i+1][j]!=0)b=1;
             if (matrice[i+2][j]!=0)b=1;
             if (matrice[i+2][j+1]!=0)b=1;
             if (matrice[i+2][j+2]!=0)b=1;
             if (b==0)
             {
                 matrice[i][j]=9;
                 matrice[i+1][j]=9;
                 matrice[i+2][j]=9;
                 matrice[i+2][j+1]=9;
                 matrice[i+2][j+2]=9;
             }
         break;

         case 20:
             if (i>8)               b=1;
             if (j>8)               b=1;
             if (matrice[i][j]!=0)  b=1;
             if (matrice[i][j+1]!=0)b=1;
             if (matrice[i][j+2]!=0)b=1;
             if (matrice[i+1][j]!=0)b=1;
             if (matrice[i+2][j]!=0)b=1;
             if (b==0)
             {
                 matrice[i][j]=9;
                 matrice[i][j+1]=9;
                 matrice[i][j+2]=9;
                 matrice[i+1][j]=9;
                 matrice[i+2][j]=9;
             }
         break;

         case 21:
             if (i>8)               b=1;
             if (j>8)               b=1;
             if (matrice[i][j]!=0)  b=1;
             if (matrice[i][j+1]!=0)b=1;
             if (matrice[i][j+2]!=0)b=1;
             if (matrice[i+1][j+2]!=0)b=1;
             if (matrice[i+2][j+2]!=0)b=1;
             if (b==0)
             {
                 matrice[i][j]=9;
                 matrice[i][j+1]=9;
                 matrice[i][j+2]=9;
                 matrice[i+1][j+2]=9;
                 matrice[i+2][j+2]=9;
             }
         break;

         case 22:
             if (i>8)               b=1;
             if (j>8)               b=1;
             if (matrice[i][j+2]!=0)b=1;
             if (matrice[i+1][j+2]!=0)b=1;
             if (matrice[i+2][j+2]!=0)b=1;
             if (matrice[i+2][j+1]!=0)b=1;
             if (matrice[i+2][j]!=0)b=1;
             if (b==0)
             {
                 matrice[i][j+2]=9;
                 matrice[i+1][j+2]=9;
                 matrice[i+2][j+2]=9;
                 matrice[i+2][j+1]=9;
                 matrice[i+2][j]=9;
             }
         break;

         case 23:
             if(i==10)              b=1;
             if(j>8)                b=1;
             if (matrice[i][j]!=0)  b=1;
             if (matrice[i][j+2]!=0)b=1;
             if (matrice[i+1][j]!=0)b=1;
             if (matrice[i+1][j+1]!=0)b=1;
             if (matrice[i+1][j+2]!=0)b=1;
             if (b==0)
             {
                 matrice[i][j]=10;
                 matrice[i][j+2]=10;
                 matrice[i+1][j]=10;
                 matrice[i+1][j+1]=10;
                 matrice[i+1][j+2]=10;
             }
         break;

         case 24:
             if(i>8)                b=1;
             if(j==10)              b=1;
             if (matrice[i][j]!=0)  b=1;
             if (matrice[i][j+1]!=0)b=1;
             if (matrice[i+1][j]!=0)b=1;
             if (matrice[i+2][j]!=0)b=1;
             if (matrice[i+2][j+1]!=0)b=1;
             if (b==0)
             {
                 matrice[i][j]=10;
                 matrice[i][j+1]=10;
                 matrice[i+1][j]=10;
                 matrice[i+2][j]=10;
                 matrice[i+2][j+1]=10;
             }
         break;

         case 25:
             if (i==10)             b=1;
             if (j>8)               b=1;
             if (matrice[i][j]!=0)  b=1;
             if (matrice[i][j+1]!=0)b=1;
             if (matrice[i][j+2]!=0)b=1;
             if (matrice[i+1][j]!=0)b=1;
             if (matrice[i+1][j+2]!=0)b=1;
             if (b==0)
             {
                 matrice[i][j]=10;
                 matrice[i][j+1]=10;
                 matrice[i][j+2]=10;
                 matrice[i+1][j]=10;
                 matrice[i+1][j+2]=10;
             }
         break;

         case 26:
             if (i>8)               b=1;
             if (j==10)             b=1;
             if (matrice[i][j]!=0)  b=1;
             if (matrice[i][j+1]!=0)b=1;
             if (matrice[i+1][j+1]!=0)b=1;
             if (matrice[i+2][j]!=0)b=1;
             if (matrice[i+2][j+1]!=0)b=1;
             if (b==0)
             {
                 matrice[i][j]=10;
                 matrice[i][j+1]=10;
                 matrice[i+1][j+1]=10;
                 matrice[i+2][j]=10;
                 matrice[i+2][j+1]=10;
             }
         break;

         case 27:
             if (i>8)               b=1;
             if (j>8)               b=1;
             if (matrice[i][j]!=0)  b=1;
             if (matrice[i][j+1]!=0)b=1;
             if (matrice[i][j+2]!=0)b=1;
             if (matrice[i+1][j]!=0)b=1;
             if (matrice[i+1][j+1]!=0)b=1;
             if (matrice[i+1][j+2]!=0)b=1;
             if (matrice[i+2][j]!=0)b=1;
             if (matrice[i+2][j+1]!=0)b=1;
             if (matrice[i+2][j+2]!=0)b=1;
             if(b==0)
             {
                 matrice[i][j]=11;
                 matrice[i][j+1]=11;
                 matrice[i][j+2]=11;
                 matrice[i+1][j]=11;
                 matrice[i+1][j+1]=11;
                 matrice[i+1][j+2]=11;
                 matrice[i+2][j]=11;
                 matrice[i+2][j+1]=11;
                 matrice[i+2][j+2]=11;
             }
         break;
    }
    return b;
}

void verif_explosion(int matrice[11][11],int tab_destru_l[6],int tab_destru_c[6])
{
    int i,j,kl=1,kc=1,b;
    for(i=1;i<=10;i++)
    {
      b=0;j=1;
      while(b==0&&j<=10)
      {
          if(matrice[i][j]==0) b=1;
          j=j+1;
      }
      if(b==0){tab_destru_l[kl]=i;kl=kl+1;}
     }

    for(j=1;j<=10;j++)
    {
        b=0;i=1;
            while(b==0&&i<=10)
            {
                if(matrice[i][j]==0) b=1;
                i=i+1;
            }
            if(b==0){tab_destru_c[kc]=j;kc=kc+1;}
    }
}
void effacer_lc(int matrice[11][11],int tab_piece_jouable[4],int piece_selected,int matrice2[11][11],int tab_piece_jouable2[4],SDL_Surface *ecran,int mode_jeu,SDL_Rect positionMenu,int partie_lancee,SDL_Surface *grille,SDL_Surface *grille2,SDL_Surface *background,SDL_Surface *texte,TTF_Font *police, char score[20],int *compteur,SDL_Color couleurNoire, SDL_Color couleurBlanche,SDL_Rect positionTexte,SDL_Surface *texte2,char score2[20],int *compteur2,SDL_Rect positionTexte3,SDL_Rect positionTexte2)
{
            int k,m,gp,b,som=0;
            int tab_destru_c[6]; int tab_destru_l[6];
            initial_tab_destru(tab_destru_l,tab_destru_c);
            k=1;
            verif_explosion(matrice,tab_destru_l,tab_destru_c);
            while(tab_destru_l[k]!=0)
            {
             for(m=1;m<=10;m++)
                {
                  matrice[tab_destru_l[k]][m]=0;
                  if(mode_jeu!=3)Proc_grille(grille,ecran,background,positionMenu,matrice,&partie_lancee,mode_jeu,texte,police,score,*compteur,couleurNoire,couleurBlanche,positionTexte);
                  else Proc_grille2(grille,grille2,ecran,background,positionMenu,matrice,matrice2,&partie_lancee,mode_jeu,texte,texte2,police,score,score2,*compteur,*compteur2,couleurNoire,couleurBlanche,positionTexte3,positionTexte2);
                  show_playable(ecran,tab_piece_jouable,piece_selected,mode_jeu);
                }
                k=k+1;
            }
            som=k-1;
            k=1;
            while(tab_destru_c[k]!=0)
            {
              for(m=1;m<=10;m++)
              {
                matrice[m][tab_destru_c[k]]=0;
                if(mode_jeu!=3)Proc_grille(grille,ecran,background,positionMenu,matrice,&partie_lancee,mode_jeu,texte,police,score,*compteur,couleurNoire,couleurBlanche,positionTexte);
                else Proc_grille2(grille,grille2,ecran,background,positionMenu,matrice,matrice2,&partie_lancee,mode_jeu,texte,texte2,police,score,score2,*compteur,*compteur2,couleurNoire,couleurBlanche,positionTexte3,positionTexte2);
                show_playable(ecran,tab_piece_jouable,piece_selected,mode_jeu);
              }

              k=k+1;
            }
            som=som+k-1;
            *compteur=ajout_score_explosion(som,*compteur);

            if(mode_jeu!=3)Proc_grille(grille,ecran,background,positionMenu,matrice,&partie_lancee,mode_jeu,texte,police,score,*compteur,couleurNoire,couleurBlanche,positionTexte);              /*affiche la grille*/
            else
            {
            b=1;gp=-1;som=0;
            pc_pose(matrice2,tab_piece_jouable2,&gp,&b,ecran,mode_jeu,compteur2);
            initial_tab_destru(tab_destru_l,tab_destru_c);
            k=1;
            verif_explosion(matrice2,tab_destru_l,tab_destru_c);
            while(tab_destru_l[k]!=0)
            {
              for(m=1;m<=10;m++)
              {
                matrice2[tab_destru_l[k]][m]=0;
                Proc_grille2(grille,grille2,ecran,background,positionMenu,matrice,matrice2,&partie_lancee,mode_jeu,texte,texte2,police,score,score2,*compteur,*compteur2,couleurNoire,couleurBlanche,positionTexte3,positionTexte2);
                show_playable(ecran,tab_piece_jouable,piece_selected,mode_jeu);
              }
              k=k+1;
            }
            som=k-1;
            k=1;
            while(tab_destru_c[k]!=0)
            {
              for(m=1;m<=10;m++)
              {
                matrice2[m][tab_destru_c[k]]=0;
                Proc_grille2(grille,grille2,ecran,background,positionMenu,matrice,matrice2,&partie_lancee,mode_jeu,texte,texte2,police,score,score2,*compteur,*compteur2,couleurNoire,couleurBlanche,positionTexte3,positionTexte2);
                show_playable(ecran,tab_piece_jouable,piece_selected,mode_jeu);
              }
              k=k+1;
             }
             som=som+k-1;
             *compteur2=ajout_score_explosion(som,*compteur2);
             Proc_grille2(grille,grille2,ecran,background,positionMenu,matrice,matrice2,&partie_lancee,mode_jeu,texte,texte2,police,score,score2,*compteur,*compteur2,couleurNoire,couleurBlanche,positionTexte3,positionTexte2);
            }
           show_playable(ecran,tab_piece_jouable,piece_selected,mode_jeu);
           SDL_Flip(ecran);
}

int jouabilite_piece(int matrice[11][11],int intermat[11][11],int val)
{
    int i=1,j,b=1;
    while (b==1 && i<=10)
    {
        j=1;
        while (b==1 && j<=10)
        {
            initial_mat_inter(matrice,intermat);
            b=piece_posable(val,intermat,i,j);
            j++;
        }
        i++;
    }
    return b;
}

int nbr_pieces_non_jouables(int tab_piece_jouable[4],int matrice[11][11],int intermat[11][11])
{
    int i,k=0;
    for(i=1;i<=3;i++)
    {
        if (jouabilite_piece(matrice,intermat,tab_piece_jouable[i])==1) k++;
    }
    return k;
}
