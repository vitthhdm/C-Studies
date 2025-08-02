#ifdef LINKED_LIST_H_API
#endif
#include "stdio.h"
#include "stdlib.h"

/*
 *************************************************
 * @Author: Vittoro Eduardo
 * 
 * @Date: 24-07-2025
 * 
 * @Brief: Esse bloco .h é um documento para definir
 * as funcoes que serão utilizadas para manipulacao
 * de linked list.
 * ***********************************************
*/

/*
* @brief: Estrutura que define o nó
* dentro da linked list com proximo 
* e id de tipo inteiro
* 
* @PARAMETERS_RETURN: iIndex, variável inteira que define o index/id do no'
* @PARAMETERS_RETURN: pNext, ponteiro para o pro'ximo no'
*/
typedef struct No{
    int iIndex;
    struct No *pNext;
}No, *pNo;

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
pNo pInsereNoInicio(pNo pHead, int iNewIndex);

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
pNo pInsereNoFinal(pNo pHead, int iNewIndex);

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
pNo pInsereOrdenado(pNo pHead, int iNewIndex);

/*
 * @brief: vPrintList é uma função que imprime a lista ligada
 * 
 * @Parameters: pNo pHead; é uma variável do tipo ponteiro da estrutura No
 * que referencia ao início da lista ligada
 * 
*/
void vPrintList(pNo pHead);

/*
 * @brief: vLiberaLista é uma função que libera uma lista ligada, liberando
 * todos os nós.
 * 
 * @Parameters: pNo pHead; é uma variável do tipo ponteiro da estrutura No
 * que referencia ao início da lista ligada
 * 
*/
void vLiberaLista(pNo pHead);

/*
 * @brief: vRemoveNo libera um nó da lista ligada especificada no index do nó
 * 
 * @Parameters: pNo pHead; é uma variável do tipo ponteiro da estrutura No
 * que referencia ao início da lista ligada
 * @Parameters: int iIndex é uma variável do tipo inteiro que representa o
 * nó que será retirado.
 * 
*/
void vRemoveNo(pNo pHead, int iIndex);