#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lista.h"


int main() {
    FILE *entrada = fopen("../data/entrada.txt", "r"); // Caminho relativo
    FILE *saida = fopen("../data/saida.txt", "w");     // Caminho relativo

    struct listaDupla *lista = malloc(sizeof(struct listaDupla));
    lista->inicio = NULL;
    lista->fim = NULL;

    if (entrada == NULL || saida == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    } else {
        printf("Sucesso ao abrir o arquivo!\n");
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), entrada)) {
        // Normalizar a palavra ou frase
        normalizar(linha);

        // Inserir na lista duplamente encadeada
        int tamanho = strlen(linha);
        for (int i = 0; i < tamanho; i++){
            inserir_fim(lista, linha[i]);
        }
        

        // Escreve no arquivo de saída
        //fprintf(saida, "%s\n", linha);
    }

    fclose(entrada);
    fclose(saida);

    return 0;
}
