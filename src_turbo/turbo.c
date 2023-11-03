#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <unistd.h>
#include <math.h>
#include <string.h>

typedef unsigned int  uint;
typedef unsigned long ulong;

/*** v UTILS v ***/

uint size(ulong n) {
    uint sz = 0;

    while (n > 0) {
        n /= 10;
        sz++;
    }
    return sz;
}
uint nbhead(ulong n) {
    while (n > 9) n /= 10;
    return n;
}
ulong nbtail(ulong n) {
    return n - nbhead(n) * pow(10, size(n) - 1);
}
char *strtail(char *s) {
    return &(s[1]);
}
char *strhead(char *s) {
    char *head = malloc(sizeof(char) * 2);
    head[0] = s[0];
    head[1] = '\0';
    return head;
}

/*** v RESULT v ***/

char *strrev(char *s) {
    uint sz = strlen(s);
    char tmp;

    for (uint i = 0; i < sz / 2; i++) {
        tmp = s[i];
        s[i] = s[sz - i - 1];
        s[sz - i - 1] = tmp;
    }
    return s;
}
char *push_back(char *s, char c) {
    uint sz = 0;
    char *new = NULL;

    if (s) sz = strlen(s);
    new = malloc(sizeof(char) * (sz + 2));
    for (uint i = 0; i < sz; i++)
        new[i] = s[i];
    new[sz] = c;
    new[sz + 1] = '\0';
    if (s) free(s);
    return new;

}

char *ltos(ulong n) {
    char *s = NULL;
    uint i = 0;

    for (uint sz = size(n); i < sz; i++) {
        s = push_back(s, n % 10 + '0');
        n /= 10;
    }
    return strrev(s);
}

char *get_result(long c, uint nexp, uint limit, uint precision) {
    char *stringified = ltos(c), *limit_str = ltos(limit),
        *head = NULL, *tail = strtail(stringified),
        *result = NULL;

    head = strhead(stringified);
    result = malloc(sizeof(char) * (strlen(stringified) + strlen(limit_str) + 3));
    strcpy(result, head); strcat(result, "."); strcat(result, tail);
    strcat(result, "e"); strcat(result, limit_str);
    result[strlen(stringified) + strlen(limit_str) + 2] = '\0';
    free(head); free(limit_str); free(stringified);
    return result;
}

/*** v CORE v ***/

char *fib_turbo(uint exp_limit, uint precision) {
    ulong a = 0, b = 1, c;
    uint exp = 0, nexp = 0;
    uint nth = 2;

    for (; exp < exp_limit; nth++) {
        c = a + b; a = b; b = c;
        exp  += (size(c) > size(a));
        nexp += (size(b) > precision);
        a /= (1 + 9 * (size(b) > precision));
        b /= (1 + 9 * (size(b) > precision));
    }
    printf("  F(%u)\t=\t", nth);
    return get_result(c, nexp, exp_limit, precision);
}

int main(int ac, char **av) {
    int exp_limit = 100;
    int precision = 15;
    char *res = NULL;

    if (ac > 1) exp_limit = atoi(av[1]);
    if (ac > 2) precision = atoi(av[2]);
    if (exp_limit < 1 || precision < 1 || precision > 15) {
        printf("Usage: %s [exp_limit > 0] [16 > precision > 0]\n", av[0]);
        printf("Default: exp_limit = 100, precision = 15\n");
        printf("You provided: limit = %d, precision = %d\n", exp_limit, precision);
        return 84;
    }
    res = fib_turbo(exp_limit, precision);
    printf("%s\n", res);
    free(res);
    printf("Calculations done.\n");
    return 0;
}