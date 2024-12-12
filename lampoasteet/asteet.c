#include "asteet.h"

float muunna(Lampotila a, Asteikko b) {
	// Muuntaa lämpötilan annettuun asteikkoon.
	
    float lam;

    if (a.asteikko == b) {
        return a.lampotila;
    }
    else if (a.asteikko == Celsius && b == Fahrenheit) {
        return a.lampotila*1.8+32;
    }
    else if (a.asteikko == Fahrenheit && b == Celsius) {
        return (a.lampotila-32)/1.8;
    }
    else if (a.asteikko == Kelvin && b == Celsius) {
        return a.lampotila-273.15;
    }
    else if (a.asteikko == Celsius && b == Kelvin) {
        return a.lampotila+273.15;
    }
    else if (a.asteikko == Fahrenheit && b == Kelvin) {
        lam = muunna(a, Celsius);
        return lam+273.15;
    }
    else if (a.asteikko == Kelvin && b == Fahrenheit){
        lam = muunna(a, Celsius);
        return lam*1.8+32;
    }
    return -1;
}

float erotus(Lampotila a, Lampotila b, Asteikko c) {
	// Laskee kahden lämpötilan erotuksen annetulla asteikolla.
	
    float lam;

    lam = muunna(a, c) - muunna(b, c);

    return lam;
}
