#include "hashTable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){    
    int iSize;
    pTableItem pItem;
    pTableItem pNewHashTable = NULL; 
    int iOpcao;
    while(iOpcao != CONCLUIR){
        printf("Digite uma opcao:\n1 - INSERIR DADO NA TABELA\t\n2 - EXCLUIR TABELA INTEIRA\t\n3 - FINALIZAR PROGRAMA\t\n4 - RETIRAR  ELEMENTO DA TABELA\t\n5 - CRIAR TABELA\t\n6 - IMPRIMIR TABELA\n");
        scanf("%d", &iOpcao);
        getchar();
        if (iOpcao == INSERIR){
            if (pNewHashTable){
                pItem = pReadNewItem();
                vInsertItemLinked(pNewHashTable, pItem, iSize);  
                pNewHashTable = pRehashing(pNewHashTable, &iSize);
                printf("\nFator de Carga: %f\n Disponibilidade: %f \n", (fCheckAvailability/iSize), fCheckAvailability);
            }
            else{
                printf("Não existe hash table criada, crie uma nova\n");                
            }
        }
        else if(iOpcao == EXCLUIR){
            if(pNewHashTable){
                vFreeHashTable(pNewHashTable, iSize);
                printf("TABELA EXCLUIDA COM SUCESSO\n");
                pNewHashTable=NULL;
            }
        }
        else if (iOpcao == CONCLUIR){
            if(pNewHashTable){
                vFreeHashTable(pNewHashTable, iSize);
            }
            printf("PROGRAMA ENCERRADO\n");
        }
        else if (iOpcao == LIMPAR){
            char cKey[12];
            printf("Insira a key do sistema: \n");
            scanf("%s", &cKey);
            getchar();
            vDeleteKey(pNewHashTable, cKey, iSize);
        }
        else if (iOpcao == CRIAR){
            printf("Digite o tamanho da tabela hash: \n");
            scanf("%d", &iSize);
            getchar();
            if(pNewHashTable)
                printf("Tabela já existente\n");
            else
                pNewHashTable = pGeraHashTable(iSize);
        }
        else if (iOpcao == IMPRIMIR){
            if(pNewHashTable){
                vPrintHashTable(pNewHashTable, iSize);
            }
            else{
                printf("Não existe tabela criada\n");
            }
        }
    }
    pNewHashTable = NULL;
    return 0;
}