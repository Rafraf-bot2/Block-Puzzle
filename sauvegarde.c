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
#include "modepc.h"



void sauvegarder_partieP(int matrice[11][11],int vecteur[4],int score)
{
    FILE* fichierM=NULL;
    FILE* fichierV=NULL;
    FILE* fichierS=NULL;
    int i=1,j=1;
    int vecteur2[2];
    vecteur2[1]=score;

    fichierM=fopen("grille.txt","w"); //sauvegarde de la grille
    for (i=1 ;i<11 ;i++)
    {
        for (j=1 ;j<11 ;j++)
        {
            fprintf(fichierM, "%d ", matrice[i][j]);
            fprintf(fichierM,"\n");
        }
    }
     fclose(fichierM);

     fichierV=fopen("pieces.txt","w"); //sauvegarde des 3 pieces proposées
      for (i=1 ;i<4 ;i++)
    {
         fprintf(fichierV, "%d ", vecteur[i]);
    }
     fclose(fichierV);

    fichierS=fopen("score.txt","w"); //sauvegarde du score
          fprintf(fichierS, "%d", vecteur2[1]);
          fclose(fichierS);

}


void charger_partieP(int matrice[11][11],int vecteur[4],int *score)
{
 FILE* fichierM=NULL;
    FILE* fichierV=NULL;
    FILE* fichierS=NULL;
    int i=1;
    int vecteur2[2];

     fichierV=fopen("pieces.txt","r"); //chargement des 3 pieces proposées
      fscanf(fichierV, "%d %d %d", &vecteur[1], &vecteur[2], &vecteur[3]);
     fclose(fichierV);

    fichierS=fopen("score.txt","r"); //chargement  du score
          fscanf(fichierS, "%d", &vecteur2[1]); *score=vecteur2[1];
          fclose(fichierS);

      fichierM=fopen("grille.txt","r"); //chargement de la grille
     for (i=1 ;i<11 ;i++)
     {
         fscanf (fichierM, "%d %d %d %d %d %d %d %d %d %d\n",&matrice[i][1],&matrice[i][2],&matrice[i][3],&matrice[i][4],&matrice[i][5],&matrice[i][6],&matrice[i][7],&matrice[i][8],&matrice[i][9],&matrice[i][10]);

     }
     fclose(fichierM);

}

void sauvegarder_partieIA(int matrice[11][11],int vecteur[4],int score)
{
    FILE* fichierM=NULL;
    FILE* fichierV=NULL;
    FILE* fichierS=NULL;
    int i=1,j=1;
    int vecteur2[2];
    vecteur2[1]=score;

    fichierM=fopen("grilleIA.txt","w"); //sauvegarde de la grille
    for (i=1 ;i<11 ;i++)
    {
        for (j=1 ;j<11 ;j++)
        {
            fprintf(fichierM, "%d ", matrice[i][j]);
            fprintf(fichierM,"\n");
        }
    }
     fclose(fichierM);

     fichierV=fopen("piecesIA.txt","w"); //sauvegarde des 3 pieces proposées
      for (i=1 ;i<4 ;i++)
    {
         fprintf(fichierV, "%d ", vecteur[i]);
    }
     fclose(fichierV);

    fichierS=fopen("scoreIA.txt","w"); //sauvegarde du score
          fprintf(fichierS, "%d", vecteur2[1]);
          fclose(fichierS);

}


void charger_partieIA(int matrice[11][11],int vecteur[4],int *score)
{
    FILE* fichierM=NULL;
    FILE* fichierV=NULL;
    FILE* fichierS=NULL;
    int i=1;
    int vecteur2[2];

     fichierV=fopen("piecesIA.txt","r"); //chargement des 3 pieces proposées
      fscanf(fichierV, "%d %d %d", &vecteur[1], &vecteur[2], &vecteur[3]);
     fclose(fichierV);

    fichierS=fopen("scoreIA.txt","r"); //chargement  du score
          fscanf(fichierS, "%d", &vecteur2[1]); *score=vecteur2[1];
          fclose(fichierS);

      fichierM=fopen("grilleIA.txt","r");
     for (i=1 ;i<11 ;i++)
     {
         fscanf (fichierM, "%d %d %d %d %d %d %d %d %d %d\n",&matrice[i][1],&matrice[i][2],&matrice[i][3],&matrice[i][4],&matrice[i][5],&matrice[i][6],&matrice[i][7],&matrice[i][8],&matrice[i][9],&matrice[i][10]);

     }
     fclose(fichierM);

}


void sauvegarder_partieIVP(int matriceP[11][11],int matriceI[11][11],int vecteurP[4],int vecteurI[4],int scoreP,int scoreI)
{
    FILE* fichierMP=NULL;
    FILE* fichierVP=NULL;
    FILE* fichierSP=NULL;
    FILE* fichierMI=NULL;
    FILE* fichierVI=NULL;
    FILE* fichierSI=NULL;

    int i=1,j=1;
    int vecteurP2[2];
    vecteurP2[1]=scoreP;
    int vecteurI2[2];
    vecteurI2[1]=scoreI;


    fichierMP=fopen("grilleP.txt","w"); //sauvegarde de la grille du joueur
    for (i=1 ;i<11 ;i++)
    {
        for (j=1 ;j<11 ;j++)
        {
            fprintf(fichierMP, "%d ", matriceP[i][j]);
            fprintf(fichierMP,"\n");
        }
    }
     fclose(fichierMP);

      fichierMI=fopen("grilleI.txt","w"); //sauvegarde de la grille de l'IA
    for (i=1 ;i<11 ;i++)
    {
        for (j=1 ;j<11 ;j++)
        {
            fprintf(fichierMI, "%d ", matriceI[i][j]);
            fprintf(fichierMI,"\n");
        }
    }
     fclose(fichierMI);

     fichierVP=fopen("piecesP.txt","w"); //sauvegarde des 3 pieces proposées au joueur
      for (i=1 ;i<4 ;i++)
    {
         fprintf(fichierVP, "%d ", vecteurP[i]);
    }
     fclose(fichierVP);

     fichierVI=fopen("piecesI.txt","w"); //sauvegarde des 3 pieces proposées à l'IA
      for (i=1 ;i<4 ;i++)
    {
         fprintf(fichierVI, "%d ", vecteurI[i]);
    }
     fclose(fichierVI);

    fichierSP=fopen("scoreP.txt","w"); //sauvegarde du score du joueur
          fprintf(fichierSP, "%d", vecteurP2[1]);
          fclose(fichierSP);

    fichierSI=fopen("scoreI.txt","w"); //sauvegarde du score de l'IA
          fprintf(fichierSI, "%d", vecteurI2[1]);
          fclose(fichierSI);


}




void charger_partieIVP(int matriceP[11][11],int matriceI[11][11],int vecteurP[4],int vecteurI[4],int *scoreP,int *scoreI)
{
    FILE* fichierMP=NULL;
    FILE* fichierVP=NULL;
    FILE* fichierSP=NULL;
    FILE* fichierMI=NULL;
    FILE* fichierVI=NULL;
    FILE* fichierSI=NULL;
    int i=1;
    int vecteurP2[2];
    int vecteurI2[2];

     fichierVP=fopen("piecesP.txt","r"); //chargement des 3 pieces proposées au joueur
      fscanf(fichierVP, "%d %d %d", &vecteurP[1], &vecteurP[2], &vecteurP[3]);
     fclose(fichierVP);

     fichierVI=fopen("piecesI.txt","r"); //chargement des 3 pieces proposées à l'IA
      fscanf(fichierVI, "%d %d %d", &vecteurI[1], &vecteurI[2], &vecteurI[3]);
     fclose(fichierVI);

    fichierSP=fopen("scoreP.txt","r"); //chargement  du score du joueur
          fscanf(fichierSP, "%d", &vecteurP2[1]); *scoreP=vecteurP2[1];
          fclose(fichierSP);

    fichierSI=fopen("scoreI.txt","r"); //chargement  du score de l'IA
          fscanf(fichierSI, "%d", &vecteurI2[1]); *scoreI=vecteurI2[1];
          fclose(fichierSI);


      fichierMP=fopen("grilleP.txt","r");
     for (i=1 ;i<11 ;i++)
     {
         fscanf (fichierMP, "%d %d %d %d %d %d %d %d %d %d\n",&matriceP[i][1],&matriceP[i][2],&matriceP[i][3],&matriceP[i][4],&matriceP[i][5],&matriceP[i][6],&matriceP[i][7],&matriceP[i][8],&matriceP[i][9],&matriceP[i][10]);

     }
     fclose(fichierMP);

     fichierMI=fopen("grilleI.txt","r");
     for (i=1 ;i<11 ;i++)
     {
         fscanf (fichierMI, "%d %d %d %d %d %d %d %d %d %d\n",&matriceI[i][1],&matriceI[i][2],&matriceI[i][3],&matriceI[i][4],&matriceI[i][5],&matriceI[i][6],&matriceI[i][7],&matriceI[i][8],&matriceI[i][9],&matriceI[i][10]);

     }
     fclose(fichierMI);

}
