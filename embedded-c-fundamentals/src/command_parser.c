#include "command_parser.h"
#include <string.h>

void command_parser_init(command_parser_t *parser)
{
    if (!parser) {
        return;
    }

    parser->index = 0;
}

static command_t parse_command(const char *cmd)
{
    if (strcmp(cmd, "ARM") == 0) {
        return CMD_ARM;
    }
    if (strcmp(cmd, "DISARM") == 0) {
        return CMD_DISARM;
    }
    if (strcmp(cmd, "START") == 0) {
        return CMD_START;
    }
    if (strcmp(cmd, "STOP") == 0) {
        return CMD_STOP;
    }
    if (strcmp(cmd, "STATUS") == 0) {
        return CMD_STATUS;
    }

    return CMD_UNKNOWN;
}

bool command_parser_process_char(command_parser_t *parser,
                                 char c,
                                 command_t *out_cmd)
{
    if (!parser || !out_cmd) {
        return false;
    }

    /* End of command */
    if (c == '\n') {
        parser->buffer[parser->index] = '\0';
        *out_cmd = parse_command(parser->buffer);
        parser->index = 0;
        return true;
    }

    /* Ignore carriage return */
    if (c == '\r') {
        return false;
    }

    /* Prevent buffer overflow */
    if (parser->index >= (CMD_MAX_LENGTH - 1)) {
        parser->index = 0;
        *out_cmd = CMD_UNKNOWN;
        return true;
    }

    parser->buffer[parser->index++] = c;
    return false;
}
