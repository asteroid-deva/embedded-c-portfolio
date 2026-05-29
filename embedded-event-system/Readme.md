<div align="center">

  
# ⚡ Embedded Event System



### 🧠 Interrupt-Driven Firmware Architecture in C  
*A lightweight event-based framework for exploring asynchronous embedded system design.*

</div>

---

# 📖 Overview

A lightweight interrupt-driven event system written in **C** for learning how modern embedded firmware handles asynchronous events while maintaining deterministic behavior.

This project focuses on architectural concepts commonly found in real-world embedded systems without requiring actual hardware interrupts.

---

# 🎯 Motivation

Embedded systems must react to external events asynchronously while remaining:

- ⚡ Responsive
- 📏 Deterministic
- 🧠 Predictable
- 🛡️ Reliable

This project demonstrates:

- ✅ Interrupt-driven architecture
- ✅ Deferred event processing
- ✅ ISR-safe event queueing
- ✅ Volatile shared data
- ✅ Asynchronous firmware behavior

through a software-based simulation environment.

---

# 🏗️ System Architecture

```text id="v7s3qx"
┌──────────────────────┐
│ Interrupt Source     │
└──────────┬───────────┘
           │
           ▼
┌──────────────────────┐
│ ISR                  │
│ (Interrupt Handler)  │
└──────────┬───────────┘
           │
           ▼
┌──────────────────────┐
│ Event Queue          │
└──────────┬───────────┘
           │
           ▼
┌──────────────────────┐
│ Main Loop            │
└──────────┬───────────┘
           │
           ▼
┌──────────────────────┐
│ Event Handler        │
└──────────────────────┘
````

---

# ✨ Implemented Features

---

## 📦 Ring Buffer Event Queue

Efficient event storage using a fixed-size circular buffer.

---

## ⚡ Interrupt Simulation

Simulates interrupt-generated events without requiring hardware.

---

## 🔄 Deferred Event Processing

Heavy application logic is executed outside interrupt context.

---

## ⚠️ Volatile Shared Queue Indices

Demonstrates safe communication between asynchronous execution contexts.

---

## 🔁 Main-Loop Event Handling

Events are processed through a deterministic application loop.

---

## 📏 Deterministic Event Flow

Predictable event ordering and execution behavior.

---

# 🧠 Core Concepts Explored

This project serves as a practical introduction to:

---

## ⚡ Interrupt Service Routines (ISR)

Understanding fast interrupt-driven event generation.

---

## 🔄 Producer–Consumer Systems

Separating event creation from event processing.

---

## ⚠️ Race Conditions

Exploring timing-sensitive shared data problems.

---

## 📥 Deferred Processing

Moving expensive operations outside interrupt context.

---

## ⚔️ Polling vs Interrupts

Comparing two fundamental event-handling approaches.

---

## 🛡️ Shared Data Safety

Understanding the role of:

* volatile variables
* synchronization concepts
* execution timing

---

## 🧩 Event-Driven Firmware Design

Building responsive systems around events rather than blocking logic.

---

# 🚀 Build & Run

```bash
gcc test/interrupt_event_test.c \
src/event_queue.c \
src/interrupt_simulator.c \
src/event_handler.c \
-Iinclude \
-o interrupt_test

./interrupt_test
```

---

# 🔮 Future Improvements

Planned extensions include:

* 🚀 Real Arduino interrupt integration
* ⚛️ Atomic queue operations
* 🔒 Critical section protection
* 📡 UART interrupt simulation
* ⏱️ Scheduler integration
* 🧠 FSM integration

---

# 🌍 Embedded Systems Relevance

The architectural patterns demonstrated here are widely used in:

* 🤖 Robotics controllers
* 🚁 Drone flight systems
* 🏭 Industrial automation
* ⚙️ Motor control applications
* 📡 Communication firmware
* 🔌 Event-driven embedded platforms

---

# 📚 Learning Outcomes

By working through this project, you'll gain intuition for:

* asynchronous execution
* interrupt behavior
* event-driven architectures
* deferred processing
* deterministic firmware design

which form the foundation of more advanced embedded and real-time systems.

---

<div align="center">

## ⚡ Embedded Systems Philosophy

*"Interrupts generate events. Queues organize them. The main loop makes decisions."*

</div>

