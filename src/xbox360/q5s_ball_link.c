/* Ball/effect linked-record sync: push eight floats into the record, pull the ranges back out.
 * All functions here byte-match on the LTCG route (/Oc); see work/specs/Q5S/q5s_ball_link.json. */
#ifdef _MSC_VER
typedef unsigned int q5_uptr;
#else
typedef unsigned long q5_uptr;
#endif
typedef struct Ts4LinkF3 { float x, y, z; } Ts4LinkF3;

/* Swing_DLL.xex 0x888AF4F8: copy two float4s into the linked record, storing only changed values. */
typedef struct Ts4LinkF8Rec { char pad[0x6c]; float a[4]; int pad7c; float b[4]; } Ts4LinkF8Rec;
typedef struct Ts4LinkF8Src { float a[4]; float b[4]; } Ts4LinkF8Src;
typedef struct Ts4LinkF8Holder { char pad[8]; int *link; } Ts4LinkF8Holder;
static Ts4LinkF8Rec *ts4_link_f8_rec(int *o) { return *o != -1 ? (Ts4LinkF8Rec *)(*o + (char *)o) : 0; }
static __inline void ts4_set_if_changed(float *d, float s) { if (*d != s) *d = s; }
void ts4_link_push_f8_888AF4F8(Ts4LinkF8Holder *self, const Ts4LinkF8Src *s)
{
    int *o = self->link;
    if ((long)o != 0) {
        Ts4LinkF8Rec *r = ts4_link_f8_rec(o);
        if (r) {
            ts4_set_if_changed(&r->a[0], s->a[0]); ts4_set_if_changed(&r->a[1], s->a[1]);
            ts4_set_if_changed(&r->a[2], s->a[2]); ts4_set_if_changed(&r->a[3], s->a[3]);
            ts4_set_if_changed(&r->b[0], s->b[0]); ts4_set_if_changed(&r->b[1], s->b[1]);
            ts4_set_if_changed(&r->b[2], s->b[2]); ts4_set_if_changed(&r->b[3], s->b[3]);
        }
    }
}

/* Swing_DLL.xex 0x888AEEA8: pull the three vec3s and the range from the linked record into the saved copy,
 * zero the angles, restore the live copy from it, mark dirty and recompute the angles (tail call). */
extern const float lbl_8814B440;
void ts4_update_angles_b8_888ADDC8(char *self);
typedef struct Ts4LinkRangeRec {
    int pad0; Ts4LinkF3 a, b, c; float lo; float hi; char p30[0xd8]; unsigned char b108; char p109[0xb]; unsigned char b114;
} Ts4LinkRangeRec;
typedef struct Ts4LinkRangeOwner {
    char p0[8]; int link; Ts4LinkF3 a, b, c; float w; unsigned char d0, d1, d2, d3;
    char p38[0x44]; unsigned char alt; char p7d[0xf]; Ts4LinkF3 sa, sb, sc; float sw; unsigned char sel; char pb5[3];
    float b8; float bc;
} Ts4LinkRangeOwner;
static Ts4LinkRangeRec *ts4_link_range_rec(int *o) { return (Ts4LinkRangeRec *)(*o + (char *)o); }
static __inline void ts4_link_cp3(Ts4LinkF3 *d, const Ts4LinkF3 *s) { d->x = s->x; d->y = s->y; d->z = s->z; }
void ts4_link_pull_ranges_888AEEA8(Ts4LinkRangeOwner *s)
{
    if (s->link != 0) {
        Ts4LinkRangeRec *r = ts4_link_range_rec((int *)(q5_uptr)s->link);
        ts4_link_cp3(&s->sa, &r->a);
        ts4_link_cp3(&s->sb, &r->b);
        ts4_link_cp3(&s->sc, &r->c);
        s->b8 = lbl_8814B440;
        s->bc = lbl_8814B440;
        s->sw = s->alt ? r->hi : r->lo;
        r->b114 = 0;
        r->b108 = s->sel;
    }
    s->w = s->sw;
    ts4_link_cp3(&s->a, &s->sa);
    ts4_link_cp3(&s->b, &s->sb);
    ts4_link_cp3(&s->c, &s->sc);
    s->d0 = 1; s->d1 = 1; s->d2 = 1; s->d3 = 1;
    ts4_update_angles_b8_888ADDC8((char *)s);
}
