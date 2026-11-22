typedef unsigned int u32;
typedef struct Q5Entry5C { u32 key; char pad04[0x58]; } Q5Entry5C;
typedef struct Q5EntryOwner { char pad[0x5c]; Q5Entry5C *begin; Q5Entry5C *end; } Q5EntryOwner;
extern void ts4_set_flag_mirror_to_service_787_88865508(Q5EntryOwner *self, unsigned char v);
extern unsigned char fn_88869D28(Q5Entry5C *e, u32 hash);

static __inline Q5Entry5C *q5_find_key(Q5Entry5C *it, Q5Entry5C *end, u32 key)
{
    for (; it != end; it++)
        if (it->key == key)
            break;
    return it;
}

/* Swing_DLL.xex 0x8886AB08 */
unsigned char ts4_entry_try_CF0C5EA8_8886AB08(Q5EntryOwner *self, u32 key)
{
    Q5Entry5C *it;
    Q5Entry5C *end;
    unsigned char r;
    ts4_set_flag_mirror_to_service_787_88865508(self, 0);
    end = self->end;
    it = self->begin;
    r = 0;
    if (it != end) {
        it = q5_find_key(it, end, key);
        if (it != end) {
            r = fn_88869D28(it, 0xCF0C5EA8u);
            if (!r)
                ts4_set_flag_mirror_to_service_787_88865508(self, 1);
        }
    }
    return r;
}
