/* SC2: float initialiser matched on the LTCG route (no context). The zero is loaded from g_ts4_event_value and the
   w component from g_ts4_script_constants[0]; both reads volatile so the zero is loaded first. */
extern float g_ts4_event_value;
extern float g_ts4_script_constants[];
typedef struct Sc2V4 { float x, y, z, w; } Sc2V4;

/* Swing_DLL.xex 0x886EB3B0 */
void ts4_vec4_init_unit_w_886EB3B0(Sc2V4 *v)
{
    float z = *(volatile float *)&g_ts4_event_value;
    float w = *(volatile float *)&g_ts4_script_constants[0];
    v->x = z;
    v->y = z;
    v->z = z;
    v->w = w;
}

