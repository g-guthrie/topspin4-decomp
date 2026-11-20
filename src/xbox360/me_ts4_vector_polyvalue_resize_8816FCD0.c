/* Swing_DLL.xex 0x8816FCD0: vector<12-byte polymorphic value>::resize(n): erase(first + n, last) via ts4_dc0c_erase_88170398, or _Insert_n (fn_88170860) with a default {vtable lbl_880D63EC, 0, 0}.
 * /Oc. Same resize shape as 88280428, but the element has a vtable, so the erase is the out-of-line erase. */
typedef struct PolyValue { const void *vt; unsigned int f4, f8; } PolyValue;
typedef struct PolyVec { PolyValue *first; PolyValue *last; PolyValue *end; } PolyVec;
extern const char lbl_880D63EC[];   /* vtable of the default value */
PolyValue *ts4_dc0c_erase_88170398(PolyVec *v, PolyValue *dst, PolyValue *first);
void fn_88170860(PolyVec *v, PolyValue *where, unsigned int count, const PolyValue *val);

void fn_8816FCD0(PolyVec *v, unsigned int n)
{
    PolyValue val;
    val.vt = lbl_880D63EC;
    val.f8 = 0;
    val.f4 = 0;
    if (n < (unsigned int)(v->last - v->first))
        ts4_dc0c_erase_88170398(v, v->first + n, v->last);
    else
        fn_88170860(v, v->last, n - (v->last - v->first), &val);
}
