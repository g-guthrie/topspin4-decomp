/* CW3 core helpers: range find and uninitialized-copy loops (Swing_DLL.xex) */
typedef unsigned int u32;
typedef unsigned char u8;
void ts4_call_seq_u32_off0_8815ED78(void *, void *);
void ts4_assign_formatted_text(void *, int);
void fn_88166BC0(void *, void *);

/* Swing_DLL.xex 0x88166548: uninitialized copy of 0x54-byte elements */
char *cw3_uninit_copy_84_88166548(char *first, char *last, char *dst) {
  for (; first != last; first += 0x54, dst += 0x54) {
    if (dst) {
      ts4_call_seq_u32_off0_8815ED78(dst, first);
      ts4_assign_formatted_text(dst + 0x30, *(int *)(first + 0x30));
      ts4_assign_formatted_text(dst + 0x3c, *(int *)(first + 0x3c));
      *(float *)(dst + 0x48) = *(float *)(first + 0x48);
      *(int *)(dst + 0x4c) = *(int *)(first + 0x4c);
      *(int *)(dst + 0x50) = *(int *)(first + 0x50);
    }
  }
  return dst;
}
/* Swing_DLL.xex 0x881668A8: uninitialized copy of 0x28-byte elements */
char *cw3_uninit_copy_40_881668A8(char *first, char *last, char *dst) {
  for (; first != last; first += 0x28, dst += 0x28) {
    if (dst) {
      *(int *)dst = *(int *)first;
      *(int *)(dst + 4) = *(int *)(first + 4);
      *(int *)(dst + 8) = *(int *)(first + 8);
      *(int *)(dst + 0xc) = *(int *)(first + 0xc);
      *(int *)(dst + 0x10) = *(int *)(first + 0x10);
      *(u8 *)(dst + 0x14) = *(u8 *)(first + 0x14);
      *(int *)(dst + 0x18) = *(int *)(first + 0x18);
      fn_88166BC0(dst + 0x1c, first + 0x1c);
    }
  }
  return dst;
}

/* Swing_DLL.xex 0x881655A0: find an int in [first,last); returns match or last */
int *cw3_find_int_881655A0(int *first, int *last, const int *val) {
  int n = (last - first) >> 2;
  for (; n > 0; --n) {
    if (*first == *val) return first;
    ++first;
    if (*first == *val) return first;
    ++first;
    if (*first == *val) return first;
    ++first;
    if (*first == *val) return first;
    ++first;
  }
  switch (last - first) {
  case 3: if (*first == *val) return first; ++first;
  case 2: if (*first == *val) return first; ++first;
  case 1: if (*first == *val) return first; ++first;
  case 0:
  default: break;
  }
  return last;
}
