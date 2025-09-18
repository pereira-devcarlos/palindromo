#ifndef _H_LISTA
#include <stdbool.h>
#define _H_LISTA

struct node {
    char data;
    struct node *next, *prev;
}*tmp, *tmp1;

struct listaDupla {
	struct node *inicio, *fim;
};

void inserir_fim(struct listaDupla *lista, int elemento);
void inserir_inicio(struct listaDupla *lista, int elemento);
void inserir_posicao(struct listaDupla *lista, int elemento, int pos);
void apagar(struct listaDupla *lista, int elemento);
void apagar_inicio(struct listaDupla *lista);
void apagar_fim(struct listaDupla *lista);
void apagar_posicao(struct listaDupla *lista, int pos);
bool ehVazia(struct listaDupla *lista);
int obter_primeiro(struct listaDupla *lista);
int obter_ultimo(struct listaDupla *lista);
int obter_posicao(struct listaDupla *lista, int pos);
void imprimir(struct listaDupla *lista);
char ehAcentuado(unsigned char c1, unsigned char c2);
void normalizar(char *str);

#endif // _H_LISTA