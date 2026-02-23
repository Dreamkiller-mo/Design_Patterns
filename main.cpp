#include <iostream>
#include "Operator.h"

using namespace std;

int main() {
    double a, b;
    int choice;

    std::cout << "Enter two numbers: ";
    std::cin >> a >> b;

    std::cout << "Choose operation:\n";
    std::cout << "1. Add\n2. Subtract\n3. Multiply\n4. Divide\n";
    std::cin >> choice;

    // 创建工厂对象
    Factory factory(choice);

    // 使用普通指针（需要手动 delete）
    Operation* op = factory.Choose();
    if (op == nullptr) {
        return 1;  // 非法选择
    }

    // 设置操作数
    op->number_A = a;
    op->number_B = b;

    // 计算并输出结果
    double res = op->Result();
    std::cout << "Result: " << res << std::endl;

    // 释放内存
    delete op;

    return 0;
}