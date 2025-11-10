#ifndef __DATABASE_HPP
#define __DATABASE_HPP

#include <string>
#include "database.hpp"

class mydatabase{
    private:

    public:
        mydatabase();

        static database createEmptyDB(std::string& dbname);
        static database loadDB(std::string& dbname);
};

#endif