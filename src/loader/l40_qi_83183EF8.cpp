/* Loader_DLL.xex 0x83183EF8-0x83183F8C, 0x83184570-0x83184604, 0x83186640-0x831866D4, 0x83186C48-0x83186CDC, 0x83187D68-0x83187DFC, 0x8316F7D0-0x8316F870, executable version 0.0.0.3. */
#ifdef _MSC_VER
extern "C" int memcmp(const void *, const void *, unsigned);
#pragma intrinsic(memcmp)
#else
#include <string.h>
#endif
struct L40QI { virtual void s0(); virtual long AddRef(); };
extern "C" unsigned char lbl_830088B4[16];
extern "C" unsigned char lbl_830088A4[16];
extern "C" long fn_83182CE8(L40QI *, const unsigned char *, void **);

extern "C" long ts4l_query_interface_83183EF8(L40QI *self, const unsigned char *riid, void **ppv)
{
    long hr;
    int d;
    hr = 0;
    d = memcmp(riid, lbl_830088B4, 16);
    if (d == 0) {
        *ppv = self ? (void *)((char *)self + 0x20) : 0;
        self->AddRef();
    } else {
        hr = fn_83182CE8(self, riid, ppv);
    }
    return hr;
}

extern "C" long ts4l_query_interface_83184570(L40QI *self, const unsigned char *riid, void **ppv)
{
    long hr;
    int d;
    hr = 0;
    d = memcmp(riid, lbl_830088B4, 16);
    if (d == 0) {
        *ppv = self ? (void *)((char *)self + 0x20) : 0;
        self->AddRef();
    } else {
        hr = fn_83182CE8(self, riid, ppv);
    }
    return hr;
}

extern "C" long ts4l_query_interface_83186640(L40QI *self, const unsigned char *riid, void **ppv)
{
    long hr;
    int d;
    hr = 0;
    d = memcmp(riid, lbl_830088A4, 16);
    if (d == 0) {
        *ppv = self ? (void *)((char *)self + 0x20) : 0;
        self->AddRef();
    } else {
        hr = fn_83182CE8(self, riid, ppv);
    }
    return hr;
}

extern "C" long ts4l_query_interface_83186C48(L40QI *self, const unsigned char *riid, void **ppv)
{
    long hr;
    int d;
    hr = 0;
    d = memcmp(riid, lbl_830088B4, 16);
    if (d == 0) {
        *ppv = self ? (void *)((char *)self + 0x20) : 0;
        self->AddRef();
    } else {
        hr = fn_83182CE8(self, riid, ppv);
    }
    return hr;
}


extern "C" long ts4l_query_interface_83187D68(L40QI *self, const unsigned char *riid, void **ppv)
{
    long hr;
    int d;
    hr = 0;
    d = memcmp(riid, lbl_830088B4, 16);
    if (d == 0) {
        *ppv = self ? (void *)((char *)self + 0x20) : 0;
        self->AddRef();
    } else {
        hr = fn_83182CE8(self, riid, ppv);
    }
    return hr;
}

extern "C" unsigned char lbl_830080EC[16];
extern "C" long fn_8316F448(void *, const unsigned char *, void **);

extern "C" long ts4l_query_interface_8316F7D0(L40QI *self, const unsigned char *riid, void **ppv)
{
    long hr;
    int d;
    hr = 0;
    if (ppv == 0) {
        hr = 0x88960001;
    } else {
        *ppv = 0;
        d = memcmp(riid, lbl_830080EC, 16);
        if (d == 0) {
            *ppv = self;
            self->AddRef();
        } else {
            hr = fn_8316F448((char *)self + 8, riid, ppv);
        }
    }
    return hr;
}
