<div align="center">

# 🔄 Event Flow



### 🧠 Deterministic State Transitions Through Events  
*How an event-driven system evolves from startup to recovery.*

</div>

---

# 📖 Overview

This example illustrates a complete event-driven control sequence.

Each event triggers a predictable state transition inside the Finite State Machine (FSM), creating deterministic and testable system behavior.

---

# 🏗️ Event Flow Diagram

```text id="y5k3mv"
┌─────────────────┐
│ System Boot     │
└────────┬────────┘
         │
         ▼
 EVT_BOOT_COMPLETE
         │
         ▼
┌─────────────────┐
│ STATE_IDLE      │
└────────┬────────┘
         │
         ▼
      EVT_ARM
         │
         ▼
┌─────────────────┐
│ STATE_ARMED     │
└────────┬────────┘
         │
         ▼
     EVT_START
         │
         ▼
┌─────────────────┐
│ STATE_ACTIVE    │
└────────┬────────┘
         │
         ▼
     EVT_FAULT
         │
         ▼
┌─────────────────┐
│ STATE_FAULT     │
└────────┬────────┘
         │
         ▼
    EVT_RECOVER
         │
         ▼
┌─────────────────┐
│ STATE_RECOVERY  │
└────────┬────────┘
         │
         ▼
 EVT_RECOVERY_DONE
         │
         ▼
┌─────────────────┐
│ STATE_IDLE      │
└─────────────────┘
````

---

# ⚙️ State Transition Breakdown

---

## 🚀 System Startup

```text
System Boot
      ↓
EVT_BOOT_COMPLETE
      ↓
STATE_IDLE
```

The system completes initialization and enters a safe idle state.

---

## 🔐 System Arming

```text
User Arms System
      ↓
EVT_ARM
      ↓
STATE_ARMED
```

The controller transitions into an armed state and becomes ready for operation.

---

## 🎯 Mission Execution

```text
Mission Starts
      ↓
EVT_START
      ↓
STATE_ACTIVE
```

The system begins executing its primary operational tasks.

---

## ⚠️ Fault Handling

```text
Fault Detected
      ↓
EVT_FAULT
      ↓
STATE_FAULT
```

Any critical error immediately moves the system into a fault state.

---

## 🛠️ Recovery Process

```text
Recovery Requested
      ↓
EVT_RECOVER
      ↓
STATE_RECOVERY
```

Recovery procedures are initiated to restore normal operation.

---

## ✅ Return to Idle

```text
Recovery Finished
      ↓
EVT_RECOVERY_DONE
      ↓
STATE_IDLE
```

Once recovery completes successfully, the system safely returns to the idle state.

---

# 🧠 Why This Matters

This event-driven approach provides:

* 📏 Deterministic behavior
* 🔄 Predictable state transitions
* 🛡️ Safer fault handling
* 🐞 Easier debugging
* 🧪 Better testability

Every state transition occurs only through explicitly defined events.

---

# 🌍 Real-World Relevance

This control pattern is commonly found in:

* 🚁 Drone flight controllers
* 🤖 Robotic systems
* 🏭 Industrial automation
* ⚙️ Motor control applications
* 🛡️ Safety-critical embedded systems

---

# 🚀 Key Embedded Insight

The system never jumps randomly between states.

Instead:

```text id="2f7jkw"
Event
   ↓
FSM Decision
   ↓
State Transition
   ↓
System Action
```

This creates reliable, deterministic, and maintainable firmware behavior.

---

<div align="center">

## ⚡ Embedded Systems Principle

*"Events drive transitions. States drive behavior."*

</div>

