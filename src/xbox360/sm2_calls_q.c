/* SM2: wrappers around out-of-line helpers with stack temporaries and virtual calls. */
extern double fn_8841DFD0(void *p);
extern void fn_8858BE70(void *p);
extern void fn_8858C0C8(void *p);
extern void fn_88406238();
extern int fn_886EBCE8(int v);
extern void fn_8860DCF8(void *self, int a, int b, int c);
extern void ts4_swing_anim_register_node_types_886D75B8(const char *names);
extern void fn_881B9148(void *p);
extern int fn_885BDF00(int a, int b);
extern char lbl_880C8F91[];

void *ts4_init_header_88583068(void *unused, int a, int *p)
{
        p[0] = 0x76c3f250;
    p[1] = 1;
    p[2] = a;
    fn_8858BE70(unused);
    return p;
}
void *ts4_init_header_88583138(void *unused, int a, int *p)
{
    p[0] = 0x76c3f251;
    p[1] = 1;
    p[2] = a;
    fn_8858C0C8(unused);
    return p;
}
void ts4_call_with_short_ptr_88408240(void *self, int a, short s, int c)
{
    fn_88406238(self, 1, &s, a, 0, 0, 0, c);
}
void ts4_call_with_short_ptr_88408280(void *self, int a, short s, int c)
{
    fn_88406238(self, 0, 0, 0, 1, &s, a, c);
}
void ts4_init_anim_node_886DACA8(char *p)
{
    ts4_swing_anim_register_node_types_886D75B8(lbl_880C8F91);
    p[8] = 0;
    fn_881B9148(p + 0x10);
}
