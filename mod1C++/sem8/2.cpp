#include <iostream>
#include <vector>
#include <string>

enum class Status {
    NONE = 1,
    CREATED = 2,
    PAID = 4,
    PROCESSING = 8,
    SHIPPED = 16,
    DELIVERED = 32,
    CANCELLED = 64

};

struct Orders {
    int id;
    std::string name;
    Status ord;
};

Status operator|(Status ord1, Status ord2) {
    return (Status)((int)(ord1) | (int)(ord2));
}

Status operator&(Status ord1, Status ord2) {
    return (Status)((int)(ord1) & (int)(ord2));
}


std::vector<Orders> filter(std::vector<Orders>& orders, Status const status) {
    std::vector<Orders> ans;
    for (auto ord : orders) {
        if ((ord.ord & status) == status) {
            ans.push_back(ord);
        } 
    }
    return ans;
}

void changeByIndex(std::vector<Orders>& orders, int index, Status replace) {
    if (index < 0 || index >=orders.size()) {
        std::cout << "Wrong index";
    } else {
        orders[index].ord = replace;
    }
}

void printStatus(const std::vector<Orders>& orders) {
    for (auto ord : orders) {
        std::cout << ord.id << '\t';
        switch (ord.ord) {
            case Status::CREATED:
                std::cout << "CREATED\t";
                break;
            case Status::DELIVERED:
                std::cout << "DELIVERED\t";
                break;
            case Status::CANCELLED:
                std::cout << "CANCELLED\t";
                break;
            case Status::PAID:
                std::cout << "PAID\t";
                break;
            case Status::PROCESSING:
                std::cout << "PROCESSING\t";
                break;
            case Status::SHIPPED:
                std::cout << "SHIPPED\t";
                break;
            default:
                std::cout << "NONE\t";

        }
        std::cout << std::endl;
    }
}
int main() {
    std::vector<Orders> userOrders{
        {1239, "name1", Status::CREATED},
        {6435, "name2", Status::PROCESSING},
        {2832, "name3", Status::DELIVERED}
    };

    printStatus(userOrders);
    std::cout << std::endl;
    auto filteredord = filter(userOrders, Status::CREATED);
    printStatus(filteredord);
}

