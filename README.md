# argparse

A basic command line argument parser written for C. Pretty much fully documented
and ready to go. Comes with these features:
    - Variable number of positional arguments
    - Variable number of parameters to options
    - Repeatable options (similar to -L and -I in GCC) that can be 'collected'
    - Iterators for variable positional arguments, parameters to repetable options,
      as well as both fixed and variable option parameters
    - Error checking for number of parameters, unrecognized options, too many and
      too few positional arguments.
    - Extracting individual positional arguments
    - Getting an individual parameter to an option

It should be noted however, this library does not tackle the creation of help
messages. This is mostly to simplify the desgin of the library. However, you can
find examples on writing your own logic for displaying help messages, as well as
how to write a basic program with argparse, in `examples/isum.c`
