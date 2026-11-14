/* HS3 hand-matched: script-property clear wrappers (0x887..0x88A). */
typedef unsigned long hs3_word;
typedef struct HS3Args3 { unsigned w[3]; } HS3Args3;
typedef struct HS3Obj { char pad[0x40]; HS3Args3 handle; } HS3Obj;
typedef struct HS3Tmp { unsigned w[2]; } HS3Tmp;

void *ts4_handle_forward_88610778(void *out, void *handle, unsigned *hash);
HS3Tmp *ts4_init_range_and_run_service_opt_88164450(void *out, void *in, unsigned *hash, unsigned count);

typedef struct HS3VT { char pad[0x28]; unsigned char *(*slot28)(void *self, void *arg, unsigned a, unsigned b); } HS3VT;
typedef struct HS3Svc { HS3VT *vt; } HS3Svc;

/* Resolve a script property for hash `h` through the object's handle and clear its byte. */
#define HS3_CLEAR_PROP(NAME, ADDR_COMMENT, HASH)                                              \
    void NAME(HS3Obj *self)                                                                    \
    {                                                                                          \
        unsigned loc50[1];                                                                     \
        HS3Args3 loc58;                                                                        \
        unsigned loc54[1];                                                                     \
        unsigned loc68[3];                                                                     \
        unsigned loc78[3];                                                                     \
        HS3Tmp *t;                                                                             \
        loc58 = self->handle;                                                                  \
        loc50[0] = (HASH);                                                                     \
        ts4_handle_forward_88610778(loc68, &loc58, loc50);                                     \
        loc54[0] = 0xb01f4f95;                                                                 \
        t = ts4_init_range_and_run_service_opt_88164450(loc78, loc68, loc54, 0);               \
        *((HS3Svc *)(hs3_word)t->w[0])->vt->slot28((void *)(hs3_word)t->w[0], t, t->w[1], 1) = 0; \
    }

HS3_CLEAR_PROP(ts4_clear_script_prop_B1CA7E98_888C8190, 0x888C8190, 0xb1ca7e98)
HS3_CLEAR_PROP(ts4_clear_script_prop_DB0366CE_888C8230, 0x888C8230, 0xdb0366ce)
HS3_CLEAR_PROP(ts4_clear_script_prop_052C33A9_888C82D0, 0x888C82D0, 0x052c33a9)
HS3_CLEAR_PROP(ts4_clear_script_prop_3D814F55_888C87D8, 0x888C87D8, 0x3d814f55)

void *fn_8861CE00(void *out, void *in, unsigned hash, unsigned value);
typedef struct HS3Handle { unsigned w[3]; } HS3Handle;
extern HS3Handle lbl_88C6B428;
extern HS3Handle lbl_88C6B41C;
extern HS3Handle lbl_88C6B410;

/* Write `*value` into a script property (found via handle `H`/hash `HA`, property hash `HB`) and clear the status byte. */
#define HS3_SET_PROP(NAME, H, HA, HB)                                                         \
    void *NAME(void *self, unsigned *value)                                                    \
    {                                                                                          \
        unsigned loc50[1];                                                                     \
        HS3Handle loc58;                                                                       \
        unsigned loc54[1];                                                                     \
        unsigned loc68[3];                                                                     \
        unsigned char *p;                                                                      \
        HS3Tmp *t;                                                                             \
        loc50[0] = (HA);                                                                       \
        loc58 = (H);                                                                           \
        ts4_handle_forward_88610778(self, &loc58, loc50);                                      \
        fn_8861CE00(loc68, self, (HB), *value);                                                \
        loc54[0] = 0xb01f4f95;                                                                 \
        t = ts4_init_range_and_run_service_opt_88164450(loc68, self, loc54, 0);                \
        p = ((HS3Svc *)(hs3_word)t->w[0])->vt->slot28((void *)(hs3_word)t->w[0], t, t->w[1], 1); \
        *p = 0;                                                                                \
        return self;                                                                           \
    }

