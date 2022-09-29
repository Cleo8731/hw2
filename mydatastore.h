#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <string>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include "product.h"
#include "user.h"
#include "datastore.h"

class MyDataStore : public DataStore {
public:
     MyDataStore();
     ~MyDataStore();

     /**
     * Adds a product to the data store
     */
     void addProduct(Product* p);

     /**
     * Adds a user to the data store
     */
     void addUser(User* u);

     /**
     * Performs a search of products whose keywords match the given "terms"
     *  type 0 = AND search (intersection of results for each term) while
     *  type 1 = OR search (union of results for each term)
     */
     std::vector<Product*> search(std::vector<std::string>& terms, int type);

     /**
     * Reproduce the database file from the current Products and User values
     */
     void dump(std::ostream& ofile);

     bool addToCart(std::string username, Product* product);

     void printCart(std::string username, std::ostream& out);

private:
     std::vector<User*> users_;
     std::vector<Product*> products_;
     std::map<std::string, std::vector<Product*>> carts_;
};

#endif