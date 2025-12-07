#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <getopt.h>
#include <mupdf/fitz.h>
#include <gtk/gtk.h>
#include "flags.c"
#include "pdfRendering.c"

int main(int argc, char *argv[]) {
    //handle args for split logic and path
    struct pdfFlags pdfArgs = handleFlags(argc, argv);

    return 0;
}
