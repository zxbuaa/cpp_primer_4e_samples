/*
 * This file contains code from "C++ Primer, Fourth Edition", by Stanley B.
 * Lippman, Jose Lajoie, and Barbara E. Moo, and is covered under the
 * copyright and warranty notices given in that book:
 * 
 * "Copyright (c) 2005 by Objectwrite, Inc., Jose Lajoie, and Barbara E. Moo."
 * 
 * 
 * "The authors and publisher have taken care in the preparation of this book,
 * but make no expressed or implied warranty of any kind and assume no
 * responsibility for errors or omissions. No liability is assumed for
 * incidental or consequential damages in connection with or arising out of the
 * use of the information or programs contained herein."
 * 
 * Permission is granted for this code to be used for educational purposes in
 * association with the book, given proper citation if and when posted or
 * reproduced.Any commercial use of this code requires the explicit written
 * permission of the publisher, Addison-Wesley Professional, a division of
 * Pearson Education, Inc. Send your request for permission, stating clearly
 * what code you would like to use, and in what specific way, to the following
 * address: 
 * 
 * 	Pearson Education, Inc.
 * 	Rights and Contracts Department
 * 	75 Arlington Street, Suite 300
 * 	Boston, MA 02216
 * 	Fax: (617) 848-7047
*/ 

#include <iostream>
#include <list>
#include <map>
#include "Sales_item.h"

int main() 
{
    // declare variables to hold running sum and data for the next record 
    Sales_item total, trans;

    // use a map to store sales items with same isbn in a group
    std::map<std::string, std::list<Sales_item> > db;
    while (std::cin >> trans) {
        std::string k = trans.get_isbn();
        db[k].push_back(trans);
    }

    // traverse the map
    for (std::map<std::string, std::list<Sales_item> >::const_iterator it = db.begin();
            it != db.end(); it++) {
        Sales_item total(it->first);
        std::list<Sales_item> sales_items = it->second;
        for (std::list<Sales_item>::const_iterator i = sales_items.begin();
                i != sales_items.end(); i++) {
            total += *i;
        }
        std::cout << total << std::endl;
    }


    return 0;
}
