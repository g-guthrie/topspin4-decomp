/* 0x885B7388: for a null or -2 (current) handle, true when unowned or owned by the current caller from fn_8857C8C8 */
/* Matched on /Oc /Os (agAH). Handle is a pointer, so ==0 is cmplwi; -2 compare signed. */
typedef struct Own { char pad[0x14]; void *owner; } Own;
void *fn_8857C8C8(void);
int fn_885B7388(Own *o, void *who)
{
    if (who == 0 || who == (void *)-2) {
        if (o->owner == 0 || fn_8857C8C8() == o->owner)
            return 1;
    }
    return 0;
}
