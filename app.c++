
#include <iostream>
#include <string>
#include <limits>
using namespace std;

class bank
{
    string name, add;
    char y;
    double balance = 0.0;
    bool account_open = false;

public:
    void open_account();
    void deposite_money();
    void withdraw_money();
    void display_account();
};

void bank::open_account()
{
    if (account_open)
    {
        cout << "\nAccount is already open!\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter your full name: ";
    getline(cin, name);

    cout << "Enter your address: ";
    getline(cin, add);

    cout << "Choose account type (Saving: s / Current: c): ";
    cin >> y;

    if (y != 's' && y != 'S' && y != 'c' && y != 'C')
    {
        cout << "Invalid account type!\n";
        return;
    }

    cout << "Enter initial deposit amount: ";
    if (!(cin >> balance) || balance < 0)
    {
        cout << "Invalid deposit amount!\n";
        balance = 0;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    account_open = true;
    cout << "\nAccount created successfully!\n";
}

void bank::deposite_money()
{
    if (!account_open)
    {
        cout << "\nPlease open an account first!\n";
        return;
    }

    double a;
    cout << "Enter amount to deposit: ";

    if (!(cin >> a) || a <= 0)
    {
        cout << "Please enter a valid positive amount!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    balance += a;
    cout << "Deposit successful!\n";
    cout << "Updated balance: " << balance << '\n';
}

void bank::withdraw_money()
{
    if (!account_open)
    {
        cout << "\nPlease open an account first!\n";
        return;
    }

    double amount;
    cout << "Enter amount to withdraw: ";

    if (!(cin >> amount) || amount <= 0)
    {
        cout << "Please enter a valid positive amount!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    if (amount > balance)
    {
        cout << "Insufficient balance!\n";
        return;
    }

    balance -= amount;
    cout << "Withdrawal successful!\n";
    cout << "Remaining balance: " << balance << '\n';
}

void bank::display_account()
{
    if (!account_open)
    {
        cout << "\nPlease open an account first!\n";
        return;
    }

    cout << "\n----- ACCOUNT DETAILS -----\n";
    cout << "Name: " << name << '\n';
    cout << "Address: " << add << '\n';
    cout << "Account type: "
         << ((y == 's' || y == 'S') ? "Saving" : "Current")
         << '\n';
    cout << "Current balance: " << balance << '\n';
    cout << "---------------------------\n";
}

int main()
{
    bank obj;
    int ch;

    do
    {
        cout << "\n===== BANK MANAGEMENT SYSTEM =====\n";
        cout << "1. Open Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Display Account\n";
        cout << "5. Exit\n";
        cout << "Select an option: ";

        if (!(cin >> ch))
        {
            cout << "Invalid input! Enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (ch)
        {
            case 1:
                obj.open_account();
                break;

            case 2:
                obj.deposite_money();
                break;

            case 3:
                obj.withdraw_money();
                break;

            case 4:
                obj.display_account();
                break;

            case 5:
                cout << "Thank you for using the Bank Management System!\n";
                break;

            default:
                cout << "Invalid choice! Please select 1 to 5.\n";
        }

    } while (ch != 5);

    return 0;
}
