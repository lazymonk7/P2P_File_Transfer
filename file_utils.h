#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <fcntl.h>

#define BLOCK_SIZE 4096
#define BUFF 512

// struct offset *
struct offset{
    char* file_name;
    unsigned int start;
    unsigned int end;
};

/**
 * @brief reconstruct from the n file created by segment_file
 * @param offsets 
 */
void reconstruct_file(struct offset* offsets, int nr_of_peers);

/**
 * @brief returns content of the designated peer
 *
 * 
 * @param offsets 
 * @param file to read from
 */
void write_segment(struct offset* offsets, int file);

/**
 * @brief segments file for a number of peers
 * @param file_name 
 * @param nr_of_peers 
 * @return list of offsets assignated 
 */
struct offset* segment_file(int file_name, unsigned int nr_of_peers);

/**
 * @brief Deletes the locally intermediary filles.
 * @return 0 on succesful removal
 */
int remove_files(struct offset* offsets, int nr_of_peers);
void write_segment_socket(struct offset* offsets, int socket_fd);
struct offset* segment_file_size(unsigned int file_size, unsigned int nr_of_peers);
#endif