#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "BTree.h"
//d�claration de la Pile
typedef struct EPile* Pile;
typedef struct EPile { BTree Val; Pile Suiv;} CelluleP;

//d�claration de la File
typedef struct Element* EFile;
typedef struct Element { int  Val; EFile Suiv;} CelluleF;
typedef struct {EFile Tete,Queue;} File;

//primitives des Piles
//procedure Initpile
void Initpile(Pile *P)
{*P=NULL;}

//procedure Empiler
void Empiler(Pile *P, BTree x)
{Pile V;
 V=malloc(sizeof(CelluleP));
 V->Val=x;
 V->Suiv=*P;
 *P=V;
}

//procedure Depiler
void Depiler(Pile *P, BTree *x)
{Pile V;
 *x=(*P)->Val;
 V=*P;
 *P=(*P)->Suiv;
 free(V);
}

//Fonction Pilevide
int Pilevide(Pile P)
{if (P==NULL) return 1;
 else return 0;
}

//Fonction SommetPile
BTree SommetPile(Pile P,BTree *temp)
{return P->Val;}


// //primitives des Files
// //procedure Initfile
// void Initfile(File *F)
// {(*F).Tete=NULL; (*F).Queue=NULL;}

// //procedure Enfiler
// void Enfiler(File *F, int x)
// {EFile V;
//  V=malloc(sizeof(CelluleF));
//  V->Val=x;
//  V->Suiv=NULL;
//  if ((*F).Tete==NULL) (*F).Tete=V; //la file est vide
//  else (*F).Queue->Suiv=V;
//  (*F).Queue=V;
// }

// //procedure Defiler
// void Defiler(File *F, int *x)
// {EFile V;
//  V=(*F).Tete;
//  *x=V->Val; //ou  *x=(*F).Tete->Val;

//  if ((*F).Tete==(*F).Queue) {(*F).Tete=NULL; (*F).Queue=NULL;}
//  else (*F).Tete=(*F).Tete->Suiv; // ou  (*F).Tete=V->Suiv;
//  free(V);
// }

// //Fonction Filevide
// int Filevide(File F)
// {if (F.Tete==NULL) return 1;
//  else return 0;
// }

// //Fonction Tetefile
// int Tetefile(File F)
// {return F.Tete->Val;}
