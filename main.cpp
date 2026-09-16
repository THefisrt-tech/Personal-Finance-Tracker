#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <numeric>

struct Transaction {
    std::string date;
    std::string category;
    std::string description;
    double amount;
};

class FinanceTracker {
private:
    std::vector<Transaction> transactions;
    double monthlyBudget;

public:
    FinanceTracker(double budget = 0.0) : monthlyBudget(budget) {}

    void setBudget(double budget) {
        monthlyBudget = budget;
        std::cout << "Monthly budget set to: $" << std::fixed << std::setprecision(2) << monthlyBudget << "\n";
    }

    void addTransaction(const std::string& date, const std::string& category, const std::string& description, double amount) {
        transactions.push_back({date, category, description, amount});
        std::cout << "Transaction added successfully!\n";
    }

    void displayTransactions() const {
        if (transactions.empty()) {
            std::cout << "No transactions recorded yet.\n";
            return;
        }

        std::cout << "\n--- All Transactions ---\n";
        std::cout << std::left << std::setw(12) << "Date" 
                  << std::setw(18) << "Category" 
                  << std::setw(25) << "Description" 
                  << std::right << std::setw(10) << "Amount ($)" << "\n";
        std::cout << std::string(65, '-') << "\n";

        for (const auto& t : transactions) {
            std::cout << std::left << std::setw(12) << t.date 
                      << std::setw(18) << t.category 
                      << std::setw(25) << t.description 
                      << std::right << std::setw(10) << std::fixed << std::setprecision(2) << t.amount << "\n";
        }
    }

    void displaySummary() const {
        double totalSpending = 0.0;
        for (const auto& t : transactions) {
            totalSpending += t.amount;
        }

        std::cout << "\n=== Financial Summary ===\n";
        std::cout << "Monthly Budget : $" << std::fixed << std::setprecision(2) << monthlyBudget << "\n";
        std::cout << "Total Spent    : $" << totalSpending << "\n";
        
        if (monthlyBudget > 0) {
            double remaining = monthlyBudget - totalSpending;
            if (remaining >= 0) {
                std::cout << "Remaining      : $" << remaining << " (Within Budget)\n";
            } else {
                std::cout << "Remaining      : -$" << -remaining << " (OVER BUDGET!)\n";
            }
        }
    }
};

int main() {
    FinanceTracker tracker(500.0);

    tracker.addTransaction("2026-09-01", "Groceries", "Campus Store Supplies", 45.50);
    tracker.addTransaction("2026-09-05", "Books", "C++ Programming Guide", 65.00);
    tracker.addTransaction("2026-09-10", "Dining", "Sodexo Meal Pass", 25.00);

    tracker.displayTransactions();
    tracker.displaySummary();

    return 0;
}
