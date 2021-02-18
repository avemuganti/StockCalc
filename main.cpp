#include <iostream>
#include <float.h>
#include <iomanip>
#include "stock.hpp"

using namespace std;

int countCommas(string s); // Counts the commas in a string.
void removeSpaces(string& s); // Removes spaces in a string.
void populateArray(string *b, string str);
int findMinCoefIdx(stock *s, int length); // -1 does not count.

int main() {
    
    // Data for all owned stock.
    // TODO: For every stock you own, add 1 to this value.
    
    const int STOCK_COUNT = 1;
    
    // TODO: Add all ticker symbols here. The number of elements here should equal STOCK_COUNT.
    enum ticker {EXAMPLE};
    
    stock portfolio[STOCK_COUNT];
    
    // Initialize all stocks
    // TODO: Add all stocks in your portfolio.
    // EXAMPLE & USAGE: portfolio[TICKER] = stock("CompanyName", "TICKER", sharesOwned, totalPricePaid);. Example below.
    
    portfolio[EXAMPLE] = stock("Example Company", "EXAMPLE", 1, 100);
    
    double mon;
    
    cout << "How much money is in your brokerage? : ";
    
    cin >> mon;
    stock::money = mon;
    cin.ignore(10000, '\n');
    
    cout << "On what stocks are you losing money? : ";
    
    string lossyStocks;
    getline(cin, lossyStocks);
    removeSpaces(lossyStocks);
    int buysLength = countCommas(lossyStocks) + 1;
    string *buys;
    buys = new string[buysLength];
    populateArray(buys, lossyStocks);
    
    stock *buy;
    buy = new stock[buysLength];
    
    for (int i = 0; i < buysLength; i++) {
        
        for (int j = 0; j < STOCK_COUNT; j++) {
            if (buys[i] == portfolio[j].getTicker()) {
                buy[i] = portfolio[j];
                break;
            }
        }
        
    }
    
    cout << endl;
    
    for (int i = 0; i < buysLength; i++) {
        double price;
        cout << "What is the share price of " << buy[i].getName() << "? : ";
        cin >> price;
        buy[i].setSharePrice(price);
    }
    
    while (stock::money > 0) {
        int index = findMinCoefIdx(buy, buysLength);
        buy[index].buy();
        if (stock::money < 0) {
            buy[index].undoBuy();
            break;
        }
    }
    
    cout << endl;
    
    for (int i = 0; i < buysLength; i++) {
        cout << buy[i].getName() << ": " << buy[i].getBuyCount() << endl;
    }
    
    cout << fixed << showpoint << setprecision(2) << endl;
    cout << "You will have $" << stock::money << " left." << endl << endl;
    
    return 0;
    
}

int countCommas(string str) {
    
    int count = 0;
    
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 44) {
            count++;
        }
    }
    
    return count;
    
}

void removeSpaces(string& str) {
    
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 32) {
            str = str.substr(0, i) + str.substr(i + 1);
        }
    }
    
}

void populateArray(string* arr, string str) {
    
    int i = 0;
    
    for (int j = 0; j < str.length(); j++) {
        if (str[j] != 44) {
            arr[i] += str[j];
        } else {
            i++;
        }
    }
    
}

int findMinCoefIdx(stock *s, int length) { // length is the length of array s[]
    
    int idx = -1;
    double minCoef = DBL_MAX;
    
    for (int i = 0; i < length; i++) {
        if (s[i].generateCoefficient() > 0 && s[i].generateCoefficient() < minCoef) {
            minCoef = s[i].generateCoefficient();
            idx = i;
        }
    }
    
    return idx;
    
}

