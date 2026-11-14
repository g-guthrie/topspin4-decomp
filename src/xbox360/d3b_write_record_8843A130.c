/* Swing_DLL.xex 0x8843A130-0x88460378, executable version 0.0.0.3. */
typedef struct Stream { void **vtbl; } Stream;
extern char lbl_880818C4[];
extern char lbl_880818CC[];
extern char lbl_88081A40[];
extern char lbl_88081A70[];
extern char lbl_88081F14[];
extern char lbl_88081F20[];
extern char lbl_88082C90[];
extern char lbl_88082C9C[];

/* Serialises an object through a stream: writes the owner reference under one tag, a 32-bit field under a second tag,
   then finishes the record. */
#define WRITE_REC(NAME, TAGA, TAGB, OFF, A5, B5) \
typedef struct NAME##_obj { char pad[OFF]; void *field; } NAME##_obj; \
void NAME(NAME##_obj *self, Stream *s) \
{ \
    ((void (*)(Stream *, const char *, int, void *))s->vtbl[1])(s, TAGA, A5, self); \
    ((void (*)(Stream *, const char *, int, void *))s->vtbl[3])(s, TAGB, B5, self->field); \
    ((void (*)(Stream *))s->vtbl[6])(s); \
}

WRITE_REC(ts4_write_record_8843A130, lbl_880818CC, lbl_880818C4, 0x18, 1, 1)
WRITE_REC(ts4_write_record_8843D240, lbl_88081A40, lbl_880818C4, 0x18, 1, 1)
WRITE_REC(ts4_write_record_8843DCA0, lbl_88081A70, lbl_880818C4, 0x18, 1, 1)
WRITE_REC(ts4_write_record_8844A8E8, lbl_88081F20, lbl_88081F14, 0x14, 1, 1)
WRITE_REC(ts4_write_record_884602E8, lbl_88082C9C, lbl_88082C90, 0xc, 8, 8)
