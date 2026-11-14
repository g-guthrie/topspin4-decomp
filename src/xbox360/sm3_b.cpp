/* SM3 batch B: small C++-compiled helpers (bool returns, delete thunks, stack-spilled args). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

struct ts4_sm3_e4 { int a, b, c, d; };
struct ts4_sm3_bits_ent { u32 a : 13; u32 b : 3; u32 c : 3; u32 d : 3; u32 e : 10; char pad[0x14]; };

struct ts4_sm3_bits_ent2 { u32 p0 : 7; u32 x : 2; u32 q0 : 23; u32 a : 5; u32 b : 5; u32 q1 : 22; u32 q2 : 27; u32 c : 2; u32 d : 1; u32 q3 : 2; char pad[12]; };

struct ts4_sm3_slot { char pad[0x168]; u8 f168; char p2[3]; float f16c; char p3[0x19c - 0x170]; };

struct ts4_sm3_vobj2 { virtual ~ts4_sm3_vobj2(); };

extern "C" {
extern char *lbl_88D45930;
extern char *lbl_88D45B1C;
extern u32 lbl_88C6BFF8, lbl_88C6BFF4;
extern char lbl_88C6C050[], lbl_88D48820[], lbl_88C6C058[], lbl_88D48848[], lbl_880D6B70[];
extern void fn_887561A8(void *, int);
extern struct ts4_sm3_slot lbl_88D45CC0[];
extern void fn_8890DB90(void *, void *, int);
extern void *g_ts4_title_server;
extern void ts4_if_call_seq_fn_889B5A30_889B5BE0(void *);
extern void ts4_destroy_owned_object(void *);
extern char lbl_880D75FC[], lbl_880D7604[], lbl_880EFD04[];
extern void fn_888B2CE8(float);
extern void fn_888B2838(float);
extern void fn_888B2AB0(float);
extern void fn_888B24E8(float);
extern void fn_888BB5A8(void *, int, int);
extern void *lbl_88D45960;
extern void fn_888E8A80(void *, void *);
extern void fn_889254C8(void *, int);
extern void ts4_report_component_event(void *, int, u32, float);
extern char *lbl_88D41FC4;
extern char *lbl_88D45A60;
extern char lbl_88C6B728[];
extern char lbl_88C6C948[];
extern char lbl_880F3388[];
extern void *lbl_88D45B38;
extern void ts4_if_call_seq_fn_881F04B8_886131F0(void *, void *, u32);
extern void fn_885651F8(void *);
extern char *lbl_88D45908;
extern void *lbl_88D45A70, *lbl_88D45AD8;
extern void fn_887036B0(void *, void *, u64);
extern void fn_88731AF0(void *, void *, u64);
extern void fn_8874AAB0(void *, void *, u64);
extern void *lbl_88D45AC8, *lbl_88D45AC4, *lbl_88D45AB4, *lbl_88D45AB0;
extern void fn_88933B20(void *, int, void *);
extern void fn_8893DB88(void *, void *);
extern void fn_8893D788(void *, void *, void *);
extern int fn_889A0478(void *);
extern void *g_ts4_session_context;
extern void *fn_881AC7D0(void *, u32 *);
extern void *ts4_find_record_by_key_881AC778(void *, u32 *);
extern void *ts4_find_record_by_key_88187800(void *, u32 *);
extern char *lbl_88D45888;
extern u32 lbl_88D458AC, lbl_88D458B0;
extern void *fn_88923238(void *, int, u32, u32);
extern void fn_88563470(void *);
extern char ts4_noop_88AFF300[], ts4_noop_88AFF308[];
extern char lbl_88D488B8[], lbl_88D48A98[];
extern double floor(float);
extern float lbl_8814B910;
extern float lbl_8814B440;
extern void *ts4_if_call_seq_u32_off0_8819B0C8(void *, void *);
extern void *fn_88213CC8(void *, void *);
extern void *ts4_find_record_by_key_881AD100(void *, u32 *);
extern void *ts4_find_record_by_key_881AD0A8(void *, u32 *);
extern void fn_88865388(void *, int, int, u8 *);
extern char *lbl_88D459DC;
extern void *fn_888B1AE0(void *);
extern void *ts4_loop_call_seq_fn_88563230_88884B20(void *, int, void *, int);
extern void ts4_resume_thread(void *);
extern char lbl_880D9334[], lbl_880D9354[];
extern void fn_888BFC20(void);
extern void fn_889055A0(void);
extern int ts4_format_text(void *, int, void *, int);
extern char lbl_880D1B40[];
extern void *ts4_if_call_seq_u32_off0_886F7B38(void *, int, u64);
extern void ts4_byte_string_assign_88158908(void *);
extern float g_ts4_script_constants[];
extern void fn_88652CC0(void *, float *);
extern char *lbl_88D45940;
extern void *lbl_88D45A0C;
extern void *ts4_find_record_by_key_881ACFC8(void *, u32 *);
extern void fn_887DD110(void *, u32, u8, u32);
extern void fn_888368B0(void *, int, void *);
extern void fn_887FEA98(void *, int, int, u64);
extern void fn_88947E40(void *, u64, int);
extern u32 ts4_get_u32__imp_KeTimeStampBundle_8857B830(void);
extern float fn_88771618(void *, int);
extern int ts4_obj_sub_vcall_count_887E9778(void *);
extern int fn_88996860(void);

/* 0x887CF258: bounds-checked (0..3) pointer slot at +8; returns byte field +0x28 of the slot. */
char *ts4_slot_byte_field28_887CF258(char *self, int i)
{
    if (i < 0 || i > 3) return 0;
    char *p = *(char **)(self + (i + 2) * 4);
    if (p) return (char *)(u32)*(u8 *)(p + 0x28);
    return 0;
}

/* 0x8883EBF8: find record by key in the table at field +0x28 (+0x30). */
void *ts4_find_record_by_key_field28_8883EBF8(char *self, u32 key)
{
    return ts4_find_record_by_key_881ACFC8(*(char **)(self + 0x28) + 0x30, &key);
}

/* 0x887DF088: store byte flag at +0x34, then call helper with a stack temp. */
struct ts4_sm3_tmp16 { char b[16]; };
void ts4_set_flag_and_call_887DF088(char *self, u8 a, u32 b)
{
    ts4_sm3_tmp16 t;
    self[0x34] = a;
    fn_887DD110(&t, *(u32 *)(self + 0x24), a, b);
}

/* 0x888373F8: build a {tag=1, value=(u8)c} record on the stack and pass it on. */
struct ts4_sm3_tagval { int tag; int pad; int val; };
void ts4_call_with_tagged_byte_888373F8(void *self, int b, u8 c)
{
    ts4_sm3_tagval t;
    t.tag = 1;
    t.val = c;
    fn_888368B0(self, b, &t);
}

/* 0x887FEC60: forward the high word of a 64-bit argument (low word cleared). */
void ts4_forward_high_word_887FEC60(char *self, int b, int c, u64 a)
{
    fn_887FEA98(*(void **)(self + 0x20), b, c, (u64)*(u32 *)&a << 32);
}

/* 0x8894D698: same high-word forwarding with a trailing 0. */
void ts4_forward_high_word_zero_8894D698(void *self, u64 a)
{
    fn_88947E40(self, (u64)*(u32 *)&a << 32, 0);
}

/* 0x889311A8: store the low 16 bits of the kernel time stamp. */
void ts4_store_timestamp_u16_889311A8(u16 *p)
{
    *p = (u16)ts4_get_u32__imp_KeTimeStampBundle_8857B830();
}

/* 0x88771A80: self.f8 = helper(self, self.fC) (float result). */
void ts4_update_float_f8_88771A80(char *self)
{
    *(float *)(self + 8) = fn_88771618(self, *(int *)(self + 0xc));
}

/* 0x8877C318: true when helper on the global object returns a positive value. */
bool ts4_global_helper_positive_8877C318(void)
{
    return ts4_obj_sub_vcall_count_887E9778(lbl_88D45A0C) > 0;
}

/* 0x8899DCB8: -1 if helper returned -1, else 0. */
int ts4_helper_is_minus1_mask_8899DCB8(void)
{
    int r = fn_88996860() + 1;
    return r ? 0 : -1;
}
/* Linear searches / fills over [begin,end) ranges stored in the object. */
/* 0x88864F90: find element (stride 0xC) whose first word equals key; end if absent. */
char *ts4_find_by_word0_stride12_88864F90(char *self, u32 k)
{
    char *p = *(char **)(self + 0x84);
    char *e = *(char **)(self + 0x88);
    if (p == e) return p;
    do {
        if (k == *(u32 *)p) return p;
        p += 0xc;
    } while (p != e);
    return p;
}

/* 0x88778EF8: clear byte +0x3C in each 0x40-byte element of the range at +0xB8. */
void ts4_clear_flag3c_in_range_88778EF8(char *self)
{
    char *e = *(char **)(self + 0xbc);
    char *p = *(char **)(self + 0xb8);
    if (p == e) return;
    do {
        p[0x3c] = 0;
        p += 0x40;
    } while (p != e);
}

/* 0x8890D798: zero each word of the range at +0x14. */
void ts4_zero_word_range_8890D798(char *self)
{
    u32 *e = *(u32 **)(self + 0x18);
    u32 *p = *(u32 **)(self + 0x14);
    if (p == e) return;
    do {
        *p = 0;
        p++;
    } while (p != e);
}

/* 0x888C7200: set byte +8 of every object pointed to by the pointer range at +0x6C. */
void ts4_set_byte8_on_ptr_range_888C7200(char *self, u8 v)
{
    char **e = *(char ***)(self + 0x70);
    char **p = *(char ***)(self + 0x6c);
    if (e == p) return;
    do {
        (*p)[8] = v;
        p++;
    } while (p != e);
}
/* 0x888C1A88: true when both ranges (+0xC..+0x10 and +0x18..+0x1C) are non-empty. */
u8 ts4_both_ranges_nonempty_888C1A88(char *self)
{
    return (*(u32 *)(self + 0xc) != *(u32 *)(self + 0x10) && *(u32 *)(self + 0x18) != *(u32 *)(self + 0x1c)) ? 1 : 0;
}

/* 0x888C4218: true when flag byte +0x9A == 1 and a lies in (field0xC, field0x8]. */
int ts4_value_in_open_interval_888C4218(char *self, int a)
{
    if (self[0x9a] == 1 && *(int *)(self + 0xc) < a && *(int *)(self + 8) >= a) return 1;
    return 0;
}

/* 0x888C4248: copy a 3-float vector into slot i (stride 12) of the array at +0x94. */
void ts4_set_vec3_slot_888C4248(char *self, int i, float *src)
{
    float *d = (float *)(*(char **)(self + 0x94) + i * 12);
    d[0] = src[0];
    d[1] = src[1];
    d[2] = src[2];
}

/* 0x887E9DF0: zero the first word of records [a, b) (stride 20) of the table at +0x30. */
void ts4_zero_record_heads_887E9DF0(char *self, u32 a, u32 b)
{
    u32 i;
    for (i = a; i < b; i++) *(int *)(*(char **)(self + 0x30) + i * 5 * 4) = 0;
}

/* Virtual-destructor delete thunks: if (obj) delete obj (scalar deleting dtor, flag 1).
   The object is the second argument (first is an ignored this) or the first argument. */
struct ts4_sm3_vobj { virtual ~ts4_sm3_vobj(); };
#define TS4_DELETE_ARG2(NAME) void NAME(void *, ts4_sm3_vobj *p) { delete p; }
#define TS4_DELETE_ARG1(NAME) void NAME(ts4_sm3_vobj *p) { delete p; }
TS4_DELETE_ARG2(ts4_delete_object_arg2_88931630)
TS4_DELETE_ARG2(ts4_delete_object_arg2_88931658)
TS4_DELETE_ARG2(ts4_delete_object_arg2_88994BF0)
TS4_DELETE_ARG2(ts4_delete_object_arg2_88995180)
TS4_DELETE_ARG2(ts4_delete_object_arg2_889951A8)
TS4_DELETE_ARG2(ts4_delete_object_arg2_889951D0)
TS4_DELETE_ARG2(ts4_delete_object_arg2_889951F8)
TS4_DELETE_ARG2(ts4_delete_object_arg2_88995220)
TS4_DELETE_ARG2(ts4_delete_object_arg2_8899C3B8)
TS4_DELETE_ARG2(ts4_delete_object_arg2_8899C3E0)
TS4_DELETE_ARG2(ts4_delete_object_arg2_8899C408)
TS4_DELETE_ARG2(ts4_delete_object_arg2_8899C430)
TS4_DELETE_ARG1(ts4_delete_object_arg1_887E9398)
TS4_DELETE_ARG1(ts4_delete_object_arg1_887E9640)
/* 0x887CDC08: find object pointer in vector (+0x48..+0x4C) whose first word equals key */
char *ts4_find_obj_by_word0_a_887CDC08(char *self, u32 k) { char *p = *(char **)(self + 72); char *e = *(char **)(self + 76); if (p == e) return 0; do { char *o = *(char **)p; if (*(u32 *)o == k) return o; p += 4; } while (p != e); return 0; }

/* 0x88933138: find object pointer in vector (+0x18..+0x1C) whose field +0x14 equals key */
char *ts4_find_obj_by_field14_88933138(char *self, u32 k) { char *e = *(char **)(self + 28); char *p = *(char **)(self + 24); if (p == e) return 0; do { char *o = *(char **)p; if (*(u32 *)(o + 0x14) == k) return o; p += 4; } while (p != e); return 0; }

/* 0x88838948: find object pointer in vector (+0x20..+0x24) whose field +0x184 equals key (signed) */
char *ts4_find_obj_by_field184_signed_88838948(char *self, int k) { char *e = *(char **)(self + 36); char *p = *(char **)(self + 32); if (p == e) return 0; do { char *o = *(char **)p; if (*(int *)(o + 0x184) == (int)k) return o; p += 4; } while (p != e); return 0; }

/* 0x88933068: first object pointer in vector (+0x18..+0x1C) with nonzero byte +0x2C */
char *ts4_find_obj_with_flag2c_88933068(char *self) { char *e = *(char **)(self + 28); char *p = *(char **)(self + 24); if (p == e) return 0; do { char *o = *(char **)p; if (*(u8 *)(o + 0x2c) != 0) return o; p += 4; } while (p != e); return 0; }

/* 0x88933E88: first object pointer in vector (+0..+4) whose field +0x28 is zero */
char *ts4_find_obj_with_zero_field28_88933E88(char *self) { char *e = *(char **)(self + 4); char *p = *(char **)(self + 0); if (p == e) return 0; do { char *o = *(char **)p; if (*(u32 *)(o + 0x28) == 0) return o; p += 4; } while (p != e); return 0; }

/* 0x88864FC0: find element (stride 0x3C) with word +8 equal to key */
char *ts4_find_by_word2_stride60_88864FC0(char *self, u32 k) { char *p = *(char **)(self + 120); char *e = *(char **)(self + 124); if (p == e) return p; do { if (*(u32 *)(p + 8) == k) return p; p += 60; } while (p != e); return p; }

/* 0x88865358: find element (stride 8) with word 0 equal to key */
char *ts4_find_by_word0_stride8_88865358(char *self, u32 k) { char *p = *(char **)(self + 108); char *e = *(char **)(self + 112); if (p == e) return p; do { if (*(u32 *)(p + 0) == k) return p; p += 8; } while (p != e); return p; }

/* 0x88933EC0: find object pointer in vector (+0..+4) whose field +4 equals key (signed) */
char *ts4_find_obj_by_field4_signed_88933EC0(char *self, int k) { char *e = *(char **)(self + 4); char *p = *(char **)(self + 0); if (p == e) return 0; do { char *o = *(char **)p; if (k == *(int *)(o + 4)) return o; p += 4; } while (p != e); return 0; }

/* 0x88718668: fill a 3-float vector with script constant 0 and pass it on */
void ts4_call_with_splat_const0_88718668(void *self) { float t[3]; t[0] = g_ts4_script_constants[0]; t[1] = g_ts4_script_constants[0]; t[2] = g_ts4_script_constants[0]; fn_88652CC0(self, t); }

/* 0x887788B8: set byte +0x8A in each 0x98-byte record (count at +0x1C4) */
void ts4_set_byte_8a_in_all_records_887788B8(char *self, u8 v) { u32 i; for (i = 0; i < *(u32 *)(self + 0x1c4); i++) *(u8 *)(*(char **)(self + 0xa4) + i * 0x98 + 0x8a) = v; }

/* 0x88864FF0: true if an element (stride 8) of the range at +0xA0 has word0 == key */
int ts4_contains_word0_stride8_88864FF0(char *self, u32 k) { char *p = *(char **)(self + 160); char *e = *(char **)(self + 164); if (p == e) return 0; do { if (k == *(u32 *)(p + 0)) return 1; p += 8; } while (p != e); return 0; }

/* 0x888652A0: true if an element (stride 0x5C) of the range at +0x5C has word +0x3C == key */
int ts4_contains_word15_stride92_888652A0(char *self, u32 k) { char *p = *(char **)(self + 92); char *e = *(char **)(self + 96); if (p == e) return 0; do { if (*(u32 *)(p + 60) == k) return 1; p += 92; } while (p != e); return 0; }

/* 0x887CF560: true if every element (stride 0x14) of the range at +0x10 has nonzero byte +0x10 */
int ts4_all_flags10_set_887CF560(char *self) { char *p = *(char **)(self + 0x10); char *e = *(char **)(self + 0x14); if (p == e) return 1; do { if (*(u8 *)(p + 0x10) == 0) return 0; p += 0x14; } while (p != e); return 1; }

/* 0x887CE918: find object pointer in vector (+0x380..+0x384) whose field +4 equals *key */
char *ts4_find_obj_by_field4_via_ptr_887CE918(char *self, u32 *k) { char *p = *(char **)(self + 0x380); char *e = *(char **)(self + 0x384); u32 kk; if (p == e) return 0; kk = *k; do { char *o = *(char **)p; if (*(u32 *)(o + 4) == kk) return o; p += 4; } while (p != e); return 0; }

/* 0x887CF528: find element (stride 0x14) of the range at +0x10 whose word +4 equals *key */
char *ts4_find_by_word1_via_ptr_stride20_887CF528(char *self, u32 *k) { char *p = *(char **)(self + 0x10); char *e = *(char **)(self + 0x14); if (p == e) return 0; do { if (*k == *(u32 *)(p + 4)) return p; p += 0x14; } while (p != e); return 0; }

/* 0x888BFD00: fill the int array at +0x40 (count at +0x44) with -1 */
void ts4_fill_minus1_words_888BFD00(char *self) { int i = 0; if (*(int *)(self + 0x44) <= 0) return; do { *(int *)(*(char **)(self + 0x40) + i * 4) = -1; i++; } while (i < *(int *)(self + 0x44)); }

/* 0x888C4690: true if word0 and word10 are set and field +4 differs from field +8 */
u8 ts4_object_has_range_gap_888C4690(char *self) { return (*(u32 *)self != 0 && *(int *)(self + 0x10) != 0 && *(u32 *)(self + 4) != *(u32 *)(self + 8)) ? 1 : 0; }

/* 0x888AE0C0: if object (+8) set, store f1 or f2 (by byte +0x7C) at +0x30 and mark +0x37 */
void ts4_set_float30_choose_by_flag_888AE0C0(char *self, float a, float b) { if (*(int *)(self + 8) == 0) return; if (self[0x7c]) { *(float *)(self + 0x30) = b; } else { *(float *)(self + 0x30) = a; } self[0x37] = 1; }

/* 0x887793F0: true if an element (stride 0x10) of the range at +0x1EC has word0 == key */
int ts4_contains_word0_stride16_887793F0(char *self, u32 k) { char *e = *(char **)(self + 496); char *p = *(char **)(self + 492); if (e == p) return 0; do { if (*(u32 *)(p + 0) == k) return 1; p += 16; } while (e != p); return 0; }

/* 0x887815B0: find 8-byte entry whose word0 == *key in the range at +0xAC; call helper with entry+4 */
void *ts4_find_pair_by_key_then_call_887815B0(char *self, u32 *k, void *a5) { char *e = *(char **)(self + 0xb0); char *p = *(char **)(self + 0xac); if (e == p) return self; do { if (*(u32 *)p == *k) return ts4_if_call_seq_u32_off0_8819B0C8(a5, p + 4); p += 8; } while (e != p); return self; }

/* 0x887E9D38: true if any object pointer in the range at +0x4C has nonzero field +0xC */
int ts4_any_obj_field_c_set_887E9D38(char *self) { char *p = *(char **)(self + 0x4c); char *e = *(char **)(self + 0x50); if (p == e) return 0; do { if (*(u32 *)(*(char **)p + 0xc) != 0) return 1; p += 4; } while (p != e); return 0; }

/* 0x88865648: call helper on global with flag 1, index -1 and a zeroed stack byte */
void ts4_call_with_zero_byte_and_minus1_88865648(void) { u8 t = 0; fn_88865388(lbl_88D459DC, 1, -1, &t); }

/* 0x888656C8: call helper on global with flag 1, index a and a zeroed stack byte */
void ts4_call_with_zero_byte_and_arg_888656C8(int a) { u8 t = 0; fn_88865388(lbl_88D459DC, 1, a, &t); }

/* 0x888C2290: create thread running fn_888BFC20 (stack 0x20000) and resume it */
void ts4_spawn_and_resume_thread_888C2290(void) { ts4_resume_thread(ts4_loop_call_seq_fn_88563230_88884B20((void *)fn_888BFC20, 0, lbl_880D9334, 0x20000)); }

/* 0x889058D0: create thread running fn_889055A0 with the given argument and resume it */
void ts4_spawn_and_resume_thread_889058D0(int a) { ts4_resume_thread(ts4_loop_call_seq_fn_88563230_88884B20((void *)fn_889055A0, a, lbl_880D9354, 0x20000)); }

/* 0x888C4278: copy 3 floats from the pointer at +0xCC+i*4 into slot i (stride 12) of the array at +0xA0 */
void ts4_copy_vec3_from_ptr_slot_888C4278(char *self, int i) { float *d = (float *)(*(char **)(self + 0xa0) + i * 12); float *s = *(float **)(self + (i + 0x33) * 4); d[0] = s[0]; d[1] = s[1]; d[2] = s[2]; }

/* 0x88912298: true if an element (stride 0x28) of the range at +8 has word0 == *key */
int ts4_contains_word0_via_ptr_stride40_88912298(char *self, u32 *k) { char *e = *(char **)(self + 0xc); char *p = *(char **)(self + 8); if (p == e) return 0; do { if (*k == *(u32 *)p) return 1; p += 0x28; } while (p != e); return 0; }

/* 0x889329C0: true when state==2, bytes +0x26 and +0x27 set and byte +0x24 clear */
int ts4_state2_flags_26_27_clear24_889329C0(char *self) { if (*(int *)(self + 0x14) == 2 && self[0x26] != 0 && self[0x27] != 0 && self[0x24] == 0) return 1; return 0; }

/* 0x88932A00: true when bytes +0x26,+0x27,+0x24,+0x25 are all nonzero */
int ts4_four_flags_all_set_88932A00(char *self) { if (self[0x26] != 0 && self[0x27] != 0 && self[0x24] != 0 && self[0x25] != 0) return 1; return 0; }

/* 0x8898EE30: init sub-object at +0x10, then store 0x30 into byte +5 of the object it points to */
void ts4_init_sub_and_set_byte5_8898EE30(char *self) { ts4_byte_string_assign_88158908(self + 0x10); (*(char **)(self + 0x10))[5] = 0x30; }

/* 0x88778878: clear byte +0x65 in each 0x98-byte record (count at +0x1C4) */
void ts4_clear_byte_65_in_all_records_88778878(char *self) { u32 i; for (i = 0; i < *(u32 *)(self + 0x1c4); i++) { char *b = *(char **)(self + 0xa4); u32 o = i * 0x98; b[o + 0x65] = 0; } }

/* 0x88796118: find 16-byte entry in the range at +0x1EC with word0 == key; call helper(range base, entry) */
void *ts4_find_entry_by_word0_then_call_88796118(char *self, u32 k) { char *v = self + 0x1ec; char *e = *(char **)(self + 0x1f0); char *p = *(char **)v; if (e == p) return v; do { if (k == *(u32 *)p) return fn_88213CC8(v, p); p += 0x10; } while (e != p); return v; }

/* 0x8899DD78: if both objects have word +0x80, compare word +0x84 (this greater); else whether this one has it */
bool ts4_pair_greater_8899DD78(char *a, char *b) { if (*(u32 *)(a + 0x80) != 0 && *(u32 *)(b + 0x80) != 0) return *(u32 *)(b + 0x84) < *(u32 *)(a + 0x84); return *(u32 *)(a + 0x80) != 0; }

/* 0x8899DA60: if both objects have word +0xC0, compare word +0xC4 (this greater); else whether this one has it */
bool ts4_pair_greater_8899DA60(char *a, char *b) { if (*(u32 *)(a + 0xc0) != 0 && *(u32 *)(b + 0xc0) != 0) return *(u32 *)(b + 0xc4) < *(u32 *)(a + 0xc4); return *(u32 *)(a + 0xc0) != 0; }

/* 0x8890C870: set 3-bit field b (bits 13..15) of entry i+0x30 (stride 0x18) and set the 64-bit presence bit i+0x20 */
void ts4_set_entry_bitfield_b_mask_8890C870(char *s, int i, u32 v) { ((ts4_sm3_bits_ent *)s)[i + 0x30].b = v; *(u64 *)(s + 0x18) |= 0x8000000000000000ULL >> (u32)(i + 0x20); }

/* 0x8890C8B0: set 3-bit field c (bits 16..18) of entry i+0x30 (stride 0x18) and set the 64-bit presence bit i+0x20 */
void ts4_set_entry_bitfield_c_mask_8890C8B0(char *s, int i, u32 v) { ((ts4_sm3_bits_ent *)s)[i + 0x30].c = v; *(u64 *)(s + 0x18) |= 0x8000000000000000ULL >> (u32)(i + 0x20); }

/* 0x8890C8F0: set 3-bit field d (bits 19..21) of entry i+0x30 (stride 0x18) and set the 64-bit presence bit i+0x20 */
void ts4_set_entry_bitfield_d_mask_8890C8F0(char *s, int i, u32 v) { ((ts4_sm3_bits_ent *)s)[i + 0x30].d = v; *(u64 *)(s + 0x18) |= 0x8000000000000000ULL >> (u32)(i + 0x20); }

/* 0x889D2FE8: initialise 30 16-byte entries (word2 = 0xFFFFF) and register */
void ts4_init_array30_889D2FE8(void) { struct E { int a, b, c, d; } *p = (struct E *)lbl_88D488B8; int i; for (i = 0; i < 30; i++) { p[i].a = 0; p[i].b = 0; p[i].d = 0; p[i].c = 0xFFFFF; } fn_88563470(ts4_noop_88AFF300); }

/* 0x889D3028: initialise 30 16-byte entries (word2 = 0xFFFFF) and register */
void ts4_init_array30_889D3028(void) { struct E { int a, b, c, d; } *p = (struct E *)lbl_88D48A98; int i; for (i = 0; i < 30; i++) { p[i].a = 0; p[i].b = 0; p[i].d = 0; p[i].c = 0xFFFFF; } fn_88563470(ts4_noop_88AFF308); }

/* 0x8883EE30: find record by key in table at +0x24(+0x74) and store a float at +4 */
void ts4_set_record_float_8883EE30(char *self, u32 k, float v) { *(float *)((char *)fn_881AC7D0(*(char **)(self + 0x24) + 0x74, &k) + 4) = v; }

/* 0x8883EE70: find record by key in table at +0x24(+0x74) and store a word at +4 */
void ts4_set_record_word_8883EE70(char *self, u32 k, u32 v) { *(u32 *)((char *)ts4_find_record_by_key_881AC778(*(char **)(self + 0x24) + 0x74, &k) + 4) = v; }

/* 0x887CE580: true if word0 is one of three type hashes */
int ts4_is_one_of_three_hashes_887CE580(char *self) { u32 h = *(u32 *)self; if (h == 0x236F2EA1u || h == 0x2FA88503u || h == 0x55ACCA9Cu) return 1; return 0; }

/* 0x887CF140: element (stride 0x24) of the vector at +0 selected by index at +0xC, or 0 when out of range */
char *ts4_get_element_stride36_at_cursor_887CF140(char *self) { char *b = *(char **)self; int n = (*(char **)(self + 4) - b) / 0x24; if (n == 0) return 0; u32 i = *(u32 *)(self + 0xc); if (i < (u32)n) return b + i * 0x24; return 0; }

/* 0x88941900: call helper with two global words, return self */
void *ts4_call_with_two_globals_return_self_88941900(void *self, int b) { fn_88923238(self, b, lbl_88D458B0, lbl_88D458AC); return self; }

/* 0x888C77E8: for each 0xF4-byte entry in the range at +0x1C whose word +0xEC == key: clear bytes +0x9A/+0x9B and set +0xF0 */
void ts4_reset_entries_with_key_888C77E8(char *self, u32 k) { char *e = *(char **)(self + 0x20); char *p = *(char **)(self + 0x1c); if (e == p) return; do { if (*(u32 *)(p + 0xec) == k) { p[0x9a] = 0; p[0x9b] = 0; p[0xf0] = 1; } p += 0xf4; } while (e != p); }

/* 0x889453A0: if the global object exists and byte +0x178 == 1, return word +0xE8, else 0 */
static __forceinline u8 ts4_sm3_obj_ready(char *g) { return (g && g[0x178] == 1) ? 1 : 0; } u32 ts4_global_obj_f178_is1_get_fe8_889453A0(void) { char *g = lbl_88D45888; if (ts4_sm3_obj_ready(g)) return *(u32 *)(g + 0xe8); return 0; }

/* 0x887F6FB0: signed int a >= b (method) */
bool ts4_int_ge_887F6FB0(void *t, int a, int b) { return a >= b; }

/* 0x887F7088: signed int a <= b (method) */
bool ts4_int_le_887F7088(void *t, int a, int b) { return a <= b; }

/* 0x887F6F90: byte a >= b (method) */
bool ts4_u8_ge_887F6F90(void *t, u8 a, u8 b) { return a >= b; }

/* 0x887F7068: byte a <= b (method) */
bool ts4_u8_le_887F7068(void *t, u8 a, u8 b) { return a <= b; }

/* 0x887F70B8: byte a < b (method) */
bool ts4_u8_lt_887F70B8(void *t, u8 a, u8 b) { return a < b; }

/* 0x887F70D0: signed int a < b (method) */
bool ts4_int_lt_887F70D0(void *t, int a, int b) { return a < b; }

/* 0x887F70A0: float a <= b (method) */
bool ts4_float_le_887F70A0(void *t, float a, float b) { return a <= b; }

/* 0x887F70E8: float a < b (method) */
bool ts4_float_lt_887F70E8(void *t, float a, float b) { return a < b; }

/* 0x887F7128: float a == b (method) */
bool ts4_float_eq_887F7128(void *t, float a, float b) { return a == b; }

/* 0x887F6FE0: byte a > b (method) */
bool ts4_u8_gt_887F6FE0(void *t, u8 a, u8 b) { return a > b; }

/* 0x887F6FF8: signed int a > b (method) */
bool ts4_int_gt_887F6FF8(void *t, int a, int b) { return a > b; }

/* 0x888C0590: compare int field +0 of two objects */
bool ts4_obj_int0_cmp_888C0590(char *x, char *y) { int a = *(int *)(x + 0); int b = *(int *)(y + 0); return a < b; }

/* 0x888C05B0: compare int field +4 of two objects */
bool ts4_obj_int4_cmp_888C05B0(char *x, char *y) { int a = *(int *)(x + 4); int b = *(int *)(y + 4); return a < b; }

/* 0x888C1BC0: compare int field +0x20 of two objects */
bool ts4_obj_int20_cmp_888C1BC0(char *x, char *y) { int a = *(int *)(x + 32); int b = *(int *)(y + 32); return a > b; }

/* 0x88934C70: if object at +0x1C is set, call helper(obj, arg, self) */
void ts4_forward_field1c_with_self_88934C70(char *self, int b) { void *p = *(void **)(self + 0x1c); if (p) fn_88933B20(p, b, self); }

/* 0x8893E450: if object at +0x1C is set, call helper(obj, self) */
void ts4_forward_field1c_with_self_8893E450(char *self) { void *p = *(void **)(self + 0x1c); if (p) fn_8893DB88(p, self); }

/* 0x8893E430: if object at +0x1C is set, call helper(obj, self, arg) */
void ts4_forward_field1c_with_self_8893E430(char *self, void *b) { void *p = *(void **)(self + 0x1c); if (p) fn_8893D788(p, self, b); }

/* 0x887F7440: element i (stride 4) of the relative-offset array at (obj(+0x1C)+0x20)+0xC */
char *ts4_rel_array_elem_887F7440(char *self, int i) { char *q = *(char **)(*(char **)(self + 0x1c) + 0x20) + 12; return q + (i * 4 + *(int *)q); }

/* 0x887F7478: element i (stride 4) of the relative-offset array at (obj(+0x1C)+0x20)+0x48 */
char *ts4_rel_array_elem_887F7478(char *self, int i) { char *q = *(char **)(*(char **)(self + 0x1c) + 0x20) + 72; return q + (i * 4 + *(int *)q); }

/* 0x887F7498: element i (stride 4) of the relative-offset array at (obj(+0x1C)+0x20)+0x24 */
char *ts4_rel_array_elem_887F7498(char *self, int i) { char *q = *(char **)(*(char **)(self + 0x1c) + 0x20) + 36; return q + (i * 4 + *(int *)q); }

/* 0x887F74B8: element i (stride 4) of the relative-offset array at (obj(+0x1C)+0x20)+0x3C */
char *ts4_rel_array_elem_887F74B8(char *self, int i) { char *q = *(char **)(*(char **)(self + 0x1c) + 0x20) + 60; return q + (i * 4 + *(int *)q); }

/* 0x887F74D8: element i (stride 8) of the relative-offset array at (obj(+0x1C)+0x20)+0x30 */
char *ts4_rel_array_elem_887F74D8(char *self, int i) { char *q = *(char **)(*(char **)(self + 0x1c) + 0x20) + 48; return q + (i * 8 + *(int *)q); }

/* 0x8890C700: set 5-bit field a (bits 0..4 of word +4) of entry i (stride 0x18 from +0x48C) and the presence bit i+0x20 */
void ts4_set_entry_bitfield_a_mask_8890C700(char *s, int i, u32 v) { ((ts4_sm3_bits_ent2 *)(s + 0x48c))[i].a = v; *(u64 *)(s + 0x18) |= 0x8000000000000000ULL >> (u32)(i + 0x20); }

/* 0x8890C748: set 5-bit field b (bits 5..9 of word +4) of entry i and the presence bit i+0x20 */
void ts4_set_entry_bitfield_b_mask_8890C748(char *s, int i, u32 v) { ((ts4_sm3_bits_ent2 *)(s + 0x48c))[i].b = v; *(u64 *)(s + 0x18) |= 0x8000000000000000ULL >> (u32)(i + 0x20); }

/* 0x8890C790: set 2-bit field c (bits 27..28 of word +8) of entry i and the presence bit i+0x20 */
void ts4_set_entry_bitfield_c_mask_8890C790(char *s, int i, u32 v) { ((ts4_sm3_bits_ent2 *)(s + 0x48c))[i].c = v; *(u64 *)(s + 0x18) |= 0x8000000000000000ULL >> (u32)(i + 0x20); }

/* 0x8890C6B8: set 1-bit field d (bit 29 of word +8) of entry i and the presence bit i+0x20 */
void ts4_set_entry_bitfield_d_mask_8890C6B8(char *s, int i, u32 v) { ((ts4_sm3_bits_ent2 *)(s + 0x48c))[i].d = v; *(u64 *)(s + 0x18) |= 0x8000000000000000ULL >> (u32)(i + 0x20); }

/* 0x8890C828: set 2-bit field x (bits 7..8 of word +0) of entry i and the presence bit i+0x20 */
void ts4_set_entry_bitfield_x_mask_8890C828(char *s, int i, u32 v) { ((ts4_sm3_bits_ent2 *)(s + 0x48c))[i].x = v; *(u64 *)(s + 0x18) |= 0x8000000000000000ULL >> (u32)(i + 0x20); }

/* 0x88711C70: if the global object exists, call helper(global, self, high word of arg << 32) */
void ts4_forward_high_word_global_88711C70(void *self, u64 a) { if (lbl_88D45A70) fn_887036B0(lbl_88D45A70, self, (u64)*(u32 *)&a << 32); }

/* 0x88711CB8: if the global object exists, call helper(global, self, high word of arg << 32) */
void ts4_forward_high_word_global_88711CB8(void *self, u64 a) { if (lbl_88D45A70) fn_887036B0(lbl_88D45A70, self, (u64)*(u32 *)&a << 32); }

/* 0x88711D00: if the global object exists, call helper(global, self, high word of arg << 32) */
void ts4_forward_high_word_global_88711D00(void *self, u64 a) { if (lbl_88D45A70) fn_887036B0(lbl_88D45A70, self, (u64)*(u32 *)&a << 32); }

/* 0x88733FB8: if the global object exists, call helper(global, self, high word of arg << 32) */
void ts4_forward_high_word_global_88733FB8(void *self, u64 a) { if (lbl_88D45AD8) fn_88731AF0(lbl_88D45AD8, self, (u64)*(u32 *)&a << 32); }

/* 0x8874D228: if the global object exists, call helper(global, self, high word of arg << 32) */
void ts4_forward_high_word_global_8874D228(void *self, u64 a) { if (lbl_88D45AD8) fn_8874AAB0(lbl_88D45AD8, self, (u64)*(u32 *)&a << 32); }

/* 0x888C3348: relative-offset table entry i (stride 0x44) of the global's table at +0x54, offset 0 */
char *ts4_table_rel_elem_888C3348(int i) { char *q = *(char **)(lbl_88D45908 + 0x54); char *e = q + (i * 0x44 + *(int *)q); char *t = e + 0; return t + *(int *)t; }

/* 0x888C3370: relative-offset table entry i (stride 0x44) of the global's table at +0x54, sub-offset 0xC */
char *ts4_table_rel_elem_888C3370(int i) { char *q = *(char **)(lbl_88D45908 + 0x54); char *e = q + (i * 0x44 + *(int *)q); char *t = e + 12; return t + *(int *)t; }

/* 0x888C33A0: relative-offset table entry i (stride 0x44) of the global's table at +0x54, sub-offset 0x30 */
char *ts4_table_rel_elem_888C33A0(int i) { char *q = *(char **)(lbl_88D45908 + 0x54); char *e = q + (i * 0x44 + *(int *)q); char *t = e + 48; return t + *(int *)t; }

/* 0x888C33D0: relative-offset table entry i (stride 0x44) of the global's table at +0x54, sub-offset 0x24 */
char *ts4_table_rel_elem_888C33D0(int i) { char *q = *(char **)(lbl_88D45908 + 0x54); char *e = q + (i * 0x44 + *(int *)q); char *t = e + 36; return t + *(int *)t; }

/* 0x888C3400: relative-offset table entry i (stride 0x44) of the global's table at +0x54, sub-offset 0x18 */
char *ts4_table_rel_elem_888C3400(int i) { char *q = *(char **)(lbl_88D45908 + 0x54); char *e = q + (i * 0x44 + *(int *)q); char *t = e + 24; return t + *(int *)t; }

/* 0x88864CA8: out = table[i] from a four-entry constant hash table */
void ts4_lookup_const_hash_table4_88864CA8(u32 *out, int i) { u32 t[4]; t[0] = 0x677AED08u; t[1] = 0xFE73BCB2u; t[2] = 0x89748C24u; t[3] = 0x17101987u; *out = t[i]; }

/* 0x888AE900: find object pointer in vector (+0x1C..+0x20) whose field +0x34 equals *key, or 0 */
char *ts4_find_obj_by_field34_via_ptr_888AE900(char *self, u32 *k) { char *r = 0; char *e = *(char **)(self + 32); char *p = *(char **)(self + 28); for (; p != e; p += 4) { char *o = *(char **)p; if (*k == *(u32 *)(o + 0x34)) { r = o; break; } } return r; }

/* 0x888AE948: find object pointer in vector (+0x34..+0x38) whose field +0x44 equals *key, or 0 */
char *ts4_find_obj_by_field44_via_ptr_888AE948(char *self, u32 *k) { char *r = 0; char *e = *(char **)(self + 56); char *p = *(char **)(self + 52); for (; p != e; p += 4) { char *o = *(char **)p; if (*k == *(u32 *)(o + 0x44)) { r = o; break; } } return r; }

/* 0x887787B8: scale an int by script constant 85 when byte +0x1D is set */
int ts4_scale_int_by_const85_if_flag1d_887787B8(char *self, int a) { if (self[0x1d]) { float f = (float)a; return (int)(f * g_ts4_script_constants[85]); } return a; }

/* 0x88778800: scale an int by script constant 86 when byte +0x1E is set */
int ts4_scale_int_by_const86_if_flag1e_88778800(char *self, int a) { if (self[0x1e]) { float f = (float)a; return (int)(f * g_ts4_script_constants[86]); } return a; }

/* 0x88778B70: scale an int by script constant 85 when the global object has byte +0x1D set */
int ts4_scale_int_by_const85_global_88778B70(int a) { char *g = lbl_88D45A60; if (g[0x1d] == 0) return a; return (int)((float)a * g_ts4_script_constants[85]); }

/* 0x888385F0: out = table[i-1] from a four-entry constant hash table */
void ts4_lookup_const_hash_table4_prev_888385F0(u32 *out, int i) { u32 t[4]; t[0] = 0x677AED08u; t[1] = 0xFE73BCB2u; t[2] = 0x89748C24u; t[3] = 0x17101987u; *out = t[i - 1]; }

/* 0x88915A78: zero the words of the ranges at +8..+0xC and +0x14..+0x18 */
void ts4_zero_two_word_ranges_88915A78(char *self) { u32 *e = *(u32 **)(self + 0xc); u32 *p = *(u32 **)(self + 8); u32 *e2, *q; if (p != e) { do { *p = 0; p++; } while (p != e); } e2 = *(u32 **)(self + 0x18); q = *(u32 **)(self + 0x14); if (q == e2) return; do { *q = 0; q++; } while (q != e2); }

/* 0x88915D28: search 7 8-byte entries of a global table (+4 key) for *key; return its word0 or -1 */
int ts4_lookup_table_by_word1_88915D28(u32 *k) { int i; for (i = 0; i < 7; i++) { if (*k == *(u32 *)(lbl_88C6B728 + 4 + i * 8)) return *(int *)(lbl_88C6B728 + i * 8); } return -1; }

/* 0x888C0338: true when words +0x38, +0, +4, +8 and +0xC are all nonzero */
u8 ts4_all_five_words_set_888C0338(char *self) { return (*(int *)(self + 0x38) != 0 && *(int *)self != 0 && *(int *)(self + 4) != 0 && *(int *)(self + 8) != 0 && *(int *)(self + 0xc) != 0) ? 1 : 0; }

/* 0x88778768: scale an int by script constant 84 plus constant 16 when byte +0x1F is set */
int ts4_scale_int_by_const84_plus16_if_flag1f_88778768(char *self, int a) { if (self[0x1f]) return (int)((float)a * g_ts4_script_constants[84] + g_ts4_script_constants[16]); return a; }

/* 0x88756830: if object field +0x10 is set, call helper(obj, 0) */
void ts4_call_with_field10_zero_88756830(char *self) { int p = *(int *)(self + 0x10); if (p != 0) fn_887561A8((void *)p, 0); }

/* 0x888C3738: set float +0x16C of slot i (stride 0x19C) of the global slot table */
void ts4_set_slot_f16c_888C3738(int i, float v) { lbl_88D45CC0[i].f16c = v; }

/* 0x888C3750: set byte +0x168 of slot i (stride 0x19C) of the global slot table */
void ts4_set_slot_f168_888C3750(int i, u8 v) { lbl_88D45CC0[i].f168 = v; }

/* 0x8890DCB0: call helper(a, b, byte (b.f24+12)*4 bytes into a.f18) */
void ts4_forward_with_indexed_byte_8890DCB0(char *a, char *b) { fn_8890DB90(a, b, ((u8 *)*(char **)(a + 0x18))[(*(int *)(b + 0x24) + 12) * 4]); }

/* 0x88931140: true if (short)(*a - *b) < 0 for two 16-bit values */
bool ts4_u16_diff_negative_88931140(u16 *a, u16 *b) { return (short)(*a - *b) < 0; }

/* 0x8899DAA0: true if this.word(+0xC4) > other.word(+0xC4) */
bool ts4_obj_field_c4_greater_8899DAA0(char *a, char *b) { return *(u32 *)(b + 0xc4) < *(u32 *)(a + 0xc4); }

/* 0x889B6890: call title server helper on the global title server if present */
void ts4_title_server_forward_889B6890(void) { if (g_ts4_title_server) ts4_if_call_seq_fn_889B5A30_889B5BE0(g_ts4_title_server); }

/* 0x88802FC8: if object at +0x44 is set, call its virtual method slot 8 */
void ts4_call_vslot8_of_field44_88802FC8(char *self) { int p = *(int *)(self + 0x44); if (p) (*(void (**)(void *))(*(char **)p + 0x20))((void *)p); }

/* 0x88802FE8: if object at +0x44 is set, call its virtual method slot 7 */
void ts4_call_vslot7_of_field44_88802FE8(char *self) { int p = *(int *)(self + 0x44); if (p) (*(void (**)(void *))(*(char **)p + 0x1c))((void *)p); }

/* 0x888B3CB0: call one of two helpers with script constant 14 depending on byte +0x68 */
void ts4_dispatch_const14_by_flag_888B3CB0(char *self) { if (self[0x68] == 0) fn_888B2CE8(g_ts4_script_constants[14]); else fn_888B2838(g_ts4_script_constants[14]); }

/* 0x888B3CD0: call one of two helpers with script constant 14 depending on byte +0x68 */
void ts4_dispatch_const14_by_flag_888B3CD0(char *self) { if (self[0x68] == 0) fn_888B2AB0(g_ts4_script_constants[14]); else fn_888B24E8(g_ts4_script_constants[14]); }

/* 0x888BD808: if object at +0xC is set, call helper(obj, field +8, field +4) */
void ts4_forward_fields_if_f0c_888BD808(char *self) { void *p = *(void **)(self + 0xc); if (p) fn_888BB5A8(p, *(int *)(self + 8), *(int *)(self + 4)); }

/* 0x888EE870: call helper(global, self) if the global is set */
void ts4_forward_to_global_if_set_888EE870(void *self) { if (lbl_88D45960) fn_888E8A80(lbl_88D45960, self); }

/* 0x888ADB78: if object at +8 is set, store a float through its vbase displacement at +0xC4 */
void ts4_set_vbase_float_c4_888ADB78(char *self, float f) { int p = *(int *)(self + 8); if (p == 0) return; *(float *)((char *)p + *(int *)p + 0xc4) = f; }

/* 0x888ADF50: if object at +8 is set, store a word through its vbase displacement at +0x110 */
void ts4_set_vbase_word_110_888ADF50(char *self, u32 v) { int p = *(int *)(self + 8); if (p == 0) return; *(u32 *)((char *)p + *(int *)p + 0x110) = v; }

/* 0x888C0E80: field +0x34 += a, clamped at zero */
void ts4_add_clamp_f34_888C0E80(char *self, int a) { int v = *(int *)(self + 0x34) + a; *(int *)(self + 0x34) = v; if (v < 0) *(int *)(self + 0x34) = 0; }

/* 0x889A0C60: store *src at +0x24 of the relative-offset block at (field +0x24)+0x214 */
void ts4_set_rel_array_word_24_889A0C60(char *self, u32 *src) { char *q = *(char **)(self + 0x24) + 0x214; *(u32 *)(q + *(int *)q + 0x24) = *src; }

/* 0x8883DD28: if sub-object (this+0x80) word +0xC is set, call helper(sub, 1) */
void ts4_call_with_flag_if_sub_fc_8883DD28(char *self) { char *s = self + 0x80; if (*(u32 *)(s + 0xc)) fn_889254C8(s, 1); }

/* 0x888D9878: report component event A3AE3B93 for the component at +0x48 with constant float */
void ts4_report_event_a3ae3b93_888D9878(char *self) { ts4_report_component_event(*(void **)(self + 0x48), -1, 0xA3AE3B93u, lbl_8814B440); }

/* 0x88864C18: pointer to the first 0x20 in a zero-terminated 16-bit string, or 0 */
u16 *ts4_find_space_in_wide_string_88864C18(u16 *p) { while (*p != 0) { if (*p == 0x20) return p; p++; } return 0; }

/* 0x88923408: word 0 of element i (stride 16) of the table at +4, or 0 when i >= count (+8) */
u32 ts4_get_word_stride16_or0_88923408(char *self, u32 i) { u32 r = 0; if (i < *(u32 *)(self + 8)) r = *(u32 *)(**(char ***)(self + 4) + i * 16); return r; }

/* 0x887CE7E8: true when words +0x10 and +0x14 are both nonzero */
bool ts4_both_words_set_10_14_887CE7E8(char *self) { return *(u32 *)(self + 0x10) && *(u32 *)(self + 0x14); }

/* 0x88940ED8: true when state (+8) is 0 or 1 */
bool ts4_state_is_0_or_1_88940ED8(char *self) { int v = *(int *)(self + 8); return v == 0 || v == 1; }

/* 0x887CF300: true when pointer at +0 is set and its byte +0x75 is nonzero */
bool ts4_obj_flag75_887CF300(char *self) { char *p = *(char **)self; return p && p[0x75] != 0; }

/* 0x889238F0: true when word +0x20 is nonzero and signed word +0x24 is nonzero */
bool ts4_words_20_24_set_889238F0(char *self) { return *(u32 *)(self + 0x20) && *(int *)(self + 0x24) != 0; }

/* 0x88931848: true when word +8 and half +6 are both zero */
bool ts4_word8_and_half6_clear_88931848(char *self) { return *(u32 *)(self + 8) == 0 && *(u16 *)(self + 6) == 0; }

/* 0x88836280: true when state (+8) is 7 or 2 */
bool ts4_state_is_7_or_2_88836280(char *self) { int v = *(int *)(self + 8); return v == 7 || v == 2; }

/* 0x8899CE38: true when state (+8) == 2 and word +0x80 != -1 */
bool ts4_state2_with_slot_set_8899CE38(char *self) { return *(int *)(self + 8) == 2 && *(int *)(self + 0x80) != -1; }

/* 0x888C5728: true when bool byte +0x5C or +0x5D is set */
bool ts4_flag5c_or_5d_888C5728(char *self) { return *(bool *)(self + 0x5c) || *(bool *)(self + 0x5d); }

/* 0x888360C8: true when state (+8) is nonzero and (state != 1 or word +0x10 nonzero) */
bool ts4_state_nonzero_not_1_or_f10_888360C8(char *self) { int v = *(int *)(self + 8); return v != 0 && (v != 1 || *(int *)(self + 0x10) != 0); }

/* 0x888C2238: true if the global object exists and its type word equals 0x165BBDE9 */
bool ts4_global_obj_hash_matches_165BBDE9_888C2238(void) { char *g = lbl_88D45940; return g && **(u32 **)(g + 0x24) == 0x165BBDE9u; }

/* 0x88923430: word 0 of element i (stride 16) of the table at +4, or 0 when i >= count (+8) */
u32 ts4_get_word_stride16_or0_88923430(char *self, u32 i) { u32 r = 0; if (i < *(u32 *)(self + 8)) r = *(u32 *)(**(char ***)(self + 4) + i * 16); return r; }

/* 0x887CE798: true if the global object exists and word +0x1C is nonzero */
bool ts4_global_obj_has_f1c_887CE798(void) { char *g = lbl_88D45930; return g && *(u32 *)(g + 0x1c) != 0; }

/* 0x887F04F0: true if word +0xDC equals a known global or the argument */
bool ts4_matches_slot_dc_887F04F0(char *self, u32 a) { u32 x = *(u32 *)(self + 0xdc); return lbl_88C6BFF8 == x || a == x; }

/* 0x88836250: true when state (+8) == 6 and byte +0xC of the object at +0x10 is set */
bool ts4_state6_with_flag_88836250(char *self) { return *(int *)(self + 8) == 6 && *(u8 *)(*(char **)(self + 0x10) + 0xc) != 0; }

/* 0x88942C50: true if the global object exists and byte +0x178 == 1 */
bool ts4_global_obj_f178_is1_88942C50(void) { char *g = lbl_88D45888; return g && g[0x178] == 1; }

/* 0x88778CA0: true if sub-object (+0x2CC) of the global is set and its byte +9 is nonzero */
bool ts4_global_sub_flag9_88778CA0(void) { int p = *(int *)(lbl_88D45B1C + 0x2cc); return p && *(u8 *)((char *)p + 9) != 0; }

/* 0x88922AD8: true when state (+8) is one of 1,2,3,4,6,8,9 */
bool ts4_state_in_set_1234689_88922AD8(char *self) { int v = *(int *)(self + 8); return v == 1 || v == 2 || v == 3 || v == 4 || v == 6 || v == 8 || v == 9; }

/* 0x8890D738: true if x lies within [p[0], p[1]] */
bool ts4_float_in_closed_range_8890D738(float *p, float x) { return x >= p[0] && x <= p[1]; }

/* 0x887F0520: true if word +0xD8 equals a known global or the argument */
bool ts4_matches_slot_d8_887F0520(char *self, u32 a) { u32 x = *(u32 *)(self + 0xd8); return lbl_88C6BFF4 == x || a == x; }

/* 0x888C1A58: false (0) when element i (stride 0x3C) has words +0x4C == a and +0x50 == b, else 1 */
int ts4_pair_mismatch_stride60_888C1A58(char *self, int i, int a, int b) { char *p = self + i * 0x3c; if (a == *(int *)(p + 0x4c) && b == *(int *)(p + 0x50)) return 0; return 1; }

/* 0x887E99A0: find element (stride 0x10) in the range at +0x1C whose word0 equals *key; end if absent */
char *ts4_find_by_word0_via_ptr_stride16_887E99A0(char *self, u32 *k) { char *p = *(char **)(self + 0x1c); char *e = *(char **)(self + 0x20); if (p == e) return p; do { if (*k == *(u32 *)p) return p; p += 0x10; } while (p != e); return p; }

/* 0x889228F0: element i (stride 0x40) of the relative-offset block at obj(+0x20)+0xC, or 0 when out of range */
char *ts4_get_rel_elem_stride64_or0_889228F0(char *self, u32 i) { char *o = *(char **)(self + 0x20); if (i < *(u32 *)(o + 0x10)) { char *q = o + 0xc; return (i * 0x40 + *(int *)q) + q; } return 0; }

/* 0x887CEC70: two-level relative-offset table lookup using indices at +0x64 and +0x68 of the argument */
int ts4_two_level_rel_elem_a_887CEC70(char *self, char *a) { char *q = *(char **)(self + 0x104) + 0x220; char *e = q + (*(int *)(a + 0x64) * 16 + *(int *)q); return *(int *)(e + *(int *)e + *(int *)(a + 0x68) * 4); }

/* 0x888C4B40: two-level relative-offset table lookup with indices i (stride 16) and j (stride 4) */
int ts4_two_level_rel_elem_b_888C4B40(char *self, int i, int j) { char *q = *(char **)(self + 0x254) + 0x220; char *e = q + (i * 16 + *(int *)q); return *(int *)(e + (j * 4 + *(int *)e)); }

/* 0x88932158: decrement refcount at +0x414; delete this when it reaches zero or below */
void ts4_release_ref_f414_delete_self_88932158(ts4_sm3_vobj2 *self) { if (--*(int *)((char *)self + 0x414) <= 0) delete self; }

/* 0x889322D0: load owner pointer; decrement its refcount at +0x414; delete it when zero or below */
void ts4_release_ref_f414_delete_owner_889322D0(ts4_sm3_vobj2 **pp) { ts4_sm3_vobj2 *o = *pp; if (--*(int *)((char *)o + 0x414) <= 0) delete o; }

/* 0x88995EE0: append a 64-bit value to the array at +0x328 (count at +0x32C) */
void ts4_push_u64_f328_88995EE0(char *self, u64 v) { ((u64 *)*(char **)(self + 0x328))[*(int *)(self + 0x32c)] = v; (*(int *)(self + 0x32c))++; }

/* 0x88931AE8: fill the first (+0x20C) bytes at +4 with 9 and copy the count to +0x204 */
void ts4_fill_nines_f4_88931AE8(char *self) { u32 i; for (i = 0; i < *(u32 *)(self + 0x20c); i++) self[4 + i] = 9; *(u32 *)(self + 0x204) = *(u32 *)(self + 0x20c); }

}
