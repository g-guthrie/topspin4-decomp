/* Family SWB2 (jump-table switch). */
unsigned short fn_885677C0(int ch);
int ts4_ctype_table_test_88569800(int value, int mask);

int ts4_match_flag_char_8882EED0(int value, int ch)
{
    switch (fn_885677C0(ch)) {
    case 'a': value = ts4_ctype_table_test_88569800(value, 0x103); break;
    case 'c': value = ts4_ctype_table_test_88569800(value, 0x20); break;
    case 'd': value = ts4_ctype_table_test_88569800(value, 4); break;
    case 'l': value = ts4_ctype_table_test_88569800(value, 2); break;
    case 'p': value = ts4_ctype_table_test_88569800(value, 0x10); break;
    case 's': value = ts4_ctype_table_test_88569800(value, 8); break;
    case 'u': value = ts4_ctype_table_test_88569800(value, 1); break;
    case 'w': value = ts4_ctype_table_test_88569800(value, 0x107); break;
    case 'x': value = ts4_ctype_table_test_88569800(value, 0x80); break;
    case 'z': value = ((unsigned short)value == 0); break;
    default:
        return (unsigned short)ch == (unsigned short)value;
    }
    if (ts4_ctype_table_test_88569800(ch, 2) != 0)
        return value;
    return value == 0;
}
