/*
** PERSONAL PROJECT, 2018
** fibonacci
** File description:
** fibonacci headers
*/

#ifndef FIBONACCI_H_
#define FIBONACCI_H_

typedef struct set_s {
    unsigned int start;
    char *       end;
    unsigned int find;
    unsigned int digits;
    unsigned int slow;
    unsigned int until;
    unsigned int silent;
    unsigned int store;
    unsigned int turbo;
    unsigned int precision;
} set_t;

typedef enum {
    START  = 0, OSTART = 'S',
    END    = 1, OEND = 'E',
    FIND   = 2, OFIND = 'F',
    DIGITS = 3, ODIGITS = 'd',
    SLOW   = 4, OSLOW = 's',
    UNTIL  = 5, OUNTIL = 'u',
    SILENT = 6, OSILENT = '-',
    STORE  = 7, OSTORE = 'D',
    TURBO  = 8, OTURBO = 't',
    PRECI  = 9, OPRECI = 'p',
} settings_id_t;

typedef enum {
    MAX = 2147483647,
} default_t;

int end_exceeded(char *number, char *limit);
int digits_ok(set_t *settings, char *nb);

void write_result(unsigned int nth, char *nb, set_t *settings);

char *read_last_line(int id);

unsigned int adjust(char *optarg, unsigned int val);
int get_settings(int ac, char **av, set_t *settings);
set_t *setup(void);

int help(void);

#endif
