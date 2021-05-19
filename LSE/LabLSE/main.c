#include <stdlib.h>
#include <stdio.h>
#include "lselab.h"

int main(){
    TypeLinkedData *L;
    TypeInfoData data;

    L = InitList();

    ReadData(&data);
    L = InsertProduct( L , data);
    PrintList(L);

    ReadData(&data);
    L = InsertProduct( L , data);
    PrintList(L);

    ReadData(&data);
    L = InsertProduct( L , data);
    PrintList(L);

    ReadData(&data);
    L = InsertProduct( L , data);
    PrintList(L);

    free(L);

    system("pause");
    return 0;
}
