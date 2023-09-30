# include<iostream>
#include<map>
#include<unordered_map>
using namespace std;
int main(){
    // creation
    unordered_map<string,int> m;
    
    // insertion

    //1
    pair<string,int> p = make_pair("mera",2);
    m.insert(p);

    // 2
    pair<string,int> p2("desh",3);
    m.insert(p2);

    // 3
    m["mahan"]=4;
    // first time creation and secons time update
    m["mahan"]=5;


    // search
    // this find the key if exists then return the value otherwise it crate new key with a value 0
    cout<<m["mahan"]<<endl;
    cout<<m["babbar"]<<endl;
    cout<<m.at("mahan")<<endl;
    // this return the value if and only if the key exists otherwise it gives error
    // cout<<m.at("dibya")<<endl;
    cout<<m.at("babbar")<<endl;


    // size
    cout<<m.size()<<endl;

    // check presence
    // if the key present it returns 1 otherwise it return 0
    cout<<m.count("love")<<endl;
    cout<<m.count("mera")<<endl;

    // erase
    m.erase("mera");
    cout<<m.size()<<endl;

    // iterator
    unordered_map<string,int> :: iterator it=m.begin();
    while(it!=m.end()){
        cout<<it->first<<"  "<<it->second<<endl;
        it++;
    }
    // unordered map doesn't preserve the order but ordered map preservers the order

    return 0;
}