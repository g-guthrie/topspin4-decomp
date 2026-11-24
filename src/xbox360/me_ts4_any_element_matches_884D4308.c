/* Swing_DLL.xex 0x884D4308: walks n elements of type at data (stride ts4_get_u32_off8_8841EF28(type)) and returns 1 as soon as
 * fn_884D44A8(element, type, arg) returns 1, else 0. agO: plain and LTCG. */
int ts4_get_u32_off8_8841EF28(void *type);
int fn_884D44A8(char *elem, void *type, void *arg);

int fn_884D4308(char *data, int n, void *type, void *arg)
{
    int i;
    int stride = ts4_get_u32_off8_8841EF28(type);
    for (i = 0; i < n; i++) {
        if (fn_884D44A8(data + i * stride, type, arg) == 1)
            return 1;
    }
    return 0;
}
