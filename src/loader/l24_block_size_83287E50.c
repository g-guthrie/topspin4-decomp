/* Loader_DLL.xex 0x83287E50-0x8328A108, executable version 0.0.0.3. */

typedef struct ts4l_blkhdr {
    int w0, w4, count_a, stride, w10, count_b, w18, w1c, rows;
} ts4l_blkhdr;

/* Byte size of a block: fixed header words plus rows * stride; 0 for a null block. */
int ts4l_block_size_83287E50(ts4l_blkhdr *h)
{
    int r = 0;
    if (h) r = (h->count_b + h->count_a + 10) * 4 + h->rows * h->stride;
    return r;
}

/* Byte size of a block: fixed header words plus rows * stride; 0 for a null block. */
int ts4l_block_size_83288550(ts4l_blkhdr *h)
{
    int r = 0;
    if (h) r = (h->count_b + h->count_a + 10) * 4 + h->rows * h->stride;
    return r;
}

/* Byte size of a block: fixed header words plus rows * stride; 0 for a null block. */
int ts4l_block_size_83288C58(ts4l_blkhdr *h)
{
    int r = 0;
    if (h) r = (h->count_b + h->count_a + 10) * 4 + h->rows * h->stride;
    return r;
}

/* Byte size of a block: fixed header words plus rows * stride; 0 for a null block. */
int ts4l_block_size_83289338(ts4l_blkhdr *h)
{
    int r = 0;
    if (h) r = (h->count_b + h->count_a + 10) * 4 + h->rows * h->stride;
    return r;
}

/* Byte size of a block: fixed header words plus rows * stride; 0 for a null block. */
int ts4l_block_size_83289A20(ts4l_blkhdr *h)
{
    int r = 0;
    if (h) r = (h->count_b + h->count_a + 10) * 4 + h->rows * h->stride;
    return r;
}

/* Byte size of a block: fixed header words plus rows * stride; 0 for a null block. */
int ts4l_block_size_8328A108(ts4l_blkhdr *h)
{
    int r = 0;
    if (h) r = (h->count_b + h->count_a + 10) * 4 + h->rows * h->stride;
    return r;
}

