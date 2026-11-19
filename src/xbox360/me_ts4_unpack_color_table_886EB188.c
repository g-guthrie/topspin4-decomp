/* Swing_DLL.xex 0x886EB188: unpack 16 packed D3DCOLOR words (at +0x4C) into float4 colors: out[i] = c * scale + bias. */
#include "vx1_vector.h"
extern const __vector4 lbl_880F3200;   /* bias */
extern const __vector4 lbl_880F3210;   /* scale */
typedef struct Ts4ColorTable { char pad[0x4c]; unsigned int packed[16]; } Ts4ColorTable;
__vector4 __vsldoi(__vector4 a, __vector4 b, int imm);
#pragma intrinsic(__vsldoi)
void ts4_unpack_color_table_886EB188(Ts4ColorTable *t, __vector4 *out)
{
    int i;
    for (i = 0; i < 16; i++) {
        __vector4 v = __lvlx(&t->packed[i], 0);
        out[i] = __vmaddfp(lbl_880F3210, __vupkd3d(__vsldoi(v, v, 4), 0), lbl_880F3200);
    }
}
