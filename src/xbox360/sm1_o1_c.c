/* SM1 /O1 batch c: more small functions compiled with /O1 (0x883E.. - 0x883F..). */
typedef unsigned int u32;
typedef unsigned long long u64;

/* Swing_DLL.xex 0x883E8930: true when every 16-byte entry has a zero word at +8 */
typedef struct Ts4Entries { char pad[0xc]; char *items; u32 count; } Ts4Entries;
int ts4_all_entries_field8_zero_883E8930(Ts4Entries *t) { u32 n = t->count; u32 i = 0; char *p; if (n != 0) { p = t->items + 8; do { if (*(u32 *)p != 0) return 0; i++; p += 16; } while (i < n); } return 1; }

/* 0x883F62F0: forward to the child with the inverted bit 6 of a short flag word */
extern int fn_883E3018(void *, int, int);
typedef struct Ts4Linked { char pad[4]; char *info; char pad2[8]; void *child; } Ts4Linked;
int ts4_forward_inverted_flag_883F62F0(Ts4Linked *t, int a) { if (t->child) { short s = *(short *)(t->info + 0x64); fn_883E3018(t->child, a, ((u32)~s >> 6) & 1); } return 0; }

/* 0x883E8080: look up a key in a u32 array, report presence through a byte */
typedef struct Ts4KeyList { char pad[0x30]; u32 count; u32 *keys; } Ts4KeyList;
int ts4_key_list_contains_883E8080(Ts4KeyList *t, u32 key, unsigned char *out) { u32 n = t->count; u32 i = 0; if (n) { u32 *a = t->keys; do { if (key == *a) break; i++; a++; } while (i < n); } *out = (n - i) != 0; return 0; }

/* 0x883FB848 / 0x883FB890: call the user callback at +0x98 with a constant first argument */
typedef int (*Ts4Callback4)(int, int, int, int);
typedef struct Ts4CbHolder { char pad[0x98]; Ts4Callback4 cb; int user; } Ts4CbHolder;
int ts4_call_callback_arg0_883FB848(Ts4CbHolder *t, int b) { Ts4Callback4 cb = t->cb; if (cb) { int r = cb(0, b, 0, t->user); if (r != 0) return r; } return 0; }
int ts4_call_callback_arg1_883FB890(Ts4CbHolder *t, int b) { Ts4Callback4 cb = t->cb; if (cb) { int r = cb(1, b, 0, t->user); if (r != 0) return r; } return 0; }

/* 0x883FF800 */
extern int fn_883E7028(void *, int);
int ts4_forward_optional_value_883FF800(void **t, int *a) { if (*t) { int r = fn_883E7028(*t, a ? *a : 0); if (r != 0) return r; } return 0; }

/* 0x883FF460: fn(a) divided by the unsigned count at +0x2c */
extern double fn_8856B2C0(int);
typedef struct Ts4Counter2C { char pad[0x2c]; u32 count; } Ts4Counter2C;
float ts4_div_by_count_883FF460(Ts4Counter2C *t, int a) { return (float)fn_8856B2C0(a) / (float)(u64)t->count; }
