/* 0x8857AFB0: Calls fn_88584548(obj, (unsigned char)flag) and returns 0xc0 when it returns 0xc0, else 0. */
/* Matched on /Oc /Os (agAH). Built /Os. The int parameter narrowed at the call gives the clrlwi r4,r4,24; the ternary gives the subic/subfe/and mask. */
int fn_88584548(void *obj, unsigned char flag);
int fn_8857AFB0(void *obj, int flag)
{
    return fn_88584548(obj, (unsigned char)flag) == 0xc0 ? 0xc0 : 0;
}
