#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#include <stdint.h>
#include <stdbool.h>

#define CMD_MAX_LENGTH 32

typedef enum {
    CMD_NONE = 0,
    CMD_ARM,
    CMD_DISARM,
    CMD_START,
    CMD_STOP,
    CMD_STATUS,
    CMD_UNKNOWN
} command_t;

/* Command parser context */
typedef struct {
    char buffer[CMD_MAX_LENGTH];
    uint8_t index;
} command_parser_t;

/* Initialize command parser */
void command_parser_init(command_parser_t *parser);

/* Feed one character into the parser */
bool command_parser_process_char(command_parser_t *parser,
                                 char c,
                                 command_t *out_cmd);

#endif /* COMMAND_PARSER_H */
