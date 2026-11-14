/* Derived from zlib 1.1.4 (zlib license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family PNG2: inftrees.c of the second statically linked zlib copy (/Os). inflate_trees_fixed (0x88308418) and the
 * inffixed.h tables it returns are matched elsewhere; inflate_copyright is not reproduced. */

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

#define exop word.what.Exop
#define bits word.what.Bits

local int png2_zlib_huft_build_88307CD8 OF((
    uIntf *,
    uInt,
    uInt,
    const uIntf *,
    const uIntf *,
    inflate_huft * FAR*,
    uIntf *,
    inflate_huft *,
    uInt *,
    uIntf * ));

local const uInt lbl_88027710[31] = {
        3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 15, 17, 19, 23, 27, 31,
        35, 43, 51, 59, 67, 83, 99, 115, 131, 163, 195, 227, 258, 0, 0};

local const uInt png2_zlib_cplext[31] = {
        0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2,
        3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 0, 112, 112};
local const uInt png2_zlib_cpdist[30] = {
        1, 2, 3, 4, 5, 7, 9, 13, 17, 25, 33, 49, 65, 97, 129, 193,
        257, 385, 513, 769, 1025, 1537, 2049, 3073, 4097, 6145,
        8193, 12289, 16385, 24577};
local const uInt png2_zlib_cpdext[30] = {
        0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6,
        7, 7, 8, 8, 9, 9, 10, 10, 11, 11,
        12, 12, 13, 13};

#define BMAX 15

local int png2_zlib_huft_build_88307CD8(uIntf *b, uInt n, uInt s, const uIntf *d, const uIntf *e, inflate_huft **t, uIntf *m, inflate_huft *hp, uInt *hn, uIntf *v)
{

  uInt a;
  uInt c[BMAX+1];
  uInt f;
  int g;
  int h;
  register uInt i;
  register uInt j;
  register int k;
  int l;
  uInt mask;
  register uIntf *p;
  inflate_huft *q;
  struct inflate_huft_s r;
  inflate_huft *u[BMAX];
  register int w;
  uInt x[BMAX+1];
  uIntf *xp;
  int y;
  uInt z;

  p = c;
#define C0 *p++ = 0;
#define C2 C0 C0 C0 C0
#define C4 C2 C2 C2 C2
  C4
  p = b;  i = n;
  do {
    c[*p++]++;
  } while (--i);
  if (c[0] == n)
  {
    *t = (inflate_huft *)Z_NULL;
    *m = 0;
    return Z_OK;
  }

  l = *m;
  for (j = 1; j <= BMAX; j++)
    if (c[j])
      break;
  k = j;
  if ((uInt)l < j)
    l = j;
  for (i = BMAX; i; i--)
    if (c[i])
      break;
  g = i;
  if ((uInt)l > i)
    l = i;
  *m = l;

  for (y = 1 << j; j < i; j++, y <<= 1)
    if ((y -= c[j]) < 0)
      return Z_DATA_ERROR;
  if ((y -= c[i]) < 0)
    return Z_DATA_ERROR;
  c[i] += y;

  x[1] = j = 0;
  p = c + 1;  xp = x + 2;
  while (--i) {
    *xp++ = (j += *p++);
  }

  p = b;  i = 0;
  do {
    if ((j = *p++) != 0)
      v[x[j]++] = i;
  } while (++i < n);
  n = x[g];

  x[0] = i = 0;
  p = v;
  h = -1;
  w = -l;
  u[0] = (inflate_huft *)Z_NULL;
  q = (inflate_huft *)Z_NULL;
  z = 0;

  for (; k <= g; k++)
  {
    a = c[k];
    while (a--)
    {

      while (k > w + l)
      {
        h++;
        w += l;

        z = g - w;
        z = z > (uInt)l ? (uInt)l : z;
        if ((f = 1 << (j = k - w)) > a + 1)
        {
          f -= a + 1;
          xp = c + k;
          if (j < z)
            while (++j < z)
            {
              if ((f <<= 1) <= *++xp)
                break;
              f -= *xp;
            }
        }
        z = 1 << j;

        if (*hn + z > MANY)
          return Z_DATA_ERROR;
        u[h] = q = hp + *hn;
        *hn += z;

        if (h)
        {
          x[h] = i;
          r.bits = (Byte)l;
          r.exop = (Byte)j;
          j = i >> (w - l);
          r.base = (uInt)(q - u[h-1] - j);
          u[h-1][j] = r;
        }
        else
          *t = q;
      }

      r.bits = (Byte)(k - w);
      if (p >= v + n)
        r.exop = 128 + 64;
      else if (*p < s)
      {
        r.exop = (Byte)(*p < 256 ? 0 : 32 + 64);
        r.base = *p++;
      }
      else
      {
        r.exop = (Byte)(e[*p - s] + 16 + 64);
        r.base = d[*p++ - s];
      }

      f = 1 << (k - w);
      for (j = i >> w; j < z; j += f)
        q[j] = r;

      for (j = 1 << (k - 1); i & j; j >>= 1)
        i ^= j;
      i ^= j;

      mask = (1 << w) - 1;
      while ((i & mask) != x[h])
      {
        h--;
        w -= l;
        mask = (1 << w) - 1;
      }
    }
  }

  return y != 0 && g != 1 ? Z_BUF_ERROR : Z_OK;
}

int png2_zlib_inflate_trees_bits_88308178(uIntf *c, uIntf *bb, inflate_huft **tb, inflate_huft *hp, z_streamp z)
{
  int r;
  uInt hn = 0;
  uIntf *v;

  if ((v = (uIntf*)ZALLOC(z, 19, sizeof(uInt))) == Z_NULL)
    return Z_MEM_ERROR;
  r = png2_zlib_huft_build_88307CD8(c, 19, 19, (uIntf*)Z_NULL, (uIntf*)Z_NULL,
                 tb, bb, hp, &hn, v);
  if (r == Z_DATA_ERROR)
    z->msg = (char *)lbl_88028A24;
  else if (r == Z_BUF_ERROR || *bb == 0)
  {
    z->msg = (char *)lbl_88028A00;
    r = Z_DATA_ERROR;
  }
  ZFREE(z, v);
  return r;
}

int png2_zlib_inflate_trees_dynamic_88308258(uInt nl, uInt nd, uIntf *c, uIntf *bl, uIntf *bd, inflate_huft **tl, inflate_huft **td, inflate_huft *hp, z_streamp z)
{
  int r;
  uInt hn = 0;
  uIntf *v;

  if ((v = (uIntf*)ZALLOC(z, 288, sizeof(uInt))) == Z_NULL)
    return Z_MEM_ERROR;

  r = png2_zlib_huft_build_88307CD8(c, nl, 257, lbl_88027710, png2_zlib_cplext, tl, bl, hp, &hn, v);
  if (r != Z_OK || *bl == 0)
  {
    if (r == Z_DATA_ERROR)
      z->msg = (char *)lbl_88028A6C;
    else if (r != Z_MEM_ERROR)
    {
      z->msg = (char *)lbl_88028A4C;
      r = Z_DATA_ERROR;
    }
    ZFREE(z, v);
    return r;
  }

  r = png2_zlib_huft_build_88307CD8(c + nl, nd, 0, png2_zlib_cpdist, png2_zlib_cpdext, td, bd, hp, &hn, v);
  if (r != Z_OK || (*bd == 0 && nl > 257))
  {
    if (r == Z_DATA_ERROR)
      z->msg = (char *)lbl_88028AD0;
    else if (r == Z_BUF_ERROR) {
      z->msg = (char *)lbl_88028AB4;
      r = Z_DATA_ERROR;
    }
    else if (r != Z_MEM_ERROR)
    {
      z->msg = (char *)lbl_88028A90;
      r = Z_DATA_ERROR;
    }
    ZFREE(z, v);
    return r;
  }

  ZFREE(z, v);
  return Z_OK;
}

