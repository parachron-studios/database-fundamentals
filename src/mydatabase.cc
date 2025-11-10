#include "../include/mydatabase.hpp"
#include "../include/database.hpp"

#include <filesystem>

namespace fs = std::filesystem;

mydatabase::mydatabase(){

}

database mydatabase::createEmptyDB(std::string &dbname){
    return database::createEmpty(dbname);
}

database mydatabase::loadDB(std::string &dbname){
    return database::load(dbname);
}