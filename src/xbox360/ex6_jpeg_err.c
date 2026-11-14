/* Derived from the IJG JPEG library 6b (IJG license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX6: libjpeg jerror.c (jpeg_std_error, format_message). */

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
void ts4_get_u32_off0_882E5420(void *cinfo);
void ts4_if_get_u32_off0_882E54A0(void *cinfo, int msg_level);
void ts4_get_u32_off0_882E5470(void *cinfo);
struct ex6_jpeg_common_struct;
void ex6_jpeg_format_message_882E5530(struct ex6_jpeg_common_struct *cinfo, char *buffer);
void ts4_get_u32_off0_882E5650(void *cinfo);
extern const char *const lbl_88009088[]; /* jpeg_std_message_table */

#define EX6_JMSG_LASTMSGCODE 124

/* Fill a jpeg_error_mgr with the standard handlers and message table (jpeg_std_error). Swing_DLL.xex 0x882E5668 */
ex6_jpeg_error_mgr *ex6_jpeg_std_error_882E5668(ex6_jpeg_error_mgr *err)
{
    err->error_exit = ts4_get_u32_off0_882E5420;
    err->emit_message = ts4_if_get_u32_off0_882E54A0;
    err->output_message = ts4_get_u32_off0_882E5470;
    err->format_message = (void (*)(void *, char *))ex6_jpeg_format_message_882E5530;
    err->reset_error_mgr = ts4_get_u32_off0_882E5650;
    err->trace_level = 0;
    err->num_warnings = 0;
    err->msg_code = 0;
    err->jpeg_message_table = lbl_88009088;
    err->last_jpeg_message = EX6_JMSG_LASTMSGCODE - 1;
    err->addon_message_table = 0;
    err->first_addon_message = 0;
    err->last_addon_message = 0;
    return err;
}

typedef struct ex6_jpeg_common_struct {
    ex6_jpeg_error_mgr *err; /* +0x00 */
} ex6_jpeg_common_struct;


int fn_885635D0(char *buffer, const char *format, ...); /* sprintf */

/* Build the text of the current error/trace message into buffer, substituting the integer or string parameters
 * (jerror.c format_message). Swing_DLL.xex 0x882E5530 */
void ex6_jpeg_format_message_882E5530(ex6_jpeg_common_struct *cinfo, char *buffer)
{
    ex6_jpeg_error_mgr *err = cinfo->err;
    int msg_code = err->msg_code;
    const char *msgtext = 0;
    const char *msgptr;
    char ch;
    int isstring;

    if (msg_code > 0 && msg_code <= err->last_jpeg_message) {
        msgtext = err->jpeg_message_table[msg_code];
    } else if (err->addon_message_table != 0 && msg_code >= err->first_addon_message &&
               msg_code <= err->last_addon_message) {
        msgtext = err->addon_message_table[msg_code - err->first_addon_message];
    }
    if (msgtext == 0) {
        err->msg_parm.i[0] = msg_code;
        msgtext = err->jpeg_message_table[0];
    }
    isstring = 0;
    msgptr = msgtext;
    while ((ch = *msgptr++) != '\0') {
        if (ch == '%') {
            if (*msgptr == 's')
                isstring = 1;
            break;
        }
    }
    if (isstring)
        fn_885635D0(buffer, msgtext, err->msg_parm.s);
    else
        fn_885635D0(buffer, msgtext, err->msg_parm.i[0], err->msg_parm.i[1], err->msg_parm.i[2], err->msg_parm.i[3],
                    err->msg_parm.i[4], err->msg_parm.i[5], err->msg_parm.i[6], err->msg_parm.i[7]);
}
