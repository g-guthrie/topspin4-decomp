/* nearmiss: 2 off (no volatile); concrete blocker: the two pool loads come out swapped (target: lfs f13 of
 * g_ts4_script_constants[0] then lfs f0 of g_ts4_event_value; here the event value is loaded first). Everything
 * else, including the lis order and all 27 stores, matches. Store order fixed without volatile by (SC1/SC2)
 * putting the int stores first and writing every later store as a block-local member pointer.
 * Tried for the load order, all 2 off: swapping the one/z assignments, declarations and initialisers, swapping
 * the scale/f38 stores, block-local pointers for scale/f38, literal 1.0f, extern order and names, a {f38, scale}
 * sub-struct set through an inline helper (either store order), perm_auto (900 s, baseline 2, no improvement),
 * and 270 hand orderings. Odds improve once the scheduler tie-break between two independent pool loads is known. */

/* Swing_DLL.xex 0x886CBC30: reset a tracker record (counters cleared, scale 1, all accumulators 0). */
typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;
extern const float g_ts4_event_value;   /* 0.0f */
extern const float g_ts4_script_constants[];
struct Ts4RsRec {
    ts4_u8 pad_00[4]; ts4_u32 n04; ts4_u8 pad_08[4];
    float f0c, f10, f14, f18, f1c, f20, f24, f28, f2c;
    ts4_u32 n30_pad; ts4_u32 n34; float f38; float scale; float f40;
    float f44, f48, f4c, f50; ts4_u32 n54; ts4_u8 pad_58[0x14]; ts4_u32 n6c; float f70;
    ts4_u32 n74, n78, n7c; ts4_u8 b80;
};

void ts4_tracker_reset_886CBC30(struct Ts4RsRec *r)
{
    float z, one;
    { ts4_u32 *p = &r->n34; *p = 0; }
    { ts4_u32 *p = &r->n04; *p = 0; }
    one = g_ts4_script_constants[0];
    z = g_ts4_event_value;
    r->scale = one;
    r->f38 = z;
    { float *p = &r->f40; *p = z; }
    { float *p = &r->f0c; *p = z; }
    { float *p = &r->f10; *p = z; }
    { float *p = &r->f14; *p = z; }
    { float *p = &r->f18; *p = z; }
    { ts4_u32 *p = &r->n54; *p = 0; }
    { float *p = &r->f44; *p = z; }
    { float *p = &r->f48; *p = z; }
    { float *p = &r->f4c; *p = z; }
    { float *p = &r->f50; *p = z; }
    { ts4_u32 *p = &r->n6c; *p = 0; }
    { float *p = &r->f1c; *p = z; }
    { ts4_u32 *p = &r->n74; *p = 0; }
    { float *p = &r->f20; *p = z; }
    { ts4_u32 *p = &r->n78; *p = 0; }
    { float *p = &r->f24; *p = z; }
    { ts4_u32 *p = &r->n7c; *p = 0; }
    { float *p = &r->f28; *p = z; }
    { ts4_u8 *p = &r->b80; *p = 0; }
    { float *p = &r->f2c; *p = z; }
    { float *p = &r->f70; *p = z; }
}
