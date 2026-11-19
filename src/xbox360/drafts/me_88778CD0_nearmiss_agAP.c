/* agAP near miss (3 off, /Oc and LTCG ctx=[]): target 0x88778CD0 loads the byte into r9 and
 * computes cntlzw into r8; every form tried (C ==0, !x, u8 return, C++ bool, inline, local int)
 * uses r10/r9. Behaviour: returns 1 when the flag byte lbl_88C46F42 is zero. */
extern unsigned char lbl_88C46F42;
int flag_clear_88778CD0(void) { return lbl_88C46F42 == 0; }
