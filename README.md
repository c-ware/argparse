# argparse

A basic command line argument parser written for C. Pretty much fully documented
and ready to go. Comes with these features:
</br>
    - Variable number of positional arguments
</br>
    - Variable number of parameters to options
</br>
    - Repeatable options (similar to -L and -I in GCC) that can be 'collected'
</br>
    - Iterators for variable positional arguments, parameters to repetable options,
</br>
      as well as both fixed and variable option parameters
</br>
    - Error checking for number of parameters, unrecognized options, too many and
</br>
      too few positional arguments.
</br>
    - Extracting individual positional arguments
</br>
    - Getting an individual parameter to an option
</br>

It should be noted however, this library does not tackle the creation of help
messages. This is mostly to simplify the desgin of the library. However, you can
find examples on writing your own logic for displaying help messages, as well as
how to write a basic program with argparse, in `examples/isum.c`
