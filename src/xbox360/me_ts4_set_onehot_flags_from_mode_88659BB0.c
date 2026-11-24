/* Swing_DLL.xex 0x88659BB0: sets three one-hot flag bytes (+2/+3/+4) of the
 * object at +0x20 from the mode (1..3) held at (+0x28)->+8; mode 0 or >3 leaves them.
 * The original config split this function at 0x88659C24 (inside case 3). */
struct ts4_onehot_flags { char pad[2]; unsigned char first, second, third; };
struct ts4_mode_holder { char pad[8]; unsigned int mode; };
struct ts4_onehot_owner { char pad[0x20]; struct ts4_onehot_flags *flags; char pad2[4]; struct ts4_mode_holder *mode; };
void ts4_set_onehot_flags_from_mode(struct ts4_onehot_owner *o)
{
    switch (o->mode->mode) {
    case 0: return;
    case 1: o->flags->first = 1; o->flags->second = 0; o->flags->third = 0; return;
    case 2: o->flags->first = 0; o->flags->second = 1; o->flags->third = 0; return;
    case 3: o->flags->first = 0; o->flags->second = 0; o->flags->third = 1; return;
    }
}
