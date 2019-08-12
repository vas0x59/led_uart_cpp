#ifndef SERIAL_LED_H_
#define SERIAL_LED_H_

#include <cstdlib>
#include <stdio.h>   // Standard input/output definitions

#include <string>


#include "message.h"
#include "serial_port.h"

using namespace std;

namespace serial_led
{


class LED
{

public:
    LED();
    LED(Serial_Port *sp_, uint8_t led_count_);
    void initialize_defaults();
    ~LED();


    void fill_color(Color color);
    void set_pixel_color(Color color, uint8_t index);
    // void 
    // void open();
    // void close();

    void start();
    void stop();

    uint8_t count_to_send = 1;

private:
    Serial_Port *sp;
    uint8_t led_count;
};
} // namespace serial_led

#endif