/* Family JT: first function containing an MSVC switch jump table.
 *
 * ts4_state_flag_8865DA28 reads a state index at +0x10 and answers a boolean for it.
 * The 23-entry jump table sits in .text right after the bctr; cases 0, 1, 7,
 * 8, 12, 13 and 19 return 1. Cases 2-6, 9-11, 14-18 and 20-22 are explicit
 * and return 0, and an index above 22 falls out of the switch and returns 0
 * as well (the compiler answers that with a bare bgtlr).
 */
int ts4_state_flag_8865DA28(const char *object)
{
    int result = 0;

    switch (*(const unsigned int *)(object + 0x10)) {
    case 0:
    case 1:
    case 7:
    case 8:
    case 12:
    case 13:
    case 19:
        result = 1;
        break;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 9:
    case 10:
    case 11:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 20:
    case 21:
    case 22:
        result = 0;
        break;
    }
    return result;
}
