#include <iostream>
#include "money.h"

using namespace std;

        Money::Money(int d, int c)
        {
           pennies = d * 100 + c;
        }
        Money::Money(int d)
        {
           pennies = d * 100;
        }
        int Money::Dollars() const { return pennies / 100; }
        int Money::Cents()   const { return pennies % 100; }

        void Money::Print()  const
        {
           cout << "$" << Dollars() << ".";
           if ( Cents() < 10 ) cout << "0";
           cout << Cents();
        }
        void Money::Add(const Money &other)
        {
           pennies += other.pennies;
        }
        void Money::AddInterest(float rate)
        {
           pennies += int(pennies * rate + 0.5);
        }
