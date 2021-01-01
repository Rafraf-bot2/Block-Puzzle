#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <time.h>

int nbr_aleatoire ()                /* donne un entier aléatoire entre 1 et 27*/
{
    int c;
    c=(rand() % (27 - 1+ 1)) + 1;
    return c;
}

SDL_Surface *la_piece(int c,int mode_jeu)  /*retourne la piece correspondante à un entier entre 1 et 27*/
{

    SDL_Surface *piece=NULL;

    switch (c)
    {
        case 1:
         if(mode_jeu==3) piece=SDL_LoadBMP("1.1145.bmp");
         else piece=SDL_LoadBMP("1.11.bmp");
         break;
        case 2:
            if(mode_jeu==3) piece=SDL_LoadBMP("2.1145.bmp");
            else piece=SDL_LoadBMP("2.11.bmp");
            break;
        case 3:
            if(mode_jeu==3) piece=SDL_LoadBMP("2.1245.bmp");
            else piece=SDL_LoadBMP("2.12.bmp");
            break;
        case 4:
            if(mode_jeu==3) piece=SDL_LoadBMP("3.1145.bmp");
            else piece=SDL_LoadBMP("3.11.bmp");
            break;
        case 5:
            if(mode_jeu==3) piece=SDL_LoadBMP("3.1245.bmp");
            else piece=SDL_LoadBMP("3.12.bmp");
            break;
        case 6:
            if(mode_jeu==3) piece=SDL_LoadBMP("3.2145.bmp");
            else piece=SDL_LoadBMP("3.21.bmp");
            break;
        case 7:
            if(mode_jeu==3) piece=SDL_LoadBMP("3.2245.bmp");
            else piece=SDL_LoadBMP("3.22.bmp");
            break;
        case 8:
            if(mode_jeu==3) piece=SDL_LoadBMP("3.2345.bmp");
            else piece=SDL_LoadBMP("3.23.bmp");
            break;
        case 9:
            if(mode_jeu==3) piece=SDL_LoadBMP("3.2445.bmp");
            else piece=SDL_LoadBMP("3.24.bmp");
            break;
        case 10:
            if(mode_jeu==3) piece=SDL_LoadBMP("4.1145.bmp");
            else piece=SDL_LoadBMP("4.11.bmp");
            break;
        case 11:
            if(mode_jeu==3) piece=SDL_LoadBMP("4.2145.bmp");
            else piece=SDL_LoadBMP("4.21.bmp");
            break;
        case 12:
            if(mode_jeu==3) piece=SDL_LoadBMP("4.2245.bmp");
            else piece=SDL_LoadBMP("4.22.bmp");
            break;
        case 13:
            if(mode_jeu==3) piece=SDL_LoadBMP("4.2345.bmp");
            else piece=SDL_LoadBMP("4.23.bmp");
            break;
        case 14:
            if(mode_jeu==3) piece=SDL_LoadBMP("4.2445.bmp");
            else piece=SDL_LoadBMP("4.24.bmp");
            break;
        case 15:
            if(mode_jeu==3) piece=SDL_LoadBMP("4.3145.bmp");
            else piece=SDL_LoadBMP("4.31.bmp");
            break;
        case 16:
            if(mode_jeu==3) piece=SDL_LoadBMP("4.3245.bmp");
            else piece=SDL_LoadBMP("4.32.bmp");
            break;
        case 17:
            if(mode_jeu==3) piece=SDL_LoadBMP("5.1145.bmp");
            else piece=SDL_LoadBMP("5.11.bmp");
            break;
        case 18:
            if(mode_jeu==3) piece=SDL_LoadBMP("5.1245.bmp");
            else piece=SDL_LoadBMP("5.12.bmp");
            break;
        case 19:
            if(mode_jeu==3) piece=SDL_LoadBMP("5.2145.bmp");
            else piece=SDL_LoadBMP("5.21.bmp");
            break;
        case 20:
            if(mode_jeu==3) piece=SDL_LoadBMP("5.2245.bmp");
            else piece=SDL_LoadBMP("5.22.bmp");
            break;
        case 21:
            if(mode_jeu==3) piece=SDL_LoadBMP("5.2345.bmp");
            else piece=SDL_LoadBMP("5.23.bmp");
            break;
        case 22:
            if(mode_jeu==3) piece=SDL_LoadBMP("5.2445.bmp");
            else piece=SDL_LoadBMP("5.24.bmp");
            break;
        case 23:
            if(mode_jeu==3) piece=SDL_LoadBMP("5.3145.bmp");
            else piece=SDL_LoadBMP("5.31.bmp");
            break;
        case 24:
            if(mode_jeu==3) piece=SDL_LoadBMP("5.3245.bmp");
            else piece=SDL_LoadBMP("5.32.bmp");
            break;
        case 25:
            if(mode_jeu==3) piece=SDL_LoadBMP("5.3345.bmp");
            else piece=SDL_LoadBMP("5.33.bmp");
            break;
        case 26:
            if(mode_jeu==3) piece=SDL_LoadBMP("5.3445.bmp");
            else piece=SDL_LoadBMP("5.34.bmp");
            break;
        case 27:
            if(mode_jeu==3) piece=SDL_LoadBMP("9.1145.bmp");
            else piece=SDL_LoadBMP("9.11.bmp");
            break;

  }
         return (piece);
}

SDL_Surface *le_carre(int c,int mode_jeu)                                    /*retourne l'image du carre coloré correspondant à un entier entre 1 et 11*/
{
    SDL_Surface *carre=NULL;
    switch(c)
    {
        case 0:
          if (mode_jeu==3) carre=SDL_LoadBMP("carreGrille45.bmp");
          else carre=SDL_LoadBMP("carreGrille50.bmp");
            break;
      case 1:
          if (mode_jeu==3) carre=SDL_LoadBMP("orange45.bmp");
          else carre=SDL_LoadBMP("orange.bmp");
        break;

      case 2:
          if (mode_jeu==3) carre=SDL_LoadBMP("roseC45.bmp");
          else carre=SDL_LoadBMP("roseC.bmp");
        break;

      case 3:
          if (mode_jeu==3) carre=SDL_LoadBMP("rougeC45.bmp");
          else carre=SDL_LoadBMP("rougeC.bmp");
        break;

      case 4:
          if (mode_jeu==3) carre=SDL_LoadBMP("bleuC45.bmp");
          else carre=SDL_LoadBMP("bleuC.bmp");
        break;

      case 5:
          if (mode_jeu==3) carre=SDL_LoadBMP("vertC45.bmp");
          else carre=SDL_LoadBMP("vertC.bmp");
        break;

      case 6:
          if (mode_jeu==3) carre=SDL_LoadBMP("vert45.bmp");
          else carre=SDL_LoadBMP("vert.bmp");
        break;

      case 7:
          if (mode_jeu==3) carre=SDL_LoadBMP("jaune45.bmp");
          else carre=SDL_LoadBMP("jaune.bmp");
        break;

      case 8:
          if (mode_jeu==3) carre=SDL_LoadBMP("bleu45.bmp");
          else carre=SDL_LoadBMP("bleu.bmp");
        break;

      case 9:
          if (mode_jeu==3) carre=SDL_LoadBMP("rose45.bmp");
          else carre=SDL_LoadBMP("rose.bmp");
        break;

      case 10:
          if (mode_jeu==3) carre=SDL_LoadBMP("rouge45.bmp");
          else carre=SDL_LoadBMP("rouge.bmp");
        break;

      case 11:
          if (mode_jeu==3) carre=SDL_LoadBMP("violet45.bmp");
          else carre=SDL_LoadBMP("violet.bmp");
        break;
    }
    return(carre);
}
