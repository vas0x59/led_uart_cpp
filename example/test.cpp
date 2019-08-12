// Example program
#include <iostream>
#include <string>
#include "src/checksum.h"
#include "src/message.h"
#include "src/message.cpp"
using namespace serial_led;
using namespace std;


int main()
{
    Color color;
    int r, g, b, c;
    std::cout << "r ";
    std::cin >> r;
    std::cout << "g ";
    std::cin >> g;
    std::cout << "b ";
    std::cin >> b;
    std::cout << "c ";
    std::cin >> c;
    Message msg;
    // message_encode_fill_color(c, {r, g, b}, msg);
    message_encode_set_pixel_color(c, 20, {r, g, b}, msg);
    // for (uint8_t i = 0; i < 4; i++)
    // {
    //     std::cout << (int)fmsg.data_a[i] << "\n";
    // }
    // for (uint8_t i = 0; i < 6; i++)
    // {
    //     std::cout << (int)i << ": " << (int)msg.data_a[i] << "\n";
    // }
    // cout << "   \n";
    // Color test;
    // uint8_t l;
    // message_decode_fill_color(l, test, msg.msg);
    // cout << test.ToString() << '\n\n';
    uint8_t buf[10];
    message_to_send_buf(msg, buf);
    // for (uint8_t i = 0; i < 10; i++)
    // {
    //     std::cout << (int)i << ": " << (int)buf[i] << "\n";
    // }
    // t:2,r:255,g:235,b:255,l:255,i:255
    Message msg_r;
    if (message_from_buf(msg_r, buf))
    {
        switch (msg_r.type)
        {
        case CMD_FILL_COLOR:
        {
            Color test;
            uint8_t l;
            message_decode_fill_color(l, test, msg_r);
            cout << "l: " << (int)l << " color: " << test.ToString() << '\n';
        }
        break;
        case CMD_SET_PIXEL_COLOR:
        {
            Color test;
            uint8_t l, index;
            message_decode_set_pixel_color(l, index, test, msg_r);
            cout << "l: " << (int)l << " i: " << (int)index << " color: " << test.ToString() << '\n';
        }
        break;

        default:
            break;
        }
    }
    // cout << msg2.

    /*
  std::string name;
  std::cout << "What is your name? ";
  getline (std::cin, name);
  std::cout << "Hello, " << name << "!\n";*/
}
