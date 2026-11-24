/* (C) 2007-2009 Jean-Marc Valin, CSIRO
   (C) 2008 Gregory Maxwell */
/*
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:

   - Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

   - Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

   - Neither the name of the Xiph.org Foundation nor the names of its
   contributors may be used to endorse or promote products derived from
   this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR
   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
/* Derived from CELT 0.6.1 libcelt/modes.c (BSD license); see
   THIRD_PARTY_NOTICES.md. */
#include "aud1_celt.h"

#define MODEVALID 0xa110ca7e
#define MODEPARTIAL 0x7eca10a1
#define MODEFREED 0xb10cf8ee

void ts4_get_u32_off0_883B3368(struct PsyDecay *decay);         /* psydecay_clear */
void ts4_call_seq_lbl_8802EE60_883B2400(mdct_lookup *l);         /* mdct_clear */
void ts4_addr_lbl_8802EE60_883B1EC8(void *p);                    /* pitch_state_free / quant_prob_free */

extern const char lbl_8802EF04[]; /* "NULL passed to celt_mode_destroy" */
extern const char lbl_8802EEB0[]; /* "Freeing a mode which has already been freed" */
extern const char lbl_8802EEDC[]; /* "This is not a valid CELT mode structure" */
extern const char lbl_8802EF28[]; /* "Using a mode that has already been freed" */
extern const char lbl_8802EF54[]; /* "This is not a valid CELT mode" */

/* celt_mode_destroy: release a mode built by celt_mode_create. */
void aud1_celt_mode_destroy_8839A4E0(CELTMode *mode)
{
    int i;
    const celt_int16_t *prevPtr = NULL;
    if (mode == NULL) {
        celt_warning(lbl_8802EF04);
        return;
    }

    if (mode->marker_start == MODEFREED || mode->marker_end == MODEFREED) {
        celt_warning(lbl_8802EEB0);
        return;
    }

    if (mode->marker_start != MODEVALID && mode->marker_start != MODEPARTIAL) {
        celt_warning(lbl_8802EEDC);
        return;
    }
    mode->marker_start = MODEFREED;
    if (mode->bits != NULL) {
        for (i = 0; i < mode->nbEBands; i++) {
            if (mode->bits[i] != prevPtr) {
                prevPtr = mode->bits[i];
                celt_free((int *)mode->bits[i]);
            }
        }
    }
    celt_free((int **)mode->bits);
    celt_free((int *)mode->eBands);
    celt_free((int *)mode->pBands);
    celt_free((int *)mode->allocVectors);

    celt_free((celt_word16_t *)mode->window);

    ts4_get_u32_off0_883B3368(&mode->psy);
    ts4_call_seq_lbl_8802EE60_883B2400(&mode->mdct);
    ts4_call_seq_lbl_8802EE60_883B2400(&mode->shortMdct);
    ts4_addr_lbl_8802EE60_883B1EC8(mode->fft);
    ts4_addr_lbl_8802EE60_883B1EC8(mode->prob);
    mode->marker_end = MODEFREED;
    celt_free((CELTMode *)mode);
}

/* check_mode: CELT_OK for a live mode, CELT_INVALID_MODE otherwise. */
int aud1_check_mode_8839A678(const CELTMode *mode)
{
    if (mode == NULL) return CELT_INVALID_MODE;
    if (mode->marker_start == MODEVALID && mode->marker_end == MODEVALID) return CELT_OK;
    if (mode->marker_start == MODEFREED || mode->marker_end == MODEFREED)
        celt_warning(lbl_8802EF28);
    else
        celt_warning(lbl_8802EF54);
    return CELT_INVALID_MODE;
}

#define MIN_BINS 3
#define BARK_BANDS 25
extern const celt_int16_t lbl_8802E968[BARK_BANDS + 1]; /* bark_freq */
#define bark_freq lbl_8802E968

/* compute_ebands: band edges (in MDCT bins) for this rate and frame size. */
celt_int16_t *aud1_compute_ebands_88399B40(celt_int32_t Fs, int frame_size, int *nbEBands)
{
    celt_int16_t *eBands;
    int i, res, min_width, lin, low, high, nBark;
    res = (Fs + frame_size) / (2 * frame_size);
    min_width = MIN_BINS * res;

    /* Find the number of critical bands supported by our sampling rate */
    for (nBark = 1; nBark < BARK_BANDS; nBark++)
        if (bark_freq[nBark + 1] * 2 >= Fs) break;

    /* Find where the linear part ends (i.e. where the spacing is more than min_width */
    for (lin = 0; lin < nBark; lin++)
        if (bark_freq[lin + 1] - bark_freq[lin] >= min_width) break;

    low = ((bark_freq[lin] / res) + (MIN_BINS - 1)) / MIN_BINS;
    high = nBark - lin;
    *nbEBands = low + high;
    eBands = celt_alloc(sizeof(celt_int16_t) * (*nbEBands + 2));

    if (eBands == NULL) return NULL;

    /* Linear spacing (min_width) */
    for (i = 0; i < low; i++)
        eBands[i] = MIN_BINS * i;
    /* Spacing follows critical bands */
    for (i = 0; i < high; i++)
        eBands[i + low] = (bark_freq[lin + i] + res / 2) / res;
    /* Enforce the minimum spacing at the boundary */
    for (i = 0; i < *nbEBands; i++)
        if (eBands[i] < MIN_BINS * i) eBands[i] = MIN_BINS * i;
    eBands[*nbEBands] = (bark_freq[nBark] + res / 2) / res;
    eBands[*nbEBands + 1] = frame_size;
    if (eBands[*nbEBands] > eBands[*nbEBands + 1]) eBands[*nbEBands] = eBands[*nbEBands + 1];

    /* FIXME: Remove last band if too small */
    return eBands;
}
