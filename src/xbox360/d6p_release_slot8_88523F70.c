/* Swing_DLL.xex 0x88523F70-0x88523FBC, executable version 0.0.0.3. */
typedef struct Ts4Entry8d { unsigned char a; unsigned char b; unsigned short key; unsigned pad; } Ts4Entry8d;
typedef struct Ts4Hdr8d { char pad[2]; unsigned char count; char pad2; Ts4Entry8d e[1]; } Ts4Hdr8d;
void ts4_release_slot_88523F70(int unused, char *t, unsigned short key)
{
    Ts4Hdr8d *h = (Ts4Hdr8d *)(t + 0xC);
    int n = h->count;
    int i = 0;
    Ts4Entry8d *p;
    (void)unused;
    for (; i < n; i++) {
        p = h->e + i;
        if (p->key == key) {
            p->a = 0;
            p->b = 0;
            return;
        }
    }
}
