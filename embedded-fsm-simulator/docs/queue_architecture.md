<div align="center">

# 🔄 Queue Architecture



### ⚙️ Event-Driven Embedded System Design

*Building deterministic and decoupled firmware using queue-based event processing.*

</div>

---

# 🎯 Motivation

Embedded systems constantly receive asynchronous events from multiple hardware and software sources such as:

- ⏱️ Timers
- ⚡ Interrupts
- 📡 Sensors
- 🔌 Communication Interfaces

Directly executing application logic from these sources can lead to:

- tightly coupled systems
- blocking behavior
- race conditions
- unpredictable execution flow

---

# ✅ Core Idea

Instead of executing logic immediately:

📥 events are first pushed into a queue  
📤 then processed later by the main application loop

This creates a far more stable and maintainable architecture.

---

# 🏗️ System Architecture

```text
┌─────────────────┐
│  Event Source   │
└────────┬────────┘
         │
         ▼
┌─────────────────┐
│ Ring Buffer     │
│ Queue           │
└────────┬────────┘
         │
         ▼
┌─────────────────┐
│ Main Loop       │
└────────┬────────┘
         │
         ▼
┌─────────────────┐
│ FSM Dispatcher  │
└─────────────────┘
```

⚡ Advantages
🔗 Decoupled Architecture

Separates:

event generation
event processing

making the system modular and scalable.

🚫 Prevents Blocking Behavior

Interrupts and timers remain lightweight and responsive.

⏱️ Deterministic Processing

Events are handled in controlled order through the queue.

🐞 Easier Debugging

Queued events can be inspected and traced systematically.

📦 Safe Event Ordering

Maintains predictable execution flow even under high event load.

🔄 Producer–Consumer Model
📤 Producers

Components that generate events:

⏱️ Timers
⚡ Interrupts
📡 Sensor Logic
🔌 Communication Drivers
📥 Consumers

Components that process events:

🔁 Main Loop
🧠 FSM Dispatcher
🧠 Why Ring Buffers?

Ring buffers are heavily used in embedded systems because they provide:

📏 Fixed Memory Usage

No heap allocation required.

⚡ Predictable Timing

Essential for real-time and deterministic systems.

♻️ Efficient Memory Reuse

Buffer indices wrap around automatically.

🛡️ Safer Embedded Design

Avoids fragmentation caused by dynamic allocation.

🔢 Circular Indexing

The modulo operator enables safe buffer wrapping:

next_index = (current_index + 1) % BUFFER_SIZE;

This allows the queue to behave like a continuous circular structure while using fixed memory.

<div align="center">
🚀 Embedded Systems Philosophy

"Fast interrupts. Smart queues. Deterministic systems."

</div> 
