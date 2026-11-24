/* Loader_DLL.xex 0x83218C50-0x8344C6B0, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned long long u64;
extern void fn_8340D830(void *p, u32 tag);
int ts4l_cmp_u32_83218C50(u32 a,u32 b){ if(a<b) return -1; return a>b; }
int ts4l_has_either_8321A8C8(char *p){ if(*(u32*)(p+8)==0){ if(*(u32*)(p+4)!=0) return 1; } return 0; }
u32 ts4l_next_pow2_8321A888(u32 n){ u32 r=1; if(n>1){ do{ r<<=1; }while(r<n); } return r; }
u32 ts4l_log2_8318BB40(u32 n){ u32 r=0; if(n>1){ do{ r++; }while((n>>r)>1); } return r; }
void ts4l_free_aligned_831BB398(u8 *p){ if(p) fn_8340D830(p-p[-1],0x248c8000); }
void ts4l_free_aligned_832523C8(u8 *p){ if(p) fn_8340D830(p-p[-1],0x248c8000); }
void ts4l_free_tag_pair_8344C6B0(void *a,void *b){ if(a && b) fn_8340D830(b,0x24810000); }
int ts4l_add_cursor_83225740(char *p,u64 a){ *(u32*)(p+0x34)+=(u32)a; return 0; }
int ts4l_set_flag_83233DB0(char *p,short i){ ((u32*)p)[i+0x17f]=1; return 0; }
u32 ts4l_log2_8323A5F8(u32 n){ u32 r=0; if(n>1){ do{ r++; }while((n>>r)>1); } return r; }
