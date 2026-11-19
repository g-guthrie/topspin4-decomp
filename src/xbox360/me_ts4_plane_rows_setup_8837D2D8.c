/* Swing_DLL.xex 0x8837D2D8: Sets row count and pitch (pitch raised to at least rows), then carves three planes of 8 row pointers from *cursor; unused rows get NULL.
 * Leaf; int args narrowed to short, *cursor = *cursor + pitch form; /Oc. */
typedef struct Planes {
    unsigned char pad[0x24];
    short rows;          /* 0x24 */
    short pitch;         /* 0x26: in shorts */
    short *row[3][8];    /* 0x28 */
} Planes;
int fn_8837D2D8(Planes *p, short **cursor, int rows, int pitch)
{
    int i;
    p->rows = (short)rows;
    p->pitch = (short)pitch;
    if ((short)pitch < (short)rows) p->pitch = (short)rows;
    for (i = 0; i < 8; i++) {
        if (i < p->rows) {
            p->row[0][i] = *cursor;
            *cursor = *cursor + p->pitch;
            p->row[1][i] = *cursor;
            *cursor = *cursor + p->pitch;
            p->row[2][i] = *cursor;
            *cursor = *cursor + p->pitch;
        } else {
            p->row[0][i] = 0;
            p->row[1][i] = 0;
            p->row[2][i] = 0;
        }
    }
    return 0;
}
