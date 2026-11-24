/* Constructor of the class with vtable lbl_880D2A0C (5 slots). The base-class
 * constructors write the zeroed words more than once, and the target keeps
 * those redundant stores. The +0x4C0 handle comes from session slot 14.
 * Matched byte-exact on the LTCG route (/Oc, pool primer context). */

typedef unsigned int ts4_u32;
typedef unsigned char ts4_u8;

struct TS4GlueSession {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13();
    virtual ts4_u32 acquire_handle(ts4_u32 a, ts4_u32 b); /* slot 14, +0x38 */
};
extern "C" TS4GlueSession *g_ts4_session_context;

struct TS4GluePair {
    ts4_u32 a; /* +0x4 in the derived layout */
    ts4_u32 b; /* +0x8 */
    TS4GluePair() { a = 0; b = 0; }
};
struct TS4GlueObjBase : TS4GluePair {
    ts4_u32 c; /* +0xC */
    TS4GlueObjBase() { a = 0; b = 0; c = 0; }
    virtual void m0();
};
struct TS4Obj880D2A0C : TS4GlueObjBase {
    ts4_u8 pad10[0x4c0 - 0x10];
    ts4_u32 handle; /* +0x4C0 */
    TS4Obj880D2A0C();
    virtual void m0();
};

/* 0x88934788 */
TS4Obj880D2A0C::TS4Obj880D2A0C() : handle(0)
{
    handle = g_ts4_session_context->acquire_handle(0, 0);
}
