#include <time.h>
#include <stdio.h>
#include <string.h>

int main() {
	// Tulostaa päivämäärän ja ajan.
	
    time_t a = time(NULL);
    struct tm *b = localtime(&a);
    char vpv[12];

    switch (b->tm_wday) {
    case 0:
        strcpy(vpv, "Sunnuntai");
        break;
    case 1:
        strcpy(vpv, "Maanantai");
        break;
    case 2:
        strcpy(vpv, "Tiistai");
        break;
    case 3:
        strcpy(vpv, "Keskiviikko");
        break;
    case 4:
        strcpy(vpv, "Torstai");
        break;
    case 5:
        strcpy(vpv, "Perjantai");
        break;
    case 6:
        strcpy(vpv, "Lauantai");
        break;
    }
    printf("%s %02d.%02d.%d klo %02d:%02d\n",
           vpv, b->tm_mday, b->tm_mon + 1,
           b->tm_year + 1900, b->tm_hour, b->tm_min);

    return 0;
}
