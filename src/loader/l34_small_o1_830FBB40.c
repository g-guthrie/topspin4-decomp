/* Loader_DLL.xex 0x830A6298-0x833FA2A0, executable version 0.0.0.3. */
#ifdef __GNUC__
#define L34_UNUSED __attribute__((unused))
#else
#define L34_UNUSED
#endif
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned long long u64;
extern int lbl_83530F2C;
typedef struct { int a; float f; } l34_ef_t;
extern int ts4_if_tail_fn_83415CD0_8340D850(void *p, u32 tag);
extern int fn_83145338(void *p);
extern void fn_833E3AD0(void *d, const void *s, u32 n);
extern void fn_83126218(float a, float b);
extern int fn_83116F28(void *p, int v);
int ts4l_is_below_80_833F7BE8(u32 a){ return a<0x80; }
int ts4l_is_below_80_u16_833FA2A0(u16 a){ return a<0x80; }
u16 ts4l_pack_u16_830FBB40(u16 a,u16 b){ return (a<<8)|b; }
int ts4l_select_flag_83146A80(int a L34_UNUSED,int b){ return b ? 0x8000FFFF : 0; }
u32 ts4l_div_by_u16_ptr_831F2EB0(char *p){ return *(u32*)(p+0x34) / *(u16*)(*(char**)(p+0x2c)+0xc); }
int ts4l_mask_if_ne_83174D38(int *a,int *b){ return *a != *b ? -1 : 0; }
int ts4l_is_fmt_830A68A8(int a){ return a==0x18280186||a==0x28280186; }
int ts4l_before_830A6298(char *p,u32 v){ u32 x=*(u32*)(p+0x2a9c); return (u32)(x-v) < (u32)(x-**(u32**)(p+0x2a90)); }
int ts4l_in_window_830DFCC0(u32 a){ return a>=0xc0100000 && a<0xc8000000; }
int ts4l_overflows_830E0358(u32 x L34_UNUSED,u32 a,u32 b L34_UNUSED,u32 c){ return a<=0x1844 && a+c>0x1844; }
u32 ts4l_hash_u16_83100588(u16 *s){ u32 h=0; u32 c=*s; while(c){ h=h*0x21+c; c=*++s; } return h; }
u32 ts4l_sum_u16_83146188(int u L34_UNUSED,u16 *s){ u32 h=0; u32 c=*s; while(c){ h+=c; c=*++s; } return h&0x1f; }
u8 ts4l_eq_vec2_83149548(float *a,float *b){ return a[0]==b[0] && a[1]==b[1]; }
int ts4l_mode_ok_83121A48(char *p){ int k=*(int*)(p+0xa0); if(k==2||k==3){ if((*(u32*)(p+0xf4)&1)==1) return 1; } return 0; }
int ts4l_sum_pairs_83150FF8(int unused L34_UNUSED,int n,l34_ef_t *p){ int i; u32 s=0; for(i=0;i<n;i++){ s+=(u32)p[i].f+p[i].a; } return s; }
void ts4l_copy_elem_8312D548(char **s,int i,const void *src){ char *d=*s+i*0x1c; if(d) fn_833E3AD0(d,src,0x1c); }
void ts4l_copy_elem_8312D618(char **s,int i,const void *src){ char *d=*s+i*0xa8; if(d) fn_833E3AD0(d,src,0xa8); }
void ts4l_tail_8312E0E0(float *p){ fn_83126218(p[3],p[4]); }
int ts4l_tail_83133230(char **s,int i,int v){ char *d=*s+i*0xc; return fn_83116F28(d,v); }
void ts4l_get_f_83144360(char *p,float *out){ float f; if(*(u16*)p&8) f=(*(float**)(p+8))[1]; else f=*(float*)(p+8); *out=f; }
u64 ts4l_div_round_83180A60(u64 a,u64 b,int mode){ if(mode==1) a=a+b-1; if(mode==2) a=a+(b>>1); return a/b; }
int ts4l_is_finite_83184640(float x){ return ((*(u32*)&x)&0x7f800000)!=0x7f800000; }
int ts4l_is_pos_83111880(void){ return lbl_83530F2C>0; }
void ts4l_zero8_832A3AC8(u64 *p){ int i; if(p){ for(i=0;i<8;i++) p[i]=0; } }
int ts4l_tail_tag_83120520(void *p){ int r=0; if(p) r=ts4_if_tail_fn_83415CD0_8340D850(p,0x248e0000); return r; }
int ts4l_tail_or_err_8311E710(void *p){ int r=0x80070057; if(p) r=fn_83145338(p); return r; }
