#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
	// Tulostaa tiedon, onko komentoriviparametrin merkkijono palindromi vai ei
	
    char word[50];
    int i = 0;
    int j = 0;
    int k = 0;
    bool pal = true;

    for (i = 1; i < argc; ++i) {
        pal = true;
        strcpy(word, argv[i]);

        for (j = 0; j < strlen(word); ++j) {
            word[j] = tolower(word[j]);
        }

        for (j = 0; j < strlen(word) / 2; ++j) {
            k = strlen(word) - 1 - j;
            if (word[j] != word[k]) {
                pal = false;
                break;
            }
        }
        if (pal) {
            printf("\"%s\": on palindromi\n", argv[i]);
        }
        else {
            printf("\"%s\": ei ole palindromi\n", argv[i]);
        }
    }
    return 0;
}
