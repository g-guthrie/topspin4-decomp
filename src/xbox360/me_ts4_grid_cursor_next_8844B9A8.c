/* 0x8844B9A8: Advances a packed grid cursor (bit 0 = second half, bits 1-15 column, bits 16+ row): sets bit 0 if clear; otherwise moves to the next column, wrapping to the next row at columns-1, and returns -1 past rows-1. */
/* Matched on /Oc (agAH). Plain C. */
typedef struct GridInfo { char pad[0x10]; int columns; int rows; } GridInfo;
typedef struct Grid { int unk0; int unk4; GridInfo *info; } Grid;
unsigned int fn_8844B9A8(Grid *g, unsigned int cursor)
{
    int col;
    int row;
    if ((cursor & 1) == 0)
        return cursor | 1;
    col = ((cursor >> 1) & 0x7FFF) + 1;
    row = cursor >> 16;
    if (col == g->info->columns - 1) {
        row++;
        col = 0;
        if (row == g->info->rows - 1)
            return (unsigned int)-1;
    }
    return ((row << 15) + col) << 1;
}
