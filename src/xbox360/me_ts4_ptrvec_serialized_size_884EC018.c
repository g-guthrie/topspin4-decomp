/* Swing_DLL.xex 0x884EC018: serialized size of a pointer list: 4 bytes for the count plus fn_884ED120 of each element
 * (count re-read each pass). Matches on /Oc /Os. */
typedef struct PtrVec { void **items; int count; } PtrVec;
int fn_884ED120(void *item);

int fn_884EC018(PtrVec *v)
{
    int i;
    int size = 4;
    for (i = 0; i < v->count; i++)
        size += fn_884ED120(v->items[i]);
    return size;
}
