/* Top Spin 4 (Xbox 360, Swing_DLL.xex) 0x887ED280: submit a job: run it now (887EC7A0) when nothing is pending and it is not queued; otherwise queue
 * it once on the +0x58 vector (grow through 88174A38 when full).
 * Body unchanged from the equivalent-tier source named below (Q5S sweep, 2026-11-24): byte-exact now, see
 * work/specs/Q5S/sweep_887ED280.json for route and flags. */
/* from eq_q5a_gameplay_small_j.c */
typedef struct Q5Job Q5Job;
struct Q5Job { char pad[0xc]; void *pending; unsigned char queued; };
typedef struct Q5JobVec { Q5Job **first; Q5Job **last; Q5Job **end; } Q5JobVec;
typedef struct Q5JobQueue { char pad[0x58]; Q5JobVec queue; } Q5JobQueue;
extern void fn_887EC7A0(Q5JobQueue *self, Q5Job *job);
extern void ts4_vector_grow_append_scalar4_88174A38(Q5JobVec *v, Q5Job **where, Q5Job **val);

static void q5_job_push(Q5JobVec *v, Q5Job **val)
{
    if (v->last != v->end) {
        if (v->last)
            *v->last = *val;
        v->last++;
    } else {
        ts4_vector_grow_append_scalar4_88174A38(v, v->last, val);
    }
}

void ts4_job_submit_887ED280(Q5JobQueue *self, Q5Job *job)
{
    if (job->pending == 0 && !job->queued) {
        fn_887EC7A0(self, job);
        return;
    }
    if (!job->queued) {
        job->queued = 1;
        q5_job_push(&self->queue, &job);
    }
}
