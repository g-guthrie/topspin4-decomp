/* 0x882E2570: handle API: with a handle (~node) asks fn_882E1F88(node, key, 1), else fn_882E2308(ctx, key, &out); returns ~result or 0 on failure */
/* Matched on /O1 plain and LTCG (agT, v.py chk). */
int fn_882E2308(void *ctx, void *key, unsigned long *out);
unsigned long fn_882E1F88(unsigned long node, void *key, int create);
unsigned long ts4_lookup_or_create_handle_882E2570(void *ctx, unsigned long handle, void *key)
{
    unsigned long out;
    if (!handle) {
        if (fn_882E2308(ctx, key, &out) < 0)
            return 0;
    } else {
        out = fn_882E1F88(~handle, key, 1);
        if (!out)
            return 0;
    }
    return ~out;
}
