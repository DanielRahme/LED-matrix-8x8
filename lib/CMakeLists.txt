
add_library(led
            animations.c
            led.c
            led_hw.c
            patterns.c
)

target_include_directories(led PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../include")

set_property(TARGET led PROPERTY C_STANDARD 99)
target_compile_options(led PRIVATE -Werror -Wall -Wextra -Wshadow -pedantic)
