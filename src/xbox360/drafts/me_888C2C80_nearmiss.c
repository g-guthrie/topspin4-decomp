/* 0x888C2C80: clears the flag byte (+0x54) and resets the weight (+0x74) to g_ts4_event_value on the node at +0x1C and on each 0x84-byte child of its vector (+0x84/+0x88). */
/* Near miss (agAB, /Oc): 2 off, the node's flag store is scheduled after the begin/end loads in the target. Store and
 * load order permutations of the five statements tried; locals for end and the constant are needed for the rest. */
typedef struct E { char p[0x54]; unsigned char on; char p55[0x74 - 0x55]; float w; char p78[0x84 - 0x78]; } E;
typedef struct N { E e; E *begin; E *end; } N;
typedef struct T { char p[0x1c]; N *n; } T;
extern float g_ts4_event_value;
void ts4_timed_tree_reset_888C2C80(T *t)
{
    N *n = t->n;
    E *e, *end;
    float z;
    if (!n)
        return;
    n->e.on = 0;
    e = n->begin;
    end = n->end;
    z = g_ts4_event_value;
    n->e.w = z;
    for (; e != end; e++) {
        e->w = z;
        e->on = 0;
    }
}
