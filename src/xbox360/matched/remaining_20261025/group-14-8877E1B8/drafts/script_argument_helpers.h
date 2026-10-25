/*
 * Provisional guest declarations for independently checked exact-code units.
 * Type roles, layouts and signatures remain inferred, not original ABI proof.
 * This header carries no separate function or behavior credit; each unit
 * manifest pins its complete source/header dependency closure.
 */
#ifndef TS4_DRAFT_SCRIPT_ARGUMENT_HELPERS_H
#define TS4_DRAFT_SCRIPT_ARGUMENT_HELPERS_H

#include "../script_context.h"

typedef unsigned char ts4_u8;
typedef unsigned short ts4_u16;
typedef unsigned int ts4_u32;
typedef int ts4_s32;
typedef long long ts4_s64;

#define TS4_SCRIPT_VALUE_STRIDE 0x38u

extern struct TS4ScriptValue *g_ts4_default_script_value;
extern double g_ts4_script_constants[];

/* A2 hypothesis: upstream's matched idiom (tsu_read_stats_by_rank.c, tsu_friends_leaderboard.h):
 * count is a volatile field, and the first argument's test reads it through a non-volatile cast. */
static struct TS4ScriptValue *ts4_script_argument(struct TS4ScriptContext *context, ts4_u32 index)
{
    if (index == 0 ? *(ts4_u32 *)&context->arguments->count > 0 : *(volatile ts4_u32 *)&context->arguments->count > index) {
        return (struct TS4ScriptValue *)((ts4_u8 *)context->arguments->first_value + index * TS4_SCRIPT_VALUE_STRIDE);
    }
    return g_ts4_default_script_value;
}

static double ts4_script_number(const struct TS4ScriptValue *value)
{
    if (value->type == TS4_SCRIPT_VALUE_NUMBER) {
        return value->value.number;
    }
    if (value->type == TS4_SCRIPT_VALUE_INTEGER) {
        return (double)value->value.integer;
    }
    return g_ts4_script_constants[11];
}

/* fctiwz */
static ts4_s32 ts4_script_number_to_s32(double number)
{
    return (ts4_s32)number;
}

/* fctidz, then the low word: MSVC's direct double -> unsigned int conversion
 * (U hypothesis: no intermediate 64-bit integer in the source). */
static ts4_u32 ts4_script_number_to_low_word(double number)
{
    return (ts4_u32)number;
}

static const char *ts4_script_text(const struct TS4ScriptValue *value)
{
    return *(const char *const *)value->payload;
}

#endif
