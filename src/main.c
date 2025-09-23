#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

/** Trabalho Prático 1 – Palíndromos
 *
 * Este programa lê palavras ou frases de um arquivo de entrada,
 * normaliza os caracteres (remove acentos, espaços e pontuação),
 * insere os caracteres em uma lista duplamente encadeada e verifica
 * se cada expressão é um palíndromo. O resultado é salvo em um arquivo
 * de saída e exibido na tela.
 */

int main() {
    FILE *entrada = fopen("../data/entrada.txt", "r"); // Abrir arquivo de entrada
    FILE *saida = fopen("../data/saida.txt", "w");     // Abrir arquivo de saída

    // Inicializar a lista duplamente encadeada
    struct listaDupla *lista = malloc(sizeof(struct listaDupla));
    lista->inicio = NULL;
    lista->fim = NULL;

    // Verificar se os arquivos foram abertos corretamente
    if (entrada == NULL || saida == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    // Ler cada linha do arquivo de entrada
    char linha[256];
    while (fgets(linha, sizeof(linha), entrada)) {        
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
        
        // Imprimir na tela também
        printf("%d\n", resultado ? 1 : 0);
        
        // Apagar a lista para a próxima linha
        apagar_lista(lista);
    }

    // Fechar os arquivos e liberar memória
    free(lista);
    fclose(entrada);
    fclose(saida);

    return 0;
}
