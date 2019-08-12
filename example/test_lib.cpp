#include "serial_port.h"
#include "serial_led.h"

// using namespace serial_led;

int main()
{
    serial_led::Serial_Port sp("serial:///dev/ttyACM0:9600");
    serial_led::LED led(&sp, 10);
    led.fill_color({255, 200, 100});
}