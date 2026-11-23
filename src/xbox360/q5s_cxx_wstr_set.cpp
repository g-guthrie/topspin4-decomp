/* 0x8819C360: Ts4WStr::SetString(src, n): replace the contents of a shared wide string with n UTF-16 units.
 * n == 0 drops the shared buffer; else the buffer is made writable for n units (0x8819C528) and filled:
 * with a memmove when src lies inside the old contents, else with an inline memcpy.
 * It matches only as a C++ member (`this` is numbered differently from a first parameter: as an extern "C"
 * function the last sthx has its operands swapped). symbols.txt therefore holds the decorated name
 * ?SetString@Ts4WStr@@QAAXPBGH@Z; C sources call it as ts4_wstr_set_string_8819C360, its reviewed "cxx"
 * alias (config/54540859/icf_aliases.json, docs/ltcg-route.md section 12). */
#include "include/ts4/ts4.h"
#ifdef _MSC_VER
extern "C" void *memcpy(void *, const void *, unsigned int);
#pragma intrinsic(memcpy)
#else
#include <string.h>
#endif
struct Ts4WStr;
extern "C" void ts4_wstring_unshare_8819C2D8(Ts4WStr *self);
extern "C" unsigned short *fn_8819C528(Ts4WStr *self, int n);
extern "C" void fn_88562DC0(void *dst, const void *src, unsigned int n);
struct Ts4WStr {
    unsigned short *data;
    Ts4StrHdr *hdr() const { return (Ts4StrHdr *)data - 1; }
    int length() const { return hdr()->length; }
    void SetString(const unsigned short *src, int n);
};
void Ts4WStr::SetString(const unsigned short *src, int n)
{
    if (n == 0) {
        ts4_wstring_unshare_8819C2D8(this);
    } else {
        unsigned int old_len = length();
        unsigned int off = src - data;
        unsigned short *buf = fn_8819C528(this, n);
        if (off <= old_len)
            fn_88562DC0(buf, buf + off, n * sizeof(unsigned short));
        else
            memcpy(buf, src, n * sizeof(unsigned short));
        hdr()->length = n;
        data[n] = 0;
    }
}
