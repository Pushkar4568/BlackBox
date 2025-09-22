#include <math.h>
#include <stdio.h>

#define VREF     3.3f       // ADC reference voltage
#define ADC_RES  4095.0f    // 12-bit ADC
#define RL       10000.0f   // 10 kΩ load resistor
#define RO       20000.0f   // Calibrated Ro in clean air (you must calibrate!)
#define A        99.042f    // Curve constant (example for CO)
#define B        -1.518f    // Curve exponent (example for CO)

float MQ7_PPM_OP(int adc_val) {
    // Convert ADC reading to voltage
    float voltage = ((float)adc_val / ADC_RES) * VREF;
    if (voltage <= 0.01f) return 0.0f;  // safeguard

    // Calculate sensor resistance Rs
    float Rs = RL * (VREF - voltage) / voltage;
    if (Rs <= 0.0f) return 0.0f;        // safeguard

    // Rs/Ro ratio
    float ratio = Rs / RO;
    if (ratio <= 0.0f) return 0.0f;     // safeguard

    // Compute CO concentration in ppm
    float ppm = A * powf(ratio, B);
    if (!isfinite(ppm) || ppm < 0.0f) return 0.0f;

    return ppm;
}
