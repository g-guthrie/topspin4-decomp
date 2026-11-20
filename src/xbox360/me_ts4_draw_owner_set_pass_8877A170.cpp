/* Swing_DLL.xex 0x8877A170: point a draw request at the chosen pass and its source texture. */
struct Ts4Key { unsigned int v; Ts4Key() {} Ts4Key(unsigned int x) : v(x) {} };
struct Ts4DrawReq { Ts4Key source; Ts4Key pass; char pad[1]; unsigned char dirty; };
struct Ts4TexRef { char pad[0xc]; Ts4Key key; };
struct Ts4Globals { char pad[0x27c]; Ts4Key default_tex; };
extern "C" Ts4Globals *lbl_88D45B1C;
struct Ts4DrawOwner { char pad[0x28]; Ts4DrawReq *req; Ts4TexRef *tex; char p30[0x94]; unsigned char locked; };
extern "C" void ts4_draw_owner_set_pass_8877A170(Ts4DrawOwner *o, bool alt)
{
    o->req->pass = alt ? Ts4Key(0xA0BDE62E) : Ts4Key(0x9C1C9375);
    o->req->source = (int)o->tex != 0 /* signed compare in the target (cmpwi) */ ? Ts4Key(o->tex->key) : Ts4Key(lbl_88D45B1C->default_tex);
    if (!o->locked) o->req->dirty = 1;
}
