#include <iostream>
#include <string>


enum class ParamType {
    INT,
    DOUBLE,
    BOOL,
    STRING,
};


union ParamValue {
    int i;
    double d;
    bool b;
    char s[64];
};

struct ConfigEntry {
    std::string name;
    ParamType type;
    ParamValue value;
};