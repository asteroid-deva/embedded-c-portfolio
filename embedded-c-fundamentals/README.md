# Embedded Core Logic Library

A hardware-agnostic, portable C library designed for reliable embedded systems development. This project decouples application logic from hardware, allowing for rigorous testing on host machines before deployment to MCUs.

##  Motivation
Why structure embedded software this way? High-reliability embedded systems require constraints that typical software does not. This library is built to enforce:

* **Explicit Memory Control:** Preventing fragmentation and stack overflows by managing data structures manually.
* **Predictable Timing:** Ensuring operations complete within known timeframes without hidden latencies.

##  Scope
This project is strictly defined by the following boundaries:

* **Hardware Independent:** No direct calls to HAL (Hardware Abstraction Layers) or registers.
* **MCU-Portable:** Designed to compile and run on any architecture (ARM Cortex-M, AVR, RISC-V, etc.).
* **Testable:** All logic is validated via software unit tests on a PC host.

##  Modules Overview
The library is composed of modular, reusable components:

| Module | Functionality |
| :--- | :--- |
| **Ring Buffer** | FIFO buffering logic designed for UART/Serial data streams. |
| **State Machine** | Explicit control logic management to prevent undefined states. |
| **Software Timer** | Non-blocking timing mechanisms for task scheduling. |
| **Fixed-Point** | Math library optimized for MCUs lacking a Floating Point Unit (FPU). |
| **Command Parser** | Lightweight ASCII command handling for serial interfaces. |

##  Design Philosophy
To ensure safety and reliability, we adhere to strict design rules:

1.  **No Dynamic Allocation:** `malloc` and `free` are strictly forbidden. All memory is statically allocated or pool-managed.
2.  **Clear Ownership:** Every data structure has a single, explicit owner to prevent race conditions.
3.  **Explicit State Transitions:** System state changes must be deliberate and traceable.
4.  **Separation of Concerns:** Pure logic is completely separated from I/O drivers.

##  Limitations
Since this is a logic-only library running in a hardware-agnostic context, the following are not covered:

* **No Real ISR Timing:** Interrupt Service Routine behavior cannot be perfectly simulated on a host PC.
* **No Hardware Latency:** Bus speeds, peripheral initialization times, and electrical propagation are not modeled.

##  Future Work / Roadmap
* [ ] Port integration example to **Raspberry Pi Pico W**.
* [ ] Replace current test mocks with real hardware drivers for integration testing.

---
*Maintained by asteriod-deva*

## Hardware Validation

The core modules in this repository were validated on real hardware using an ATmega328P (Arduino Uno–class microcontroller).

The same C source files were reused without modification, with only a minimal hardware-specific application layer added for GPIO and timing.

During integration with the Arduino toolchain, a C/C++ linkage issue was encountered and resolved using extern "C" guards in the headers, ensuring correct symbol linkage between C modules and the C++-based Arduino build system.

This validation confirmed the portability, determinism and non-blocking behavior of the firmware logic when deployed on an actual microcontroller.

*Maintained by asteriod-deva*
