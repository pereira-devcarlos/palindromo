#ifndef _H_LISTA
#include <stdbool.h>
#define _H_LISTA

// Nó da fila
typedef struct no {
    int valor;
    struct no* prox;
} No;

struct fila* criar_fila();
bool filaEhVazia(struct fila* fila);
void filaPush(struct fila* fila, int item);
No* filaPop(struct fila* fila);
No* obtem_elemento(struct fila* fila);
char ehAcentuado(unsigned char c1, unsigned char c2);
void normalizar(char *str);

#endif // _H_LISTA