#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "BTree.h"
#include "LibPileFile.c"
 

void errorB(char *s){
	fprintf(stderr, "%s", s);
	exit(EXIT_FAILURE);
}

/*****************************************************************************/
/**************************** fonctions de base ******************************/
/*****************************************************************************/

BTree makeEmptyBTree(void){
	return (BTree)NULL;	
}

BTree makeNode(Element e, BTree l,  BTree r){
	BTree new;
	if ((new=(BTree)malloc(sizeof(Node)))==NULL) errorB("Allocation rat�e!");
	new->elem=e;
	new->left=l;
	new->right=r;
	return new;
}

BTree makeLeaf(Element e){
	return makeNode(e,makeEmptyBTree(),makeEmptyBTree());
}


int isEmptyBTree(BTree bt){
	return (bt==NULL);
}

Element root(BTree bt){
	if(isEmptyBTree(bt)) errorB("Pas de noeud � la racine d'un arbre vide!!!");
	return bt->elem;
}


BTree leftChild(BTree bt){
	if(isEmptyBTree(bt)) errorB("Pas de fils gauche dans un arbre vide!!!");
	return bt->left;
}

BTree rightChild(BTree bt){
	if(isEmptyBTree(bt)) errorB("Pas de fils droit dans un arbre vide!!!");
	return bt->right;
}

int isLeaf(BTree bt){
	return !isEmptyBTree(bt) && isEmptyBTree(leftChild(bt)) && isEmptyBTree(rightChild(bt));
}

void freeNode(Node *c){
	free(c);
}

/*****************************************************************************/
/*************************** fonctions bas niveau ****************************/
/*****************************************************************************/

void insertRight(Node *n, Element e){
	if(!isEmptyBTree(n) && isEmptyBTree(rightChild(n)))
		n->right=makeLeaf(e);
	else errorB("insertRight impossible!");
}

void insertLeft(Node *n, Element e){
	if(!isEmptyBTree(n) && isEmptyBTree(leftChild(n)))
		n->left=makeLeaf(e);
	else errorB("insertLeft impossible!");
}

Element deleteRight(Node *n){
	if(isEmptyBTree(n) || !isLeaf(rightChild(n)))
		errorB("deleteRight imossible!");
		
	Element res=root(n->right);
	n->right=makeEmptyBTree();
	return res;
}

Element deleteLeft(Node *n){
	if(isEmptyBTree(n)  || !isLeaf(leftChild(n)))
		errorB("deleteLeft imossible!");
		
	Element res=root(n->left);
	n->left=makeEmptyBTree();
	return res;
}

void insertRightmostNode(BTree *bt, Element e){
	if(isEmptyBTree(*bt))
		*bt=makeLeaf(e);
	else{
		BTree tmp=*bt;
		while(!isEmptyBTree(rightChild(tmp)))
			tmp=rightChild(tmp);
		insertRight(tmp,e);
	}
}

Element deleteLeftmostNode(BTree *bt){
	Element res;
	if(isEmptyBTree(*bt))
		errorB("deleteLeftmostNode imossible!");
	if(isEmptyBTree(leftChild(*bt))){
		res=root(*bt);
		*bt=rightChild(*bt);
	}
	else{
		BTree tmp=*bt;
		while(!isEmptyBTree(leftChild(leftChild(tmp))))
			tmp=leftChild(tmp);
		res=root(leftChild(tmp));
		tmp->left=(tmp->left)->right;
	}
	return res;
}

void display_arbre_prefixe(BTree noeud){

	if(!isEmptyBTree(noeud)){
	printf(" %d  ",noeud->elem);
	display_arbre_prefixe(noeud->left);
	display_arbre_prefixe(noeud->right);

	

	}

}
//identique rec

bool identique_rec(BTree noeud1 ,BTree noeud2){

if (isEmptyBTree(noeud1) && isEmptyBTree(noeud2)) return true;

if (!isEmptyBTree(noeud1) && !isEmptyBTree(noeud2)) 

   return ((noeud1->elem == noeud2->elem) && (identique_rec(noeud1->left,noeud2->left)) && 
          (identique_rec(noeud1->right,noeud2->right)));

return false;
}


// sousrabre rec

bool sub_tree_rec(BTree arbre , BTree sous_arbre){

if (isEmptyBTree(sous_arbre)) return true;

if(isEmptyBTree((arbre))) return false;

if(identique_rec(arbre,sous_arbre))return true;

return (sub_tree_rec(arbre->left,sous_arbre) || sub_tree_rec(arbre->right,sous_arbre));

}
// identique iterative
bool identique_iter(BTree arbre1 , BTree arbre2){

    Pile p1 ,p2;
    Initpile(&p1);
    Initpile(&p2);
 
    BTree temp1,temp2;

    Empiler(&p1,arbre1);
    Empiler(&p2,arbre2);

     

    
    while ( ! Pilevide(p1) && ! Pilevide(p2))
    {

        Depiler(&p1,&temp1);
        Depiler(&p2,&temp2);

        if (temp1 == NULL &&  temp2 == NULL)

            continue;
        if ((temp1 == NULL && temp2 != NULL) ||  (temp1 != NULL && temp2 == NULL))

            return false;

        if (temp1->elem != temp2->elem)

            return false;
 

        Empiler(&p1,temp1->right);
        Empiler(&p1,temp1->left);

        Empiler(&p2,temp2->right);
        Empiler(&p2,temp2->left);

    }

   
    if (  Pilevide(p1) &&  Pilevide(p2)) return true;

    else  return false;

}

// sousrabre rec
bool sub_tree_iter (BTree arbre,BTree sousarbre )
{

    // first we find the root of s in t

    // by traversing in pre order fashion

    Pile P;

    BTree temp;

    Empiler(&P,arbre);

    while (! Pilevide(P)) {

        Depiler(&P,&temp);
        
        if (temp->elem == sousarbre->elem) {

            if (identique_iter(sousarbre, temp))

                return true;

        }

        if (! isEmptyBTree (temp->right))

			Empiler(&P,temp->right);

        if (! isEmptyBTree (temp->left))

            Empiler(&P,temp->left);

    }

    return false;
}