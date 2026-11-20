/* Loader_DLL.xex 0x83123348-0x83123CF0, executable version 0.0.0.3. */
#ifdef _MSC_VER
#define TS4L_NOINLINE __declspec(noinline)
#else
#define TS4L_NOINLINE
#endif

/* Message header initialiser: zero a 5-word header, then tag it with a type and id. */
typedef struct ts4l_hdr { int w[5]; } ts4l_hdr;
TS4L_NOINLINE static void ts4_set_u32_off0_831230F0(void *m, int id)
{
    volatile ts4l_hdr *h = (volatile ts4l_hdr *)m;
    h->w[0] = 0; h->w[1] = 0; h->w[2] = 0; h->w[3] = 0; h->w[4] = 0;
    h->w[0] = 20; h->w[1] = id;
}

void ts4l_msg_ctor_0_83123348(void *m, int v)
{
    ts4_set_u32_off0_831230F0(m, 0);
    ((int *)m)[4] = v;
    ((int *)m)[3] = 20;
}

void ts4l_msg_ctor_1_83123380(void *m, int v)
{
    ts4_set_u32_off0_831230F0(m, 1);
    ((int *)m)[4] = v;
    ((int *)m)[3] = 20;
}

extern void *fn_83123118(void *m, void *buf, int n);
extern float lbl_83000A00[];

typedef struct Ts4lPayloadC { int a, b, c, d; float e; } Ts4lPayloadC;

void ts4l_msg_ctor_2015_83123CF0(void *m, Ts4lPayloadC *buf, int a, int b, int c)
{
    ts4_set_u32_off0_831230F0(m, 2015);
    fn_83123118(m, buf, 0x28);
    buf->a = a;
    buf->b = b;
    buf->c = c;
    buf->e = lbl_83000A00[0];
}
