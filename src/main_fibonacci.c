/*
** PERSONAL PROJECT, 2019
** fibonacci
** File description:
** main fibonacci
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/fib.h"
#include "../include/my.h"

static void free3(char *s1, char *s2, char *s3)
{
    if (s1)
        free(s1);
    if (s2)
        free(s2);
    if (s3)
        free(s3);
}

static char *addup(char *s2, char *n1)
{
    char *n2 = my_revstr(s2);
    char *add = malloc(sizeof(char) * (my_strlen(n2) + 2));
    uchar c;
    char carry = 0;
    uint j = 0;

    for (uint k = 0; k != my_strlen(n2) + 2; k++)
        add[k] = 0;
    for (uint i = 0; n2[i]; i++) {
        c = ctoi(n2[i]) + (n1[i] ? ctoi(n1[i]) : 0) + carry;
        carry = (c > 9) ? 1 : 0;
        if (c > 9)
            c %= 10;
        add[j] += itoc(c);
        j++;
    }
    if (carry)
        add[j] += (add[j] ? carry : '1');
    return (add);
}

static char *fibonacci(char **n1, char **n2, char *n3)
{
    if (n3 != NULL)
        free(n3);
    n3 = addup(*n2, *n1);
    if ((*n1) != NULL)
        free((*n1));
    (*n1) = my_strdup(*n2);
    if ((*n2) != NULL)
        free((*n2));
    (*n2) = my_strdup(my_revstr(n3));
    return (n3);
}

static void fibonacci_loop(uint *settings)
{
    char *n3 = my_strdup("0\0");
    char *n2 = my_strdup("1\0");
    char *n1 = my_strdup("0\0");

    write_result(0, n1, settings);
    write_result(1, n2, settings);
    for (uint nth = 2; nth <= settings[UNTIL]; nth++) {
        n3 = fibonacci(&n1, &n2, n3);
        if (!digits_ok(settings, n3) || end_exceeded(n3, settings[END]))
            break;
        write_result(nth, n3, settings);
    }
    free3(n1, n2, n3);
    printf("Calculations done.\n");
}

static void fibonacci_find(uint max)
{
    char *n3 = my_strdup("0\0");
    char *n2 = my_strdup("1\0");
    char *n1 = my_strdup("0\0");

    if (max >= 7000)
        printf("This may take a while...\n");
    for (uint nth = 2; nth < max; nth++)
        n3 = fibonacci(&n1, &n2, n3);
    n3 = fibonacci(&n1, &n2, n3);
    printf("  F(%u)\t%c=\t%s\n", max, max > 99 ? '\0' : '\t', n3);
    free3(n1, n2, n3);
    printf("Calculations done.\n");
}

int main(int ac, char **av)
{
    uint *settings;

    if (ac == 2 &&
        (my_str_isequal(av[1], "-h") || my_str_isequal(av[1], "--help")))
        return (help());
    settings = setup();
    if (get_settings(ac, av, settings) == FAILURE)
        return (FAILURE);
    if (settings[FIND] != 0)
        fibonacci_find(settings[FIND]);
    else {
        remove("calculations_fib.txt");
        fibonacci_loop(settings);
    }
    free(settings);
    return (0);
}
