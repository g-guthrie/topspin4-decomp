/* CW38 part e: UI helpers in 0x887B0000-0x887D0000 (batch 2). */
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct VT { void *s[12]; void (*s30)(void *, void *, u8); } VT;
extern VT **lbl_88D45A24;

int ts4_notify_vcall_887CE750(char *self, void *a)
{
    VT **o = lbl_88D45A24;
    if (o) {
        (*o)->s30(o, a, (u8)self[0x1b4]);
    }
    return 1;
}

extern void ts4_vec5c_clear_88213E28(void *);
extern void fn_887C03E8(void *, u8);

/* 0x887C0948: advance the state flags of the sub-object at +0x20. */
void ts4_state_tick_887C0948(char *self)
{
    char *o = *(char **)(self + 0x20);
    if (o[0x58] == 0 && *(int *)(*(char **)o + 0x38) == 7) {
        if (o[0x59] == 0) {
            fn_887C03E8(*(void **)o, (u8)self[0x34]);
            o[0x59] = 1;
        } else {
            o[0x58] = 1;
        }
    }
    if (o[0x58]) ts4_vec5c_clear_88213E28(self + 0x20);
}

extern int fn_8856A3A0(const char *, const char *);

/* 0x887C76D8: name to data pointer through a 16-byte-stride entry table. */
char *ts4_find_name_887C76D8(char *self, const char *name)
{
    if (*(char **)(self + 0x10) && name) {
        u32 i = 0;
        u32 off;
        if (*(u32 *)(self + 0x14) > 0) {
            off = 0;
            do {
                if (fn_8856A3A0(name, *(char **)(*(char **)(self + 0x10) + off + 0xc)) == 0) {
                    return *(char **)(*(char **)(self + 0x10) + i * 16 + 4) + *(int *)self;
                }
                i++;
                off += 0x10;
            } while (i < *(u32 *)(self + 0x14));
        }
    }
    return 0;
}

#ifdef _MSC_VER
extern unsigned int strlen(const char *);
#else
#include <string.h>
#endif
extern void fn_88150600(void *, void *);
extern void fn_8816C930(void *, const char *, const char *);
extern char lbl_880EA2AC[];

/* 0x887CC320: append the stored path plus a string to dst when the object is open. */
int ts4_append_path_887CC320(char *self, char **p, void *dst)
{
    if (self[0x370] == 1) {
        char *s;
        char *e;
        fn_88150600(dst, self + 0x364);
        fn_8816C930(dst, lbl_880EA2AC, lbl_880EA2AC + 2);
        s = *p;
        e = s + strlen(s);
        if (s != e) fn_8816C930(dst, s, e);
        return 1;
    }
    return 0;
}
