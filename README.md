# Guardian: Embedded System Health & Peripheral Monitor

[![Guardian CI/CD](https://github.com/YOUR_USERNAME/guardian/actions/workflows/pipeline.yml/badge.svg)](https://github.com/YOUR_USERNAME/guardian/actions)
![Platform: Linux](https://img.shields.io/badge/Platform-Linux-orange.svg)
![Language: C++17](https://img.shields.io/badge/Language-C%2B%2B17-blue.svg)

**Guardian** is a production-ready system daemon designed for embedded Linux targets. It demonstrates high-reliability engineering practices, hardware peripheral abstraction, and automated build/release engineering—directly addressing the requirements for PamirAI’s embedded product development.

---

## 🛠 Features & Requirements Traceability

| Requirement | Implementation in Guardian |
| :--- | :--- |
| **Linux OS & BSP Bring-up** | Mocked Device Tree Source (`bsp/`) and I2C/GPIO abstraction. |
| **System Services** | Native `systemd` integration with automated lifecycle management. |
| **Reliability/Watchdog** | POSIX signal handling (SIGTERM/SIGINT) and Watchdog heartbeating. |
| **Build/Release Engineering** | CMake-based reproducible builds with GitHub Actions CI/CD. |
| **Versioned Artifacts** | Automated packaging of binaries and service definitions into `.tar.gz` releases. |

---

## 📂 Project Structure

```
.
├── .github/workflows/  # CI/CD Pipeline (Build, Test, Release)
├── bsp/                # Device Tree Source (DTS) snippets for hardware bring-up
├── docs/               # Troubleshooting Runbook & Weekly Status templates
├── include/            # Hardware Abstraction Layer (HAL) headers
├── scripts/            # Acceptance test and deployment scripts
├── src/                # Core C++ daemon logic and signal handling
├── systemd/            # Linux service configuration files
└── CMakeLists.txt      # Reproducible build configuration
```

## 🚀 Getting Started

**Prerequisites**

 * Linux environment (Ubuntu 22.04+ recommended)
 * CMake 3.10+
 * G++ (supporting C++17)

**Build & Install**
To ensure a **reproducible build** consistent with production requirements:

```
# Clone and enter repo
git clone [https://github.com/YOUR_USERNAME/guardian.git](https://github.com/YOUR_USERNAME/guardian.git) && cd guardian

# Configure and Build
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build

# Install to system (Simulates production deployment)
sudo make -C build install
sudo systemctl daemon-reload
sudo systemctl enable --now guardian
```

## 📋 Acceptance Test Checklist (ATC)
Before marking a release as "Production Ready," the following tests are executed via `scripts/acceptance_test.sh`:

 1 Static Analysis: Zero compiler warnings with -Wall -Werror.
 2 Binary Verification: Executable links correctly against standard libraries.
 3 Signal Integrity: Service exits with code 0 upon receiving SIGTERM.
 4 Service Persistence: systemd successfully restarts the daemon on unexpected failure.

## 📖 Troubleshooting Runbook (Summary)
See docs/RUNBOOK.md for full details.

 * Symptom: [ERROR] Failed to open I2C bus.
    * Cause: User lack of permissions or missing kernel module i2c-dev.
    * Fix: Add user to i2c group: sudo usermod -aG i2c $USER.
 * Symptom: Watchdog triggers system reset.
    * Cause: Main thread blocked by heavy I/O or high CPU load.
    * Fix: Verify kick_watchdog() frequency vs. hardware timeout settings.





