# Design Decisions

## Ring Buffer Overwrite Policy

### Chosen Behavior
When the ring buffer is full and new data is written, the oldest unread data is overwritten.

### Rationale
In embedded systems, especially in interrupt-driven contexts (UART receive) blocking or failing on data arrival can be more harmful than controlled data loss. Overwriting the oldest data ensures:

- Deterministic behavior under load
- No blocking in interrupt service routines
- Continuous system operation even when producers are faster than consumers

This policy is commonly used in logging, telemetry and non-critical data streams.

### Trade-offs
The primary downside is loss of the oldest unread data. This approach is unsuitable for:

- Command protocols where every byte is critical
- Safety-critical communication without redundancy

### Alternatives Considered
1. **Reject New Data**  
   Prevents data loss but requires error handling and may block producers.
2. **Signal Overflow Error**  
   Adds complexity and requires higher-level recovery mechanisms.
3. **Dynamic Resizing**  
   Not suitable for embedded systems due to non-deterministic memory behavior.

### Conclusion
Given the constraints and intended use cases, overwrite-on-full provides the best balance between simplicity, safety and determinism.
