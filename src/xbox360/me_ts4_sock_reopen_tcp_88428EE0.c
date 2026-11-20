/* 0x88428EE0: Calls the object virtual at slot 4 (close), opens a new socket(2, 1, 0) (AF_INET, SOCK_STREAM), stores the handle at +0x20 and returns 1 when it is -1 (failure), else 0. */
/* Matched on /Oc (agAH). Comparison written unsigned against 0xFFFFFFFF to get the li -1 / subf / cntlzw form; int == -1 compiles to addi/cntlzw. */
typedef struct Sock Sock;
typedef struct SockVtbl { void *slot0[4]; void (*close)(Sock *s); } SockVtbl;
struct Sock { SockVtbl *vtable; char pad4[0x1c]; int handle; };
int ts4_tailcall_NetDll_socket_884F0240(int af, int type, int protocol);
int fn_88428EE0(Sock *s)
{
    int h;
    s->vtable->close(s);
    h = ts4_tailcall_NetDll_socket_884F0240(2, 1, 0);
    s->handle = h;
    return (unsigned int)h == 0xFFFFFFFF;
}
