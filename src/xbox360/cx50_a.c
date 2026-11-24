/* CX50: static initialisers, Swing_DLL.xex 0x889D2B00-0x889D2BC8. */
typedef unsigned long ts4_word;
extern char lbl_88C6C028[];
extern char lbl_88C6C038[];
extern char lbl_88C6C048[];
extern char lbl_88C6C050[];
extern char lbl_88D48810[];
extern char lbl_88D48820[];
extern char lbl_88D48828[];
extern char lbl_88D48838[];

#define S(sym, off) (*(ts4_word *)((char *)(sym) + (off)))
#define VS(sym, off) (*(volatile ts4_word *)((char *)(sym) + (off)))

/* 0x889D2B00 */
void ts4_cx50_copy4_889D2B00(void)
{
    S(lbl_88D48810, 0) = S(lbl_88C6C028, -12);
    S(lbl_88D48810, 4) = S(lbl_88C6C028, -8);
    S(lbl_88D48810, 8) = S(lbl_88C6C028, -4);
    VS(lbl_88D48810, 12) = S(lbl_88C6C028, 0);
}

/* 0x889D2B38 */
void ts4_cx50_copy2_889D2B38(void)
{
    S(lbl_88D48820, 0) = S(lbl_88C6C050, -4);
    VS(lbl_88D48820, 4) = S(lbl_88C6C050, 0);
}

/* 0x889D2B60 */
void ts4_cx50_copy4_889D2B60(void)
{
    S(lbl_88D48828, 0) = S(lbl_88C6C038, -12);
    S(lbl_88D48828, 4) = S(lbl_88C6C038, -8);
    S(lbl_88D48828, 8) = S(lbl_88C6C038, -4);
    VS(lbl_88D48828, 12) = S(lbl_88C6C038, 0);
}

/* 0x889D2B98 */
void ts4_cx50_copy4_889D2B98(void)
{
    S(lbl_88D48838, 0) = S(lbl_88C6C048, -12);
    S(lbl_88D48838, 4) = S(lbl_88C6C048, -8);
    S(lbl_88D48838, 8) = S(lbl_88C6C048, -4);
    VS(lbl_88D48838, 12) = S(lbl_88C6C048, 0);
}
