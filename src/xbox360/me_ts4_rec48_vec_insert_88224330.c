/* Swing_DLL.xex 0x88224330: vector<48-byte record>::insert(where, val): constructs at end or shifts up with copy_backward, else _Insert_n; returns begin + offset.
 * /Oc. Element copy-construct ts4_get_u32_off0_88224E60, copy_backward fn_8823E390, assign ts4_get_u8_offc_88224F10, _Insert_n(v, where, val, 1) ts4_vector_realloc_insert_88227480. */
typedef struct Rec48 { unsigned int w[12]; } Rec48;
typedef struct Rec48Vec { Rec48 *first; Rec48 *last; void *alloc; Rec48 *end; } Rec48Vec;
void ts4_get_u32_off0_88224E60(Rec48 *dest, const Rec48 *src);
void fn_8823E390(Rec48 *first, Rec48 *last, Rec48 *dest_end);
void ts4_get_u8_offc_88224F10(Rec48 *dest, const Rec48 *src);
void ts4_vector_realloc_insert_88227480(Rec48Vec *v, Rec48 *where, const Rec48 *val, unsigned int count);

static __inline void construct(Rec48 *p, const Rec48 *val)
{
    if (p) ts4_get_u32_off0_88224E60(p, val);
}

Rec48 *fn_88224330(Rec48Vec *v, Rec48 *where, const Rec48 *val)
{
    int off = where - v->first;
    if (v->last != v->end) {
        if (where == v->last) {
            construct(v->last, val);
            v->last++;
        } else {
            Rec48 tmp;
            construct(v->last, v->last - 1);
            v->last++;
            ts4_get_u32_off0_88224E60(&tmp, val);
            fn_8823E390(where, v->last - 2, v->last - 1);
            ts4_get_u8_offc_88224F10(where, &tmp);
        }
    } else {
        ts4_vector_realloc_insert_88227480(v, where, val, 1);
    }
    return v->first + off;
}
