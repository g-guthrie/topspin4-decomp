/* Q5 gameplay: hand three self-relative records of an object's data block to a system. */
typedef unsigned int u32;

/* A self-relative pointer: the target is `off` bytes from the field itself. */
typedef struct Q5RelPtr { int off; } Q5RelPtr;
static const void *q5_rel(Q5RelPtr *r) { return r->off + (const char *)r; }

typedef struct Q5RelRecords {
    Q5RelPtr first;     /* +0x0 */
    Q5RelPtr second;    /* +0x4 */
    Q5RelPtr third;     /* +0x8 */
} Q5RelRecords;
typedef struct Q5RecData { char pad0[0x6dc]; Q5RelRecords recs; } Q5RecData;
typedef struct Q5RecUser { char pad0[0x28]; Q5RecData *data; } Q5RecUser;

extern void *lbl_88D45B18;
/* 0x88636FA0: copies the three records into the system (first word pair of each is read). */
extern void fn_88636FA0(void *sys, const void *first, const void *third, const void *second);

/* Swing_DLL.xex 0x8888AC30 */
void ts4_submit_rel_records_8888AC30(Q5RecUser *self)
{
    int op1_pad0 = 0, op1_pad1 = 0; /* register-allocation order (tools/operand_order_pad.py) */
    Q5RelRecords *n = &self->data->recs;
    const void *third = q5_rel(&n->third);
    const void *second = q5_rel(&n->second);
    (void)op1_pad0;
    (void)op1_pad1;
    fn_88636FA0(lbl_88D45B18, q5_rel(&n->first), third, second);
}
