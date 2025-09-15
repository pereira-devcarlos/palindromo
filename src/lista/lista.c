#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "lista.h"

char removerAcento(unsigned char c) {
    switch(c) {
        case 'á': case 'à': case 'ã': case 'â': return 'a';
        case 'Á': case 'À': case 'Ã': case 'Â': return 'a';
        case 'é': case 'è': case 'ê': return 'e';
        case 'É': case 'È': case 'Ê': return 'e';
        case 'í': case 'ì': case 'î': return 'i';
        case 'Í': case 'Ì': case 'Î': return 'i';
        case 'ó': case 'ò': case 'õ': case 'ô': return 'o';
        case 'Ó': case 'Ò': case 'Õ': case 'Ô': return 'o';
        case 'ú': case 'ù': case 'û': return 'u';
        case 'Ú': case 'Ù': case 'Û': return 'u';
        case 'ç': case 'Ç': return 'c';
        default: return tolower(c);
    }
}

void normalizar(char *str) {
    int i, j = 0;
    char temp[256];

    for (i = 0; str[i] != '\0'; i++) {
        if (isalnum((unsigned char) str[i]) || str[i] == 'ç' || str[i] == 'Ç') {
            temp[j++] = removerAcento((unsigned char) str[i]);
        }
    }

    temp[j] = '\0';
    strcpy(str, temp);
}
