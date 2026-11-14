/* Derived from zlib 1.1.4 (zlib license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family PNG2: inffast.c of the second statically linked zlib copy (/Os). */

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

struct inflate_codes_state {int dummy;};

#define exop word.what.Exop
#define bits word.what.Bits

#define GRABBITS(j) {while(k<(j)){b|=((uLong)NEXTBYTE)<<k;k+=8;}}
#define UNGRAB {c=z->avail_in-n;c=(k>>3)<c?k>>3:c;n+=c;p-=c;k-=c<<3;}

int png2_zlib_inflate_fast_883085B0(uInt bl, uInt bd, inflate_huft *tl, inflate_huft *td, inflate_blocks_statef *s, z_streamp z)
{
  inflate_huft *t;
  uInt e;
  uLong b;
  uInt k;
  Bytef *p;
  uInt n;
  Bytef *q;
  uInt m;
  uInt ml;
  uInt md;
  uInt c;
  uInt d;
  Bytef *r;

  LOAD

  ml = lbl_88028AF0[bl];
  md = lbl_88028AF0[bd];

  do {

    GRABBITS(20)
    if ((e = (t = tl + ((uInt)b & ml))->exop) == 0)
    {
      DUMPBITS(t->bits)
      Tracevv((stderr, t->base >= 0x20 && t->base < 0x7f ?
                "inflate:         * literal '%c'\n" :
                "inflate:         * literal 0x%02x\n", t->base));
      *q++ = (Byte)t->base;
      m--;
      continue;
    }
    do {
      DUMPBITS(t->bits)
      if (e & 16)
      {

        e &= 15;
        c = t->base + ((uInt)b & lbl_88028AF0[e]);
        DUMPBITS(e)
        Tracevv((stderr, "inflate:         * length %u\n", c));

        GRABBITS(15);
        e = (t = td + ((uInt)b & md))->exop;
        do {
          DUMPBITS(t->bits)
          if (e & 16)
          {

            e &= 15;
            GRABBITS(e)
            d = t->base + ((uInt)b & lbl_88028AF0[e]);
            DUMPBITS(e)
            Tracevv((stderr, "inflate:         * distance %u\n", d));

            m -= c;
            r = q - d;
            if (r < s->window)
            {
              do {
                r += s->end - s->window;
              } while (r < s->window);
              e = s->end - r;
              if (c > e)
              {
                c -= e;
                do {
                    *q++ = *r++;
                } while (--e);
                r = s->window;
                do {
                    *q++ = *r++;
                } while (--c);
              }
              else
              {
                *q++ = *r++;  c--;
                *q++ = *r++;  c--;
                do {
                    *q++ = *r++;
                } while (--c);
              }
            }
            else
            {
              *q++ = *r++;  c--;
              *q++ = *r++;  c--;
              do {
                *q++ = *r++;
              } while (--c);
            }
            break;
          }
          else if ((e & 64) == 0)
          {
            t += t->base;
            e = (t += ((uInt)b & lbl_88028AF0[e]))->exop;
          }
          else
          {
            z->msg = (char *)lbl_880DFB08;
            UNGRAB
            UPDATE
            return Z_DATA_ERROR;
          }
        } while (1);
        break;
      }
      if ((e & 64) == 0)
      {
        t += t->base;
        if ((e = (t += ((uInt)b & lbl_88028AF0[e]))->exop) == 0)
        {
          DUMPBITS(t->bits)
          Tracevv((stderr, t->base >= 0x20 && t->base < 0x7f ?
                    "inflate:         * literal '%c'\n" :
                    "inflate:         * literal 0x%02x\n", t->base));
          *q++ = (Byte)t->base;
          m--;
          break;
        }
      }
      else if (e & 32)
      {
        Tracevv((stderr, "inflate:         * end of block\n"));
        UNGRAB
        UPDATE
        return Z_STREAM_END;
      }
      else
      {
        z->msg = (char *)lbl_880DFAEC;
        UNGRAB
        UPDATE
        return Z_DATA_ERROR;
      }
    } while (1);
  } while (m >= 258 && n >= 10);

  UNGRAB
  UPDATE
  return Z_OK;
}
