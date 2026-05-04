#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

// ============================================================
//  Account klassi — 3-bobdagi bank hisob raqami
//  Ma'lumotlar: name (ism), balance (balans)
//  Funksiyalar: deposit, withdraw, getBalance, getName, setName
// ============================================================
class Account {
public:
    // Konstruktor: ism va boshlang'ich balansni qabul qiladi
    Account(std::string accountName, int initialBalance);

    // Depozit qilish (musbat summani tekshiradi)
    bool deposit(int amount);

    // Yechib olish (balansdan ortiqmasini tekshiradi)
    bool withdraw(int amount);

    // Getter funksiyalar
    std::string getName() const;
    int getBalance() const;
    int getTransactionCount() const;

    // Setter funksiya
    void setName(std::string newName);

    // Tranzaksiyalar tarixini qaytaradi
    std::string getHistory() const;

    // Hisobni nolga qaytarish
    void reset();

private:
    std::string name;       // egasining ismi (private!)
    int balance;            // joriy balans (private!)
    std::string history;    // tranzaksiyalar tarixi
    int transactionCount;   // tranzaksiyalar soni
};

#endif // ACCOUNT_H
