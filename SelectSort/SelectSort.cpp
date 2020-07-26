//
// Created by 王思敏 on 2020/7/26.
//

#include "SelectSort.h"
#include <vector>

vector<int> SelectSort::selectSort(vector<int> arr) {

    for(int i = 0; i < arr.size(); ++i) {
        int min = INT32_MAX;
        int index = 0;
        for(int j = i; j < arr.size(); ++j) {
            if(min > arr[j]) {
                index = j;
                min = arr[j];
            }
        }
        arr[index] = arr[i];
        arr[i] = min;
    }
    return arr;

}