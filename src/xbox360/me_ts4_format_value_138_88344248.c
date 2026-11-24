/* 0x88344248: returns the float at +0x138 of the outer object in *out and formats it into buf; returns 0 */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct { char p[0x1c]; } Base;
typedef struct { char p[0x138]; float v; } O;
extern const char lbl_8802974C[];
int fn_885635D0(char *buf, const char *fmt, ...);
int ts4_format_value_138_88344248(Base *b, int unused, float *out, char *buf) { O *o = b ? (O *)((char *)b - 0x1c) : 0; *out = o->v; fn_885635D0(buf, lbl_8802974C, (double)o->v); return 0; }
