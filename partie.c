#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <fmod/fmod.h>
#include <time.h>
#include "pieces.h"
#include "initialisations.h"
#include "modepc.h"
#include "sons.h"

void menu(SDL_Surface *acceuil,SDL_Surface *ecran,SDL_Rect positionMenu,int *partie_lancee,int *menu_lance)
{
    acceuil = SDL_LoadBMP("MenuBouton.bmp");
    SDL_BlitSurface(acceuil, NULL, ecran, &positionMenu);
    SDL_Flip(ecran);
    SDL_FreeSurface(acceuil);
    *menu_lance=1;
    *partie_lancee=0;
}

void menu2 (SDL_Surface *acceuil,SDL_Surface *ecran,SDL_Rect positionMenu,int *menu_lance)
{
    acceuil = SDL_LoadBMP("MenuModeJeu.bmp");
    SDL_BlitSurface(acceuil, NULL, ecran, &positionMenu);
    SDL_Flip(ecran);
    SDL_FreeSurface(acceuil);
    *menu_lance=2;
}

void menu3 (SDL_Surface *acceuil,SDL_Surface *ecran,SDL_Rect positionMenu,int *menu_lance)
{
    acceuil = SDL_LoadBMP("MenuNewSave.bmp");
    SDL_BlitSurface(acceuil, NULL, ecran, &positionMenu);
    SDL_Flip(ecran);
    SDL_FreeSurface(acceuil);
    *menu_lance=3;
}

void menu_en_jeu(SDL_Surface *ecran,SDL_Surface *menupause,SDL_Rect positionMiniMenu,int *menu_lance)
{
    *menu_lance=4;
    menupause=SDL_LoadBMP("MenuPause.bmp");
    positionMiniMenu.x=ecran->w / 2 - menupause->w / 2; positionMiniMenu.y = ecran->h / 2 - menupause->h /2;
    SDL_BlitSurface(menupause, NULL, ecran, &positionMiniMenu);
    SDL_Flip(ecran);
    SDL_FreeSurface(menupause);
}

void Proc_grille(SDL_Surface *grille,SDL_Surface *ecran, SDL_Surface *background,SDL_Rect positionMenu,int matrice[11][11] ,int *partie_lancee,int mode_jeu,SDL_Surface *texte,TTF_Font *police, char score[20],int compteur,SDL_Color couleurNoire, SDL_Color couleurBlanche,SDL_Rect positionTexte)
{

   int i,j; int k=1;

   *partie_lancee=1;

    SDL_Rect positionGrille;
    if(mode_jeu==1)background=SDL_LoadBMP("FondModeJoueur.bmp");
    else background=SDL_LoadBMP("FondModePc.bmp");

    SDL_BlitSurface(background,NULL,ecran,&positionMenu); /*on blit l'arriere plan en jeu */

        for(i=5;i<=14;i++)
        {
            positionGrille.x=i*50;
            for(j=0;j<10;j++)
                {
                  positionGrille.y=j*50;

                  grille=le_carre(matrice[j+1][k],mode_jeu);                            /* J+1 CAR ON COMMENCE NOTRE MATRICE PAR 1 OUBLIE PAS*/

                  SDL_BlitSurface(grille, NULL, ecran, &positionGrille);
                }
           k=k+1;
        }

                   affich_score(texte,police,score,compteur,couleurNoire,couleurBlanche,positionTexte,ecran);
                   SDL_Flip(ecran);
                   SDL_FreeSurface(grille);SDL_FreeSurface(background);SDL_FreeSurface(texte);
}

void Proc_grille2(SDL_Surface *grille,SDL_Surface *grille2,SDL_Surface *ecran, SDL_Surface *background,SDL_Rect positionMenu,int matrice[11][11],int matrice2[11][11] ,int *partie_lancee,int mode_jeu,SDL_Surface *texte,SDL_Surface *texte2,TTF_Font *police, char score[20],char score2[20],int compteur,int compteur2,SDL_Color couleurNoire, SDL_Color couleurBlanche,SDL_Rect positionTexte3,SDL_Rect positionTexte2)
{

   int i,j; int k=1;

   *partie_lancee=1;

    SDL_Rect positionGrille;
    SDL_Rect positionGrille2;

    background=SDL_LoadBMP("FondModeJoueur.bmp");

    SDL_BlitSurface(background,NULL,ecran,&positionMenu); /*on blit l'arriere plan en jeu */

        for(i=0;i<10;i++)
        {
            positionGrille.x=i*45;
            positionGrille2.x=positionGrille.x + 494;
            for(j=0;j<10;j++)
                {
                  positionGrille.y=(j+1.25)*45;
                  positionGrille2.y=positionGrille.y;

                  grille=le_carre(matrice[j+1][k],mode_jeu);                            /* J+1 CAR ON COMMENCE NOTRE MATRICE PAR 1 OUBLIE PAS*/
                  grille2=le_carre(matrice2[j+1][k],mode_jeu);

                  SDL_BlitSurface(grille, NULL, ecran, &positionGrille);
                  SDL_BlitSurface(grille2, NULL, ecran, &positionGrille2);
                }
           k=k+1;
        }
                   affich_score(texte,police,score,compteur,couleurNoire,couleurBlanche,positionTexte3,ecran);
                   affich_score(texte2,police,score2,compteur2,couleurNoire,couleurBlanche,positionTexte2,ecran);
                   SDL_Flip(ecran);
                   SDL_FreeSurface(grille);SDL_FreeSurface(background);SDL_FreeSurface(grille2);SDL_FreeSurface(texte);SDL_FreeSurface(texte);
}

void Remplir_piece_jouable (SDL_Surface *ecran,int tab_piece_jouable[4],int mode_jeu)
{
    int i,c;
    SDL_Surface *piece=NULL; SDL_Rect position;
    srand(time(NULL));
    for(i=1;i<=3;i++)
    {

           if(tab_piece_jouable[i]==0)
           {
           c = (rand() % 27) + 1;                                  /*valeur aléatoire*/
           piece=la_piece(c,mode_jeu);                                      /* piece correspondante à la valeur aléatoire*/
           position.y=638-piece->h/2;
           if(i==1)position.x=1024/6 - piece->w /2;
           if(i==2)position.x=1024/2 - piece->w /2;               /* condition pour ne remplir que la case vide */
           if(i==3)position.x=1024*5/6- piece->w /2;
           SDL_SetColorKey(piece, SDL_SRCCOLORKEY, SDL_MapRGB(piece->format, 255, 255, 255));
           SDL_BlitSurface(piece, NULL, ecran, &position);
           tab_piece_jouable[i]=c;                               /*on met la valeur correspondant à la pièce qu'on a mise dans la case*/
           }

    }
    if(mode_jeu!=3)
    {SDL_Flip(ecran);                                      /* MIGHT CAUSE TROUBLE LATER !!!!!!!!!!!!!!! */
    SDL_FreeSurface(piece);}
}

void show_playable(SDL_Surface *ecran,int tab_piece_jouable[4],int piece_selected,int mode_jeu)          /*BLIT LES PIECES DANS LEURS CASES QUAND ON LES BOUGE */
{
    int i; SDL_Surface *piece=NULL; SDL_Rect position;
               for(i=1;i<=3;i++)
               {
                   if(i!=piece_selected)                                             //on blit tout sauf la pièce selectionnée
                   {
                   piece = la_piece(tab_piece_jouable[i],mode_jeu);
                   position.y=638-piece->h/2;
                   if(i==1)position.x=1024/6 - piece->w /2;
                   if(i==2)position.x=1024/2 - piece->w /2;               /* condition pour ne remplir que la case vide */
                   if(i==3)position.x=1024*5/6- piece->w /2;
                   SDL_SetColorKey(piece, SDL_SRCCOLORKEY, SDL_MapRGB(piece->format, 255, 255, 255));
                   SDL_BlitSurface(piece, NULL, ecran, &position);
                   }
               }
               SDL_Flip(ecran);
               SDL_FreeSurface(piece);
}

void partie_perdue(SDL_Surface *acceuil,SDL_Surface *ecran,SDL_Rect positionMenu)
{
    acceuil = SDL_LoadBMP("MenuFin.bmp");
    SDL_Rect positionPerdu;
    positionPerdu.x=ecran->w / 2 - acceuil->w / 2;  ;positionPerdu.y=ecran->h / 2 - acceuil->h / 2;
    SDL_BlitSurface(acceuil, NULL, ecran, &positionPerdu);
    SDL_Flip(ecran);
    SDL_FreeSurface(acceuil);
}


