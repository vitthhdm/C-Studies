#define LINKED_LIST_H_API
#include "linkedList.h"


/*
 * @brief: pInsereNoInicio é uma função que insere um no' no inicio da 
 * lista ligada.
 * 
 * @Parameters: pNo pHead; é uma variável do tipo ponteiro da estrutura No
 * que referencia ao início da lista ligada
 * @Parameters: int iNewIndex; variável do tipo inteiro para preencher o novo nó
 * inserido
 * 
 * @PARAMETERS_RETURN: pNo pBackupHead; retorna o início da lista inalterado para
 * ser possível realizar acessos futuros.
*/
pNo pInsereNoInicio(pNo pHead, int iNewIndex){
    pNo pNewNode = malloc(sizeof(No));
    pNewNode->iIndex = iNewIndex;
    pNewNode->pNext = pHead;       
    return pNewNode;
}

/*
 * @brief: pInsereNoFinal é uma função que insere um no' no final da 
 * lista ligada.
 * 
 * @Parameters: pNo pHead; é uma variável do tipo ponteiro da estrutura No
 * que referencia ao início da lista ligada
 * @Parameters: int iNewIndex; variável do tipo inteiro para preencher o novo nó
 * inserido
 * 
 * @PARAMETERS_RETURN: pNo pBackupHead; retorna o início da lista inalterado para
 * ser possível realizar acessos futuros.
*/
pNo pInsereNoFinal(pNo pHead, int iNewIndex){
    pNo pNewNode = malloc(sizeof(No));
    if (pHead == NULL){
        pNewNode->iIndex = iNewIndex;
        pNewNode->pNext = pHead;
    }
    else{
        pNo pHeadAux = pHead;
        while(pHeadAux->pNext != NULL){
            pHeadAux = pHeadAux->pNext;
        }
        pNewNode->iIndex = iNewIndex;
        pNewNode->pNext = NULL;
        pHeadAux->pNext = pNewNode;
    }
    return pHead;
}

/*
 * @brief: pInsereNoFinal é uma função que insere um no' de forma ordenada
 * 
 * @Parameters: pNo pHead; é uma variável do tipo ponteiro da estrutura No
 * que referencia ao início da lista ligada
 * @Parameters: int iNewIndex; variável do tipo inteiro para preencher o novo nó
 * inserido
 * 
 * @PARAMETERS_RETURN: pNo pBackupHead; retorna o início da lista inalterado para
 * ser possível realizar acessos futuros.
*/
pNo pInsereOrdenado(pNo pHead, int iNovoiIndex){
    pNo pNewNode = malloc(sizeof(No));
    pNo pBackupHead = pHead;
    int iFlagNULL = 1;
    if(!pHead){
        pNewNode->pNext = pHead;
        pNewNode->iIndex = iNovoiIndex;
        return pNewNode;
    }
    while(pHead->pNext != NULL){
        if(pHead->pNext->iIndex < iNovoiIndex){
            pHead = pHead->pNext;
        }
        else{
            pNewNode->pNext = pHead->pNext;
            pHead->pNext = pNewNode;
            pNewNode->iIndex = iNovoiIndex;
            return pBackupHead;
        }
    }
    if (iFlagNULL){
        pNewNode->pNext = pHead;
        pNewNode->iIndex = iNovoiIndex;
        return pNewNode;
    }
    return pBackupHead;
}

/*
 * @brief: vPrintList é uma função que imprime a lista ligada
 * 
 * @Parameters: pNo pHead; é uma variável do tipo ponteiro da estrutura No
 * que referencia ao início da lista ligada
 * 
*/
void vPrintList(pNo pHead){
    if(!pHead)
        printf("LISTA VAZIA!\n");
    while (pHead != NULL){
        printf("Número encadeado: %d\n", pHead->iIndex);
        pHead = pHead->pNext;
    }
}

/*
 * @brief: vLiberaLista é uma função que libera uma lista ligada, liberando
 * todos os nós.
 * 
 * @Parameters: pNo pHead; é uma variável do tipo ponteiro da estrutura No
 * que referencia ao início da lista ligada
 * 
*/
void vLiberaLista(pNo pHead){
    pNo pHead = pHead;
    pNo pNext;
    while((pHead != NULL)){
        pNext = pHead->pNext;
        free(pHead);
        pHead = pNext;
    }
}

/*
 * @brief: vRemoveNo libera um nó da lista ligada especificada no index do nó
 * 
 * @Parameters: pNo pHead; é uma variável do tipo ponteiro da estrutura No
 * que referencia ao início da lista ligada
 * @Parameters: int iIndex é uma variável do tipo inteiro que representa o
 * nó que será retirado.
 * 
*/
void vRemoveNo(pNo pHead, int iIndex){
    if (!pHead){
        printf("Lista vazia!\n");
        return;
    }
    
    while(pHead->pNext != NULL){
        if(pHead->pNext->iIndex == iIndex){
            pNo pHeadAux = pHead->pNext;
            pHead->pNext = pHeadAux->pNext;
            free(pHeadAux);
            printf("No' removido com sucesso!\n");
            return;
        }
        pHead = pHead->pNext;
    }
    printf("Numero nao encontrado!\n");
    return;
}
