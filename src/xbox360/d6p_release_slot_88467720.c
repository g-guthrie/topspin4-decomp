/* Swing_DLL.xex 0x88467720-0x88467768, executable version 0.0.0.3. */
typedef struct Ts4Entry8c { unsigned char a; unsigned char b; unsigned short key; unsigned pad; } Ts4Entry8c;
typedef struct Ts4EntryTable8c { char pad[0x32]; unsigned char count; char pad2; Ts4Entry8c e[1]; } Ts4EntryTable8c;
void ts4_release_slot_88467720(Ts4EntryTable8c *t, unsigned short key)
{
    int n = t->count;
    int i = 0;
    Ts4Entry8c *p;
    for (; i < n; i++) {
        p = t->e + i;
        if (p->key == key) {
            p->a = 0;
            p->b = 0;
            return;
        }
    }
}
