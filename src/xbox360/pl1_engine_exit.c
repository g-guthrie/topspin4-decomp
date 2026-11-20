/* Swing_DLL.xex 0x886E11C8: SwingAnimationEngine exit (vtable Exit slot): clears the per-player record vectors, tears down the AodManager, resets state */
typedef unsigned int u32;
extern void *fn_88562DC0(void *dst, void *src, u32 n);
typedef struct PVec { char *first; char *last; } PVec;
static __inline char *pl1_copy(char *first, char *last, char *dest)
{
    if (first == last) {
        return dest;
    } else {
        u32 n = (u32)(last - first);
        dest = (char *)fn_88562DC0(dest, first, n);
        return dest + n;
    }
}
static __inline void pl1_pvec_clear(PVec *v)
{
    v->last = pl1_copy(v->last, v->last, v->first);
}
typedef struct Rec { PVec v; u32 w8; } Rec;
typedef struct RecVec { Rec *first; Rec *last; } RecVec;
static __inline void pl1_destroy(Rec *first, Rec *last)
{
    for (; first != last; ++first)
        pl1_pvec_clear(&first->v);
}
extern void *ts4_vector_erase_range_881B4740(void *v, void *first, void *last);
static __inline void pl1_recvec_clear(RecVec *v)
{
    ts4_vector_erase_range_881B4740(v, v->first, v->last);
}
typedef struct Aod {
    void **vt;
    PVec v4;
    char p0c[4];
    PVec v10;
    char p18[4];
    PVec v1c;
    char p24[0x24];
    u32 f48;
} Aod;
typedef struct Eng {
    char p0[8];
    unsigned char b8;
    char p9[7];
    char x10[0x30];
    Aod *aod;
    u32 f44;
    u32 f48;
    u32 f4c;
    char p50[0x18];
    char x68[0xdc];
    u32 f144;
    char p148[0x10];
    RecVec recs;
} Eng;
extern void ts4_dc20e_erase_88263A08(void *v, void *first, void *last);
extern void ts4_clear_buffers_886DB398(void *p);
extern void ts4_delete_all_and_clear_886C3CB8(void *p);
extern void ts4_release_all_items_886C8358(void *p);
extern void ts4_vec204_move_tail_881B9148(void *p);
extern void fn_886D9788(Aod *a);
extern void fn_886E0F70(Eng *e);
extern u32 lbl_88D45AF0;
void ts4_engine_exit_886E11C8(Eng *e)
{
    pl1_destroy(e->recs.first, e->recs.last);
    pl1_recvec_clear(&e->recs);
    if (lbl_88D45AF0 != 0) {
        Aod *a = e->aod;
        fn_886D9788(a);
        a->f48 = 0;
        pl1_pvec_clear(&a->v10);
        ts4_dc20e_erase_88263A08(&a->v1c, a->v1c.first, a->v1c.last);
        pl1_pvec_clear(&a->v4);
        if (e->aod)
            ((void (*)(Aod *, int))e->aod->vt[0])(e->aod, 1);
    }
    e->aod = 0;
    ts4_clear_buffers_886DB398(e->x68);
    e->f48 = 0;
    fn_886E0F70(e);
    ts4_delete_all_and_clear_886C3CB8(e);
    ts4_release_all_items_886C8358(e);
    e->f44 = 0;
    e->f48 = 0;
    e->f4c = 0;
    e->f144 = 0;
    e->b8 = 0;
    ts4_vec204_move_tail_881B9148(e->x10);
}
