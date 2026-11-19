
/* Finds the 28-byte entry whose key matches and sets its flag byte. */
typedef struct { int first; int n; } RelEntTab;
typedef struct { unsigned int key; char pad[0x14]; unsigned char flag; char p2[3]; } RelEnt28;
extern RelEntTab *fn_888EC548(void);
void ts4_relent_set_flag_888F0798(unsigned int key) {
    RelEntTab *t = fn_888EC548(); int i;
    if (!t) return;
    for (i = 0; i < t->n; i++) {
        RelEnt28 *e = (RelEnt28 *)((char *)t + t->first + i * 28);
        if (e->key == key) { e->flag = 1; return; }
    }
}
