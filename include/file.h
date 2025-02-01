#ifndef FILE_H

#define FILE_H
typedef struct {
    char kind /* d: directory | a: archive | e: error*/
} FileData;

FileData fileInfo(const char *filename);

#endif
