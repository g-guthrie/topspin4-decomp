/* Swing_DLL.xex 0x884ED120: Encoded size by message type: fixed sizes for 1-5 and 7-9, 12 bytes per counted item plus 0x25 for type 6, 1 otherwise.
 * Leaf; case blocks written in the target's block order (agAE switch rule); /Oc. */
typedef struct Counts { int pad0; int a; int pad8, padc; int b; } Counts;
typedef struct Msg { unsigned char pad[8]; Counts *counts; unsigned char pad2[0x50 - 0xc]; int type; } Msg;
int fn_884ED120(const Msg *m)
{
    int size = 1;
    switch (m->type) {
    case 6: size = (m->counts->b + m->counts->a) * 12 + 0x25; break;
    case 1: case 5: size = 0x35; break;
    case 8: case 9: size = 0x41; break;
    case 3: size = 0x19; break;
    case 4: size = 0x25; break;
    case 2: case 7: size = 0x29; break;
    }
    return size;
}
