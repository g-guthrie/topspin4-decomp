/* Swing_DLL.xex 0x8843AFB8-0x8843B2FC, executable version 0.0.0.3. */
#ifdef __clang__
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
#endif
typedef unsigned char u8;
struct Ts4VwOk {
    u8 ok;
    Ts4VwOk(int v) { ok = (u8)v; }
    Ts4VwOk(const Ts4VwOk &o) { ok = o.ok; }
};
/* Hubs that ask every registered listener a yes/no question, newest first, and stop at the first no. */
#define TS4_VW_ALL(NAME, HUB, ITEM, SUB, ITEMS_OFF, SUBOFF, CALL) \
extern "C" Ts4VwOk NAME HUB \
{ \
    int i; \
    for (i = h->count - 1; i >= 0; i--) { \
        ITEM *it = h->items[i]; \
        if (!it->sub.check CALL .ok) \
            return Ts4VwOk(0); \
    } \
    return Ts4VwOk(1); \
}

struct SubA { virtual void s0(); virtual Ts4VwOk check(int a, int b); };
struct ItemA { char pad[8]; SubA sub; };
struct HubA { char pad[0x28]; ItemA **items; int count; };
TS4_VW_ALL(ts4_all_check2_8843AFB8, (HubA *h, int a, int b), ItemA, SubA, 0, 0, (a, b))

struct SubB { virtual void s0(); virtual Ts4VwOk check(int a, int b, int c, int d, int e); };
struct ItemB { char pad[0xc]; SubB sub; };
struct HubB { char pad[0x24]; ItemB **items; int count; };
TS4_VW_ALL(ts4_all_check5_8843B050, (HubB *h, int a, int b, int c, int d, int e), ItemB, SubB, 0, 0, (a, b, c, d, e))

struct SubC { virtual Ts4VwOk check(int a, int b, int c, int d); };
struct ItemC { char pad[0x10]; SubC sub; };
struct HubC { char pad[0x20]; ItemC **items; int count; };
TS4_VW_ALL(ts4_all_check4_8843B100, (HubC *h, int a, int b, int c, int d), ItemC, SubC, 0, 0, (a, b, c, d))

struct SubD { virtual Ts4VwOk check(int a, int b, int c, int d, int e, int f, int g); };
struct ItemD { char pad[0xc]; SubD sub; };
struct HubD { char pad[0x24]; ItemD **items; int count; };
TS4_VW_ALL(ts4_all_check7_8843B1A8, (HubD *h, int a, int b, int c, int d, int e, int f, int g), ItemD, SubD, 0, 0, (a, b, c, d, e, f, g))

struct SubE { virtual void s0(); virtual Ts4VwOk check(int a, int b); };
struct ItemE { char pad[0x14]; SubE sub; };
struct HubE { char pad[0x1c]; ItemE **items; int count; };
TS4_VW_ALL(ts4_all_check2_8843B268, (HubE *h, int a, int b), ItemE, SubE, 0, 0, (a, b))
