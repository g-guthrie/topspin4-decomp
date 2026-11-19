/* 0x8843B870: Has each part write its vectors at the running output position (vt slot 10), advancing by its count (slot 9) of 16-byte vectors. Returns out. */
/* Matched on /Oc (agAH). Plain loop. */
typedef struct Vec4 { float x, y, z, w; } Vec4;
typedef struct Part Part;
typedef struct PartVt { void *s[9]; int (*count)(Part *); void (*write)(Part *, Vec4 *); } PartVt;
struct Part { PartVt *vt; };
typedef struct Group { char p0[0x44]; Part **parts; int nparts; } Group;
Vec4 *fn_8843B870(Group *g, Vec4 *out)
{
    Vec4 *p = out;
    int i;
    for (i = 0; i < g->nparts; i++) {
        Part *part = g->parts[i];
        part->vt->write(part, p);
        p += part->vt->count(part);
    }
    return out;
}
