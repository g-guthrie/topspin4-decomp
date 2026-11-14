/* Swing_DLL.xex 0x885A9A50-0x885A9AE4, executable version 0.0.0.3. */
/* COM-style QueryInterface: a 16-byte interface id compare, else defer to the base. */
extern "C" {
int memcmp(const void *a, const void *b, unsigned n);
#pragma intrinsic(memcmp)
extern unsigned char lbl_88091EE4[];
extern unsigned char lbl_88091EF4[];
extern unsigned char lbl_880917B8[];
int fn_88593E40(void *self, const unsigned char *iid, void **out);
int fn_884F9EC8(void *self, const unsigned char *iid, void **out);
}
struct Obj {
    virtual void s0();
    virtual void addref();
};
/* Swing_DLL.xex 0x885A9A50 */
extern "C" int ts4_query_interface_885A9A50(Obj *self, const unsigned char *iid, void **out)
{
    int result = 0;
    int same = memcmp(iid, lbl_88091EE4, 16) == 0;
    if (same) {
        void *sub = self ? (char *)self + 0x20 : 0;
        *out = sub;
        self->addref();
    } else {
        result = fn_884F9EC8(self, iid, out);
    }
    return result;
}
/* Swing_DLL.xex 0x885A7718 */
extern "C" int ts4_query_interface_885A7718(Obj *self, const unsigned char *iid, void **out)
{
    int result = 0;
    int same = memcmp(iid, lbl_88091EF4, 16) == 0;
    if (same) {
        void *sub = self ? (char *)self + 0x20 : 0;
        *out = sub;
        self->addref();
    } else {
        result = fn_884F9EC8(self, iid, out);
    }
    return result;
}
/* Swing_DLL.xex 0x88593F30 */
extern "C" int ts4_query_interface_88593F30(Obj *self, const unsigned char *iid, void **out)
{
    int result = 0;
    int same;
    if (out == 0) {
        result = (int)0x88960001;
    } else {
        *out = 0;
        same = memcmp(iid, lbl_880917B8, 16) == 0;
        if (same) {
            *out = self;
            self->addref();
        } else {
            result = fn_88593E40((char *)self + 8, iid, out);
        }
    }
    return result;
}
/* Swing_DLL.xex 0x885A6C48 */
extern "C" int ts4_query_interface_885A6C48(Obj *self, const unsigned char *iid, void **out)
{
    int result = 0;
    if (memcmp(iid, lbl_88091EF4, 16) == 0) {
        *out = self ? (char *)self + 0x20 : 0;
        self->addref();
    } else if (memcmp(iid, lbl_88091EE4, 16) == 0) {
        *out = self ? (char *)self + 0x24 : 0;
        self->addref();
    } else {
        result = fn_884F9EC8(self, iid, out);
    }
    return result;
}
