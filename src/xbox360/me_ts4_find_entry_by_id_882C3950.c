/* 0x882C3950: returns the 0x24-byte entry with this id from lbl_88002708+0x28 up to lbl_88B310D4, else the table head (default) */
/* Matched on /Os plain and LTCG (work/army/ME/v.py chk). */
typedef struct { int id; char pad[0x20]; } E;
typedef struct { char pad[0x28]; E e[1]; } Tbl;
extern Tbl lbl_88002708;
extern E *lbl_88B310D4;
void *ts4_find_entry_by_id_882C3950(int id)
{
    E *e;
    for (e = lbl_88002708.e; e < lbl_88B310D4; e++)
        if (id == e->id) return e;
    return &lbl_88002708;
}
