#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

std::string create_id(const std::string &, const int &);
int get_counter_from_id(const std::string &, const std::string &);
std ::string set_id(const std::string &, std::vector<int> &);
#endif