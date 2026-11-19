/* NEAR MISS fn_886CBC30: 21 off (int/float store interleaving), LTCG + primer, /Oc. */
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
    r->n34 = 0;
    r->n04 = 0;
    r->scale = g_ts4_script_constants[0];
    r->f38 = g_ts4_event_value;
    r->f40 = g_ts4_event_value;
    r->f0c = g_ts4_event_value;
    r->f10 = g_ts4_event_value;
    r->f14 = g_ts4_event_value;
    r->f18 = g_ts4_event_value;
    r->n54 = 0;
    r->f44 = g_ts4_event_value;
    r->f48 = g_ts4_event_value;
    r->f4c = g_ts4_event_value;
    r->f50 = g_ts4_event_value;
    r->n6c = 0;
    r->f1c = g_ts4_event_value;
    r->n74 = 0;
    r->f20 = g_ts4_event_value;
    r->n78 = 0;
    r->f24 = g_ts4_event_value;
    r->n7c = 0;
    r->f28 = g_ts4_event_value;
    r->b80 = 0;
    r->f2c = g_ts4_event_value;
    r->f70 = g_ts4_event_value;
}
