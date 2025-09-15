#ifndef _H_PILHA
#include <stdbool.h>
#define _H_PILHA

struct pilha* criar_pilha(int tamanho);
bool pilhaEhVazia(struct pilha* pilha);
void pilhaPush(struct pilha* pilha, int item);
int pilhaPop(struct pilha* pilha);
int pilhaObtemElemento(struct pilha* pilha);
void listar_pilha (struct pilha* p);

#endif // _H_PILHA