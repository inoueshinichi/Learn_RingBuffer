//
//  QueueRingBuffer.hpp
//  ManyAlgorithm
//
//  Created by InoueShinichi on 2018/07/21.
//  Copyright © 2018年 InoueShinichi. All rights reserved.
//

#ifndef QueueRingBuffer_hpp
#define QueueRingBuffer_hpp

#include <stdio.h>

// キューの定義
typedef struct
{
    int front; // 先頭インデックス
    int rear;  // 末尾いんでっくす
    int count;
    int size;
    double *buff; // 中身
} Queue;

Queue *make_queue(int n);              // 指定した大きさのキューを作る
void queue_delete(Queue *que);         // キューを廃棄する
double dequeue(Queue *que, bool *err); // キューからデータを取り出して返す
bool enqueue(Queue *que, double x);    // キューにデータを追加する
double top(Queue *que, bool* err);     // キューの先頭データを返す。データはキューから削除されない
bool is_empty(Queue *que);             // キューが空の場合はtrueを返す
bool is_full(Queue *que);              // キューが満杯の場合はtrueを返す
int queue_length(Queue *que);          // キューに核のされたデータ数を返す
void clear(Queue *que);                // キューをからにする

#endif /* QueueRingBuffer_hpp */
