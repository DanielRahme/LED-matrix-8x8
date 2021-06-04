#define ETL_NO_STL 1

#include <stdbool.h>
#include <stdint.h>
#include "nrf_drv_timer.h"
#include "bsp.h"
#include "app_error.h"
#include "etl/array.h"
#include "pin.hpp"

const nrf_drv_timer_t TIMER_LED = NRF_DRV_TIMER_INSTANCE(0);

// Columns = x and Rows = y
static constexpr int x0_port = NRF_P1_BASE;
static constexpr int x1_port = NRF_P1_BASE;
static constexpr int x2_port = NRF_P1_BASE;
static constexpr int x3_port = NRF_P1_BASE;
static constexpr int x4_port = NRF_P1_BASE;
static constexpr int x5_port = NRF_P0_BASE;
static constexpr int x6_port = NRF_P0_BASE;
static constexpr int x7_port = NRF_P0_BASE;
static constexpr int y0_port = NRF_P1_BASE;
static constexpr int y1_port = NRF_P1_BASE;
static constexpr int y2_port = NRF_P1_BASE;
static constexpr int y3_port = NRF_P1_BASE;
static constexpr int y4_port = NRF_P1_BASE;
static constexpr int y5_port = NRF_P1_BASE;
static constexpr int y6_port = NRF_P1_BASE;
static constexpr int y7_port = NRF_P1_BASE;

static constexpr int x0_num = 11;
static constexpr int x1_num = 12;
static constexpr int x2_num = 13;
static constexpr int x3_num = 14;
static constexpr int x4_num = 15;
static constexpr int x5_num = 2;
static constexpr int x6_num = 26;
static constexpr int x7_num = 27;
static constexpr int y0_num = 10;
static constexpr int y1_num = 8;
static constexpr int y2_num = 7;
static constexpr int y3_num = 6;
static constexpr int y4_num = 5;
static constexpr int y5_num = 4;
static constexpr int y6_num = 3;
static constexpr int y7_num = 2;

static constexpr etl::array<Pin, 8> x_columns = {
    Pin(x0_port, x0_num, 0),
    Pin(x1_port, x1_num, 0),
    Pin(x2_port, x2_num, 0),
    Pin(x3_port, x3_num, 0),
    Pin(x4_port, x4_num, 0),
    Pin(x5_port, x5_num, 0),
    Pin(x6_port, x6_num, 0),
    Pin(x7_port, x7_num, 0)};

static constexpr etl::array<Pin, 8> y_rows = {
    Pin(y0_port, y0_num, 1),
    Pin(y1_port, y1_num, 1),
    Pin(y2_port, y2_num, 1),
    Pin(y3_port, y3_num, 1),
    Pin(y4_port, y4_num, 1),
    Pin(y5_port, y5_num, 1),
    Pin(y6_port, y6_num, 1),
    Pin(y7_port, y7_num, 1)};

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

void leds_init()
{
  // Init pins
  for (auto col : x_columns) col.init();
  for (auto row : y_rows) row.init();
  // Zero out pins
  for (auto col : x_columns) col.reset();
  for (auto row : y_rows) row.reset();
}

static void leds_test()
{
  for (auto y : y_rows) {
    y.set();

    // Set all columns, one-by-one
    for (auto x : x_columns) {
      x.set();
      for (volatile unsigned long long j = 0; j < 100000UL; ++j)
        ; // Delay
    }

    y.reset();
    for (auto col : x_columns)
      col.reset();    // Reset all columns
  }
}



int main(void)
{
  constexpr auto blink_time = 150;

  bsp_board_init(BSP_INIT_LEDS);    //Configure all leds on board.
  leds_init();
  timer_init(blink_time);

  while (1)
  {
    __WFI();
    leds_test();
  }
}

/** @} */
