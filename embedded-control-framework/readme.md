<div align="center">

# 🚀 Embedded Control Framework



### 🧠 Integrating Core Embedded Design Patterns Into a Unified Architecture  
*Finite State Machines • Event Queues • Software Timers • Cooperative Scheduling • Fault Handling*

</div>

---

# 📖 Overview

A host-tested embedded control framework that integrates multiple fundamental firmware concepts into a single cohesive architecture.

This project combines:

- 🧠 Finite State Machines (FSM)
- 📥 Event Queues
- ⏱️ Software Timers
- ⚙️ Cooperative Scheduling
- ⚠️ Fault Handling

to demonstrate how modern embedded control systems are commonly structured.

---

# 🎯 Motivation

Previous projects explored individual embedded concepts independently.

Examples included:

- event systems
- finite state machines
- software timers
- schedulers
- interrupt architectures

This project brings those concepts together into a complete control framework.

The objective is to model how real embedded controllers coordinate:

- timing
- events
- state transitions
- fault recovery

within a deterministic firmware architecture.

---

# 🏗️ System Architecture

```
┌─────────────────┐
│ Scheduler       │
└────────┬────────┘
         │
         ▼
┌─────────────────┐
│ Tasks           │
└────────┬────────┘
         │
         ▼
┌─────────────────┐
│ Event           │
│ Generation      │
└────────┬────────┘
         │
         ▼
┌─────────────────┐
│ Event Queue     │
└────────┬────────┘
         │
         ▼
┌─────────────────┐
│ FSM             │
│ (State Machine) │
└────────┬────────┘
         │
         ▼
┌─────────────────┐
│ System Outputs  │
└─────────────────┘
````

---

# ⚙️ Execution Flow

---

## ⏱️ Scheduler

Periodically determines which tasks are ready to execute.

---

## 📋 Tasks

Perform recurring system operations such as:

* monitoring
* control updates
* communication checks
* safety verification

---

## 📡 Event Generation

Tasks generate events representing system activity.

Examples:

```
EVT_BOOT_COMPLETE
EVT_ARM
EVT_START
EVT_FAULT
EVT_RECOVER
```

---

## 📥 Event Queue

Stores events for deterministic processing.

This decouples:

* event creation
* event handling

---

## 🧠 Finite State Machine

Consumes queued events and performs:

* state transitions
* control decisions
* fault handling

---

## ⚙️ System Outputs

The final system behavior emerges from the current state and incoming events.

---

# ✨ Concepts Demonstrated

---

## 📏 Deterministic Firmware Design

Predictable execution flow and repeatable behavior.

---

## 🔄 Event-Driven Systems

System behavior is triggered by events rather than blocking logic.

---

## ⏱️ Scheduler Integration

Periodic tasks execute without requiring an RTOS.

---

## ⚠️ Fault Recovery

Controlled recovery paths prevent unsafe operation.

---

## 🧠 State-Based Control

Application behavior is driven through explicit state transitions.

---

## 🧪 Host-Side Validation

Architecture can be tested and verified without physical hardware.

---

# 🚀 Build & Run

```bash id="j2r8vk"
gcc test/control_framework_test.c \
src/fsm.c \
-Iinclude \
-o framework_test

./framework_test
```

---

# 🌍 Embedded Systems Relevance

The architectural patterns demonstrated here closely mirror those used in:

* 🚁 Drone flight controllers
* 🤖 Robotic control systems
* 🏭 Industrial automation
* 🛡️ Embedded safety systems
* ⚙️ Real-time control applications
* 📡 Event-driven firmware platforms

while remaining completely host-testable and hardware independent.

---

# 📚 Learning Outcomes

This framework provides practical exposure to:

* event-driven architecture
* state-machine design
* scheduler-based execution
* fault management strategies
* deterministic firmware behavior
* modular embedded system design

---

# 🧩 Design Philosophy

Instead of writing firmware as one large procedural loop:

```text id="5qk7mx"
Input
 ↓
Logic
 ↓
Output
```

the system follows a structured control pipeline:

```text id="8w3tnp"
Scheduler
 ↓
Tasks
 ↓
Events
 ↓
FSM
 ↓
System Behavior
```

This creates firmware that is easier to:

* maintain
* debug
* test
* scale

---

<div align="center">

## ⚡ Embedded Systems Principle

*"Schedule tasks. Generate events. Transition states. Control the system."*

</div>

