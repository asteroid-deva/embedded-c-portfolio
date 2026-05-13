#include <stdio.h>
#include <assert.h>
#include "command_parser.h"

static command_t feed_command(command_parser_t *parser, const char *cmd)
{
    command_t out = CMD_NONE;

    while (*cmd) {
        command_parser_process_char(parser, *cmd++, &out);
    }

    command_parser_process_char(parser, '\n', &out);
    return out;
}

int main(void)
{
    command_parser_t parser;
    command_t cmd;

    command_parser_init(&parser);

    cmd = feed_command(&parser, "ARM");
    assert(cmd == CMD_ARM);

    cmd = feed_command(&parser, "DISARM");
    assert(cmd == CMD_DISARM);

    cmd = feed_command(&parser, "START");
    assert(cmd == CMD_START);

    cmd = feed_command(&parser, "STOP");
    assert(cmd == CMD_STOP);

    cmd = feed_command(&parser, "STATUS");
    assert(cmd == CMD_STATUS);

    cmd = feed_command(&parser, "INVALID");
    assert(cmd == CMD_UNKNOWN);

    printf("Command parser tests passed.\n");
    return 0;
}
