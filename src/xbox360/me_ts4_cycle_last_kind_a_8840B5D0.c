/* 0x8840B5D0: returns 4 when position is the last step of its period, else 3 */
/* Matched on  (agAH). Unsigned %% keeps twllei: /O2. */
typedef struct Cyc { char pad[0x28]; unsigned int period; } Cyc;
void fn_8840B4B8(Cyc *c, int arg, unsigned int *pos, unsigned int *aux);
int fn_8840B5D0(Cyc *c, int arg)
{
    unsigned int pos, aux;
    fn_8840B4B8(c, arg, &pos, &aux);
    return (pos % c->period + 1 == c->period) + 3;
}
