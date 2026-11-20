/* 0x88942A90: copy point i of the owner's Vec3 array to out when the array exists and i is in range; returns 1 on success.
 * Near miss (agAL, /Oc plain, 2 off): loads match (x, y, z into f0, f13, f12), but the target stores x, y, z in
 * order; storing x, y, z gives 6 off (loads reordered), storing z, y, x gives these 2 store-order diffs. */
typedef struct Vec3 { float x, y, z; } Vec3;
typedef struct Vec3Array { Vec3 *data; int count; } Vec3Array;
typedef struct Owner { void *vt; Vec3Array *points; } Owner;

unsigned char ts4_get_point_88942A90(Owner *o, int i, Vec3 *out)
{
    Vec3Array *a = o->points;
    if (a && i >= 0 && i < a->count) {
        Vec3 *p = &a->data[i];
        float x = p->x, y = p->y, z = p->z;
        out->z = z; out->y = y; out->x = x;
        return 1;
    }
    return 0;
}
