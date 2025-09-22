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
        // Salva a palavra original para exibir na saída
        char palavra_original[256];
        strcpy(palavra_original, linha);
        
        // Normalizar a palavra ou frase
        normalizar(linha);

        // Inserir na lista duplamente encadeada
        int tamanho = strlen(linha);
        for (int i = 0; i < tamanho; i++){
            inserir_fim(lista, linha[i]);
        }
        
        // Verificar se é palíndromo
        bool resultado = eh_palindromo(lista);
        
        // Escrever no arquivo de saída no formato: palavra,resultado
        fprintf(saida, "%d\n", resultado ? 1 : 0);
        
        // Opcional: imprimir na tela também
        printf("%d\n", resultado ? 1 : 0);
        
        // Apagar a lista para a próxima linha
        apagar_lista(lista);
    }

    fclose(entrada);
    fclose(saida);

    return 0;
}
