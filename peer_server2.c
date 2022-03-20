#include "server.h"
#include "handlers.h"
#include <string.h>

file_t TEST_FILE_LIST[4];

int main()
{
    memcpy(TEST_FILE_LIST[0].hash, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA", 32);
    memcpy(TEST_FILE_LIST[0].name, "file_1aaaa", 10);
    TEST_FILE_LIST[0].size = 34;
    memcpy(TEST_FILE_LIST[1].hash, "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB", 32);
    memcpy(TEST_FILE_LIST[1].name, "file_2bbbb", 10);
    TEST_FILE_LIST[1].size = 512;
    memcpy(TEST_FILE_LIST[2].hash, "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC", 32);
    memcpy(TEST_FILE_LIST[2].name, "file_3cccc", 10);
    TEST_FILE_LIST[2].size = 18312;


    server_t *peer_server = server_constructor("127.0.0.1", 5002, 5);
    peer_server->start_listening(peer_server, handle_request_peer);
}