#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>




class Logger {
public:
    enum class Level {
        ERROR = 1,
        WARNING = 2,
        INFO = 4,
        DEBUG = 8
    };


    static Logger& getInstance(const std::string& filename = "log.txt") {
        static Logger instance(filename);
        return instance;
    }


    Logger(const Logger&) = delete;
    void operator=(const Logger&) = delete;


    void setLevel(Level level) {
        curLevel = level;
    }


    void log(const std::string& message, Level level) {
        if (level > curLevel) {
            return;
        }

        std::time_t now = std::time(nullptr);
        char* timeStr = std::ctime(&now); 

        std::string stime = timeStr;
        stime.pop_back(); 

        logFile << stime << '\t' << "[" << levelToString(level) << "] " << message << '\n';

    }

private:

    std::ofstream logFile;
    Level curLevel;


    Logger(const std::string& filename) {
        logFile.open(filename, std::ios::trunc); 
    }


    ~Logger() {
        if (logFile.is_open()) {
            logFile.close();
        }
    }


    std::string levelToString(Level level) {
        switch (level) {
            case Level::ERROR:   
                return "ERROR";
            case Level::WARNING: 
                return "WARNING";
            case Level::INFO:    
                return "INFO";
            default:   
                return "DEBUG";
        }
    }
};





class TrackedString {
private:
    std::string value;
    int id;             
    static int counter; 


    std::string getAddr() const {
        std::stringstream ss;
        ss << (void*)this;
        return ss.str();
    }

public:
    TrackedString() : id(++counter), value("") {
        Logger::getInstance().log("[default ctor] id=" + std::to_string(id) + " this=" + getAddr(),
            Logger::Level::INFO);
    }


    TrackedString(const std::string& s) : id(++counter), value(s) {
        Logger::getInstance().log( "[string ctor] id=" + std::to_string(id) + " this=" + getAddr(),
            Logger::Level::INFO);
    }

    TrackedString(const char* s) : id(++counter), value(s) {
        Logger::getInstance().log("[char* ctor] id=" + std::to_string(id) + " this=" + getAddr(),
            Logger::Level::INFO);
    }


    TrackedString(const TrackedString& other) : id(++counter), value(other.value) {
        Logger::getInstance().log( "[copy ctor] id=" + std::to_string(id) + " this=" + getAddr() + " from id=" + std::to_string(other.id),
            Logger::Level::INFO);
    }


    TrackedString(TrackedString&& other) : id(++counter), value(std::move(other.value)) {
        Logger::getInstance().log( "[move ctor] id=" + std::to_string(id) + " this=" + getAddr() + " from id=" + std::to_string(other.id),
            Logger::Level::INFO);
    }

    ~TrackedString() {
        Logger::getInstance().log(
            "[dtor] id=" + std::to_string(id) + " this=" + getAddr(),
            Logger::Level::INFO
        );
    }
};






int TrackedString::counter = 0;


int main() {
    Logger::getInstance().setLevel(Logger::Level::INFO);
    
    TrackedString a;                    
    TrackedString b("hello");           
    std::string s = "world";
    TrackedString c(s);                 
    TrackedString d = c;                

    return 0;
}




