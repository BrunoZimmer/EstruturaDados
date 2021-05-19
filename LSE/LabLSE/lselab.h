struct S_InfoData {
  int codigo;
  char nome[50];
  int preco;
};
typedef struct S_InfoData TypeInfoData;

struct S_LinkedData{
  TypeInfoData info;
  struct TypeLinkedData *next;
};
typedef struct S_LinkedData TypeLinkedData;

//Inicializar a lista
TypeLinkedData* InitList( void );

//Read data of TypeInfoData
void ReadData( TypeInfoData *data );

//Insert a product in numerical order
TypeLinkedData* InsertProduct (  TypeLinkedData* list, TypeInfoData data  );

//Print all items of the list
void PrintList (  TypeLinkedData* list );
