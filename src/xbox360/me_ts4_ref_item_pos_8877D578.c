typedef unsigned int u32;
typedef struct Vec3 { float x, y, z; } Vec3;
typedef struct Ref { u32 svc; u32 arg; int name; } Ref;
typedef struct Item { char p0[0x30]; Vec3 pos; } Item;
typedef struct Svc Svc;
typedef struct SvcVt { void *s0[12]; Item *(*lookup)(Svc *s, int *h, u32 *arg, int flag); } SvcVt;
struct Svc { SvcVt *vt; };
extern Svc *ts4_find_service(u32 hash);
int fn_88608590(int, const char *);
extern const char lbl_880C1320[];
static __inline const char *ref_name(int *p) { return *p != -1 ? (const char *)p + *p : lbl_880C1320; }
static __inline void vec3_set(Vec3 *v, float x, float y, float z) { v->x = x; v->y = y; v->z = z; }
void fn_8877D578(Vec3 *out, Ref *r)
{
    Svc *s = ts4_find_service(r->svc);
    if (s) {
        int h = fn_88608590(0, ref_name(&r->name));
        Item *it = s->vt->lookup(s, &h, &r->arg, 0);
        vec3_set(out, it->pos.x, it->pos.y, it->pos.z);
    }
}
