#include "book.h"
#include "util.h"
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

Book::Book(const string name, double price, int qty, string author, string ISBN) :
     Product("book", name, price, qty),
     author_(author),
     ISBN_(ISBN) {}

Book::~Book()
{

}

set<string> Book::keywords() const
{
     set<string> keywords;
     set<string> temp = parseStringToWords(name_);
     keywords = setUnion(keywords, temp);
     temp = parseStringToWords(author_);
     keywords = setUnion(keywords, temp);
     keywords.insert(ISBN_);

     return keywords;
}

string Book::displayString() const
{
     ostringstream precisionFixer;
     precisionFixer << fixed;
     precisionFixer << std::setprecision(2);
     precisionFixer << price_;
     return name_
          + "\nAuthor: " + author_ + " ISBN: " + ISBN_
          + "\n" + precisionFixer.str() + " " + to_string(qty_);
}

void Book::dump(ostream& os) const
{
     os << category_ << endl
          << name_ << endl
          << fixed << setprecision(2) << price_ << endl
          << qty_ << endl
          << ISBN_ << endl
          << author_ << endl;
}