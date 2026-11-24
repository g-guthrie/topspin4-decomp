/* Swing_DLL.xex 0x88209E80: Ts4TextGrid::FitCell — virtual slot 14 of the
 * vtable at lbl_880E9E98. Measures the grid's text with the font returned by
 * virtual slot 13 (fn_88209810 fills a width/height pair) and grows the row
 * height at rowHeights[row] and the column width at colWidths[col] to fit.
 * Byte-exact only as a C++ member: `this` is numbered after (col, row), which
 * gives the target's lfsx operand order at both sites; the extern "C" form
 * with the object first is 2 off (regalloc.md C1 member rule).
 * Slots 0..12 are not identified yet; they are declared only to place Font
 * and FitCell at their vtable offsets (+0x34, +0x38). */
struct Ts4TextSize {
    float w;
    float h;
};

extern "C" Ts4TextSize *fn_88209810(Ts4TextSize *out, void *text, void *font);

struct Ts4TextGrid {
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void *Font();
    virtual void FitCell(int col, int row);

    int unk04;
    void *text;             /* +0x08 */
    char unk0C[0x14];
    float *colWidths;       /* +0x20 */
    char unk24[0xc];
    float *rowHeights;      /* +0x30 */
};

void Ts4TextGrid::FitCell(int col, int row)
{
    Ts4TextSize s;
    fn_88209810(&s, text, Font());
    if (rowHeights[row] < s.h)
        rowHeights[row] = s.h;
    if (colWidths[col] < s.w)
        colWidths[col] = s.w;
}
