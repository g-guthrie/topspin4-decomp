/* Loader_DLL.xex 0x830A08D0-0x830A4DC8, executable version 0.0.0.3. */
typedef unsigned int u32;
extern void ts4_tailcall_fn_833E74C0_833E1758(void *p);
extern void fn_830A50C0(void);
extern void *lbl_83544F68[];
extern volatile int lbl_83544FA8;

typedef struct Vec { char *first; char *last; char *end; } Vec;

void ts4l_vec_free_830A08D0(Vec *v)
{
    char *p = v->first;
    u32 n = v->end - p;
    void **fl;
    if (p) {
        if (n > 0x80) {
            ts4_tailcall_fn_833E74C0_833E1758(p);
        } else {
            fl = lbl_83544F68 + ((n - 1) >> 3);
            fn_830A50C0();
            *(void **)p = *fl;
            *fl = p;
            lbl_83544FA8 = 0;
        }
    }
}


void ts4l_vec_free_830A1D78(Vec *v)
{
    char *p = v->first;
    u32 n = v->end - p;
    void **fl;
    if (p) {
        if (n > 0x80) {
            ts4_tailcall_fn_833E74C0_833E1758(p);
        } else {
            fl = lbl_83544F68 + ((n - 1) >> 3);
            fn_830A50C0();
            *(void **)p = *fl;
            *fl = p;
            lbl_83544FA8 = 0;
        }
    }
}

void ts4l_vec_free_830A2520(Vec *v)
{
    char *p = v->first;
    u32 n = v->end - p;
    void **fl;
    if (p) {
        if (n > 0x80) {
            ts4_tailcall_fn_833E74C0_833E1758(p);
        } else {
            fl = lbl_83544F68 + ((n - 1) >> 3);
            fn_830A50C0();
            *(void **)p = *fl;
            *fl = p;
            lbl_83544FA8 = 0;
        }
    }
}

void ts4l_vec_free_830A2B80(Vec *v)
{
    char *p = v->first;
    u32 n = v->end - p;
    void **fl;
    if (p) {
        if (n > 0x80) {
            ts4_tailcall_fn_833E74C0_833E1758(p);
        } else {
            fl = lbl_83544F68 + ((n - 1) >> 3);
            fn_830A50C0();
            *(void **)p = *fl;
            *fl = p;
            lbl_83544FA8 = 0;
        }
    }
}

void ts4l_vec_free_830A3708(Vec *v)
{
    char *p = v->first;
    u32 n = v->end - p;
    void **fl;
    if (p) {
        if (n > 0x80) {
            ts4_tailcall_fn_833E74C0_833E1758(p);
        } else {
            fl = lbl_83544F68 + ((n - 1) >> 3);
            fn_830A50C0();
            *(void **)p = *fl;
            *fl = p;
            lbl_83544FA8 = 0;
        }
    }
}

void ts4l_vec_free_830A4DC8(Vec *v)
{
    char *p = v->first;
    u32 n = v->end - p;
    void **fl;
    if (p) {
        if (n > 0x80) {
            ts4_tailcall_fn_833E74C0_833E1758(p);
        } else {
            fl = lbl_83544F68 + ((n - 1) >> 3);
            fn_830A50C0();
            *(void **)p = *fl;
            *fl = p;
            lbl_83544FA8 = 0;
        }
    }
}

typedef struct VecI { int *first; int *last; int *end; } VecI;

void ts4l_vec_free_830A2128(VecI *v)
{
    int *p = v->first;
    u32 n;
    void **fl;
    if (p) {
        n = (v->end - p) * 4;
        if (n > 0x80) {
            ts4_tailcall_fn_833E74C0_833E1758(p);
        } else {
            fl = lbl_83544F68 + ((n - 1) >> 3);
            fn_830A50C0();
            *(void **)p = *fl;
            *fl = p;
            lbl_83544FA8 = 0;
        }
    }
}

void ts4l_vec_free_830A2868(VecI *v)
{
    int *p = v->first;
    u32 n;
    void **fl;
    if (p) {
        n = (v->end - p) * 4;
        if (n > 0x80) {
            ts4_tailcall_fn_833E74C0_833E1758(p);
        } else {
            fl = lbl_83544F68 + ((n - 1) >> 3);
            fn_830A50C0();
            *(void **)p = *fl;
            *fl = p;
            lbl_83544FA8 = 0;
        }
    }
}

void ts4l_vec_free_830A2D90(VecI *v)
{
    int *p = v->first;
    u32 n;
    void **fl;
    if (p) {
        n = (v->end - p) * 4;
        if (n > 0x80) {
            ts4_tailcall_fn_833E74C0_833E1758(p);
        } else {
            fl = lbl_83544F68 + ((n - 1) >> 3);
            fn_830A50C0();
            *(void **)p = *fl;
            *fl = p;
            lbl_83544FA8 = 0;
        }
    }
}
