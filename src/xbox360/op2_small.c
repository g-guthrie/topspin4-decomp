/* OP2: operand-order near misses closed by local-symbol numbering. */
typedef unsigned int u32;
typedef unsigned char u8;

struct op2_rec { int rel; u32 pad0; u32 type; u32 key; u8 pad1[1]; u8 flag; u8 pad2[2]; };
struct op2_hdr { int off; int count; };

void ts4_set_rec_value_88840F30(struct op2_hdr *self, u32 key, u32 value)
{
    int i;
    int n = self->count;
    for (i = 0; i < n; i++) {
        int off = self->off;
        int idx = i * 0x14;
        struct op2_rec *e = (struct op2_rec *)((char *)self + (idx + off));
        if (e->key == key) {
            if (e->type == 0x89616A1A) {
                e->flag = 1;
                *(u32 *)((char *)e + e->rel) = value;
            }
            return;
        }
    }
}
