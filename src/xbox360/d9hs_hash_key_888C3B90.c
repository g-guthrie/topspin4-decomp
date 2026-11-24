/* Swing_DLL.xex 0x888C3B90-0x888C3BE8, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef struct Out { u32 f0, f4, f8; } Out;
typedef struct Ts4Holder { char pad[0x40]; Out key; } Ts4Holder;
extern void ts4_handle_forward_88610778(Out *out, Out *in, u32 *key);

Out *ts4_hash_key_888C3B90(Out *out, Ts4Holder *h, u32 key)
{
    Out cp;
    cp = h->key;
    ts4_handle_forward_88610778(out, &cp, &key);
    return out;
}
