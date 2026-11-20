/* 0x88431250: walks the node list from n (next via ts4_get_u32_off4_8841EAD0) and stores in *found whether some node name (ts4_get_u32_off0_8841EAC8) compares equal to name with fn_884210E8 (strcmp); returns found. */
/* Matched on /Oc (agAF). A for loop with the strcmp test and break; the bool goes through the out pointer that is returned. */
typedef struct Node Node;
extern const char *ts4_get_u32_off0_8841EAC8(Node *n);
extern Node *ts4_get_u32_off4_8841EAD0(Node *n);
extern int fn_884210E8(const char *a, const char *b);
unsigned char *fn_88431250(unsigned char *found, Node *n, const char *name)
{
    for (; n; n = ts4_get_u32_off4_8841EAD0(n))
        if (fn_884210E8(ts4_get_u32_off0_8841EAC8(n), name) == 0)
            break;
    *found = n != 0;
    return found;
}
