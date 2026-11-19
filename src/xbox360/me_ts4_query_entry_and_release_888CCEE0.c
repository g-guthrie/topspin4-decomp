/* 0x888CCEE0: fills a zeroed 24-byte query result for id through fn_888CCCC8. On success it passes the result
 * handle (+0x14) to ts4_if_get_u32_off5c_888CCBE8 and returns 1; otherwise it returns 0.
 * Write the six zero stores one by one: an '= {0}' initialiser gives a different sequence. */
typedef unsigned char u8;
typedef struct { int w[5]; void *handle; } Ts4QueryResult;
u8 fn_888CCCC8(void *o, unsigned int id, Ts4QueryResult *out);
void ts4_if_get_u32_off5c_888CCBE8(void *h);
u8 ts4_query_entry_and_release_888CCEE0(void *o, unsigned int id)
{
    Ts4QueryResult r;
    u8 ok = 0;
    r.w[0] = 0; r.w[1] = 0; r.w[2] = 0; r.w[3] = 0; r.w[4] = 0; r.handle = 0;
    if (fn_888CCCC8(o, id, &r)) {
        ok = 1;
        ts4_if_get_u32_off5c_888CCBE8(r.handle);
    }
    return ok;
}
