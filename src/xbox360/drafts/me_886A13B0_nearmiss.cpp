/* 0x886A13B0 near miss (55 off, C++ /Oc): advances an aim blend: t += curve rate, w = ts4_range_lookup(t, curve);
 * w == 1 snaps out = target and t = 1, else out.x lerps and out.y/out.z go through fn_886962C0 (angle lerp, angles
 * passed as 4-byte by-value temporaries). Residue: the game keeps t in f12 (fmr f1,f12), splits the lerp into
 * fmuls+fadds (fp_contract(off) did not take) and copies the angle temporaries through a pointer to one slot. */
#pragma fp_contract(off)
struct Ts4Table2DRow { char p[0xc]; float rate; };
extern "C" float ts4_range_lookup_881899D8(float x, Ts4Table2DRow *curve);
extern "C" const float g_ts4_script_constants[];
struct Ts4Angle { float v; Ts4Angle(float x) : v(x) {} Ts4Angle(const Ts4Angle &o) : v(o.v) {} };
float *fn_886962C0(float *out, Ts4Angle from, Ts4Angle to, float t);
struct Ts4Blend { unsigned char active; char p[3]; float t; float from_x; float from_y; float from_z; };
struct Ts4Aim { float x, y, z; Ts4Blend blend; char p[0x60 - 0x20]; float out_x, out_y, out_z; };
struct Ts4Flags { char p[0xc9]; unsigned char f_c9, f_ca; };
struct Ts4AimOwner { char p[0x2c]; char *cfg; char p2[0x38 - 0x30]; Ts4Flags *flags; };
void ts4_aim_blend_update(Ts4AimOwner *self, Ts4Aim *a)
{
    Ts4Blend *b = &a->blend;
    Ts4Table2DRow *curve;
    self->flags->f_ca = 0;
    self->flags->f_c9 = 0;
    curve = (Ts4Table2DRow *)(self->cfg + 0xd0);
    if (b->active) {
        float t = curve->rate + b->t;
        b->t = t;
        float w = ts4_range_lookup_881899D8(t, curve);
        float x = a->x;
        float one = g_ts4_script_constants[0];
        if (w == one) {
            a->out_y = a->y;
            a->out_z = a->z;
            a->out_x = x;
            b->t = one;
        } else {
            float tmp;
            a->out_x = b->from_x + (x - b->from_x) * w;
            a->out_y = *fn_886962C0(&tmp, Ts4Angle(b->from_y), Ts4Angle(a->y), w);
            a->out_z = *fn_886962C0(&tmp, Ts4Angle(b->from_z), Ts4Angle(a->z), w);
        }
    }
}
