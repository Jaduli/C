#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
	/*
	Tulostaa tiedon siitä, millä kaikilla kokonaislukutyypeillä 
	komentoriviparametrin luvut voidaan esittää. 
	*/
    int i = 0;
    bool prtd = false;
    int arvo;


    for (i = 1; i < argc; ++i) {
        arvo = atoi(argv[i]);
        printf("%d: ", arvo);

        if (arvo <= SCHAR_MAX && arvo >= SCHAR_MIN) {
            printf("signed char");
            prtd = true;
        }
        if (arvo <= UCHAR_MAX && arvo >= 0) {
            if (prtd) {
                printf(", ");
            }
            printf("unsigned char");
            prtd = true;
        }
        if (arvo <= SHRT_MAX && arvo >= SHRT_MIN) {
            if (prtd) {
                printf(", ");
            }
            printf("short int");
            prtd = true;
        }
        if (arvo <= USHRT_MAX && arvo >= 0) {
            if (prtd) {
                printf(", ");
            }
            printf("unsigned short int");
            prtd = true;
        }
        if (arvo <= INT_MAX && arvo >= INT_MIN) {
            if (prtd) {
                printf(", ");
            }
            printf("int");
            prtd = true;
        }
        printf("\n");
        prtd = false;
    }
    return 0;
}
