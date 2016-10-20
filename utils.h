#ifndef UTILS_H
#define UTILS_H
#include <string>
#include "queue.h"
#include <iostream>

template<typename Item>
struct Producer
{
    void operator()(Utils::Queue<Item> &queue, Item &item)
    {
        queue.push(item);
        std::cout << item  << " pushed ..."<< std::endl;
    }

};

template<typename Item>
struct Consumer
{
    Consumer(bool *continue_running)
    {
        this->continue_running = continue_running;
    }

    void operator()(Utils::Queue<Item> &queue)
    {
        Item item;
        while(*continue_running)
        {
            std::cout <<" Consumer waiting for item ..."<< std::endl;
            queue.wait_and_pop(item);
            //std::cout << item << std::endl;
            std::cout << item  << " poped ..."<< std::endl;
        }
        std::cout <<" Consumer exited ..."<< std::endl;

    }
    bool *continue_running;
};

#endif // UTILS_H
