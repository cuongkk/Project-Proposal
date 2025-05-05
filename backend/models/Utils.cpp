#include "Utils.h"

std::string create_id(const std::string &prefix, const int &counter)
{
    std::string id_str = std::to_string(counter);
    while (id_str.size() < 4)
    {
        id_str = '0' + id_str;
    }
    return prefix + id_str;
}

int get_counter_from_id(const std::string &prefix, const std::string &id)
{
    std::string counter = id.substr(prefix.size());
    return std::stoi(counter);
}

std::string set_id(const std::string &prefix, std::vector<int> &_id_counter)
{
    std::string id = "";
    for (int i = 0; i < _id_counter.size(); i++)
    {
        if (_id_counter[i] == 0)
        {
            id = create_id(prefix, i + 1);
            _id_counter[i] = 1;
            return id;
        }
        else if (_id_counter[i] == 1 && i < _id_counter.size() - 1)
        {
            continue;
        }
        else if (_id_counter[_id_counter.size() - 1] == 1)
        {
            _id_counter.push_back(1);
            id = create_id(prefix, _id_counter.size());
            _id_counter[i] = 1;
            return id;
        }
    }
    return id;
}