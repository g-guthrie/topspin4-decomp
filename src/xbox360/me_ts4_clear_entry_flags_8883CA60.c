/* 0x8883CA60: clear the flag byte (+0x1C) of every 0x20-byte entry of the self-relative table at db+0xC90 */
/* Matched on /Oc (agAL). Plain route. Pass &o->db->ents to each begin/end inline call: a RelTab *t local lets the second inline reuse the first off load (the target reloads it). */
typedef unsigned char u8;
typedef struct Ent20 { u8 pad[0x1c]; u8 flag; u8 pad1d[3]; } Ent20;
typedef struct RelTab { int off; int count; } RelTab;
typedef struct Db { u8 pad[0xc90]; RelTab ents; } Db;
typedef struct Owner { u8 pad[0x24]; Db *db; } Owner;

static Ent20 *tab_begin(RelTab *t)
{
    Ent20 *e = 0;
    if (t->off != -1) e = (Ent20 *)((char *)t + t->off);
    return e;
}

static Ent20 *tab_end(RelTab *t)
{
    Ent20 *e = 0;
    if (t->off != -1) e = (Ent20 *)((char *)t + (t->count * 0x20 + t->off));
    return e;
}

void ts4_clear_entry_flags_8883CA60(Owner *o)
{
    Ent20 *end = tab_end(&o->db->ents);
    Ent20 *e;
    for (e = tab_begin(&o->db->ents); e != end; e++)
        e->flag = 0;
}
