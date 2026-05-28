<div align="center">

# ⚡ Interrupts vs Polling



### 🧠 Event Detection Strategies in Embedded Systems  
*Understanding the trade-offs between continuous checking and asynchronous hardware notification.*

</div>

---

# 📖 Polling

Polling is a technique where the CPU continuously checks for changes or events.

---

# 🔄 Example

```c id="0lnzjg"
while(1)
{
    check_button();
}
````

The processor repeatedly asks:

> *"Has something changed yet?"*

---

# ✅ Advantages of Polling

---

## 🧩 Simple Architecture

Easy to implement and understand.

---

## 🐞 Easier Debugging

Execution flow remains straightforward and predictable.

---

## 📚 Beginner Friendly

Commonly used in small learning projects and simple firmware.

---

# ❌ Disadvantages of Polling

---

## ⚡ Wastes CPU Cycles

The CPU keeps checking even when nothing happens.

---

## 🐢 Slower Response Time

Events may not be detected immediately.

---

## 📉 Poor Scalability

As the number of tasks increases, polling becomes inefficient.

---

# 🏗️ Polling Architecture

```text id="9x0o6j"
┌─────────────────┐
│ Main Loop       │
└────────┬────────┘
         │
         ▼
┌─────────────────┐
│ Check Event     │
└────────┬────────┘
         │
         ▼
┌─────────────────┐
│ Repeat Forever  │
└─────────────────┘
```

---

# 🚨 Interrupts

Interrupts allow hardware to notify the CPU immediately when an event occurs.

Instead of constantly checking:

> the hardware signals the processor directly.

---

# ⚡ Interrupt Flow

```text id="0h44vh"
Event Occurs
      ↓
Hardware Interrupt
      ↓
CPU Pauses Current Task
      ↓
ISR Executes
      ↓
Return to Main Program
```

---

# ✅ Advantages of Interrupts

---

## ⚡ Lower Latency

Events are handled almost immediately.

---

## 🧠 Efficient CPU Usage

CPU time is not wasted continuously checking hardware.

---

## 🚀 Responsive Behavior

Critical events can be serviced quickly.

---

# ❌ Disadvantages of Interrupts

---

## 🧩 Increased Complexity

Interrupt-driven systems require careful architectural design.

---

## ⚠️ Synchronization Concerns

Shared data between ISR and main loop can create race conditions.

---

## 🛡️ Timing Challenges

Improper ISR design can destabilize system timing.

---

# ⚔️ Polling vs Interrupts

| Polling                 | Interrupts               |
| ----------------------- | ------------------------ |
| CPU continuously checks | Hardware notifies CPU    |
| Simpler design          | More complex design      |
| Wastes CPU time         | Efficient CPU usage      |
| Higher latency          | Lower latency            |
| Easier debugging        | Requires synchronization |
| Poor scalability        | Better scalability       |

---

# 🧠 Embedded Usage

---

## 🔹 Small Embedded Systems

Sometimes rely on polling because:

* simplicity matters more
* timing requirements are relaxed
* hardware resources are limited

---

## 🔹 Real-Time Embedded Systems

Heavily rely on interrupts because they require:

* fast responsiveness
* deterministic event handling
* efficient multitasking
* low-latency reactions

---

# 🚀 Real-World Embedded Examples

| System                     | Common Approach |
| -------------------------- | --------------- |
| Simple Arduino LED project | Polling         |
| Drone flight controller    | Interrupts      |
| UART communication         | Interrupts      |
| Motor encoder tracking     | Interrupts      |
| Basic menu systems         | Polling         |
| Industrial automation      | Interrupts      |

---

# 📋 Typical Embedded Design Pattern

Modern embedded systems often combine both methods:

```text id="ngzmlv"
Interrupts:
- critical fast events

Polling:
- low-priority periodic checks
```

This hybrid approach balances simplicity and responsiveness.

---

# 🧠 Key Embedded Insight

Polling asks:

> *"Did something happen?"*

Interrupts declare:

> *"Something happened right now."*

---

<div align="center">

## ⚡ Embedded Systems Principle

*"Polling consumes time. Interrupts conserve it."*

</div>

