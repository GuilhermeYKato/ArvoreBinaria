#ifndef ARVORESBINARIAS_ARVORESBINARIAS_H
#define ARVORESBINARIAS_ARVORESBINARIAS_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct{
    int key;
} Object;

typedef struct NodeTree *PtrTreeTree;

typedef struct NodeTree {
    Object element;
    PtrTreeTree left;
    PtrTreeTree right;
    PtrTreeTree father; //OPCIONAL
} NodeTree;

void initTree(PtrTreeTree *node){
    (*node)= NULL;
}

bool isEmpty(PtrTreeTree *node){
    if((*node)== NULL){
        return true;
    } else {
        return false;
    }
}

bool insertItem(PtrTreeTree *node, Object x){
    if(*node == NULL){
        (*node) = malloc(sizeof(NodeTree));
        (*node)->right = (*node)->left = NULL;
        (*node)->element = x;
    }
    if((*node)->element.key == x.key){
        return false;
    }
    if((*node)->element.key > x.key){
        return (insertItem(&(*node)->left,x));
    } else {
        return (insertItem(&(*node)->right, x));
    }
    
}

int sizeTree(PtrTreeTree *node);

int maxDepth(PtrTreeTree *node);

void destroyTree(PtrTreeTree *node);

void preOrder(PtrTreeTree *node);

void posOrder(PtrTreeTree *node);

void inOrder(PtrTreeTree *node);


bool findItem(PtrTreeTree *node, int key, Object *ret);

bool removeItem(PtrTreeTree *node, int key);

PtrTreeTree maximum(PtrTreeTree *node);

PtrTreeTree maximumIterative(PtrTreeTree *node);

PtrTreeTree minimum(PtrTreeTree *node);

PtrTreeTree minimumIterative(PtrTreeTree *node);

PtrTreeTree getMinAux (PtrTreeTree *node); //usado na remoção

PtrTreeTree getMaxAux (PtrTreeTree *node); //usado na remoção


#endif //ARVORESBINARIAS_ARVORESBINARIAS_H
