/* Swing_DLL.xex 0x888C30F0: Copies camera set A or B (position, target Vec3s) into the two global views; the first view (optional) re-reads the position through the pointer.
 * /Oc. Pointer selects written 'flag == 0 ? &b : &a' (0x4c default, then override), globals read once into block locals. */
typedef struct Vec3 { float x, y, z; } Vec3;
typedef struct CamSet {
    unsigned char pad[0x34];
    Vec3 pos_a;     /* 0x34 */
    Vec3 target_a;  /* 0x40 */
    Vec3 pos_b;     /* 0x4c */
    Vec3 target_b;  /* 0x58 */
} CamSet;
typedef struct ViewA { unsigned char pad[0x2b8]; Vec3 target; Vec3 pos; } ViewA;
typedef struct ViewB { unsigned char pad[0xbc]; Vec3 pos; Vec3 target; } ViewB;

extern ViewA *lbl_88D45A60;
extern ViewB *lbl_88D45AD4;

void fn_888C30F0(CamSet *c, int use_a, unsigned char apply)
{
    Vec3 *pp = use_a == 0 ? &c->pos_b : &c->pos_a;
    Vec3 pos = *pp;
    Vec3 *tp = use_a == 0 ? &c->target_b : &c->target_a;
    Vec3 target = *tp;
    if (apply) {
        ViewA *a = lbl_88D45A60;
        if (a) {
            a->pos = *pp;
            a->target = target;
        }
        {
            ViewB *b = lbl_88D45AD4;
            b->pos = pos;
            b->target = target;
        }
    }
}
