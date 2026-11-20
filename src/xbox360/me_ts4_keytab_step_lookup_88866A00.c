/* 0x88866A00: step lookup in a self-relative table of {int key; a; b} rows: last row with (float)key <= x (or the first row); returns a or b by flag, 0 for an empty table (agAY). Plain /Oc; result local preset to 0 gives the early li r3,0. */
typedef unsigned char u8;
typedef struct Key { int key; int a; int b; } Key;
typedef struct KeyTab { int rel; int count; } KeyTab;
static Key *kt_begin(KeyTab *t) { Key *r = 0; if (t->rel != -1) r = (Key *)((char *)t + t->rel); return r; }
static Key *kt_end(KeyTab *t) { Key *r = 0; if (t->rel != -1) r = (Key *)((char *)t + (t->rel + t->count * sizeof(Key))); return r; }
int ts4_keytab_step_lookup_88866A00(KeyTab *t, float x, u8 first)
{
    int r = 0;
    Key *b = kt_begin(t);
    Key *e = kt_end(t);
    Key *p;
    if (e != b) {
        for (p = b; e != p; p++)
            if ((float)p->key > x) break;
        if (p != b) p--;
        if (first) r = p->a;
        else r = p->b;
    }
    return r;
}
