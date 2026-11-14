/* HS1 matching batch c: handle calls, stats helpers, lazy init, destructors.
   MSVC 16.00.10224.00 /O2 /Oi, verified with tools/fn_check.py. */

/* Swing_DLL.xex 0x8818C150 */
extern char lbl_880D312C[];
int ts4_forward_varargs_88566620(void *h, const char *fmt, ...);
int ts4_if_call_seq_u32_offc_88565B10(void *h);
void ts4_tailcall_fn_88565BA8_88565CD8(void *h);
/* run the forwarded call; abort the handle when it failed and is not usable, else remember success; true when result was 1 */
unsigned char ts4_run_handle_call_8818C150(char *self, int arg)
{
    int r = ts4_forward_varargs_88566620(*(void **)(self + 0x10), lbl_880D312C, arg);
    if (r != 1 && ts4_if_call_seq_u32_offc_88565B10(*(void **)(self + 0x10)) == 0) {
        ts4_tailcall_fn_88565BA8_88565CD8(*(void **)(self + 0x10));
        return 0;
    }
    if (ts4_if_call_seq_u32_offc_88565B10(*(void **)(self + 0x10)) != 0)
        *(unsigned char *)(self + 0xc) = 1;
    return r == 1;
}

/* Swing_DLL.xex 0x8818C1E8 */
extern char lbl_880D5854[];
int ts4_forward_varargs_88566620(void *h, const char *fmt, ...);
int ts4_if_call_seq_u32_offc_88565B10(void *h);
void ts4_tailcall_fn_88565BA8_88565CD8(void *h);
/* run the forwarded call; abort the handle when it failed and is not usable, else remember success; true when result was 1 */
unsigned char ts4_run_handle_call_8818C1E8(char *self, int arg)
{
    int r = ts4_forward_varargs_88566620(*(void **)(self + 0x10), lbl_880D5854, arg);
    if (r != 1 && ts4_if_call_seq_u32_offc_88565B10(*(void **)(self + 0x10)) == 0) {
        ts4_tailcall_fn_88565BA8_88565CD8(*(void **)(self + 0x10));
        return 0;
    }
    if (ts4_if_call_seq_u32_offc_88565B10(*(void **)(self + 0x10)) != 0)
        *(unsigned char *)(self + 0xc) = 1;
    return r == 1;
}

/* Swing_DLL.xex 0x8818C280 */
extern char lbl_880D5858[];
int ts4_forward_varargs_88566620(void *h, const char *fmt, ...);
int ts4_if_call_seq_u32_offc_88565B10(void *h);
void ts4_tailcall_fn_88565BA8_88565CD8(void *h);
/* run the forwarded call; abort the handle when it failed and is not usable, else remember success; true when result was 1 */
unsigned char ts4_run_handle_call_8818C280(char *self, int arg)
{
    int r = ts4_forward_varargs_88566620(*(void **)(self + 0x10), lbl_880D5858, arg);
    if (r != 1 && ts4_if_call_seq_u32_offc_88565B10(*(void **)(self + 0x10)) == 0) {
        ts4_tailcall_fn_88565BA8_88565CD8(*(void **)(self + 0x10));
        return 0;
    }
    if (ts4_if_call_seq_u32_offc_88565B10(*(void **)(self + 0x10)) != 0)
        *(unsigned char *)(self + 0xc) = 1;
    return r == 1;
}

/* Swing_DLL.xex 0x8827EF48 */
typedef struct TS4Stats { char pad[0x34]; int bytes; int count; } TS4Stats;
typedef struct TS4StatsOwner { int unused; TS4Stats *stats; } TS4StatsOwner;
typedef struct TS4VtblObj { int (**vtbl)(void *); } TS4VtblObj;
/* call virtual slot 1 of the object at +0x14 (returns a size) and add it to the owner's byte stat, bumping the count */
void ts4_stats_add_call_8827EF48(char *self)
{
    TS4VtblObj *obj = *(TS4VtblObj **)(self + 0x14);
    int n = obj->vtbl[1](obj);
    TS4StatsOwner *owner = *(TS4StatsOwner **)(self + 0x18);
    owner->stats->bytes += n;
    owner->stats->count += 1;
}

/* Swing_DLL.xex 0x8827EFA8 */
typedef struct TS4Stats2 { char pad[0x3c]; int bytes; int count; } TS4Stats2;
typedef struct TS4StatsOwner2 { int unused; TS4Stats2 *stats; } TS4StatsOwner2;
typedef struct TS4VtblObj2 { int (**vtbl)(void *); } TS4VtblObj2;
/* call virtual slot 4 of the object at +0x14 (returns a size) and add it to the owner's second byte stat, bumping its count */
void ts4_stats_add_call_8827EFA8(char *self)
{
    TS4VtblObj2 *obj = *(TS4VtblObj2 **)(self + 0x14);
    int n = obj->vtbl[4](obj);
    TS4StatsOwner2 *owner = *(TS4StatsOwner2 **)(self + 0x18);
    owner->stats->bytes += n;
    owner->stats->count += 1;
}

/* Swing_DLL.xex 0x8834D650 */
extern unsigned int lbl_88C8EAA0;
unsigned int fn_8839A298(unsigned int a, unsigned int b, unsigned int c, int *out);
/* lazily create a handle (type 1) into the global; returns 0x21 when the creation reported an error */
int ts4_lazy_create_handle_8834D650(void)
{
    int err;
    if (lbl_88C8EAA0 == 0) {
        lbl_88C8EAA0 = fn_8839A298(0xac44, 1, 0x200, &err);
        if (err != 0)
            return 0x21;
    }
    return 0;
}

/* Swing_DLL.xex 0x8834D6B8 */
extern unsigned int lbl_88C8EAA4;
unsigned int fn_8839A298(unsigned int a, unsigned int b, unsigned int c, int *out);
/* lazily create a handle (type 2) into the global; returns 0x21 when the creation reported an error */
int ts4_lazy_create_handle_8834D6B8(void)
{
    int err;
    if (lbl_88C8EAA4 == 0) {
        lbl_88C8EAA4 = fn_8839A298(0xac44, 2, 0x200, &err);
        if (err != 0)
            return 0x21;
    }
    return 0;
}

/* Swing_DLL.xex 0x8837BA88 */
extern char *lbl_88B3302C;
extern char lbl_88028C90[];
void fn_88315F10(void *heap, void *p, const char *file, int line);
/* free the block owned through the pointer at *self (if any) and clear it */
void ts4_free_owned_block_8837BA88(void ***self)
{
    void **p = *self;
    if (p != 0 && *p != 0) {
        fn_88315F10(*(void **)(lbl_88B3302C + 4), *p, lbl_88028C90, 0xb7);
        *p = 0;
    }
}

/* Swing_DLL.xex 0x882630A0 */
void fn_88263A88(void *self, void *pos);
/* push back one slot (grow when full), zero it and return its address */
int *ts4_vector_push_slot_882630A0(char *self)
{
    if (*(char **)(self + 4) == *(char **)(self + 8))
        fn_88263A88(self, *(char **)(self + 4));
    if (*(int **)(self + 4) != 0)
        **(int **)(self + 4) = 0;
    *(char **)(self + 4) += 4;
    return (int *)(*(char **)(self + 4) - 4);
}

/* Swing_DLL.xex 0x881A5210 */
void fn_88562EF8(const char *msg);
void fn_88562E80(void);
extern char lbl_880D19E0[];
/* init an inline buffer view of size n at +8 (n must be non-zero and within max_size); otherwise raise */
void ts4_buffer_view_init_881A5210(char *self, unsigned int n)
{
    if (n > 0xffffffffu || n == 0) {
        fn_88562EF8(lbl_880D19E0);
        fn_88562E80();
        return;
    }
    {
        char *b = self + 8;
        *(char **)(self + 0) = b;
        *(char **)(self + 4) = b;
        *(char **)(self + 0x108) = b + n;
    }
}

/* Swing_DLL.xex 0x881D9190 */
extern char lbl_880E8624[];
extern char lbl_880DD088[];
void fn_881992A8(void *heap, void *p);
void fn_881F26C0(void *first, void *last);
/* destructor: reset vtable, free the buffers at +0x30, +0x20, destroy+free the range at +0x10/+0x14, restore base vtable */
void ts4_dtor_free_buffers_881D9190(void **self)
{
    void **sub;
    *(void *volatile *)self = lbl_880E8624;
    { void *v = *(void * volatile *)&self[12]; if (v) fn_881992A8(0, v); }
    { void *v = *(void * volatile *)&self[8]; if (v) fn_881992A8(0, v); }
    sub = self + 3;
    if (sub[1]) {
        fn_881F26C0(sub[1], sub[2]);
        if (sub[1]) fn_881992A8(0, sub[1]);
    }
    *(void *volatile *)self = lbl_880DD088;
}

/* Swing_DLL.xex 0x88209AC0 */
extern char lbl_880E9E98[];
extern char lbl_880DD088[];
void fn_881992A8(void *heap, void *p);
void fn_881F26C0(void *first, void *last);
/* destructor: reset vtable, free the buffers at +0x30, +0x20, destroy+free the range at +0x10/+0x14, restore base vtable */
void ts4_dtor_free_buffers_88209AC0(void **self)
{
    void **sub;
    *(void *volatile *)self = lbl_880E9E98;
    { void *v = *(void * volatile *)&self[12]; if (v) fn_881992A8(0, v); }
    { void *v = *(void * volatile *)&self[8]; if (v) fn_881992A8(0, v); }
    sub = self + 3;
    if (sub[1]) {
        fn_881F26C0(sub[1], sub[2]);
        if (sub[1]) fn_881992A8(0, sub[1]);
    }
    *(void *volatile *)self = lbl_880DD088;
}

/* Swing_DLL.xex 0x8833BA38 */
int fn_8833B258(void *o, unsigned int flag);
/* set/clear the enabled flag at +0x134 of the outer object via the callee; no-op when enabling an already enabled one */
int ts4_set_enabled_8833BA38(char *self, unsigned int flag)
{
    char *o = self ? self - 0x1c : 0;
    unsigned char v;
    int r;
    if (flag != 0) {
        if (*(unsigned char *)(o + 0x134) != 0)
            return 0;
        r = fn_8833B258(o, flag);
        if (r != 0)
            return r;
        v = 1;
    } else {
        r = fn_8833B258(o, 0);
        if (r != 0)
            return r;
        v = 0;
    }
    *(unsigned char *)(o + 0x134) = v;
    return 0;
}

/* Swing_DLL.xex 0x8833D818 */
int fn_8833D6D8(void *o, unsigned int flag);
/* set/clear the enabled flag at +0x134 of the outer object via the callee; no-op when enabling an already enabled one */
int ts4_set_enabled_8833D818(char *self, unsigned int flag)
{
    char *o = self ? self - 0x1c : 0;
    unsigned char v;
    int r;
    if (flag != 0) {
        if (*(unsigned char *)(o + 0x134) != 0)
            return 0;
        r = fn_8833D6D8(o, flag);
        if (r != 0)
            return r;
        v = 1;
    } else {
        r = fn_8833D6D8(o, 0);
        if (r != 0)
            return r;
        v = 0;
    }
    *(unsigned char *)(o + 0x134) = v;
    return 0;
}

/* Swing_DLL.xex 0x88193938 */
extern void *lbl_88D3E3A8;
void fn_88195368(void);
void fn_88195948(void *self, void *glob, void *p, int a, int b, int c, int d, int e, int f);
/* forwarding constructor: make sure the global exists, then forward all args with p+0x2c (8th parameter unused) */
void *ts4_forward_ctor_88193938(void *self, char *p, int a, int b, int c, int d, int e, int unused, int f)
{
    (void)unused;
    if (lbl_88D3E3A8 == 0)
        fn_88195368();
    fn_88195948(self, lbl_88D3E3A8, p + 0x2c, a, b, c, d, e, f);
    return self;
}

/* Swing_DLL.xex 0x881939B0 */
extern void *lbl_88D3E3A8;
void fn_88195368(void);
void fn_88195AA0(void *self, void *glob, void *p, int a, int b, int c, int d, int e, int f);
/* forwarding constructor: make sure the global exists, then forward all args with p+0x2c (8th parameter unused) */
void *ts4_forward_ctor_881939B0(void *self, char *p, int a, int b, int c, int d, int e, int unused, int f)
{
    (void)unused;
    if (lbl_88D3E3A8 == 0)
        fn_88195368();
    fn_88195AA0(self, lbl_88D3E3A8, p + 0x2c, a, b, c, d, e, f);
    return self;
}
