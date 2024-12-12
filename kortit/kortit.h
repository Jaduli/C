#ifndef KORTIT_H
#define KORTIT_H

enum Maa {
    HERTTA = 1,
    RUUTU,
    RISTI,
    PATA
};

typedef enum Maa Maa;

enum Arvo {
    ASSA = 1,
    KAKKONEN,
    KOLMONEN,
    NELONEN,
    VIITONEN,
    KUUTONEN,
    SEISKA,
    KASI,
    YSI,
    KYMPPI,
    JATKA,
    ROUVA,
    KUNKKU
};

typedef enum Arvo Arvo;

enum {
    MAA_LKM = 4,
    MAA_KOKO = 13,
    KORTTI_LKM = MAA_LKM * MAA_KOKO
};

const char *MAIDEN_NIMET[MAA_LKM + 1];

const char *KORTTIEN_NIMET[MAA_KOKO + 1];

struct Kortti
{
    Maa maa;
    Arvo arvo;
};

typedef struct Kortti Kortti;

void tulostaKortti(Kortti kortti);

void tulostaKorttiOs(const Kortti *korttiOs);

#endif
