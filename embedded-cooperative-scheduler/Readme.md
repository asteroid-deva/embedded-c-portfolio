<div align="center">
  
# ⚙️ Embedded Cooperative Scheduler



### 🧠 Lightweight Task Scheduling for Embedded Systems  
*Built in C to explore deterministic timing and cooperative multitasking concepts.*

</div>

---

# 📖 Overview

A lightweight cooperative scheduler written in **C** for learning:

- ⏱️ embedded timing
- 📋 task scheduling
- 🔄 cooperative multitasking
- ⚡ non-blocking firmware architecture

without relying on an RTOS.

---

# 🎯 Motivation

Embedded systems often need to execute multiple periodic tasks while keeping the CPU responsive.

Traditional blocking approaches using delays quickly become inefficient and difficult to scale.

This project demonstrates:

- ✅ Cooperative scheduling
- ✅ Periodic task execution
- ✅ Non-blocking architecture
- ✅ Deterministic timing behavior

using a lightweight bare-metal design.

---

# 🏗️ System Architecture

```text id="6whxj0"
┌─────────────────┐
│ Main Loop       │
└────────┬────────┘
         │
         ▼
┌─────────────────┐
│ Scheduler       │
└────────┬────────┘
         │
         ▼
┌─────────────────┐
│ Task Timing     │
│ Check           │
└────────┬────────┘
         │
         ▼
┌─────────────────┐
│ Execute Ready   │
│ Tasks           │
└─────────────────┘
````

---

# ✨ Features

---

## 📋 Fixed Task Table

Tasks are statically defined for predictable execution.

---

## ⏱️ Periodic Task Execution

Tasks execute at configured intervals using tick timing.

---

## 🔄 Tick-Based Scheduling

A scheduler tick drives periodic task activation.

---

## ⚡ Deterministic Behavior

Execution flow remains predictable and traceable.

---

## 💾 No Dynamic Memory Allocation

Avoids heap fragmentation and improves embedded reliability.

---

# 🧪 Example Tasks

Typical embedded workloads include:

* 📡 Sensor polling
* 🎛️ Control loop updates
* 🩺 Health monitoring
* 🔌 Communication checks
* 💡 Status LED updates

---

# 🧠 Why Cooperative Scheduling?

Cooperative scheduling is widely used because it is:

* ⚡ Lightweight
* 🐞 Easy to debug
* 📏 Predictable
* 💾 Memory efficient

especially in small embedded systems.

---

# 📚 Learning Outcomes

This project helps build intuition for:

* ⏱️ timing behavior
* ⚡ responsiveness
* 🔄 execution flow
* 📋 task management
* 🧠 firmware architecture

before transitioning into:

* RTOS-based systems
* preemptive multitasking
* advanced embedded scheduling

---

# ⚔️ Cooperative vs RTOS-Based Design

| Cooperative Scheduler   | RTOS                     |
| ----------------------- | ------------------------ |
| Lightweight             | More powerful            |
| Deterministic flow      | Dynamic scheduling       |
| Minimal memory usage    | Higher overhead          |
| Easier debugging        | More complex debugging   |
| Great for small systems | Better for large systems |

---

# 🚀 Build & Run

```bash
gcc test/scheduler_test.c src/scheduler.c -Iinclude -o scheduler_test

./scheduler_test
```

---

# 📂 Project Focus

This repository focuses on understanding:

✅ bare-metal scheduling
✅ timing-driven execution
✅ lightweight embedded architectures
✅ deterministic firmware behavior

through practical implementation.

---

<div align="center">

## 🚀 Embedded Systems Philosophy

*"Simple schedulers teach the foundations of real-time thinking."*

</div>

