/* Derived from zlib 1.1.4 (zlib license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family PNG2: trees.c of the second statically linked zlib copy (object auto_03_883022AC, /Os).
 * Huffman tree construction and block emission for deflate; non-DEBUG build, _tr_tally dead-stripped. */

#ifdef _MSC_VER
void *memcpy(void *destination, const void *source, unsigned int size);
#else
#include <string.h>
#endif

#define MAX_BITS 15
#define MAX_BL_BITS 7
#define LENGTH_CODES 29
#define LITERALS 256
#define L_CODES (LITERALS + 1 + LENGTH_CODES)
#define D_CODES 30
#define BL_CODES 19
#define HEAP_SIZE (2 * L_CODES + 1)
#define END_BLOCK 256
#define REP_3_6 16
#define REPZ_3_10 17
#define REPZ_11_138 18
#define MIN_MATCH 3
#define MAX_MATCH 258
#define STORED_BLOCK 0
#define STATIC_TREES 1
#define DYN_TREES 2
#define Z_BINARY 0
#define Z_ASCII 1
#define Z_UNKNOWN 2

typedef struct png2_ct_data {
    union {
        unsigned short freq; /* frequency count */
        unsigned short code; /* bit string */
    } fc;
    union {
        unsigned short dad; /* father node in Huffman tree */
        unsigned short len; /* length of bit string */
    } dl;
} png2_ct_data;

#define Freq fc.freq
#define Code fc.code
#define Dad dl.dad
#define Len dl.len

typedef struct static_tree_desc_s png2_static_tree_desc;

typedef struct png2_tree_desc {
    png2_ct_data *dyn_tree;          /* the dynamic tree */
    int max_code;                    /* largest code with non zero frequency */
    const png2_static_tree_desc *stat_desc; /* the corresponding static tree */
} png2_tree_desc;

typedef struct png2_deflate_state {
    void *strm;                      /* 0x00 */
    int status;                      /* 0x04 */
    unsigned char *pending_buf;      /* 0x08 */
    unsigned long pending_buf_size;  /* 0x0c */
    unsigned char *pending_out;      /* 0x10 */
    int pending;                     /* 0x14 */
    int noheader;                    /* 0x18 */
    unsigned char data_type;         /* 0x1c */
    unsigned char method;            /* 0x1d */
    int last_flush;                  /* 0x20 */
    unsigned int w_size;             /* 0x24 */
    unsigned int w_bits;             /* 0x28 */
    unsigned int w_mask;             /* 0x2c */
    unsigned char *window;           /* 0x30 */
    unsigned long window_size;       /* 0x34 */
    unsigned short *prev;            /* 0x38 */
    unsigned short *head;            /* 0x3c */
    unsigned int ins_h;              /* 0x40 */
    unsigned int hash_size;          /* 0x44 */
    unsigned int hash_bits;          /* 0x48 */
    unsigned int hash_mask;          /* 0x4c */
    unsigned int hash_shift;         /* 0x50 */
    long block_start;                /* 0x54 */
    unsigned int match_length;       /* 0x58 */
    unsigned int prev_match;         /* 0x5c */
    int match_available;             /* 0x60 */
    unsigned int strstart;           /* 0x64 */
    unsigned int match_start;        /* 0x68 */
    unsigned int lookahead;          /* 0x6c */
    unsigned int prev_length;        /* 0x70 */
    unsigned int max_chain_length;   /* 0x74 */
    unsigned int max_lazy_match;     /* 0x78 */
    int level;                       /* 0x7c */
    int strategy;                    /* 0x80 */
    unsigned int good_match;         /* 0x84 */
    int nice_match;                  /* 0x88 */
    png2_ct_data dyn_ltree[HEAP_SIZE];   /* 0x08c */
    png2_ct_data dyn_dtree[2 * D_CODES + 1]; /* 0x980 */
    png2_ct_data bl_tree[2 * BL_CODES + 1];  /* 0xa74 */
    png2_tree_desc l_desc;           /* 0xb10 */
    png2_tree_desc d_desc;           /* 0xb1c */
    png2_tree_desc bl_desc;          /* 0xb28 */
    unsigned short bl_count[MAX_BITS + 1]; /* 0xb34 */
    int heap[2 * L_CODES + 1];       /* 0xb54 */
    int heap_len;                    /* 0x1448 */
    int heap_max;                    /* 0x144c */
    unsigned char depth[2 * L_CODES + 1]; /* 0x1450 */
    unsigned char *l_buf;            /* 0x1690 */
    unsigned int lit_bufsize;        /* 0x1694 */
    unsigned int last_lit;           /* 0x1698 */
    unsigned short *d_buf;           /* 0x169c */
    unsigned long opt_len;           /* 0x16a0 */
    unsigned long static_len;        /* 0x16a4 */
    unsigned int matches;            /* 0x16a8 */
    int last_eob_len;                /* 0x16ac */
    unsigned short bi_buf;           /* 0x16b0 */
    int bi_valid;                    /* 0x16b4 */
} png2_deflate_state;

#define put_byte(s, c) {s->pending_buf[s->pending++] = (c);}
#define d_code(dist) \
   ((unsigned char)((dist) < 256 ? lbl_88027218[dist] : lbl_88027218[256+((dist)>>7)]))

/* Upstream tables (trees.c / trees.h). They are file statics of the original object, so the code reaches
 * several of them from one base register; the anchors the code uses carry the image addresses as names. */
static const int lbl_88026BD0[LENGTH_CODES] 
   = {0,0,0,0,0,0,0,0,1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,0};

static const int png2_extra_dbits[D_CODES] 
   = {0,0,0,0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,12,12,13,13};

static const int png2_extra_blbits[BL_CODES]
   = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,3,7};

static const unsigned char lbl_88026C44[BL_CODES]
   = {16,17,18,0,8,7,9,6,10,5,11,4,12,3,13,2,14,1,15};

#define Buf_size (8 * 2*sizeof(char))

#define DIST_CODE_LEN  512 

static const png2_ct_data png2_static_ltree[L_CODES+2] = {
{{ 12},{  8}}, {{140},{  8}}, {{ 76},{  8}}, {{204},{  8}}, {{ 44},{  8}},
{{172},{  8}}, {{108},{  8}}, {{236},{  8}}, {{ 28},{  8}}, {{156},{  8}},
{{ 92},{  8}}, {{220},{  8}}, {{ 60},{  8}}, {{188},{  8}}, {{124},{  8}},
{{252},{  8}}, {{  2},{  8}}, {{130},{  8}}, {{ 66},{  8}}, {{194},{  8}},
{{ 34},{  8}}, {{162},{  8}}, {{ 98},{  8}}, {{226},{  8}}, {{ 18},{  8}},
{{146},{  8}}, {{ 82},{  8}}, {{210},{  8}}, {{ 50},{  8}}, {{178},{  8}},
{{114},{  8}}, {{242},{  8}}, {{ 10},{  8}}, {{138},{  8}}, {{ 74},{  8}},
{{202},{  8}}, {{ 42},{  8}}, {{170},{  8}}, {{106},{  8}}, {{234},{  8}},
{{ 26},{  8}}, {{154},{  8}}, {{ 90},{  8}}, {{218},{  8}}, {{ 58},{  8}},
{{186},{  8}}, {{122},{  8}}, {{250},{  8}}, {{  6},{  8}}, {{134},{  8}},
{{ 70},{  8}}, {{198},{  8}}, {{ 38},{  8}}, {{166},{  8}}, {{102},{  8}},
{{230},{  8}}, {{ 22},{  8}}, {{150},{  8}}, {{ 86},{  8}}, {{214},{  8}},
{{ 54},{  8}}, {{182},{  8}}, {{118},{  8}}, {{246},{  8}}, {{ 14},{  8}},
{{142},{  8}}, {{ 78},{  8}}, {{206},{  8}}, {{ 46},{  8}}, {{174},{  8}},
{{110},{  8}}, {{238},{  8}}, {{ 30},{  8}}, {{158},{  8}}, {{ 94},{  8}},
{{222},{  8}}, {{ 62},{  8}}, {{190},{  8}}, {{126},{  8}}, {{254},{  8}},
{{  1},{  8}}, {{129},{  8}}, {{ 65},{  8}}, {{193},{  8}}, {{ 33},{  8}},
{{161},{  8}}, {{ 97},{  8}}, {{225},{  8}}, {{ 17},{  8}}, {{145},{  8}},
{{ 81},{  8}}, {{209},{  8}}, {{ 49},{  8}}, {{177},{  8}}, {{113},{  8}},
{{241},{  8}}, {{  9},{  8}}, {{137},{  8}}, {{ 73},{  8}}, {{201},{  8}},
{{ 41},{  8}}, {{169},{  8}}, {{105},{  8}}, {{233},{  8}}, {{ 25},{  8}},
{{153},{  8}}, {{ 89},{  8}}, {{217},{  8}}, {{ 57},{  8}}, {{185},{  8}},
{{121},{  8}}, {{249},{  8}}, {{  5},{  8}}, {{133},{  8}}, {{ 69},{  8}},
{{197},{  8}}, {{ 37},{  8}}, {{165},{  8}}, {{101},{  8}}, {{229},{  8}},
{{ 21},{  8}}, {{149},{  8}}, {{ 85},{  8}}, {{213},{  8}}, {{ 53},{  8}},
{{181},{  8}}, {{117},{  8}}, {{245},{  8}}, {{ 13},{  8}}, {{141},{  8}},
{{ 77},{  8}}, {{205},{  8}}, {{ 45},{  8}}, {{173},{  8}}, {{109},{  8}},
{{237},{  8}}, {{ 29},{  8}}, {{157},{  8}}, {{ 93},{  8}}, {{221},{  8}},
{{ 61},{  8}}, {{189},{  8}}, {{125},{  8}}, {{253},{  8}}, {{ 19},{  9}},
{{275},{  9}}, {{147},{  9}}, {{403},{  9}}, {{ 83},{  9}}, {{339},{  9}},
{{211},{  9}}, {{467},{  9}}, {{ 51},{  9}}, {{307},{  9}}, {{179},{  9}},
{{435},{  9}}, {{115},{  9}}, {{371},{  9}}, {{243},{  9}}, {{499},{  9}},
{{ 11},{  9}}, {{267},{  9}}, {{139},{  9}}, {{395},{  9}}, {{ 75},{  9}},
{{331},{  9}}, {{203},{  9}}, {{459},{  9}}, {{ 43},{  9}}, {{299},{  9}},
{{171},{  9}}, {{427},{  9}}, {{107},{  9}}, {{363},{  9}}, {{235},{  9}},
{{491},{  9}}, {{ 27},{  9}}, {{283},{  9}}, {{155},{  9}}, {{411},{  9}},
{{ 91},{  9}}, {{347},{  9}}, {{219},{  9}}, {{475},{  9}}, {{ 59},{  9}},
{{315},{  9}}, {{187},{  9}}, {{443},{  9}}, {{123},{  9}}, {{379},{  9}},
{{251},{  9}}, {{507},{  9}}, {{  7},{  9}}, {{263},{  9}}, {{135},{  9}},
{{391},{  9}}, {{ 71},{  9}}, {{327},{  9}}, {{199},{  9}}, {{455},{  9}},
{{ 39},{  9}}, {{295},{  9}}, {{167},{  9}}, {{423},{  9}}, {{103},{  9}},
{{359},{  9}}, {{231},{  9}}, {{487},{  9}}, {{ 23},{  9}}, {{279},{  9}},
{{151},{  9}}, {{407},{  9}}, {{ 87},{  9}}, {{343},{  9}}, {{215},{  9}},
{{471},{  9}}, {{ 55},{  9}}, {{311},{  9}}, {{183},{  9}}, {{439},{  9}},
{{119},{  9}}, {{375},{  9}}, {{247},{  9}}, {{503},{  9}}, {{ 15},{  9}},
{{271},{  9}}, {{143},{  9}}, {{399},{  9}}, {{ 79},{  9}}, {{335},{  9}},
{{207},{  9}}, {{463},{  9}}, {{ 47},{  9}}, {{303},{  9}}, {{175},{  9}},
{{431},{  9}}, {{111},{  9}}, {{367},{  9}}, {{239},{  9}}, {{495},{  9}},
{{ 31},{  9}}, {{287},{  9}}, {{159},{  9}}, {{415},{  9}}, {{ 95},{  9}},
{{351},{  9}}, {{223},{  9}}, {{479},{  9}}, {{ 63},{  9}}, {{319},{  9}},
{{191},{  9}}, {{447},{  9}}, {{127},{  9}}, {{383},{  9}}, {{255},{  9}},
{{511},{  9}}, {{  0},{  7}}, {{ 64},{  7}}, {{ 32},{  7}}, {{ 96},{  7}},
{{ 16},{  7}}, {{ 80},{  7}}, {{ 48},{  7}}, {{112},{  7}}, {{  8},{  7}},
{{ 72},{  7}}, {{ 40},{  7}}, {{104},{  7}}, {{ 24},{  7}}, {{ 88},{  7}},
{{ 56},{  7}}, {{120},{  7}}, {{  4},{  7}}, {{ 68},{  7}}, {{ 36},{  7}},
{{100},{  7}}, {{ 20},{  7}}, {{ 84},{  7}}, {{ 52},{  7}}, {{116},{  7}},
{{  3},{  8}}, {{131},{  8}}, {{ 67},{  8}}, {{195},{  8}}, {{ 35},{  8}},
{{163},{  8}}, {{ 99},{  8}}, {{227},{  8}}
};

static const png2_ct_data png2_static_dtree[D_CODES] = {
{{ 0},{ 5}}, {{16},{ 5}}, {{ 8},{ 5}}, {{24},{ 5}}, {{ 4},{ 5}},
{{20},{ 5}}, {{12},{ 5}}, {{28},{ 5}}, {{ 2},{ 5}}, {{18},{ 5}},
{{10},{ 5}}, {{26},{ 5}}, {{ 6},{ 5}}, {{22},{ 5}}, {{14},{ 5}},
{{30},{ 5}}, {{ 1},{ 5}}, {{17},{ 5}}, {{ 9},{ 5}}, {{25},{ 5}},
{{ 5},{ 5}}, {{21},{ 5}}, {{13},{ 5}}, {{29},{ 5}}, {{ 3},{ 5}},
{{19},{ 5}}, {{11},{ 5}}, {{27},{ 5}}, {{ 7},{ 5}}, {{23},{ 5}}
};

/* _dist_code and _length_code are globals of this object in zlib; they are declared extern here and their
 * 0x300 bytes are reserved so that base_length and base_dist keep their original offsets. */
static const unsigned char png2_dist_length_code_space[512 + 256] = {0};
extern const unsigned char lbl_88027218[DIST_CODE_LEN]; /* _dist_code */
extern const unsigned char lbl_88027418[MAX_MATCH-MIN_MATCH+1]; /* _length_code */

static const int png2_base_length[LENGTH_CODES] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 10, 12, 14, 16, 20, 24, 28, 32, 40, 48, 56,
64, 80, 96, 112, 128, 160, 192, 224, 0
};

static const int png2_base_dist[D_CODES] = {
    0,     1,     2,     3,     4,     6,     8,    12,    16,    24,
   32,    48,    64,    96,   128,   192,   256,   384,   512,   768,
 1024,  1536,  2048,  3072,  4096,  6144,  8192, 12288, 16384, 24576
};

struct static_tree_desc_s {
    const png2_ct_data *static_tree;  
    const int *extra_bits;      
    int     extra_base;          
    int     elems;               
    int     max_length;          
};

static const png2_static_tree_desc  png2_static_l_desc =
{png2_static_ltree, lbl_88026BD0, LITERALS+1, L_CODES, MAX_BITS};

static const png2_static_tree_desc  png2_static_d_desc =
{png2_static_dtree, png2_extra_dbits, 0,          D_CODES, MAX_BITS};

static const png2_static_tree_desc  lbl_88027630 =
{(const png2_ct_data *)0, png2_extra_blbits, 0,   BL_CODES, MAX_BL_BITS};

void png2_zlib_tr_init_883034B8(png2_deflate_state *s);
static void png2_zlib_init_block(png2_deflate_state *s);
static void png2_zlib_pqdownheap_88302430(png2_deflate_state *s, png2_ct_data *tree, int k);
static void png2_zlib_gen_bitlen_88302520(png2_deflate_state *s, png2_tree_desc *desc);
static void png2_zlib_gen_codes(png2_ct_data *tree, int max_code, unsigned short *bl_count);
static void png2_zlib_build_tree_88303558(png2_deflate_state *s, png2_tree_desc *desc);
static void png2_zlib_scan_tree_88302760(png2_deflate_state *s, png2_ct_data *tree, int max_code);
static void png2_zlib_send_tree_88302888(png2_deflate_state *s, png2_ct_data *tree, int max_code);
static int png2_zlib_build_bl_tree(png2_deflate_state *s);
static void png2_zlib_send_all_trees_88302DD8(png2_deflate_state *s, int lcodes, int dcodes, int blcodes);
void png2_zlib_tr_stored_block_88303828(png2_deflate_state *s, char *buf, unsigned long stored_len, int eof);
void png2_zlib_tr_align_883039B0(png2_deflate_state *s);
void png2_zlib_tr_flush_block_88303CE0(png2_deflate_state *s, char *buf, unsigned long stored_len, int eof);
static void png2_zlib_compress_block_88303088(png2_deflate_state *s, png2_ct_data *ltree, png2_ct_data *dtree);
static void png2_zlib_set_data_type(png2_deflate_state *s);
static unsigned png2_zlib_bi_reverse(unsigned code, int len);
static void png2_zlib_bi_flush(png2_deflate_state *s);
static void png2_zlib_bi_windup(png2_deflate_state *s);
static void png2_zlib_copy_block(png2_deflate_state *s, char    *buf, unsigned len, int header);

#  define send_code(s, c, tree) send_bits(s, tree[c].Code, tree[c].Len)

#define put_short(s, w) { \
    put_byte(s, (unsigned char)((w) & 0xff)); \
    put_byte(s, (unsigned char)((unsigned short)(w) >> 8)); \
}

#define send_bits(s, value, length) \
{ int len = length;\
  if (s->bi_valid > (int)Buf_size - len) {\
    int val = value;\
    s->bi_buf |= (val << s->bi_valid);\
    put_short(s, s->bi_buf);\
    s->bi_buf = (unsigned short)val >> (Buf_size - s->bi_valid);\
    s->bi_valid += len - Buf_size;\
  } else {\
    s->bi_buf |= (value) << s->bi_valid;\
    s->bi_valid += len;\
  }\
}

#define MAX(a,b) (a >= b ? a : b)

void png2_zlib_tr_init_883034B8(png2_deflate_state *s)
{

    s->l_desc.dyn_tree = s->dyn_ltree;
    s->l_desc.stat_desc = &png2_static_l_desc;

    s->d_desc.dyn_tree = s->dyn_dtree;
    s->d_desc.stat_desc = &png2_static_d_desc;

    s->bl_desc.dyn_tree = s->bl_tree;
    s->bl_desc.stat_desc = &lbl_88027630;

    s->bi_buf = 0;
    s->bi_valid = 0;
    s->last_eob_len = 8; 

    png2_zlib_init_block(s);
}

static void png2_zlib_init_block(png2_deflate_state *s)
{
    int n; 

    for (n = 0; n < L_CODES;  n++) s->dyn_ltree[n].Freq = 0;
    for (n = 0; n < D_CODES;  n++) s->dyn_dtree[n].Freq = 0;
    for (n = 0; n < BL_CODES; n++) s->bl_tree[n].Freq = 0;

    s->dyn_ltree[END_BLOCK].Freq = 1;
    s->opt_len = s->static_len = 0L;
    s->last_lit = s->matches = 0;
}

#define SMALLEST 1

#define pqremove(s, tree, top) \
{\
    top = s->heap[SMALLEST]; \
    s->heap[SMALLEST] = s->heap[s->heap_len--]; \
    png2_zlib_pqdownheap_88302430(s, tree, SMALLEST); \
}

#define smaller(tree, n, m, depth) \
   (tree[n].Freq < tree[m].Freq || \
   (tree[n].Freq == tree[m].Freq && depth[n] <= depth[m]))

static void png2_zlib_pqdownheap_88302430(png2_deflate_state *s, png2_ct_data *tree, int k)
{
    int v = s->heap[k];
    int j = k << 1;  
    while (j <= s->heap_len) {

        if (j < s->heap_len &&
            smaller(tree, s->heap[j+1], s->heap[j], s->depth)) {
            j++;
        }

        if (smaller(tree, v, s->heap[j], s->depth)) break;

        s->heap[k] = s->heap[j];  k = j;

        j <<= 1;
    }
    s->heap[k] = v;
}

static void png2_zlib_gen_bitlen_88302520(png2_deflate_state *s, png2_tree_desc *desc)
{
    png2_ct_data *tree        = desc->dyn_tree;
    int max_code         = desc->max_code;
    const png2_ct_data *stree = desc->stat_desc->static_tree;
    const int *extra    = desc->stat_desc->extra_bits;
    int base             = desc->stat_desc->extra_base;
    int max_length       = desc->stat_desc->max_length;
    int h;              
    int n, m;           
    int bits;           
    int xbits;          
    unsigned short f;              
    int overflow = 0;   

    for (bits = 0; bits <= MAX_BITS; bits++) s->bl_count[bits] = 0;

    tree[s->heap[s->heap_max]].Len = 0; 

    for (h = s->heap_max+1; h < HEAP_SIZE; h++) {
        n = s->heap[h];
        bits = tree[tree[n].Dad].Len + 1;
        if (bits > max_length) bits = max_length, overflow++;
        tree[n].Len = (unsigned short)bits;

        if (n > max_code) continue; 

        s->bl_count[bits]++;
        xbits = 0;
        if (n >= base) xbits = extra[n-base];
        f = tree[n].Freq;
        s->opt_len += (unsigned long)f * (bits + xbits);
        if (stree) s->static_len += (unsigned long)f * (stree[n].Len + xbits);
    }
    if (overflow == 0) return;

    do {
        bits = max_length-1;
        while (s->bl_count[bits] == 0) bits--;
        s->bl_count[bits]--;      
        s->bl_count[bits+1] += 2; 
        s->bl_count[max_length]--;

        overflow -= 2;
    } while (overflow > 0);

    for (bits = max_length; bits != 0; bits--) {
        n = s->bl_count[bits];
        while (n != 0) {
            m = s->heap[--h];
            if (m > max_code) continue;
            if (tree[m].Len != (unsigned) bits) {

                s->opt_len += ((long)bits - (long)tree[m].Len)
                              *(long)tree[m].Freq;
                tree[m].Len = (unsigned short)bits;
            }
            n--;
        }
    }
}

static void png2_zlib_gen_codes(png2_ct_data *tree, int max_code, unsigned short *bl_count)
{
    unsigned short next_code[MAX_BITS+1]; 
    unsigned short code = 0;              
    int bits;                  
    int n;                     

    for (bits = 1; bits <= MAX_BITS; bits++) {
        next_code[bits] = code = (code + bl_count[bits-1]) << 1;
    }

    for (n = 0;  n <= max_code; n++) {
        int len = tree[n].Len;
        if (len == 0) continue;

        tree[n].Code = png2_zlib_bi_reverse(next_code[len]++, len);

    }
}

static void png2_zlib_build_tree_88303558(png2_deflate_state *s, png2_tree_desc *desc)
{
    png2_ct_data *tree         = desc->dyn_tree;
    const png2_ct_data *stree  = desc->stat_desc->static_tree;
    int elems             = desc->stat_desc->elems;
    int n, m;          
    int max_code = -1; 
    int node;          

    s->heap_len = 0, s->heap_max = HEAP_SIZE;

    for (n = 0; n < elems; n++) {
        if (tree[n].Freq != 0) {
            s->heap[++(s->heap_len)] = max_code = n;
            s->depth[n] = 0;
        } else {
            tree[n].Len = 0;
        }
    }

    while (s->heap_len < 2) {
        node = s->heap[++(s->heap_len)] = (max_code < 2 ? ++max_code : 0);
        tree[node].Freq = 1;
        s->depth[node] = 0;
        s->opt_len--; if (stree) s->static_len -= stree[node].Len;

    }
    desc->max_code = max_code;

    for (n = s->heap_len/2; n >= 1; n--) png2_zlib_pqdownheap_88302430(s, tree, n);

    node = elems;              
    do {
        pqremove(s, tree, n);  
        m = s->heap[SMALLEST]; 

        s->heap[--(s->heap_max)] = n; 
        s->heap[--(s->heap_max)] = m;

        tree[node].Freq = tree[n].Freq + tree[m].Freq;
        {
            /* MAX(depth[n], depth[m]) + 1, written with explicit temporaries to match the original register use */
            unsigned char dm = s->depth[m], dn = s->depth[n], mx;
            if (dn >= dm) mx = dn; else mx = dm;
            s->depth[node] = (unsigned char)(mx + 1);
        }
        tree[n].Dad = tree[m].Dad = (unsigned short)node;

        s->heap[SMALLEST] = node++;
        png2_zlib_pqdownheap_88302430(s, tree, SMALLEST);

    } while (s->heap_len >= 2);

    s->heap[--(s->heap_max)] = s->heap[SMALLEST];

    png2_zlib_gen_bitlen_88302520(s, (png2_tree_desc *)desc);

    png2_zlib_gen_codes ((png2_ct_data *)tree, max_code, s->bl_count);
}

static void png2_zlib_scan_tree_88302760(png2_deflate_state *s, png2_ct_data *tree, int max_code)
{
    int n;                     
    int prevlen = -1;          
    int curlen;                
    int nextlen = tree[0].Len; 
    int count = 0;             
    int max_count = 7;         
    int min_count = 4;         

    if (nextlen == 0) max_count = 138, min_count = 3;
    tree[max_code+1].Len = (unsigned short)0xffff; 

    for (n = 0; n <= max_code; n++) {
        curlen = nextlen; nextlen = tree[n+1].Len;
        if (++count < max_count && curlen == nextlen) {
            continue;
        } else if (count < min_count) {
            s->bl_tree[curlen].Freq += count;
        } else if (curlen != 0) {
            if (curlen != prevlen) s->bl_tree[curlen].Freq++;
            s->bl_tree[REP_3_6].Freq++;
        } else if (count <= 10) {
            s->bl_tree[REPZ_3_10].Freq++;
        } else {
            s->bl_tree[REPZ_11_138].Freq++;
        }
        count = 0; prevlen = curlen;
        if (nextlen == 0) {
            max_count = 138, min_count = 3;
        } else if (curlen == nextlen) {
            max_count = 6, min_count = 3;
        } else {
            max_count = 7, min_count = 4;
        }
    }
}

static void png2_zlib_send_tree_88302888(png2_deflate_state *s, png2_ct_data *tree, int max_code)
{
    int n;                     
    int prevlen = -1;          
    int curlen;                
    int nextlen = tree[0].Len; 
    int count = 0;             
    int max_count = 7;         
    int min_count = 4;         

    if (nextlen == 0) max_count = 138, min_count = 3;

    for (n = 0; n <= max_code; n++) {
        curlen = nextlen; nextlen = tree[n+1].Len;
        if (++count < max_count && curlen == nextlen) {
            continue;
        } else if (count < min_count) {
            do { send_code(s, curlen, s->bl_tree); } while (--count != 0);

        } else if (curlen != 0) {
            if (curlen != prevlen) {
                send_code(s, curlen, s->bl_tree); count--;
            }

            send_code(s, REP_3_6, s->bl_tree); send_bits(s, count-3, 2);

        } else if (count <= 10) {
            send_code(s, REPZ_3_10, s->bl_tree); send_bits(s, count-3, 3);

        } else {
            send_code(s, REPZ_11_138, s->bl_tree); send_bits(s, count-11, 7);
        }
        count = 0; prevlen = curlen;
        if (nextlen == 0) {
            max_count = 138, min_count = 3;
        } else if (curlen == nextlen) {
            max_count = 6, min_count = 3;
        } else {
            max_count = 7, min_count = 4;
        }
    }
}

static int png2_zlib_build_bl_tree(png2_deflate_state *s)
{
    int max_blindex;  

    png2_zlib_scan_tree_88302760(s, (png2_ct_data *)s->dyn_ltree, s->l_desc.max_code);
    png2_zlib_scan_tree_88302760(s, (png2_ct_data *)s->dyn_dtree, s->d_desc.max_code);

    png2_zlib_build_tree_88303558(s, (png2_tree_desc *)(&(s->bl_desc)));

    for (max_blindex = BL_CODES-1; max_blindex >= 3; max_blindex--) {
        if (s->bl_tree[lbl_88026C44[max_blindex]].Len != 0) break;
    }

    s->opt_len += 3*(max_blindex+1) + 5+5+4;

    return max_blindex;
}

static void png2_zlib_send_all_trees_88302DD8(png2_deflate_state *s, int lcodes, int dcodes, int blcodes)
{
    int rank;                    

    send_bits(s, lcodes-257, 5); 
    send_bits(s, dcodes-1,   5);
    send_bits(s, blcodes-4,  4); 
    for (rank = 0; rank < blcodes; rank++) {

        send_bits(s, s->bl_tree[lbl_88026C44[rank]].Len, 3);
    }

    png2_zlib_send_tree_88302888(s, (png2_ct_data *)s->dyn_ltree, lcodes-1); 

    png2_zlib_send_tree_88302888(s, (png2_ct_data *)s->dyn_dtree, dcodes-1); 

}

void png2_zlib_tr_stored_block_88303828(png2_deflate_state *s, char *buf, unsigned long stored_len, int eof)
{
    send_bits(s, (STORED_BLOCK<<1)+eof, 3);  
    png2_zlib_copy_block(s, buf, (unsigned)stored_len, 1); 
}

void png2_zlib_tr_align_883039B0(png2_deflate_state *s)
{
    send_bits(s, STATIC_TREES<<1, 3);
    send_code(s, END_BLOCK, png2_static_ltree);
    png2_zlib_bi_flush(s);

    if (1 + s->last_eob_len + 10 - s->bi_valid < 9) {
        send_bits(s, STATIC_TREES<<1, 3);
        send_code(s, END_BLOCK, png2_static_ltree);
        png2_zlib_bi_flush(s);
    }
    s->last_eob_len = 7;
}

void png2_zlib_tr_flush_block_88303CE0(png2_deflate_state *s, char *buf, unsigned long stored_len, int eof)
{
    unsigned long opt_lenb, static_lenb; 
    int max_blindex = 0;  

    if (s->level > 0) {

	if (s->data_type == Z_UNKNOWN) png2_zlib_set_data_type(s);

	png2_zlib_build_tree_88303558(s, (png2_tree_desc *)(&(s->l_desc)));

	png2_zlib_build_tree_88303558(s, (png2_tree_desc *)(&(s->d_desc)));

	max_blindex = png2_zlib_build_bl_tree(s);

	opt_lenb = (s->opt_len+3+7)>>3;
	static_lenb = (s->static_len+3+7)>>3;

	if (static_lenb <= opt_lenb) opt_lenb = static_lenb;

    } else {

	opt_lenb = static_lenb = stored_len + 5; 
    }

    if (stored_len+4 <= opt_lenb && buf != (char*)0) {

        png2_zlib_tr_stored_block_88303828(s, buf, stored_len, eof);

    } else if (static_lenb == opt_lenb) {
        send_bits(s, (STATIC_TREES<<1)+eof, 3);
        png2_zlib_compress_block_88303088(s, (png2_ct_data *)png2_static_ltree, (png2_ct_data *)png2_static_dtree);
    } else {
        send_bits(s, (DYN_TREES<<1)+eof, 3);
        png2_zlib_send_all_trees_88302DD8(s, s->l_desc.max_code+1, s->d_desc.max_code+1,
                       max_blindex+1);
        png2_zlib_compress_block_88303088(s, (png2_ct_data *)s->dyn_ltree, (png2_ct_data *)s->dyn_dtree);
    }

    png2_zlib_init_block(s);

    if (eof) {
        png2_zlib_bi_windup(s);
    }

}

static void png2_zlib_compress_block_88303088(png2_deflate_state *s, png2_ct_data *ltree, png2_ct_data *dtree)
{
    unsigned dist;      
    int lc;             
    unsigned lx = 0;    
    unsigned code;      
    int extra;          

    if (s->last_lit != 0) do {
        dist = s->d_buf[lx];
        lc = s->l_buf[lx++];
        if (dist == 0) {
            send_code(s, lc, ltree); 

        } else {

            code = lbl_88027418[lc];
            send_code(s, code+LITERALS+1, ltree); 
            extra = lbl_88026BD0[code];
            if (extra != 0) {
                lc -= png2_base_length[code];
                send_bits(s, lc, extra);       
            }
            dist--; 
            code = d_code(dist);

            send_code(s, code, dtree);       
            extra = png2_extra_dbits[code];
            if (extra != 0) {
                dist -= png2_base_dist[code];
                send_bits(s, dist, extra);   
            }
        } 

    } while (lx < s->last_lit);

    send_code(s, END_BLOCK, ltree);
    s->last_eob_len = ltree[END_BLOCK].Len;
}

static void png2_zlib_set_data_type(png2_deflate_state *s)
{
    int n = 0;
    unsigned ascii_freq = 0;
    unsigned bin_freq = 0;
    while (n < 7)        bin_freq += s->dyn_ltree[n++].Freq;
    while (n < 128)    ascii_freq += s->dyn_ltree[n++].Freq;
    while (n < LITERALS) bin_freq += s->dyn_ltree[n++].Freq;
    s->data_type = (unsigned char)(bin_freq > (ascii_freq >> 2) ? Z_BINARY : Z_ASCII);
}

static unsigned png2_zlib_bi_reverse(unsigned code, int len)
{
    register unsigned res = 0;
    do {
        res |= code & 1;
        code >>= 1, res <<= 1;
    } while (--len > 0);
    return res >> 1;
}

static void png2_zlib_bi_flush(png2_deflate_state *s)
{
    if (s->bi_valid == 16) {
        put_short(s, s->bi_buf);
        s->bi_buf = 0;
        s->bi_valid = 0;
    } else if (s->bi_valid >= 8) {
        put_byte(s, (unsigned char)s->bi_buf);
        s->bi_buf >>= 8;
        s->bi_valid -= 8;
    }
}

static void png2_zlib_bi_windup(png2_deflate_state *s)
{
    if (s->bi_valid > 8) {
        put_short(s, s->bi_buf);
    } else if (s->bi_valid > 0) {
        put_byte(s, (unsigned char)s->bi_buf);
    }
    s->bi_buf = 0;
    s->bi_valid = 0;
}

static void png2_zlib_copy_block(png2_deflate_state *s, char    *buf, unsigned len, int header)
{
    png2_zlib_bi_windup(s);        
    s->last_eob_len = 8; 

    if (header) {
        put_short(s, (unsigned short)len);   
        put_short(s, (unsigned short)~len);
    }
    while (len--) {
        put_byte(s, *buf++);
    }
}
