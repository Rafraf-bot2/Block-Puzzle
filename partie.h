#include<SDL/SDL_ttf.h>

void menu(SDL_Surface *acceuil,SDL_Surface *ecran,SDL_Rect positionMenu,int *partie_lancee,int *menu_lance);
void menu2 (SDL_Surface *acceuil,SDL_Surface *ecran,SDL_Rect positionMenu,int *menu_lance);
void menu3 (SDL_Surface *acceuil,SDL_Surface *ecran,SDL_Rect positionMenu,int *menu_lance);
void menu_en_jeu(SDL_Surface *ecran,SDL_Surface *menupause,SDL_Rect positionMiniMenu,int *menu_lance);
void Proc_grille(SDL_Surface *grille,SDL_Surface *ecran, SDL_Surface *background,SDL_Rect positionMenu,int matrice[11][11] ,int *partie_lancee,int mode_jeu,SDL_Surface *texte,TTF_Font *police, char score[20],int compteur,SDL_Color couleurNoire, SDL_Color couleurBlanche,SDL_Rect positionTexte);
void Proc_grille2(SDL_Surface *grille,SDL_Surface *grille2,SDL_Surface *ecran, SDL_Surface *background,SDL_Rect positionMenu,int matrice[11][11],int matrice2[11][11] ,int *partie_lancee,int mode_jeu,SDL_Surface *texte,SDL_Surface *texte2,TTF_Font *police, char score[20],char score2[20],int compteur,int compteur2,SDL_Color couleurNoire, SDL_Color couleurBlanche,SDL_Rect positionTexte3,SDL_Rect positionTexte2);
void Remplir_piece_jouable (SDL_Surface *ecran,int tab_piece_jouable[4],int mode_jeu);
void show_playable(SDL_Surface *ecran,int tab_piece_jouable[4],int piece_selected,int mode_jeu);
void partie_perdue(SDL_Surface *acceuil,SDL_Surface *ecran,SDL_Rect positionMenu);

