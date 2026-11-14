/* Loader_DLL.xex 0x83447830-0x834478F8, executable version 0.0.0.3.
 * libpng 1.0.x/1.2.x pngrutil.c: png_set_crc_action. */
typedef unsigned long png_uint_32;
typedef struct {
    char pad[0x55c];
    png_uint_32 flags;
} png_struct;

extern const char lbl_83075B60[];
extern void ts4_if_get_u32_off544_8343FDB8(png_struct *png_ptr, const char *msg);

#define PNG_FLAG_CRC_ANCILLARY_USE 0x0100
#define PNG_FLAG_CRC_ANCILLARY_NOWARN 0x0200
#define PNG_FLAG_CRC_CRITICAL_USE 0x0400
#define PNG_FLAG_CRC_CRITICAL_IGNORE 0x0800
#define PNG_FLAG_CRC_ANCILLARY_MASK (PNG_FLAG_CRC_ANCILLARY_USE | PNG_FLAG_CRC_ANCILLARY_NOWARN)
#define PNG_FLAG_CRC_CRITICAL_MASK (PNG_FLAG_CRC_CRITICAL_USE | PNG_FLAG_CRC_CRITICAL_IGNORE)

#define PNG_CRC_ERROR_QUIT 1
#define PNG_CRC_WARN_DISCARD 2
#define PNG_CRC_WARN_USE 3
#define PNG_CRC_QUIET_USE 4
#define PNG_CRC_NO_CHANGE 5

void ts4l_png_set_crc_action_83447830(png_struct *png_ptr, int crit_action, int ancil_action)
{
    switch (crit_action) {
        case PNG_CRC_NO_CHANGE:
            break;
        case PNG_CRC_WARN_USE:
            png_ptr->flags &= ~PNG_FLAG_CRC_CRITICAL_MASK;
            png_ptr->flags |= PNG_FLAG_CRC_CRITICAL_USE;
            break;
        case PNG_CRC_QUIET_USE:
            png_ptr->flags &= ~PNG_FLAG_CRC_CRITICAL_MASK;
            png_ptr->flags |= PNG_FLAG_CRC_CRITICAL_USE | PNG_FLAG_CRC_CRITICAL_IGNORE;
            break;
        case PNG_CRC_WARN_DISCARD:
            ts4_if_get_u32_off544_8343FDB8(png_ptr, lbl_83075B60);
        case PNG_CRC_ERROR_QUIT:
        default:
            png_ptr->flags &= ~PNG_FLAG_CRC_CRITICAL_MASK;
            break;
    }
    switch (ancil_action) {
        case PNG_CRC_NO_CHANGE:
            break;
        case PNG_CRC_WARN_USE:
            png_ptr->flags &= ~PNG_FLAG_CRC_ANCILLARY_MASK;
            png_ptr->flags |= PNG_FLAG_CRC_ANCILLARY_USE;
            break;
        case PNG_CRC_QUIET_USE:
            png_ptr->flags &= ~PNG_FLAG_CRC_ANCILLARY_MASK;
            png_ptr->flags |= PNG_FLAG_CRC_ANCILLARY_USE | PNG_FLAG_CRC_ANCILLARY_NOWARN;
            break;
        case PNG_CRC_ERROR_QUIT:
            png_ptr->flags &= ~PNG_FLAG_CRC_ANCILLARY_MASK;
            png_ptr->flags |= PNG_FLAG_CRC_ANCILLARY_NOWARN;
            break;
        case PNG_CRC_WARN_DISCARD:
        default:
            png_ptr->flags &= ~PNG_FLAG_CRC_ANCILLARY_MASK;
            break;
    }
}
