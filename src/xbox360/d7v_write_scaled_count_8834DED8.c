/* Swing_DLL.xex 0x8834DED8-0x8834DF60, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef struct Ts4V5Mode { char pad[0x100]; int channels; } Ts4V5Mode;
typedef struct Ts4V5Obj { char pad[0x20]; Ts4V5Mode *mode; char pad24[0xE4]; void *sink; } Ts4V5Obj;
int fn_883194F0(void *sink, u32 a, int step, u32 count, u32 *out);

int ts4_write_scaled_count_8834DED8(char *iface, u32 a, u32 count, u32 *out)
{
    Ts4V5Obj *o = iface ? (Ts4V5Obj *)(iface - 0x1c) : 0;
    int r;
    if (o->mode->channels == 2) {
        r = fn_883194F0(o->sink, a, 2, count >> 1, out);
        *out = *out << 1;
        return r;
    }
    return fn_883194F0(o->sink, a, 1, count, out);
}
