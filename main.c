#include "ArvoresBinarias.h"


int main(int argc, char* argv[]) {
    PtrTreeTree TreeTree;
    Object DINDIN;
    initTree(&TreeTree);
    PtrTreeTree TreeTree2;
    Object DINDIN2;
    initTree(&TreeTree2);


    DINDIN.key = 46;
    insertItem(&TreeTree, DINDIN);
    DINDIN.key = 30;
    insertItem(&TreeTree, DINDIN);
    DINDIN.key = 93;
    insertItem(&TreeTree, DINDIN);
    DINDIN.key = 43;
    insertItem(&TreeTree, DINDIN);
    DINDIN.key = 11;
    insertItem(&TreeTree, DINDIN);
    DINDIN.key = 3;
    insertItem(&TreeTree, DINDIN);
    DINDIN.key = 80;
    insertItem(&TreeTree, DINDIN);
    DINDIN.key = 37;
    insertItem(&TreeTree, DINDIN);
    DINDIN.key = 51;
    insertItem(&TreeTree, DINDIN);


//              ARVORE
//                 46
//           30          93
//      11        43 80
//   3        37






    printf("PreOrder: ");
    preOrder(&TreeTree);
    printf("\n");

    printf("PosOrder: ");
    posOrder(&TreeTree);
    printf("\n");

    printf("InOrder Crescent: ");
    inOrderCresc(&TreeTree);
    printf("\n");

    printf("InOrder Decrescent: ");
    inOrderDecresc(&TreeTree);
    printf("\n");

    if(findItemRecur(&TreeTree, 78) == true){
        printf("Achou Elemento\n");
    } else {
        printf("Não achou Elemento\n");
    }
    int x;
    x = maximumIterative(&TreeTree);
    printf("Maximum: %i", x);
    printf("\n");

    int y;
    y = minimumIterative(&TreeTree);
    printf("Minimum: %i", y);
    printf("\n");
    
    return 0;
}
