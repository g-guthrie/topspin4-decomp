
typedef unsigned int u32;
extern const float g_ts4_script_constants[];
/* 0x886F8518: unpack a signed 10:10:10 packed vector (x low bits) into three floats scaled by the unit constant */
void ts4_unpack_dec3n_886F8518(const u32 *src, float *out)
{
    u32 v = *src;
    int z = (v >> 20) & 0x3ff;
    int x = v & 0x3ff;
    int y = (v >> 10) & 0x3ff;
    if (z > 0x1ff) z -= 0x400;
    if (y > 0x1ff) y -= 0x400;
    if (x > 0x1ff) x -= 0x400;
    {
        float rz = (float)z * g_ts4_script_constants[329];
        float rx = (float)x * g_ts4_script_constants[329];
        float ry = (float)y * g_ts4_script_constants[329];
        out[2] = rz;
        out[0] = rx;
        out[1] = ry;
    }
}
