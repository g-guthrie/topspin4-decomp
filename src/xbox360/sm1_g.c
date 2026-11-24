/* SM1 batch g: small helpers (default /O2). */
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct Ts4VObj6 { int (**vt)(); } Ts4VObj6;

/* Swing_DLL.xex 0x8833B358: call a helper on the sub-object at +0x138 of the object holding this secondary base */
extern void ts4_if_call_seq_u32_off0_883974C8(void *);
int ts4_call_helper_on_subobject_adj1c_8833B358(char *t) { char *p = t ? t - 0x1c : 0; ts4_if_call_seq_u32_off0_883974C8(p + 0x138); return 0; }

/* 0x883BA9E8: byte-wise checksum chained through a 256-entry lookup table */
extern unsigned char lbl_88035A48[];
unsigned char ts4_table_chain_checksum_883BA9E8(unsigned char *p, u32 n) { unsigned char crc = 0; u32 i; for (i = 0; i < n; i++) crc = lbl_88035A48[crc ^ *p++]; return crc; }

/* 0x8820CBF8: map the top three bits of a byte to a constant id */
typedef struct Ts4B68 { char pad[0x68]; unsigned char kind; } Ts4B68;
u32 ts4_kind_to_id_8820CBF8(void *unused, Ts4B68 *t) { (void)unused; switch (t->kind >> 5) { case 0: return 0xDA554856; case 2: return 0x750B5A10; default: return 0x475CEE12; } }

/* 0x88325560: like the checked slot forwarders but also clears the output byte when there is no owner */
typedef struct Ts4Owner4C2 { char pad[0x4c]; Ts4VObj6 *owned; } Ts4Owner4C2;
int ts4_forward_owned_slot34_clear_88325560(Ts4Owner4C2 *t, unsigned char *out) { if (out == 0) return 0x25; if (t->owned == 0) { *out = 0; return 0x24; } return ((int (*)(Ts4VObj6 *, void *))t->owned->vt[0x88 / 4])(t->owned, out); }

/* 0x88374720: forward two fields of the object that contains this secondary base */
extern void fn_8832AAF8(void *, int, int);
int ts4_forward_fields_adj1c_88374720(char *t) { char *p = t ? t - 0x1c : 0; fn_8832AAF8(p, *(int *)(p + 0x16c), *(int *)(p + 0x168)); return 0; }

/* 0x883B1B08: initialise a 256-entry table (only valid for size 256) */
typedef struct Ts4Table256 { int entries[0x101]; int w404; int w408; } Ts4Table256;
int ts4_init_table256_883B1B08(u32 n, Ts4Table256 *t) { int i; if (n != 0x100) return -0x68; t->w404 = 0; t->w408 = 0x100; for (i = 0; i <= 0x100; i++) t->entries[i] = 0; return 0; }

/* 0x8827E218: call vtable slot 10 of `a` with the dereferenced value, then return this */
void *ts4_call_slot10_return_this_8827E218(void *t, Ts4VObj6 *a, int *b) { ((int (*)(void *, Ts4VObj6 *, int))a->vt[10])(t, a, *b); return t; }
