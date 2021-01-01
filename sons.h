#include <SDL/SDL_ttf.h>

void musique_menu();
void affich_score(SDL_Surface *texte,TTF_Font *police, char score[20],int compteur,SDL_Color couleurNoire, SDL_Color couleurBlanche,SDL_Rect positionTexte,SDL_Surface *ecran);
int ajout_score_piece_posee(int compteur,int val);
int ajout_score_explosion(int som,int compteur);
