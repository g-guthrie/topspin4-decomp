/* Derived from the IJG JPEG library 6b (IJG license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* JPEG progressive Huffman encoder (IJG libjpeg jcphuff.c style), Swing_DLL.xex
 * auto_03_882FD0D8. (RM3) */
#include "rm3_jpeg.h"

/* Derived encoding table (IJG c_derived_tbl). */
struct ts4_jpeg_c_derived_tbl {
    unsigned int ehufco[256]; /* 0x000 */
    char ehufsi[256];         /* 0x400 */
};

/* Progressive Huffman encoder private state (IJG phuff_entropy_encoder). */
struct ts4_jpeg_phuff_entropy {
    void *pub[3];                         /* 0x00: start_pass, encode_mcu, finish_pass */
    int gather_statistics;                /* 0x0c */
    ts4_joctet *next_output_byte;         /* 0x10 */
    unsigned int free_in_buffer;          /* 0x14 */
    int put_buffer;                       /* 0x18 */
    int put_bits;                         /* 0x1c */
    struct ts4_jpeg_comp *cinfo;          /* 0x20 */
    int last_dc_val[4];                   /* 0x24 */
    int ac_tbl_no;                        /* 0x34 */
    unsigned int EOBRUN;                  /* 0x38 */
    unsigned int BE;                      /* 0x3c */
    char *bit_buffer;                     /* 0x40 */
    unsigned int restarts_to_go;          /* 0x44 */
    int next_restart_num;                 /* 0x48 */
    struct ts4_jpeg_c_derived_tbl *derived_tbls[4]; /* 0x4c */
    long *count_ptrs[4];                  /* 0x5c */
};

void ex8_emit_bits_882FD0D8(struct ts4_jpeg_phuff_entropy *entropy, unsigned int code, int size); /* emit_bits */
void ex8_emit_buffered_bits_882FD238(struct ts4_jpeg_phuff_entropy *entropy, char *bufstart, unsigned int nbits); /* emit_buffered_bits */
void ex8_emit_eobrun_882FD3C8(struct ts4_jpeg_phuff_entropy *entropy); /* emit_eobrun */
void ex8_emit_restart_882FD4C0(struct ts4_jpeg_phuff_entropy *entropy, int restart_num); /* emit_restart */

/* Counts or emits one Huffman symbol (IJG emit_symbol, inlined). */
static void emit_symbol(struct ts4_jpeg_phuff_entropy *entropy, int tbl_no, int symbol)
{
    if (entropy->gather_statistics)
        entropy->count_ptrs[tbl_no][symbol]++;
    else {
        struct ts4_jpeg_c_derived_tbl *tbl = entropy->derived_tbls[tbl_no];
        ex8_emit_bits_882FD0D8(entropy, tbl->ehufco[symbol], tbl->ehufsi[symbol]);
    }
}

/* Encodes one block's AC refinement scan: correction bits for already-nonzero
 * coefficients plus run/size symbols for newly nonzero ones (Swing_DLL.xex 0x882FDB30). */
int ts4_jpeg_encode_mcu_AC_refine_882FDB30(struct ts4_jpeg_comp *cinfo, short (**MCU_data)[64])
{
    struct ts4_jpeg_phuff_entropy *entropy = (struct ts4_jpeg_phuff_entropy *)cinfo->entropy;
    int temp;
    int r, k;
    int EOB;
    char *BR_buffer;
    unsigned int BR;
    int Se = cinfo->Se;
    int Al = cinfo->Al;
    short (*block)[64];
    int absvalues[64];

    entropy->next_output_byte = cinfo->dest->next_output_byte;
    entropy->free_in_buffer = cinfo->dest->free_in_buffer;

    if (cinfo->restart_interval)
        if (entropy->restarts_to_go == 0)
            ex8_emit_restart_882FD4C0(entropy, entropy->next_restart_num);

    block = MCU_data[0];

    EOB = 0;
    for (k = cinfo->Ss; k <= Se; k++) {
        temp = (*block)[lbl_88025F10[k]];
        if (temp < 0)
            temp = -temp;
        temp >>= Al;
        absvalues[k] = temp;
        if (temp == 1)
            EOB = k;
    }

    r = 0;
    BR = 0;
    BR_buffer = entropy->bit_buffer + entropy->BE;

    for (k = cinfo->Ss; k <= Se; k++) {
        if ((temp = absvalues[k]) == 0) {
            r++;
            continue;
        }

        while (r > 15 && k <= EOB) {
            ex8_emit_eobrun_882FD3C8(entropy);
            emit_symbol(entropy, entropy->ac_tbl_no, 0xF0);
            r -= 16;
            ex8_emit_buffered_bits_882FD238(entropy, BR_buffer, BR);
            BR_buffer = entropy->bit_buffer;
            BR = 0;
        }

        if (temp > 1) {
            BR_buffer[BR++] = (char)(temp & 1);
            continue;
        }

        ex8_emit_eobrun_882FD3C8(entropy);

        emit_symbol(entropy, entropy->ac_tbl_no, (r << 4) + 1);

        temp = ((*block)[lbl_88025F10[k]] < 0) ? 0 : 1;
        ex8_emit_bits_882FD0D8(entropy, (unsigned int)temp, 1);

        ex8_emit_buffered_bits_882FD238(entropy, BR_buffer, BR);
        BR_buffer = entropy->bit_buffer;
        BR = 0;
        r = 0;
    }

    if (r > 0 || BR > 0) {
        entropy->EOBRUN++;
        entropy->BE += BR;
        if (entropy->EOBRUN == 0x7FFF || entropy->BE > (1000 - 64 + 1))
            ex8_emit_eobrun_882FD3C8(entropy);
    }

    cinfo->dest->next_output_byte = entropy->next_output_byte;
    cinfo->dest->free_in_buffer = entropy->free_in_buffer;

    if (cinfo->restart_interval) {
        if (entropy->restarts_to_go == 0) {
            entropy->restarts_to_go = cinfo->restart_interval;
            entropy->next_restart_num++;
            entropy->next_restart_num &= 7;
        }
        entropy->restarts_to_go--;
    }

    return 1;
}
