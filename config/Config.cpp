#include "Config.hpp"

boost::property_tree::ptree defaultConfig;
boost::property_tree::ptree currentConfig;

void readDefaultConfig() {
    boost::property_tree::ini_parser::read_ini("/default_conf/config.ini", defaultConfig);
    printf("[CONFIG] Config on /current_conf/config.ini has been read!\n");
}

void readConfig() {
    boost::property_tree::ini_parser::read_ini("/current_conf/config.ini", currentConfig);
    printf("[CONFIG] Config on /current_conf/config.ini has been read!\n");
    //printf("network.eth0Addr: %s", (currentConfig.get<std::string>("network.eth0Addr").c_str()));
}
