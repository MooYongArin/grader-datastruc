#ifndef _CP_STUDENT_QUEUE_INCLUDED_
#define _CP_STUDENT_QUEUE_INCLUDED_

#include <stdexcept>
#include <iostream>
// #pragma once
#include <vector>
#include <queue>
#include "queue.h"

template <typename T>
std::vector<CP::queue<T>> CP::queue<T>::split_queue(int k)
{
    std::vector<CP::queue<T>> qs(k);
    int current = 0;
    while (!this->empty())
    {
        qs[current].push(this->front());
        this->pop();
        current = (current + 1) % k;
    }
    
    return qs;
}

#endif