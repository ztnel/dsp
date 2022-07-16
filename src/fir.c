#include "fir.h"

static float FIR_IMPULSE_RESPONSE[FIR_FILTER_LENGTH] = {};

/**
 * @brief reset fir filter struct
 *
 * @param cbuf
 */
void fir_init(fir_cbuf_t *cbuf) {
  for (uint8_t i = 0; i < FIR_FILTER_LENGTH; i++) {
    cbuf->buf[cbuf->idx] = 0.0f;
  }
  cbuf->idx = 0;
}

/**
 * @brief Compute instantaneous filtered output
 *
 * @param cbuf fir circular buffer
 * @param sample input sample
 */
void fir_update(fir_cbuf_t *cbuf, float sample) {
  cbuf->buf[cbuf->idx] = sample;
  cbuf->idx++;
  if (cbuf->idx >= FIR_FILTER_LENGTH) {
    cbuf->idx = 0;
  }
}

/**
 * @brief Compute instantaneous filtered output
 *
 * @param cbuf fir circular buffer
 */
float fir_read(fir_cbuf_t *cbuf) {
  float fir_out = 0;
  uint8_t cum_idx = cbuf->idx;
  for (uint8_t i = 0; i < FIR_FILTER_LENGTH; i++) {
    // index for circular buffer
    cum_idx = cum_idx != 0 ? cum_idx - 1 : FIR_FILTER_LENGTH - 1;
    // apply convolution of impulse response and input buffer
    fir_out += FIR_IMPULSE_RESPONSE[i] * cbuf->buf[cum_idx];
  }
  return fir_out;
}