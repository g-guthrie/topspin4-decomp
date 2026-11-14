/* Family SWB2 (jump-table switch). */
#ifdef _MSC_VER
typedef unsigned int swb_uptr;
#else
typedef unsigned long swb_uptr;
#endif
void fn_88423660(void *ctx, unsigned int a, unsigned int b);

void ts4_walk_format_tokens_885EE0D8(const unsigned int *start, const unsigned int *end, void *ctx)
{
    const unsigned int *p = start;
    while (p < end) {
        unsigned int tok = *p;
        if (tok >= 10) {
            fn_88423660(ctx, tok, tok);
            switch (*(const unsigned char *)(swb_uptr)*p) {
            case 0x45: case 0x53: case 0x54: case 0x6c:
                p += 3;
                break;
            case 0x4c:
                fn_88423660(ctx, p[3], p[3]);
                p += 4;
                break;
            case 0x4d:
                p += 2;
                break;
            case 0x4e: case 0x50: case 0x70:
                p += 1;
                break;
            default:
                return;
            }
        } else {
            p += 1;
        }
    }
}
