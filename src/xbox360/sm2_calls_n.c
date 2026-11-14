/* SM2: short call sequences (object teardown, store-result wrappers, reset helpers). */
extern void ts4_destroy_owned_object(void *object);
extern double fn_8841DFD0(void *p);
extern void fn_886D5028(void *p);
extern void fn_886CECE0(void *p);
extern void fn_886C9688(void *p);
extern void fn_886C5C28(void *p);
extern void fn_88279F40(void *p, float a, float b);
extern void fn_88262730(void *p);
extern void *fn_886F3798(void *p);

void *ts4_store_double_result_8841E388(char *p, double *out)
{
    *out = fn_8841DFD0(*(void **)(p + 8));
    return p;
}
#define DESTROY_TWO(NAME, OFFA) \
    void NAME(char *p) \
    { \
        if (*(void **)(p + (OFFA))) ts4_destroy_owned_object(*(void **)(p + (OFFA))); \
        if (*(void **)p) ts4_destroy_owned_object(*(void **)p); \
    }
DESTROY_TWO(ts4_destroy_two_886DB4A0, 0x2c)
DESTROY_TWO(ts4_destroy_two_886CF178, 0xc)

void ts4_run_three_stages_886D50B8(void *p)
{
    fn_886D5028(p);
    fn_886CECE0(p);
    fn_886C9688(p);
}
void ts4_reset_owner_counter_886C7ED0(char *p)
{
    fn_886C5C28(*(char **)(p + 0x28) + 0x3f0);
    *(int *)(*(char **)(p + 0x28) + 0x544) = 0;
}
#define RESET_VIA_OWNER(NAME) \
    void NAME(char *p) \
    { \
        char *q = *(char **)(*(char **)(p + 4) + 0x60); \
        fn_886C5C28(*(char **)(q + 0x28) + 0x3f0); \
        *(int *)(*(char **)(q + 0x28) + 0x544) = 0; \
    }
RESET_VIA_OWNER(ts4_reset_via_owner_88671508)
RESET_VIA_OWNER(ts4_reset_via_owner_88671718)
RESET_VIA_OWNER(ts4_reset_via_owner_88671760)
void ts4_call_swapped_floats_8863B9A8(char *p, float a, float b)
{
    fn_88279F40(p + 0xc0, b, a);
    p[0x23c] = 1;
}
void ts4_call_swapped_floats_8863C5F0(char *p, float a, float b)
{
    char *q = *(char **)(p + 4);
    fn_88279F40(q + 0xc0, b, a);
    q[0x23c] = 1;
}
void ts4_clear_after_init_886D08B0(char *p)
{
    int z = 0;
    *(int *)(p + 0x14) = z;
    fn_88262730(p);
    *(int *)(p + 0x18) = z;
    *(int *)(p + 4) = z;
    *(int *)(p + 8) = z;
}
