# TODO.md

## Error Conditions

# argparse_add_option
    - parser is NULL
    - name is NULL
    - parameters is a non-special negative integer
    - either of the names collide with themselves, or with any existing options
    - parser->options is NULL (add this to the docs of this)

# argparse_add_argument
    - parser is NULL
    - name is NULL
    - name is already an argument in the parser
    - parser->arguments is NULL (add this to the docs of this)

# argparse_init
    - argc is negative
    - argv is NULL

# argparse_count_real_parameters
    - option is NULL
    - parser.argv is NULL
    - parser.argc is negative
    - looking up an option that does not exist [x]

# argparse_option_argv_index
    - option is NULL
    - parser.argv is NULL
    - parser.argc is negative
    - option does not exist in the argv

# argparse_option_parser_index
    - option is NULL
    - parser.argv is NULL
    - parser.argc is negative

# unrecognized_options
    - parser.argv is NULL
    - parser.argc is negative
