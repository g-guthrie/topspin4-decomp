/* Loader_DLL.xex 0x8313F3F8-0x8313F480, executable version 0.0.0.3. */
#ifdef _MSC_VER
#define TS4L_NOINLINE __declspec(noinline)
#else
#define TS4L_NOINLINE
#endif

/* Message header initialiser: zero a 5-word header, then tag it with a type and id. */
typedef struct ts4l_hdr { int w[5]; } ts4l_hdr;
TS4L_NOINLINE static void ts4_set_u32_off0_8313F348(void *m, int id)
{
    volatile ts4l_hdr *h = (volatile ts4l_hdr *)m;
    h->w[0] = 0; h->w[1] = 0; h->w[2] = 0; h->w[3] = 0; h->w[4] = 0;
    h->w[0] = 20; h->w[1] = id;
}
extern void *fn_8313F370(void *m, void *buf, int n);

typedef struct ts4l_msg_8313F3F8 { float f0; } ts4l_msg_8313F3F8;
void ts4l_msg_ctor_2042_8313F3F8(void *m, ts4l_msg_8313F3F8 *buf, float f1)
{
    ts4_set_u32_off0_8313F348(m, 2042);
    fn_8313F370(m, buf, 4);
    buf->f0 = f1;
}

typedef struct ts4l_msg_8313F480 { int f0; } ts4l_msg_8313F480;
void ts4l_msg_ctor_2045_8313F480(void *m, ts4l_msg_8313F480 *buf, int a5)
{
    ts4_set_u32_off0_8313F348(m, 2045);
    fn_8313F370(m, buf, 4);
    buf->f0 = a5;
}

