/* WIP (not compiled, not checked): Swing_DLL.xex 0x888F8158, 0x15f4 bytes. Full analysis in
 * work/q5/notes/888f8158.md; this file only fixes the structure for the next instance. */
#if 0
void fn_888F8158(Self *self, Ts4Handle16 handle)
{
    Q5Str name; int min_ver = 100; Iter it_c0; Ref cur;
    fn_88627EC0(self, handle);
    /* name, self->ref34, min_ver: see notes */
    fn_8860FF08(&it_c0, &handle);
    cur = forward_cached(&it_c0);
    while (live(&cur)) {
        Iter it; Ref c; u8 enabled = 1;
        fn_8860FF08(&it, &cur);
        c = forward_cached(&it);
        /* optional leading 0x86cd48ff enable child (fn_88923530/fn_886328B0) */
        if (enabled) {
            while (live(&c)) {
                /* version 0x9bd0be71 >= min_ver -> build Rec (fn_888DF7B0), fill fields, push_back self+0x1c, destroy */
                c = iter_next(&it);
            }
        }
        cur = iter_next(&it_c0);
    }
    ts4_destroy_owned_object(name.begin);
}
#endif
