#include "../type.h"
#include "../kdef.h"
#include "mem.h"

void NATIVE64 mem_copy(void *src, void *dst, uint64_t size)
{
    if (src == NULL || dst == NULL)
        return;
    char* cSrc = (char*)src;
    char* cDst = (char*)dst;
    while (size--)
        *(cDst++) = *(cSrc++);
    return;
}

void NATIVE64 mem_set(void *src, int8_t const val, uint64_t size)
{
    if (src == NULL)
        return;
    while (size--)
        *((int8_t*)src++) = val;
    return;
}

void NATIVE64 mem_move(void *src, void *dst, uint64_t size)
{
    if (src == NULL || dst == NULL)
        return;
    if (src >= dst)
    {
        return mem_copy(src, dst, size);
    }
    src += size;
    dst += size;
    while (size--)
        *((char*)--dst) = *((char*)--src);
    return;
}
