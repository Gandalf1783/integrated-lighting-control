#include "Serial.hpp"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"


/*
#######################################
    CODE CONTAINTS CONTENT FROM:
    https://blog.mbedded.ninja/programming/operating-systems/linux/linux-serial-ports-using-c-cpp/
#######################################
*/

void Serial::start() {
    fdSerialPort = open("/dev/ttyS0", O_RDWR);

    if(fdSerialPort < 0) {
        printf("[SERIAL] ERROR: Opening did not work: %d", fdSerialPort);
        return;
    }

    if(tcgetattr(fdSerialPort, &tty) != 0) {
        printf("Error %i from tcgetattr:\n", errno);
        return;
    }

    tty.c_cflag &= ~PARENB; // Clear parity bit, disabling parity (most common)
    tty.c_cflag &= ~CSTOPB; // Clear stop field, only one stop bit used in communication (most common)
    tty.c_cflag &= ~CSIZE; // Clear all bits that set the data size 
    tty.c_cflag |= CS8; // 8 bits per byte (most common)
    tty.c_cflag &= ~CRTSCTS; // Disable RTS/CTS hardware flow control (most common)
    tty.c_cflag |= CREAD | CLOCAL; // Turn on READ & ignore ctrl lines (CLOCAL = 1)

    tty.c_lflag &= ~ICANON;
    tty.c_lflag &= ~ECHO; // Disable echo
    tty.c_lflag &= ~ECHOE; // Disable erasure
    tty.c_lflag &= ~ECHONL; // Disable new-line echo
    tty.c_lflag &= ~ISIG; // Disable interpretation of INTR, QUIT and SUSP
    tty.c_iflag &= ~(IXON | IXOFF | IXANY); // Turn off s/w flow ctrl
    tty.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL); // Disable any special handling of received bytes

    tty.c_oflag &= ~OPOST; // Prevent special interpretation of output bytes (e.g. newline chars)
    tty.c_oflag &= ~ONLCR; // Prevent conversion of newline to carriage return/line feed

    tty.c_cc[VTIME] = 10;    // Wait for up to 1s (10 deciseconds), returning as soon as any data is received.
    tty.c_cc[VMIN] = 0;

    // Set in/out baud rate to be 9600
    cfsetispeed(&tty, B9600);
    cfsetospeed(&tty, B9600);

    // Save tty settings, also checking for error
    if (tcsetattr(fdSerialPort, TCSANOW, &tty) != 0) {
        printf("Error %i from tcsetattr\n", errno);
        return;
    }

    printf(ANSI_COLOR_RESET "[" ANSI_COLOR_MAGENTA "SERIAL" ANSI_COLOR_RESET "] ");
    printf("SerialPort " ANSI_COLOR_YELLOW "ttyS0" ANSI_COLOR_RESET " was opened!\n");


    write(fdSerialPort, msg, sizeof(msg)); // Writes data


    // Ready data:
    int num_bytes = read(fdSerialPort, &read_buf, sizeof(read_buf));
    if (num_bytes < 0) {
        printf("Error reading: %d", errno);
        return;
    }
    printf("Read %i bytes. Received message: %s", num_bytes, read_buf);

}

void Serial::stop() {
    
    if(fdSerialPort < 0) { // If serial was never opened, just return. Nothing to close.
        return;
    }

    close(fdSerialPort);
}