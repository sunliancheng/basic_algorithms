#include <climits>
//
// Created by 王思敏 on 2020/7/25.
//
#include <iostream>
#include <vector>
#include "MyPriorityQueue.h"

using namespace std;

void MyPriorityQueue::add_all(vector<int> p) {
    vector<int>::iterator it;
    for(it = p.begin(); it != p.end(); ++it) {
        MyPriorityQueue::vec.push_back(*it);
        MyPriorityQueue::popup();
    }
}

void MyPriorityQueue::popup() {
    int length = MyPriorityQueue::vec.size();
    int childrenIndex = length - 1;
    while(true) {
        if(length == 1 || length == 0 || childrenIndex == 0)
            break;
        else {
            int parentIndex = (childrenIndex - 1) / 2;
            if(MyPriorityQueue::vec[parentIndex] > MyPriorityQueue::vec[childrenIndex]) {
                int parent_value = MyPriorityQueue::vec[parentIndex];
                int children_value = MyPriorityQueue::vec[childrenIndex];
                MyPriorityQueue::vec[parentIndex] = children_value;
                MyPriorityQueue::vec[childrenIndex] = parent_value;
                childrenIndex = parentIndex;
            } else
                break;
        }
    }
}

void MyPriorityQueue::print() {
    vector<int>::iterator it;
    for(it = MyPriorityQueue::vec.begin(); it != MyPriorityQueue::vec.end(); ++it) {
        cout << *it;
    }
    cout << endl;
}

int MyPriorityQueue::downward() {
    int current = 0;
    if(vec.size() == 0)
        return -1;
    int first_value = this->vec[0];
    int last_value = this->vec[this->vec.size() - 1];

    while(true) {
        if(vec.size() == 0 || vec.size() == 1 || current * 2 + 1 > vec.size() - 1)
            break;
        else {
            int left_children_index = current * 2 + 1;
            int right_children_index = left_children_index + 1;
            int current_value = vec[current];
            int left_value = vec[left_children_index];

            if(right_children_index < vec.size()) {
                int right_value = vec[right_children_index];
                int min_value = left_value < right_value ? left_value : right_value;
                int min_index = left_value < right_value ? left_children_index : right_children_index;
                if(current_value > min_value) {
                    vec[current] = min_value;
                    vec[min_index] = current_value;
                    current = min_index;
                } else
                    break;
            } else if(right_children_index > vec.size() - 1) {
                if(current_value > left_value) {
                    vec[current] = left_value;
                    vec[left_children_index] =  current_value;
                    current = left_children_index;
                } else
                    break;
            } else
                break;
        }
    }
    return first_value;
}

int MyPriorityQueue::remove() {
    int last_index = vec.size() - 1;
    int last_value = vec[last_index];
    int first_value = vec[0];
    vec[0] =  last_value;
    vec.pop_back();
    downward();
    return first_value;
}