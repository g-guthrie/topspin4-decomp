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
/* Derived from CELT 0.6.1 libcelt/modes.h, mdct.h, psy.h, os_support.h
   (BSD license); see THIRD_PARTY_NOTICES.md. Float build as linked into
   FMOD Ex (Swing_DLL.xex). Version pinned from the binary: the CELTMode
   layout (nbChannels/nbPBands/pBands present, marker_end at 0x6c), the
   celt_fatal line numbers (bands.c:201, kiss_fft.c:662) and intra_fold
   taking a per-channel pulses array (new in 0.6.1). FMOD routes
   celt_alloc/celt_free through its own allocator. */
#ifndef AUD1_CELT_H
#define AUD1_CELT_H

#ifndef NULL
#define NULL ((void *)0)
#endif

typedef short celt_int16_t;
typedef int celt_int32_t;
typedef unsigned int celt_uint32_t;
typedef float celt_word16_t;

#define CELT_OK 0
#define CELT_BAD_ARG -1
#define CELT_INVALID_MODE -2
#define CELT_INTERNAL_ERROR -3
#define CELT_CORRUPTED_DATA -4
#define CELT_UNIMPLEMENTED -5
#define CELT_INVALID_STATE -6

typedef struct {
    int n;
    void *kfft;
    float *trig;
} mdct_lookup;

struct PsyDecay {
    const celt_word16_t *decayR;
};

typedef struct CELTMode {
    celt_uint32_t marker_start;
    celt_int32_t Fs;
    int overlap;
    int mdctSize;
    int nbChannels;

    int nbEBands;
    int nbPBands;
    int pitchEnd;

    const celt_int16_t *eBands;
    const celt_int16_t *pBands;

    celt_word16_t ePredCoef;

    int nbAllocVectors;
    const celt_int16_t *allocVectors;

    const celt_int16_t *const *bits;

    mdct_lookup mdct;
    void *fft;

    const celt_word16_t *window;

    int nbShortMdcts;
    int shortMdctSize;
    mdct_lookup shortMdct;
    const celt_word16_t *shortWindow;

    struct PsyDecay psy;

    int *prob;
    celt_uint32_t marker_end;
} CELTMode;

/* C runtime pieces used by os_support.h */
typedef struct {
    char _opaque[0x20];
} aud1_FILE;
aud1_FILE *ts4_addr_lbl_88C30DA8_88567BC8(void); /* __iob_func */
int fn_88569190(aud1_FILE *f, const char *fmt, ...); /* fprintf */
#define aud1_stderr (&ts4_addr_lbl_88C30DA8_88567BC8()[2])

/* FMOD's os_support.h: allocation tagged with file and line */
extern const char lbl_8802EE60[]; /* "c:\\anthill_builds\\fmod4\\lib\\libcelt\\os_support.h" */
extern const char lbl_8802EE94[]; /* "warning: %s\n" */
void *ts4_get_u32_lbl_88B3302C_883163B8(int size, const char *file, int line);
void ts4_get_u32_lbl_88B3302C_883163E0(void *ptr, const char *file, int line);
#define celt_alloc(size) ts4_get_u32_lbl_88B3302C_883163B8((size), lbl_8802EE60, 80)
#define celt_free(ptr) ts4_get_u32_lbl_88B3302C_883163E0((void *)(ptr), lbl_8802EE60, 134)
#define celt_warning(str) fn_88569190(aud1_stderr, lbl_8802EE94, (str))

#endif
