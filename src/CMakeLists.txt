
add_executable(led_demo main.c)
set_property(TARGET led_demo PROPERTY C_STANDARD 99)
target_compile_options(led_demo PRIVATE -Werror -Wall -Wextra -Wshadow -pedantic)

target_link_libraries(led_demo PRIVATE led)
