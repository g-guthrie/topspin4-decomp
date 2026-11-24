/* 0x885E39B0: stores a byte into the 4-wide cell grid at +0x80, asserting through fn_885DC838 when the value is 4 or 5 */
/* Near miss (agAH): 2 off: target adds j to the scaled row before adding the object (add r11,r11,r5; stbx r6,r11,r3); every index spelling tried adds the object first. */
typedef struct Grid { char pad[0x80]; unsigned char cell[1][4]; } Grid;
extern void fn_885DC838(void *obj, const void *a, const void *b, const void *c, unsigned int line);
extern const char lbl_880B4540[], lbl_880D1B30[], lbl_880B9F30[];
void fn_885E39B0(Grid *g, int i, int j, int v)
{
    if (v >= 4 && v <= 5) {
        fn_885DC838(0, lbl_880B4540, lbl_880D1B30, lbl_880B9F30, 1699);
        return;
    }
    g->cell[i][j] = (unsigned char)v;
}
