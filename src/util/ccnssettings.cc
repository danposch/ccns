#include "ccnssettings.h"

using namespace ccns::util;

CCNSSettings* CCNSSettings::set = NULL;

CCNSSettings* CCNSSettings::Instance()
{
    if(set == NULL)
        set = new CCNSSettings;
    return set;
}

void CCNSSettings::write(const std::string& key, const std::string &value)
{
    CCNSSettings* set = CCNSSettings::Instance();
    set->pt.put(key.c_str(), value.c_str());

    std::string dir;
    dir.append(getenv("HOME"));
    dir.append("/.ccns/");

    if(!boost::filesystem::exists(dir))
        boost::filesystem::create_directory(dir);

    dir.append("ccns_config.ini");

    boost::property_tree::ini_parser::write_ini(dir.c_str(), set->pt);
}

void CCNSSettings::print()
{
    CCNSSettings* set = CCNSSettings::Instance();
    fprintf(stderr, "CCNS_SETTINGS:\n");
    set->print(set->pt);
}

void CCNSSettings::print(boost::property_tree::ptree const& pt) const
{
    boost::property_tree::ptree::const_iterator end = pt.end();
    for (boost::property_tree::ptree::const_iterator it = pt.begin(); it != end; ++it)
    {
        fprintf(stderr, "%s: %s\n", it->first.c_str(), it->second.get_value<std::string>().c_str());
        print(it->second);
    }
}

std::string CCNSSettings::read(const std::string& key)
{
    CCNSSettings* set = CCNSSettings::Instance();

    return set->pt.get<std::string>(key.c_str());
}

CCNSSettings::CCNSSettings()
{
    std::string filepath;
    filepath.append(getenv("HOME"));
    filepath.append("/.ccns/ccns_config.ini");

    if(boost::filesystem::exists(filepath.c_str()))
        boost::property_tree::ini_parser::read_ini(filepath.c_str(), pt);
    else
        fprintf(stderr, "Settings do not exist yet.\n");
}
