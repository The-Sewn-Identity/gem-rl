#ifndef NOTHER_H
#define NOTHER_H

#define ARR_LENGTH(arr, type) (sizeof(arr) / sizeof(type))

typedef enum {
    LOW,
    MEDIUM,
    HARD
} Difficulty;

typedef enum {
    WILDERNESS = 1,
    NOWHERE
} Map;

#endif