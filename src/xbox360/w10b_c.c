extern const float g_ts4_script_constants[];
extern const float g_ts4_event_value;
struct W10kS { unsigned char pad[0x14]; unsigned kind; };
void ts4_select_axis_vec3_8866DC98(float *out, const struct W10kS *s)
{
    switch (s->kind) {
    case 0: {
        float x = g_ts4_script_constants[111];
        float y = g_ts4_script_constants[67];
        float z = g_ts4_event_value;
        out[1] = y;
        out[0] = x;
        out[2] = z;
        break; }
    case 1: {
        float x = g_ts4_script_constants[168];
        float y = g_ts4_script_constants[67];
        float z = g_ts4_event_value;
        out[1] = y;
        out[0] = x;
        out[2] = z;
        break; }
    case 2: {
        float x = g_ts4_script_constants[111];
        float y = g_ts4_script_constants[168];
        float z = g_ts4_event_value;
        out[1] = y;
        out[0] = x;
        out[2] = z;
        break; }
    case 3: {
        float x = g_ts4_script_constants[168];
        float y = g_ts4_script_constants[168];
        float z = g_ts4_event_value;
        out[1] = y;
        out[0] = x;
        out[2] = z;
        break; }
    default: {
        float z = g_ts4_event_value;
        out[1] = z;
        out[0] = z;
        out[2] = z;
        break; }
    }
}
