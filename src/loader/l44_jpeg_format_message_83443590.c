/* Loader_DLL.xex 0x83443590-0x834436AC, executable version 0.0.0.3. */
/* Library routine: libjpeg jerror.c format_message. */
#include "l44_jpeg.h"

extern int fn_833E1C78(char *buffer, const char *format, ...);

void ts4l_jpeg_format_message_83443590(struct ts4l_jpeg_decomp *cinfo, char *buffer)
{
    struct ts4l_jerr_full *err = (struct ts4l_jerr_full *)cinfo->err;
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
        err->msg_parm[0] = msg_code;
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
        fn_833E1C78(buffer, msgtext, &err->msg_parm[0]);
    else
        fn_833E1C78(buffer, msgtext, err->msg_parm[0], err->msg_parm[1], err->msg_parm[2],
                    err->msg_parm[3], err->msg_parm[4], err->msg_parm[5], err->msg_parm[6],
                    err->msg_parm[7]);
}
