/* libFLAC - Free Lossless Audio Codec library
 * Copyright (C) 2000,2001,2002,2003,2004,2005,2006,2007  Josh Coalson
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * - Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * - Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 *
 * - Neither the name of the Xiph.org Foundation nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/* Derived from libFLAC 1.2.1 src/libFLAC/fixed.c (BSD license); see THIRD_PARTY_NOTICES.md. */

typedef int FLAC__int32;
void *fn_8857ACB8(void *dst, const void *src, unsigned int n);   /* memcpy */

/* FLAC__fixed_restore_signal: undo a fixed polynomial predictor of order 0..4. */
void lib2_FLAC__fixed_restore_signal_883BAA20(const FLAC__int32 residual[], unsigned data_len, unsigned order, FLAC__int32 data[])
{
    int i, idata_len = (int)data_len;

    switch (order) {
        case 0:
            fn_8857ACB8(data, residual, sizeof(residual[0]) * data_len);
            break;
        case 1:
            for (i = 0; i < idata_len; i++)
                data[i] = residual[i] + data[i - 1];
            break;
        case 2:
            for (i = 0; i < idata_len; i++)
                data[i] = residual[i] + (data[i - 1] << 1) - data[i - 2];
            break;
        case 3:
            for (i = 0; i < idata_len; i++)
                data[i] = residual[i] + (((data[i - 1] - data[i - 2]) << 1) + (data[i - 1] - data[i - 2])) + data[i - 3];
            break;
        case 4:
            for (i = 0; i < idata_len; i++)
                data[i] = residual[i] + ((data[i - 1] + data[i - 3]) << 2) - ((data[i - 2] << 2) + (data[i - 2] << 1)) - data[i - 4];
            break;
        default:
            break;
    }
}
