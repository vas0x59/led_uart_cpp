cmake_minimum_required (VERSION 2.6)
project (Led_UART)

add_definitions("-D_USE_MATH_DEFINES")
add_definitions("-std=gnu++11")

include_directories("./src")
include_directories("./example")
# include_directories("./mavlink/v2.0/common")

add_library(led_uart_cpp  SHARED
    ./src/message.cpp
    ./src/serial_led.cpp
    ./src/serial_port.cpp
    ./src/checksum.h
)

add_executable(test_lib example/test_lib.cpp)

# target_link_libraries(led_uart_cpp
#     pthread
# )

target_link_libraries(test_lib
    pthread
    ${PROJECT_SOURCE_DIR}/libled_uart_cpp.so
)