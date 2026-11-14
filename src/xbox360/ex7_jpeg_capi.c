/* Derived from the IJG JPEG library 6b (IJG license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX7: libjpeg jcapimin.c / jcapistd.c / jcparam.c compression API routines. */

#include "ex7_jpeg.h"

#ifdef _MSC_VER
extern void *memcpy(void *, const void *, unsigned int);
#else
#include <string.h>
#endif

void fn_882EFD50(ex7_jpeg_compress_struct *cinfo); /* jinit_compress_master */
void ex7_jpeg_suppress_tables_882E57F0(ex7_jpeg_compress_struct *cinfo, int suppress);

/* Mark the quantization and Huffman tables as sent or suppressed (jpeg_suppress_tables). Swing_DLL.xex 0x882E57F0 */
void ex7_jpeg_suppress_tables_882E57F0(ex7_jpeg_compress_struct *cinfo, int suppress)
{
    int i;
    ex7_jpeg_quant_tbl *qtbl;
    ex7_jpeg_huff_tbl *htbl;

    for (i = 0; i < 4; i++) {
        if ((qtbl = cinfo->quant_tbl_ptrs[i]) != 0)
            qtbl->sent_table = suppress;
    }
    for (i = 0; i < 4; i++) {
        if ((htbl = cinfo->dc_huff_tbl_ptrs[i]) != 0)
            htbl->sent_table = suppress;
        if ((htbl = cinfo->ac_huff_tbl_ptrs[i]) != 0)
            htbl->sent_table = suppress;
    }
}

/* Start a compression cycle: reset errors, init the destination and master, prepare pass 0 (jpeg_start_compress). Swing_DLL.xex 0x882E5A10 */
void ex7_jpeg_start_compress_882E5A10(ex7_jpeg_compress_struct *cinfo, int write_all_tables)
{
    if (cinfo->global_state != 100) {
        cinfo->err->msg_code = 20; /* JERR_BAD_STATE */
        cinfo->err->msg_parm.i[0] = cinfo->global_state;
        (*cinfo->err->error_exit)(cinfo);
    }
    if (write_all_tables)
        ex7_jpeg_suppress_tables_882E57F0(cinfo, 0);
    (*cinfo->err->reset_error_mgr)(cinfo);
    (*cinfo->dest->init_destination)(cinfo);
    fn_882EFD50(cinfo);
    (*cinfo->master->prepare_for_pass)(cinfo);
    cinfo->next_scanline = 0;
    cinfo->global_state = cinfo->raw_data_in ? 102 : 101;
}

ex7_jpeg_huff_tbl *ts4_get_u32_off4_882EDE88(void *cinfo); /* jpeg_alloc_huff_table */

/* Write scanlines through the main controller, clamped to the remaining rows (jpeg_write_scanlines). Swing_DLL.xex 0x882E5AF0 */
unsigned int ex7_jpeg_write_scanlines_882E5AF0(ex7_jpeg_compress_struct *cinfo, void *scanlines, unsigned int num_lines)
{
    unsigned int row_ctr, rows_left;

    if (cinfo->global_state != 101) {
        cinfo->err->msg_code = 20; /* JERR_BAD_STATE */
        cinfo->err->msg_parm.i[0] = cinfo->global_state;
        (*cinfo->err->error_exit)(cinfo);
    }
    if (cinfo->next_scanline >= cinfo->image_height) {
        cinfo->err->msg_code = 123; /* JWRN_TOO_MUCH_DATA */
        (*cinfo->err->emit_message)(cinfo, -1);
    }
    if (cinfo->progress != 0) {
        cinfo->progress->pass_counter = (int)cinfo->next_scanline;
        cinfo->progress->pass_limit = (int)cinfo->image_height;
        (*cinfo->progress->progress_monitor)(cinfo);
    }
    if (cinfo->master->call_pass_startup)
        (*cinfo->master->pass_startup)(cinfo);
    rows_left = cinfo->image_height - cinfo->next_scanline;
    if (num_lines > rows_left)
        num_lines = rows_left;
    row_ctr = 0;
    (*cinfo->main_ctl->process_data)(cinfo, scanlines, &row_ctr, num_lines);
    cinfo->next_scanline += row_ctr;
    return row_ctr;
}

/* Copy a Huffman table definition into the compress struct (jcparam.c add_huff_table). Swing_DLL.xex 0x882E5E20 */
void ex7_jpeg_add_huff_table_882E5E20(ex7_jpeg_compress_struct *cinfo, ex7_jpeg_huff_tbl **htblptr,
                                      const unsigned char *bits, const unsigned char *val)
{
    int nsymbols, len;

    if (*htblptr == 0)
        *htblptr = ts4_get_u32_off4_882EDE88(cinfo);
    memcpy((*htblptr)->bits, bits, sizeof((*htblptr)->bits));
    nsymbols = 0;
    for (len = 1; len <= 16; len++)
        nsymbols += bits[len];
    if (nsymbols < 1 || nsymbols > 256) {
        cinfo->err->msg_code = 8; /* JERR_BAD_HUFF_TABLE */
        (*cinfo->err->error_exit)(cinfo);
    }
    memcpy((*htblptr)->huffval, val, nsymbols * sizeof(unsigned char));
    (*htblptr)->sent_table = 0;
}

ex7_jpeg_quant_tbl *ts4_get_u32_off4_882EDE48(void *cinfo); /* jpeg_alloc_quant_table */

/* Install a quantization table scaled by a percentage (jcparam.c add_quant_table). Swing_DLL.xex 0x882E5C20 */
void ex7_jpeg_add_quant_table_882E5C20(ex7_jpeg_compress_struct *cinfo, int which_tbl, const unsigned int *basic_table,
                                       int scale_factor, int force_baseline)
{
    ex7_jpeg_quant_tbl **qtblptr = &cinfo->quant_tbl_ptrs[which_tbl];
    int i;
    int temp;

    if (cinfo->global_state != 100) {
        cinfo->err->msg_code = 20; /* JERR_BAD_STATE */
        cinfo->err->msg_parm.i[0] = cinfo->global_state;
        (*cinfo->err->error_exit)(cinfo);
    }
    if (which_tbl < 0 || which_tbl >= 4) {
        cinfo->err->msg_code = 31; /* JERR_DQT_INDEX */
        cinfo->err->msg_parm.i[0] = which_tbl;
        (*cinfo->err->error_exit)(cinfo);
    }
    qtblptr = &cinfo->quant_tbl_ptrs[which_tbl];
    if (*qtblptr == 0)
        *qtblptr = ts4_get_u32_off4_882EDE48(cinfo);
    for (i = 0; i < 64; i++) {
        temp = ((int)basic_table[i] * scale_factor + 50) / 100;
        if (temp <= 0)
            temp = 1;
        if (temp > 32767)
            temp = 32767;
        if (force_baseline && temp > 255)
            temp = 255;
        (*qtblptr)->quantval[i] = (unsigned short)temp;
    }
    (*qtblptr)->sent_table = 0;
}

void ts4_if_get_u32_off4_882EDD90(void *cinfo); /* jpeg_abort */

/* Finish the compression run, write the file trailer and abort (jpeg_finish_compress). Swing_DLL.xex 0x882E5868 */
void ex7_jpeg_finish_compress_882E5868(ex7_jpeg_compress_struct *cinfo)
{
    unsigned int iMCU_row;

    if (cinfo->global_state == 101 || cinfo->global_state == 102) {
        if (cinfo->next_scanline < cinfo->image_height) {
            cinfo->err->msg_code = 67; /* JERR_TOO_LITTLE_DATA */
            (*cinfo->err->error_exit)(cinfo);
        }
        (*cinfo->master->finish_pass)(cinfo);
    } else if (cinfo->global_state != 103) {
        cinfo->err->msg_code = 20; /* JERR_BAD_STATE */
        cinfo->err->msg_parm.i[0] = cinfo->global_state;
        (*cinfo->err->error_exit)(cinfo);
    }
    while (!cinfo->master->is_last_pass) {
        (*cinfo->master->prepare_for_pass)(cinfo);
        for (iMCU_row = 0; iMCU_row < cinfo->total_iMCU_rows; iMCU_row++) {
            if (cinfo->progress != 0) {
                cinfo->progress->pass_counter = (int)iMCU_row;
                cinfo->progress->pass_limit = (int)cinfo->total_iMCU_rows;
                (*cinfo->progress->progress_monitor)(cinfo);
            }
            if (!(*cinfo->coef->compress_data)(cinfo, 0)) {
                cinfo->err->msg_code = 24; /* JERR_CANT_SUSPEND */
                (*cinfo->err->error_exit)(cinfo);
            }
        }
        (*cinfo->master->finish_pass)(cinfo);
    }
    (*cinfo->marker->write_file_trailer)(cinfo);
    (*cinfo->dest->term_destination)(cinfo);
    ts4_if_get_u32_off4_882EDD90(cinfo);
}
