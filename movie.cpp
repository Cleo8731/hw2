#include "movie.h"
#include "util.h"
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

Movie::Movie(const string name, double price, int qty, string genre, string rating) :
     Product("movie", name, price, qty),
     genre_(genre),
     rating_(rating) {}

Movie::~Movie()
{

}

set<string> Movie::keywords() const
{
     set<string> keywords;
     set<string> temp = parseStringToWords(name_);
     keywords = setUnion(keywords, temp);
     temp = parseStringToWords(genre_);
     keywords = setUnion(keywords, temp);

     return keywords;
}

string Movie::displayString() const
{
     ostringstream precisionFixer;
     precisionFixer << fixed;
     precisionFixer << std::setprecision(2);
     precisionFixer << price_;
     return name_
          + "\nGenre: " + genre_ + " Rating: " + rating_
          + "\n" + precisionFixer.str() + " " + to_string(qty_);
}

void Movie::dump(ostream& os) const
{
     os << category_ << endl
          << name_ << endl
          << fixed << setprecision(2) << price_ << endl
          << qty_ << endl
          << genre_ << endl
          << rating_ << endl;
}