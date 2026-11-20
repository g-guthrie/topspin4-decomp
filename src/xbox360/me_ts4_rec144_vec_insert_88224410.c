/* Swing_DLL.xex 0x88224410: vector<144-byte record>::insert(where, val): constructs at end or shifts up with copy_backward, else _Insert_n; returns begin + offset.
 * /Oc. Sibling of 88224330: construct ts4_get_u32_off0_88224FB0, copy_backward fn_8823E6E0, assign ts4_get_u8_off18_88225150, _Insert_n(v, where, val, 1) ts4_vector_realloc_insert_88227608. */
typedef struct Rec144 { unsigned int w[36]; } Rec144;
typedef struct Rec144Vec { Rec144 *first; Rec144 *last; void *alloc; Rec144 *end; } Rec144Vec;
void ts4_get_u32_off0_88224FB0(Rec144 *dest, const Rec144 *src);
void fn_8823E6E0(Rec144 *first, Rec144 *last, Rec144 *dest_end);
void ts4_get_u8_off18_88225150(Rec144 *dest, const Rec144 *src);
void ts4_vector_realloc_insert_88227608(Rec144Vec *v, Rec144 *where, const Rec144 *val, unsigned int count);

static __inline void construct(Rec144 *p, const Rec144 *val)
{
    if (p) ts4_get_u32_off0_88224FB0(p, val);
}

Rec144 *fn_88224410(Rec144Vec *v, Rec144 *where, const Rec144 *val)
{
    int off = where - v->first;
    if (v->last != v->end) {
        if (where == v->last) {
            construct(v->last, val);
            v->last++;
        } else {
            Rec144 tmp;
            construct(v->last, v->last - 1);
            v->last++;
            ts4_get_u32_off0_88224FB0(&tmp, val);
            fn_8823E6E0(where, v->last - 2, v->last - 1);
            ts4_get_u8_off18_88225150(where, &tmp);
        }
    } else {
        ts4_vector_realloc_insert_88227608(v, where, val, 1);
    }
    return v->first + off;
}
