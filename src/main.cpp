#include "peripherals.hpp"
#include <iostream>
#include <csignal>
#include <atomic>
#include <thread>
#include <chrono>

std::atomic<bool> running{true};

void signal_handler(int signal) {
    if (signal == SIGTERM || signal == SIGINT) {
        running = false;
    }
}

int main() {
    std::signal(SIGINT, signal_handler);
    std::signal(SIGTERM, signal_handler);

    GuardianHardware hw;
    if (!hw.initialize()) {
        std::cerr << "Failed to initialize hardware!" << std::endl;
        return 1;
    }

    std::cout << "Guardian running. Monitoring I2C Peripherals..." << std::endl;

    while (running) {
        float temp = hw.read_temperature();
        std::cout << "[DATA] Current System Temp: " << temp << "°C" << std::endl;

        // Requirement: Health Checks
        if (temp > 29.0f) {
            std::cerr << "[CRITICAL] Overheating detected! Taking action..." << std::endl;
        }

        hw.kick_watchdog();

        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    std::cout << "Cleaning up hardware handles and exiting." << std::endl;
    return 0;
}
