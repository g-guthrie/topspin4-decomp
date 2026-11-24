/* 0x886EDDF8: finds the 0xBC-byte entry in [+0x1C,+0x20) whose +0xA4 word equals *a and whose +0x84 word equals *b;
 * 0 if none.
 * Matched (/Oc plain): the target loads *b before it->b but compares `cmplw it->b,*b`. The key is a one-word struct
 * copied into a block local (matching-tips, 0x8887B380): the copy keeps the *b load first while the compare follows
 * the written order. */
typedef struct Ts4Key2 { unsigned int id; } Ts4Key2;
typedef struct Ts4Key2Ent {
    char pad_00[0x84];
    unsigned int b;
    char pad_88[0xA4 - 0x88];
    unsigned int a;
    char pad_a8[0xBC - 0xA8];
} Ts4Key2Ent;
typedef struct Ts4Key2Table { char pad_00[0x1C]; Ts4Key2Ent *begin; Ts4Key2Ent *end; } Ts4Key2Table;

Ts4Key2Ent *ts4_find_entry_by_two_keys_886EDDF8(Ts4Key2Table *t, const Ts4Key2 *a, const Ts4Key2 *b)
{
    Ts4Key2Ent *it = t->begin, *end = t->end;
    for (; it != end; it++) {
        if (it->a == a->id) {
            Ts4Key2 kb;
            kb = *b;
            if (it->b == kb.id)
                return it;
        }
    }
    return 0;
}
