/* Swing_DLL.xex 0x8836E4D0: validates the reader header (+0x16C): version 0xFFFE needs id (+0x18) equal to one of the two
 * GUIDs at lbl_8802B8D8, else version 1 or 3; then kind (+0xE) 8 is rejected. 0x2d = bad header. agAE: /Oc.
 * NEAR MISS (3 off): the second inlined memcmp sets up its three pointers as (lbl+16, h->id, h->id+16) in the target and
 * (h->id, h->id+16, lbl+16) here. No effect: lbl typed as Guid[2], u8[32] or a struct, swapped memcmp args, ||/else-if/
 * shared id local, /Os, /Ob2. The memcmp intrinsic (#pragma intrinsic) is what gives the cmpw byte loop. */
typedef struct Guid { unsigned char b[16]; } Guid;
typedef struct Header { unsigned short version; char pad2[0xe - 2]; unsigned short kind; char pad10[8]; Guid id; } Header;
typedef struct Reader { char pad[0x16c]; Header *hdr; } Reader;
extern const Guid lbl_8802B8D8[2];
int memcmp(const void *a, const void *b, unsigned int n);
#pragma intrinsic(memcmp)
int fn_8836E4D0(Reader *r)
{
    Header *h = r->hdr;
    if (!h) return 0x2d;
    if (h->version == 0xfffe) {
        if (memcmp(&h->id, &lbl_8802B8D8[0], sizeof(Guid)) && memcmp(&h->id, &lbl_8802B8D8[1], sizeof(Guid))) return 0x2d;
    } else if (h->version != 1 && h->version != 3) {
        return 0x2d;
    }
    return h->kind == 8 ? 0x2d : 0;
}
