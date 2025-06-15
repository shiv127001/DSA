# include<iostream>
# include<sstream>
# include<string>
using namespace std;

int main()
{
    string caption1 = "Check out my NEW video! #FunTime :)";
    string caption2 = "#$%^==Check o++ut my NEW video! #FunTime caption2:)";
    string word,tag = "#";
    bool first_word = true;
    stringstream ss(caption2);
    while(ss>>word)
    {
        string temp;
        for(char c:word)
        {
            if(isalpha(c))
            {
                temp+=tolower(c);
            }
        }

        if(first_word) {
            tag +=temp;
            first_word = false;
        }

        else
        {
            temp[0] = toupper(temp[0]);
            tag+= temp;
        }
    }
    cout<<"-------------------------------------\nSTRING TO camelCase converion is done :\n";
    cout<<tag;
    cout<<"\n-------------------------------------";
    return 0;
}