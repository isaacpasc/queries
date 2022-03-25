//
// Created by cse310 on 3/3/22.
//

#include "MaxHeap.h"
#include <cstring>

void MAX_HEAPIFY(SOC* heapArr, int i, int n, int id) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // total
    if (id == 1) {
        // if left child is larger
        if ((left < n && heapArr[left].total > heapArr[largest].total) ||
            (left < n && heapArr[left].total == heapArr[largest].total &&
             std::strcmp(heapArr[left].occupation, heapArr[largest].occupation) > 0)) {
            largest = left;
        }

        // if right child is largest
        if ((right < n && heapArr[right].total > heapArr[largest].total) ||
            (left < n && heapArr[right].total == heapArr[largest].total &&
             std::strcmp(heapArr[right].occupation, heapArr[largest].occupation) > 0)) {
            largest = right;
        }
    }

    // female
    if (id == 2) {
        // if left child is larger
        if ((left < n && heapArr[left].female > heapArr[largest].female) ||
            (left < n && heapArr[left].female == heapArr[largest].female &&
            std::strcmp(heapArr[left].occupation, heapArr[largest].occupation) > 0)) {
            largest = left;
        }

        // if right child is largest
        if ((right < n && heapArr[right].female > heapArr[largest].female) ||
            (right < n && heapArr[right].female == heapArr[largest].female &&
            std::strcmp(heapArr[right].occupation, heapArr[largest].occupation) > 0)) {
            largest = right;
        }
    }

    // male
    if (id == 3) {
        // if left child is larger
        if ((left < n && heapArr[left].male > heapArr[largest].male) ||
            (left < n && heapArr[left].male == heapArr[largest].male &&
            std::strcmp(heapArr[left].occupation, heapArr[largest].occupation) > 0)) {
            largest = left;
        }

        // if right child is largest
        if ((right < n && heapArr[right].male > heapArr[largest].male) ||
            (right < n && heapArr[right].male == heapArr[largest].male &&
            std::strcmp(heapArr[right].occupation, heapArr[largest].occupation) > 0)) {
            largest = right;
        }
    }

    // if largest is not root yet
    if (largest != i) {
        swap(&heapArr[largest], &heapArr[i]);
        MAX_HEAPIFY(heapArr, largest, n, id);
    }
}

void BUILD_MAX_HEAP(SOC* heapArr, int n, int id) {
    for (int i = ((n/2)-1); i >= 0; i--) {
        MAX_HEAPIFY(heapArr, i, n, id);
    }
}

SOC DELETE_MAX(SOC* heapArr, int& n, int id) {
    SOC root = heapArr[0];
    swap(&heapArr[0], &heapArr[n-1]);
    n = n - 1;
    MAX_HEAPIFY(heapArr, 0, n, id);
    return root;
}

void swap (SOC* p1, SOC* p2) {
    SOC temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
