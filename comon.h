//diretiva de pré-processador que evita múltiplas definições da mesma biblioteca
#ifndef MYMODULE_H
#define MYMODULE_H

//tamanho máximo para os arrays de produtos e vendas
#define MAX_PRODUCTS 1000
#define MAX_SALES 10000


//Definição de estruturas para produtos e vendas
typedef struct {
    int code;
    char name[50];
    float price;
    int quantity_sold;
} Product;

typedef struct {
    int product_code;
    int quantity;
    char date[11];
} Sale;


#endif