/* 0x886F0138: renderer: set the active word (+0x58) from the ready byte of source A (+0x64, byte +0x3A) in mode 1, else of source B (+0x60, byte +0xC) */
/* Matched on /Oc (LTCG) (agAL). LTCG route. Two early active = 1 returns and one shared active = 0 tail give the target block layout. */
typedef unsigned char u8;
typedef struct SrcA { u8 pad[0x3a]; u8 ready; } SrcA;
typedef struct SrcB { u8 pad[0xc]; u8 ready; } SrcB;
typedef struct Sel { u8 pad[0x54]; int mode; int active; u8 pad5c[4]; SrcB *b; SrcA *a; } Sel;

void ts4_select_source_active_886F0138(Sel *s)
{
    if (s->mode == 1) {
        if (s->a->ready) {
            s->active = 1;
            return;
        }
    } else if (s->b->ready) {
        s->active = 1;
        return;
    }
    s->active = 0;
}
