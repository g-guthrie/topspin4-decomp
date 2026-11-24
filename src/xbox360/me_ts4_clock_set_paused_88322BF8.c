/* Swing_DLL.xex 0x88322BF8: nested pause/resume of a clock: the first pause stamps pausedAt (+0x8) and the last resume stamps
 * resumedAt (+0xC) and adds the gap to pausedTotal (+0x2C); records the flag at +0x28. agAE: /Oc. */
typedef struct Clock {
    char pad[8]; unsigned int pausedAt; unsigned int resumedAt; char pad10[0x28 - 0x10]; unsigned char paused; char pad29[3];
    unsigned int pausedTotal; int pauseDepth; unsigned char enabled;
} Clock;
void fn_8831A830(unsigned int *now);
int fn_88322BF8(Clock *c, unsigned char pause)
{
    if (c->enabled) {
        if (pause) {
            if (c->pauseDepth == 0) fn_8831A830(&c->pausedAt);
            c->pauseDepth++;
        } else if (--c->pauseDepth == 0) {
            fn_8831A830(&c->resumedAt);
            if (c->resumedAt > c->pausedAt) c->pausedTotal += c->resumedAt - c->pausedAt;
        }
        c->paused = pause;
    }
    return 0;
}
