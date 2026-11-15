/* CW34 part d: small gameplay-object helpers (0x888C0000-0x888D8000), plain route. */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
#define CX34_U32(p, o) (*(u32 *)((char *)(p) + (o)))
#define CX34_F32(p, o) (*(float *)((char *)(p) + (o)))
#define CX34_I32(p, o) (*(int *)((char *)(p) + (o)))
#define CX34_U8(p, o) (*(u8 *)((char *)(p) + (o)))
#define CX34_PTR(p, o) (*(char **)((char *)(p) + (o)))
#define CX34_VT(o, slot) ((*(void ***)(o))[(slot) / 4])

extern void *ts4_find_service(u32 hash);
extern float lbl_8814B440;

/* 0x888C0130 */
void ts4_add_and_publish_24_888C0130(char *self, int d)
{
    int v = CX34_I32(self, 0x24);
    char *t = CX34_PTR(self, 4);
    v = d + v;
    CX34_I32(self, 0x24) = v;
    CX34_I32(CX34_PTR(CX34_PTR(t, 0x44), 0x10), 0x58) = v;
}

/* 0x888C0658 */
typedef struct Cx34Vec8 { char *begin; char *end; } Cx34Vec8;
int ts4_entry_count_54_888C0658(char *self, int i)
{
    char *e = self + i * 0x54;
    Cx34Vec8 *v = (Cx34Vec8 *)(e + 0x28);
    return (v->end - v->begin) >> 3;
}



/* 0x888C2278 */
void ts4_set_flag_1c_888C2278(char *self)
{
    volatile u8 t = 1;
    CX34_U8(self, 0x1c) = t;
}

/* 0x888C3908 */
u32 ts4_get_entry_word_888C3908(char *self, int i, int j)
{
    typedef struct Cx34E { char pad[0x18]; char *arr; char pad2[8]; char *ent; } Cx34E;
    Cx34E *e = (Cx34E *)(self + i * 0x54 + 4);
    char *p = e->ent + j * 8;
    u8 k = CX34_U8(p, 1);
    return CX34_U32(e->arr, k * 12);
}

/* 0x888C46C8: reset a string-like buffer */
void ts4_clear_buffer_888C46C8(char *self)
{
    char *v = self + 4;
    CX34_U32(self, 0) = 0;
    CX34_U32(self, 0x10) = 0;
    if (CX34_PTR(v, 0) != CX34_PTR(v, 4)) {
        CX34_U8(CX34_PTR(v, 0), 0) = 0;
        CX34_PTR(v, 4) = CX34_PTR(v, 0);
    }
}

/* 0x888C52E8 */
int ts4_service_exists_888C52E8(void)
{
    void *s = ts4_find_service(0x62E4E7AB);
    return 0 != s;
}



extern void *fn_88562DC0(void *dst, void *src, u32 n);
typedef void (*Cx34Fn0)(void *);
typedef struct Cx34W4 { u32 a, b, c, d; } Cx34W4;
static __inline Cx34W4 *cx34_copy4(Cx34W4 *first, Cx34W4 *last, Cx34W4 *dst)
{
    int n = last - first;
    Cx34W4 *s = first;
    Cx34W4 *p = dst;
    while (n > 0) {
        *p = *s;
        n--;
        p++;
        s++;
    }
    return p;
}

/* 0x888C04D8: clear the 16-byte element vector at +0x20 */
void ts4_clear_vec16_888C04D8(char *self)
{
    char *v = self + 0x20;
    CX34_PTR(v, 4) = (char *)cx34_copy4((Cx34W4 *)CX34_PTR(v, 4), (Cx34W4 *)CX34_PTR(v, 4), (Cx34W4 *)CX34_PTR(v, 0));
}


extern char *lbl_88D45940;
/* 0x888C2238 */
u8 ts4_service_kind_is_888C2238(void)
{
    return (u8)(lbl_88D45940 != 0 && CX34_U32(CX34_PTR(lbl_88D45940, 0x24), 0) == 0x165BBDE9 ? 1 : 0);
}

extern u32 fn_8857C8C8(void);
/* 0x888C22D0: worker loop; never returns */
void ts4_run_loop_888C22D0(char *self)
{
    char *o = CX34_PTR(self, 0x114);
    if (CX34_U32(o, 0x2a88) != 0) fn_8857C8C8();
    CX34_U32(o, 0x2a88) = fn_8857C8C8();
    for (;;) {
        ((Cx34Fn0)CX34_VT(self, 0x28))(self);
        ((Cx34Fn0)CX34_VT(self, 0x2c))(self);
    }
}

extern u32 ts4_tailcall_XamUserGetSigninState_8857A400(u32 user);
/* 0x888C2330 */
void ts4_update_signin_flag_888C2330(char *self, u32 user, char *rec)
{
    if (CX34_U8(rec, 0x18) == 1) {
        if (CX34_U8(CX34_PTR(self, 0x38) + user * 0xb0, 0x18) == 0) {
            CX34_U8(rec, 0x1a) = (u8)(0 != ts4_tailcall_XamUserGetSigninState_8857A400(user));
        }
    }
}




extern char *lbl_88D45908;


extern u32 lbl_88C6B82C[];
/* 0x888C71B8 / 0x888CD920: set byte +0x20 on three services */
void ts4_set_three_services_flag_888C71B8(u8 v)
{
    u32 *p = lbl_88C6B82C;
    int n = 3;
    do {
        char *s = (char *)ts4_find_service(*p);
        if (s) CX34_U8(s, 0x20) = v;
        n--;
        p++;
    } while (n != 0);
}
void ts4_clear_three_services_if_888CD920(char *self, char *ev)
{
    (void)self;
    if (CX34_U32(ev, 0x18) == 0x1DCA7285) {
        u32 *p = lbl_88C6B82C;
        int n = 3;
        u8 z = 0;
        do {
            char *s = (char *)ts4_find_service(*p);
            if (s) CX34_U8(s, 0x20) = z;
            n--;
            p++;
        } while (n != 0);
    }
}

/* 0x888C1AB8: map a type hash to a small kind id (default 3) */
u32 ts4_hash_to_kind_888C1AB8(u32 *p)
{
    u32 r = 3;
    switch (*p) {
    case 0x6127B0EC: r = 4; break;
    case 0x26296DD2: r = 3; break;
    case 0x48B79674: r = 6; break;
    case 0x55D982AB: r = 1; break;
    case 0xDDAE07EE: r = 5; break;
    case 0xE95035A9: r = 2; break;
    default: break;
    }
    return r;
}

extern u32 XNotifyGetNext(u32 handle, u32 id, u32 *out_id, u32 *out_param);
