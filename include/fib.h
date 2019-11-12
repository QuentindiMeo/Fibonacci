/*
** PERSONAL PROJECT, 2018
** fibonacci
** File description:
** fibonacci headers
*/

#ifndef FIBONACCI_H_
#define FIBONACCI_H_

typedef enum {
    START = 0,
    END = 1,
    FIND = 2,
    DIGITS = 3,
    SLOW = 4,
    UNTIL = 5,
    SILENT = 6,
    STORE = 7,
    OSTART = 'S',
    OEND = 'E',
    OFIND = 'F',
    ODIGITS = 'd',
    OSLOW = 's',
    OUNTIL = 'u',
    OSILENT = '-',
    OSTORE = 'D',
} settings_id_t;

typedef enum {
    MAX = 2147483647,
} default_t;

int end_exceeded(char *number, unsigned int limit);
int digits_ok(unsigned int *settings, char *nb);

void write_result(unsigned int nth, char *nb, unsigned int *settings);

char *read_last_line(int id);

unsigned int adjust(char *optarg, unsigned int val);
int get_settings(int ac, char **av, unsigned int *settings);
unsigned int *setup(void);

int help(void);

#endif
