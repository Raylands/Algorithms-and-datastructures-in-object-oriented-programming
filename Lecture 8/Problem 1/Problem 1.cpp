#include "Global.hpp"
#include "read_file.hpp"

int main()
{
    read_data("data.txt");
    for (auto entry : data_map)
    {
        cout << "Word: " << entry.first << " was found " << entry.second << " times." << endl;
    }
}
