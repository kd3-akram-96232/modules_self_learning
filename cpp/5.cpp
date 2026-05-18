#include <iostream>
using namespace std;

class String_utils
{
public:
    static int strlen(string str)
    {
        int size = 0;

        while (str[size] != '\0')
        {
            size++;
        }

        return size;
    }
    static void strcpy(string &storage, string str)
    {
        storage = str;
    }
};

int main()
{

    string sample = "sample_string";

    string storage;

    int size = String_utils::strlen(sample);

    String_utils::strcpy(storage, sample);

    cout << "String size: " << size << endl;
    cout << "String copy: " << storage << endl;

    return 0;
}
