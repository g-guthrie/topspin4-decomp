/* Derived from zlib 1.1.4 (zlib license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family PNG2: infcodes.c of the second statically linked zlib copy (/Os). inflate_codes_new (0x88307630) and
 * inflate_codes_free (0x88307CC0) are matched elsewhere and only declared here. */

#include "png2_zlib_inf.h"

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

extern int png2_zlib_inflate_fast_883085B0 OF((
    uInt,
    uInt,
    inflate_huft *,
    inflate_huft *,
    inflate_blocks_statef *,
    z_streamp ));

#define exop word.what.Exop
#define bits word.what.Bits

typedef enum {
      START,
      LEN,
      LENEXT,
      DIST,
      DISTEXT,
      COPY,
      LIT,
      WASH,
      END,
      BADCODE}
inflate_codes_mode;

struct inflate_codes_state {

  inflate_codes_mode mode;

  uInt len;
  union {
    struct {
      inflate_huft *tree;
      uInt need;
    } code;
    uInt lit;
    struct {
      uInt get;
      uInt dist;
    } copy;
  } sub;

  Byte lbits;
  Byte dbits;
  inflate_huft *ltree;
  inflate_huft *dtree;

};

int png2_zlib_inflate_codes_88307690(inflate_blocks_statef *s, z_streamp z, int r)
{
  uInt j;
  inflate_huft *t;
  uInt e;
  uLong b;
  uInt k;
  Bytef *p;
  uInt n;
  Bytef *q;
  uInt m;
  Bytef *f;
  inflate_codes_statef *c = s->sub.decode.codes;

  LOAD

  while (1) switch (c->mode)
  {
    case START:
      if (m >= 258 && n >= 10)
      {
        UPDATE
        r = png2_zlib_inflate_fast_883085B0(c->lbits, c->dbits, c->ltree, c->dtree, s, z);
        LOAD
        if (r != Z_OK)
        {
          c->mode = r == Z_STREAM_END ? WASH : BADCODE;
          break;
        }
      }
      c->sub.code.need = c->lbits;
      c->sub.code.tree = c->ltree;
      c->mode = LEN;
    case LEN:
      j = c->sub.code.need;
      NEEDBITS(j)
      t = c->sub.code.tree + ((uInt)b & lbl_88028AF0[j]);
      DUMPBITS(t->bits)
      e = (uInt)(t->exop);
      if (e == 0)
      {
        c->sub.lit = t->base;
        Tracevv((stderr, t->base >= 0x20 && t->base < 0x7f ?
                 "inflate:         literal '%c'\n" :
                 "inflate:         literal 0x%02x\n", t->base));
        c->mode = LIT;
        break;
      }
      if (e & 16)
      {
        c->sub.copy.get = e & 15;
        c->len = t->base;
        c->mode = LENEXT;
        break;
      }
      if ((e & 64) == 0)
      {
        c->sub.code.need = e;
        c->sub.code.tree = t + t->base;
        break;
      }
      if (e & 32)
      {
        Tracevv((stderr, "inflate:         end of block\n"));
        c->mode = WASH;
        break;
      }
      c->mode = BADCODE;
      z->msg = (char *)lbl_880DFAEC;
      r = Z_DATA_ERROR;
      LEAVE
    case LENEXT:
      j = c->sub.copy.get;
      NEEDBITS(j)
      c->len += (uInt)b & lbl_88028AF0[j];
      DUMPBITS(j)
      c->sub.code.need = c->dbits;
      c->sub.code.tree = c->dtree;
      Tracevv((stderr, "inflate:         length %u\n", c->len));
      c->mode = DIST;
    case DIST:
      j = c->sub.code.need;
      NEEDBITS(j)
      t = c->sub.code.tree + ((uInt)b & lbl_88028AF0[j]);
      DUMPBITS(t->bits)
      e = (uInt)(t->exop);
      if (e & 16)
      {
        c->sub.copy.get = e & 15;
        c->sub.copy.dist = t->base;
        c->mode = DISTEXT;
        break;
      }
      if ((e & 64) == 0)
      {
        c->sub.code.need = e;
        c->sub.code.tree = t + t->base;
        break;
      }
      c->mode = BADCODE;
      z->msg = (char *)lbl_880DFB08;
      r = Z_DATA_ERROR;
      LEAVE
    case DISTEXT:
      j = c->sub.copy.get;
      NEEDBITS(j)
      c->sub.copy.dist += (uInt)b & lbl_88028AF0[j];
      DUMPBITS(j)
      Tracevv((stderr, "inflate:         distance %u\n", c->sub.copy.dist));
      c->mode = COPY;
    case COPY:
      f = q - c->sub.copy.dist;
      while (f < s->window)
        f += s->end - s->window;
      while (c->len)
      {
        NEEDOUT
        OUTBYTE(*f++)
        if (f == s->end)
          f = s->window;
        c->len--;
      }
      c->mode = START;
      break;
    case LIT:
      NEEDOUT
      OUTBYTE(c->sub.lit)
      c->mode = START;
      break;
    case WASH:
      if (k > 7)
      {
        Assert(k < 16, "png2_zlib_inflate_codes_88307690 grabbed too many bytes")
        k -= 8;
        n++;
        p--;
      }
      FLUSH
      if (s->read != s->write)
        LEAVE
      c->mode = END;
    case END:
      r = Z_STREAM_END;
      LEAVE
    case BADCODE:
      r = Z_DATA_ERROR;
      LEAVE
    default:
      r = Z_STREAM_ERROR;
      LEAVE
  }
}

