#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//#include "lista/lista.h"

char removerAcento(unsigned char c) {
    switch(c) {
        case 'á': case 'à': case 'ã': case 'â': return 'a';
        case 'Á': case 'À': case 'Ã': case 'Â': return 'a';
        case 'é': case 'è': case 'ê': return 'e';
        case 'É': case 'È': case 'Ê': return 'e';
        case 'í': case 'ì': case 'î': return 'i';
        case 'Í': case 'Ì': case 'Î': return 'i';
        case 'ó': case 'ò': case 'õ': case 'ô': return 'o';
        case 'Ó': case 'Ò': case 'Õ': case 'Ô': return 'o';
        case 'ú': case 'ù': case 'û': return 'u';
        case 'Ú': case 'Ù': case 'Û': return 'u';
        case 'ç': case 'Ç': return 'c';
        default: return tolower(c);
    }
}

void normalizar(char *str) {
    int i, j = 0;
    char temp[256];

    for (i = 0; str[i] != '\0'; i++) {
        if (isalnum((unsigned char) str[i])) {
            temp[j++] = removerAcento((unsigned char) str[i]);
        }
    }

    temp[j] = '\0';
    strcpy(str, temp);
}

int main(){
    FILE *entrada = fopen("../data/entrada.txt", "r"); // Caminho relativo à pasta src a data
    FILE *saida = fopen("../data/saida.txt", "w");     // Caminho relativo à pasta src a data

    if (entrada == NULL || saida == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    } else {
        printf("Sucesso ao abrir o arquivo!\n");
    }

    char linha[32];
    while (fgets(linha, sizeof(linha), entrada)) {
        // Aqui dentro você trata a linha
        printf("Linha lida: %s", linha);
        normalizar(linha);
        printf("Linha apos normalizar: %s\n", linha);
    }
    printf("\n");



    fclose(entrada);
    return 0;
}
