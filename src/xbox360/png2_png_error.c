/* Derived from libpng 1.2.x (libpng license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family PNG2: libpng pngerror.c (compiled with /O1). The default handlers are reduced to a longjmp. */

#include "png2_png.h"

#ifdef _MSC_VER
extern void *memcpy(void *, const void *, unsigned int);
#else
#include <string.h>
#endif

#define PNG2_MAX_ERROR_TEXT 64

typedef void (*png2_error_ptr)(png2_png_struct *png_ptr, const char *message);

extern const char lbl_88007DE0[]; /* png_digit: "0123456789ABCDEF" */
#ifdef _MSC_VER
#define PNG2_NORETURN __declspec(noreturn)
#else
#define PNG2_NORETURN _Noreturn
#endif
PNG2_NORETURN void fn_88569D30(void *env, int value); /* longjmp */

#define png2_isnonalpha(c) ((c) < 41 || (c) > 122 || ((c) > 90 && (c) < 97))

/* Prefix a message with the current chunk name, printing non-letters as [hex] (libpng png_format_buffer).
 * Swing_DLL.xex 0x882E25D8 */
void png2_png_format_buffer_882E25D8(png2_png_struct *png_ptr, char *buffer, const char *error_message)
{
    int iout = 0, iin = 0;

    while (iin < 4) {
        int c = png_ptr->chunk_name[iin++];
        if (png2_isnonalpha(c)) {
            buffer[iout++] = '[';
            buffer[iout++] = lbl_88007DE0[(c & 0xf0) >> 4];
            buffer[iout++] = lbl_88007DE0[c & 0x0f];
            buffer[iout++] = ']';
        } else {
            buffer[iout++] = (char)c;
        }
    }
    if (error_message == 0) {
        buffer[iout] = 0;
    } else {
        buffer[iout++] = ':';
        buffer[iout++] = ' ';
        memcpy(buffer + iout, error_message, PNG2_MAX_ERROR_TEXT);
        buffer[iout + PNG2_MAX_ERROR_TEXT - 1] = 0;
    }
}

/* Call the user error handler, then longjmp back to the setjmp point (libpng png_error). Swing_DLL.xex 0x882E26E8 */
PNG2_NORETURN void png2_png_error_882E26E8(png2_png_struct *png_ptr, const char *error_message)
{
    if (png_ptr->error_fn != 0)
        (*(png2_error_ptr)png_ptr->error_fn)(png_ptr, error_message);
    fn_88569D30(png_ptr->jmpbuf, 1);
}

/* Raise an error whose text is prefixed with the chunk name (libpng png_chunk_error). Swing_DLL.xex 0x882E2738 */
void png2_png_chunk_error_882E2738(png2_png_struct *png_ptr, const char *error_message)
{
    char msg[16 + PNG2_MAX_ERROR_TEXT];

    png2_png_format_buffer_882E25D8(png_ptr, msg, error_message);
    png2_png_error_882E26E8(png_ptr, msg);
}
