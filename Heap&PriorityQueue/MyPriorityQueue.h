//
// Created by 王思敏 on 2020/7/25.
//


#ifndef UNTITLED_MYPRIORITYQUEUE_H
#define UNTITLED_MYPRIORITYQUEUE_H

#include <iostream>
#include <vector>
#include "MyPriorityQueue.h"
using namespace std;

class __unused MyPriorityQueue {
private:
    vector<int> vec;
    void popup();
    int downward();

public:
    void add_all(vector<int> p);
    void print();
    int remove();

};


#endif //UNTITLED_MYPRIORITYQUEUE_H
