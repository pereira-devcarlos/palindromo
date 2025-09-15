#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "lista.h"

// Função para mapear caracteres UTF-8 acentuados para suas versões sem acento
char ehAcentuado(unsigned char c1, unsigned char c2) {
    if (c1 == 0xC3) {
        switch (c2) {
            // Letras minúsculas
            case 0xA1: case 0xA0: case 0xA2: case 0xA3: return 'a';  // á à â ã
            case 0xA9: case 0xA8: case 0xAA: return 'e';             // é è ê
            case 0xAD: case 0xAC: case 0xAE: return 'i';             // í ì î
            case 0xB3: case 0xB2: case 0xB4: case 0xB5: return 'o';  // ó ò ô õ
            case 0xBA: case 0xB9: case 0xBB: return 'u';             // ú ù û
            case 0xA7: return 'c';                                   // ç

            // Letras maiúsculas
            case 0x81: case 0x80: case 0x82: case 0x83: return 'a';  // Á À Â Ã
            case 0x89: case 0x88: case 0x8A: return 'e';             // É È Ê
            case 0x8D: case 0x8C: case 0x8E: return 'i';             // Í Ì Î
            case 0x93: case 0x92: case 0x94: case 0x95: return 'o';  // Ó Ò Ô Õ
            case 0x9A: case 0x99: case 0x9B: return 'u';             // Ú Ù Û
            case 0x87: return 'c';                                   // Ç
        }
    }

    return 0; // Não é acentuado tratado
}

// Função para normalizar uma string (remover acentos, converter para minúsculas, remover não-alnum)
void normalizar(char *str) {
    char temp[256];
    int i = 0, j = 0;

    while (str[i]) {
        unsigned char c = str[i];

        if (c < 128) {
            // ASCII normal
            if (isalnum(c)) {
                temp[j++] = tolower(c);
            }
            i++;
        } else {
            // Provavelmente início de um caractere UTF-8 multibyte
            unsigned char c1 = str[i];
            unsigned char c2 = str[i + 1];

            char substituto = ehAcentuado(c1, c2);
            if (substituto) {
                temp[j++] = substituto;
            }
            i += 2; // Pular o caractere UTF-8
        }
    }

    temp[j] = '\0';
    strcpy(str, temp);
}

// Estrutura da fila
struct fila { 
	No* inicio; 
	No* fim; 
	int tamanhoAtul; 
	No* items; 
};

struct fila* criar_fila() { 
	// Aloca a estrutura de dados fila
    struct fila* fila = (struct fila*) malloc(sizeof(struct fila)); 
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanhoAtul = 0; 
    fila->items = NULL; 
    // Retorna a fila
	return fila; 
} 

bool ehVazia(struct fila* fila) { 
	// Se o início == NULL, então a fila é vazia
    if (fila->inicio == NULL) {
        return (true);
    } 
    return (false);
} 

void push(struct fila* fila, int item) { 
    // Alocação do nó a ser inserido na fila
    No* insere = (No*) malloc(sizeof(No));
    insere->valor = item;
    insere->prox = NULL;

    if (ehVazia(fila)) { 
        fila->inicio = insere;
        fila->fim = insere;
    } else {
        fila->fim->prox = insere;
        fila->fim = insere;
    }
    fila->items = fila->inicio;
    fila->tamanhoAtul++;
}

No* pop(struct fila* fila) { 
    if (ehVazia(fila)) {
        return NULL; 
    } 
    else {
        No* rem = fila->inicio;
        fila->inicio = fila->inicio->prox; 
        fila->tamanhoAtul--;

        if (fila->inicio == fila->fim) {
            // Último elemento removido
            fila->fim = NULL;
        } 
        return rem;
    }
} 

No* obtem_elemento(struct fila* fila) { 
	// Se a fila estiver vazia, não tem como obter nenhum elemento
    if (ehVazia(fila)) {
		printf("\nFila vazia. Impossível obter elementos");
        return NULL; 
    }
    // Retorna o elemento do início da fila
	return fila->inicio; 
} 