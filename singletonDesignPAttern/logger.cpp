#include <iostream>
#include "logger.hpp"
using namespace std;
int Logger::cnt=0;
Logger *Logger::loggerInstance = NULL;
mutex Logger::mtx;

Logger::Logger() {
     cnt++;
     cout<<"New instanace created.no of instances "<<cnt<<endl;
}

void Logger::log(string msg)
{
    cout<<msg<<endl;
}

Logger* Logger::getLogger(){
    if(loggerInstance == NULL)//double check logger
    {
       mtx.lock();
        if(loggerInstance == NULL)
            loggerInstance = new Logger();
       mtx.unlock();
    }
    return loggerInstance;
}