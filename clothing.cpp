#include "clothing.h"
#include "util.h"
#include <iostream>
#include <iomanip>

using namespace std;

Clothing::Clothing(const string name, double price, int qty, string size, string brand) :
     Product("clothing", name, price, qty),
     size_(size),
     brand_(brand) {}

Clothing::~Clothing()
{

}

set<string> Clothing::keywords() const
{
     set<string> keywords;
     set<string> temp = parseStringToWords(name_);
     keywords = setUnion(keywords, temp);
     temp = parseStringToWords(brand_);
     keywords = setUnion(keywords, temp);

     return keywords;
}

string Clothing::displayString() const
{
     return category_ + " "
          + name_+ " "
          + to_string(price_) + " "
          + to_string(qty_) + " "
          + size_ + " "
          + brand_;
}

void Clothing::dump(ostream& os) const
{
     os << category_ << endl
          << name_ << endl
          << fixed << setprecision(2) << price_ << endl
          << qty_ << endl
          << size_ << endl
          << brand_ << endl;
}