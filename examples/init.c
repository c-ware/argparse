/*
 * An example that demonstrates how to get a basic setup.
*/

#include <stdio.h>
#include <stdlib.h>

#include "../src/argparse.h"

int main(int argc, char **argv) {
    int index = 0;
    struct ArgparseParser parser = argparse_init("prog", argc, argv);

    argparse_variable_arguments(parser);
    argparse_add_argument(&parser, "foo");
    argparse_add_argument(&parser, "bar");
    argparse_add_option(&parser, "--foo", "-f", 1);
    argparse_add_option(&parser, "--bar", "-b", ARGPARSE_VARIABLE);
    argparse_add_option(&parser, "--qua", "-q", ARGPARSE_VARIABLE_ONE);
    argparse_add_repeatable_option(&parser, "--include", "-i");

    argparse_error(parser);

    argparse_repeatable_option_iter(parser, "-i", index) {
        const char *parameter = argparse_get_index(parser, index);

        printf("Parameter: %s\n", parameter);

    }

    argparse_free(parser);

    return 0;
}
