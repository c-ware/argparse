/*
 * An example that demonstrates how to initialize, and release an argument
 * parser from memory.
*/

#include <stdio.h>
#include <stdlib.h>

#include "../src/argparse.h"

int main(int argc, char **argv) {
    /* Create a new argument parser with the program name 'prog' and
     * give it access to the argc and argv. */
    struct ArgparseParser parser = argparse_init("prog", argc, argv);

    argparse_free(parser);

    return 0;
}
