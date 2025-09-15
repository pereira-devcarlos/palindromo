#include <stdio.h>
#include <stdlib.h>
#include "lista/lista.h"

int main(){
    FILE *entrada = fopen("../data/entrada.txt", "r"); // Caminho relativo à pasta src a data
    FILE *saida = fopen("../data/saida.txt", "w");     // Caminho relativo à pasta src a data

    if (entrada == NULL || saida == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    } else {
        printf("Sucesso ao abrir o arquivo!\n");
    }


    fclose(entrada);
    return 0;
}
