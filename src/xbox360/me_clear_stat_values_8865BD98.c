/* 0x8865BD98 (hand match): clear the four accumulated values of every 0x1c-byte entry in the
 * object's self-relative stats table. */
typedef struct Stat { char p[0xc]; float v[4]; } Stat;
typedef struct Table { int offset; int count; } Table;
typedef struct Obj { char p[0x30]; Table *stats; } Obj;
extern float g_ts4_event_value;
void ts4_clear_stat_values_8865BD98(Obj *o)
{
    Table * t = o->stats;
    float z = g_ts4_event_value;
    unsigned int i;
    int n = t->count;
    for (i = 0; i < n; i++) {
        Stat *__restrict s = (Stat *)((char *)t + (i * sizeof(Stat) + t->offset));
        s->v[0] = z;
        s->v[1] = z;
        s->v[2] = z;
        s->v[3] = z;
    }
}
