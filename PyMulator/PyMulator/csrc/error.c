
#include <stdio.h>
#include <stdlib.h>

#define PP_STRING "COR"
#include "core/pretty_print.h"


void CORE_WARN_real(const char *f, int l, const char *msg) {
    WARN("%s:%d\t%s\n", f, l, msg);
}
