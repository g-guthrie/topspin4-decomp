/* Swing_DLL.xex band3 constructors with a 12-byte by-value argument and a named registration call, executable version 0.0.0.3. */
struct TS4Triple {
    unsigned int first;
    unsigned int second;
    unsigned int third;
};
void *fn_88627EC0(void *object, struct TS4Triple value);
void fn_88707908(struct TS4Triple value);
void fn_88890140(void *object);
void fn_889139A0(void *object);
extern char lbl_880C8F25[];
void ts4_keyed_items_register_all_8869C9E8(char *name);
extern char lbl_880C8F37[];
void ts4_swing_anim_register_node_types_886D75B8(char *name);
extern char lbl_880C963A[];
void ts4_name_keys_register_887FB3B0(char *name);
extern char lbl_880CF0C7[];
void fn_88918EA8(char *name);
extern char lbl_880CFC4F[];
void fn_889298D8(char *name);

void ts4_construct_registered_886AA698(void *self, struct TS4Triple value)
{
    fn_88627EC0(self, value);
    ts4_keyed_items_register_all_8869C9E8(lbl_880C8F25);
}

void ts4_construct_registered_886DACF0(void *self, struct TS4Triple value)
{
    fn_88627EC0(self, value);
    ts4_swing_anim_register_node_types_886D75B8(lbl_880C8F37);
}

void ts4_construct_registered_887FC790(void *self, struct TS4Triple value)
{
    fn_88627EC0(self, value);
    ts4_name_keys_register_887FB3B0(lbl_880C963A);
}

void ts4_construct_registered_8891FFA0(void *self, struct TS4Triple value)
{
    fn_88627EC0(self, value);
    fn_88918EA8(lbl_880CF0C7);
}

void ts4_construct_registered_8892B650(void *self, struct TS4Triple value)
{
    fn_88627EC0(self, value);
    fn_889298D8(lbl_880CFC4F);
}

void ts4_construct_then_88890210(void *self, struct TS4Triple value)
{
    fn_88890140(fn_88627EC0(self, value));
}

void ts4_construct_then_88913BA8(void *self, struct TS4Triple value)
{
    fn_889139A0(fn_88627EC0(self, value));
}

void ts4_forward_triple_skip_self_88713770(void *self, struct TS4Triple value)
{
    (void)self;
    fn_88707908(value);
}
