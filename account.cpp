#include "account.h"

// Konstruktor: validatsiya bilan boshlash
Account::Account(std::string accountName, int initialBalance)
    : name{accountName}, balance{0}, history{""}, transactionCount{0}
{
    if (initialBalance > 0) {
        balance = initialBalance;
        history += "[OCHILDI] Boshlang'ich balans: " + std::to_string(initialBalance) + " so'm\n";
    } else {
        history += "[OCHILDI] Boshlang'ich balans: 0 so'm (manfiy qiymat rad etildi)\n";
    }
}

// Depozit: faqat musbat summani qabul qiladi
bool Account::deposit(int amount) {
    if (amount <= 0) {
        history += "[XATO] Depozit rad etildi: " + std::to_string(amount) + " so'm (manfiy yoki nol)\n";
        return false;
    }
    balance += amount;
    transactionCount++;
    history += "[DEPOZIT] +" + std::to_string(amount) + " so'm | Balans: " + std::to_string(balance) + " so'm\n";
    return true;
}

// Yechib olish: balansdan ortiq bo'lsa rad etadi
bool Account::withdraw(int amount) {
    if (amount <= 0) {
        history += "[XATO] Yechib olish rad etildi: manfiy summa\n";
        return false;
    }
    if (amount > balance) {
        history += "[XATO] Yetarli mablag' yo'q! So'ralgan: " + std::to_string(amount) +
                   " so'm | Mavjud: " + std::to_string(balance) + " so'm\n";
        return false;
    }
    balance -= amount;
    transactionCount++;
    history += "[YECHIB OLISH] -" + std::to_string(amount) + " so'm | Balans: " + std::to_string(balance) + " so'm\n";
    return true;
}

std::string Account::getName() const  { return name; }
int         Account::getBalance() const { return balance; }
int         Account::getTransactionCount() const { return transactionCount; }
void        Account::setName(std::string newName) { name = newName; }
std::string Account::getHistory() const { return history; }

void Account::reset() {
    balance = 0;
    history += "[RESET] Hisob nolga qaytarildi\n";
}
