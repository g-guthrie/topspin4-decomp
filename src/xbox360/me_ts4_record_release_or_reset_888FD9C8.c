/* 0x888FD9C8: if the id is registered in the manager's 12-byte entry vector (+0x84), hand it to ts4_keytable_release_8886B840;
 * otherwise look the record up in the active table and, unless its name equals lbl_880D9C70, post the id to
 * the queue at lbl_88D41FC4->+0x70 and clear the record's +0x30 flag. */

typedef unsigned int u32; typedef unsigned char u8;
typedef struct { u32 id; u32 a, b; } E12;
typedef struct { char pad[0x84]; E12 *first, *last; } Mgr;
typedef struct { char pad[0xc]; char name[0x24]; u8 b30; } Ent;
typedef struct { char pad[0x70]; void *q; } Glob;
extern Mgr *lbl_88D459DC;
extern Glob *lbl_88D41FC4;
extern char lbl_880D9C70[];
extern void ts4_keytable_release_8886B840(Mgr *m, u32 id);
extern void *fn_888EC5F8(void);
extern Ent *ts4_find_record_by_key_88187800(void *r, u32 *id);
extern u8 ts4_relname_equals_8816C440(char *a, char *b);
extern void fn_882107D0(void *q, u32 *id, int z);
static E12 *find(Mgr *m, u32 id) { E12 *e = m->last, *it; for (it = m->first; it != e; it++) if (id == it->id) break; return it; }
void ts4_record_release_or_reset_888FD9C8(u32 id)
{
    Mgr *m = lbl_88D459DC;
    if (find(m, id) != m->last) { ts4_keytable_release_8886B840(m, id); return; }
    {
        void *r = fn_888EC5F8();
        if (r) {
            Ent *p = ts4_find_record_by_key_88187800(r, &id);
            if (p && !ts4_relname_equals_8816C440(p->name, lbl_880D9C70)) {
                fn_882107D0(lbl_88D41FC4->q, &id, 0);
                p->b30 = 0;
            }
        }
    }
}
