/* Swing_DLL.xex 0x88661560 */
struct W7bBase { char pad[0x60]; };
struct W7bSel { char pad[4]; unsigned char b4; };
struct W7bO { char pad[0x28]; char *p28; };
extern void *ts4_find_record_by_key_8826C818(void *);
int ts4_has_record_88661560(struct W7bO *o, struct W7bSel *s, unsigned char flag)
{
    void *r;
    if (s->b4) {
        if (flag) r = ts4_find_record_by_key_8826C818(o->p28 + 0x78);
        else r = ts4_find_record_by_key_8826C818(o->p28 + 0x60);
    } else {
        if (flag) r = ts4_find_record_by_key_8826C818(o->p28 + 0x84);
        else r = ts4_find_record_by_key_8826C818(o->p28 + 0x6c);
    }
    return 0 != r;
}

/* Swing_DLL.xex 0x886C4278: clear the four vectors, then fill the pair array with -1 */
struct W7bPair4278 { short a, b; };
struct W7bO4278 { char pad[8]; struct W7bPair4278 *begin; struct W7bPair4278 *end; };
extern struct W7bO4278 *ts4_clear_four_vectors_886C3820(struct W7bO4278 *a, struct W7bO4278 *b);
void ts4_reset_pairs_886C4278(struct W7bO4278 *o)
{
    struct W7bPair4278 v;
    struct W7bPair4278 *p;
    struct W7bPair4278 *end;
    o = ts4_clear_four_vectors_886C3820(o, o);
    v.a = -1;
    v.b = -1;
    end = o->end;
    for (p = o->begin; p != end; p++) *p = v;
}
