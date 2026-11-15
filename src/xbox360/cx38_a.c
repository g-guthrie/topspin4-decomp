/* CW38 part a: small PlayerCreator/UI helpers in 0x887B0000-0x887D0000. */
typedef unsigned int u32;
typedef unsigned char u8;

#ifdef _MSC_VER
typedef unsigned int cx38_uptr;
#else
typedef unsigned long cx38_uptr;
#endif
cx38_uptr RtlLeaveCriticalSection(cx38_uptr);
typedef struct Crit { char pad[0x114]; char *owner; char pad2[0x1c]; char cs[0x1c]; int cnt; } Crit;
#ifdef _MSC_VER
void __emit(unsigned);
#pragma intrinsic(__emit)
#define cx38_eieio() __emit(0x7c0006ac)
#else
#define cx38_eieio() ((void)0)
#endif

/* 0x887C78F0: drop one recursion level and leave the critical section. */
void ts4_crit_leave_887C78F0(Crit *self)
{
    int n = self->cnt - 1;
    self->cnt = n;
    if (n < 0) return;
    if (n == 0) {
        char *o = self->owner;
        cx38_eieio();
        *(volatile int *)(o + 0x2a88) = 0;
    }
    RtlLeaveCriticalSection((cx38_uptr)(self->cs));
}

extern void *ts4_addr_fn_881F7958_881F4108(void *);
extern char lbl_880EF750[];
extern float lbl_8814B440;
typedef struct S53E8 { void *vt; char pad[0x20]; float a, b, c; } S53E8;
S53E8 *ts4_ctor_zero3_887B53E8(S53E8 *self)
{
    ts4_addr_fn_881F7958_881F4108(self);
    self->vt = lbl_880EF750;
    self->a = lbl_8814B440;
    self->b = self->a;
    self->c = self->a;
    return self;
}

extern void fn_8857BA40(void *, int, int, int);

int ts4_set_mode_887CB690(char *self, int a, int n)
{
    int m;
    if (n == 0) m = 1;
    else if (n == 1) m = 2;
    else m = 0;
    fn_8857BA40(*(void **)(self + 0x14), a, 0, m);
    return 0;
}

typedef struct RObj { void **vt; char *owner; } RObj;
void ts4_release_if_owner_887CB618(char *self, RObj **pp)
{
    RObj *obj = *pp;
    u32 chk = (u32)(cx38_uptr)*pp;
    if (self == obj->owner) {
        if (chk) ((void (*)(void *, int))(*(void ***)obj)[0])(obj, 1);
        *(int *)(self + 0x374) -= 1;
    }
}

int ts4_flags_check_887CEBF0(char *self, char *o)
{
    if (self[0x2cc] || self[0x60]) return 1;
    {
        char *p = self + *(int *)(o + 0x60);
        if (p[0x1c] || p[0x40]) return 1;
    }
    if (self[0x301]) {
        if (*(int *)(self + 0x128) == *(int *)(o + 0x64)) return 1;
    }
    return 0;
}

#define FLAG_PAIR(NAME, A, B) \
u8 NAME(u32 *self, int i, u8 *o1, u8 *o2) \
{ \
    int res; \
    *o1 = 0; \
    *o2 = 0; \
    if (self[i + 2]) { \
        *o1 = *(u8 *)((cx38_uptr)self[i + 2] + A); \
        *o2 = *(u8 *)((cx38_uptr)self[i + 2] + B); \
    } \
    if (*o1 == 0 && *o2 == 0) res = 0; else res = 1; \
    return (u8)res; \
}
FLAG_PAIR(ts4_get_flag_pair_887CF188, 0x24, 0x25)
FLAG_PAIR(ts4_get_flag_pair_887CF1F0, 0x26, 0x27)
