#include <malloc.h>
#include "luku.h"

char * lueKunnes(FILE *virta, char erotin, size_t *pituus) {
	// Lukee tiedostosta merkkejä annettuun erottimeen asti. 
    char mrk;
    size_t kap = 1;
    char *puskuri = malloc(kap);
    size_t pit = 0;

    while ((mrk = fgetc(virta)) != EOF && mrk != erotin) {
        if (pit == kap) {
            kap *= 2;
            puskuri = realloc(puskuri, kap);
        }
        puskuri[pit++] = mrk;
    }
    if (pit > 0) {
        puskuri = realloc(puskuri, pit + 1);
        puskuri[pit + 1] = '\0';
    }
    else {
        if (mrk == EOF) {
            puskuri = realloc(puskuri, 0);
        }
        else {
            puskuri = realloc(puskuri, 1);
        }
    }
    *pituus = pit;
    return puskuri;
}
