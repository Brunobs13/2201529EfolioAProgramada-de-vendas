#include <stdio.h>
#include "file_io.h"
#include "comon.h"
#include "search.h"
#include <string.h>
//Declaração das variáveis globais dos produtos e vendas
extern Product products[MAX_PRODUCTS];
extern int num_products;

extern Sale sales[MAX_SALES];
extern int num_sales; 


//Função para pesquisar um produto por código ou nome
void search_product() {
	int option;
	printf("Pesquisar por:\n");
	printf("1. Código\n");
	printf("2. Nome\n");
	printf("Digite a opção: ");
	scanf("%d", &option);
	getchar();
	
	if (option == 1) {
		int code;
		printf("Digite o código do produto para pesquisar: ");
		scanf("%d", &code);
		//Busca por código do produto
		for (int i = 0; i < num_products; i++) {
			if (products[i].code == code) {
				printf("Produto encontrado: %d - %s\n", products[i].code, products[i].name);
			return;
			}
		}
	} else if (option == 2) { //Pesquisa um produto pelo nome ou código.
		char name[50];
		printf("Digite o nome do produto para pesquisar: ");
		fgets(name, sizeof(name), stdin); //Lê uma string com o nome do produto do utilizador
		name[strcspn(name, "\n")] = 0; // Remove o caractere de quebra de linha do final da string "name"
		
		// Itera sobre todos os produtos e verifica se o nome informado corresponde a algum deles,
		// se sim, exibe o código do produto encontrado e finaliza o loop
		for (int i = 0; i < num_products; i++) {
			if (strcmp(products[i].name, name) == 0) {
				printf("Produto encontrado: %d\n", products[i].code);
				break;
			}
		}
	} else {
		printf("Opção inválida\n");
	}
}


