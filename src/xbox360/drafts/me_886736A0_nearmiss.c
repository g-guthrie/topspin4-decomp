/* near-miss 0x886736A0 (plain /Oc): 33 instructions off (size 0x1BC vs 0x1C0). Open: target reloads s->bank after the slot-reset loop (we reuse the loop's last load, one instruction short), and the loop's add order (off+i*8 vs i*8+off) ignores source order. bank_of accessor + __restrict copy gave the clrrwi. */
/* 0x886736A0: applies preset idx: copies its parameter block into the live block, resets every slot to the default
 * (hash 0xA90612C0, weight 200) and then copies the preset's own slots over them. */
typedef unsigned int u32;
typedef struct RelArr { int self_off; u32 count; } RelArr;
typedef struct RelVec { int self_off; u32 count; u32 cap; } RelVec;
typedef struct Slot { u32 hash; int weight; } Slot;
typedef struct PresetParams {
    int i0, i1, i2, i3, i4; float f[9]; int j0, j1, j2, j3, j4; float last;
} PresetParams;
typedef struct Preset { RelArr slots; char p[0xc - 8]; PresetParams params; char p2[0x60 - 0x5c]; } Preset;
typedef struct PresetBank { char p[0x58]; RelArr presets; int presets_cap; RelVec slots; PresetParams live; } PresetBank;
typedef struct PresetOwner { char p[0x2c]; PresetBank *bank; } PresetOwner;
void *memcpy(void *dst, const void *src, unsigned int n);
static __inline void params_copy(PresetParams *__restrict d, const PresetParams *s)
{
    int k;
    d->i0 = s->i0; d->i1 = s->i1; d->i2 = s->i2; d->i3 = s->i3; d->i4 = s->i4;
    for (k = 0; k < 9; k++) d->f[k] = s->f[k];
    d->j0 = s->j0; d->j1 = s->j1; d->j2 = s->j2; d->j3 = s->j3; d->j4 = s->j4;
    d->last = s->last;
}
static __inline void *rel(void *r) { return (char *)r + *(int *)r; }
static __inline PresetBank *bank_of(PresetOwner *s) { return s->bank; }
static __inline Preset *preset_at(RelArr *t, u32 i) { return (Preset *)((char *)t + (i * sizeof(Preset) + t->self_off)); }
void fn_886736A0(PresetOwner *s, u32 idx)
{
    PresetBank *b = s->bank;
    u32 i;
    if (idx >= b->presets.count) return;
    params_copy(&bank_of(s)->live, &preset_at(&bank_of(s)->presets, idx)->params);
    for (i = 0; i < s->bank->slots.count; i++) {
        RelVec *v = &s->bank->slots;
        Slot *d = (Slot *)((char *)v + (v->self_off + i * sizeof(Slot)));
        d->hash = 0xA90612C0u;
        d->weight = 200;
    }
    {
        PresetBank *bk = s->bank;
        RelVec *dst = &bk->slots;
        RelArr *src = &preset_at(&bk->presets, idx)->slots;
        int n = (int)src->count;
        if (n > 0 && dst->self_off != -1 && src->self_off != -1 && dst->cap >= (u32)n) {
            memcpy(rel(dst), rel(src), n * sizeof(Slot));
            dst->count = dst->count < (u32)n ? (u32)n : dst->count;
        }
    }
}
