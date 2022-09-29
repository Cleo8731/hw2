#include <iostream>
#include "mydatastore.h"
#include "util.h"

using namespace std;

MyDataStore::MyDataStore() :
     users_(), products_(), carts_()
{

}

MyDataStore::~MyDataStore() 
{
     /*map<string, queue<Product*>>::iterator it;
     for (it = carts_.begin(); it != carts_.end(); ++it)
     {

     }*/
}

void MyDataStore::addProduct(Product* p) 
{
     products_.push_back(p);
}

void MyDataStore::addUser(User* u) 
{
     users_.push_back(u);
     vector<Product*> q;
     carts_.insert({u->getName(), q});
}

vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type)
{
     vector<Product*> matches;
     vector<string>::iterator it;
     set<string> terms_;
     for (it = terms.begin(); it != terms.end(); ++it)
     {
          terms_.insert(*it);
     }
     if (!type) // AND
     {
          vector<Product*>::iterator it2;
          for(it2 = products_.begin(); it2 != products_.end(); ++it2)
          {
               set<string> temp = (*it2)->keywords();
               temp = setIntersection(terms_, temp);
               if (temp == terms_) matches.push_back(*it2);
          }
     }
     else // OR
     {
          vector<Product*>::iterator it2;
          for(it2 = products_.begin(); it2 != products_.end(); ++it2)
          {
               set<string> temp = (*it2)->keywords();
               temp = setIntersection(terms_, temp);
               if (temp.size() > 0) matches.push_back(*it2);
          }
     }
     return matches;
}

void MyDataStore::dump(ostream& ofile)
{
     ofile << "<products>\n";
     vector<Product*>::iterator it;
     for(it = products_.begin(); it != products_.end(); ++it)
     {
          (*it)->dump(ofile);
     }
     ofile << "</products>\n";

     vector<User*>::iterator it2;
     ofile << "<users>\n";
     for(it2 = users_.begin(); it2 != users_.end(); ++it2)
     {
          (*it2)->dump(ofile);
     }
     ofile << "</users>\n";
}

bool MyDataStore::addToCart(string username, Product* product)
{
     if (carts_.find(username) == carts_.end()) return false;
     carts_[username].push_back(product);
     return true;
}

void MyDataStore::printCart(string username, ostream& out)
{
     int index = 1;
     vector<Product*>::iterator it;
     for (it = carts_[username].begin(); it != carts_[username].end(); ++it)
     {
          out << "\nItem " << index << endl;
          out << (*it)->displayString() << endl;
          index++;
     }
}