# This Makefile is the output of a template Makefile that was
# processed by the m4 macro preprocessor. It is not intended
# to be human readable.

CC=cc
PREFIX=/usr/local
CFLAGS=
OBJS=src/ap_inter.o src/extract.o src/argparse.o 
TESTS=
EXAMPLES=examples/isum.out examples/init.out 
DOCS=./doc/argparse_option_parameter_start.cware ./doc/argparse_option_argv_index.cware ./doc/argparse_repeatable_option_start.cware ./doc/argparse_option_parameter_stop.cware ./doc/argparse_error.cware ./doc/argparse_parameter_count.cware ./doc/argparse_get_argument.cware ./doc/argparse_free.cware ./doc/argparse_argument_variable_start.cware ./doc/argparse_init.cware ./doc/argparse_unrecognized_options.cware ./doc/argparse_is_option.cware ./doc/argparse_option_exists.cware ./doc/argparse_get_option_parameter.cware ./doc/argparse.cware ./doc/argparse_count_argv_parameters.cware ./doc/argparse_count_arguments.cware ./doc/argparse_count_parser_parameters.cware ./doc/argparse_repeatable_parameter_count.cware ./doc/argparse-internal.cware ./doc/argparse_add_argument.cware ./doc/argparse_argument_count.cware ./doc/argparse_add_option.cware ./doc/argparse_option_parser_index.cware ./doc/argparse_argument_variable_next.cware ./doc/argparse_add_repeatable_option.cware 
MANNAMES=argparse_option_parameter_start.cware argparse_option_argv_index.cware argparse_repeatable_option_start.cware argparse_option_parameter_stop.cware argparse_error.cware argparse_parameter_count.cware argparse_get_argument.cware argparse_free.cware argparse_argument_variable_start.cware argparse_init.cware argparse_unrecognized_options.cware argparse_is_option.cware argparse_option_exists.cware argparse_get_option_parameter.cware argparse.cware argparse_count_argv_parameters.cware argparse_count_arguments.cware argparse_count_parser_parameters.cware argparse_repeatable_parameter_count.cware argparse-internal.cware argparse_add_argument.cware argparse_argument_count.cware argparse_add_option.cware argparse_option_parser_index.cware argparse_argument_variable_next.cware argparse_add_repeatable_option.cware 
DEBUGGER=

all: $(OBJS) $(EXAMPLES)

clean:
	rm -f $(TESTS)
	rm -f $(OBJS)
	rm -f $(EXAMPLES)

check:
	./scripts/check.sh $(DEBUGGER)

install:
	for manual in $(MANNAMES); do					  \
		cp doc/$$manual $(PREFIX)/share/man/mancware; \
	done

uninstall:
	for manual in $(MANNAMES); do					 \
		rm -f $(PREFIX)/share/man/mancware/$$manual; \
    done

.c.o:
	$(CC) -c $< $(CFLAGS) -o $@

.c.out:
	$(CC) $< $(OBJS) $(CFLAGS) -o $@
