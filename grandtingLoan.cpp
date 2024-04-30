#include <iostream>
#include <limits>
#include <vector>

using namespace std;

// Forward declaration of the BankersAlgorithm class
class BankersAlgorithm;

// Function prototypes
bool isSafeState(int availableMoney, int requestedAmount);

class BankersAlgorithm {
public:
    BankersAlgorithm(int totalMoney);

    bool requestLoan(int requestedAmount);
    void returnLoan(int returnedAmount);

public:
    int totalMoney;
    int availableMoney;

    friend bool isSafeState(int availableMoney, int requestedAmount);
};

BankersAlgorithm::BankersAlgorithm(int totalMoney) : totalMoney(totalMoney), availableMoney(totalMoney) {}

bool BankersAlgorithm::requestLoan(int requestedAmount) {
    if (requestedAmount > availableMoney || !isSafeState(availableMoney, requestedAmount)) {
        cout << "Loan request denied. Insufficient funds or unsafe state." << endl;
        return false;
    }

    // Simulate granting the loan
    availableMoney -= requestedAmount;
    cout << "Loan of $" << requestedAmount << " granted or safe state. Available funds: $" << availableMoney << endl;
    return true;
}

void BankersAlgorithm::returnLoan(int returnedAmount) {
    // Simulate returning the loan
    availableMoney += returnedAmount;
    cout << "Returned loan of $" << returnedAmount << ". Available funds: $" << availableMoney << endl;
}

bool isSafeState(int availableMoney, int requestedAmount) {
    return availableMoney - requestedAmount >= 0;
}

int main() {
    int totalMoney;
    cout << "Enter the total amount of money in the bank: $";
    cin >> totalMoney;

    // Input validation
    while (cin.fail() || totalMoney < 0) {
        cout << "Invalid input. Please enter a valid amount: $";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> totalMoney;
    }

    BankersAlgorithm banker(totalMoney);

    int choice;
    do {
        cout << "\n1. Request Loan\n";
        cout << "2. Return Loan\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Input validation
        while (cin.fail() || (choice < 1 || choice > 3)) {
            cout << "Invalid choice. Please enter a valid option: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> choice;
        }

        switch (choice) {
            case 1: {
                int requestedAmount;
                cout << "Enter the loan request amount: $";
                cin >> requestedAmount;

                // Input validation
                while (cin.fail() || requestedAmount < 0) {
                    cout << "Invalid input. Please enter a valid amount: $";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> requestedAmount;
                }
                
                banker.requestLoan(requestedAmount);
                break;
            }

            case 2: {
                int returnedAmount;
                cout << "Enter the returned amount: $";
                cin >> returnedAmount;

                // Input validation
                while (cin.fail() || returnedAmount < 0) {
                    cout << "Invalid input. Please enter a valid amount: $";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> returnedAmount;
                }

                banker.returnLoan(returnedAmount);
                break;
            }

            case 3:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 3);

    return 0;
}
