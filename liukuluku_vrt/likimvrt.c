#include <math.h>
#include "likimvrt.h"

double toleranssi = 0.000001;

double lueToleranssi() {
    return toleranssi;
}

void asetaToleranssi(double uusiToleranssi) {
    toleranssi = uusiToleranssi;
}

int doubleVrt(double a, double b) {
	// Vertaa, onko kaksi likulukuja sama luku voimassa olevalla toleranssilla.
	
    double tol = lueToleranssi();
    if (fabs(a-b) <= tol) {
        return 1;
    }
    return 0;
}
