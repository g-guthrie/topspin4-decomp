/* context only: unmatched model of 0x888AF5C0 (supplies its register usage to LTCG callers) */
typedef unsigned int u32;
typedef unsigned char u8;
#define F32(p, o) (*(float *)((char *)(p) + (o)))
#define U32(p, o) (*(u32 *)((char *)(p) + (o)))
#define U8(p, o) (*(u8 *)((char *)(p) + (o)))
extern char lbl_880DC550[];
extern float lbl_8814B440;
extern float g_ts4_script_constants[];
#ifdef _MSC_VER
__declspec(noinline)
#endif
char *fn_888AF5C0(char *self)
{
    float g0 = g_ts4_script_constants[0];
    float g1 = g_ts4_script_constants[0x424 / 4];
    float zero;
    U32(self, 4) = 0;
    U32(self, 0) = (u32)(unsigned long)lbl_880DC550;
    F32(self, 0xc) = g1;
    F32(self, 0x10) = g1;
    F32(self, 0x14) = g1;
    zero = lbl_8814B440;
    F32(self, 0x18) = zero;
    F32(self, 0x1c) = zero;
    F32(self, 0x20) = zero;
    F32(self, 0x28) = g0;
    F32(self, 0x24) = zero;
    F32(self, 0x2c) = zero;
    U8(self, 0x34) = 0;
    F32(self, 0x30) = g_ts4_script_constants[0x464 / 4];
    U8(self, 0x35) = 0;
    U8(self, 0x36) = 0;
    F32(self, 0x5c) = zero;
    U8(self, 0x37) = 0;
    U32(self, 0x60) = 0;
    U32(self, 0x64) = 0;
    U32(self, 0x68) = 0;
    U32(self, 0x6c) = 0;
    U32(self, 0x70) = 0;
    U32(self, 0x74) = 0;
    U32(self, 0x78) = 0;
    U8(self, 0x7c) = 0;
    return self;
}
