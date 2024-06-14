#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "comon.h"
#include "file_io.h"
#include "product.h"
#include "sale.h"


extern Product products[MAX_PRODUCTS];
extern int num_products;

extern Sale sales[MAX_SALES];
extern int num_sales;


//atualiza as quantidades vendidas de cada produto com base nas vendas registradas no sistema
void update_sales() {
    for (int i = 0; i < num_sales; i++) {
        for (int j = 0; j < num_products; j++) {
            if (sales[i].product_code == products[j].code) {
                products[j].quantity_sold += sales[i].quantity;
                break;
            }
        }
    }
}
//gera um relatório de vendas e mostra os detalhes de cada venda e o total de vendas e receita gerada
void generate_report() {
    float total_sales = 0;
    float total_revenue = 0;
    
    printf("Relatório de vendas:\n\n");
    for (int i = 0; i < num_sales; i++) {
        if (sales[i].product_code != 0 && sales[i].quantity != 0 && sales[i].date != 0) {
            printf("Código do produto: %d\n", sales[i].product_code);
            printf("Quantidade vendida: %d\n", sales[i].quantity);
            printf("Data da venda: %s\n", sales[i].date);
            
            for (int j = 0; j < num_products; j++) {
                if (products[j].code == sales[i].product_code) {
                    printf("Nome do produto: %s\n", products[j].name);
                    printf("Preço do produto: %.2f\n", products[j].price);
                    printf("Receita total: %.2f\n\n", products[j].price * sales[i].quantity);
                    
                    total_sales += sales[i].quantity;
                    total_revenue += products[j].price * sales[i].quantity;
                    break;
                }
            }
        }
    }
    
    printf("Total de vendas: %.0f\n", total_sales);
    printf("Receita total: %.2f\n", total_revenue);
}