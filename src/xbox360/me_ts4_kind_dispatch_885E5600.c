/* 0x885E5600: calls the handler in the 8-byte table lbl_880BD018 chosen by lbl_88C43458[i].kind (+0x30, stride 0x34) */
/* Matched on /Os plain and LTCG (work/army/ME/v.py chk). */
typedef struct { char pad[0x30]; int kind; } Ent;
typedef struct { int (*fn)(int); int x; } Op;
extern Ent lbl_88C43458[];
extern const Op lbl_880BD018[];
int ts4_kind_dispatch_885E5600(int i)
{
    return lbl_880BD018[lbl_88C43458[i].kind].fn(i);
}
