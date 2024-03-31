#ifndef logger_h
#define logger_h

#include <string>
#include <mutex>
using namespace std;

class Logger {
    static int cnt;
    Logger();
    static mutex mtx;
    static Logger* loggerInstance;

    public:
    static Logger* getLogger();//belong to class
    void log(string msg);
};

#endif
