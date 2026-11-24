/* Loader_DLL.xex 0x8316B9E0-0x8316BD0C, executable version 0.0.0.3.
 * zlib deflate (trees.c): _tr_align. */
typedef unsigned char uch;
typedef unsigned short ush;

typedef struct {
    void *strm;
    int status;
    uch *pending_buf;
    unsigned pending_buf_size;
    uch *pending_out;
    unsigned pending;
    unsigned char pad1[0x16ac - 0x18];
    int last_eob_len;
    ush bi_buf;
    int bi_valid;
} Ts4lDeflateState;

#define Buf_size 16
#define put_byte(s, c) { s->pending_buf[s->pending++] = (uch)(c); }
#define put_short(s, w) { put_byte(s, (uch)((w) & 0xff)); put_byte(s, (uch)((ush)(w) >> 8)); }
#define send_bits(s, value, length) \
    { int len = length; \
      if (s->bi_valid > (int)Buf_size - len) { \
          int val = value; \
          s->bi_buf |= (val << s->bi_valid); \
          put_short(s, s->bi_buf); \
          s->bi_buf = (ush)val >> (Buf_size - s->bi_valid); \
          s->bi_valid += len - Buf_size; \
      } else { \
          s->bi_buf |= (value) << s->bi_valid; \
          s->bi_valid += len; \
      } \
    }

#ifdef _MSC_VER
__forceinline
#endif
static void ts4l_bi_flush(Ts4lDeflateState *s)
{
    if (s->bi_valid == 16) {
        put_short(s, s->bi_buf);
        s->bi_buf = 0;
        s->bi_valid = 0;
    } else if (s->bi_valid >= 8) {
        put_byte(s, (uch)s->bi_buf);
        s->bi_buf >>= 8;
        s->bi_valid -= 8;
    }
}

void ts4l_tr_align_8316B9E0(Ts4lDeflateState *s)
{
    send_bits(s, 2, 3);
    send_bits(s, 0, 7);
    ts4l_bi_flush(s);
    if (1 + s->last_eob_len + 10 - s->bi_valid < 9) {
        send_bits(s, 2, 3);
        send_bits(s, 0, 7);
        ts4l_bi_flush(s);
    }
    s->last_eob_len = 7;
}
