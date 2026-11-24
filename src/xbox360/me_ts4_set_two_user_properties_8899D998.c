/* Swing_DLL.xex 0x8899D998: write two property pairs through 88995AB8: slot 0x34 gets a 64-bit property 0x20000021 (type 2) holding a, then property 0x10000044 (type 1) holding *value at the current slot; then the same for slot 0x35 with b.
 * /Oc. One UserProperty local reused for all four calls; the unsigned args widen to the 64-bit union member (rldicl). */
typedef struct UserProperty { unsigned int id; int pad; unsigned char type; char pad2[7]; union { unsigned int u32; unsigned long long u64; } v; } UserProperty;
typedef struct PropSink { char pad[0x6c]; unsigned int slot; } PropSink;
void fn_88995AB8(PropSink *s, unsigned int slot, const UserProperty *p);

void fn_8899D998(PropSink *s, unsigned int a, const unsigned int *value, unsigned int b)
{
    UserProperty p;
    s->slot = 0x34;
    p.id = 0x20000021;
    p.type = 2;
    p.v.u64 = a;
    fn_88995AB8(s, 0x34, &p);
    p.id = 0x10000044;
    p.type = 1;
    p.v.u32 = *value;
    fn_88995AB8(s, s->slot, &p);
    s->slot = 0x35;
    p.id = 0x20000021;
    p.type = 2;
    p.v.u64 = b;
    fn_88995AB8(s, 0x35, &p);
    p.id = 0x10000044;
    p.type = 1;
    p.v.u32 = *value;
    fn_88995AB8(s, s->slot, &p);
}
