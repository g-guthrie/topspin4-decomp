/* Q5h3: copy a flag and two float3 vectors into a self-relative target (Top Spin 4, Xbox 360, Swing_DLL.xex). */
#include "vx1_vector.h"
typedef unsigned char u8;

typedef struct Q5h3Float3 { float x, y, z; } Q5h3Float3;
/* Source record: flag byte at +0x40, two vec4s at +0x50 and +0x60 (only x, y, z are used). */
typedef struct Q5h3XformSrc { char p00[0x40]; u8 flag; char p41[0xf]; __vector4 a; __vector4 b; } Q5h3XformSrc;
/* Target record: two float3s at +0x98 / +0xa4 and the flag byte at +0xb0. */
typedef struct Q5h3XformDst { char p00[0x98]; Q5h3Float3 a; Q5h3Float3 b; u8 flag; } Q5h3XformDst;
/* Self-relative header: the record lives at (char *)hdr + hdr->off. */
typedef struct Q5h3RelHdr { int off; } Q5h3RelHdr;
typedef struct Q5h3XformOwner { char p00[8]; Q5h3RelHdr *hdr; /* +0x08 */ } Q5h3XformOwner;

/* x, y, z of v through the stack (stvewx of each splat). */
static __inline void q5h3_store_float3(Q5h3Float3 *dst, __vector4 v)
{
    __stvewx(__vspltw(v, 0), dst, 0);
    __stvewx(__vspltw(v, 1), dst, 4);
    __stvewx(__vspltw(v, 2), dst, 8);
}

/* 0x888B0D50: same body as 0x888B09A0 (byte-identical target code), under its own name.
 * When the owner has a record, copy src's flag (only if it differs) and its two vectors into it.
 * The five unused locals set the function-local symbol number of `h`, which fixes the operand order of the
 * self-relative add (matching-tips.md, "Operand order of indexed add"). */
void ts4_xform_copy_to_rel_888B0D50(Q5h3XformOwner *self, Q5h3XformSrc *src)
{
    int op1_pad0 = 0, op1_pad1 = 0, op1_pad2 = 0, op1_pad3 = 0, op1_pad4 = 0;
    Q5h3RelHdr *h = self->hdr;
    (void)op1_pad0; (void)op1_pad1; (void)op1_pad2; (void)op1_pad3; (void)op1_pad4;
    if ((long)h != 0) {
        Q5h3XformDst *d = (Q5h3XformDst *)(h->off + (char *)h);
        Q5h3Float3 t;
        if (src->flag != d->flag) d->flag = src->flag;
        q5h3_store_float3(&t, src->a);
        d->a.x = t.x; d->a.y = t.y; d->a.z = t.z;
        q5h3_store_float3(&t, src->b);
        d->b.x = t.x; d->b.y = t.y; d->b.z = t.z;
    }
}
