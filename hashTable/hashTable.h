#ifdef HASHTABLE_H_API
#endif
#define MAX_VALUE_NAME 256

typedef struct TableItem{
    char cName[MAX_VALUE_NAME];
    int iAge;
    char cCpf[12];
    struct TableItem *pNext;
}TableItem, *pTableItem;

extern float fCheckAvailability;

enum xOptions{
    INSERIR = 1,
    EXCLUIR = 2,
    CONCLUIR = 3,
    LIMPAR = 4,
    CRIAR = 5,
    IMPRIMIR = 6
};

int iHashFunction(pTableItem pItem, int iSize);

pTableItem pGeraHashTable(int iSize);

pTableItem pReadNewItem();

void vFreeHashTable(pTableItem pHashTable, int iSize);

void vInsertItemNoLinked(pTableItem pHashTable, pTableItem pItem, int iSize);

void vPrintHashTable(pTableItem pHashTable, int iSize);

void vInsertItemLinked(pTableItem pHashTable, pTableItem pNewItem, int iSize);

void vDeleteKey(pTableItem pHashTable, char *cKey, int iSize);

pTableItem pRehashing(pTableItem pHashTable, int *iSize);