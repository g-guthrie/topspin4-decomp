/* Swing_DLL.xex 0x88286558: uninitialized_copy of 20-byte records {formatted text; two words}.
 * /Oc. Element copy: ts4_assign_formatted_text then the two words. */
typedef struct Text { char *p; char *last; char *end; } Text;
typedef struct TextRec20 { Text text; unsigned int a; unsigned int b; } TextRec20;
void ts4_assign_formatted_text(void *dst, void *src);

TextRec20 *fn_88286558(const TextRec20 *first, const TextRec20 *last, TextRec20 *dest)
{
    for (; first != last; ++first, ++dest)
        if (dest) {
            ts4_assign_formatted_text(&dest->text, first->text.p);
            dest->a = first->a;
            dest->b = first->b;
        }
    return dest;
}
