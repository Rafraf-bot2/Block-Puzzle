#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <fmod/fmod.h>
#include <SDL/SDL_ttf.h>
/*action qui s'occupe de la musique au menu d'acceuil*/
void musique_menu()
{
    FMOD_SYSTEM *system;
    FMOD_SOUND *musique;
    FMOD_RESULT resultat;
    FMOD_System_Create(&system);
    FMOD_System_Init(system, 1, FMOD_INIT_NORMAL, NULL);
    /* On ouvre la musique */
    resultat = FMOD_System_CreateSound(system, "Clairo.mp3", FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &musique);
    /* On active la répétition de la musique à l'infini */
    FMOD_Sound_SetLoopCount(musique, -1);
    /* On joue la musique */
    FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, musique, 0, NULL);
}

void affich_score(SDL_Surface *texte,TTF_Font *police, char score[20],int compteur,SDL_Color couleurNoire, SDL_Color couleurBlanche,SDL_Rect positionTexte,SDL_Surface *ecran)
{

    sprintf(score, "score : %d", compteur);
    texte = TTF_RenderText_Shaded(police, score, couleurNoire, couleurBlanche);
    SDL_SetColorKey(texte, SDL_SRCCOLORKEY, SDL_MapRGB(texte->format, 0, 0, 255));
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_Flip(ecran);
    SDL_FreeSurface(texte);
}
int ajout_score_piece_posee(int compteur,int val)
{
    if (val==1 )compteur=compteur+10;
    else if (val>=2 && val<=3) compteur=compteur+20;
    else if (val>=4 && val<=9) compteur=compteur+30;
    else if (val>=10 && val<=16)compteur=compteur+40;
    else if (val>=17 && val<=26)compteur=compteur+50;
    else compteur=compteur+90;

    return compteur;
}

int ajout_score_explosion(int som,int compteur)
{
  if(som!=0)
  {
    if (som==1)      compteur=compteur+100;
    else if (som==2) compteur=compteur+300;
    else if (som==3) compteur=compteur+600;
    else if (som==4) compteur=compteur+1000;
    else compteur=compteur+1500;
  }
    return compteur;
}
