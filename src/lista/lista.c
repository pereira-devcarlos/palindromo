#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "lista.h"

bool ehVazia(struct listaDupla *lista) {
    if (lista->inicio == NULL) {
        return (1);
    } else {
        return (0);
    }
}

void inserir_inicio(struct listaDupla *lista, int elemento) {
	tmp = (struct node*) malloc (sizeof(struct node));
	tmp->data=elemento;
	tmp->next = NULL;
	tmp->prev = NULL;
	if (ehVazia(lista)){
		lista->inicio = tmp;
		lista->fim = tmp;
	} else {
		tmp->next = lista->inicio;
		lista->inicio->prev = tmp;
		lista->inicio = tmp;
	}
}

void inserir_fim(struct listaDupla *lista, int elemento) {
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

// Função para inserir em uma determinada posição
void inserir_posicao(struct listaDupla *lista, int elemento, int pos) {
    // Caso for inserir na primeira posição
    if (pos == 1){
        inserir_inicio(lista, elemento);
		return;
    }

    tmp = (struct node*) malloc (sizeof(struct node));
    tmp->data=elemento;
	tmp->next=NULL;
	tmp->prev = NULL;

	tmp1 = lista->inicio;
    
    for (int i = 1; i < pos && tmp1 != NULL; i++){
        tmp1 = tmp1->next;
    }
    // Caso não tiver uma posição, liberar a memória
    if (tmp1 == NULL){
        printf("\nErro: posicao inexistente, no inserido no final da lista!");
        inserir_fim(lista, elemento);
		return;
    }
    // Inserir na lista duplamente encadeada
	tmp->next = tmp1;
	tmp->prev = tmp1->prev;
	tmp1->prev->next = tmp;
	tmp1->prev = tmp;
}

void apagar(struct listaDupla *lista, int ele) {
	tmp = lista->inicio;
	struct node *pre = tmp;
	while (tmp != NULL) {
		if (tmp->data==ele) {
            if (tmp == lista->inicio) {
                lista->inicio = lista->inicio->next;
				if (lista->inicio != NULL){
					lista->inicio->prev = NULL;
				}
				printf("\nElemento deletado - %d", tmp->data);			
				free(tmp);
				return;
			} else if (tmp->next == NULL){
				pre->next = NULL;
				lista->fim = pre;
				printf("\nElemento deletado - %d", tmp->data);			
				free(tmp);
				return;
			} else {
                pre->next=tmp->next;
				tmp->next->prev = pre;
				printf("\nElemento deletado - %d", tmp->data);			
			    free(tmp);
			    return;
			}
		} else {
            pre = tmp;
		    tmp = tmp->next;
		}
	}
	printf("\n Valor não encontrado! ");
 }
 
void apagar_inicio(struct listaDupla *lista) {	
	tmp = lista->inicio;
	if (tmp == NULL) {
		printf("\n Nenhum elemento deletado ");
    } else {
		printf("\nElemento deletado - %d", lista->inicio->data);
		lista->inicio = lista->inicio->next;
		if (lista->inicio != NULL){
			lista->inicio->prev = NULL;
		}
		free(tmp);
	}
 }
 
void apagar_fim(struct listaDupla *lista) {	
	tmp= lista->fim;
	struct node* pre;
	if(lista->inicio == NULL) {
		printf("\n Nenhum elemento deletado ");
    } else {
		if (lista->inicio->next == NULL){
			lista->inicio = NULL;
			lista->fim = NULL;
			printf("\nElemento deletado - %d", tmp->data);
			free(tmp);
			return;
		}
		pre = lista->fim->prev;
		pre->next= NULL;
		lista->fim = pre;
		
		printf("\nElemento deletado - %d", tmp->data);
		free(tmp);
	}
}

// Função para apagar em uma determinada posição
void apagar_posicao(struct listaDupla *lista,int pos) {
	tmp = lista->inicio;
	int i;

	// Remover na primeira posição 
	if (pos == 1){
		if (lista->inicio == NULL) {
			printf("\nErro: lista vazia!");
			return;
		}
		apagar_inicio(lista);
		return;
	}

	for (i = 1; i < pos - 1 && tmp != NULL; i++){
		tmp = tmp->next;
	}
	tmp1 = tmp->next;
	// Se tmp for NULL ou tmp->next for NULL, posição é inválida
	if (tmp == NULL || tmp->next == NULL){
		printf("\nErro: nao possui no nesta posicao!");
		return;
	} else if (tmp1->next == NULL){
		apagar_fim(lista);
		return;
	} else {
		tmp->next = tmp1->next;
		tmp1->next->prev = tmp;
		printf("\nElemento deletado - %d", tmp1->data);
		free(tmp1);
	}
}	

void imprimir(struct listaDupla *lista) {
	tmp = lista->inicio;
 	while (tmp != NULL) {
        printf("\n %d",tmp->data);
	 	tmp = tmp->next;
	}
}

int obter_primeiro(struct listaDupla *lista) {
	if (lista->inicio == NULL) {
		printf("\n Nenhum elemento encontrado ");
        return (0);
    } else {
		return (lista->inicio->data);
	}
}

int obter_ultimo(struct listaDupla *lista) {
	if (lista->inicio == NULL) {
		printf("\n Nenhum elemento encontrado ");
        return (0);
    } else {
		return(lista->fim->data);
	}
}

// Função para obter o valor em uma determinada posição
int obter_posicao (struct listaDupla *lista, int pos) {
	tmp = lista->inicio;

	if (lista->inicio == NULL){
		// Retornar 0 caso de lista vazia
		return 0;
	}

	for (int i = 1; i < pos; i++){
		tmp = tmp->next;
	}
	if (tmp == NULL || pos <= 0){
		// Posição é inválida
		return -1;
	}
	return tmp->data;
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