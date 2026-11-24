/* Near-miss (agAP), 0x886FCC50, plain /Oc: 2 off. The target computes the != 0 into r11 and adds a final clrlwi r3,r11,24; this form writes the result straight into r3. */
typedef struct Req { unsigned int a; char p4[4]; unsigned int b; } Req;
typedef struct T { char p[0x14]; void *m14; char p18[4]; Req *req; } T;
typedef struct S { char p[0x34]; T *t; unsigned int m38; unsigned int m3c; } S;
extern "C" unsigned char ts4_loop_get_u32_off44_886FCB88(S *s, unsigned int a, unsigned int b);
extern "C" bool ts4_consume_pending_request_886FCC50(S *s){ T *t = s->t; bool r = false; if (t && t->m14 && t->req) { s->m3c = s->m38; r = (bool)ts4_loop_get_u32_off44_886FCB88(s, t->req->a, t->req->b); t->req = 0; } return r; }