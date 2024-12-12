#include <stdio.h>
#include <stdbool.h>
#include "murtoluku.h"

// Operaatioita murtolukujen laskuja varten.

Murtoluku tee_murtoluku(int os, int nim) {
    Murtoluku ml;
    ml.os = os;
    ml.nim = nim;
    return ml;
}

Murtoluku supistettuML(int os, int nim) {
    int iso;
    int pieni;
    int temp;
    bool neg = false;

    if (os == 0 || nim == 0) {
        return tee_murtoluku(os, nim);
    }

    if (nim < 0 && os < 0) {
        nim = nim * (-1);
        os = os * (-1);
        neg = false;
    }
    else if (nim < 0) {
        nim = nim * (-1);
        neg = true;
    }
    else if (os < 0) {
        os = os * (-1);
        neg = true;
    }

    if (os > nim) {
        iso = os;
        pieni = nim;
    }
    else {
        iso = nim;
        pieni = os;
    }

    while (iso != pieni) {
        iso = iso - pieni;

        if (iso < pieni) {
            temp = pieni;
            pieni = iso;
            iso = temp;
        }
    }
    if (neg) {
        return tee_murtoluku(os / iso * (-1), nim / iso);
    }
    return tee_murtoluku(os / iso, nim / iso);

}

Murtoluku lisaaML(Murtoluku a, Murtoluku b) {
    int os1 = a.os;
    int os2 = b.os;
    int nim1 = a.nim;
    int nim2 = b.nim;
    int nos;

    os1 = os1 * nim2;
    os2 = os2 * nim1;

    nim1 = nim1 * nim2;
    nim2 = nim2 * nim1;

    nos = os1 + os2;

    return supistettuML(nos, nim1);
}

Murtoluku vahennaML(Murtoluku a, Murtoluku b) {
    int os1 = a.os;
    int os2 = b.os;
    int nim1 = a.nim;
    int nim2 = b.nim;
    int nos;

    os1 = os1 * nim2;
    os2 = os2 * nim1;

    nim1 = nim1 * nim2;

    nos = os1 - os2;

    return supistettuML(nos, nim1);
}

Murtoluku kerroML(Murtoluku a, Murtoluku b) {
    int os1 = a.os;
    int os2 = b.os;
    int nim1 = a.nim;
    int nim2 = b.nim;

    return supistettuML(os1 * os2, nim1 * nim2);
}

Murtoluku jaaML(Murtoluku a, Murtoluku b) {
    int os1 = a.os;
    int os2 = b.os;
    int nim1 = a.nim;
    int nim2 = b.nim;

    return supistettuML(os1 * nim2, nim1 * os2);
}

void tulostaML(Murtoluku ml) {
    if (ml.os == 0) {
        printf("%d", 0);
    }
    else if (ml.os % ml.nim == 0){
        printf("%d", ml.os / ml.nim);
    }
    else {
        printf("%d/%d", ml.os, ml.nim);
    }
}
