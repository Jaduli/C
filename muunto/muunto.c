#include <ctype.h>
#include <string.h>
#include "muunto.h"

void muunna(char mj[]) {
	/*
	Muuntaa merkkijonon isot kirjaimet pieniksi ja pienet isoiksi,
	sekä kääntää merkkijonon takaperin. 
	*/
	
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int length = strlen(mj);
    char merkki;

    for (i = 0; i < length; ++i) {
        if (islower(mj[i])) {
            mj[i] = toupper(mj[i]);
        }
        else {
            mj[i] = tolower(mj[i]);
        }
    }
    for (i = 0; i < length / 2; ++i) {
        j = length - 1 - i;
        merkki = mj[i];
        mj[i] = mj[j];
        mj[j] = merkki;
    }
}
