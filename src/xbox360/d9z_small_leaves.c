/* Swing_DLL.xex 0x88213AA0-0x88879150, executable version 0.0.0.3. */
/* Small leaf accessors, bounds helpers and function-pointer-table thunks. */

typedef struct ts4_hdr_88213AA0 { int first; int idx; } ts4_hdr_88213AA0;
typedef struct ts4_e8 { float f; float g; } ts4_e8;
typedef struct ts4_e16 { float f; float g[3]; } ts4_e16;
typedef struct ts4_e32 { float f; float g[7]; } ts4_e32;
typedef struct ts4_o8 { char p0[0x40]; float key; char p1[8]; ts4_e8 *e; int n; } ts4_o8;
typedef struct ts4_o16 { char p0[0x40]; float key; char p1[8]; ts4_e16 *e; int n; } ts4_o16;
typedef struct ts4_o32 { char p0[0x40]; float key; char p1[8]; ts4_e32 *e; int n; } ts4_o32;
typedef int (*ts4_cb0)(void);
typedef int (*ts4_cb2)(int, int);
extern void *lbl_88D2E270[];

typedef struct ts4_range_88879150 { char p[0x28]; int *b; int *e; } ts4_range_88879150;
int ts4_count_words_88879150(ts4_range_88879150 *o) { return o->e - o->b; }
