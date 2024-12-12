#include "gotokoe.h"

int max2D(int **t2d, int kork, int lev) {
	/* 
	Loop-rakenteen luominen goto-komennolla.
	Löytää suurimman alkion 2-ulotteisesta listasta.
	*/
    int i = 0;
    int j = 0;
    int suurin = t2d[i][j];

    ALKU:
    if (!(i<kork) && !(j<lev))
        goto LOPPU;
    if (t2d[i][j] > suurin)
        goto MUUNNA;
    if (t2d[i][j] < suurin)
        goto OHI;

    OHI:
        if (j == lev - 1)
            goto OHI2;
        ++j;
        goto ALKU;

    OHI2:
        if (i == kork - 1)
            goto LOPPU;
        j = 0;
        ++i;
        goto ALKU;

    MUUNNA:
        suurin = t2d[i][j];
        goto ALKU;

    LOPPU:
        return suurin;

}
