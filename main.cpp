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
    
    const int STOCK_COUNT = 24;
    
    enum ticker {MRO, GD, ABEV, BA, AXP, PFE, MCD, BRKB, BAC, BUD, EADSY, IMBBY, WFC, CLB, EPD, BTI, ENB, VTRS, RHHBY, SLB, XOM, HBI, INGR, RDSB};
    
    stock portfolio[STOCK_COUNT];
    
    // Initialize all stocks
    
    portfolio[MRO] = stock("Marathon Oil", "MRO", 1, 0);
    portfolio[GD] = stock("General Dynamics", "GD", 3, 399.84);
    portfolio[ABEV] = stock("AmBev", "ABEV", 67, 140.55);
    portfolio[BA] = stock("Boeing", "BA", 4, 526.16);
    portfolio[AXP] = stock("American Express", "AXP", 6, 523.24);
    portfolio[PFE] = stock("Pfizer", "PFE", 198, 6'938.45);
    portfolio[MCD] = stock("McDonalds", "MCD", 4, 741.08);
    portfolio[BRKB] = stock("Berkshire Hathaway", "BRK.B", 7, 1'252.53);
    portfolio[BAC] = stock("Bank of America", "BAC", 15, 345.62);
    portfolio[BUD] = stock("Anheuser Busch InBev", "BUD", 9, 480.77);
    portfolio[EADSY] = stock("Airbus", "EADSY", 39, 743.73);
    portfolio[IMBBY] = stock("Imperial Brands", "IMBBY", 139, 2'340.40);
    portfolio[WFC] = stock("Wells Fargo", "WFC", 154, 3'673.35);
    portfolio[CLB] = stock("Core Laboratories", "CLB", 201, 3'495.17);
    portfolio[EPD] = stock("Enterprise Products", "EPD", 22, 363.79);
    portfolio[BTI] = stock("British American Tobacco", "BTI", 34, 1'156.81);
    portfolio[ENB] = stock("Enbridge", "ENB", 35, 1'033.90);
    portfolio[VTRS] = stock("Viatris", "VTRS", 24, 0);
    portfolio[RHHBY] = stock("Roche", "RHHBY", 2, 84.52);
    portfolio[SLB] = stock("Schlumberger", "SLB", 31, 678.59);
    portfolio[XOM] = stock("Exxon Mobil", "XOM", 6, 276.93);
    portfolio[HBI] = stock("Hanesbrands", "HBI", 11, 170.00);
    portfolio[INGR] = stock("Ingredion", "INGR", 30, 2'347.65);
    portfolio[RDSB] = stock("Shell", "RDS.B", 43, 1'574.53);
    
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

