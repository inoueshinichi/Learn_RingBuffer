//
//  QueueRingBuffer.cpp
//  ManyAlgorithm
//
//  Created by InoueShinichi on 2018/07/21.
//  Copyright © 2018年 InoueShinichi. All rights reserved.
//

#include "QueueRingBuffer.hpp"
#include <stdio.h>

Queue *make_queue(int n)
{
    Queue *que = new Queue;
    if (que != NULL)
    {
        que->front = 0;
        que->rear = 0;
        que->count = 0;
        que->size = n;
        que->buff = new double[n * sizeof(double)];
        if (que->buff == NULL)
        {
            delete que;
            return NULL;
        }
    }
    return que;
}

bool is_full(Queue *que)
{
    return que->count == que->size;
}

bool enqueue(Queue *que, double x)
{
    if (is_full(que))
        return false;
    
    que->buff[que->rear++] = x;
    que->count++;
    if (que->rear == que->size)
        que->rear = 0;
    return true;
}

bool is_empty(Queue *que)
{
    bool flg = true;
    if (que == NULL || que->count == 0)
        flg = false;
    return flg;
}

double dequeue(Queue *que, bool *err)
{
    if (is_empty(que))
    {
        *err = false;
        return 0;
    }
    
    double x = que->buff[que->front++];
    que->count--;
    *err = true;
    if (que->front == que->size)
        que->front = 0;
    return x;
}

double top(Queue *que, bool *err)
{
    if (is_empty(que))
    {
        *err = false;
        return 0;
    }
    
    return que->buff[que->front];
}

int queue_length(Queue *que)
{
    if (is_empty(que))
        return 0;
    
    return que->count;
}



