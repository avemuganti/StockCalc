#include "stock.hpp"

using namespace std;

double stock::money;

stock::stock() {
    
    name = "REDO INPUT";
    ticker = "";
    shareCount = 0;
    totalCost = 0;
    
}

stock::stock(string n, string t, int count, double totCost) {
    
    name = n;
    ticker = t;
    shareCount = count;
    totalCost = totCost;
    
}

void stock::setName(string n) {
    
    name = n;
    
}

string stock::getName() const {
    
    return name;
    
}

void stock::setTicker(string t) {
    
    ticker = t;
    
}

string stock::getTicker() const {
    
    return ticker;
    
}

void stock::setShareCount(int s) {
    
    shareCount = s;
    
}

int stock::getShareCount() const {
    
    return shareCount;
    
}

void stock::setTotalCost(double c) {
    
    totalCost = c;
    
}

double stock::getTotalCost() const {
    
    return totalCost;
    
}

void stock::setSharePrice(double p) {
    
    sharePrice = p;
    
}

double stock::getSharePrice() const {
    
    return sharePrice;
    
}

double stock::generateCoefficient() const {
    
    if (!totalCost ||(100 * (1 - (sharePrice * shareCount) / totalCost)) == 0) {
        return -1;
    }
    double coef = sharePrice / ((100 * (1 - (sharePrice * shareCount) / totalCost)) / (shareCount + 1));
    if (coef < 0) {
        return -1;
    }
    return coef;
    
}

void stock::setBuyCount(int c) {
    
    buyCount = c;
    
}

int stock::getBuyCount() const {
    
    return buyCount;
    
}

void stock::buy() {
    
    setShareCount(shareCount + 1);
    setTotalCost(totalCost + sharePrice);
    money -= sharePrice;
    setBuyCount(buyCount + 1);
    
}

void stock::undoBuy() {
    
    setShareCount(shareCount - 1);
    setTotalCost(totalCost - sharePrice);
    money += sharePrice;
    setBuyCount(buyCount - 1);
    
}
