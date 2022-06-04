/*
 * This example shows how to create a basic command line program that sums
 * two integers given to it.
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "../src/argparse.h"

static const char *help_message =
    "Usage: isum FIRST SECOND [ --help | -h ]\n"
    "Sum two integers.\n"
    "\n"
    "Positional Arguments:\n"
    "\tfirst\t\tthe first integer\n"
    "\tsecond\t\tthe second integer\n"
    "\n"
    "Optional Arguments:\n"
    "\t--help, -h\t\tdisplay this message\n";

void sum_integers(const char *first, const char *second) {
    long x = 0;
    long y = 0;

    /* Convert the integers */
    x = strtol(first, NULL, 10);
    y = strtol(second, NULL, 10);

    /* Display the result */
    printf("%s + %s is %i.\n", first, second, x + y);
}

/*
 * Verify that the string provided is an integer. To pass this test, it
 * should consist of only digits until the NUL byte. Otherwise, this will
 * produce an error.
*/
void check_for_integerness(const char *string) {
    int index = 0;

    for(index = 0; string[index] != '\0'; index++) {
        if(isdigit(string[index]) != 0)
            continue;

        fprintf(stderr, "isum: '%s' is not an integer\n", string);
        fprintf(stderr, "%s", "Try 'isum --help' for more information.\n");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char **argv) {
    char *first = NULL;
    char *second = NULL;
    struct ArgparseParser parser = argparse_init("prog", argc, argv);

    /* Add two positional arguments to represent the numbers to add */
    argparse_add_argument(&parser, "first");
    argparse_add_argument(&parser, "second");

    /* Add some options the program can accept. */
    argparse_add_option(&parser, "--help", "-h", ARGPARSE_FLAG);

    /* Check for help */
    if(argparse_option_exists(parser, "--help") != ARGPARSE_NOT_FOUND ||
       argparse_option_exists(parser, "-h") != ARGPARSE_NOT_FOUND) {

        printf("%s", help_message);
        exit(EXIT_SUCCESS);
    }

    /* Do error checks */
    argparse_error(parser);

    /* Get the two numbers to sum */
    first = argparse_get_argument(parser, "first");
    second = argparse_get_argument(parser, "second");

    /* Verify they are integer-y */
    check_for_integerness(first);
    check_for_integerness(second);

    /* Sum the two integers */
    sum_integers(first, second);

    /* Release the argument parser from memory */
    argparse_free(parser);

    return 0;
}
