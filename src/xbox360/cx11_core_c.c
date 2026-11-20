/* CW11 part c: more core helpers (0x885F4E48-0x88610000). Built with /Oc. */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned long long u64;

/* 0x8860AD90: call the owner's service (slot 4) with a fixed name, once per requested count */
typedef struct Cx11Sv Cx11Sv;
typedef struct Cx11SvVt { void *s[4]; void (*f10)(Cx11Sv *, const void *, u32); } Cx11SvVt;
struct Cx11Sv { const Cx11SvVt *vt; };
typedef struct Cx11SvOwner { u8 pad[4]; Cx11Sv *sv; } Cx11SvOwner;
extern char lbl_880E1828[];
void ts4_repeat_service_call_8860AD90(Cx11SvOwner *o, u32 *count)
{
    u32 i = 0;
    if (*count > 0) {
        do {
            o->sv->vt->f10(o->sv, lbl_880E1828, 1);
            i++;
        } while (i < *count);
    }
}

/* 0x8860CD38: find the 0x38-byte entry (array at 0x17c, count at 0x184) whose key at +8 equals the given key; null for a zero key */
typedef struct Cx11KEnt { u8 pad[8]; u32 key; u8 pad2[0x38 - 12]; } Cx11KEnt;
typedef struct Cx11KTab { u8 pad[0x17c]; Cx11KEnt *ents; u8 pad2[4]; u32 count; } Cx11KTab;
Cx11KEnt *ts4_find_entry_8860CD38(Cx11KTab *t, u32 key)
{
    Cx11KEnt *r = 0;
    if (key != 0) {
        u32 n = t->count;
        Cx11KEnt *e = t->ents;
        u32 i = 0;
        if (n != 0) {
            do {
                if (key == e->key) { r = e; break; }
                i++;
                e++;
            } while (n != i);
        }
    }
    return r;
}

/* 0x8860D360: under the owner's guard (service at 0x120), scan the entry array from the back for the entry whose range [lo,hi) contains v
   (or, with no range, whose slot 17 accepts it) and return it */
typedef struct Cx11RSv Cx11RSv;
typedef struct Cx11RSvVt { void *s[1]; void (*f4)(Cx11RSv *); void (*f8)(Cx11RSv *); } Cx11RSvVt;
struct Cx11RSv { const Cx11RSvVt *vt; };
typedef struct Cx11Rg Cx11Rg;
typedef struct Cx11RgVt { void *s[17]; u32 (*f44)(Cx11Rg *, u32); } Cx11RgVt;
struct Cx11Rg { const Cx11RgVt *vt; u8 pad[0x164]; u32 lo; u32 hi; };
typedef struct Cx11ROwn { u8 pad[0x120]; Cx11RSv *sv; u32 count; } Cx11ROwn;
Cx11Rg *ts4_find_range_owner_8860D360(Cx11ROwn *o, u32 v)
{
    Cx11RSv *sv = o->sv;
    Cx11Rg *r;
    int i;
    u32 n;
    Cx11Rg **p;
    sv->vt->f4(sv);
    n = o->count;
    r = 0;
    if (n != 0) {
        i = (int)n - 1;
        if (i >= 0) {
            p = (Cx11Rg **)((char *)o + 0x30 + i * 4);
            do {
                Cx11Rg *e = *p;
                u8 hit;
                if ((int)e->lo != 0) {
                    if (e->lo > v || v >= e->hi) hit = 0; else hit = 1;
                } else {
                    hit = (u8)e->vt->f44(e, v);
                }
                if (hit) { r = *(Cx11Rg **)((char *)o + 0x30 + i * 4); break; }
                i--;
                p--;
            } while (i >= 0);
        }
    }
    sv->vt->f8(sv);
    return r;
}

/* 0x8860C7D0: validate a guarded block: 0xDEADBEAF guard words before (at -4) and after (at the size stored at -0x54), and the owner at -0x60.
   Returns -1 null, 1 bad head guard, 3 wrong owner, 2 bad tail guard, 0 ok. memcmp is the intrinsic. */
#ifdef _MSC_VER
extern int memcmp(const void *, const void *, unsigned int);
#pragma intrinsic(memcmp)
#else
#include <string.h>
#endif
int ts4_check_block_guards_8860C7D0(u32 owner, char *p)
{
    u32 magic;
    if (p == 0) return -1;
    magic = 0xdeadbeaf;
    if (memcmp(p - 4, &magic, 4) != 0) return 1;
    if (*(u32 *)(p - 0x60) != owner) return 3;
    if (memcmp(p + *(u32 *)(p - 0x54), &magic, 4) != 0) return 2;
    return 0;
}
