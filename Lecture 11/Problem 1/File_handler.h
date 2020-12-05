#pragma once
#include <fstream>
#include <unordered_map>
#include "Client.hpp"
#include "Hash.hpp"

using namespace std;

namespace IO {
    template<typename T, typename N>
    bool save_entries(const unordered_map<string, Client, T, N>& hash_map)
    {
        ofstream wf("client.txt", ios::out);
        if (!wf)
            return false;
        
        int size = hash_map.size();
        wf.write((char*)& size, sizeof(size));
        for (const auto obj : hash_map)
        {
            wf.write((char*)&obj.second, sizeof(obj.second));
            wf.write((char*)&obj.first, sizeof(obj.first));
        }
        
        wf.close();

        if (!wf.good())
            return false;

        return true;
    }

    unordered_map<string, Client, pairHash, pairEquals> read_entries()
    {
        ifstream wf("client.txt", ios::in);
        if (!wf)
            return unordered_map<string, Client, pairHash, pairEquals>{};

        unordered_map<string, Client, pairHash, pairEquals> ret;
        int max = 0;
        wf.read((char*)&max, sizeof(max));

        for (int i = 0; i < max; i++)
        {
            Client tmp;
            string tmp2;
            wf.read((char*)&tmp, sizeof(tmp));
            wf.read((char*)&tmp2, sizeof(tmp2));
            ret.insert({ tmp2, tmp });
        }

        wf.close();

        return ret;
    }
}