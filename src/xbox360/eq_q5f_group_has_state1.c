/* Top Spin 4 (Xbox 360, Swing_DLL.xex) 0x8865EF18 - EQUIVALENT tier, not byte-matched.
 * fn_check: not matched (the table base is hoisted out of the loop in the target).
 * fn_equiv/4 evidence: work/q5/evidence/eq_q5f_group_has_state1.equiv.json (flags /Oc) */
typedef unsigned int u32;
typedef unsigned char u8;

/* ---- 0x8865EF18: does any member of the current group have its 0xe0-byte record
 * (self-relative table at mgr+0x70) in state 1 (+0xc4)?
 * Not byte-matched: the table base is hoisted out of the loop in the target. */
typedef struct Q5GRec { char pad[0xc4]; u8 state; char padc5[0x1b]; } Q5GRec;
typedef struct Q5GTable { int off; } Q5GTable;
typedef struct Q5GMember { char pad[0x14]; u32 rec_index; } Q5GMember;
typedef struct Q5Group { char pad[0x10]; Q5GMember **begin; Q5GMember **end; } Q5Group;
typedef struct Q5GMgr { char pad[0x70]; Q5GTable table; char pad74[8]; u32 current; } Q5GMgr;
typedef struct Q5GOwner { char pad[0x10]; Q5Group **groups; char pad14[0x1c]; Q5GMgr *mgr; } Q5GOwner;

/* Swing_DLL.xex 0x8865EF18 */
int ts4_group_has_state1_8865EF18(Q5GOwner *self)
{
    Q5GMgr *m = self->mgr;
    Q5Group *g = self->groups[m->current];
    int n = (int)(g->end - g->begin);
    int i;
    for (i = 0; i < n; i++) {
        Q5GRec *recs = (Q5GRec *)((char *)&m->table + m->table.off);
        if (recs[g->begin[i]->rec_index].state == 1)
            return 1;
    }
    return 0;
}

