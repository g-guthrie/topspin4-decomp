/* 0x886468B8: reset of a float block (zeroes, with 10.0 in the middle vector's y). */
extern const float lbl_880C8FB0; /* 10.0f */
typedef struct MeV3 { float x, y, z; } MeV3;
typedef struct MeV2 { float x, y; } MeV2;
typedef struct MeFloatBlock {
    char pad[0x20];
    unsigned v20;
    char p24[4];
    MeV2 p;
    MeV3 a;
    char p3c[0x28];
    MeV3 b;
} MeFloatBlock;
static __inline void me_v3_set(MeV3 *v, float x, float y, float z) { v->x = x; v->y = y; v->z = z; }
void ts4_reset_floats_886468B8(MeFloatBlock *s)
{
    s->v20 = 0;
    s->p.x = 0.0f;
    s->p.y = 0.0f;
    me_v3_set(&s->a, 0.0f, lbl_880C8FB0, 0.0f);
    me_v3_set(&s->b, 0.0f, 0.0f, 0.0f);
}
