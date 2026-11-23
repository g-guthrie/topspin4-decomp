/* nearmiss: 0 off as C++ member ?SetString@Ts4WStr@@QAAXPBGH@Z (plain, /Oc: MATCH);
 * 1 off (+0x80 sthx operand order) as extern "C" free function.
 * Concrete blocker: fn_8819C360 is referenced from C sources (hs1_d.c, fam5_nm6_000.c,
 * q5s_cont_strings.cpp extern "C"), so the matching mangled member name cannot be
 * integrated without renaming those callers (needs coordinator decision / tool alias).
 * Check: fn_check.py <this> "?SetString@Ts4WStr@@QAAXPBGH@Z=0x8819C360" --flags /Oc */
#include "../include/ts4/ts4.h"
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
