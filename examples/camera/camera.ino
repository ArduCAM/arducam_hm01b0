#include "arducam_hm01b0.h"

uint8_t image_data[96 * 96];
struct arducam_config config;
uint8_t header[2] = {0x55, 0xAA};

void setup() {
  Serial1.begin(921600);
  pinMode(LED_BUILTIN, OUTPUT);
  // put your setup code here, to run once:
  config.sccb            = i2c0;
  config.sccb_mode       = I2C_MODE_16_8;
  config.sensor_address  = 0x24;
  config.pin_sioc        = PIN_CAM_SIOC;
  config.pin_siod        = PIN_CAM_SIOD;
  config.pin_resetb      = PIN_CAM_RESETB;
  config.pin_xclk        = PIN_CAM_XCLK;
  config.pin_vsync       = PIN_CAM_VSYNC;
  config.pin_y2_pio_base = PIN_CAM_Y2_PIO_BASE;
  config.pio             = pio0;
  config.pio_sm          = 0;
  config.dma_channel     = 0;
  arducam_init(&config);

}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)

  arducam_capture_frame(&config, image_data);
  Serial1.write(header, 2);
  Serial1.write(image_data, 96 * 96);

  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
}
