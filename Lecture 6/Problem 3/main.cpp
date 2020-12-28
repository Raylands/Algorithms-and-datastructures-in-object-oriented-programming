#include <iostream>
#include <vector>

using namespace std;

bool fine(vector<char>& vector);

int main()
{
    vector<char> vector { '(', '(', ')', '(',')', ')', '{', '}' };

    cout << (fine(vector) ? "Everything is fine!" : "Something is missing!") << endl;
}

bool fine(vector<char>& vector)
{
    int parentheses = 0, brackets = 0, braces = 0;
    for (auto item : vector)
    {
        switch (item)
        {
        case '(':
            parentheses++;
            break;
        case '[':
            brackets++;
            break;
        case '{':
            braces++;
            break;
        case ')':
            parentheses--;
            break;
        case ']':
            brackets--;
            break;
        case '}':
            braces--;
            break;
        }
    }
    if (parentheses || brackets || braces) return false;
    else return true;
}