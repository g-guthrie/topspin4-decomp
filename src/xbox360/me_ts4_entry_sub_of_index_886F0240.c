/* 0x886F0240: returns fn_886EE988(&table[i]+0x40) for 0x120-byte entries of lbl_88D45AD4->+0x2C->+0x24, or 0 for i == -1. */
/* Matched on /Oc (agAB). Array base hoisted into a local gives the offset-first add. */
typedef struct E { char p[0x120]; } E;
typedef struct S8 { char p[0x24]; E *arr; } S8;
typedef struct G { char p[0x2c]; S8 *s; } G;
extern G *lbl_88D45AD4;
int fn_886EE988(void *p);
int fn_886F0240(int i)
{
    E *e;
    if (i == -1)
        return 0;
    e = lbl_88D45AD4->s->arr;
    return fn_886EE988(e[i].p + 0x40);
}
