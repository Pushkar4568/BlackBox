#ifndef WATERLVL_H_
#define WATERLVL_H_

#include <stdint.h>

// Function prototype for water level sensor (ADC to percentage)
float WaterLevel_Percent(uint16_t adc_val);

#endif /* WATERLVL_H_ */

