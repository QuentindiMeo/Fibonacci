/*
** PERSONAL PROJECT, 2018
** fibonacci
** File description:
** fibonacci headers
*/

#ifndef FIBONACCI_H_
#define FIBONACCI_H_

struct set_s {
    unsigned int start;
    char *end;
    unsigned int find;
    unsigned int digits;
    unsigned int slow;
    unsigned int until;
    unsigned int silent;    
    unsigned int store;
};
typedef struct set_s set_t;

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

int end_exceeded(char *number, char *limit);
int digits_ok(set_t *settings, char *nb);

void write_result(unsigned int nth, char *nb, set_t *settings);

char *read_last_line(int id);

unsigned int adjust(char *optarg, unsigned int val);
int get_settings(int ac, char **av, set_t *settings);
set_t *setup(void);

int help(void);

#endif
