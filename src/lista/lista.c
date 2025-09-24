#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "lista.h"

// Variável global para manipulação temporária de nós
struct node *tmp;

// Função para verificar se a lista está vazia
bool ehVazia(struct listaDupla *lista) {
    if (lista->inicio == NULL) {
        return (1);
    } else {
        return (0);
    }
}

// Função para inserir um elemento no final da lista
void inserir_fim(struct listaDupla *lista, char elemento) {
    tmp = (struct node*) malloc (sizeof(struct node));
    tmp->data=elemento;
    tmp->next=NULL;
	tmp->prev = NULL;
    if (ehVazia(lista)) {
		lista->inicio = tmp;
		lista->fim = tmp;
    } else {
        lista->fim->next = tmp;
		tmp->prev = lista->fim;
		lista->fim = tmp;
    }
}

// Função para apagar toda a lista e liberar memória
void apagar_lista(struct listaDupla *lista) {	
	tmp = lista->inicio;
	while (tmp != NULL) {
		struct node *proximo = tmp->next;
		free(tmp);
		tmp = proximo;
	}
	lista->inicio = NULL;
	lista->fim = NULL;
}

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
        // Pega o caractere atual
        unsigned char c = str[i];

        if (c < 128) {
            // Caractere ASCII sem acentuação
            if (isalnum(c)) {
                temp[j++] = tolower(c);
            }
            i++;
        } else {
            // Provavelmente início de um caractere UTF-8 multibyte (acentuado)
            unsigned char c1 = str[i];
            unsigned char c2 = str[i + 1];

            char substituto = ehAcentuado(c1, c2);
            if (substituto) {
                temp[j++] = substituto;
            }
            i += 2; // Pular o caractere UTF-8
        }
    }

    // Finaliza a string normalizada 
    temp[j] = '\0';
    strcpy(str, temp);
}

// Função para verificar se a linha é palíndromo
bool eh_palindromo(struct listaDupla *lista) {
    // Ponteiros para o início e o fim da lista
    struct node *inicio = lista->inicio;
    struct node *fim = lista->fim;
    
    // Compara caracteres do início e fim, movendo-se em direção ao centro
	// Verifica se os ponteiros não se cruzaram ou se encontraram
    while (inicio != fim && inicio->prev != fim) {
        if (inicio->data != fim->data) {
            // Caracteres diferentes, não é palíndromo
            return false;
        }
        inicio = inicio->next;
        fim = fim->prev;
    }
    
    return true;
}