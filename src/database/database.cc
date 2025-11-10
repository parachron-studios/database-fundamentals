#include "../../include/database.hpp"

#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

database::database(std::string dbname, std::string fullpath) : m_name(dbname), m_fullpath(fullpath) {}

std::string database::getDirectory(){
    return m_fullpath;
}

void database::setKeyValue(std::string key, std::string value){
    std::ofstream os;
    os.open(m_fullpath + "/" + key + "_string.kv", std::ios::out | std::ios::trunc);
    os << value;
    os.close();
}

std::string database::getKeyValue(std::string key){
    std::ifstream t(m_fullpath + "/" + key + "_string.kv");
    std::string value;

    t.seekg(0, std::ios::end);
    value.reserve(t.tellg());
    t.seekg(0, std::ios::beg);

    value.assign((std::istreambuf_iterator<char>(t)),
                  std::istreambuf_iterator<char>());
    return value;
}

void database::destroy(){
    if(fs::exists(m_fullpath)){
        fs::remove_all(m_fullpath);
    }
}

database database::createEmpty(std::string dbname){
    std::string basedir("mydatabase");
    if(!fs::exists(basedir)){
        fs::create_directory(basedir);
    }
    
    std::string dbfolder(basedir + "/" + dbname);
    if(!fs::exists(dbfolder)){
        fs::create_directory(dbfolder);
    }
    return database(dbname,dbfolder);
}

    database database::load(std::string dbname){
    std::string basedir("mydatabase");
    std::string dbfolder(basedir + "/" + dbname);
    return database(dbname,dbfolder);
}