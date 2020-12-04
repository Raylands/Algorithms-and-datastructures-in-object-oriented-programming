#include <iostream>
#include <unordered_map>
#include <utility>

#include "Client.hpp"
#include "Hash.hpp"

using namespace std;

int main()
{
    unordered_map <string, Reason, pairHash, pairEquals> client_reasons;
    
    client_reasons.insert(make_pair("Name1", Reason::Leasing));
    //client_reasons.insert({ "Name2", Reason::Insurance });

    //cout << "What does Name2 want from us? " << enum_strings[(int)client_reasons.find("Name2")->second] << endl;

    //pair<string, Reason> a("Name1", Reason::Insurance);
    //cout << client_reasons.hash_function()(a) << endl;
}
