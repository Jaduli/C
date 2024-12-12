#ifndef YKKOSVALIT_H
#define YKKOSVALIT_H

struct UintPari {
    unsigned int x;
    unsigned int y;
};

typedef struct UintPari UintPari;

UintPari ykkosValit(const char *syoteNimi, const char *tulosNimi);

#endif
