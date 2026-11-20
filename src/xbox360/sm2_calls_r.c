/* SM2: wrapper storing a float result (callee returns float here, double in sm2_calls_n.c). */
extern float fn_8841DFD0(void *p);

void *ts4_store_float_result_8841E340(char *p, float *out)
{
    *out = fn_8841DFD0(*(void **)(p + 8));
    return p;
}
