#include "Main_all.h"
#include "Main.h"

std::vector<int> UserManagement::_id_counter_user = {0};

std::vector<int> BillManagement::_id_counter_bill = {0};

std::vector<int> KhoHang::_id_counter_sp = {0};

std::string create_id(const std::string &prefix, const int &counter)
{
    std::string id_str = std::to_string(counter);
    while (id_str.size() < 4)
    {
        id_str = '0' + id_str;
    }
    return std::string(prefix) + id_str;
}

int get_counter_from_id(const std::string &prefix, const std::string &id)
{
    std::string counter = id.substr(prefix.size());
    return std::stoi(counter);
}

void set_id_counter(const std::string &id, std::vector<int> &_id_counter)
{
    int counter = get_counter_from_id("AA", id);
    if (counter >= _id_counter.size())
    {
        for (int i = _id_counter.size(); i < counter; i++)
        {
            _id_counter.push_back(0);
        }
        _id_counter[counter - 1] = 1;
    }
}
void delete_id_counter(const std::string &id, std::vector<int> &_id_counter)
{
    int counter = get_counter_from_id("AA", id);
    if (counter < _id_counter.size())
    {
        _id_counter[counter - 1] = 0;
    }
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

bool findContains(const std::string &text, const std::string &pattern)
{
    std::regex regex(pattern, std::regex_constants::icase);
    return std::regex_search(text, regex);
}

bool is_positive_number(const std::string &str)
{
    if (str.empty())
        return false;
    for (char c : str)
    {
        if (!isdigit(c))
            return false;
    }
    return !str.empty() && std::stoll(str) >= 0;
}

bool is_diffrent_name(const std::string &name, const std::vector<std::string> &names)
{
    for (int i = 0; i < names.size(); i++)
    {
        std::string existing_name = names[i];
        if (name == existing_name)
        {
            return false;
        }
    }
    return true;
}
