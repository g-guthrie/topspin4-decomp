/* Loader_DLL.xex 0x8316F448-0x8316F4C8, executable version 0.0.0.3. */
#ifdef _MSC_VER
extern "C" int memcmp(const void *, const void *, unsigned);
#pragma intrinsic(memcmp)
#else
#include <string.h>
#endif
struct L46QI { virtual void s0(); virtual long AddRef(); };
extern "C" unsigned char lbl_830081B0[16];

extern "C" long ts4l_query_interface_8316F448(L46QI *self, const unsigned char *riid, void **ppv)
{
    int d;
    d = memcmp(riid, lbl_830081B0, 16);
    if (d == 0) {
        *ppv = self;
        self->AddRef();
        return 0;
    }
    *ppv = 0;
    return (long)0x80004002;
}
