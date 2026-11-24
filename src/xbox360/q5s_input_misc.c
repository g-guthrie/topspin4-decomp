/*
 * Q5S input: small helpers (Swing_DLL.xex), LTCG route, /Oc.
 *
 * 0x88884618: delete the profile content item; returns true on success. The u8 return type is what produces
 *             the `addi r9,r3,0` copy before cntlzw (an int return drops it).
 * 0x88886938: pick the pending sound event from the context id and clear the pending flag.
 * 0x88883CD0: find the job slot of the calling thread (25 slots) and return a pointer into its data area.
 */
typedef unsigned int u32;
typedef unsigned char u8;

extern unsigned int lbl_88C6A45C;
extern char lbl_88D41E28[];
unsigned int ts4_tailcall_XamContentDelete_8857B2D0(unsigned int user, void *data, void *overlapped);

/* 0x88884618 */
u8 ts4_input_content_delete_ok_88884618(void)
{
    return 0 == ts4_tailcall_XamContentDelete_8857B2D0(lbl_88C6A45C, lbl_88D41E28, 0);
}

typedef struct Q5sSnd { char pad0[0x204]; u8 pending; char pad205[3]; u32 event; } Q5sSnd;
typedef struct Q5sSndCtx { u32 type; char pad4[0x14]; u32 id; } Q5sSndCtx;
typedef struct Q5sSndOwner { char pad0[0x40]; Q5sSndCtx *ctx; Q5sSnd *snd; } Q5sSndOwner;

/* 0x88886938 */
void ts4_input_pick_event_88886938(Q5sSndOwner *o)
{
    Q5sSnd *s = o->snd;
    Q5sSndCtx *c;
    if (s->pending != 1)
        return;
    c = o->ctx;
    if (c->type == 0x3e5)
        return;
    if (c->id == 0)
        s->event = 0x504521a8;
    else if (c->id == 0x4c7)
        s->event = 0xa6ee02f4;
    o->snd->pending = 0;
}

typedef struct Q5sJobSlot { u32 h; int id; char data[0x200]; } Q5sJobSlot;
extern Q5sJobSlot lbl_88D3EB60[25];
extern int fn_8857C8C8(void);

/* 0x88883CD0 */
void *ts4_input_thread_slot_data_88883CD0(u32 off)
{
    int id = fn_8857C8C8();
    void *r = 0;
    Q5sJobSlot *e = lbl_88D3EB60;
    do {
        if (id == e->id) {
            r = e->data + off;
            break;
        }
        e++;
    } while (e != lbl_88D3EB60 + 25);
    return r;
}
