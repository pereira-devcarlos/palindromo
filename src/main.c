#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lista.h"
#include "pilha.h"


int main() {
    FILE *entrada = fopen("../data/entrada.txt", "r"); // Caminho relativo
    FILE *saida = fopen("../data/saida.txt", "w");     // Caminho relativo

    if (entrada == NULL || saida == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    } else {
        printf("Sucesso ao abrir o arquivo!\n");
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), entrada)) {
        // Exibe a linha original
        printf("\nLinha lida: %s", linha);

        // Normaliza
        normalizar(linha);

        // Exibe a linha normalizada
        printf("\nLinha apos normalizar: %s\n", linha);

        // Escreve no arquivo de saída
        fprintf(saida, "%s\n", linha);
    }

    fclose(entrada);
    fclose(saida);

    return 0;
}
