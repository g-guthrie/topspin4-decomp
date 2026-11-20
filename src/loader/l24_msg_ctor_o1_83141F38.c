/* Loader_DLL.xex 0x83141FC0-0x83141FC0, executable version 0.0.0.3. */
#ifdef _MSC_VER
#define TS4L_NOINLINE __declspec(noinline)
#else
#define TS4L_NOINLINE
#endif

/* Message header initialiser: zero a 5-word header, then tag it with a type and id. */
typedef struct ts4l_hdr { int w[5]; } ts4l_hdr;
TS4L_NOINLINE static void ts4_set_u32_off0_83141F38(void *m, int id)
{
    volatile ts4l_hdr *h = (volatile ts4l_hdr *)m;
    h->w[0] = 0; h->w[1] = 0; h->w[2] = 0; h->w[3] = 0; h->w[4] = 0;
    h->w[0] = 20; h->w[1] = id;
}
extern void *fn_83141F60(void *m, void *buf, int n);

typedef struct ts4l_msg_83141FC0 { int f0; } ts4l_msg_83141FC0;
void ts4l_msg_ctor_24_83141FC0(void *m, ts4l_msg_83141FC0 *buf)
{
    ts4_set_u32_off0_83141F38(m, 24);
    fn_83141F60(m, buf, 4);
    buf->f0 = 0;
}

