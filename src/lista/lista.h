#ifndef _H_LISTA
#include <stdbool.h>
#define _H_LISTA

struct node {
    char data;
    struct node *next, *prev;
};

extern struct node *tmp, *tmp1;

struct listaDupla {
	struct node *inicio, *fim;
};

bool ehVazia(struct listaDupla *lista);
void inserir_inicio(struct listaDupla *lista, int elemento);
void inserir_fim(struct listaDupla *lista, int elemento);
void apagar_lista(struct listaDupla *lista);
void imprimir(struct listaDupla *lista);
int obter_primeiro(struct listaDupla *lista);
int obter_ultimo(struct listaDupla *lista);
int obter_posicao(struct listaDupla *lista, int pos);
char ehAcentuado(unsigned char c1, unsigned char c2);
void normalizar(char *str);

#endif // _H_LISTA