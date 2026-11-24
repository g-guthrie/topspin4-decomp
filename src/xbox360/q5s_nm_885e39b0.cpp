/* Swing_DLL.xex 0x885E39B0: Ts4CellGridA::SetCell: stores the low byte of v into the 4-wide byte grid at +0x80
 * (cell[i][j]); the values 4 and 5 are rejected through the assert reporter fn_885DC838 (line 1699).
 * Matched on /O1 as a C++ member: `add` takes (row, j) and `stbx` (row+j, this) only with the grid
 * reached off `this` (docs/agents/regalloc.md C1 member rule); /Oc allocates the sum to a fresh register. */
extern "C" void fn_885DC838(void *obj, const void *fmt, const void *expr, const void *msg, unsigned int line);
extern "C" const char lbl_880B4540[], lbl_880D1B30[], lbl_880B9F30[];

struct Ts4CellGridA {
    char pad00[0x80];
    unsigned char cell[1][4];

    void SetCell(int i, int j, int v);
};

void Ts4CellGridA::SetCell(int i, int j, int v)
{
    if (v >= 4 && v <= 5) {
        fn_885DC838(0, lbl_880B4540, lbl_880D1B30, lbl_880B9F30, 1699);
        return;
    }
    cell[i][j] = (unsigned char)v;
}
