/* Derived from the IJG JPEG library 6b (IJG license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
#include "jp2_jpeg.h"

static const double lbl_880038D0 = 1.0; /* input_gamma default */

void ts4_jpeg_jinit_memory_mgr_882EDC68(struct ts4_jpeg_decomp *cinfo);
void ex7_jpeg_jinit_marker_reader_882E5348(struct ts4_jpeg_decomp *cinfo); /* jinit_marker_reader */
void ts4_get_u32_off4_882ECAE0(struct ts4_jpeg_decomp *cinfo);            /* jinit_input_controller */

enum { JP2_DECOMPRESS_STRUCT_SIZE = 0x1d8 };

/* Initializes a compression object: checks versions, zeroes it and creates the memory manager
 * (jcapimin.c jpeg_CreateCompress). */
void ts4_jpeg_CreateCompress_882E56D8(struct jp2_jpeg_compress *cinfo, int version, unsigned int structsize)
{
    int i;

    cinfo->mem = 0;
    if (version != JP2_JPEG_LIB_VERSION) {
        cinfo->err->msg_code = JP2_JERR_BAD_LIB_VERSION;
        cinfo->err->msg_parm[0] = JP2_JPEG_LIB_VERSION;
        cinfo->err->msg_parm[1] = version;
        (*cinfo->err->error_exit)((struct ts4_jpeg_decomp *)cinfo);
    }
    if (structsize != sizeof(struct jp2_jpeg_compress)) {
        cinfo->err->msg_code = JP2_JERR_BAD_STRUCT_SIZE;
        cinfo->err->msg_parm[0] = (int)sizeof(struct jp2_jpeg_compress);
        cinfo->err->msg_parm[1] = (int)structsize;
        (*cinfo->err->error_exit)((struct ts4_jpeg_decomp *)cinfo);
    }

    {
        struct ts4_jpeg_error_mgr *err = cinfo->err;
        void *client_data = cinfo->client_data;
        memset(cinfo, 0, sizeof(struct jp2_jpeg_compress));
        cinfo->err = err;
        cinfo->client_data = client_data;
    }
    cinfo->is_decompressor = 0;

    ts4_jpeg_jinit_memory_mgr_882EDC68((struct ts4_jpeg_decomp *)cinfo);

    cinfo->progress = 0;
    cinfo->dest = 0;

    cinfo->comp_info = 0;

    for (i = 0; i < 4; i++)
        cinfo->quant_tbl_ptrs[i] = 0;

    for (i = 0; i < 4; i++) {
        cinfo->dc_huff_tbl_ptrs[i] = 0;
        cinfo->ac_huff_tbl_ptrs[i] = 0;
    }

    cinfo->script_space = 0;

    cinfo->input_gamma = lbl_880038D0;

    cinfo->global_state = JP2_CSTATE_START;
}

/* Initializes a decompression object: checks versions, zeroes it, creates the memory manager and the
 * marker reader and input controller (jdapimin.c jpeg_CreateDecompress). */
void ts4_jpeg_CreateDecompress_882E29C8(struct ts4_jpeg_decomp *cinfo, int version, unsigned int structsize)
{
    int i;

    cinfo->mem = 0;
    if (version != JP2_JPEG_LIB_VERSION) {
        cinfo->err->msg_code = JP2_JERR_BAD_LIB_VERSION;
        cinfo->err->msg_parm[0] = JP2_JPEG_LIB_VERSION;
        cinfo->err->msg_parm[1] = version;
        (*cinfo->err->error_exit)(cinfo);
    }
    if (structsize != JP2_DECOMPRESS_STRUCT_SIZE) {
        cinfo->err->msg_code = JP2_JERR_BAD_STRUCT_SIZE;
        cinfo->err->msg_parm[0] = JP2_DECOMPRESS_STRUCT_SIZE;
        cinfo->err->msg_parm[1] = (int)structsize;
        (*cinfo->err->error_exit)(cinfo);
    }

    {
        struct ts4_jpeg_error_mgr *err = cinfo->err;
        void *client_data = cinfo->client_data;
        memset(cinfo, 0, JP2_DECOMPRESS_STRUCT_SIZE);
        cinfo->err = err;
        cinfo->client_data = client_data;
    }
    cinfo->is_decompressor = 1;

    ts4_jpeg_jinit_memory_mgr_882EDC68(cinfo);

    cinfo->progress = 0;
    cinfo->src = 0;

    for (i = 0; i < 4; i++)
        cinfo->quant_tbl_ptrs[i] = 0;

    for (i = 0; i < 4; i++) {
        cinfo->dc_huff_tbl_ptrs[i] = 0;
        cinfo->ac_huff_tbl_ptrs[i] = 0;
    }

    cinfo->marker_list = 0;
    ex7_jpeg_jinit_marker_reader_882E5348(cinfo);
    ts4_get_u32_off4_882ECAE0(cinfo);

    cinfo->global_state = JP2_DSTATE_START;
}

#define JP1_WARNMS1(c, code, p1)                                                         \
    ((c)->err->msg_code = (code), (c)->err->msg_parm[0] = (p1), (*(c)->err->emit_message)((c), -1))

enum { JP2_JWRN_ADOBE_XFORM = 114, JP2_JTRC_UNKNOWN_IDS = 111 };
enum { JP2_JCS_UNKNOWN = 0, JP2_JCS_GRAYSCALE = 1, JP2_JCS_RGB = 2, JP2_JCS_YCbCr = 3, JP2_JCS_CMYK = 4,
       JP2_JCS_YCCK = 5 };

/* Guesses the JPEG and output colorspaces from the markers seen and sets the default decompression
 * parameters (jdapimin.c default_decompress_parms). */
void ts4_jpeg_default_decompress_parms_882E2AE8(struct ts4_jpeg_decomp *cinfo)
{
    switch (cinfo->num_components) {
    case 1:
        cinfo->jpeg_color_space = JP2_JCS_GRAYSCALE;
        cinfo->out_color_space = JP2_JCS_GRAYSCALE;
        break;

    case 3:
        if (cinfo->saw_JFIF_marker) {
            cinfo->jpeg_color_space = JP2_JCS_YCbCr;
        } else if (cinfo->saw_Adobe_marker) {
            switch (cinfo->Adobe_transform) {
            case 0:
                cinfo->jpeg_color_space = JP2_JCS_RGB;
                break;
            case 1:
                cinfo->jpeg_color_space = JP2_JCS_YCbCr;
                break;
            default:
                JP1_WARNMS1(cinfo, JP2_JWRN_ADOBE_XFORM, cinfo->Adobe_transform);
                cinfo->jpeg_color_space = JP2_JCS_YCbCr;
                break;
            }
        } else {
            int cid0 = cinfo->comp_info[0].component_id;
            int cid1 = cinfo->comp_info[1].component_id;
            int cid2 = cinfo->comp_info[2].component_id;

            if (cid0 == 1 && cid1 == 2 && cid2 == 3)
                cinfo->jpeg_color_space = JP2_JCS_YCbCr;
            else if (cid0 == 82 && cid1 == 71 && cid2 == 66)
                cinfo->jpeg_color_space = JP2_JCS_RGB;
            else {
                JP1_TRACEMS3(cinfo, 1, JP2_JTRC_UNKNOWN_IDS, cid0, cid1, cid2);
                cinfo->jpeg_color_space = JP2_JCS_YCbCr;
            }
        }
        cinfo->out_color_space = JP2_JCS_RGB;
        break;

    case 4:
        if (cinfo->saw_Adobe_marker) {
            switch (cinfo->Adobe_transform) {
            case 0:
                cinfo->jpeg_color_space = JP2_JCS_CMYK;
                break;
            case 2:
                cinfo->jpeg_color_space = JP2_JCS_YCCK;
                break;
            default:
                JP1_WARNMS1(cinfo, JP2_JWRN_ADOBE_XFORM, cinfo->Adobe_transform);
                cinfo->jpeg_color_space = JP2_JCS_YCCK;
                break;
            }
        } else {
            cinfo->jpeg_color_space = JP2_JCS_CMYK;
        }
        cinfo->out_color_space = JP2_JCS_CMYK;
        break;

    default:
        cinfo->jpeg_color_space = JP2_JCS_UNKNOWN;
        cinfo->out_color_space = JP2_JCS_UNKNOWN;
        break;
    }

    cinfo->scale_num = 1;
    cinfo->scale_denom = 1;
    cinfo->output_gamma = lbl_880038D0;
    cinfo->buffered_image = 0;
    cinfo->raw_data_out = 0;
    cinfo->dct_method = 0;
    cinfo->do_fancy_upsampling = 1;
    cinfo->do_block_smoothing = 1;
    cinfo->quantize_colors = 0;
    cinfo->dither_mode = 2;
    cinfo->two_pass_quantize = 0;
    cinfo->desired_number_of_colors = 256;
    cinfo->colormap = 0;
    cinfo->enable_1pass_quant = 0;
    cinfo->enable_external_quant = 0;
    cinfo->enable_2pass_quant = 0;
}

void ts4_if_get_u32_off4_882EDD90(struct ts4_jpeg_decomp *cinfo); /* jpeg_abort */

enum { JP2_JERR_TOO_LITTLE_DATA = 67 };

/* Ends decompression: finishes the last output pass, reads to the EOI marker and releases the image
 * pool (jdapimin.c jpeg_finish_decompress). */
int ts4_jpeg_finish_decompress_882E2E50(struct ts4_jpeg_decomp *cinfo)
{
    if ((cinfo->global_state == JP1_DSTATE_SCANNING || cinfo->global_state == JP1_DSTATE_RAW_OK) &&
        !cinfo->buffered_image) {
        if (cinfo->output_scanline < cinfo->output_height)
            JP1_ERREXIT(cinfo, JP2_JERR_TOO_LITTLE_DATA);
        (*cinfo->master->finish_output_pass)(cinfo);
        cinfo->global_state = JP1_DSTATE_STOPPING;
    } else if (cinfo->global_state == JP1_DSTATE_BUFIMAGE) {
        cinfo->global_state = JP1_DSTATE_STOPPING;
    } else if (cinfo->global_state != JP1_DSTATE_STOPPING) {
        JP1_ERREXIT1(cinfo, JP2_JERR_BAD_STATE, cinfo->global_state);
    }
    while (!cinfo->inputctl->eoi_reached) {
        if ((*cinfo->inputctl->consume_input)(cinfo) == 0)
            return 0;
    }
    (*cinfo->src->term_source)(cinfo);
    ts4_if_get_u32_off4_882EDD90(cinfo);
    return 1;
}
