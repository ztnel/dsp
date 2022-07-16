#ifndef FIR_H_
#define FIR_H_

#include <stdint.h>

#define FIR_FILTER_LENGTH 16

/**
 * @brief Circular buffer for fir filter
 *
 */
typedef struct fir_cbuf_t {
  float buf[FIR_FILTER_LENGTH];  // buffer array
  uint32_t idx;                  // buffer index (struct padded)
} fir_cbuf_t;

void fir_init(fir_cbuf_t *cbuf);
void fir_update(fir_cbuf_t *cbuf, float input);
float fir_read(fir_cbuf_t *cbuf);

#endif  // FIR_H_