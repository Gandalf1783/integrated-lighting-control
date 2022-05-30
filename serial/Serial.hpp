#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h> 
#include <errno.h>
#include <termios.h> 
#include <unistd.h>

#ifndef SERIAL_HPP
#define SERIAL_HPP

class Serial {
    private:
        int fdSerialPort;
        termios tty; // termios struct already exists
        char read_buf [256];
        unsigned char msg[6] = { 'H', 'e', 'l', 'l', 'o', '\r' };
    public:
        void start();
        void stop();
};

#endif