/*
 * Swing_DLL.xex constructors and forwarders that take a 12-byte structure by value.
 *
 * Codegen idiom (docs/agents/codegen-idioms.md, idiom 4): a 12-byte struct passed by value
 * after `self` arrives in r4 (words 0-1) and the high half of r5 (word 2). MSVC spills r5 to
 * its home slot and rebuilds it: `std r5,0x88(r1); lwz r11,0x88(r1); rldicr r5,r11,32,63`.
 * The meaning of the three words is not established; the third word is passed on as an
 * object pointer by the service-binding constructors below.
 */
struct TS4TripleArg {
    unsigned int first;
    unsigned int second;
    unsigned int third;
};

void *fn_88627EC0(void *object, struct TS4TripleArg value);
void fn_8862BCB8(void *object, struct TS4TripleArg value, unsigned int word);
void fn_8862BF38(void *object, struct TS4TripleArg value, unsigned int word);
void ts4_call_seq_u32_lbl_88D45B20_886496F0(char *name);
extern char lbl_880C88D9[];
void fn_88638D10(void *object);
void fn_8863C218(void *object, int arg, struct TS4TripleArg value);
extern void *lbl_88D45914;
void fn_888C3220(void *object);
void fn_886F7B38(void *object, struct TS4TripleArg value);
void *fn_88923458(void *owner, struct TS4TripleArg value, unsigned int size);
void fn_88633BD8(void *object, void *child);
void fn_88652A90(void);
void fn_886529C8(void);
void ts4_call_seq_lbl_880F4FD0_886580B8(void);
void fn_887DBFD0(void *object, struct TS4TripleArg value, int mask);
void fn_88801428(int arg);
extern void *lbl_88D459F8;
void fn_8863E750(void *object, int a, int b, struct TS4TripleArg value, int d);
void fn_886F7A70(void *object, struct TS4TripleArg value, int *a, int *b);

struct TS4VirtualObject {
    void (**vtbl)(struct TS4VirtualObject *, ...);
};

/* Call base(self, value, *word_ptr) and return self. */
#define TRIPLE_WORD_CTOR(name, base) \
    void *name(void *self, struct TS4TripleArg value, unsigned int *word_ptr) \
    { base(self, value, *word_ptr); return self; }

TRIPLE_WORD_CTOR(ts4_triple_word_ctor_8862BDC8, fn_8862BCB8) /* 0x8862BDC8 */
TRIPLE_WORD_CTOR(ts4_triple_word_ctor_8862C0A8, fn_8862BF38) /* 0x8862C0A8 */

/* Base-construct, then run the module's name registration (cluster ts4_triple_ctor_register_8864A1A8). */
void ts4_triple_ctor_register_8864A1A8(void *self, struct TS4TripleArg value)
{
    fn_88627EC0(self, value);
    ts4_call_seq_u32_lbl_88D45B20_886496F0(lbl_880C88D9);
}

/* Base-construct, then finish initialisation on the returned object. */
void ts4_triple_ctor_then_init_88638E80(void *self, struct TS4TripleArg value)
{
    fn_88638D10(fn_88627EC0(self, value));
}

/* Forward to the object at self+4 with (arg, value); the third parameter is unused. */
void ts4_triple_forward_member_8863C6D0(void *self, int arg, int unused, struct TS4TripleArg value)
{
    (void)unused;
    fn_8863C218(*(void **)((char *)self + 4), arg, value);
}

/* Base-construct, then notify the global manager if one exists. */
void ts4_triple_ctor_notify_888DDC98(void *self, struct TS4TripleArg value)
{
    fn_88627EC0(self, value);
    if (lbl_88D45914)
        fn_888C3220(lbl_88D45914);
}

/* Call base(self, value) and return self. */
void *ts4_triple_ctor_return_self_88945AC8(void *self, struct TS4TripleArg value)
{
    fn_886F7B38(self, value);
    return self;
}

/* Virtual slot 10 with the owner's field +0x24 offset by value.second. */
void ts4_triple_vcall_offset_88613B28(struct TS4VirtualObject *self, struct TS4TripleArg value)
{
    self->vtbl[10](self, *(int *)(unsigned long)(value.third + 0x24) + value.second);
}

/* Allocate a 0x44-byte child through the owner and attach it to self. */
void ts4_triple_attach_child_88636210(void *self, struct TS4TripleArg value)
{
    fn_88633BD8(self, fn_88923458((void *)(unsigned long)value.third, value, 0x44));
}

/* Base-construct, clear the byte flag at +8 and run two module initialisers. */
void ts4_triple_ctor_clear_flag_88654248(void *self, struct TS4TripleArg value)
{
    fn_88627EC0(self, value);
    *((unsigned char *)self + 8) = 0;
    fn_88652A90();
    fn_886529C8();
}

/* Base-construct, clear the byte flag at +8 and run the module initialiser. */
void ts4_triple_ctor_clear_flag_88658878(void *self, struct TS4TripleArg value)
{
    fn_88627EC0(self, value);
    *((unsigned char *)self + 8) = 0;
    ts4_call_seq_lbl_880F4FD0_886580B8();
}

/* Construct with an all-ones mask when `enabled` is set; return self. */
void *ts4_triple_ctor_mask_887DC1A8(void *self, struct TS4TripleArg value, unsigned char enabled)
{
    fn_887DBFD0(self, value, enabled ? -1 : 0);
    return self;
}

/* Base-construct, run the module setup and publish self as the global instance. */
void ts4_triple_ctor_singleton_88801E60(void *self, struct TS4TripleArg value)
{
    fn_88627EC0(self, value);
    fn_88801428(1);
    lbl_88D459F8 = self;
}

/* Forward (a, b, value, d) to the base constructor, dropping the second parameter; return self. */
void *ts4_triple_ctor_forward_abc_8863EF00(void *self, int unused, int a, int b, struct TS4TripleArg value, int d)
{
    (void)unused;
    fn_8863E750(self, a, b, value, d);
    return self;
}

/* Construct passing two in/out ints by address; return self. */
void *ts4_triple_ctor_inout_88945A78(void *self, struct TS4TripleArg value, int a, int b)
{
    fn_886F7A70(self, value, &a, &b);
    return self;
}

