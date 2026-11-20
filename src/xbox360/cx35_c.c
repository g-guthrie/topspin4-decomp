/* CW35 part c: state helper in 0x88790000-0x887B0000. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct G38 { u8 pad[0x24]; struct G24b *f24; u8 pad2[0x10]; void *f38; } G38;
typedef struct G24b { u8 pad[0xd20]; u32 fd20; } G24b;
typedef struct St18 { u8 pad[0x10]; u32 f10; u32 f14; volatile u32 f18; } St18;
extern G38 *lbl_88D459E8;
extern void fn_88854258(void *, u32);
extern void fn_8885F628(void *, u32);

void ts4_state_apply_887ACD90(St18 *s)
{
    u8 ok = 0;
    G38 *g = lbl_88D459E8;
    s->f18 = 0xDFA2AFF1;
    s->f18 = 0xA0BDE62E;
    if (g) {
        fn_88854258(g->f38, g->f24->fd20);
        fn_8885F628(lbl_88D459E8->f38, s->f10);
        ok = 1;
    }
    if (!ok) {
        s->f18 = 0x9C1C9375;
    }
}
