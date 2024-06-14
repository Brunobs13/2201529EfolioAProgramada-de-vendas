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

void add_product() {
    //Abre o arquivo "products.csv" em modo de escrita ao final do arquivo "append"
    FILE *fp;
    fp = fopen("products.csv", "a");
    // Solicita ao usuário que digite o código do produto e armazena na estrutura "products" na posição "num_products"
    printf("Enter product code: ");
    scanf("%d", &products[num_products].code);
    fprintf(fp, "%d,", products[num_products].code); //Escreve o código do produto no arquivo aberto anteriormente
    
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);
    fprintf(fp, "%s,", products[num_products].name);
    
    printf("Enter product price: ");
    scanf("%f", &products[num_products].price);
    fprintf(fp, "%.2f,", products[num_products].price);
    
    products[num_products].quantity_sold = 0; // Definir a quantidade vendida como 0 e armazenar na estrutura "products" na posição "num_products"
    fprintf(fp, "%d\n", products[num_products].quantity_sold);
    num_products++;//Incrementar o número de produtos adicionados
    
    fclose(fp);//fechar arquivo
}

void remove_product() {
    int code;
    printf("Enter product code to remove: ");
    scanf("%d", &code);
    
    // Percorre todos os produtos no array até encontrar um com o mesmo código
    for (int i = 0; i < num_products; i++) {
        if (products[i].code == code) { //Verifica se o código do produto atual é igual ao código passado
            for (int j = i; j < num_products - 1; j++) { // Se o código for encontrado, os produtos à frente do produto atual são movidos uma posição para trás
                products[j] = products[j + 1];
            }
            num_products--; //Diminui o número total de produtos
            break; //Sai do loop pois o produto foi encontrado e excluído com sucesso
        }
    }
    
    //Abre o arquivo original de produtos para leitura
    FILE *input_file = fopen("products.csv", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return;
    }
    
    //Abre o arquivo temporário para escrita
    FILE *temp_file = fopen("products_temp.csv", "w");
    if (temp_file == NULL) {
        printf("Error opening temporary file.\n");
        fclose(input_file);
        return;
    }
    
    //Copia todas as linhas do arquivo de entrada para o arquivo temporário exceto a linha correspondente ao produto removido
    char line[100];
    while (fgets(line, sizeof(line), input_file)) {
        int product_code;
        sscanf(line, "%d", &product_code);
        if (product_code != code) {
            fputs(line, temp_file);
        }
    }
    
    //Fecha ambos os arquivos
    fclose(input_file);
    fclose(temp_file);
    
    //Remove o arquivo original de produtos e renomeia o arquivo temporário para o nome original
    remove("products.csv");
    rename("products_temp.csv", "products.csv");
}


void edit_product() {
    FILE *fp;
    int codigo;
    char novo_nome[100];
    float novo_preco;
    
    printf("Digite o código do produto: ");
    scanf("%d", &codigo);
    
    //Abrir arquivo "products.csv" em modo de leitura e escrita
    fp = fopen("products.csv", "r+");
    //Iteração pelo arquivo e buscar pelo produto com o código digitado
    char linha[1024];
    while (fgets(linha, 1024, fp)) {
        char *tmp = strdup(linha);//Fazer uma cópia da linha para não modificar o ponteiro original
        //Dividir a linha em tokens separados por vírgulas
        char *token = strtok(tmp, ",");
        int tmp_codigo = atoi(token);
       //Se o código for encontrado pedir ao usuário o novo nome e preço e atualizar a linha correspondente
        if (tmp_codigo == codigo) {
            printf("Digite o novo nome do produto: ");
            scanf("%s", novo_nome);
            printf("Digite o novo preço do produto: ");
            scanf("%f", &novo_preco);
            //Movimentar o cursor de volta para o começo da linha e sobrescrevê-la com as novas informações
            fseek(fp, -strlen(linha), SEEK_CUR);
            fprintf(fp, "%d,%s,%.2f\n", codigo, novo_nome, novo_preco);
            break;
        }
        free(tmp); //Libertar memória alocada para cópia da linha
    }
    fclose(fp);
}



