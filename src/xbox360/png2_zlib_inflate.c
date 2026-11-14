/* Derived from zlib 1.1.4 (zlib license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family PNG2: inflate() from inflate.c of the second statically linked zlib copy (/Os); the other inflate.c entry
 * points (inflateReset, inflateEnd, inflateInit2_, inflateInit_) are matched elsewhere, the rest were dead-stripped. */

#include "png2_zlib_inf.h"

struct inflate_blocks_state;
typedef struct inflate_blocks_state FAR inflate_blocks_statef;

extern inflate_blocks_statef * png2_zlib_inflate_blocks_new_88304190 OF((
    z_streamp z,
    check_func c,
    uInt w));

extern int png2_zlib_inflate_blocks_88304278 OF((
    inflate_blocks_statef *,
    z_streamp ,
    int));

extern void png2_zlib_inflate_blocks_reset_883040C8 OF((
    inflate_blocks_statef *,
    z_streamp ,
    uLongf *));

extern int ts4_get_fn_883040C8_88304AC8 OF((
    inflate_blocks_statef *,
    z_streamp));

struct inflate_blocks_state {int dummy;};

typedef enum {
      METHOD,
      FLAG,
      DICT4,
      DICT3,
      DICT2,
      DICT1,
      DICT0,
      BLOCKS,
      CHECK4,
      CHECK3,
      CHECK2,
      CHECK1,
      DONE,
      BAD}
inflate_mode;

struct internal_state {

  inflate_mode  mode;

  union {
    uInt method;
    struct {
      uLong was;
      uLong need;
    } check;
    uInt marker;
  } sub;

  int  nowrap;
  uInt wbits;
  inflate_blocks_statef
    *blocks;

};





#define NEEDBYTE {if(z->avail_in==0)return r;r=f;}
#define NEXTBYTE (z->avail_in--,z->total_in++,*z->next_in++)

int png2_zlib_inflate_882F3178(z_streamp z, int f)
{
  int r;
  uInt b;

  if (z == Z_NULL || z->state == Z_NULL || z->next_in == Z_NULL)
    return Z_STREAM_ERROR;
  f = f == Z_FINISH ? Z_BUF_ERROR : Z_OK;
  r = Z_BUF_ERROR;
  while (1) switch (z->state->mode)
  {
    case METHOD:
      NEEDBYTE
      if (((z->state->sub.method = NEXTBYTE) & 0xf) != Z_DEFLATED)
      {
        z->state->mode = BAD;
        z->msg = (char *)lbl_880DFB58;
        z->state->sub.marker = 5;
        break;
      }
      if ((z->state->sub.method >> 4) + 8 > z->state->wbits)
      {
        z->state->mode = BAD;
        z->msg = (char *)lbl_880DFB74;
        z->state->sub.marker = 5;
        break;
      }
      z->state->mode = FLAG;
    case FLAG:
      NEEDBYTE
      b = NEXTBYTE;
      if (((z->state->sub.method << 8) + b) % 31)
      {
        z->state->mode = BAD;
        z->msg = (char *)lbl_880DFB40;
        z->state->sub.marker = 5;
        break;
      }
      Tracev((stderr, "inflate: zlib header ok\n"));
      if (!(b & PRESET_DICT))
      {
        z->state->mode = BLOCKS;
        break;
      }
      z->state->mode = DICT4;
    case DICT4:
      NEEDBYTE
      z->state->sub.check.need = (uLong)NEXTBYTE << 24;
      z->state->mode = DICT3;
    case DICT3:
      NEEDBYTE
      z->state->sub.check.need += (uLong)NEXTBYTE << 16;
      z->state->mode = DICT2;
    case DICT2:
      NEEDBYTE
      z->state->sub.check.need += (uLong)NEXTBYTE << 8;
      z->state->mode = DICT1;
    case DICT1:
      NEEDBYTE
      z->state->sub.check.need += (uLong)NEXTBYTE;
      z->adler = z->state->sub.check.need;
      z->state->mode = DICT0;
      return Z_NEED_DICT;
    case DICT0:
      z->state->mode = BAD;
      z->msg = (char *)lbl_880DFC58;
      z->state->sub.marker = 0;
      return Z_STREAM_ERROR;
    case BLOCKS:
      r = png2_zlib_inflate_blocks_88304278(z->state->blocks, z, r);
      if (r == Z_DATA_ERROR)
      {
        z->state->mode = BAD;
        z->state->sub.marker = 0;
        break;
      }
      if (r == Z_OK)
        r = f;
      if (r != Z_STREAM_END)
        return r;
      r = f;
      png2_zlib_inflate_blocks_reset_883040C8(z->state->blocks, z, &z->state->sub.check.was);
      if (z->state->nowrap)
      {
        z->state->mode = DONE;
        break;
      }
      z->state->mode = CHECK4;
    case CHECK4:
      NEEDBYTE
      z->state->sub.check.need = (uLong)NEXTBYTE << 24;
      z->state->mode = CHECK3;
    case CHECK3:
      NEEDBYTE
      z->state->sub.check.need += (uLong)NEXTBYTE << 16;
      z->state->mode = CHECK2;
    case CHECK2:
      NEEDBYTE
      z->state->sub.check.need += (uLong)NEXTBYTE << 8;
      z->state->mode = CHECK1;
    case CHECK1:
      NEEDBYTE
      z->state->sub.check.need += (uLong)NEXTBYTE;

      if (z->state->sub.check.was != z->state->sub.check.need)
      {
        z->state->mode = BAD;
        z->msg = (char *)lbl_880DFBB8;
        z->state->sub.marker = 5;
        break;
      }
      Tracev((stderr, "inflate: zlib check ok\n"));
      z->state->mode = DONE;
    case DONE:
      return Z_STREAM_END;
    case BAD:
      return Z_DATA_ERROR;
    default:
      return Z_STREAM_ERROR;
  }
}



