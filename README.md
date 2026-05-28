# Embedded C Portfolio

This repository is a consolidated portfolio of hardware-agnostic, host-tested C projects focused on deterministic embedded systems, firmware architecture and robotics-oriented control logic.

The projects emphasize:
- event-driven design
- finite state machines (FSMs)
- cooperative scheduling
- ring buffer communication
- timer-based execution
- deterministic firmware behavior

All projects are designed to be validated on a PC host before microcontroller deployment.

---

# Maintained By

**GitHub:** https://github.com/asteroid-deva

---

# Core Embedded Design Philosophy

These projects follow strict embedded-system engineering principles commonly used in robotics, industrial automation and safety-critical firmware.

## Hardware Independence
Application logic is fully decoupled from:
- MCU registers
- HAL layers
- vendor SDKs

The same core logic can later be reused across:
- AVR
- STM32
- ESP32
- ARM Cortex-M
- RISC-V

---

## Deterministic Execution

The projects avoid:
- blocking delays
- unpredictable memory behavior
- uncontrolled state transitions

Instead they use:
- event-driven execution
- software timers
- explicit FSM transitions
- cooperative scheduling

---

## No Dynamic Allocation

`malloc()` and `free()` are intentionally avoided.

Reasons:
- fragmentation risk
- unpredictable timing
- reduced reliability

All memory is:
- statically allocated
- fixed-size
- deterministic

---

## Separation of Concerns

The architecture separates:
- control logic
- timing
- event generation
- scheduling
- hardware interaction

This improves:
- testability
- portability
- maintainability

---

# Repository Projects

---

# 1. Embedded C Fundamentals
📁 `/embedded-c-fundamentals`

A modular embedded C library implementing foundational firmware components commonly used in constrained embedded environments.

## Implemented Modules

### Ring Buffer
FIFO queue implementation using circular buffering.

Concepts explored:
- producer-consumer systems
- fixed-memory buffering
- queue overflow handling
- asynchronous communication

Typical usage:
- UART buffering
- telemetry streams
- interrupt-driven communication

---

### Software Timer
Non-blocking timing module.

Concepts explored:
- periodic execution
- timer expiration
- cooperative scheduling preparation
- replacing blocking delays

---

### State Machine
Basic finite state machine implementation.

Concepts explored:
- deterministic behavior
- explicit transitions
- illegal state prevention
- event-driven logic

---

### Command Parser
Lightweight ASCII command parser for embedded serial interfaces.

Concepts explored:
- command tokenization
- embedded input handling
- serial interface architecture

---

## Hardware Validation

The core modules were validated on an ATmega328P-based Arduino Uno platform.

The same host-tested C modules were reused without modification by adding only:
- minimal GPIO handling
- Arduino timing wrappers

During integration:
- C/C++ linkage issues were resolved using `extern "C"`
- host-tested logic successfully compiled inside the Arduino toolchain

This demonstrated portability between:
- host-based testing
- embedded deployment

---

# 2. Embedded FSM Simulator
📁 `/embedded-fsm-simulator`

A host-tested finite state machine simulator designed to model deterministic embedded control systems.

The project evolved from a simple FSM into a complete event-driven firmware architecture.

---

## Implemented Architecture

### Finite State Machine (FSM)

Implemented states:

- `INIT`
- `IDLE`
- `READY`
- `RUNNING`
- `FAULT`
- `RECOVERY`
- `SHUTDOWN`

Supported events:

- `EVT_INIT_DONE`
- `EVT_CHECKS_OK`
- `EVT_START`
- `EVT_STOP`
- `EVT_FAULT`
- `EVT_RECOVER`
- `EVT_RECOVERY_DONE`

---

## Event Queue System

The FSM later evolved into a queue-driven architecture using a ring buffer.

Architecture:

Event Source
↓
Ring Buffer Queue
↓
Main Loop
↓
FSM

Concepts explored:
- asynchronous event handling
- producer-consumer systems
- queue overflow strategy
- deterministic event ordering

---

## Timer-Generated Events

Software timers were later integrated to simulate periodic embedded behavior.

Instead of manually feeding events:
- timers generated events dynamically
- the queue stored events
- the FSM processed transitions asynchronously

Concepts explored:
- periodic scheduling
- timer-driven systems
- non-blocking execution
- event orchestration

---

## Host-Based Validation

The FSM was tested entirely on a PC host using:
- GCC
- standard C
- console-based test harnesses

This enabled:
- deterministic validation
- transition verification
- architecture testing before hardware deployment

---

# 3. Embedded Cooperative Scheduler
📁 `/embedded-cooperative-scheduler`

A lightweight cooperative scheduler designed to simulate periodic task execution in deterministic embedded systems.

The scheduler demonstrates how multiple firmware tasks can coexist without:
- RTOS kernels
- threading
- blocking delays

---

## Scheduler Architecture

Main Loop
↓
Scheduler
↓
Task Timing Check
↓
Execute Ready Tasks

---

## Implemented Features

### Periodic Task Execution

Tasks execute at configurable intervals using tick-based scheduling.

Example:
- sensor polling
- health monitoring
- control loop execution

---

### Cooperative Scheduling

Tasks:
- voluntarily return control
- remain short and non-blocking
- execute deterministically

Concepts explored:
- CPU time sharing
- task orchestration
- execution timing
- cooperative multitasking

---

### Tick-Based Timing

The scheduler simulates embedded timing behavior using periodic ticks.

Concepts explored:
- task periods
- elapsed timing
- deterministic scheduling
- execution coordination

---

## Embedded Relevance

The scheduler models patterns commonly found in:
- robotics controllers
- drones
- industrial automation
- sensor systems
- lightweight embedded firmware

---

# Skills Demonstrated Across Projects

- Embedded C architecture
- Finite State Machines (FSM)
- Ring Buffer implementation
- Cooperative scheduling
- Event-driven firmware design
- Timer-based execution
- Producer-consumer systems
- Deterministic system behavior
- Host-side validation
- Hardware abstraction
- Static memory design
- Embedded debugging mindset

---

# Build and Run

## FSM Simulator

```bash
cd embedded-fsm-simulator
gcc test/fsm_test.c src/fsm.c src/event_queue.c src/software_timer.c -Iinclude -o fsm_test
./fsm_test
```

## Cooperative Scheduler

```bash
cd embedded-cooperative-scheduler
gcc test/scheduler_test.c src/scheduler.c -Iinclude -o scheduler_test
./scheduler_test
```

---

# Future Roadmap

Planned future areas:

- interrupt-safe event systems
- watchdog simulation
- embedded logging systems
- lightweight communication protocols
- hardware-integrated validation
- cooperative scheduler + FSM integration

---

# Purpose of This Portfolio

The purpose of this portfolio is not merely to demonstrate syntax familiarity.

The primary objective is to understand:
- deterministic firmware behavior
- embedded architecture design
- timing-aware systems
- event-driven control logic
- scalable embedded software structure

through incremental, host-validated embedded projects.
