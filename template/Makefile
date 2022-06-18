# This Makefile is the output of a template Makefile that was
# processed by the m4 macro preprocessor. It is not intended
# to be human readable.

CC=cc
PREFIX=/usr/local
CFLAGS=
OBJS=syscmd(`find src/ -type f -name "*.c" | tr "\n" " " | sed "s/\.c/.o/g"')
TESTS=syscmd(`find tests/ -type f -name "*.c" | tr "\n" " " | sed "s/\.c/.out/g"')
EXAMPLES=syscmd(`find examples/ -type f -name "*.c" | tr "\n" " " | sed "s/\.c/.out/g"')
DOCS=syscmd(`find . -type f -name "*.cware" | tr "\n" " "')
MANNAMES=syscmd(`for src in $(find . -type f -name "*.cware"); do echo $src | xargs basename; done | tr "\n" " "')
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
