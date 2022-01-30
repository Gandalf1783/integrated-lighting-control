#include <iostream>
#include <cstring>
#include <linux/ioctl.h>
#include <linux/kd.h>
#include <linux/vt.h>
#include <vector>
#include "Display.hpp"
#include "ui/UiObject.hpp"
#include "ui/Image.hpp"
#include "ui/ProgressBar.hpp"
#include "ui/Text.hpp"
#include "ui/Rectangle.hpp"
#include <chrono>
#include <thread>


#ifndef UIMANAGER_HPP
#define UIMANAGER_HPP

using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;

class UiManager {
  private:
    char ttyfd; // TTY File Descriptor.
    std::thread uiManagerThread;
    std::chrono::system_clock::time_point timeA;
    std::chrono::system_clock::time_point timeB;
    std::chrono::duration<double, std::milli> work_time;

  public:
    std::vector<Display> displayArray;
    std::vector<UiObject*> uiArray;
    bool shouldStop;
    bool displayFPS;

    UiManager();

    void stop();

    void renderDisplays();

    void addDisplay(Display d);

    void startThread();

    void stopThread();
};
#endif
