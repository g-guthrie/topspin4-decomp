/* 0x885DB700: null handle returns 8; otherwise clears three header words, resets the member at +8, then runs the handle teardown and returns 0 */
/* Matched on /Oc /Os (agAH).  */
typedef struct Hd { int a; int b; int lock[1]; int d; } Hd;
void ts4_if_get_u32_off0_885DBA68(int *lock);
void ts4_call_seq_u32_off0_885DBBB0(Hd **p);
int fn_885DB700(Hd **p)
{
    Hd *h;
    if (p == 0)
        return 8;
    h = *p;
    h->a = 0;
    h->d = 0;
    h->b = 0;
    ts4_if_get_u32_off0_885DBA68(h->lock);
    ts4_call_seq_u32_off0_885DBBB0(p);
    return 0;
}
