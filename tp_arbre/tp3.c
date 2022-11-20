#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BTree.c"
#include "BTree.h"




int main(){


BTree racine =makeLeaf(5);

insertLeft(racine,10);
insertRight(racine,90);

insertLeft(racine->left,13);
insertRight(racine->left,19);


insertRight(racine->right,70);
insertLeft(racine->right,80);
// display_arbre_prefixe(racine);

/*arbre 2 identique a racine */


BTree racine2 =makeLeaf(5);

insertLeft(racine2,10);
insertRight(racine2,90);

insertLeft(racine2->left,13);
insertRight(racine2->left,19);


insertRight(racine2->right,70);
insertLeft(racine2->right,80);


/*sous arbre qui existe*/

BTree subtree =makeLeaf(90);
insertLeft(subtree,80);
insertRight(subtree,70);

//    display_arbre_prefixe(sous_arbre); 


// verifier identique rec
// printf(identique_rec(racine,racine2)?"identique \n":"non identique\n");

// verifier identique iter
printf(identique_iter(racine,racine2)?"identique \n":"non identique\n");

//verifier sous arbre rec

printf(sub_tree_iter(racine,subtree)?"est un sous arbre \n":"n'est pas un sous arbre");




}