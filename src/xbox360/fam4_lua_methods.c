/* Lua method registration (Swing_DLL.xex 0x88805B48 group).  The table path
   is looked up under the object's context; when missing it is built from the
   context's base path plus TABLE.  Each method is bound as a C closure
   (thunk fn_881B3080) with the object and the C function as 4-byte upvalues.
   Strings are the 0x20-byte script string type (fn_881B18E0 construct,
   fn_881B19A0 destroy).  Verified byte-for-byte with tools/fn_check.py. */
struct ts4_str20 { int f00, f04, f08, f0c, f10, f14, f18, f1c; };
struct ts4_lobj { char pad[0x3c]; int *ctx; };
void ts4_call_seq_u32_off0_88832F70(struct ts4_str20 *out, int *ctx, const char *name);
void fn_881B18E0(struct ts4_str20 *s, void *a, void *b);
struct ts4_str20 *fn_88837B00(struct ts4_str20 *out, struct ts4_str20 *in, const char *name);
void fn_881B19A0(struct ts4_str20 *s);
void fn_88836968(struct ts4_str20 *s, const char *name, void *thunk, void *a, int asz, void *b, int bsz);
int fn_881B3080();
static __inline void ts4_str20_init(struct ts4_str20 *s, void *a, void *b)
{
    s->f08 = 0;
    s->f10 = 0;
    fn_881B18E0(s, a, b);
}

#define TS4_LUA_REGISTER_METHODS(ADDR, TABLE, METHODS) \
void ts4_lua_register_methods_##ADDR(struct ts4_lobj *self) \
{ \
    const char *table = TABLE; \
    struct ts4_str20 path; \
    ts4_call_seq_u32_off0_88832F70(&path, self->ctx, table); \
    if (path.f08 == 0) { \
        struct ts4_str20 base, full; \
        struct ts4_str20 *r; \
        ts4_str20_init(&base, self->ctx, (char *)(long)*self->ctx + 0x48); \
        r = fn_88837B00(&full, &base, table); \
        fn_881B19A0(&path); \
        fn_881B18E0(&path, (void *)(long)r->f18, &r->f08); \
        fn_881B19A0(&full); \
        fn_881B19A0(&base); \
    } \
    METHODS \
    fn_881B19A0(&path); \
}
/* Bind NAME to the C function FN with SELF as its upvalue. */
#define TS4_LUA_METHOD(NAME, FN) \
    { \
        struct ts4_lobj *obj; \
        void *fn; \
        obj = self; \
        fn = (void *)FN; \
        fn_88836968(&path, NAME, (void *)fn_881B3080, &obj, 4, &fn, 4); \
    }
extern char lbl_880E3658[];
extern char lbl_880E3674[];
extern char lbl_880E367C[];
int fn_88804DF0();
int fn_88804CD0();
extern char lbl_880E365C[];
extern char lbl_880E3664[];
extern char lbl_880E366C[];
extern char lbl_880E3688[];
extern char lbl_880E369C[];
int fn_88803B58();
int fn_88804C38();
int ts4_call_seq_u32_off8_88803C50();
int ts4_fn_88802EF0();
int ts4_lua_push_scaled_timestamp_88804D90();

TS4_LUA_REGISTER_METHODS(88805B48, lbl_880E3658, TS4_LUA_METHOD(lbl_880E369C, fn_88804C38))
TS4_LUA_REGISTER_METHODS(88805D68, lbl_880E3658, TS4_LUA_METHOD(lbl_880E3688, fn_88803B58))
TS4_LUA_REGISTER_METHODS(88805F80, lbl_880E3658, TS4_LUA_METHOD(lbl_880E366C, ts4_lua_push_scaled_timestamp_88804D90))
TS4_LUA_REGISTER_METHODS(888060C8, lbl_880E3658, TS4_LUA_METHOD(lbl_880E3664, ts4_fn_88802EF0))
TS4_LUA_REGISTER_METHODS(88806210, lbl_880E3658, TS4_LUA_METHOD(lbl_880E365C, ts4_call_seq_u32_off8_88803C50))
TS4_LUA_REGISTER_METHODS(88805E58, lbl_880E3658, TS4_LUA_METHOD(lbl_880E3674, fn_88804DF0) TS4_LUA_METHOD(lbl_880E367C, fn_88804CD0))
