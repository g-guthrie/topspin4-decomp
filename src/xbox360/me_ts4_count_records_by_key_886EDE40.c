/* Swing_DLL.xex 0x886EDE40: counts the 0xBC-byte records in [+0x1c, +0x20) whose word at +0xc equals *key (8-bit count).
 * agO: lookalike of 888C2FD8; plain and LTCG. */
typedef struct Rec { char pad[0xc]; unsigned key; char rest[0xbc - 0x10]; } Rec;
typedef struct Obj { char pad[0x1c]; Rec *first; Rec *last; } Obj;

unsigned char fn_886EDE40(Obj *o, const unsigned *key)
{
    unsigned char n = 0;
    Rec *r;
    for (r = o->first; r != o->last; r++) {
        if (r->key == *key)
            n++;
    }
    return n;
}
