/* CW31 part c: script callback that builds a link record inline and submits it (see cx21_near_e.cpp for the form). */
typedef unsigned long ts4_word;
typedef unsigned long long ts4_u64;

extern "C" {
extern char lbl_880D1F18[];
ts4_word ts4_node_dispatch_8860DCF8(ts4_word heap, ts4_word size, ts4_word align, ts4_word flags);
void ts4_guarded_update_88151560(void *state, void *record);
extern ts4_word g_ts4_session_state;
extern ts4_word g_ts4_online_state;
}

#ifdef _MSC_VER
#define TS4_ALIGN8 __declspec(align(8))
#else
#define TS4_ALIGN8 __attribute__((aligned(8)))
#endif
inline void *operator new(decltype(sizeof(0)), void *where) { return where; }

struct TS4_ALIGN8 ts4_link_pair { ts4_word offset, object, zero0, zero1; };

#pragma pack(push, 4)
struct ts4_link_record {
    ts4_word owner;
    ts4_u64 pair_lo;
    ts4_u64 pair_hi;
    ts4_word count;
    unsigned char active;
    ts4_link_record(ts4_word who, const ts4_link_pair &pair)
    {
        owner = who;
        count = 0;
        active = 0;
        pair_lo = *(const ts4_u64 *)&pair.offset;
        pair_hi = *(const ts4_u64 *)&pair.zero0;
    }
};
#pragma pack(pop)

/* 0x88787AD8: when the online state has a session, create a link record in a fresh object and submit it */
extern "C" ts4_word ts4_script_submit_link_record_88787AD8(void *context)
{
    (void)context;
    if (*(int *)(g_ts4_online_state + 0x1c) != 0) {
        ts4_word ctx = *(ts4_word *)(g_ts4_session_state + 0x1c);
        ts4_link_pair pair;
        ts4_word obj;
        ts4_word made;
        pair.zero0 = 0;
        pair.zero1 = 0;
        obj = ts4_node_dispatch_8860DCF8(*(ts4_word *)(ctx + 0x2c), 0x30, 4, 2);
        if (obj != 0) {
            *(volatile ts4_word *)(obj + 4) = 0;
            *(volatile ts4_word *)(obj + 0) = (ts4_word)lbl_880D1F18;
            *(volatile ts4_word *)(obj + 8) = 0xa0bde62eUL;
            *(volatile ts4_word *)(obj + 0xc) = 1;
            *(volatile ts4_word *)(obj + 0x10) = 0;
            made = obj;
        } else {
            made = 0;
        }
        pair.object = made;
        pair.offset = 0x14;
        ts4_guarded_update_88151560((void *)g_ts4_session_state, new ((void *)(obj + 0x14)) ts4_link_record(0xebf56a9aUL, pair));
    }
    return 0;
}
