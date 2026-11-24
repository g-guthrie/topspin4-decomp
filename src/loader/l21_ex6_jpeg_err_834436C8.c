/* Loader_DLL.xex 0x834436C8-0x83443738, executable version 0.0.0.3.
 * Statically linked libjpeg 6b routines. */


typedef struct ex6_jpeg_error_mgr {
    void (*error_exit)(void *cinfo);                   /* +0x00 */
    void (*emit_message)(void *cinfo, int msg_level);  /* +0x04 */
    void (*output_message)(void *cinfo);               /* +0x08 */
    void (*format_message)(void *cinfo, char *buffer); /* +0x0C */
    void (*reset_error_mgr)(void *cinfo);              /* +0x10 */
    int msg_code;                                      /* +0x14 */
    union {
        int i[8];
        char s[80];
    } msg_parm;                                        /* +0x18 */
    int trace_level;                                   /* +0x68 */
    long num_warnings;                                 /* +0x6C */
    const char *const *jpeg_message_table;             /* +0x70 */
    int last_jpeg_message;                             /* +0x74 */
    const char *const *addon_message_table;            /* +0x78 */
    int first_addon_message;                           /* +0x7C */
    int last_addon_message;                            /* +0x80 */
} ex6_jpeg_error_mgr;

/* jerror.c callbacks (placeholders in the symbol map) */
void ts4l_get_u32_off0_83443480(void *cinfo);
void ts4l_if_get_u32_off0_83443500(void *cinfo, int msg_level);
void ts4_get_u32_off0_834434D0(void *cinfo);
struct ex6_jpeg_common_struct;
void fn_83443590(struct ex6_jpeg_common_struct *cinfo, char *buffer);
void ts4_get_u32_off0_834436B0(void *cinfo);
extern const char *const lbl_83074FD0[]; /* jpeg_std_message_table */

#define EX6_JMSG_LASTMSGCODE 124

/* Fill a jpeg_error_mgr with the standard handlers and message table (jpeg_std_error). */
ex6_jpeg_error_mgr *ts4l_jpeg_std_error_834436C8(ex6_jpeg_error_mgr *err)
{
    err->error_exit = ts4l_get_u32_off0_83443480;
    err->emit_message = ts4l_if_get_u32_off0_83443500;
    err->output_message = ts4_get_u32_off0_834434D0;
    err->format_message = (void (*)(void *, char *))fn_83443590;
    err->reset_error_mgr = ts4_get_u32_off0_834436B0;
    err->trace_level = 0;
    err->num_warnings = 0;
    err->msg_code = 0;
    err->jpeg_message_table = lbl_83074FD0;
    err->last_jpeg_message = EX6_JMSG_LASTMSGCODE - 1;
    err->addon_message_table = 0;
    err->first_addon_message = 0;
    err->last_addon_message = 0;
    return err;
}

typedef struct ex6_jpeg_common_struct {
    ex6_jpeg_error_mgr *err; /* +0x00 */
} ex6_jpeg_common_struct;



