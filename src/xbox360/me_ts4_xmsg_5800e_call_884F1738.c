/* 0x884F1738: Builds a {user, 64-bit id, result = 0} message and sends it with XMsgInProcessCall(0xfc, 0x5800e, &msg, overlapped); returns msg.result. */
/* Matched on /Oc (agAH). Fields stored in source order; the result is read back from the message. */
extern int XMsgInProcessCall(unsigned int app, unsigned int msg, void *buf, void *overlapped);
typedef struct Msg5800E { unsigned int user; unsigned long long id; unsigned int result; } Msg5800E;
unsigned int fn_884F1738(unsigned int user, unsigned long long id, void *overlapped)
{
    Msg5800E m;
    m.user = user;
    m.id = id;
    m.result = 0;
    XMsgInProcessCall(0xfc, 0x5800e, &m, overlapped);
    return m.result;
}
