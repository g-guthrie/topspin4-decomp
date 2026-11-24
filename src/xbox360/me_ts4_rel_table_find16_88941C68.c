/* 0x88941C68: finds the 16-byte entry with key (+0xc) in the self-relative table at +0x24 (count at +4) */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct { int a, b, c, key; } E;
typedef struct { int off; unsigned int n; } R;
typedef struct { char pad[0x24]; R *r; } O;
E *ts4_rel_table_find16_88941C68(O *o, int key)
{
    R *r = o->r;
    if (r) {
        unsigned int i = 0;
        if (r->n) {
            for (; i < r->n; i++) {
                E *e = (E *)((char *)r + r->off) + i;
                if (key == e->key) return e;
            }
        }
    }
    return 0;
}
