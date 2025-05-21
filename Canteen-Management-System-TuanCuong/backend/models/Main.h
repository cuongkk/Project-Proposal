#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <list>
#include <iomanip>
#include <sstream>
#include <unordered_map>
#include <ctime>
#include <regex>
#include <bitset>
#include <fstream>
#include <filesystem>

std::string create_id(const std::string &, const int &);
int get_counter_from_id(const std::string &, const std::string &);
std::string set_id(const std::string &, std::vector<int> &);
bool findContains(const std::string &text, const std::string &pattern);
bool is_positive_number(const std::string &str);
bool is_diffrent_name(const std::string &, const std::vector<std::string> &);

#endif