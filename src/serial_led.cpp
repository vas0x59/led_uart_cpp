#include "serial_led.h"

namespace serial_led
{
LED::LED(Serial_Port *sp_, uint8_t led_count_)
{
    sp = sp_;
    led_count = led_count_;
}


LED::LED()
{
	// initialize_defaults();
    led_count = 255;
}


void LED::start()
{
	sp->start();
}

void LED::stop()
{
	sp->stop();
}
void LED::fill_color(Color color)
{
    Message msg;
    message_encode_fill_color(led_count, color, msg);
    
    uint8_t buf[10];
    message_to_send_buf(msg, buf);
    
    for (uint8_t i = 0; i < count_to_send; i++)
    {
        sp->write_port((char *)buf, 10);
    }
}
void LED::set_pixel_color(Color color, uint8_t index)
{
    Message msg;
    message_encode_set_pixel_color(led_count, index, color, msg);

    uint8_t buf[10];
    message_to_send_buf(msg, buf);

    for (uint8_t i = 0; i < count_to_send; i++)
    {
        sp->write_port((char *)buf, 10);
    }
}
} // namespace serial_led