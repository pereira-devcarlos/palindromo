#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
#include <stdbool.h>
#include "pilha.h"


struct pilha* criar_pilha(int tamanho) { 
	// Aloca a estrutura de dados pilha
    struct pilha* pilha = (struct pilha*)malloc(sizeof(struct pilha)); 
	// Armazena o tamanho que ela foi criada
    pilha->tamanho = tamanho; 
    // Diz que não existe nenhum elemento no topo
	pilha->topo = -1; 
    // Aloca o vetor de items utilizando o tamanho passado para a função
	pilha->items = (int*)malloc(pilha->tamanho * sizeof(int)); 
    // Retorna a pilha
	return pilha; 
} 

bool pilhaEhVazia(struct pilha* pilha) { 
	// Se o topo == -1, então a pilha é vazia
    // Verificar que isto é verdade na criação da pilha
    if (pilha->topo == -1) {
        return (true);
    } 
    return (false);
} 

void pilhaPush(struct pilha* pilha, int item) { 
	// Se a pilha encher, dobramos o tamanho dela e realocamos
    if (pilha->topo == pilha->tamanho - 1) {
		pilha->tamanho *= 2;
        pilha->items = (int*) realloc(pilha->items, pilha->tamanho * sizeof(int));
    }
    // Aumenta o topo da pilha
    pilha->topo++;
    // Insere o elemento no topo da pilha
	pilha->items[pilha->topo] = item; 
} 

int pilhaPop(struct pilha* pilha) { 
	// Se a pilha estiver vazia, não tem como remover nenhum elemento
    if (pilhaEhVazia(pilha)) {
		printf("\nPilha  vazia. Impossível remover elementos");
        return -1; 
    }
    // Remove o elemento no topo da pilha e diminui o topo
	return (pilha->items[pilha->topo--]); 
}


