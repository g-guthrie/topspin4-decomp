/* Derived from libpng 1.2.x (libpng license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family PNG2: libpng pngwrite.c png_set_filter_heuristics (1.0.x-era code, /O1). */

#include "png2_png.h"

#define PNG2_FILTER_HEURISTIC_DEFAULT 0
#define PNG2_FILTER_HEURISTIC_UNWEIGHTED 1
#define PNG2_FILTER_HEURISTIC_LAST 3
#define PNG2_FILTER_VALUE_LAST 5
#define PNG2_WEIGHT_FACTOR 256
#define PNG2_COST_FACTOR 8

void ts4_if_get_u32_off544_882E2720(png2_png_struct *png_ptr, const char *message);  /* png_warning */
void *ts4_if_call_seq_fn_88888668_882EC170(png2_png_struct *png_ptr, unsigned int size); /* png_malloc */
extern const char lbl_88009790[]; /* "Unknown filter heuristic method" */
extern const double lbl_88007B20; /* 0.5 */
extern const double lbl_880038D8; /* 0.0 */
#ifdef _MSC_VER
#pragma const_seg(".png2wf1")
#endif
static const double lbl_88009788 = 256.0; /* PNG_WEIGHT_FACTOR */
#ifdef _MSC_VER
#pragma const_seg(".png2wf2")
#endif
static const double lbl_880038D0 = 1.0;
#ifdef _MSC_VER
#pragma const_seg(".png2wf3")
#endif
static const double lbl_88009780 = 8.0; /* PNG_COST_FACTOR */
#ifdef _MSC_VER
#pragma const_seg()
#endif

/* Configure the weighted filter-selection heuristic: per-history-entry weights and per-filter costs,
 * stored as 8.8 and 13.3 fixed-point factors and their inverses (libpng png_set_filter_heuristics).
 * Swing_DLL.xex 0x882E6D60 */
void png2_png_set_filter_heuristics_882E6D60(png2_png_struct *png_ptr, int heuristic_method, int num_weights,
                                             const double *filter_weights, const double *filter_costs)
{
    int i;
    double half, zero;

    if (heuristic_method >= PNG2_FILTER_HEURISTIC_LAST) {
        ts4_if_get_u32_off544_882E2720(png_ptr, lbl_88009790);
        return;
    }
    if (heuristic_method == PNG2_FILTER_HEURISTIC_DEFAULT)
        heuristic_method = PNG2_FILTER_HEURISTIC_UNWEIGHTED;
    if (num_weights < 0 || filter_weights == 0 || heuristic_method == PNG2_FILTER_HEURISTIC_UNWEIGHTED)
        num_weights = 0;

    png_ptr->num_prev_filters = (unsigned char)num_weights;
    png_ptr->heuristic_method = (unsigned char)heuristic_method;
    half = lbl_88007B20;
    zero = lbl_880038D8;

    if (num_weights > 0) {
        if (png_ptr->prev_filters == 0) {
            png_ptr->prev_filters = (unsigned char *)ts4_if_call_seq_fn_88888668_882EC170(png_ptr, num_weights);
            for (i = 0; i < num_weights; i++)
                png_ptr->prev_filters[i] = 255;
        }
        if (png_ptr->filter_weights == 0) {
            png_ptr->filter_weights = (unsigned short *)ts4_if_call_seq_fn_88888668_882EC170(png_ptr, sizeof(unsigned short) * num_weights);
            png_ptr->inv_filter_weights = (unsigned short *)ts4_if_call_seq_fn_88888668_882EC170(png_ptr, sizeof(unsigned short) * num_weights);
            for (i = 0; i < num_weights; i++)
                png_ptr->inv_filter_weights[i] = png_ptr->filter_weights[i] = PNG2_WEIGHT_FACTOR;
        }
        for (i = 0; i < num_weights; i++) {
            if (filter_weights[i] < zero) {
                png_ptr->inv_filter_weights[i] = png_ptr->filter_weights[i] = PNG2_WEIGHT_FACTOR;
            } else {
                png_ptr->inv_filter_weights[i] = (unsigned short)(lbl_88009788 * filter_weights[i] + half);
                png_ptr->filter_weights[i] = (unsigned short)(lbl_88009788 / filter_weights[i] + half);
            }
        }
    }

    if (png_ptr->filter_costs == 0) {
        png_ptr->filter_costs = (unsigned short *)ts4_if_call_seq_fn_88888668_882EC170(png_ptr, sizeof(unsigned short) * PNG2_FILTER_VALUE_LAST);
        png_ptr->inv_filter_costs = (unsigned short *)ts4_if_call_seq_fn_88888668_882EC170(png_ptr, sizeof(unsigned short) * PNG2_FILTER_VALUE_LAST);
        for (i = 0; i < PNG2_FILTER_VALUE_LAST; i++)
            png_ptr->inv_filter_costs[i] = png_ptr->filter_costs[i] = PNG2_COST_FACTOR;
    }
    for (i = 0; i < PNG2_FILTER_VALUE_LAST; i++) {
        if (filter_costs == 0 || filter_costs[i] < zero) {
            png_ptr->inv_filter_costs[i] = png_ptr->filter_costs[i] = PNG2_COST_FACTOR;
        } else if (filter_costs[i] >= lbl_880038D0) {
            png_ptr->inv_filter_costs[i] = (unsigned short)(lbl_88009780 / filter_costs[i] + half);
            png_ptr->filter_costs[i] = (unsigned short)(lbl_88009780 * filter_costs[i] + half);
        }
    }
}
