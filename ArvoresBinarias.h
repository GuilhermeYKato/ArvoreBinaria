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
        printf("Elemento inserido: %d\n",(*node)->element.key);
        return true;
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

void preOrder(PtrTreeTree *node){
//    printf("P");
    if((*node) != NULL){
        printf("%d ", (*node)->element.key);
        preOrder(&(*node)->left);
        preOrder(&(*node)->right);
    }
}

void posOrder(PtrTreeTree *node){
    if((*node) != NULL){
        posOrder(&(*node)->left);
        posOrder(&(*node)->right);
        printf("%d ", (*node)->element.key);
    }
}

void inOrderCresc(PtrTreeTree *node){
    if((*node) != NULL){
        inOrderCresc(&(*node)->left);
        printf("%d ", (*node)->element.key);
        inOrderCresc(&(*node)->right);
    }

}

void inOrderDecresc(PtrTreeTree *node){
    if((*node) != NULL){
        inOrderDecresc(&(*node)->right);
        printf("%d ", (*node)->element.key);
        inOrderDecresc(&(*node)->left);
    }
}

bool findItemRecur(PtrTreeTree *node, int key){
    if((*node)== NULL){
        return false;
    }
    if((*node)->element.key == key){
        return true;
    }
    if(key < (*node)->element.key){
        findItemRecur(&(*node)->left,key);
    } else {
        findItemRecur(&(*node)->right,key);
    }
}

PtrTreeTree getMinAux (PtrTreeTree *node){//usado na remoção
    PtrTreeTree Aux;
    if((*node)->left == NULL){
        Aux = (*node);
        (*node)=(*node)->right;
        return Aux;
    } else {
        return getMinAux(&(*node)->left);
    }
//    Aux = (*node);
//    while(Aux->left != NULL){
//        Aux = Aux->left;
//    }
//    (*node) = (*node)->right;
//    return (*node);
}
PtrTreeTree getMaxAux (PtrTreeTree *node) { //usado na remoção

    PtrTreeTree Aux;
    if((*node)->right == NULL) {
        Aux = (*node);
        (*node) = (*node)->left;
        return Aux;
    } else {
        return getMaxAux(&((*node)->right));
    }
    //    Aux = (*node);
//    while(Aux->right != NULL){
//        Aux = Aux->right;
//    }
//    (*node) = (*node)->left;
//    return Aux;
}

bool removeItem(PtrTreeTree *node, int key){
    if((*node) == NULL){
        return false;
    }
    PtrTreeTree Aux = NULL;
    if((*node)->element.key == key){
        if((*node)->left == NULL && (*node)->right != NULL){
            (*node) = (*node)->right;

        } else if((*node)->left != NULL && (*node)->right == NULL){//arvore direita NULA
            (*node) = (*node)->left;

        } else if((*node)->left == NULL && (*node)->right == NULL){//arvore esqueda NULA
            (*node) = NULL;

        } else if((*node)->left != NULL && (*node)->right != NULL){//((*node)->left != NULL && (*node)->right != NULL)
            Aux = getMinAux(&((*node)->right));
//            Aux = getMaxAux(&((*node)->left));
            (*node)->element = Aux->element;
            printf("Elemento Removido com Sucesso: %d\n",key);
        }
        free(Aux);

        return true;
    }
    if((*node)->element.key > key){
        return (removeItem(&(*node)->left, key));
    } else {
        return (removeItem(&(*node)->right, key));
    }
}

PtrTreeTree maximum(PtrTreeTree *node){
    if((*node)->right == NULL){
        return (*node);
    }
    return maximum(&(*node)->right);

}

int maximumIterative(PtrTreeTree *node){
    PtrTreeTree TreeTree = (*node);
    while(TreeTree->right != NULL){
        TreeTree = TreeTree->right;
    }
    return TreeTree->element.key;
}

PtrTreeTree minimum(PtrTreeTree *node){
    if((*node)->left == NULL){
        return (*node);
    }
    return maximum(&(*node)->left);
}

int minimumIterative(PtrTreeTree *node){
    PtrTreeTree TreeTree = (*node);
    while(TreeTree->left != NULL){
        TreeTree = TreeTree->left;
    }
    return TreeTree->element.key;
}
//getminAux((*node).right)


#endif //ARVORESBINARIAS_ARVORESBINARIAS_H
