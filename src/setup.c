/*
** PERSONAL PROJECT, 2019
** fibonacci
** File description:
** fibonacci settings setup
*/

#include <stdlib.h>
#include <getopt.h>
#include "../include/fib.h"
#include "../include/my.h"

static uint limit_slow(int slow)
{
    if (slow > 100000000)
        return (0);
    return (slow);
}

static char *do_switch(char c, char *optarg, set_t **settings)
{
    switch (c) {
    case ODIGITS :
        (*settings)->digits = adjust(optarg, my_atou(optarg));
        break;
    case OEND :
        (*settings)->end = my_strdup(optarg);
        break;
    case OFIND :
        (*settings)->find = my_atou(optarg);
        break;
    case OSILENT :
        (*settings)->silent = 1;
        break;
    case OSLOW :
        (*settings)->slow = limit_slow(my_atou(optarg) * 1000);
        break;
    case OSTART :
        (*settings)->start = my_atou(optarg);
        break;
    case OSTORE :
        (*settings)->store = 1;
        break;
    case OUNTIL :
        (*settings)->until = adjust(optarg, my_atou(optarg));
        break;
    case '?' :
        my_putstr("Try './fibonacci --help' for more information.\n");
        return (NULL);
        break;
    }
    return ("-");
}

static void set_longopts(struct option **longopts)
{
    (*longopts)[0].name = "digits";
    (*longopts)[0].has_arg = 1;
    (*longopts)[0].flag = NULL;
    (*longopts)[0].val = ODIGITS;
    (*longopts)[1].name = "end";
    (*longopts)[1].has_arg = 1;
    (*longopts)[1].flag = NULL;
    (*longopts)[1].val = OEND;
    (*longopts)[2].name = "find";
    (*longopts)[2].has_arg = 1;
    (*longopts)[2].flag = NULL;
    (*longopts)[2].val = OFIND;
    (*longopts)[3].name = "start";
    (*longopts)[3].has_arg = 1;
    (*longopts)[3].flag = NULL;
    (*longopts)[3].val = OSTART;
    (*longopts)[4].name = "slow";
    (*longopts)[4].has_arg = 1;
    (*longopts)[4].flag = NULL;
    (*longopts)[4].val = OSLOW;
    (*longopts)[5].name = "until";
    (*longopts)[5].has_arg = 1;
    (*longopts)[5].flag = NULL;
    (*longopts)[5].val = OUNTIL;
    (*longopts)[6].name = "silent";
    (*longopts)[6].has_arg = 0;
    (*longopts)[6].flag = NULL;
    (*longopts)[6].val = OSILENT;
    (*longopts)[7].name = "store";
    (*longopts)[7].has_arg = 0;
    (*longopts)[7].flag = NULL;
    (*longopts)[7].val = OSTORE;
}

int get_settings(int ac, char **av, set_t *settings)
{
    struct option *longopts = malloc(sizeof(struct option) * 8);

    set_longopts(&longopts);
    for (char c = 0; c != END_OF_ARGS;) {
        c = getopt_long(ac, av, "d:u:E:F:S:", longopts, NULL);
        if (do_switch(c, optarg, &settings) == NULL) {
            free(longopts);
            if (settings->end)
                free(settings->end);
            free(settings);
            return (FAILURE);
        }
    }
    free(longopts);
    return (SUCCESS);
}

set_t *setup(void)
{
    set_t *settings = malloc(sizeof(set_t));

    settings->start = 0;
    settings->end = NULL;
    settings->find = 0;
    settings->digits = MAX;
    settings->slow = 0;
    settings->until = MAX;
    settings->silent = 0;
    settings->store = 0;
    return (settings);
}
