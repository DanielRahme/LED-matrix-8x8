#define ETL_NO_STL 1

#include <stdbool.h>
#include <stdint.h>
#include "nrf_drv_timer.h"
#include "bsp.h"
#include "app_error.h"
#include "etl/array.h"
#include "pin.hpp"
#include "leds.hpp"

const nrf_drv_timer_t TIMER_LED = NRF_DRV_TIMER_INSTANCE(0);


/**
 * @brief Handler for timer events.
 */
void timer_led_event_handler(nrf_timer_event_t event_type, void *p_context)
{
  static uint32_t i = 0;

  if (event_type != NRF_TIMER_EVENT_COMPARE0)
    return;

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
  constexpr auto blink_time = 150;

  bsp_board_init(BSP_INIT_LEDS);    //Configure all leds on board.
  leds::init();
  timer_init(blink_time);

  while (1)
  {
    __WFI();
    leds::test();
  }
}

/** @} */
