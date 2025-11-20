#include <stdlib.h>
#include <stdio.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main(void) {
    int n = 0;
    int m = 0;
    int capacity = 0;
    int room = 0; 
    int real = 1;
    scanf("%d %d", &n, &m);
    while(n != 0 || m != 0) {
        int lectures[n];
        int rooms[m];
        for (int i = 0; i < n; ++i) {
            scanf("%d", &lectures[i]);
        }
        for (int j = 0; j < m; ++j) {
            scanf("%d", &rooms[j]);
        }
        qsort(lectures, n, sizeof(int), compare);
        qsort(rooms, m, sizeof(int), compare);
        capacity = 0;
        room = 0;
        real = 1;
        for (int i = 0; i < n; ++i) {
            while (room < m && rooms[room] < lectures[i]) {
                room++;
            }
            if (room == m) {
                real = 0;
                break;
            }
            capacity += rooms[room];
            ++room;
        }
        if(real) {
            printf("%d\n", capacity);
        } else {
            printf("Impossible\n");
        }
        scanf("%d %d", &n, &m);
    }
    return 0;
} 
