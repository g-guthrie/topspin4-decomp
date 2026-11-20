/* 0x88479FB8: Sends the event to the bindings in reverse order (handler vt slot 3 with the dispatcher area, binding arg, context and event) until one marks it handled. ctx defaults to the owner context. */
/* Matched on /Oc (agAH). Plain reverse loop. */
typedef struct Event { int type; unsigned char handled; } Event;
typedef struct Handler Handler;
typedef struct HandlerVt { void *s[3]; void (*handle)(Handler *, void *self_area, void *arg, void *ctx, Event *ev); } HandlerVt;
struct Handler { HandlerVt *vt; };
typedef struct Binding { Handler *handler; void *arg; } Binding;
typedef struct Owner { char p0[0x6c]; void *ctx; } Owner;
typedef struct Dispatcher { char p0[8]; Owner *owner; char pc[4]; char area[0x140]; Binding *bindings; int count; } Dispatcher;
void fn_88479FB8(Dispatcher *d, Event *ev, void *ctx)
{
    int i;
    if (ctx == 0)
        ctx = d->owner->ctx;
    for (i = d->count - 1; i >= 0; i--) {
        Binding *b = &d->bindings[i];
        b->handler->vt->handle(b->handler, d->area, b->arg, ctx, ev);
        if (ev->handled)
            break;
    }
}
