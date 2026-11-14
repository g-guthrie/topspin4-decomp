#ifndef _MSC_VER
#pragma GCC diagnostic ignored "-Wunused-function"
#endif
/* Swing_DLL.xex 0x88801E60-0x88889080, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned char u8;

/* 12-byte id passed by value (r4 holds the first two words, r5 the third). */
typedef struct Ts4Id12 {
    u32 a;
    u32 b;
    u32 c;
} Ts4Id12;

extern void fn_88627EC0(void *self, Ts4Id12 id);
extern void fn_88628D48(void *self, Ts4Id12 id);
extern char *fn_88923530(u32 c, Ts4Id12 id, u32 key);
extern void fn_88801428(u32 flag);
extern void fn_888866E8(char *dst, u32 value);
extern void fn_88888F90(void *self, char *record);
extern void *lbl_88D459F8;

/* Base initialiser, then copy three fields from the id's record. */
void ts4_init_from_record_88888538(char *self, Ts4Id12 id)
{
    char *record;
    fn_88628D48(self, id);
    record = fn_88923530(id.c, id, 0xB40632A8);
    *(u32 *)(self + 0x34) = *(u32 *)(record + 0x20);
    *(u8 *)(self + 0x1d) = *(u8 *)(record + 0x1d);
    *(u8 *)(self + 0x1c) = *(u8 *)(record + 0x1e);
}

/* Base initialiser, then take a name from the id's record and clear a flag byte. */
static void ts4_call_seq_fn_88627EC0_88888598(char *self, Ts4Id12 id)
{
    char *record;
    fn_88627EC0(self, id);
    record = fn_88923530(id.c, id, 0xA262959B);
    fn_888866E8(self + 0x1c, *(u32 *)(record + 0x1c));
    *(u8 *)(self + 0x30) = 0;
}

