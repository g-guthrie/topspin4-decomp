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
/* Derived from libFLAC 1.2.1 src/libFLAC/stream_decoder.c (BSD license); see THIRD_PARTY_NOTICES.md.
 * FMOD's copy: no Ogg; the read callback takes a leading context argument
 * (unused here) so it can be passed to the bitreader. */

#include "lib2_flac.h"

/* read_callback_: refill callback of the bitreader, driving the client's
   read and eof callbacks. Referenced by name from lib2_flac_stream_decoder.c. */
FLAC__bool fn_883A4C20(void *ctx, FLAC__byte buffer[], lib2_size_t *bytes, void *client_data)
{
    FLAC__StreamDecoder *decoder = (FLAC__StreamDecoder *)client_data;
    (void)ctx;
    if(decoder->private_->eof_callback && decoder->private_->eof_callback(decoder, decoder->private_->client_data)) {
        *bytes = 0;
        decoder->protected_->state = FLAC__STREAM_DECODER_END_OF_STREAM;
        return false;
    }
    else if(*bytes > 0) {
        if(decoder->private_->is_seeking && decoder->private_->unparseable_frame_count > 20) {
            decoder->protected_->state = FLAC__STREAM_DECODER_ABORTED;
            return false;
        }
        else {
            const FLAC__StreamDecoderReadStatus status = decoder->private_->read_callback(decoder, buffer, bytes, decoder->private_->client_data);
            if(status == FLAC__STREAM_DECODER_READ_STATUS_ABORT) {
                decoder->protected_->state = FLAC__STREAM_DECODER_ABORTED;
                return false;
            }
            else if(*bytes == 0) {
                if(
                    status == FLAC__STREAM_DECODER_READ_STATUS_END_OF_STREAM ||
                    (decoder->private_->eof_callback && decoder->private_->eof_callback(decoder, decoder->private_->client_data))
                ) {
                    decoder->protected_->state = FLAC__STREAM_DECODER_END_OF_STREAM;
                    return false;
                }
                else
                    return true;
            }
            else
                return true;
        }
    }
    else {
        /* abort to avoid a deadlock */
        decoder->protected_->state = FLAC__STREAM_DECODER_ABORTED;
        return false;
    }
}
