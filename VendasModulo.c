#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "comon.h"
#include "file_io.h"
#include "product.h"
#include "sale.h"
#include "search.h"  //cabeçalho que inclui as bibliotecas e arquivos de cabeçalho necessários e define os protótipos das funções do programa

//função main que executa o menu com opções para gerir vendas da loja
int main() {
    int option;
    
    read_products("products.csv");
    read_sales("sales.csv");
    update_sales();
    
    do {
        printf("\nMenu:\n1. Add product\n2. Remove product\n3. Edit product\n4. Search product\n5. Generate sales report\n6. Exit\n");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                add_product();
                break;
            case 2:
                remove_product();
                break;
            case 3:
                edit_product();
                break;
            case 4:
                search_product();
                break;
            case 5:
                generate_report();
                break;
            case 6:
                break;
            default:
                printf("Invalid option\n");
        }
    } while (option != 6);
    
    return 0;
}