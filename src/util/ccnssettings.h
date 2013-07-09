#ifndef CCNSSETTINGS_H
#define CCNSSETTINGS_H

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <boost/filesystem.hpp>

namespace ccns
{
    namespace util
    {
        class CCNSSettings
        {
        public:
            static void write(const std::string& key, const std::string &value);
            static std::string read(const std::string& key);
            static void print();

        protected:
            CCNSSettings();
            static CCNSSettings* set;
            static CCNSSettings* Instance();

            void print(boost::property_tree::ptree const& pt) const;
            boost::property_tree::ptree pt;
        };
    }
}
#endif // CCNSSETTINGS_H
