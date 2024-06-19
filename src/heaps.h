#pragma once

#include <stdint.h>
#include <stddef.h>

typedef struct {
    int64_t* nodes;
} PriorityHeap;

PriorityHeap priority_heap_create();

void priority_heap_insert(PriorityHeap* ph, int64_t node);

int priority_heap_delete(PriorityHeap* ph, int64_t* out);

void priority_heap_destroy(PriorityHeap* ph);
