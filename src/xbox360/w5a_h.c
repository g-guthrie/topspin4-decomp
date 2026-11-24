/* W5A: clamp a value to [0, curve limit] where the limit is read from a self-relative table. */
#include "w5a_types.h"

static const float w5a_zero = 0.0f;

typedef struct W5aTbl { int rel; } W5aTbl;                   /* self-relative table header */
typedef struct W5aEnt { int rel; float v; } W5aEnt;          /* rel == -1: no base */
typedef struct W5aCfg { unsigned char pad00[0x74]; unsigned char pad74[0x9f8 - 0x74]; float k9f8; } W5aCfg;
typedef struct W5aCfgp { unsigned char pad00[0x74]; char *cfg; } W5aCfgp;
typedef struct W5aSelf { unsigned char pad00[0x18]; W5aCfgp *c; } W5aSelf;

static __inline float w5a_max(float a, float b) { return (a - b >= w5a_zero) ? a : b; }
static __inline float w5a_min(float a, float b) { return (a - b >= w5a_zero) ? b : a; }

void ts4_clamp_to_table_88691B38(W5aSelf *self, W5aTbl *t, int idx, float *val)
{
    W5aTbl *h;
    W5A_PAD3
    W5aEnt *e;
    if (t->rel == -1)
        return;
    h = (W5aTbl *)((char *)t + t->rel);
    e = (W5aEnt *)((char *)h + idx * 8 + h->rel);
    if (e->rel != -1) {
        float base = *(float *)((char *)e + e->rel);
        float lim = (e->v - base) * ((W5aCfg *)self->c->cfg)->k9f8 + base;
        *val = w5a_min(w5a_max(*val, 0.0f), lim);
    } else {
        *val = w5a_min(w5a_max(*val, 0.0f), e->v);
    }
}
