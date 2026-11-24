/* Residue pass (tools/ltcg_ctx_find.py): functions whose original code keeps volatile registers
 * across a call, so they only match with the callee's body in an LTCG link.
 * Check: python3 tools/fn_check_ltcg.py src/xbox360/q5s_res_pad_stick.c \
 *        ts4_pad_send_stick_888C5C00=0x888C5C00 --flags /Oc \
 *        --include ts4_pad_record_find_88614938 --context src/xbox360/pr2_signin.c \
 *        --context src/xbox360/pp1_pool_primer.c */
typedef unsigned short u16;
typedef struct Q5ResPadRec { char pad[0x10]; int id; } Q5ResPadRec;
typedef struct Q5ResModList Q5ResModList;
typedef struct Q5ResEngine { char pad[0x234]; Q5ResModList *modules; } Q5ResEngine;
typedef struct Q5ResStickOut { char pad[0x20c]; u16 xy[2]; } Q5ResStickOut;

extern Q5ResEngine *lbl_88D45B1C;
extern Q5ResPadRec *ts4_pad_record_find_88614938(Q5ResModList *m, int pad);
extern int ts4_if_call_seq_u32_off0_8857B180(int id, u16 *xy);

/* Swing_DLL.xex 0x888C5C00: scale a stick (x, y) to 0..65535, store it as two u16 at +0x20c/+0x20e and
 * send it to the pad's controller (id of the pad record, -1 when the pad has none); returns 1 when the
 * send returns 0. The link keeps x and y in f1/f2 across ts4_pad_record_find_88614938 (the callee writes
 * no float register). The scale is the literal 65535.0f (g_ts4_script_constants + 0x84): as a literal it
 * is the second fmuls operand, as the target has it. */
int ts4_pad_send_stick_888C5C00(Q5ResStickOut *o, int pad, float x, float y)
{
    Q5ResPadRec *rec = ts4_pad_record_find_88614938(lbl_88D45B1C->modules, pad);
    int id = rec ? rec->id : -1;
    o->xy[0] = (u16)(x * 65535.0f);
    o->xy[1] = (u16)(y * 65535.0f);
    return ts4_if_call_seq_u32_off0_8857B180(id, o->xy) == 0;
}
