/* 0x8825A348: insertion-sort step (_Unguarded_linear_insert) for 20-byte records keyed by their first word, the value passed by value */
/* Matched on /Oc (agAL). Plain route, first try with the Dinkumware loop shape. */
typedef unsigned int u32;
typedef struct Rec20 { u32 key; u32 w[4]; } Rec20;

void ts4_rec20_unguarded_linear_insert_8825A348(Rec20 *last, Rec20 val)
{
    Rec20 *next = last - 1;
    while (val.key < next->key) {
        *last = *next;
        last = next;
        --next;
    }
    *last = val;
}
