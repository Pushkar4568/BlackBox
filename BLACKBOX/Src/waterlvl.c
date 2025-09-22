#define VREF     3.3f
#define ADC_RES  4095.0f

float WaterLevel_Percent(int adc_val) {
    // Convert ADC to voltage
    float voltage = ((float)adc_val / ADC_RES) * VREF;

    // Normalize to percentage (0% = dry, 100% = fully submerged)
    float percent = (voltage / VREF) * 100.0f;

    if (percent < 0.0f) percent = 0.0f;
    if (percent > 100.0f) percent = 100.0f;

    return percent;
}
