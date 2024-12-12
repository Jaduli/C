#include <stdio.h>
#include <string.h>
#include "muunto.h"

int main(int argc, char *argv[])
{
    int i = 0;
    char sana[300] = "";

    for (i = 1; i < argc; ++i) {
        sprintf(sana, argv[i]);
        printf("%d: %s --> ", i, sana);
        muunna(sana);
        printf("%s\n", sana);
    }
    return 0;
}
