#include <iostream>
#include <map>
#include <iomanip>

using namespace std;

// Hardcoded exchange rates relative to 1 USD
map<string, double> exchangeRates = {
    {"USD", 1.00},
    {"EUR", 0.92},
    {"JPY", 155.65},
    {"AUD", 1.49},
    {"CAD", 1.36},
    {"GBP", 0.78},
    {"INR", 83.12},
    {"CNY", 7.27}
};

void showCurrencies() {
    cout << "Available currencies:\n";
    for (const auto& [code, rate] : exchangeRates) {
        cout << " - " << code << "\n";
    }
    cout << endl;
}

int main() {
    string from, to;
    double amount;

    cout << fixed << setprecision(2);
    cout << "=== CURRENCY CONVERTER ===\n\n";
    showCurrencies();

    cout << "Enter currency code to convert FROM (e.g. USD): ";
    cin >> from;

    cout << "Enter currency code to convert TO (e.g. EUR): ";
    cin >> to;

    // Convert to uppercase (simple normalization)
    for (auto& c : from) c = toupper(c);
    for (auto& c : to) c = toupper(c);

    if (exchangeRates.find(from) == exchangeRates.end() ||
        exchangeRates.find(to) == exchangeRates.end()) {
        cout << "Invalid currency code!\n";
        return 1;
    }

    cout << "Enter amount in " << from << ": ";
    cin >> amount;

    // Convert using USD as base
    double inUSD = amount / exchangeRates[from];
    double converted = inUSD * exchangeRates[to];

    cout << "\n" << amount << " " << from << " = " << converted << " " << to << "\n";
    cout << "===========================\n";

    return 0;
}
