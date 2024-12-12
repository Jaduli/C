#include "bitit.h"
#include <limits.h>

/*
Funktiot kääntävät annettujen lukujen bitit käänteiseen järjestykseen. 
*/

void kaannaScharBitit(signed char *x) {
    signed char num = (signed char) *x;
    signed char reversed_num;
    unsigned int i;
    unsigned int bits = sizeof(signed char) * CHAR_BIT;

    for (i = 0; i < bits; i++) {
        reversed_num = (reversed_num << 1) | (num & 1);
        num >>= 1;
    }
    *x = reversed_num;
}

void kaannaShortBitit(short int *x) {
    short int num = (short int) *x;
    short int reversed_num;
    unsigned int i;
    unsigned int bits = sizeof(short int) * CHAR_BIT;

    for (i = 0; i < bits; i++) {
        reversed_num = (reversed_num << 1) | (num & 1);
        num >>= 1;
    }
    *x = reversed_num;
}

void kaannaIntBitit(int *x) {
    int num = (int) *x;
    int reversed_num;
    unsigned int i;
    unsigned int bits = sizeof(int) * CHAR_BIT;;


    for (i = 0; i < bits; i++) {
        reversed_num = (reversed_num << 1) | (num & 1);
        num >>= 1;
    }
    *x = reversed_num;
}

void kaannaLongBitit(long int *x) {
    long int num = (long int) *x;
    long int reversed_num;
    unsigned int i;
    unsigned int bits = sizeof(long int) * CHAR_BIT;

    for (i = 0; i < bits; i++) {
        reversed_num = (reversed_num << 1) | (num & 1);
        num >>= 1;
    }
    *x = reversed_num;
}
