#include <iostream>
#include <string>
#include <vector>

enum class Permission {
    READ = 1,       //0001
    WRITE = 2,      //0010
    EXECUTE = 4,    //0100
    DELETE = 8     //1000

};

Permission operator|(Permission p1, Permission p2) {
    return (Permission)((int)(p1) | (int)(p2));
}
Permission operator&(Permission p1, Permission p2) {
    return (Permission)((int)(p1) & (int)(p2));
}
Permission operator~(Permission p) {
    return (Permission) ~(int)(p);
}

bool is_allowed(Permission p1, Permission p2) {
    return (p1 & p2) == p2;
}

struct User {
    std::string name;
    Permission p;
};

int main() {
    std::vector<User> users = {
        {"name1", Permission::READ | Permission::WRITE},
        {"name2", Permission::READ | Permission::EXECUTE},
        {"name3", Permission::DELETE}
    };

    for (const auto& user : users) {
        std::cout << "\nUser " << user.name << " permissions:\n READ\t";
        std::cout << is_allowed(user.p, Permission::READ) << "\nWRITE\t";
        std::cout << is_allowed(user.p, Permission::WRITE) << "\nEXECUTE\t ";
        std::cout << is_allowed(user.p, Permission::EXECUTE) << "\n DELETE\t ";
        std::cout << is_allowed(user.p, Permission::DELETE);
    }
    return 0;
}