int la_colonne(SDL_Rect curseur,int mode_jeu);
int la_ligne(SDL_Rect curseur,int mode_jeu);
int piece_posable(int num_piece,int matrice[11][11],int i,int j);
SDL_Rect pos_mat(int i,int j);
void verif_explosion(int matrice[11][11],int tab_destru_l[6],int tab_destru_c[6]);
void effacer_lc(int matrice[11][11],int tab_piece_jouable[4],int piece_selected,int matrice2[11][11],int tab_piece_jouable2[4],SDL_Surface *ecran,int mode_jeu,SDL_Rect positionMenu,int partie_lancee,SDL_Surface *grille,SDL_Surface *grille2,SDL_Surface *background,SDL_Surface *texte,TTF_Font *police, char score[20],int *compteur,SDL_Color couleurNoire, SDL_Color couleurBlanche,SDL_Rect positionTexte,SDL_Surface *texte2,char score2[20],int *compteur2,SDL_Rect positionTexte3,SDL_Rect positionTexte2);
int jouabilite_piece(int matrice[11][11],int intermat[11][11],int val);
int nbr_pieces_non_jouables(int tab_piece_jouable[4],int matrice[11][11],int intermat[11][11]);
