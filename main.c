#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <fmod/fmod.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include "partie.h"
#include "pieces.h"
#include "initialisations.h"
#include "sons.h"
#include "conditions.h"
#include "modepc.h"

int main(int argc, char *argv[])
{
    /*declaration des surfaces */
    SDL_Surface *ecran = NULL, *acceuil = NULL, *tuto=NULL, *grille=NULL,*background=NULL, *piece=NULL, *menupause=NULL, *grille2=NULL, *texte=NULL, *texte2=NULL;

    /* declaration des positions */
    SDL_Rect positionMenu,positionTuto,position_piece,positionMiniMenu;

    /* lancer SDL */
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
    SDL_WM_SetIcon(SDL_LoadBMP("icone.bmp"), NULL);     /* icone du jeu */
    ecran = SDL_SetVideoMode(1024, 768, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);    /*resolution de l'image*/

    /*le titre du jeu*/
    SDL_WM_SetCaption("Block Puzzle", NULL);
    /*charge les images de l'acceuil et du tutoriel*/
    acceuil = SDL_LoadBMP("MenuBouton.bmp");tuto=SDL_LoadBMP("tuto.bmp");


    /*initialiser les positions de l'acceuil et du tuto*/
    positionMenu.x = ecran->w / 2 - acceuil->w / 2; positionTuto.x=ecran->w / 2 - tuto->w / 2;
    positionMenu.y = ecran->h / 2 - acceuil->h / 2; positionTuto.y=200;

//musique_menu(); /* on lance la musique du menu*/

    int partie_lancee; /*variable pour savoir  si on est dans un menu ou en jeu */
    int menu_lance;    /*variable pour savoir dans quel menu on est*/
    int mode_jeu;      /*variable pour savoir dans quel mode de jeu on est*/

menu(acceuil,ecran,positionMenu,&partie_lancee,&menu_lance); /* blit le menu */

     SDL_SetColorKey(tuto, SDL_SRCCOLORKEY, SDL_MapRGB(tuto->format, 100, 100, 100)); /*efface le gris de l'image du tuto */
     SDL_BlitSurface(tuto, NULL, ecran, &positionTuto);                               /*blit le tuto */
     SDL_Flip(ecran);                                                                 /*affiche l'ecran à jour*/

    int matrice[11][11]={0};                   /* matrice pour savoir que contient chaque case de la grille */
    int matrice2[11][11]={0};
    int tab_piece_jouable[4]={0};              /* vecteur pour connaître les 3 pieces jouables en bas de l'ecran */
    int tab_piece_jouable2[4]={0};
    int tab_destru_l[6]; int tab_destru_c[6];  /* vecteurs pour savoir si une LIGNE ou une COLONNE est remplie*/
    int intermat[11][11];

    int continuer=1;         /*variable de contrôle , à 0 le programme se ferme */

    int skiptuto=0;          /*skiptuto pour savoir si on a fermé le tuto ou pas*/

    int piece_selected=0;    /*pour savoir si on a selectionné une pièce à jouer ou pas*/

    int piece_put;           /*savoir si on a posé la pièce selectionnée ou pas*/

    /*position du curseur */
    SDL_Rect curseur;
    /*emplacement sur la grille dans lequel on a posé la pièce*/
    SDL_Rect positionPiecePosee;

    int i,j,b;
    int k,m;
    int ta_perdu=0;

int gp;
int continuer2;
int tempsPrecedent=0,tempsActuel=0;
int tempsZik1,tempsZik2=0;

    SDL_Event event; /*type event pour savoir si les périphériques d'entrées ont étés utilisés*/
    SDL_Event event2;

    TTF_Init();
    TTF_Font *police = NULL;
    police = TTF_OpenFont("bebas.ttf",35);
    char score[20] = ""; char score2[20] = "";
    int compteur,compteur2;
    SDL_Color couleurNoire = {255, 255, 0};
    SDL_Color couleurBlanche = {0,0,255};
    SDL_Color couleurBleue= {255,255,255};
    SDL_Rect positionTexte,positionTexte2,positionTexte3,positionTextePause;
    positionTexte.x=0; positionTexte.y=120;
    positionTexte3.x=173;positionTexte2.y=5;
    positionTexte2.x=663;positionTexte3.y=5;
    positionTextePause.x=410; positionTextePause.y=120;
    compteur=0;compteur2=0;




    while(continuer==1)            /*BOUCLE PRINCIPALE*/
    {

      SDL_WaitEvent(&event);
        switch(event.type)
        {
         case SDL_KEYDOWN:                   /*savoir si on a appuyé sur une touche*/

           switch (event.key.keysym.sym)
           {
            case SDLK_ESCAPE:                             /*clique sur échap*/

         /*si la partie n'est PAS lancée on quitte le programme*/
                if (partie_lancee==0 && menu_lance==1) continuer=0;
                else if (partie_lancee==0 && menu_lance!=1)
                {menu(acceuil,ecran,positionMenu,&partie_lancee,&menu_lance);initial_tab_piece_jouable(tab_piece_jouable);initial_matrice_grille(matrice);compteur=0;initial_matrice_grille(matrice2);initial_tab_piece_jouable(tab_piece_jouable2);compteur2=0;}
                else if(partie_lancee==1 && piece_selected==0)
        /*si la partie est lancée on revient au menu on blit le menu ET on remet le tableau des pieces jouables et la matrice de la grille à 0*/
                {menu(acceuil,ecran,positionMenu,&partie_lancee,&menu_lance);initial_tab_piece_jouable(tab_piece_jouable);initial_matrice_grille(matrice);compteur=0;initial_matrice_grille(matrice2);initial_tab_piece_jouable(tab_piece_jouable2);compteur2=0;}
                else if (partie_lancee==1 && piece_selected>0){
        /*si une pièce est selectionnée on la lâche */
                        piece_selected=0; SDL_ShowCursor(SDL_ENABLE);
                        if(mode_jeu==1)Proc_grille(grille,ecran,background,positionMenu,matrice,&partie_lancee,mode_jeu,texte,police,score,compteur,couleurNoire,couleurBlanche,positionTexte);
                        else Proc_grille2(grille,grille2,ecran,background,positionMenu,matrice,matrice2,&partie_lancee,mode_jeu,texte,texte2,police,score,score2,compteur,compteur2,couleurNoire,couleurBlanche,positionTexte3,positionTexte2);
                        show_playable(ecran,tab_piece_jouable,piece_selected,mode_jeu);
                    }
              break;
           }
            case SDL_MOUSEBUTTONUP:
            if (event.button.button==SDL_BUTTON_LEFT)     /*clique bouton gauche souris*/
            {
               /*fermer la fenêtre du tuto*/
               if(skiptuto==0 && event.button.x>=689&&event.button.x<=720 && event.button.y>=340&& event.button.y<=367)
               {
                    skiptuto=1;
                    menu(acceuil,ecran,positionMenu,&partie_lancee,&menu_lance);
                    SDL_FreeSurface(tuto);
               }
               /*bouton passer au menu 2 (choisir le type de partie)*/
               if(skiptuto==1 && partie_lancee==0 && menu_lance==1 && event.button.x>=367&&event.button.x<=637 && event.button.y>=345&& event.button.y<=421)
               {
                   menu2 (acceuil,ecran,positionMenu,&menu_lance);
               }
               /*bouton quitter le programme quand on est au menu 1*/
               else if(skiptuto==1 && partie_lancee==0 && menu_lance==1 &&event.button.x>=367&&event.button.x<=637 && event.button.y>=487&& event.button.y<=564)
               {
                   continuer=0;
               }
               //bouton pour choisir le mode JOUEUR
               else if(skiptuto==1 && partie_lancee==0 && menu_lance==2 &&event.button.x>=373&&event.button.x<=635 && event.button.y>=275&& event.button.y<=356)
               {
                   mode_jeu=1;
                   menu3 (acceuil,ecran,positionMenu,&menu_lance);
               }

               else if(skiptuto==1 && partie_lancee==0 && menu_lance==2 &&event.button.x>=373&&event.button.x<=635 && event.button.y>=405&& event.button.y<=485)
               {
                   mode_jeu=2;
                   menu3 (acceuil,ecran,positionMenu,&menu_lance);
               }

               else if(skiptuto==1 && partie_lancee==0 && menu_lance==2 &&event.button.x>=373&&event.button.x<=635 && event.button.y>=533&& event.button.y<=612)
               {
                   mode_jeu=3;
                   menu3 (acceuil,ecran,positionMenu,&menu_lance);
               }
               else if(skiptuto==1 && partie_lancee==0 && menu_lance==2 &&event.button.x>=462&&event.button.x<=536 && event.button.y>=498&& event.button.y<=721)
               {
                   menu(acceuil,ecran,positionMenu,&partie_lancee,&menu_lance);
               }

               else if(skiptuto==1 && partie_lancee==0 && menu_lance==3 &&event.button.x>=462&&event.button.x<=536 && event.button.y>=625&& event.button.y<=700)
               {
                   menu2(acceuil,ecran,positionMenu,&menu_lance);
                   mode_jeu==0;
               }

               else if(skiptuto==1 && partie_lancee==0 && menu_lance==3 &&event.button.x>=350&&event.button.x<=655 && event.button.y>=343&& event.button.y<=424)
               {
                 if(mode_jeu==1)
                 {

                     charger_partieP(matrice,tab_piece_jouable,&compteur);
                     Proc_grille(grille,ecran,background,positionMenu,matrice,&partie_lancee,mode_jeu,texte,police,score,compteur,couleurNoire,couleurBlanche,positionTexte);
                     show_playable(ecran,tab_piece_jouable,piece_selected,mode_jeu);
                 }

                 else if(mode_jeu==2)
                 {

                   charger_partieIA(matrice,tab_piece_jouable,&compteur);
                   Proc_grille(grille,ecran,background,positionMenu,matrice,&partie_lancee,mode_jeu,texte,police,score,compteur,couleurNoire,couleurBlanche,positionTexte);
                   show_playable(ecran,tab_piece_jouable,piece_selected,mode_jeu);
                   continuer2=1;
                 }

                 else if(mode_jeu==3)
                 {
                     charger_partieIVP(matrice,matrice2,tab_piece_jouable,tab_piece_jouable2,&compteur,&compteur2);
                     Proc_grille2(grille,grille2,ecran,background,positionMenu,matrice,matrice2,&partie_lancee,mode_jeu,texte,texte2,police,score,score2,compteur,compteur2,couleurNoire,couleurBlanche,positionTexte3,positionTexte2);
                     show_playable(ecran,tab_piece_jouable,piece_selected,mode_jeu);

                 }
               }

               else if(skiptuto==1 && partie_lancee==0 && menu_lance==3 &&event.button.x>=350&&event.button.x<=655 && event.button.y>=485&& event.button.y<=565)
               {
                 if(mode_jeu!=3)
                   {
                    Proc_grille(grille,ecran,background,positionMenu,matrice,&partie_lancee,mode_jeu,texte,police,score,compteur,couleurNoire,couleurBlanche,positionTexte);
                    Remplir_piece_jouable(ecran,tab_piece_jouable,mode_jeu);
                    if (mode_jeu==2) continuer2=1;
                   }
                   else
                   {
                    Proc_grille2(grille,grille2,ecran,background,positionMenu,matrice,matrice2,&partie_lancee,mode_jeu,texte,texte2,police,score,score2,compteur,compteur2,couleurNoire,couleurBlanche,positionTexte3,positionTexte2);
                    Remplir_piece_jouable(ecran,tab_piece_jouable,mode_jeu);
                    Remplir_piece_jouable(ecran,tab_piece_jouable2,mode_jeu);
                    show_playable(ecran,tab_piece_jouable,piece_selected,mode_jeu);
                   }
               }

               else if (partie_lancee==1&& ta_perdu!=1&&event.button.x>=955&&event.button.x<=1020 && event.button.y>=30&& event.button.y<=100)
               {
                   menu_en_jeu(ecran,menupause,positionMiniMenu,&menu_lance);
                   affich_score(texte,police,score,compteur,couleurBleue,couleurBleue,positionTextePause,ecran);
               }

               else if(menu_lance!=4&&ta_perdu!=1 &&event.button.x>=950&&event.button.x<=1020 && event.button.y>=125&& event.button.y<=195)
               {
                   menu(acceuil,ecran,positionMenu,&partie_lancee,&menu_lance);
                   initial_tab_piece_jouable(tab_piece_jouable);
                   initial_matrice_grille(matrice);
                   compteur=0;
                   initial_matrice_grille(matrice2);
                   initial_tab_piece_jouable(tab_piece_jouable2);
                   compteur2=0;
               }

               else if(menu_lance==4)
               {
                    if(event.button.x>=366&&event.button.x<=410 && event.button.y>=288&& event.button.y<=342)
                    {
                      if(mode_jeu==1)sauvegarder_partieP(matrice,tab_piece_jouable,compteur);
                      else if(mode_jeu==2)sauvegarder_partieIA(matrice,tab_piece_jouable,compteur);
                      else sauvegarder_partieIVP(matrice,matrice2,tab_piece_jouable,tab_piece_jouable2,compteur,compteur2);
                    }

                    else if(event.button.x>=478&&event.button.x<=532 && event.button.y>=288&& event.button.y<=342)
                    {
                        if(mode_jeu!=3)
                        {
                        Proc_grille(grille,ecran,background,positionMenu,matrice,&partie_lancee,mode_jeu,texte,police,score,compteur,couleurNoire,couleurBlanche,positionTexte);
                        show_playable(ecran,tab_piece_jouable,piece_selected,mode_jeu);
                        }
                        else
                        {
                        Proc_grille2(grille,grille2,ecran,background,positionMenu,matrice,matrice2,&partie_lancee,mode_jeu,texte,texte2,police,score,score2,compteur,compteur2,couleurNoire,couleurBlanche,positionTexte3,positionTexte2);
                        show_playable(ecran,tab_piece_jouable,piece_selected,mode_jeu);
                        }
                        menu_lance=0;
                    }
                    else if (event.button.x>=600&&event.button.x<=655 && event.button.y>=288&& event.button.y<=342)
                    {
                        if(mode_jeu!=3)
                        {
                        compteur=0;
                        initial_matrice_grille(matrice);
                        initial_tab_piece_jouable(tab_piece_jouable);
                        Proc_grille(grille,ecran,background,positionMenu,matrice,&partie_lancee,mode_jeu,texte,police,score,compteur,couleurNoire,couleurBlanche,positionTexte);
                        Remplir_piece_jouable(ecran,tab_piece_jouable,mode_jeu);
                        }
                        else
                        {
                        compteur=0;compteur2=0;
                        initial_matrice_grille(matrice);
                        initial_matrice_grille2(matrice2);
                        initial_tab_piece_jouable(tab_piece_jouable);
                        initial_tab_piece_jouable(tab_piece_jouable2);
                        Proc_grille2(grille,grille2,ecran,background,positionMenu,matrice,matrice2,&partie_lancee,mode_jeu,texte,texte2,police,score,score2,compteur,compteur2,couleurNoire,couleurBlanche,positionTexte3,positionTexte2);
                        Remplir_piece_jouable(ecran,tab_piece_jouable2,mode_jeu);
                        Remplir_piece_jouable(ecran,tab_piece_jouable,mode_jeu);
                        SDL_Flip(ecran);SDL_FreeSurface(piece);
                        }
                        menu_lance=0;
                    }
               }

               else if(ta_perdu==1)
               {
                   if(event.button.x>=243&&event.button.x<=476 && event.button.y>=459&& event.button.y<=528)
                   {
                       ta_perdu=0;
                       menu(acceuil,ecran,positionMenu,&partie_lancee,&menu_lance);
                       initial_tab_piece_jouable(tab_piece_jouable);
                       initial_matrice_grille(matrice);
                   }
                   else if (event.button.x>=539&&event.button.x<=771 && event.button.y>=459&& event.button.y<=528)
                   {
                       ta_perdu=0;
                       if(mode_jeu!=3)
                        {
                        compteur=0;
                        initial_matrice_grille(matrice);
                        initial_tab_piece_jouable(tab_piece_jouable);
                        Proc_grille(grille,ecran,background,positionMenu,matrice,&partie_lancee,mode_jeu,texte,police,score,compteur,couleurNoire,couleurBlanche,positionTexte);
                        Remplir_piece_jouable(ecran,tab_piece_jouable,mode_jeu);
                        }
                        else
                        {
                        compteur=0;compteur2=0;
                        initial_matrice_grille(matrice);
                        initial_matrice_grille2(matrice2);
                        initial_tab_piece_jouable(tab_piece_jouable);
                        initial_tab_piece_jouable(tab_piece_jouable2);
                        Remplir_piece_jouable(ecran,tab_piece_jouable2,mode_jeu);
                        Proc_grille2(grille,grille2,ecran,background,positionMenu,matrice,matrice2,&partie_lancee,mode_jeu,texte,texte2,police,score,score2,compteur,compteur2,couleurNoire,couleurBlanche,positionTexte3,positionTexte2);
                        Remplir_piece_jouable(ecran,tab_piece_jouable,mode_jeu);
                        SDL_Flip(ecran);SDL_FreeSurface(piece);
                        }
                   }
               }

               /*selection de pièces*/
               else if(piece_selected==0 && mode_jeu!=2 && partie_lancee==1 && event.button.x>=0&&event.button.x<=1024 && event.button.y>=500&& event.button.y<=768)
                /* si on selectionne une pièce */
               {
                  if(piece_selected==0 && event.button.x>=0&&event.button.x<=340 && event.button.y>=500&& event.button.y<=768 && jouabilite_piece(matrice,intermat,tab_piece_jouable[1])==0)
                    piece_selected=1;
                  if(piece_selected==0 && event.button.x>=350&&event.button.x<=682 && event.button.y>=500&& event.button.y<=768 && jouabilite_piece(matrice,intermat,tab_piece_jouable[2])==0)
                    piece_selected=2;
                  if(piece_selected==0 && event.button.x>=685&&event.button.x<=1024 && event.button.y>=500&& event.button.y<=768 && jouabilite_piece(matrice,intermat,tab_piece_jouable[3])==0)
                    piece_selected=3;

                  if(piece_selected>0)
                  {
                  piece=la_piece(tab_piece_jouable[piece_selected],mode_jeu);   /* recevoir l'image de la pièce selectionnée*/

                    case SDL_MOUSEMOTION:                              /*la pièce suit le curseur de la souris*/
                         position_piece.x=event.motion.x; position_piece.y=event.motion.y;
                         break;
                  }
               }
            }
        }

            if (nbr_pieces_non_jouables(tab_piece_jouable,matrice,intermat)==3)
            {
                      partie_perdue(acceuil,ecran,positionMenu);
                      ta_perdu=1;
            }


             while(continuer2==1)
             {
              tempsActuel=SDL_GetTicks();
              if(menu_lance!=4 && ta_perdu!=1 && tempsActuel-tempsPrecedent>2000)
              {
              b=1;gp=-1;
              pc_pose(matrice,tab_piece_jouable,&gp,&b,ecran,mode_jeu,&compteur);
              effacer_lc(matrice,tab_piece_jouable,piece_selected,matrice2,tab_piece_jouable2,ecran,mode_jeu,positionMenu,partie_lancee,grille,grille2,background,texte,police,score,&compteur,couleurNoire,couleurBlanche,positionTexte,texte2,score2,&compteur2,positionTexte3,positionTexte2);
              piece_put=0;
              if (b==1)
              {
                partie_perdue(acceuil,ecran,positionMenu);
                ta_perdu=1;
                continuer2=0;compteur=0;
              }
              tempsPrecedent=tempsActuel;
              }
              SDL_PollEvent(&event2);
              switch(event2.type)
           {
           case SDL_KEYDOWN:                   /*savoir si on a appuyé sur une touche*/

           if (event2.key.keysym.sym)
           {
            if (SDLK_ESCAPE)
             {
                menu(acceuil,ecran,positionMenu,&partie_lancee,&menu_lance);
                initial_tab_piece_jouable(tab_piece_jouable);
                initial_matrice_grille(matrice);
                continuer2=0;compteur=0;
                SDL_WaitEvent(&event2);
             }
            }

            case SDL_MOUSEBUTTONUP:
              if (event2.button.button==SDL_BUTTON_LEFT)
              {
                if (menu_lance!= 4 &&ta_perdu!=1 && event2.button.x>=955&&event2.button.x<=1020 && event2.button.y>=30&& event2.button.y<=100)
               {
                   menu_en_jeu(ecran,menupause,positionMiniMenu,&menu_lance);
                   affich_score(texte,police,score,compteur,couleurBleue,couleurBleue,positionTextePause,ecran);
               }

                     if(menu_lance==4 && event2.button.x>=366&&event2.button.x<=410 && event2.button.y>=288&& event2.button.y<=342)
                     {
                         sauvegarder_partieIA(matrice,tab_piece_jouable,compteur);
                     }

                     else if(menu_lance==4 && event2.button.x>=478&&event2.button.x<=532 && event2.button.y>=288&& event2.button.y<=342)
                     {
                         Proc_grille(grille,ecran,background,positionMenu,matrice,&partie_lancee,mode_jeu,texte,police,score,compteur,couleurNoire,couleurBlanche,positionTexte);
                         show_playable(ecran,tab_piece_jouable,piece_selected,mode_jeu);
                         menu_lance=0;
                     }
                     else if (menu_lance==4 && event2.button.x>=600&&event2.button.x<=655 && event2.button.y>=288&& event2.button.y<=342)
                     {
                        initial_matrice_grille(matrice);
                        initial_tab_piece_jouable(tab_piece_jouable);
                        Proc_grille(grille,ecran,background,positionMenu,matrice,&partie_lancee,mode_jeu,texte,police,score,compteur,couleurNoire,couleurBlanche,positionTexte);
                        Remplir_piece_jouable(ecran,tab_piece_jouable,mode_jeu);
                        compteur=0;
                        menu_lance=0;
                     }
                if(menu_lance!=4 && ta_perdu!=1 &&event2.button.x>=950&&event2.button.x<=1020 && event2.button.y>=125&& event2.button.y<=195)
                {
                 menu(acceuil,ecran,positionMenu,&partie_lancee,&menu_lance);
                 initial_tab_piece_jouable(tab_piece_jouable);
                 initial_matrice_grille(matrice);
                 continuer2=0;compteur=0;
                 SDL_WaitEvent(&event2);
                }
              }
              break;
            }
             }


        if(piece_selected>0 && mode_jeu==1) /* SI ON A SELECTIONNE UNE PIECE*/
        {
          SDL_ShowCursor(SDL_DISABLE);
         Proc_grille(grille,ecran,background,positionMenu,matrice,&partie_lancee,mode_jeu,texte,police,score,compteur,couleurNoire,couleurBlanche,positionTexte);              /*affiche la grille*/
         show_playable(ecran,tab_piece_jouable,piece_selected,mode_jeu);                                 /*affiche les pieces jouables*/
         SDL_SetColorKey(piece, SDL_SRCCOLORKEY, SDL_MapRGB(piece->format, 255, 255, 255));
         SDL_BlitSurface(piece,NULL,ecran,&position_piece);
         SDL_Flip(ecran);
                    if(SDL_MOUSEBUTTONUP)
                {
                    if (event.button.button==SDL_BUTTON_LEFT)
                    {
                        if(event.button.x>=250&&event.button.x<=750 && event.button.y>=0&& event.button.y<=500)
                        {
                            curseur.x=event.button.x+15; curseur.y=event.button.y+15;
                            i=la_ligne(curseur,mode_jeu); j=la_colonne(curseur,mode_jeu);

                            b=piece_posable(tab_piece_jouable[piece_selected],matrice,i,j);
                            if (b==0)
                            {
                                SDL_ShowCursor(SDL_ENABLE);
                                compteur=ajout_score_piece_posee(compteur,tab_piece_jouable[piece_selected]);
                                affich_score(texte,police,score,compteur,couleurNoire,couleurBlanche,positionTexte,ecran);
                                tab_piece_jouable[piece_selected]=0; piece_selected=0;
                                Remplir_piece_jouable (ecran,tab_piece_jouable,mode_jeu);
                                piece_put=1;
                            }
                        }

                    }
                    else if (event.button.button==SDL_BUTTON_RIGHT)
                    {
                        piece_selected=0; SDL_ShowCursor(SDL_ENABLE);
                        Proc_grille(grille,ecran,background,positionMenu,matrice,&partie_lancee,mode_jeu,texte,police,score,compteur,couleurNoire,couleurBlanche,positionTexte);
                        show_playable(ecran,tab_piece_jouable,piece_selected,mode_jeu);
                    }
                }

        }
        else if(piece_selected>0 && mode_jeu==3) /* SI ON A SELECTIONNE UNE PIECE*/
        {
          SDL_ShowCursor(SDL_DISABLE);
         Proc_grille2(grille,grille2,ecran,background,positionMenu,matrice,matrice2,&partie_lancee,mode_jeu,texte,texte2,police,score,score2,compteur,compteur2,couleurNoire,couleurBlanche,positionTexte3,positionTexte2);
         show_playable(ecran,tab_piece_jouable,piece_selected,mode_jeu);                                 /*affiche les pieces jouables*/
         SDL_SetColorKey(piece, SDL_SRCCOLORKEY, SDL_MapRGB(piece->format, 255, 255, 255));
         SDL_BlitSurface(piece,NULL,ecran,&position_piece);
         SDL_Flip(ecran);
                    if(SDL_MOUSEBUTTONUP)
                {
                    if (event.button.button==SDL_BUTTON_LEFT)
                    {
                        if(event.button.x>=0&&event.button.x<=450 && event.button.y>=55&& event.button.y<=505)
                        {
                            curseur.x=event.button.x+15; curseur.y=event.button.y+15;
                            i=la_ligne(curseur,mode_jeu); j=la_colonne(curseur,mode_jeu);

                            b=piece_posable(tab_piece_jouable[piece_selected],matrice,i,j);
                            if (b==0)
                            {
                                SDL_ShowCursor(SDL_ENABLE);
                                compteur=ajout_score_piece_posee(compteur,tab_piece_jouable[piece_selected]);
                                tab_piece_jouable[piece_selected]=0; piece_selected=0;
                                Remplir_piece_jouable (ecran,tab_piece_jouable,mode_jeu);
                                piece_put=1;
                            }
                        }

                    }
                    else if (event.button.button==SDL_BUTTON_RIGHT)
                    {
                        piece_selected=0; SDL_ShowCursor(SDL_ENABLE);
                        Proc_grille2(grille,grille2,ecran,background,positionMenu,matrice,matrice2,&partie_lancee,mode_jeu,texte,texte2,police,score,score2,compteur,compteur2,couleurNoire,couleurBlanche,positionTexte3,positionTexte2);
                        show_playable(ecran,tab_piece_jouable,piece_selected,mode_jeu);
                    }
                }

        }

        if(mode_jeu!=2&&piece_put==1)
        {
          effacer_lc(matrice,tab_piece_jouable,piece_selected,matrice2,tab_piece_jouable2,ecran,mode_jeu,positionMenu,partie_lancee,grille,grille2,background,texte,police,score,&compteur,couleurNoire,couleurBlanche,positionTexte,texte2,score2,&compteur2,positionTexte3,positionTexte2);
          piece_put=0;
        }

        tempsZik1=SDL_GetTicks();
        if (tempsZik1-tempsZik2>=180000)
        {
            musique_menu();
            tempsZik2=tempsZik1;
        }
   }

   TTF_CloseFont(police); /* Doit être avant TTF_Quit() */
   TTF_Quit();
   SDL_Quit();
}

