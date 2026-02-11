#ifndef PERIPHERALS_HPP
#define PERIPHERALS_HPP

#include <iostream>
#include <fstream>
#include <string>

class GuardianHardware {
public:
    // Simulates opening a device node like /dev/i2c-1
    bool initialize() {
        std::cout << "[HAL] Initializing I2C Bus and GPIO pins..." << std::endl;
        return true; 
    }

    // Addresses the "logging and health checks" requirement
    float read_temperature() {
        // In a real scenario, we use ioctl() here. 
        // For the project, we simulate a sensor reading.
        return 25.0f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX/5.0f));
    }

    // Addresses the "Watchdog" requirement
    void kick_watchdog() {
        // Logic to prevent system reset
        // std::ofstream wdt("/dev/watchdog");
        // wdt << "1";
        std::cout << "[HAL] Watchdog kicked (Heartbeat OK)" << std::endl;
    }
};

#endif
