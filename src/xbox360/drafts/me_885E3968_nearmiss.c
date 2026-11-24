/* 0x885E3968: stores a byte into the 4-wide cell grid at +0x80, asserting through fn_885DC838 when the value is 4 or 5 */
/* nearmiss: 2 off; blocker: as a C++ member (virtual slot +0x54, shared by 9 vtables e.g. lbl_880BA508; `void SetCell(int i,int j,int v)` with cell[N][4] at +0x80) the operand order is right (add rX,r11,r5; stbx r6,rX,r3) but the sum lands in r9 instead of reusing r11. The plain getter at slot +0x50 (fn_885E39F8, return cell[i][j]) has the same in-place-add miss (r10 vs r11) in every form tried: row struct, inline At()/operator[], sub-object Get, byte offset, long/unsigned index, virtual with base, noreturn assert, OP1 pads 0..9, LTCG route. Solve the getter first; the setter and its twin fn_885E39B0 should follow. */
typedef struct Grid { char pad[0x80]; unsigned char cell[1][4]; } Grid;
extern void fn_885DC838(void *obj, const void *a, const void *b, const void *c, unsigned int line);
extern const char lbl_880B4540[], lbl_880D1B30[], lbl_880B9F30[];
void fn_885E3968(Grid *g, int i, int j, int v)
{
    if (v >= 4 && v <= 5) {
        fn_885DC838(0, lbl_880B4540, lbl_880D1B30, lbl_880B9F30, 1686);
        return;
    }
    g->cell[i][j] = (unsigned char)v;
}
