/* NEAR MISS 0x8865BE68: 47 off (0xec vs 0xf4): target hoists all phase/paused loads before the divide and emits subf x-K for the hash compares; 5 variants. */
typedef unsigned int u32;
extern u32 ts4_get_u32__imp_KeTimeStampBundle_8857B830(void);

#define TS4_STATE_PLAYING 0x165BBDE9u

typedef struct Session { char p[0xd4]; unsigned char paused; char q[0x35c - 0xd5]; u32 played_secs; u32 start_ms; } Session;
typedef struct Phase { char p[0x1c0]; u32 cur; u32 prev; u32 next; } Phase;
typedef struct PhaseOwner { char p[0x38]; Phase *phase; } PhaseOwner;
typedef struct Stats { char p[0x68]; u32 live_secs; } Stats;
typedef struct Timer { char p[0x20]; Session *s; char q[4]; Stats *stats; char r[8]; PhaseOwner *po; } Timer;

/* 0x8865BE68: play-time bookkeeping: start the clock when entering play, bank the seconds when play ends, else publish the live total. */
void ts4_session_play_clock_8865BE68(Timer *t)
{
    u32 start = t->s->start_ms;
    u32 now = ts4_get_u32__imp_KeTimeStampBundle_8857B830();
    Phase *ph = t->po->phase;
    Session *s = t->s;
    u32 secs = (now - start) / 1000;
    unsigned char cur_playing = ph->cur == TS4_STATE_PLAYING;
    unsigned char paused = s->paused;
    unsigned char next_playing = ph->next == TS4_STATE_PLAYING;
    if (start) {
        if (!cur_playing) {
            if (ph->prev == TS4_STATE_PLAYING) {
                s->played_secs += secs;
                t->s->start_ms = cur_playing;
            } else if (!cur_playing && !paused) {
                t->stats->live_secs = s->played_secs + secs;
            }
        }
    } else if (next_playing) {
        s->start_ms = now;
    }
}
