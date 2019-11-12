/*
** PERSONAL PROJECT, 2019
** fibonacci
** File description:
** fibonacci detectors
*/

#include <stdlib.h>
#include "../include/fib.h"
#include "../include/my.h"

uint adjust(char *optarg, uint val)
{
    for (int i = 0; optarg[i]; i++)
        if (optarg[i] != '0' && val == 0)
            return (MAX);
    return (val);
}

static int istrcmp(char *number, char *limit)
{
    if (my_strlen(number) < my_strlen(limit))
        return (-1);
    if (my_strlen(number) > my_strlen(limit))
        return (1);
    for (int i = 0; number[i] && limit[i]; i++) {
        if (number[i] > limit[i])
            return (1);
        else if (number[i] < limit[i])
            return (-1);
    }
    return (0);
}

int end_exceeded(char *number, uint limit)
{
    char *nlimit = NULL;

    if (!limit)
        return (FALSE);
    nlimit = my_utoa(limit);
    if (istrcmp(number, nlimit) >= 0) {
        free(nlimit);
        return (TRUE);
    }
    free(nlimit);
    return (FALSE);
}

int digits_ok(uint *settings, char *nb)
{
    if (!nb)
        return (TRUE);
    if (my_strlen(nb) >= settings[DIGITS])
        return (FALSE);
    return (TRUE);
}
