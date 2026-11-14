/* Derived from zlib 1.1.4 (zlib license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family PNG2: infutil.c of the second statically linked zlib copy (/Os). inflate_mask is the image table
 * lbl_88028AF0 and is only declared here. */

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

typedef struct inflate_huft_s FAR inflate_huft;

struct inflate_huft_s {
  union {
    struct {
      Byte Exop;
      Byte Bits;
    } what;
    uInt pad;
  } word;
  uInt base;
};

#define MANY 1440

extern int png2_zlib_inflate_trees_bits_88308178 OF((
    uIntf *,
    uIntf *,
    inflate_huft * FAR *,
    inflate_huft *,
    z_streamp));

extern int png2_zlib_inflate_trees_dynamic_88308258 OF((
    uInt,
    uInt,
    uIntf *,
    uIntf *,
    uIntf *,
    inflate_huft * FAR *,
    inflate_huft * FAR *,
    inflate_huft *,
    z_streamp));

extern int ts4_addr_lbl_88028900_88308418 OF((
    uIntf *,
    uIntf *,
    inflate_huft * FAR *,
    inflate_huft * FAR *,
    z_streamp));

struct inflate_codes_state;
typedef struct inflate_codes_state FAR inflate_codes_statef;

extern inflate_codes_statef *ts4_if_get_u32_off20_88307630 OF((
    uInt, uInt,
    inflate_huft *, inflate_huft *,
    z_streamp ));

extern int png2_zlib_inflate_codes_88307690 OF((
    inflate_blocks_statef *,
    z_streamp ,
    int));

extern void ts4_get_u32_off24_88307CC0 OF((
    inflate_codes_statef *,
    z_streamp ));

typedef enum {
      TYPE,
      LENS,
      STORED,
      TABLE,
      BTREE,
      DTREE,
      CODES,
      DRY,
      DONE,
      BAD}
inflate_block_mode;

struct inflate_blocks_state {

  inflate_block_mode  mode;

  union {
    uInt left;
    struct {
      uInt table;
      uInt index;
      uIntf *blens;
      uInt bb;
      inflate_huft *tb;
    } trees;
    struct {
      inflate_codes_statef
         *codes;
    } decode;
  } sub;
  uInt last;

  uInt bitk;
  uLong bitb;
  inflate_huft *hufts;
  Bytef *window;
  Bytef *end;
  Bytef *read;
  Bytef *write;
  check_func checkfn;
  uLong check;

};

#define UPDBITS {s->bitb=b;s->bitk=k;}
#define UPDIN {z->avail_in=n;z->total_in+=p-z->next_in;z->next_in=p;}
#define UPDOUT {s->write=q;}
#define UPDATE {UPDBITS UPDIN UPDOUT}
#define LEAVE {UPDATE return png2_zlib_inflate_flush_88308448(s,z,r);}

#define LOADIN {p=z->next_in;n=z->avail_in;b=s->bitb;k=s->bitk;}
#define NEEDBYTE {if(n)r=Z_OK;else LEAVE}
#define NEXTBYTE (n--,*p++)
#define NEEDBITS(j) {while(k<(j)){NEEDBYTE;b|=((uLong)NEXTBYTE)<<k;k+=8;}}
#define DUMPBITS(j) {b>>=(j);k-=(j);}

#define WAVAIL (uInt)(q<s->read?s->read-q-1:s->end-q)
#define LOADOUT {q=s->write;m=(uInt)WAVAIL;}
#define WRAP {if(q==s->end&&s->read!=s->window){q=s->window;m=(uInt)WAVAIL;}}
#define FLUSH {UPDOUT r=png2_zlib_inflate_flush_88308448(s,z,r); LOADOUT}
#define NEEDOUT {if(m==0){WRAP if(m==0){FLUSH WRAP if(m==0) LEAVE}}r=Z_OK;}
#define OUTBYTE(a) {*q++=(Byte)(a);m--;}

#define LOAD {LOADIN LOADOUT}

extern uInt lbl_88028AF0[17];

extern int png2_zlib_inflate_flush_88308448 OF((
    inflate_blocks_statef *,
    z_streamp ,
    int));

struct inflate_codes_state {int dummy;};

int png2_zlib_inflate_flush_88308448(inflate_blocks_statef *s, z_streamp z, int r)
{
  uInt n;
  Bytef *p;
  Bytef *q;

  p = z->next_out;
  q = s->read;

  n = (uInt)((q <= s->write ? s->write : s->end) - q);
  if (n > z->avail_out) n = z->avail_out;
  if (n && r == Z_BUF_ERROR) r = Z_OK;

  z->avail_out -= n;
  z->total_out += n;

  if (s->checkfn != Z_NULL)
    z->adler = s->check = (*s->checkfn)(s->check, q, n);

  zmemcpy(p, q, n);
  p += n;
  q += n;

  if (q == s->end)
  {

    q = s->window;
    if (s->write == s->end)
      s->write = s->window;

    n = (uInt)(s->write - q);
    if (n > z->avail_out) n = z->avail_out;
    if (n && r == Z_BUF_ERROR) r = Z_OK;

    z->avail_out -= n;
    z->total_out += n;

    if (s->checkfn != Z_NULL)
      z->adler = s->check = (*s->checkfn)(s->check, q, n);

    zmemcpy(p, q, n);
    p += n;
    q += n;
  }

  z->next_out = p;
  s->read = q;

  return r;
}
