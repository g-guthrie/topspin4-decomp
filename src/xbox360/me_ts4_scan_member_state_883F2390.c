/* Swing_DLL.xex 0x883F2390: scans every group (list +0xC) and member (list +0x34); a member with flag 2 or 0x10 at +0x24 is
 * probed itself, otherwise each child on its +0x78 list is: the timer at +0x34 (busy byte; 0x24/0xB also count as idle) and the
 * handle at +0x28 (state, ready byte) set *flags bits 0x40 (ready), 0x2 (state not 0/6) and 0x10 (busy, which ends that scan). agAD: /O1. */
typedef struct Link { struct Link *next; } Link;
typedef struct Probe { int pad0[9]; unsigned int flags24; void *handle28; int pad2c[2]; void *timer34; } Probe;
typedef struct Member { int pad0[9]; unsigned int flags24; void *handle28; int pad2c[2]; void *timer34; char pad38[0x78 - 0x38]; Link children; } Member;
typedef struct Group { int pad0[0xd]; Link members; } Group;
typedef struct Owner { int pad0[3]; Link groups; } Owner;
int ts4_if_call_seq_fn_88322CA8_88317788(void *timer, unsigned char *busy);
int ts4_if_get_fn_8832BFC0_88316BB0(void *h, int *state, int a, unsigned char *ready);

int fn_883F2390(Owner *o, unsigned int *flags)
{
    Link *g, *m, *k;
    unsigned char busy;
    int r;
    for (g = o->groups.next; g != &o->groups; g = g->next) {
        Group *gi = g ? (Group *)((char *)g - 4) : 0;
        for (m = gi->members.next; m != &gi->members; m = m->next) {
            Member *mi = m ? (Member *)((char *)m - 4) : 0;
            if ((mi->flags24 & 2) || (mi->flags24 & 0x10)) {
                unsigned char ready;
                int state;
                r = ts4_if_call_seq_fn_88322CA8_88317788(mi->timer34, &busy);
                if (r == 0x24 || r == 0xb)
                    busy = 0;
                else if (r != 0)
                    return r;
                if (mi->handle28) {
                    r = ts4_if_get_fn_8832BFC0_88316BB0(mi->handle28, &state, 0, &ready);
                    if (r)
                        return r;
                    if (ready)
                        *flags |= 0x40;
                    if (state != 0 && state != 6)
                        *flags |= 2;
                }
                if (busy) {
                    *flags |= 0x10;
                    break;
                }
            } else {
                for (k = mi->children.next; k != &mi->children; k = k->next) {
                    Probe *ki = k ? (Probe *)((char *)k - 4) : 0;
                    unsigned char ready;
                    int state;
                    r = ts4_if_call_seq_fn_88322CA8_88317788(ki->timer34, &busy);
                    if (r == 0x24 || r == 0xb)
                        busy = 0;
                    else if (r != 0)
                        return r;
                    if (ki->handle28) {
                        r = ts4_if_get_fn_8832BFC0_88316BB0(ki->handle28, &state, 0, &ready);
                        if (r)
                            return r;
                        if (ready)
                            *flags |= 0x40;
                        if (state != 0 && state != 6)
                            *flags |= 2;
                    }
                    if (busy) {
                        *flags |= 0x10;
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
