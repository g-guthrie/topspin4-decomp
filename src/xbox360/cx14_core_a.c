/* CW14 part a: game flow database accessors (0x8883C000-0x88850000). Built with /Oc. */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern void *ts4_find_record_by_key_881AD100(void *tbl, void *key);

typedef struct Cx14Db { char pad[8]; void *tbl; } Cx14Db;

/* Self-relative table: {int off; int count;} followed by entries at (char*)t + off + i*stride */
typedef struct Cx14Tbl { int off; int count; } Cx14Tbl;

/* 0x88840E60: clear the flag byte (+0x11) of the 0x14-byte entry whose key (+0xc) matches */
void ts4_ptbl_clear_flag_88840E60(Cx14Tbl *t, u32 key)
{
    int i;
    for (i = 0; i < t->count; i++) {
        char *e = (char *)t + (i * 0x14 + t->off);
        if (*(u32 *)(e + 0xc) == key) {
            e[0x11] = 0;
            return;
        }
    }
}

/* 0x88840EB0: type 0x2C1C9C51 entry: set flag, store a word and a byte at its self-relative target */
void ts4_ptbl_set_word_byte_88840EB0(Cx14Tbl *t, u32 key, u32 val, u8 b)
{
    int i;
    for (i = 0; i < t->count; i++) {
        char *e = (char *)t + (i * 0x14 + t->off);
        if (*(u32 *)(e + 0xc) == key) {
            char *p;
            if (*(u32 *)(e + 8) != 0x2C1C9C51) return;
            p = e + *(int *)e;
            e[0x11] = 1;
            *(u32 *)p = val;
            p[4] = b;
            return;
        }
    }
}

/* 0x88840430: add or subtract one from the counter at record+0x24, moving away from zero */
int ts4_db_bump_counter_88840430(Cx14Db *self, u32 key, u8 up)
{
    char *r = (char *)ts4_find_record_by_key_881AD100(self->tbl, &key);
    int v = 0;
    if (r != 0) {
        v = *(int *)(r + 0x24);
        if (up == 1) v = (v > 0) ? v + 1 : 1;
        else v = (v < 0) ? v - 1 : -1;
        *(int *)(r + 0x24) = v;
    }
    return v;
}

/* ---- manager with a vector of object pointers at +0x20/+0x24 ---- */
typedef struct Cx14MObj { char pad0[0x8c]; void *f8c; char pad90[0x180 - 0x90]; int id180; int id184; } Cx14MObj;
typedef struct Cx14Mgr { char pad0[0x20]; Cx14MObj **begin; Cx14MObj **end; } Cx14Mgr;
extern int fn_889254C8(void *, int);

/* 0x8883D038: find the object with id180 == id and, if its +0xc member is set, call fn_889254C8(obj, 1) */
void ts4_mgr_poke_by_id180_8883D038(Cx14Mgr *m, int id)
{
    Cx14MObj **e = m->end;
    Cx14MObj **p = m->begin;
    Cx14MObj *found = 0;
    for (; p != e; p++) {
        if ((*p)->id180 == id) {
            found = *p;
            break;
        }
    }
    if (found != 0 && *(void **)((char *)found + 0xc) != 0) fn_889254C8(found, 1);
}

typedef struct Cx14VObj { void **vt; } Cx14VObj;
extern void *ts4_find_record_by_key_881AC778(void *tbl, void *key);

/* 0x88842BA8: find the object with id180 == id, ask its member (+0x8c) for a record owner, bump a counter of the keyed record */
void ts4_mgr_bump_record_88842BA8(Cx14Mgr *m, int id, u32 key)
{
    Cx14MObj **e = m->end;
    Cx14MObj **p = m->begin;
    Cx14MObj *found = 0;
    Cx14VObj *sub;
    char *own;
    u32 *rec;
    for (; p != e; p++) {
        if ((*p)->id180 == id) {
            found = *p;
            break;
        }
    }
    sub = (Cx14VObj *)found->f8c;
    own = (char *)((void *(*)(void *, int))sub->vt[0x4c / 4])(sub, 0);
    rec = (u32 *)ts4_find_record_by_key_881AC778(own + 0xec, &key);
    rec[1] = rec[1] + 1;
}

/* ---- global game state (lbl_88D459E8) ---- */
struct Cx14Game;
extern struct Cx14Game *lbl_88D459E8;
typedef struct Cx14State { char pad0[0x24]; char *f24; } Cx14State;

/* 0x888411F0 / 0x88841250: set a flag byte on the entry (0x18-byte stride, key at +0) of the table at state+0xe8 */
#define CX14_SET_FLAG(NAME, FOFF) \
void NAME(u32 key) \
{ \
    Cx14Tbl *t = (Cx14Tbl *)(((Cx14State *)lbl_88D459E8)->f24 + 0xe8); \
    int i; \
    for (i = 0; i < t->count; i++) { \
        char *e = (char *)t + (i * 0x18 + t->off); \
        if (*(u32 *)e == key) { \
            e[FOFF] = 1; \
            return; \
        } \
    } \
}
CX14_SET_FLAG(ts4_state_flag_entry_888411F0, 0x15)
CX14_SET_FLAG(ts4_state_flag_entry_88841250, 0x14)

/* ---- hashed property updates ---- */
typedef struct Cx14Id { u32 v; } Cx14Id;
extern void fn_8883F508(void *, Cx14Id, int);

/* 0x8883FD88: update four properties with the same value */
void ts4_child_set_props_8883FD88(void *self, int val)
{
    { Cx14Id id_ = { 0x13335288 }; fn_8883F508(self, id_, val); }
    { Cx14Id id_ = { 0x1208D727 }; fn_8883F508(self, id_, val); }
    { Cx14Id id_ = { 0xD08AD3EF }; fn_8883F508(self, id_, val); }
    { Cx14Id id_ = { 0xD77D3268 }; fn_8883F508(self, id_, val); }
}
