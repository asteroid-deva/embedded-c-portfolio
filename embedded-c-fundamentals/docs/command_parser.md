# Command Parser Design

## Overview
The command parser module converts a stream of incoming characters into high-level system commands. It is designed to operate in resource-constrained embedded systems and processes input one character at a time.

## Responsibilities
- Buffer incoming characters
- Detect end-of-command delimiters
- Identify known commands
- Output a structured command enum

The parser does not execute actions or modify system state. It only interprets input.

## Design Rationale
Embedded systems often receive data via UART, USB CDC or similar interfaces where characters arrive asynchronously. Processing input one character at a time allows:

- Non-blocking behavior
- Compatibility with interrupt-driven input
- Minimal memory usage

A fixed-size buffer is used to guarantee deterministic memory behavior.

## Integration with System Logic
The output of the command parser is intended to be mapped to system events and passed into a finite state machine (FSM). For example:

- `CMD_ARM` → FSM event `EVENT_ARM`
- `CMD_START` → FSM event `EVENT_START`

This separation ensures that parsing logic remains independent of control logic.

## Error Handling
- Unknown commands are reported explicitly
- Buffer overflow resets safely without memory corruption
- Empty or invalid input does not affect system state

## Real-World Usage
This command parser structure is commonly used to implement debug consoles, configuration interfaces and control shells in embedded firmware for robotics, drones and industrial controllers.
