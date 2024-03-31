#include <iostream>
#include "logger.hpp"
#include <thread>

using namespace std;
//restrict users from creating object of class

void user1logs()
{
    
     Logger* logger1 = Logger::getLogger();
    logger1->log("This messgae is from user1");
}

void user2logs()
{
    Logger* logger2 = Logger::getLogger();
    logger2->log("This messgae is from user2");
}

int main()
{
    thread t1(user1logs);
    thread t2(user2logs);

    t1.join();
    t2.join();

    return 0;
}