/* (C) 2001-2008 Timothy B. Terriberry
   (C) 2008 Jean-Marc Valin */
/* Derived from CELT 0.6.1 libcelt/rangedec.c (BSD license); see
   THIRD_PARTY_NOTICES.md. Float build as linked into FMOD Ex. */
#include "lb3_celt.h"

/* ec_byte_read1 / ec_byte_adv1 live in entdec.c's unit */
int ts4_if_get_u32_off0_883B39D0(ec_byte_buffer *b);   /* ec_byte_read1 */
void ts4_get_u32_off4_883B39C0(ec_byte_buffer *b);     /* ec_byte_adv1 */
#define ec_byte_read1 ts4_if_get_u32_off0_883B39D0
#define ec_byte_adv1 ts4_get_u32_off4_883B39C0

/* upstream name -> placeholder/new name in Swing_DLL.xex */
#define ec_dec_init lb3_celt_ec_dec_init_883B5358
#define ec_decode fn_883B5418 /* referenced by name from another source */
#define ec_decode_bin lb3_celt_ec_decode_bin_883B5468
#define ec_dec_update lb3_celt_ec_dec_update_883B54C0
#define ec_dec_tell lb3_celt_ec_dec_tell_883B5588

/*Constants used by the entropy encoder/decoder (mfrngcod.h).*/
#define EC_UNIT_BITS (8)
#define EC_SYM_BITS (8)
#define EC_CODE_BITS (32)
#define EC_SYM_MAX ((1U<<EC_SYM_BITS)-1)
#define EC_CODE_TOP (((ec_uint32)1U)<<(EC_CODE_BITS-1))
#define EC_CODE_BOT (EC_CODE_TOP>>EC_SYM_BITS)
#define EC_CODE_EXTRA ((EC_CODE_BITS-2)%EC_SYM_BITS+1)
#define EC_CODE_MASK ((((((ec_uint32)1U)<<(EC_CODE_BITS-1))-1)<<1)|1)
#define EC_MINI(_a,_b) ((_a)+(((_b)-(_a))&-((_b)<(_a))))
#define IMUL32(a,b) ((a)*(b))

unsigned ec_decode(ec_dec *_this,unsigned _ft);
unsigned ec_decode_bin(ec_dec *_this,unsigned bits);
void ec_dec_update(ec_dec *_this,unsigned _fl,unsigned _fh,unsigned _ft);
void ec_dec_init(ec_dec *_this,ec_byte_buffer *_buf);
long ec_dec_tell(ec_dec *_this,int _b);

/*Gets the next byte of input.
  After all the bytes in the current packet have been consumed, and the extra
   end code returned if needed, this function will continue to return zero each
   time it is called.
  Return: The next byte of input.*/
static int ec_dec_in(ec_dec *_this){
  int ret;
  ret=ec_byte_read1(_this->buf);
  if(ret<0){
    ret=0;
    /*Needed to keep oc_dec_tell() operating correctly.*/
    ec_byte_adv1(_this->buf);
  }
  return ret;
}

/*Normalizes the contents of dif and rng so that rng lies entirely in the
   high-order symbol.*/
static LB3_FORCEINLINE void ec_dec_normalize(ec_dec *_this){
  /*If the range is too small, rescale it and input some bits.*/
  while(_this->rng<=EC_CODE_BOT){
    int sym;
    _this->rng<<=EC_SYM_BITS;
    /*Use up the remaining bits from our last symbol.*/
    sym=(_this->rem<<(EC_CODE_EXTRA))&EC_SYM_MAX;
    /*Read the next value from the input.*/
    _this->rem=ec_dec_in(_this);
    /*Take the rest of the bits we need from this new symbol.*/
    sym|=_this->rem>>(EC_SYM_BITS-EC_CODE_EXTRA);
    _this->dif=((_this->dif<<EC_SYM_BITS)-sym)&EC_CODE_MASK;
    /*dif can never be larger than EC_CODE_TOP.
      This is equivalent to the slightly more readable:
      if(_this->dif>EC_CODE_TOP)_this->dif-=EC_CODE_TOP;*/
    _this->dif^=_this->dif&(_this->dif-1)&EC_CODE_TOP;
  }
}

void ec_dec_init(ec_dec *_this,ec_byte_buffer *_buf){
  _this->buf=_buf;
  _this->rem=ec_dec_in(_this);
  _this->rng=1U<<EC_CODE_EXTRA;
  _this->dif=_this->rng-(_this->rem>>(EC_SYM_BITS-EC_CODE_EXTRA));
  /*Normalize the interval.*/
  ec_dec_normalize(_this);
}


unsigned ec_decode(ec_dec *_this,unsigned _ft){
  unsigned s;
  _this->nrm=_this->rng/_ft;
  s=(unsigned)((_this->dif-1)/_this->nrm);
  return _ft-EC_MINI(s+1,_ft);
}

unsigned ec_decode_bin(ec_dec *_this,unsigned bits){
   unsigned s;
   ec_uint32 ft;
   ft = (ec_uint32)1<<bits;
   _this->nrm=_this->rng>>bits;
   s=(unsigned)((_this->dif-1)/_this->nrm);
   return ft-EC_MINI(s+1,ft);
}

void ec_dec_update(ec_dec *_this,unsigned _fl,unsigned _fh,unsigned _ft){
  ec_uint32 s;
  s=IMUL32(_this->nrm,(_ft-_fh));
  _this->dif-=s;
  _this->rng=_fl>0?IMUL32(_this->nrm,(_fh-_fl)):_this->rng-s;
  ec_dec_normalize(_this);
}

long ec_dec_tell(ec_dec *_this,int _b){
  ec_uint32 r;
  int       l;
  long      nbits;
  nbits=(ec_byte_bytes(_this->buf)-(EC_CODE_BITS+EC_SYM_BITS-1)/EC_SYM_BITS)*
   EC_SYM_BITS;
  /*To handle the non-integral number of bits still left in the encoder state,
     we compute the number of bits of low that must be encoded to ensure that
     the value is inside the range for any possible subsequent bits.
    Note that this is subtly different than the actual value we would end the
     stream with, which tries to make as many of the trailing bits zeros as
     possible.*/
  nbits+=EC_CODE_BITS;
  nbits<<=_b;
  l=EC_ILOG(_this->rng);
  r=_this->rng>>(l-16);
  while(_b-->0){
    int b;
    r=(r*r)>>15;
    b=(int)(r>>16);
    l=(l<<1)|b;
    r>>=b;
  }
  return nbits-l;
}
