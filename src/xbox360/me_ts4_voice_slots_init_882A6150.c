/* 0x882A6150: allocates the 0x7A0-byte pool (+0x555C) and the four 16-byte slots (+0x5560) on first use, then binds each slot to its 0x1E0-byte pool chunk (allocating one when missing), initialises the chunk and marks the slot used */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); returns 0 on allocation failure, else 1; the null checks on &slots[i] and on the chunk are in the target (inlined placement-new style). */
typedef struct Ent { int used; char *buf; void *owner; int pc; } Ent;
typedef struct T { char pad[0x555C]; char *pool; Ent *slots; } T;
void *fn_88888668(unsigned int size, unsigned int tag);
void ts4_if_call_seq_u32_lbl_88D45B38_88884DE0(void *p, unsigned int tag);
void fn_8829C048(char *begin, char *end);
int ts4_voice_slots_init_882A6150(T *t)
{
    int i;
    Ent *e;
    char *buf;
    if (!t->pool) {
        char *p = (char *)fn_88888668(0x7a0, 0xa3800000);
        if (!p) return 0;
        t->pool = p;
    }
    if (!t->slots) {
        Ent *s = (Ent *)fn_88888668(0x40, 0x24800000);
        if (!s) return 0;
        t->slots = s;
    }
    for (i = 0; i < 4; ++i) {
        e = &t->slots[i];
        buf = t->pool + i * 0x1e0;
        if (!e) {
            e = (Ent *)fn_88888668(0x10, 0x24800000);
            if (!e) continue;
        }
        if (buf) {
            e->buf = buf;
        } else {
            e->buf = (char *)fn_88888668(0x1e0, 0xa2800000);
            if (!e->buf) {
                ts4_if_call_seq_u32_lbl_88D45B38_88884DE0(e, 0x24800000);
                continue;
            }
        }
        fn_8829C048(e->buf, e->buf + 0x1e0);
        e->owner = t;
        e->used = 1;
        e->pc = 0;
    }
    return 1;
}
