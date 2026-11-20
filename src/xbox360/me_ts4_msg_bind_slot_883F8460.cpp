/* 0x883F8460: has the system (virtual slot 19) prepare the message at +0x10, points the object's bank slot at entry index*0x90 of the owner's (or its own) bank when message flag 4 is set, then sets or clears object flag 0x80000 from ts4_chk_empty_883E1890 */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); a and b are forwarded untouched in r4/r5, so the function takes them as parameters; C++ virtual call. */
struct Sys { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual int prepare(int a, int b, void *m); };
extern "C" Sys *lbl_88CAC988;
struct Bank { char pad[0x40]; char *slots; };
struct Owner { char pad[0xA8]; Bank *bank; };
struct Lnk { Owner *owner; };
struct Obj { char pad[0x60]; unsigned int flags; char p64[0xA8 - 0x64]; Bank *bank; Lnk *link; };
struct D2 { int p0; int index; };
struct D1 { char pad[0xC]; D2 *d; };
struct D0 { char pad[0xC]; D1 *d; };
struct Msg { char pad[0x14]; D0 *d; char p18[0x24 - 0x18]; unsigned int flags; };
struct T { int p0; Obj *obj; char p8[8]; Msg *msg; };
extern "C" unsigned char ts4_chk_empty_883E1890(Msg *m);
extern "C" int ts4_msg_bind_slot_883F8460(T *t, int a, int b)
{
    int r;
    r = lbl_88CAC988->prepare(a, b, t->msg);
    if (r) return r;
    if (t->msg->flags & 4) {
        Bank *src = (t->obj->link ? t->obj->link->owner : 0) ? (t->obj->link ? t->obj->link->owner : 0)->bank : t->obj->bank;
        t->obj->bank->slots = src->slots + t->msg->d->d->d->index * 0x90;
    }
    if (ts4_chk_empty_883E1890(t->msg))
        t->obj->flags |= 0x80000;
    else
        t->obj->flags &= ~0x80000;
    return 0;
}
