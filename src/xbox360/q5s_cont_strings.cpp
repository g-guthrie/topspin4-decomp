/* q5s_cont: engine string / text helpers (LTCG route, /Oc). Types: include/ts4/containers.h. */
#include "include/ts4/ts4.h"

/* ---- Text buffer assigned from an XData text reference (12-byte handle passed by value). ---- */
struct XDataRef;
struct XDataNode {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C(); virtual void v10();
    virtual void v14(); virtual void v18(); virtual void v1C(); virtual void v20(); virtual void v24();
    virtual void v28(); virtual void v2C(); virtual void v30(); virtual void v34(); virtual void v38();
    virtual void v3C(); virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C();
    virtual const char *get_text(XDataRef *ref, unsigned int offset, int flag); /* +0x50 */
};
struct XDataRef {
    XDataNode *node;
    unsigned int offset;
    unsigned int extra;
};
extern "C" void fn_8816CAA0(Ts4Text *t, const char *s); /* Ts4Text::assign(const char *) */

extern "C" void ts4_text_assign_xref_88176E18(Ts4Text *t, XDataRef ref)
{
    fn_8816CAA0(t, ref.node->get_text(&ref, ref.offset, 1));
}

/* ---- Narrow string Right(n). ---- */
struct Ts4Str;
extern "C" Ts4StrHdr *ts4_if_get_u32_offc_8819B6C0(Ts4StrHdr *h); /* CloneData */
extern "C" void ts4_string_assign_alloc_8819B060(Ts4Str *self, const char *s, int n, void *alloc);
struct Ts4Str : Ts4String {
    Ts4StrHdr *hdr() const { return (Ts4StrHdr *)data - 1; }
    int length() const { return hdr()->length; }
    const char *c_str() const { return data; }
};

extern "C" Ts4Str *ts4_string_right_8819BE18(Ts4Str *out, const Ts4Str *src, int n)
{
    if (n < 0)
        n = 0;
    int len = src->length();
    if (n >= len) {
        out->data = (char *)(ts4_if_get_u32_offc_8819B6C0(src->hdr()) + 1);
    } else {
        ts4_string_assign_alloc_8819B060(out, src->c_str() + len - n, n, src->hdr()->alloc);
    }
    return out;
}

/* ---- Wide string assign(const wchar *). ---- */
struct Ts4WStr;
extern "C" void fn_8819C360(Ts4WStr *self, const unsigned short *s, int n); /* wide SetString (unmatched) */
struct Ts4WStr {
    unsigned short *data;
    static int StringLength(const unsigned short *s)
    {
        int n = 0;
        if (s != 0) {
            const unsigned short *p = s;
            while (*p != 0) {
                ++p;
                ++n;
            }
        }
        return n;
    }
};

extern "C" Ts4WStr *ts4_wstring_assign_cstr_8819AE68(Ts4WStr *self, const unsigned short *s)
{
    fn_8819C360(self, s, Ts4WStr::StringLength(s));
    return self;
}
