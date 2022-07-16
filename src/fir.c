#include "fir.h"

static float FIR_IMPULSE_RESPONSE[FIR_FILTER_LENGTH] = {};

/**
 * @brief reset fir filter struct
 *
 * @param fir
 */
void fir_init(fir_filter_t *fir) {
  for (uint8_t i = 0; i < FIR_FILTER_LENGTH; i++) {
    fir->buf[fir->idx] = 0.0f;
  }
  fir->idx = 0;
  fir->out = 0.0f;
}

/**
 * @brief Compute instantaneous filtered output
 *
 * @param fir
 * @param input
 * @return float
 */
float fir_update(fir_filter_t *fir, float input) {
  fir->buf[fir->idx] = input;
  fir->idx++;
  if (fir->idx >= FIR_FILTER_LENGTH) {
    fir->idx = 0;
  }
  fir->out = 0.0f;
  // implement convolution of filter against input to get a filtered output
  uint8_t sum_idx = fir->idx;
  for (uint8_t i = 0; i < FIR_FILTER_LENGTH; i++) {
    // circular buffer logic
    if (sum_idx > 0) {
      sum_idx--;
    } else {
      sum_idx = FIR_FILTER_LENGTH - 1;
    }
    fir->out += FIR_IMPULSE_RESPONSE[i] * fir->buf[sum_idx];
  }
  return fir->out;
}