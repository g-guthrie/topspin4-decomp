/* Swing_DLL.xex 0x88576B30-0x885773E0, executable version 0.0.0.3. */
/* Statically linked MSVC CRT: _cftoe and _cftog (exponent and general formats). */
typedef unsigned int u32;
typedef struct CrtDouble {
    double x;
} CrtDouble;
typedef struct StrFlt {
    int sign;
    int decpt;
    int flag;
    char *mantissa;
} StrFlt;
extern u32 *ts4_if_call_seq_fn_8856CD88_88567ED8(void);
extern void fn_8856D2C0(void);
extern StrFlt *fn_88579318(CrtDouble v, StrFlt *pflt, char *result, u32 size);
extern int fn_885790D8(char *buf, u32 size, int digits, StrFlt *pflt);
extern int fn_88577028(char *buf, u32 size, int ndec, StrFlt *pflt, char g_fmt);

extern int fn_885768E0(char *buf, u32 size, int ndec, int caps, StrFlt *pflt, char g_fmt);

int ts4_crt_cftoe_88576B30(CrtDouble *pvalue, char *buf, u32 size, int ndec, int caps)
{
    StrFlt strflt;
    char result[0x16];
    int e;
    u32 *err;
    fn_88579318(*pvalue, &strflt, result, 0x16);
    if (buf == 0) {
        err = ts4_if_call_seq_fn_8856CD88_88567ED8();
        *err = 22;
        fn_8856D2C0();
        return 22;
    }
    if (size == 0) {
        err = ts4_if_call_seq_fn_8856CD88_88567ED8();
        *err = 22;
        fn_8856D2C0();
        return 22;
    }
    e = fn_885790D8(buf + (strflt.sign == '-') + (ndec > 0),
                    size == (u32)-1 ? (u32)-1 : size - (strflt.sign == '-') - (ndec > 0), ndec + 1, &strflt);
    if (e != 0) {
        *buf = 0;
        return e;
    }
    return fn_885768E0(buf, size, ndec, caps, &strflt, 0);
}

int ts4_crt_cftog_885772B0(CrtDouble *pvalue, char *buf, u32 size, int ndec, int caps)
{
    StrFlt strflt;
    char result[0x16];
    char *p;
    int magnitude;
    int mag2;
    char rounded;
    int e;
    u32 *err;
    fn_88579318(*pvalue, &strflt, result, 0x16);
    if (buf == 0) {
        err = ts4_if_call_seq_fn_8856CD88_88567ED8();
        *err = 22;
        fn_8856D2C0();
        return 22;
    }
    if (size == 0) {
        err = ts4_if_call_seq_fn_8856CD88_88567ED8();
        *err = 22;
        fn_8856D2C0();
        return 22;
    }
    magnitude = strflt.decpt - 1;
    p = buf + (strflt.sign == '-');
    e = fn_885790D8(p, size == (u32)-1 ? (u32)-1 : size - (strflt.sign == '-'), ndec, &strflt);
    if (e != 0) {
        *buf = 0;
        return e;
    }
    mag2 = strflt.decpt - 1;
    rounded = magnitude < mag2;
    if (mag2 >= -4 && mag2 < ndec) {
        if (rounded) {
            while (*p++)
                ;
            p[-2] = 0;
        }
        return fn_88577028(buf, size, ndec, &strflt, 1);
    }
    return fn_885768E0(buf, size, ndec, caps, &strflt, 1);
}
