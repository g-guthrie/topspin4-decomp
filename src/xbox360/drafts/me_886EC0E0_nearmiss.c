/* DRAFT (1 instruction off on /Oc): Swing_DLL.xex 0x886EC0E0, font glyph lookup through u16 [first,last] ranges, falling back to '_' by tail recursion.
 * Only the final lhzx operand order differs (target base-first r9,r11). Tried 5 index forms, an inline range accessor, a first local and int i. */
typedef struct GlyphRange { unsigned short first, last; } GlyphRange;
typedef struct Glyph { unsigned char data[0x1c]; } Glyph;
typedef struct Font {
    unsigned char pad[0x14];
    unsigned int range_count;   /* 0x14 */
    GlyphRange *ranges;         /* 0x18 */
    unsigned char pad1c[4];
    Glyph *glyphs;              /* 0x20 */
} Font;

Glyph *fn_886EC0E0(Font *f, unsigned short ch)
{
    unsigned int i = 0;
    int base = 0;
    for (; i < f->range_count; i++) {
        GlyphRange *r = &f->ranges[i];
        if (ch >= r->first && ch <= r->last) break;
        base += f->ranges[i].last - f->ranges[i].first + 1;
    }
    if (i >= f->range_count) return fn_886EC0E0(f, '_');
    return &f->glyphs[ch - f->ranges[i].first + base];
}
