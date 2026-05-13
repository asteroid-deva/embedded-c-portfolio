# Finite State Machine Design

## Overview
This module implements a deterministic finite state machine (FSM) to control system behavior in a safe and predictable manner. The FSM ensures that the system is always in exactly one well-defined state.

## States
- **IDLE**: System is inactive and safe.
- **ARMED**: System is prepared but not actively running.
- **ACTIVE**: System is operating normally.
- **FAILSAFE**: Emergency state triggered by errors or signal loss.

## Events
- ARM / DISARM
- START / STOP
- SIGNAL_LOST / SIGNAL_RESTORED
- ERROR

## Transition Rules
- IDLE → ARMED → ACTIVE is enforced sequentially.
- Any critical error or signal loss forces transition to FAILSAFE.
- FAILSAFE cannot transition directly to ACTIVE.
- Recovery from FAILSAFE requires explicit operator action.

## Safety Rationale
Using an FSM prevents illegal state combinations (active motors while disarmed) and centralizes all control logic. This is critical in embedded and safety-related systems such as drones and robotics.

## Real-World Application
This FSM structure directly maps to drone flight control systems, robotic actuators and industrial controllers where deterministic behavior is required.
