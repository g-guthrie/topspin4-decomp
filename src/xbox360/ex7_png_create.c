/* Derived from libpng 1.2.x (libpng license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX7: libpng png_create_write_struct / png_create_read_struct. They use the real setjmp (placeholder setjmp -> setjmp). */

#include "ex7_png.h"

void *fn_882EC0E0(int type);                                         /* png_create_struct */
int _setjmp(void *env);
void fn_882EC1E0(ex7_png_struct *png_ptr, void *ptr);                /* png_free */
void ts4_call_with_tag_if_nonnull_882EC158(ex7_png_struct *png_ptr);                           /* png_destroy_struct */
void ts4_set_u32_off548_882E26D8(ex7_png_struct *png_ptr, void *error_ptr, void *error_fn, void *warning_fn);
void fn_882E26E8(ex7_png_struct *png_ptr, const char *message);
void *ts4_if_call_seq_fn_88888668_882EC170(ex7_png_struct *png_ptr, unsigned int size);
void ts4_if_call_seq_u32_off550_882E71D8(ex7_png_struct *png_ptr, void *io_ptr, void *write_fn, void *flush_fn);
void fn_882E6D60(ex7_png_struct *png_ptr, int heuristic_method, int num_weights, const double *filter_weights,
                 const double *filter_costs);
extern const char lbl_880097B0[];

/* Allocate a write struct, install the setjmp error handler and the deflate buffer (libpng png_create_write_struct). Swing_DLL.xex 0x882E7000 */
ex7_png_struct *ex7_png_create_write_struct_882E7000(const char *user_png_ver, void *error_ptr, void *error_fn, void *warning_fn)
{
    ex7_png_struct *png_ptr;

    png_ptr = (ex7_png_struct *)fn_882EC0E0(1);
    if (png_ptr == 0)
        return 0;
    if (_setjmp(png_ptr->jmpbuf)) {
        fn_882EC1E0(png_ptr, png_ptr->zbuf);
        ts4_call_with_tag_if_nonnull_882EC158(png_ptr);
        return 0;
    }
    ts4_set_u32_off548_882E26D8(png_ptr, error_ptr, error_fn, warning_fn);
    if (user_png_ver == 0 || user_png_ver[0] != '1')
        fn_882E26E8(png_ptr, lbl_880097B0);
    png_ptr->zbuf_size = 0x2000;
    png_ptr->zbuf = (unsigned char *)ts4_if_call_seq_fn_88888668_882EC170(png_ptr, 0x2000);
    ts4_if_call_seq_u32_off550_882E71D8(png_ptr, 0, 0, 0);
    fn_882E6D60(png_ptr, 0, 1, 0, 0);
    return png_ptr;
}

void *fn_882EC0E0(int type);                                         /* png_create_struct */
int _setjmp(void *env);                                              /* setjmp */
void fn_882EC1E0(ex7_png_struct *png_ptr, void *ptr);                /* png_free */
void ts4_call_with_tag_if_nonnull_882EC158(ex7_png_struct *png_ptr);                           /* png_destroy_struct */
void ts4_set_u32_off548_882E26D8(ex7_png_struct *png_ptr, void *error_ptr, void *error_fn, void *warning_fn);
void fn_882E26E8(ex7_png_struct *png_ptr, const char *message);
void *ts4_if_call_seq_fn_88888668_882EC170(ex7_png_struct *png_ptr, unsigned int size);
void fn_882E2848(void);                                              /* png_zalloc */
void ts4_forward_882E28B8(ex7_png_struct *png_ptr, void *ptr);       /* png_zfree */
int ts4_tailcall_fn_882F3010_882F3168(ex7_z_stream *strm, const char *version, int stream_size); /* inflateInit_ */
void ts4_if_call_seq_u32_off54c_882EA0C0(ex7_png_struct *png_ptr, void *io_ptr, void *read_data_fn);
extern const char lbl_880097B0[];
extern const char lbl_880DD1EC[]; /* ZLIB_VERSION */
extern const char lbl_8800995C[]; /* zlib version error */
extern const char lbl_88009970[]; /* zlib memory error */
extern const char lbl_88009984[]; /* unknown zlib error */

/* Allocate a read struct, install the setjmp error handler and initialise zlib inflate (libpng png_create_read_struct). Swing_DLL.xex 0x882E7470 */
ex7_png_struct *ex7_png_create_read_struct_882E7470(const char *user_png_ver, void *error_ptr, void *error_fn, void *warning_fn)
{
    ex7_png_struct *png_ptr;
    int ret;

    png_ptr = (ex7_png_struct *)fn_882EC0E0(1);
    if (png_ptr == 0)
        return 0;
    if (_setjmp(png_ptr->jmpbuf)) {
        fn_882EC1E0(png_ptr, png_ptr->zbuf);
        ts4_call_with_tag_if_nonnull_882EC158(png_ptr);
        return 0;
    }
    ts4_set_u32_off548_882E26D8(png_ptr, error_ptr, error_fn, warning_fn);
    if (user_png_ver == 0 || user_png_ver[0] != '1')
        fn_882E26E8(png_ptr, lbl_880097B0);
    png_ptr->zbuf_size = 0x2000;
    png_ptr->zbuf = (unsigned char *)ts4_if_call_seq_fn_88888668_882EC170(png_ptr, 0x2000);
    png_ptr->zstream.zalloc = (void *)fn_882E2848;
    png_ptr->zstream.zfree = (void *)ts4_forward_882E28B8;
    png_ptr->zstream.opaque = png_ptr;
    ret = ts4_tailcall_fn_882F3010_882F3168(&png_ptr->zstream, lbl_880DD1EC, 0x38);
    switch (ret) {
    case -6:
        fn_882E26E8(png_ptr, lbl_8800995C);
        break;
    case -4:
    case -2:
        fn_882E26E8(png_ptr, lbl_88009970);
        break;
    case 0:
        break;
    default:
        fn_882E26E8(png_ptr, lbl_88009984);
        break;
    }
    png_ptr->zstream.next_out = png_ptr->zbuf;
    png_ptr->zstream.avail_out = png_ptr->zbuf_size;
    ts4_if_call_seq_u32_off54c_882EA0C0(png_ptr, 0, 0);
    return png_ptr;
}
