#include <math.h>

int comparator(float marksarray[][2], int index1, int index2) {
    float rms1 = sqrt(0.5 * (marksarray[index1][0]*marksarray[index1][0] + marksarray[index1][1]*marksarray[index1][1]));
    float rms2 = sqrt(0.5 * (marksarray[index2][0]*marksarray[index2][0] + marksarray[index2][1]*marksarray[index2][1]));

    if (rms1 > rms2) return -1;
    else if (rms1 < rms2) return 1;
    else {
        if (marksarray[index1][1] > marksarray[index2][1]) return -1;
        else if (marksarray[index1][1] < marksarray[index2][1]) return 1;
        else return 0;
    }
}

int selectionSort2(float array[][2], int numElements) {
    int break_point = numElements - 1;
    while (break_point > 0 && comparator(array, break_point - 1, break_point) <= 0) {
        break_point--;
    }
    for (int i = 0; i < break_point - 1; i++) {
        int min = i;
        for (int j = i + 1; j < break_point; j++) {
            if (comparator(array, j, min) == -1) min = j;
        }
        if (min != i) {
            float temp0 = array[i][0], temp1 = array[i][1];
            array[i][0] = array[min][0]; array[i][1] = array[min][1];
            array[min][0] = temp0; array[min][1] = temp1;
        }
    }
    return break_point;
}

int merge(float sortedarray[][2], float mergedarray[][2], int break_point, int numElements) {
    int i = 0, j = break_point, k = 0;
    while (i < break_point && j < numElements) {
        int cmp = comparator(sortedarray, i, j);
        if (cmp == -1) {
            mergedarray[k][0] = sortedarray[i][0];
            mergedarray[k++][1] = sortedarray[i++][1];
        } else if (cmp == 1) {
            mergedarray[k][0] = sortedarray[j][0];
            mergedarray[k++][1] = sortedarray[j++][1];
        } else {
            mergedarray[k][0] = sortedarray[i][0];
            mergedarray[k++][1] = sortedarray[i][1];
            i++; j++; // skip duplicates
        }
    }
    while (i < break_point) {
        mergedarray[k][0] = sortedarray[i][0];
        mergedarray[k++][1] = sortedarray[i++][1];
    }
    while (j < numElements) {
        mergedarray[k][0] = sortedarray[j][0];
        mergedarray[k++][1] = sortedarray[j++][1];
    }
    return k;
}
