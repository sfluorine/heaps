#include <raylib.h>
#include <stdio.h>

#include "heaps.h"
#include "stb_ds/stb_ds.h"

#define WINDOW_WIDTH    1280
#define WINDOW_HEIGHT   720

int main()
{
    // InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "DijkstraViz");
    //
    // while (!WindowShouldClose()) {
    //     BeginDrawing();
    //     ClearBackground(RAYWHITE);
    //     EndDrawing();
    // }
    //
    // CloseWindow();

    PriorityHeap ph = priority_heap_create();
    priority_heap_insert(&ph, 6);
    priority_heap_insert(&ph, 8);
    priority_heap_insert(&ph, 7);
    priority_heap_insert(&ph, 9);
    priority_heap_insert(&ph, 10);

    priority_heap_insert(&ph, 5);
    priority_heap_insert(&ph, 2);
    priority_heap_insert(&ph, 4);
    priority_heap_insert(&ph, 1);
    priority_heap_insert(&ph, 3);

    int64_t result = 0;
    while (priority_heap_delete(&ph, &result)) {
        printf("%ld\n", result);
    }

    priority_heap_destroy(&ph);
}
