/* Near-miss (2 off at /Oc, also with LTCG): the target spills id (stw r4,0x7c(r1)) before mr r31,r3 / lwz 0x1c; this source schedules the load first. Lookup by id in a self-relative 0x3c-byte record table, falling back to the first record. */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct RecordTable { u32 offset; int count; } RecordTable;
typedef struct RecordData { u8 pad[0x14]; RecordTable table; } RecordData;
typedef struct RecordOwner { u8 pad[0x6c]; RecordData *data; } RecordOwner;
typedef struct RecordLink { u8 pad[0x1c]; RecordOwner *owner; } RecordLink;
typedef struct RecordUser { u8 pad[0x1c]; RecordLink *link; } RecordUser;

extern u8 *fn_8826CCD8(RecordTable *table, u32 *id);

/* Find the record with this id; fall back to the table's first record. */
u8 *fn_8865FD40(RecordUser *u, u32 id)
{
    u8 *rec = fn_8826CCD8(&u->link->owner->data->table, &id);
    if (rec == 0) {
        RecordTable *t = &u->link->owner->data->table;
        rec = (u8 *)t + t->offset;
    }
    return rec;
}
