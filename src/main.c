#include <stdio.h>
#include <stdlib.h>
#include "lista/lista.h"

int main(){
    FILE *entrada = fopen("../data/entrada.txt", "r"); // Caminho relativo à pasta src

    if (entrada == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    } else {
        printf("Sucesso ao abrir o arquivo!\n");
    }

    // ... código para ler o arquivo ...

    fclose(entrada);
    return 0;
}
