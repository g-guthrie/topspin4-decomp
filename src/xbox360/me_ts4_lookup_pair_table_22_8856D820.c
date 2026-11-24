/* 0x8856D820: looks key up in the 22-entry {key, value} table lbl_88090050; 0 when absent */
/* Matched on /Os plain and LTCG (work/army/ME/v.py chk). */
typedef struct { int key; int val; } KV;
extern const KV lbl_88090050[];
int ts4_lookup_pair_table_22_8856D820(int key)
{
    unsigned int i;
    for (i = 0; i < 0x16; i++)
        if (key == lbl_88090050[i].key) return lbl_88090050[i].val;
    return 0;
}
