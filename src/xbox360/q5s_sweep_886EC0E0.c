/* Top Spin 4 (Xbox 360, Swing_DLL.xex) 0x886EC0E0: font glyph lookup through u16 [first,last] ranges, falling back to '_' by tail recursion.
 * Byte-exact form found by tools/perm_auto.py --targeted from drafts/me_886EC0E0_nearmiss.c (Q5S sweep, 2026-11-24): the alias local(s) of the parameter change which symbol the indexed access goes through (regalloc.md C1/R2).
 * See work/specs/Q5S/sweep_886EC0E0.json for route and flags. */
typedef struct GlyphRange { unsigned short first, last; } GlyphRange;
typedef struct Glyph { unsigned char data[0x1c]; } Glyph;
typedef struct Font {
    unsigned char pad[0x14];
    unsigned int range_count;   /* 0x14 */
    GlyphRange *ranges;         /* 0x18 */
    unsigned char pad1c[4];
    Glyph *glyphs;              /* 0x20 */
} Font;

Glyph *ts4_font_find_glyph_886EC0E0(Font *f, unsigned short ch)
{ Font* font = f; 
    unsigned int i = 0;
    int base = 0;
    for (; i < font->range_count; i++) {
        GlyphRange *r = &font->ranges[i];
        if (ch >= r->first && ch <= r->last) break;
        base += font->ranges[i].last - font->ranges[i].first + 1;
    }
    if (i >= font->range_count) return ts4_font_find_glyph_886EC0E0(font, '_');
    { unsigned short first = font->ranges[i].first; return &font->glyphs[ch - first + base]; }
}
