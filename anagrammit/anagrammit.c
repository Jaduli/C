#include <string.h>
#include <stdio.h>
#include <limits.h>
#include "anagrammit.h"

int anagrammeja(char mj1[], char mj2[]) {
	/*
	Tutkii, ovatko annetut merkkijonot anagrammmeja (sisältävät
	täsmälleen samat merkit eri järjestyksessä).
	Paluuarvo 1, jos ovat anagrammeja, muuten 0.
	*/
    int lkmt[UCHAR_MAX + 1];
    int i = 0;

    memset(lkmt, 0, sizeof(lkmt));

    for (i = 0; mj1[i] != '\0'; i++) {
        lkmt[(unsigned char)mj1[i]]++;
    }

    for (i = 0; mj2[i] != '\0'; i++) {
        lkmt[(unsigned char)mj2[i]]--;
    }

    for (i = 0; i <= UCHAR_MAX; i++) {
        if (lkmt[i] != 0) {
            return 0;
        }
    }

    return 1;
}
