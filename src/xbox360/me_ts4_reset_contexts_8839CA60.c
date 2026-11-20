/* Swing_DLL.xex 0x8839CA60: clears each 0x492C-byte context (count +0x128, at least 1) while keeping +0x48B4/+0x48B8, then sets
 * index -1, active 1 and the 16-byte-aligned scratch pointer (+0x2440 = ctx + 0x120F & ~0xF). agAE: /Oc. */
typedef struct Ctx {
    char pad[0x2440]; char *aligned; char pad2444[0x489c - 0x2444]; int active; char pad48a0[0x48b4 - 0x48a0];
    void *keepA; void *keepB; char pad48bc[4]; int index; char pad48c4[0x492c - 0x48c4];
} Ctx;
typedef struct Mgr { char pad[0x110]; Ctx *ctxs; char pad114[0x128 - 0x114]; int count; } Mgr;
void *ts4_memset(void *p, int v, unsigned int n);
int fn_8839CA60(Mgr *m)
{
    int i;
    if (m->ctxs) {
        for (i = 0; i < (m->count ? m->count : 1); i++) {
            void *b = m->ctxs[i].keepB;
            void *a = m->ctxs[i].keepA;
            ts4_memset(&m->ctxs[i], 0, sizeof(Ctx));
            m->ctxs[i].keepA = a;
            m->ctxs[i].keepB = b;
            m->ctxs[i].index = -1;
            m->ctxs[i].active = 1;
            m->ctxs[i].aligned = (char *)(((unsigned int)&m->ctxs[i] + 0x120f) & ~0xf);
        }
    }
    return 0;
}
