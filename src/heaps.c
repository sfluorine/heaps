#include <assert.h>

#include "heaps.h"
#include "stb_ds/stb_ds.h"

static size_t get_lhs_child_index(size_t parent_index)
{
    return 2 * parent_index + 1;
}

static size_t get_rhs_child_index(size_t parent_index)
{
    return 2 * parent_index + 2;
}

static size_t get_parent_index(size_t child_index)
{
    return (child_index - 1) / 2;
}

static int has_lhs_child(int64_t* nodes, size_t index)
{
    return get_lhs_child_index(index) < arrlen(nodes);
}

static int has_rhs_child(int64_t* nodes, size_t index)
{
    return get_rhs_child_index(index) < arrlen(nodes);
}

static int has_parent(size_t index)
{
    return get_parent_index(index) >= 0;
}

static int64_t get_lhs_child(int64_t* nodes, size_t index)
{
    return nodes[get_lhs_child_index(index)];
}

static int64_t get_rhs_child(int64_t* nodes, size_t index)
{
    return nodes[get_rhs_child_index(index)];
}

static int64_t get_parent(int64_t* nodes, size_t index)
{
    return nodes[get_parent_index(index)];
}

static void sift_up(int64_t* nodes)
{
    size_t index = arrlen(nodes) - 1;

    while (has_parent(index) && get_parent(nodes, index) > nodes[index]) {
        int64_t temp = nodes[index];
        nodes[index] = get_parent(nodes, index);
        nodes[get_parent_index(index)] = temp;

        index = get_parent_index(index);
    }
}

static void sift_down(int64_t* nodes)
{
    size_t index = 0;

    while (has_lhs_child(nodes, index)) {
        size_t smaller_child_index = get_lhs_child_index(index);

        if (
            has_rhs_child(nodes, index) && 
            get_rhs_child(nodes, index) < get_lhs_child(nodes, index))
        {
            smaller_child_index = get_rhs_child_index(index);
        }

        if (nodes[index] <= nodes[smaller_child_index]) {
            break;
        } else {
            int64_t temp = nodes[index];
            nodes[index] = nodes[smaller_child_index];
            nodes[smaller_child_index] = temp;
        }

        index = smaller_child_index;
    }
}

PriorityHeap priority_heap_create()
{
    return (PriorityHeap) {.nodes = NULL};
}

void priority_heap_insert(PriorityHeap* ph, int64_t node)
{
    assert(ph);

    arrput(ph->nodes, node);
    sift_up(ph->nodes);
}

int priority_heap_delete(PriorityHeap* ph, int64_t* out)
{
    assert(ph);

    if (arrlen(ph->nodes) == 0) {
        return 0;
    }

    if (out) {
        *out = ph->nodes[0];
    }

    ph->nodes[0] = arrpop(ph->nodes);
    sift_down(ph->nodes);

    return 1;
}

void priority_heap_destroy(PriorityHeap* ph)
{
    assert(ph);

    arrfree(ph->nodes);
}
