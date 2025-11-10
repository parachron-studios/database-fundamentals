#pragma once
#ifndef __DB_HPP
#define __DB_HPP

#include <string>

class database{
    protected:
        std::string m_name;
        std::string m_fullpath;
    public:
        database(std::string dbname, std::string fullpath);

        std::string getDirectory();
        void setKeyValue(std::string key, std::string value);
        std::string getKeyValue(std::string key);
        void destroy();

        static database createEmpty(std::string dbname);
        static database load(std::string dbname);
};

#endif