# Embedded C Portfolio

This repository is a consolidated portfolio of hardware-agnostic, host-tested C projects designed for reliable embedded systems and robotics. 

By deliberately decoupling application control logic from hardware-specific features (like registers and HALs), these projects demonstrate how to build deterministic firmware that can be rigorously tested and validated on a PC host prior to microcontroller deployment.

**Maintained by:** [asteroid-deva](https://github.com/asteroid-deva)

---

## 📐 Core Design Philosophy

Both projects in this repository adhere to strict safety-critical and high-reliability design rules:

* **Hardware Independence:** No direct calls to hardware abstraction layers. Designed to compile on ARM Cortex-M, AVR, RISC-V, or standard PC architectures.
* **No Dynamic Allocation:** `malloc` and `free` are strictly forbidden. All memory is statically allocated or pool-managed to prevent fragmentation and stack overflows.
* **Deterministic Execution:** No blocking delays. Operations are designed to complete within known timeframes.
* **Separation of Concerns:** Pure logic is completely isolated from I/O drivers.
* **Explicit State Transitions:** System state changes must be deliberate, traceable, and strictly prevent undefined behavior.

---

## 📁 Repository Contents

### 1. Embedded Core Logic Library
*(Located in `/embedded-c-fundamentals`)*

A portable C library providing fundamental data structures and timing mechanisms optimized for constrained environments.

**Key Modules:**
* **Ring Buffer:** FIFO buffering logic designed for asynchronous UART/Serial data streams.
* **Software Timer:** Non-blocking timing mechanisms for task scheduling.
* **State Machine:** Lightweight management for explicit control logic.
* **Fixed-Point Math:** Optimized math library for MCUs lacking a hardware Floating Point Unit (FPU).
* **Command Parser:** Lightweight ASCII command handling for serial interfaces.

**Hardware Validation:**
The core modules were validated on real hardware using an ATmega328P (Arduino Uno–class microcontroller). The host-tested C source files were reused *without modification*, adding only a minimal hardware-specific application layer for GPIO and timing. During integration, C/C++ linkage issues were resolved using `extern "C"` guards, successfully bridging the C modules with the C++ Arduino build system.

### 2. Embedded FSM Simulator
*(Located in `/embedded-fsm-simulator`)*

A host-tested Finite State Machine (FSM) designed specifically to model and validate safety-critical state transitions. Illegal transitions are mathematically prevented by design.

**System States & Event-Driven Design:**
The FSM reacts deterministically to external triggers.

| Valid States | Accepted Events |
| :--- | :--- |
| `INIT`, `IDLE`, `READY`, `RUNNING`, `FAULT`, `RECOVERY`, `SHUTDOWN` | `EVT_INIT_DONE`, `EVT_CHECKS_OK`, `EVT_START`, `EVT_STOP`, `EVT_FAULT`, `EVT_RECOVER`, `EVT_RECOVERY_DONE` |

**Testing Strategy:**
The FSM is validated using a host-based test harness that feeds predefined events and prints state transitions, allowing for complete logic verification without hardware dependencies.

---

## 🚀 How to Build and Run Tests

Because these projects are hardware-agnostic, you can compile and run their test harnesses directly on your local machine using GCC.

**Running the FSM Simulator:**
```bash
cd embedded-fsm-simulator
gcc test/fsm_test.c src/fsm.c -Iinclude -o fsm_test
./fsm_test
