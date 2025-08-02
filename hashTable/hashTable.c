#define HASHTABLE_H_API
#include <stdio.h>
#include <stdlib.h>
#include "hashTable.h"
#include <string.h>

float fCheckAvailability = 0;

pTableItem pGeraHashTable(int iSize){
    pTableItem pNewTable = malloc(iSize*sizeof(TableItem));
    for (int i = 0; i < iSize; i++){
        pNewTable[i].cName[0] = '\0'; // Inicializa o nome como vazio
        pNewTable[i].iAge = 0; // Inicializa a idade como 0
        pNewTable[i].cCpf[0] = '\0'; // Inicializa o CPF como vazio
        pNewTable[i].pNext = NULL;
    }
    return pNewTable;
    fCheckAvailability = 0;
}

int iHashFunction(pTableItem pItem, int iSize){
    char *cKeyPreHashing = pItem->cCpf;
    int iCaracterHash;
    unsigned long ulKeyNumber= (cKeyPreHashing[0] & 0x0B);
    while((iCaracterHash = *cKeyPreHashing++)){
        ulKeyNumber = (ulKeyNumber ^= (iCaracterHash)) << 5 + ulKeyNumber; 
    }
    return ulKeyNumber % iSize;
}

void vInsertItemNoLinked(pTableItem pHashTable, pTableItem pItem, int iSize){
    int iHashIndex = iHashFunction(pItem, iSize);
    while ((pHashTable[iHashIndex].iAge != 0) && (iHashIndex < iSize)){
        printf("Colisão detectada no índice %d. Tentando resolver...\n", iHashIndex);
        iHashIndex = (iHashIndex + 1); 
    }
    if (iHashIndex == iSize){
        iHashIndex = 0;
        while((pHashTable[iHashIndex].iAge != 0) && (iHashIndex < iSize)){
            printf("Colisão detectada no índice %d. Tentando resolver...\n", iHashIndex);
            iHashIndex = (iHashIndex + 1); 
        }
        if (iHashIndex == iSize){
            printf("Tabela cheia, não foi possível inserir o item.\n");
            return;
        }
    }
    pHashTable[iHashIndex] = *pItem; 
    return;
}

pTableItem pReadNewItem(){
    pTableItem pNewItem = malloc(sizeof(TableItem));
    printf("Digite o nome: ");
    fgets(pNewItem->cName, 256, stdin);
    printf("Digite a idade: ");
    scanf("%d", &pNewItem->iAge);
    getchar();
    printf("Digite o CPF (apenas números): ");
    scanf("%s", &pNewItem->cCpf);
    getchar(); 
    return pNewItem;
}

void vPrintHashTable(pTableItem pHashTable, int iSize){
    int j;
    for(int i = 0; i < iSize; i++){
        printf("Index %d: Name: %s, Age: %d, CPF: %s\n", 
               i, pHashTable[i].cName, pHashTable[i].iAge, pHashTable[i].cCpf);
        pTableItem pAux = pHashTable[i].pNext;
        j = 1;
        while (pAux != NULL){
            printf("Index %d.%d: Name: %s, Age: %d, CPF: %s\n", 
                i, j, pAux->cName, pAux->iAge, pAux->cCpf);
            pAux = pAux->pNext;
            j++;
        }
    }
}

void vFreeHashTable(pTableItem pHashTable, int iSize){
    for(int i = 0; i < iSize; i++){
        pTableItem pAux = pHashTable[i].pNext;
        while(pAux){
            pTableItem pNodeDeleted = pAux;
            pAux = pAux->pNext;
            free(pNodeDeleted);
        }
    }
    free(pHashTable);
}

void vInsertItemLinked(pTableItem pHashTable, pTableItem pNewItem, int iSize){
    int iKey = iHashFunction(pNewItem, iSize);
    if (pHashTable[iKey].iAge != 0){
        printf("Colisão encontrada no index: %d, realizando ligação de listas...\n", iKey);
        pTableItem pAux = &pHashTable[iKey];
        while(pAux->pNext != NULL){
            pAux = pAux->pNext;
        }
        pNewItem->pNext = NULL;
        pAux->pNext = pNewItem;
        return;
    } else {
        fCheckAvailability++;
        pHashTable[iKey] = *pNewItem;
        pHashTable[iKey].pNext = NULL;
    }
    free(pNewItem); 
    return;
}

void vDeleteKey(pTableItem pHashFunction, char *cKey, int iSize){
    pTableItem pItemSearch = malloc(sizeof(TableItem));
    strcpy(pItemSearch->cCpf , cKey);
    int iValue = iHashFunction(pItemSearch, iSize);
    pTableItem pHashAux = pHashFunction;
    while(pHashAux[iValue].pNext){
        if (strcmp(pHashAux[iValue].pNext->cCpf, cKey) == 0){
            pTableItem pAux = pHashAux[iValue].pNext;
            pHashAux[iValue].pNext = pAux->pNext;
            printf("Elemento de CPF: %s excluido com sucesso\n", pAux->cCpf);
            free(pAux);
            free(pItemSearch);
            return;
        }
        pHashAux[iValue].pNext = pHashAux[iValue].pNext->pNext;
    }
    if(strcmp(pHashAux[iValue].cCpf, cKey) == 0){
        fCheckAvailability--;
        pHashAux[iValue].cName[0] = '\0';
        pHashAux[iValue].iAge = 0; 
        pHashAux[iValue].cCpf[0] = '\0';
        pHashAux[iValue].pNext = NULL;
    }
    return;
}

pTableItem pRehashing(pTableItem pHashTable, int *iSize){
    int iNewSize = (*iSize);
    if(fCheckAvailability/(*iSize) > 0.7){
        printf("Rehashing the table...\n");
        iNewSize = (*iSize)<<1;
    }
    else if (fCheckAvailability/(*iSize) < 0.2){
        printf("Rehashing the table...\n");
        iNewSize = (*iSize)>>1;
    }

    if (*iSize != iNewSize){
        pTableItem pTableRehashed = pGeraHashTable(iNewSize);
        for (int i = 0; i < (*iSize); i++) {
            pTableItem pAux = &pHashTable[i];
            if (pAux->iAge != 0) {
                pTableItem pCopy = malloc(sizeof(TableItem));
                *pCopy = *pAux;
                pCopy->pNext = NULL;
                vInsertItemLinked(pTableRehashed, pCopy, iNewSize);
                pAux = pAux->pNext;
                while (pAux != NULL) {
                    pCopy = malloc(sizeof(TableItem));
                    *pCopy = *pAux;
                    pCopy->pNext = NULL;
                    vInsertItemLinked(pTableRehashed, pCopy, iNewSize);
                    pAux = pAux->pNext;
                }
            }
        }
        vFreeHashTable(pHashTable, *iSize);
        *iSize = iNewSize;
        return pTableRehashed;
    }

    return pHashTable;
}