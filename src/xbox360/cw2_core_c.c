/* CW2 batch c: algorithm helpers (Swing_DLL.xex). */
typedef unsigned int cw2_u32;
typedef unsigned char cw2_u8;

#ifdef _MSC_VER
extern int strcmp(const char *, const char *);
#pragma intrinsic(strcmp)
#else
#include <string.h>
#endif

extern char lbl_880C1320[];
cw2_u8 fn_8822BF98(void *, void *);

/* a text object with two string pointers; fn_8822BF98 decides which one is current */
struct Cw2TextA {
    char *primary;
    cw2_u32 pad[2];
    char *secondary;
};

/* Swing_DLL.xex 0x8815E6F0: compare the current string of the text object with s */
int ts4_cw2_text_equals_8815E6F0(struct Cw2TextA *t, const char *s)
{
    if (fn_8822BF98(lbl_880C1320, &t->secondary) == 0)
        return strcmp(t->secondary, s) == 0;
    return strcmp(t->primary, s) == 0;
}

/* Swing_DLL.xex 0x8815EA80: same test on a text object whose strings sit at +0xc and +0x18 */
struct Cw2TextC {
    cw2_u32 pad0[3];
    char *primary;
    cw2_u32 pad1[2];
    char *secondary;
};
int ts4_cw2_text_equals_8815EA80(struct Cw2TextC *t, const char *s)
{
    if (fn_8822BF98(lbl_880C1320, &t->secondary) == 0)
        return strcmp(t->secondary, s) == 0;
    return strcmp(t->primary, s) == 0;
}
