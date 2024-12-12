#include <stdio.h>
#include <string.h>
#include "ykkosvalit.h"

UintPari ykkosValit(const char *syoteNimi, const char *tulosNimi) {
	// Poistaa tiedostosta ylimääräiset välilyönnit. 
	// Tulos laitetaan annetun nimiseen tiedostoon. 
	
    int spc = 0;
    int lkm1 = 0;
    int lkm2 = 0;
    char ch;
    char nw[800] = {0};
    FILE *ff = fopen(syoteNimi, "r");
    FILE *fw = fopen(tulosNimi, "w");
    UintPari pari;

    while ((ch = fgetc(ff)) != EOF) {
        if (ch == '\n') {
            if (lkm2 > 0 && nw[lkm2 - 1] == ' ') {
                --lkm2;
                nw[lkm2++] = '\n';
                ++lkm1;
            }
            else {
                nw[lkm2++] = ch;
                ++lkm1;
            }
            spc = 0;
        }
        else if (ch != ' ') {
            nw[lkm2++] = ch;
            spc = 1;
            ++lkm1;
        }
        else {
            if (spc) {
                nw[lkm2++] = ' ';
                spc = 0;
            }
            ++lkm1;
        }
    }
    nw[lkm2] = '\0';
    fputs(nw, fw);
    fclose(ff);
    fclose(fw);
    pari.x = lkm1;
    pari.y = lkm2;
    return pari;
}
