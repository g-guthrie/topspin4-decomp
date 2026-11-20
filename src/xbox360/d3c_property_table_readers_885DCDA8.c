/* Swing_DLL.xex 0x885DCDA8-0x885DD1F4, executable version 0.0.0.3. */
typedef unsigned int u32;

typedef struct Ts4PropRecord {
    u32 base;
    u32 stride;
    u32 count;
} Ts4PropRecord;

typedef struct Ts4PropTable {
    char pad0[0x48];
    u32 count;
    char pad1[0x8];
    Ts4PropRecord *records;
} Ts4PropTable;

extern void fn_885DC838(void *obj, const void *a, const void *b, const void *c, u32 line);
extern u32 ts4_if_call_seq_u32_off44_885DCD38(void *obj, u32 addr);
extern float ts4_if_call_seq_u32_off44_885DD0D8(void *obj, u32 addr);
extern char lbl_880B4540[], lbl_880B45A8[], lbl_880B4648[], lbl_880B4600[];

/* Range-checked read of element SUB of record IDX as an integer property. */
u32 ts4_read_indexed_u32_property_885DCDA8(Ts4PropTable *p, u32 idx, u32 sub)
{
    Ts4PropRecord *rec;
    if (idx >= p->count) fn_885DC838(0, lbl_880B4540, lbl_880B4648, lbl_880B45A8, 0x27a);
    rec = (Ts4PropRecord *)((char *)p->records + idx * 0xc);
    if (sub >= rec->count) fn_885DC838(0, lbl_880B4540, lbl_880B4600, lbl_880B45A8, 0x27a);
    rec = (Ts4PropRecord *)((char *)p->records + idx * 0xc);
    return ts4_if_call_seq_u32_off44_885DCD38(p, rec->base + rec->stride * sub);
}

/* Same lookup, returning the property as a float. */
float ts4_read_indexed_float_property_885DD148(Ts4PropTable *p, u32 idx, u32 sub)
{
    Ts4PropRecord *rec;
    if (idx >= p->count) fn_885DC838(0, lbl_880B4540, lbl_880B4648, lbl_880B45A8, 0x29e);
    rec = (Ts4PropRecord *)((char *)p->records + idx * 0xc);
    if (sub >= rec->count) fn_885DC838(0, lbl_880B4540, lbl_880B4600, lbl_880B45A8, 0x29e);
    rec = (Ts4PropRecord *)((char *)p->records + idx * 0xc);
    return ts4_if_call_seq_u32_off44_885DD0D8(p, rec->base + rec->stride * sub);
}
