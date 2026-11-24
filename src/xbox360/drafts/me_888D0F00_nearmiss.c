/* nearmiss: 2 off (q5s batch 2); the target stores id (+0x4c) right after state, then channel, then time; ours puts time first. The source order state,id,channel,time gives 3; a pre-loaded id local gives 5; a C++ inline Cue::Start(id,ch) member (by value or const ref) stays at 2. Blocker: probably the lazy-init table is a C++ function-local static and the cue fill is a different inline helper; not found yet. */
/* DRAFT (2 instructions off on /Oc): Swing_DLL.xex 0x888D0F00, lazily initialised table of three cue ids (guard bit in lbl_88D4BD90),
 * each assigned to the next free 0x170-byte cue of the self-relative cue table. Only the id store is scheduled after the channel/time stores; all 24 orders of the four field stores were tried. */
typedef struct Cue {
    unsigned char pad[0x44];
    unsigned int state;    /* 0x44 */
    int time;              /* 0x48 */
    unsigned int id;       /* 0x4c */
    unsigned char pad50;
    unsigned char channel; /* 0x51 */
    unsigned char pad52[0x170 - 0x52];
} Cue;
typedef struct CueTab { int first; int count; } CueTab;
typedef struct Player {
    unsigned char pad[0x7c];
    CueTab *cues;          /* 0x7c */
    unsigned char pad80[0xc4 - 0x80];
    int last_param;        /* 0xc4 */
} Player;

extern unsigned int lbl_88D4BD90;      /* lazy-init guard */
extern unsigned int lbl_88D4BD84[3];   /* cue ids */

static __inline Cue *tbegin(CueTab *t) { Cue *e = 0; if (t->first != -1) e = (Cue *)((char *)t + t->first); return e; }
static __inline Cue *tend(CueTab *t) { Cue *e = 0; if (t->first != -1) e = (Cue *)((char *)t + t->first + t->count * sizeof(Cue)); return e; }

void fn_888D0F00(Player *pl, unsigned char channel, int param)
{
    unsigned int *ids = lbl_88D4BD84;
    unsigned int g = lbl_88D4BD90;
    Cue *e, *end;
    int k;
    if (!(g & 1)) {
        lbl_88D4BD90 = g | 1;
        ids[0] = 0x1FA594C8;
        ids[1] = 0x873CB0F8;
        ids[2] = 0xFACE0FFC;
    }
    e = tbegin(pl->cues);
    end = tend(pl->cues);
    for (k = 0; k < 3; k++, ids++) {
        for (; e != end; e++) {
            if (!e->state) {
                e->state = 0x5EC616BF;
                e->id = *ids;
                e->time = 0;
                e->channel = channel;
                pl->last_param = param;
                break;
            }
        }
    }
}
