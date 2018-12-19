#include <ke/cdef.h>
#include <ke/assert.h>
#include <ke/print.h>

void kassert_ex(const char *expr_str, const char *file, int32 line, int32 expr)
{
    if (!expr)
    {
        ke_printf("Assertion \"%s\" failed at %s:%d.\n", expr_str, file, line);

    }
}
