#include <iostream>
#include <unordered_map>
#include <utility>

#include "Client.hpp"
#include "Hash.hpp"
#include "File_handler.h"

using namespace std;

int main()
{
    unordered_map <string, Client, pairHash, pairEquals> client_reasons;
    unordered_map <string, Client, pairHash, pairEquals> client_reasons_read;
    Client Nr1(1, "First1", "Last1", Reason::Buying);
    Client Nr2(2, "First2", "Last2", Reason::Leasing);
    Client Nr3(3, "First3", "Last3", Reason::Selling);

    client_reasons.insert({ Nr1.get_First_Name(), Nr1 });
    client_reasons.insert({ Nr2.get_First_Name(), Nr2 });
    client_reasons.insert({ Nr3.get_First_Name(), Nr2 });

    cout << "What does First2 want from us? " << enum_strings[(int)client_reasons.find("First2")->second.get_Reason()] << endl;
    cout << "What does First1 want from us? " << enum_strings[(int)client_reasons.find("First1")->second.get_Reason()] << endl;

    IO::save_entries(client_reasons);
    cout << "Name1: " << client_reasons.hash_function()("Name1") << endl;
    cout << "ame1N: " << client_reasons.hash_function()("ame1N") << endl;

    
    client_reasons_read = IO::read_entries();

    cout << "What does First2 want from us? " << enum_strings[(int)client_reasons_read.find("First2")->second.get_Reason()] << endl;
    cout << "What does First1 want from us? " << enum_strings[(int)client_reasons_read.find("First1")->second.get_Reason()] << endl;
}
