/* Loader_DLL.xex 0x8314A988-0x8314A9F0, executable version 0.0.0.3. */

void fn_831556C0();

typedef struct ts4l_run_state {
    char p[0x9c];
    int state;
    int flag;
} ts4l_run_state;

/* Leave the running state (1 -> 0); invokes a callback if no flag is set. */
int ts4l_run_state_stop_8314A988(ts4l_run_state *s)
{
    int z;
    if (s->state != 1) return 0x8000ffff;
    z = 0;
    s->state = z;
    if (s->flag == 0) fn_831556C0();
    s->flag = z;
    return 0;
}
