#ifndef _H_LISTA
#include <stdbool.h>
#define _H_LISTA

// Definição da estrutura do nó da lista duplamente encadeada
struct node {
    char data;
    struct node *next, *prev;
};

// Variável global para manipulação temporária de nós
extern struct node *tmp;

// Definição da estrutura da lista duplamente encadeada
struct listaDupla {
	struct node *inicio, *fim;
};

bool ehVazia(struct listaDupla *lista);
void inserir_fim(struct listaDupla *lista, int elemento);
void apagar_lista(struct listaDupla *lista);
char ehAcentuado(unsigned char c1, unsigned char c2);
void normalizar(char *str);
bool eh_palindromo(struct listaDupla *lista);

#endif // _H_LISTA