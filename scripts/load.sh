#!/bin/sh
# Process all files with m4 and output them to their respective directories.

# Process and generate all manual pages
docgen project ./src/argparse.h --section 'cware'            \
                                --title 'C-Ware Manuals'     \
                                --date "`date +'%b %d, %Y'`" \
                                --include 'argparse.h'

docgen functions ./src/argparse.h --section 'cware'            \
                                  --title 'C-Ware Manuals'     \
                                  --date "`date +'%b %d, %Y'`" \
                                  --include 'argparse.h'

docgen category ./src/ap_inter.h --section 'cware'            \
                                 --title 'C-Ware Manuals'     \
                                 --date "`date +'%b %d, %Y'`" \
                                 --include 'argparse.h'

docgen functions ./src/ap_inter.h --section 'cware'            \
                                  --title 'C-Ware Manuals'     \
                                  --date "`date +'%b %d, %Y'`"

# Process the Makefile
m4 ./template/Makefile > ./Makefile
