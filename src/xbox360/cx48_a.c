/* CW48 part a: Pam Display renderer small helpers (0x88760000-0x88780000), plain route, no flags. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
#ifdef _MSC_VER
#define CX48_INL static __forceinline
#else
#define CX48_INL static inline
#endif
#define W(p, o) (*(u32 *)((char *)(p) + (o)))
#define B(p, o) (*(u8 *)((char *)(p) + (o)))

extern char *lbl_88D45950;
extern char *g_ts4_session_context;
extern char *lbl_88D41FC4;
typedef struct { u32 w[4]; } Cx48S16;

CX48_INL u8 cx48_get82(char *s) { return B(s, 0x82); }
CX48_INL u32 cx48_getf0(void) { return W(lbl_88D45950, 0xf0); }
CX48_INL u32 cx48_get2c4(void) { return W(*(char **)(g_ts4_session_context + 0x3c), 0x2c4); }
u8 ts4_flag_set_887795A0(char *self) { return 0 != cx48_get82(self); }
u8 ts4_flag_f0_8877A1F8(void) { return 0 != cx48_getf0(); }
u8 ts4_flag_sess_8877BE98(void) { return 0 != cx48_get2c4(); }
void ts4_set_from_global_88779790(char *self, Cx48S16 a) { Cx48S16 *q = &a; W(self, 8) = W(lbl_88D41FC4, 0x88); (void)q; }

extern char lbl_880D6B70[];
typedef struct { u32 a, b, c; } Cx48X;
CX48_INL void cx48_x_ini(Cx48X *x) { x->a = 0; x->c = 0; x->b = 0xFFFFF; }
void ts4_ctor_vt_x_8876D470(char *o) { W(o, 0) = (u32)(unsigned long)lbl_880D6B70; cx48_x_ini((Cx48X *)(o + 4)); }
