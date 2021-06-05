#define ETL_NO_STL 1

#include <stdbool.h>
#include <stdint.h>
#include "nrf_drv_timer.h"
#include "bsp.h"
#include "app_error.h"
#include "etl/array.h"
#include "pin.hpp"
#include "leds.hpp"
#include "display.hpp"




const nrf_drv_timer_t TIMER_LED = NRF_DRV_TIMER_INSTANCE(0);

static auto update_led_flag = false;

/**
 * @brief Handler for timer events.
 */
void timer_led_event_handler(nrf_timer_event_t event_type, void *p_context)
{
  static uint32_t i = 0;

  if (event_type != NRF_TIMER_EVENT_COMPARE0)
    return;

  update_led_flag = true;

  // Toggle on-board leds
  uint32_t led_to_invert = ((i++) % LEDS_NUMBER);
  bsp_board_led_invert(led_to_invert);
}

void timer_init(int time_ms)
{
  uint32_t err_code = NRF_SUCCESS;

  //Configure TIMER_LED for generating simple light effect - leds on board will invert his state one after the other.
  nrf_drv_timer_config_t timer_cfg = NRF_DRV_TIMER_DEFAULT_CONFIG;
  err_code = nrf_drv_timer_init(&TIMER_LED, &timer_cfg, timer_led_event_handler);
  APP_ERROR_CHECK(err_code);

  int time_ticks = nrf_drv_timer_ms_to_ticks(&TIMER_LED, time_ms);
  nrf_drv_timer_extended_compare(&TIMER_LED, NRF_TIMER_CC_CHANNEL0, time_ticks, NRF_TIMER_SHORT_COMPARE0_CLEAR_MASK, true);
  nrf_drv_timer_enable(&TIMER_LED);
}


int main(void)
{
  constexpr int blink_time = 1;
  static constexpr pattern_t pattern_sun = {0x91,0x42,0x18,0x3D,0xBC,0x18,0x42,0x89};

  bsp_board_init(BSP_INIT_LEDS);    //Configure all leds on board.
  leds::init();
  timer_init(blink_time);


  auto display = Display(pattern_sun);

  while (1)
  {
    __WFI();

    if (update_led_flag) {
      display.update();
      update_led_flag = false;  // Clear flag
    }
  }

}

/** @} */
