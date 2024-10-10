#include <iostream>
#include <fstream>

class BinOp {
private:
    double opnd1;
    char op;
    double opnd2;

public:
    // setter methods
    void setOpnd1(double val) {
        opnd1 = val;
    }

    void setOp(char value) {
        if (value != '+' && value != '-' && value != '*' && value != '/')
            throw std::invalid_argument("Invalid operator");
        
        op = value;
    }

    void setOpnd2(double val) {
        opnd2 = val;
    }

    // getter methods
    double getOpnd1() const {
        return opnd1;
    }

    char getOp() const {
        return op;
    }

    double getOpnd2() const {
        return opnd2;
    }

    double evaluate() const {
        switch (op) {
            case '+': return opnd1 + opnd2;
            case '-': return opnd1 - opnd2;
            case '*': return opnd1 * opnd2;
            case '/':
                if (opnd2 == 0) // Check for division by zero
                    throw std::runtime_error("Division by zero");
                return opnd1 / opnd2;
        }
    }
};

int main() {
    const int SIZE = 3; // Fixed size as per requirement
    BinOp* expressions = new BinOp[SIZE]; // Array on heap
    int count = 0;

    std::cout << "Enter expressions (opnd1 op opnd2):\n";
    
    /*
    // use std::getline() combined with parsing the resulting strings as an std::istringsstream

    std::string line;
    while (count < SIZE && std::getline(std::cin, line)) {
        std::istringstream iss(line);
        double opnd1, opnd2;
        char op;

        if (iss >> opnd1 >> op >> opnd2) {
            expressions[count].setOpnd1(opnd1);
            expressions[count].setOp(op);
            expressions[count].setOpnd2(opnd2);
            count++;
        } else {
            std::cerr << "Invalid input. Please enter in the format: opnd1 op opnd2\n";
        }
    */
   
    while (count < SIZE) {
        double opnd1, opnd2;
        char op;
        
        // Check if input is valid and break if not
        if (!(std::cin >> opnd1 >> op >> opnd2)) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(10000, '\n'); // Discard the rest of the line
            break;
        }
        
        expressions[count].setOpnd1(opnd1);
        expressions[count].setOp(op);
        expressions[count].setOpnd2(opnd2);
        count++;
    }

    std::ofstream outFile("results.txt");
    if (!outFile) {
        std::cerr << "Unable to open file for writing\n";
        return 1;
    }

    for (int i = 0; i < count; i++) {
        double result = expressions[i].evaluate();
        outFile << expressions[i].getOpnd1() << " " << expressions[i].getOp() << " " 
                << expressions[i].getOpnd2() << " = " << result << "\n";
    }
    
    outFile.close();
    delete[] expressions;
    return 0;
}