//
// Created on 2020/7/26.
//

#include "InsertSort.h"

vector<int> InsertSort::insertSort(vector<int> vec) {

    if(vec.size() < 2)
        return vec;

    for(int i = 1; i < vec.size(); ++i) {
        int temp = vec[i];
        int k = i - 1;
        while(k >= 0 && vec[k] > temp)
            k--;
        for(int j = i; j > k + 1; --j)
            vec[j] = vec[j - 1];
        vec[k + 1] = temp;
    }
    return vec;

}
