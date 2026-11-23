/* W6B context: stand-in for ts4_path_sample_8867A7C0 (clobbers r3 and r5-r12 but not r4), compile with flags(/Ob1). */
#include "w6b_types.h"

typedef struct W6dCtxP78 { unsigned char pad[0x90]; __vector4 vec90; } W6dCtxP78;
typedef struct W6dCtxObj { unsigned char pad[0x78]; W6dCtxP78 *p78; } W6dCtxObj;

void ts4_path_sample_8867A7C0(W6dCtxObj *self, __vector4 *out, float t)
{
    __vector4 tmp[2];
    int i = (int)t;
    int n = *(int *)((char *)self->p78 + 0x384);
    tmp[0] = self->p78->vec90;
    tmp[1] = __vaddfp(tmp[0], tmp[0]);
    *out = tmp[(i + 1) % (n | 1) & 1];
}
