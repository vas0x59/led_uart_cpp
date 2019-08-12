#ifndef SERIAL_PORT_H_
#define SERIAL_PORT_H_

// ------------------------------------------------------------------------------
//   Includes
// ------------------------------------------------------------------------------

#include <cstdlib>
#include <stdio.h>   // Standard input/output definitions
#include <unistd.h>  // UNIX standard function definitions
#include <fcntl.h>   // File control definitions
#include <termios.h> // POSIX terminal control definitions
#include <pthread.h> // This uses POSIX Threads
#include <signal.h>

#include <string>

using namespace std;

// ------------------------------------------------------------------------------
//   Defines
// ------------------------------------------------------------------------------

// The following two non-standard baudrates should have been defined by the system
// If not, just fallback to number
#ifndef B460800
#define B460800 460800
#endif

#ifndef B921600
#define B921600 921600
#endif

// Status flags
#define SERIAL_PORT_OPEN 1;
#define SERIAL_PORT_CLOSED 0;
#define SERIAL_PORT_ERROR -1;

// ------------------------------------------------------------------------------
//   Prototypes
// ------------------------------------------------------------------------------

//class Serial_Port;

// ----------------------------------------------------------------------------------
//   Serial Port Manager Class
// ----------------------------------------------------------------------------------
/*
 * Serial Port Class
 *
 * This object handles the opening and closing of the offboard computer's
 * serial port over which we'll communicate.  It also has methods to write
 * a byte stream buffer.  MAVlink is not used in this object yet, it's just
 * a serialization interface.  To help with read and write pthreading, it
 * gaurds any port operation with a pthread mutex.
 */
namespace serial_led {
class Serial_Port
{

public:
    Serial_Port();
    Serial_Port(string url);
    Serial_Port(const char *uart_name_, int baudrate_);
    void initialize_defaults();
    ~Serial_Port();

    bool debug;
    const char *uart_name;
    int baudrate;
    int status;


    void open_serial();
    void close_serial();
    // void open();
    // void close();

    void start();
    void stop();

    void handle_quit(int sig);
    int read_port(uint8_t &cp);
    int write_port(char *buf, unsigned len);

private:
    int fd;
    pthread_mutex_t lock;

    int _open_port(const char *port);
    bool _setup_port(int baud, int data_bits, int stop_bits, bool parity, bool hardware_control);
};
}
#endif // SERIAL_PORT_H_
