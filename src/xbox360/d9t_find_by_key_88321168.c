/* Swing_DLL.xex 0x88321168-0x883212CC, executable version 0.0.0.3. */
typedef struct Ts4Item88321168 { char pad0[0x30]; char *next; char pad1[0x18]; unsigned key; } Ts4Item88321168;
typedef struct Ts4Owner88321168 { char pad0[0x19c]; char sentinel[0x30]; char *head; } Ts4Owner88321168;
int ts4_find_by_key_88321168(Ts4Owner88321168 *o, unsigned key, Ts4Item88321168 **out)
{
    Ts4Item88321168 *sent;
    Ts4Item88321168 *n;
    if (out == 0) { return 0x25; }
    sent = (Ts4Item88321168 *)o->sentinel;
    *out = 0;
    n = o->head ? (Ts4Item88321168 *)(o->head - 0x30) : 0;
    while (n != sent) {
        if (n->key == key) {
            *out = n;
            return 0;
        }
        n = n->next ? (Ts4Item88321168 *)(n->next - 0x30) : 0;
    }
    return 0x44;
}
typedef struct Ts4Item883211E0 { char pad0[0x5c]; char *next; char pad1[0x24]; unsigned key; } Ts4Item883211E0;
typedef struct Ts4Owner883211E0 { char pad0[0x104]; char sentinel[0x5c]; char *head; } Ts4Owner883211E0;
int ts4_find_by_key_883211E0(Ts4Owner883211E0 *o, unsigned key, Ts4Item883211E0 **out)
{
    Ts4Item883211E0 *sent;
    Ts4Item883211E0 *n;
    if (out == 0) { return 0x25; }
    sent = (Ts4Item883211E0 *)o->sentinel;
    *out = 0;
    n = o->head ? (Ts4Item883211E0 *)(o->head - 0x5c) : 0;
    while (n != sent) {
        if (n->key == key) {
            *out = n;
            return 0;
        }
        n = n->next ? (Ts4Item883211E0 *)(n->next - 0x5c) : 0;
    }
    return 0x44;
}
typedef struct Ts4Item88321258 { char pad0[0x34]; char *next; char pad1[0x14]; unsigned key; } Ts4Item88321258;
typedef struct Ts4Owner88321258 { char pad0[0x218]; char sentinel[0x34]; char *head; } Ts4Owner88321258;
int ts4_find_by_key_88321258(Ts4Owner88321258 *o, unsigned key, Ts4Item88321258 **out)
{
    Ts4Item88321258 *sent;
    Ts4Item88321258 *n;
    if (out == 0) { return 0x25; }
    sent = (Ts4Item88321258 *)o->sentinel;
    *out = 0;
    n = o->head ? (Ts4Item88321258 *)(o->head - 0x34) : 0;
    while (n != sent) {
        if (n->key == key) {
            *out = n;
            return 0;
        }
        n = n->next ? (Ts4Item88321258 *)(n->next - 0x34) : 0;
    }
    return 0x44;
}
