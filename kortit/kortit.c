#include <stdio.h>
#include "kortit.h"

const char *MAIDEN_NIMET[MAA_LKM + 1] = {"", "Hertta", "Ruutu",
                                         "Risti", "Pata"};

const char *KORTTIEN_NIMET[MAA_KOKO + 1] = {"", "ässä", "kakkonen",
                                         "kolmonen", "nelonen",
                                         "viitonen", "kuutonen", "seiska",
                                         "kasi", "ysi", "kymppi",
                                         "jätkä", "rouva", "kunkku"};

void tulostaKortti(Kortti kortti) {
    printf("%s%s", MAIDEN_NIMET[kortti.maa], KORTTIEN_NIMET[kortti.arvo]);
}

void tulostaKorttiOs(const Kortti *korttiOs) {
    printf("%s%s", MAIDEN_NIMET[korttiOs->maa],
           KORTTIEN_NIMET[korttiOs->arvo]);
}

