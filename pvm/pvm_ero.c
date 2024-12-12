#include <stdio.h>
#include <time.h>
#include <locale.h>
#include "pvm_ero.h"

// Operaatioita päivämäärän käsittelyä varten

int onko_karkausvuosi(int vuosi) {
    if ((vuosi % 4 == 0 && vuosi % 100 != 0) || (vuosi % 400 == 0)) {
        return 1;
    }
    return 0;
}

int onko_pvm_validi(int p, int k, int v) {
    int pv_lkm[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (onko_karkausvuosi(v)) {
        pv_lkm[1] = 29;
    }

    if (k < 1 || k > 12 || p < 1 || p > pv_lkm[k - 1]) {
        return 0;
    }
    return 1;
}

void pvm_ero(const char *pvm1, const char *pvm2) {
    int d1, m1, y1;
    int d2, m2, y2;
    unsigned int ero;
    struct tm p1 = {0};
    struct tm p2 = {0};
    time_t e1;
    time_t e2;
    char tul[80];

    setlocale(LC_TIME, "fi_FI.utf8");

    if (sscanf(pvm1, "%2d.%2d.%4d", &d1, &m1, &y1) != 3 || !onko_pvm_validi(d1, m1, y1)) {
        fprintf(stderr, "Parametri \"%s\" tai \"%s\" on laiton!\n", pvm1, pvm2);
        return;
    }
    if (sscanf(pvm2, "%2d.%2d.%4d", &d2, &m2, &y2) != 3 || !onko_pvm_validi(d2, m2, y2)) {
        fprintf(stderr, "Parametri \"%s\" tai \"%s\" on laiton!\n", pvm1, pvm2);
        return;
    }

    p1.tm_mday = d1;
    p1.tm_mon = m1 - 1;
    p1.tm_year = y1 - 1900;
    p1.tm_isdst = 0;

    e1 = mktime(&p1);

    p2.tm_mday = d2;
    p2.tm_mon = m2 - 1;
    p2.tm_year = y2 - 1900;
    p1.tm_isdst = 0;

    e2 = mktime(&p2);

    if (e2 > e1) {
        ero = difftime(e2, e1) / 60 / 60 / 24 + 1;
        strftime(tul, sizeof(tul), "%A %d.%m.%Y", &p1);
        printf("%s --> ", tul);
        strftime(tul, sizeof(tul), "%A %d.%m.%Y", &p2);
        printf("%s: yhteensä %d päivää\n", tul, ero);
    }
    else {
        ero = difftime(e1, e2) / 60 / 60 / 24 + 1;
        strftime(tul, sizeof(tul), "%A %d.%m.%Y", &p2);
        printf("%s --> ", tul);
        strftime(tul, sizeof(tul), "%A %d.%m.%Y", &p1);
        printf("%s: yhteensä %d päivää\n", tul, ero);
    }


}
