/* Swing_DLL.xex 0x885771E0-0x885772AC, executable version 0.0.0.3. */
/* Statically linked MSVC CRT: _cftof (fixed-point conversion of a double). */
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

int ts4_crt_cftof_885771E0(CrtDouble *pvalue, char *buf, u32 size, int ndec)
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
    e = fn_885790D8(buf + (strflt.sign == '-'), size == (u32)-1 ? (u32)-1 : size - (strflt.sign == '-'), strflt.decpt + ndec, &strflt);
    if (e != 0) {
        *buf = 0;
        return e;
    }
    return fn_88577028(buf, size, ndec, &strflt, 0);
}
