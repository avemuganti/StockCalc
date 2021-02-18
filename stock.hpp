#ifndef stock_hpp
#define stock_hpp

#include <stdio.h>
#include <string>

using namespace std;

class stock {
    
public:
    static double money;
    stock();
    stock(string name, string ticker, int shares, double cost);
    void setName(string name);
    string getName() const;
    void setTicker(string ticker);
    string getTicker() const;
    void setShareCount(int shares);
    int getShareCount() const;
    void setTotalCost(double cost);
    double getTotalCost() const;
    void setSharePrice(double price);
    double getSharePrice() const;
    double generateCoefficient() const;
    void setBuyCount(int c);
    int getBuyCount() const;
    void buy();
    void undoBuy();
    
private:
    string name;
    string ticker;
    int shareCount;
    double totalCost;
    double sharePrice = 0;
    int buyCount = 0;
    
};

#endif
