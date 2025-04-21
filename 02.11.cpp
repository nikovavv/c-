//1
#include <iostream>
#include <fstream>
#include <string>
#include <set>
using namespace std;

int main() {
    ifstream if1("input.txt");
    ofstream of1("output.txt");
    set<char> spisok = {'u','s','e','r','a','g','m','n','t'};
    for (char i: "useragreement"){
        spisok.insert(toupper(i));
    }
    string line;
    while (getline(if1,line)){
        for (char c: line){
            if (spisok.find(c)==spisok.end()){
                of1 <<c;
            }
        }
    }
    if1.close();
    of1.close();
    return 0;
}

//2
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream if1("input1.txt");
    ifstream if2("input2.txt");
    string x,y;
    getline(if1,x);
    getline(if2,y);
    if (x.find(y) != string::npos){
        cout << "yes"<<endl;
    }else{
        cout <<"no"<<endl;
    }
    if1.close();
    if2.close();
    return 0;
}

//3
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;
string binar(int n){
    string b = "";
    while (n>0){
        b = (n%2==0 ? "0":"1")+b;
        n/=2;
    }
    if (b.empty()){
        b = "0";
    }
    return b;
}
int main() {
    ifstream if1("input3.txt");
    ofstream of1("output3.txt");
    string line;
    getline(if1,line);
    string result = "";
    string number = "";
    for (char c:line){
        if (isdigit(c)){
            number+=c;
        }else{
            if (!number.empty()){
                result+=binar(stoi(number));
                number = "";
            }
            result+=c;
        }
    }
    if (!number.empty()){
        result+=binar(stoi(number));
    }
    of1<<result;
    if1.close();
    of1.close();
    return 0;
}
