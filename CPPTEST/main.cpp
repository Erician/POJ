#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(){
    string mystr;
    getline(cin,mystr);
    stringstream ss;
    ss<<mystr;
    int n;
    ss>>n;
    cout<<n<<endl;
    return 0;
}
