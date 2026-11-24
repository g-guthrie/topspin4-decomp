/* 0x88516CD8: n choose k as fn_88516C28(n) / (fn_88516C28(n-k) * fn_88516C28(k)); the callee is a factorial table lookup */
/* Matched on  (agAH). Signed divide keeps the twllei/twi traps: /O2. */
int fn_88516C28(int n);
int fn_88516CD8(int n, int k)
{
    return fn_88516C28(n) / (fn_88516C28(n - k) * fn_88516C28(k));
}
