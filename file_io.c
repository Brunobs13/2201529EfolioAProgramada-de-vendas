#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "comon.h"
#include "file_io.h"
#include "product.h"
#include "sale.h"

//Definição das variáveis globais
Product products[MAX_PRODUCTS];
int num_products = 0;

Sale sales[MAX_SALES];
int num_sales = 0;


void read_products(char *filename) {    
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%d,%[^,],%f", &products[num_products].code, products[num_products].name, &products[num_products].price);
        products[num_products].quantity_sold = 0;
        num_products++;
    }
    
    fclose(file);
    //Implementação da leitura de produtos de um arquivo CSV
}

void read_sales(char *filename) {
    //mplementação da leitura de vendas de um arquivo CSV
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    // Lê uma linha do arquivo, faz a análise da string utilizando sscanf() e armazena as informações na struct sales.
// A contagem de vendas é incrementada
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%d,%d,%[^,\n]", &sales[num_sales].product_code, &sales[num_sales].quantity, sales[num_sales].date);
        num_sales++;
    }
    
    fclose(file);
}

