/* Swing_DLL.xex 0x88707630: clear the vector of 32-byte entries at +0xC (last = copy(last, last, first)). */
typedef struct Ts4Ent32 { unsigned char b[32]; } Ts4Ent32;
typedef struct Ts4Ent32Vec { Ts4Ent32 *first; Ts4Ent32 *last; } Ts4Ent32Vec;
typedef struct Ts4Ent32Owner { char pad[0xc]; Ts4Ent32Vec v; } Ts4Ent32Owner;
static __inline Ts4Ent32 *ts4_ent32_copy(Ts4Ent32 *first, Ts4Ent32 *last, Ts4Ent32 *dest)
{
    int n;
    for (n = last - first; n > 0; --n, ++first, ++dest) *dest = *first;
    return dest;
}
void ts4_ent32_vec_clear_88707630(Ts4Ent32Owner *o)
{
    Ts4Ent32Vec *v = &o->v;
    v->last = ts4_ent32_copy(v->last, v->last, v->first);
}
