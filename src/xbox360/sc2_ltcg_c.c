/* SC2: float constructors matched on the LTCG route (no context). The zero is loaded from g_ts4_event_value and the
   w component from g_ts4_script_constants[0]. Load order: 0x886EB3B0 needs both reads volatile (zero first); in
   0x886FD240 the w read is a local assigned between the vec3 member inits (SC1: loads float freely, the position of
   the source statement pins it). */
typedef unsigned int u32;
typedef unsigned char u8;
extern float g_ts4_event_value;
extern float g_ts4_script_constants[];
typedef struct Sc2V3 { float x, y, z; } Sc2V3;
typedef struct Sc2V4 { float x, y, z, w; } Sc2V4;
typedef struct Sc2Obj5c { u32 w0; float f4; u8 b8, b9, pad[2]; Sc2V3 a, b, c, d; float w; } Sc2Obj5c;
static __inline void sc2_v3_init(Sc2V3 *v, float z) { v->x = z; v->y = z; v->z = z; }

/* Swing_DLL.xex 0x886FD240 */
void ts4_obj5c_ctor_886FD240(Sc2Obj5c *o)
{
    float w;
    float z = g_ts4_event_value;
    o->w0 = 0;
    o->b8 = 0;
    o->b9 = 0;
    o->f4 = z;
    sc2_v3_init(&o->d, z);
    sc2_v3_init(&o->c, z);
    sc2_v3_init(&o->b, z);
    w = g_ts4_script_constants[0];
    sc2_v3_init(&o->a, z);
    o->w = w;
}
