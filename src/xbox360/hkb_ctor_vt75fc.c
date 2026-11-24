/* HKB: small constructor with vtable lbl_880D75FC (plain route, /Oc). */

extern char lbl_880D75FC[];
extern const float g_ts4_script_constants[];

typedef struct HkbWord2 { unsigned a, b; } HkbWord2;
typedef struct HkbCtor14 {
    void *vt;
    HkbWord2 w;
    unsigned c;
    unsigned pad10;
    float f;
    unsigned d;
} HkbCtor14;

static __inline void hkb_word2_zero(HkbWord2 *v)
{
    v->a = 0;
    v->b = 0;
}

/* Swing_DLL.xex 0x886CBBA0 */
void ts4_ctor_vt75fc_886CBBA0(HkbCtor14 *s)
{
    s->vt = lbl_880D75FC;
    hkb_word2_zero(&s->w);
    {
        unsigned *q = &s->c;
        float k = g_ts4_script_constants[87];
        *q = 0;
        s->f = k;
    }
    s->d = 0;
}
