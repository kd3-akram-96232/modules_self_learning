#include<iostream>
using namespace std;

class Utils {
    int pointer = 0;
    string data;

    public:
        Utils(string data){
            this->data = data;
        }

        void setData(string data){
            setData(data);
        }

        void getLine(string &str, char seperator){
            string temp = "";
            bool commaFound = false;
            for(int i = pointer; i < data.size(); i++){
                if (data[i] == seperator){
                    commaFound = true;
                    if(pointer == 0){
                        temp = data.substr(pointer, i);
                    }else{
                        temp = data.substr(pointer, i-2);
                    }
                    pointer = i+1;
                    break;
                    return;
                }
                
            }
            if(!commaFound){
                temp = data.substr(pointer, data.size()-1);
            }
            str = temp;

        }
};





int main(){

    string data = "1,nilesh,1000,true,16-march-2003";

    Utils u(data);
    
    string id,name,salary,active,date;

    u.getLine(id, ',');
    u.getLine(name, ',');
    u.getLine(salary, ',');
    u.getLine(active, ',');
    u.getLine(date, ',');

    cout << "id: " << id <<endl;
    cout << "name: " << name <<endl;
    cout << "salary: " << salary <<endl;
    cout << "active: " << active <<endl;
    cout << "date: " << date <<endl;


    return 0;
}