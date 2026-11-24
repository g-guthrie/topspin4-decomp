/* 0x88954A38: marks the request pending, optionally locks it, resolves its id with fn_88942DA8 and returns fn_889546A8 of the result (0 when nothing is found) */
/* Matched on /Oc (agAH). A result local set to 0 first and assigned inside 'if (res)' gives the saved li r29,0 path. */
typedef struct Req { char p[0x10]; int id; unsigned char pending; } Req;
typedef struct Res Res;
extern void fn_889518A0(Req *r);
extern Res *fn_88942DA8(Req *r, int id);
extern void fn_889517E0(Res *r);
extern void *fn_889546A8(Res *r);
void *fn_88954A38(void *self, Req *req, unsigned char lock)
{
    void *r = 0;
    Res *res;
    req->pending = 1;
    if (lock)
        fn_889518A0(req);
    res = fn_88942DA8(req, req->id);
    if (res) {
        if (lock)
            fn_889517E0(res);
        r = fn_889546A8(res);
    }
    return r;
}
