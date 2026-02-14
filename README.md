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

```text
.
├── .github/workflows/  # CI/CD Pipeline (Build, Test, Release)
├── bsp/                # Device Tree Source (DTS) snippets for hardware bring-up
├── docs/               # Troubleshooting Runbook & Weekly Status templates
├── include/            # Hardware Abstraction Layer (HAL) headers
├── scripts/            # Acceptance test and deployment scripts
├── src/                # Core C++ daemon logic and signal handling
├── systemd/            # Linux service configuration files
└── CMakeLists.txt      # Reproducible build configuration
