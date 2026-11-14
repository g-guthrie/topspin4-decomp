/* Loader_DLL.xex 0x83464630-0x834646E8, executable version 0.0.0.3. */
/* Statically linked zlib 1.1.4 (trees.c): _tr_tally (second copy of the library). */
#include "l45_zlib_ds.h"

extern const uch lbl_8307BC70[];
extern const uch lbl_8307BA70[];
extern const Ts4lStaticDesc lbl_8307BE88;

#define d_code(dist) ((uch)((dist) < 256 ? lbl_8307BA70[dist] : lbl_8307BA70[256 + ((dist) >> 7)]))

int ts4l_tr_tally_83464630(Ts4lDeflateState *s, unsigned dist, unsigned lc)
{
    s->d_buf[s->last_lit] = (ush)dist;
    s->l_buf[s->last_lit++] = (uch)lc;
    if (dist == 0) {
        s->dyn_ltree[lc].fc++;
    } else {
        s->matches++;
        dist--;
        s->dyn_ltree[lbl_8307BC70[lc] + 256 + 1].fc++;
        s->dyn_dtree[d_code(dist)].fc++;
    }
    return (s->last_lit == s->lit_bufsize - 1);
}
