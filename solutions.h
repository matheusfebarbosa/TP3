#include <stdlib.h>
#include <stdio.h>
#include "internal_sorting.h"

int dinamico(Edge *flagLines, int n);
int guloso(Edge *flagLines, int n);
int forca_bruta(Edge *flagLines, int n);
int try_options(Edge *flagLines, int *options, int i, int n);