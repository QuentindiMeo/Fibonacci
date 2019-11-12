/*
** PERSONAL PROJECT, 2019
** fibonacci
** File description:
** fibonacci reading functions
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"

static char *get_number(char *str)
{
    int i = my_strlen(str) - 1;
    int j;
    char *number = NULL;

    if (str[my_strlen(str) - 1] == '\n')
        i--;
    j = i;
    for (; i && str[i] >= '0' && str[i] <= '9'; i--);
    if (str[my_strlen(str) - 1] == '\n')
        j = my_strlen(str) - 2;
    i++;
    number = my_cut_str(str, i, j);
    return (number);
}

static char *get_nth(char *str)
{
    char *n_th = NULL;
    uint i = 5;

    for (; str[i] >= '0' && str[i] <= '9'; i++);
    n_th = my_cut_str(str, 5, i - 1);
    if ((*n_th) == '1' && my_strlen(n_th) == 1)
        n_th[my_strlen(n_th) - 1] += 1;
    return (n_th);
}

char *my_charadd(char *str, char const c)
{
    char *temp = NULL;
    uint len = 0;

    if (!str) {
        str = malloc(sizeof(char) * 2);
        str[0] = c;
        str[1] = 0;
        return (str);
    }
    temp = my_strdup(str);
    len = my_strlen(str);
    free(str);
    str = malloc(sizeof(char) * (len + 2));
    my_strcpy(str, temp);
    my_charcat(str, c);
    return (str);
}

char *read_last_line(int id)
{
    char *response = NULL;
    char *buff = NULL;
    FILE *stream = fopen("calculations_fib.txt", "r");
    char stk = 0;
    ssize_t ret_v = 1;

    if (!stream)
        return (id == 1 ? my_strdup("2") : my_strdup("0"));
    ret_v = fread(&stk, 1, 1, stream);
    while (ret_v) {
        while (stk != '\n' && ret_v) {
            buff = my_charadd(buff, stk);
            ret_v = fread(&stk, 1, 1, stream);
        }
        ret_v = fread(&stk, 1, 1, stream);
        if (buff != NULL && ret_v)
            free(buff);
        buff = my_charadd(buff, stk);
    }
    response = (id == 1) ? get_nth(buff) : get_number(buff);
    printf("response:\"%s\"\n", response);
    free(buff);
    fclose(stream);
    return (response);
}
