/* 0x886A0188: scans the pending entries of a 20-slot ring queue (oldest first). The newest entry
 * flagged "urgent" wins; otherwise the oldest entry flagged "ready" is used. The chosen entry is handed
 * to the handler's dispatcher, whose result is returned; 0 when the queue is empty or nothing qualifies. */
typedef struct QEntry { char p[0x2c]; unsigned char urgent; unsigned char ready; char p2[0x30 - 0x2e]; } QEntry;
typedef struct Handler { char p[0x60]; void *dispatcher; } Handler;
typedef struct Queue { char p[0x10]; unsigned int head; int count; Handler *handler; char p2[0x5c - 0x1c]; QEntry slots[20]; } Queue;
int fn_886D1C70(void *dispatcher, QEntry *e);
int ts4_dispatch_queued_entry_886A0188(Queue *q)
{
    unsigned int i, end;
    int last;
    int r = 0;
    if (q->count != 0) {
        end = q->head + q->count;
        last = -1;
        for (i = q->head; i < end; i++)
            if (q->slots[i % 20].urgent) last = i;
        if (last != -1) {
            r = fn_886D1C70(q->handler->dispatcher, &q->slots[last % 20]);
        } else {
            for (i = q->head; i < end; i++) {
                QEntry *e = &q->slots[i % 20];
                if (e->ready) { r = fn_886D1C70(q->handler->dispatcher, e); break; }
            }
        }
    }
    return r;
}
