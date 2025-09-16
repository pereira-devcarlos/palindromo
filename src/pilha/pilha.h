#ifndef _H_PILHA
#include <stdbool.h>
#define _H_PILHA

struct pilha { 
	int topo; 
	int tamanho; 
	int* items; 
}; 

struct pilha* criar_pilha(int tamanho);
bool pilhaEhVazia(struct pilha* pilha);
void pilhaPush(struct pilha* pilha, int item);
int pilhaPop(struct pilha* pilha);

#endif // _H_PILHA