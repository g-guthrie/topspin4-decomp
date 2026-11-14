/* Swing_DLL.xex 0x88AFDE30-0x88AFE628, executable version 0.0.0.3. */
#ifdef _MSC_VER
void *memset(void *, int, unsigned);
void *memcpy(void *, const void *, unsigned);
#else
#include <string.h>
#endif
typedef int s32;
extern char lbl_8808D820[];
extern char lbl_88C2D800[];
extern char lbl_88C326F8[];
extern char lbl_88C32B28[];
extern char lbl_88C32F58[];
extern char lbl_88C33388[];
extern char lbl_88C337B8[];
extern char lbl_88C33BE8[];
extern char lbl_88C34018[];

void ts4_reset_config_block_88AFDE30(void)
{
    memset(lbl_88C2D800 + 0x18, 0, 0x1f8);
    memcpy(lbl_88C2D800 + 0x210, lbl_8808D820, 0x48);
    memset(lbl_88C2D800 + 0x258, 0, 0x1b8);
    *(s32 *)(lbl_88C2D800 + 0x410) = 1;
    *(s32 *)(lbl_88C2D800 + 0x414) = 0;
    *(s32 *)(lbl_88C2D800 + 0x418) = 31;
    *(s32 *)(lbl_88C2D800 + 0x41c) = 1;
    *(s32 *)(lbl_88C2D800 + 0x420) = 1;
    *(s32 *)(lbl_88C2D800 + 0x424) = 1;
    *(s32 *)(lbl_88C2D800 + 0x428) = 1;
}

