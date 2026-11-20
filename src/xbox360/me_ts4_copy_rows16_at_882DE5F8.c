/* 0x882DE5F8: copies count 16-byte rows from src to row `first` of the buffer returned by vtable slot 3; argument 4 is unused */
/* Matched on /Os plain and LTCG (work/army/ME/v.py chk). */
typedef struct { char b[16]; } Row;
typedef struct O O;
typedef struct { void *s[3]; char *(*base)(O *); } OVt;
struct O { OVt *vt; };
void *memcpy(void *d, const void *s, unsigned int n);
int ts4_copy_rows16_at_882DE5F8(O *o, int first, const void *src, int unused, int count)
{
    memcpy((Row *)o->vt->base(o) + first, src, count * sizeof(Row));
    return 0;
}
