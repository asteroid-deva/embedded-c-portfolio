# Software Timer Design

## Problem with Blocking Delays
Using blocking delays such as `delay()` or busy-wait loops prevents the CPU from handling other tasks. In embedded systems, this can lead to:

- Missed events or interrupts
- Increased interrupt latency
- Poor system responsiveness
- Difficulty scaling to multiple timed tasks

Blocking delays make firmware fragile and hard to reason about.

## Software Timer Approach
A software timer does not pause execution. Instead, it records a start time and periodically checks whether a specified timeout has elapsed based on a system tick counter.

This allows the main loop to continue running while timing conditions are evaluated non-blockingly.

## Tick-Based Timing
Time is represented using a monotonically increasing tick counter (milliseconds). Timer expiration is determined using unsigned arithmetic:

(current_tick - start_tick) >= timeout


This method remains correct even if the tick counter overflows, which is a common occurrence in long-running embedded systems.

## Benefits
- Non-blocking execution
- Deterministic timing behavior
- Supports multiple concurrent timers
- Easily testable without hardware dependencies

## Real-World Usage
Software timers form the basis of cooperative schedulers, task loops, watchdog timers and timeout handling in embedded firmware. They are widely used in robotics, drones and real-time control systems.
