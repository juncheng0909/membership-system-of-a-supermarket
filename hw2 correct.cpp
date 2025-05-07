#include<iostream>
#include<string>
#include<vector>
#include <sstream>

using namespace std;

class Product{
    private:
        string name;
        int price;
        int count;
    public:
        Product(){
            name = "";
            price = 0;
            count = 0;
        }
        void setName(string n){ name = n; }
        void setPrice(int p){ price = p; }
        void setCount(int c){ count = c; }
        string getName(){ return name; }
        int getPrice(){ return price; }
        int getCount(){return count; }
        int getTotal() { return price * count; }
        void display(){
            cout<<name<<" "<<price<<" "<<count<<" "<<getTotal()<<endl;
        }

};

class Record{
    private:
        string date;
    public:
        vector<Product> products;
        Record(){
            date = "";
        }
        void setDate(string d){ date = d; }
        string getDate(){ return date; }
        void display(){
            cout<<"Date : "<<date<<endl;
        }
};

class Membership{
    private:
        string name;
        string birth;
    public:
        vector<Record> records;
        Membership(){
            name = "";
            birth = "";
        }
        void setName(string n){ name = n; }
        void setBirth(string b){ birth = b; }
        string getName(){ return name; }
        string getBirth(){return birth; }
        void display(){
            cout<<name<<" "<<birth<<endl;
        }
};

vector<Membership> members;
vector<string> word;

void Rigister(vector<string> w){
    Membership member;
    member.setName(w[1]);
    member.setBirth(w[2]);
    members.push_back(member);
}

void Update(vector<string> w){
    for(auto &m : members){
        if(m.getName() == w[1]){
            m.setBirth(w[2]);
        }
    }
}

void Search(vector<string> w){
    bool flag = false;
    for(int i = 0;i<members.size();i++ ){
        if(members[i].getName() == w[1]){
            members[i].display();
            flag = true;
        }
    }
    if(flag == false){
        cout<<"USER NOT FOUND"<<endl;
    }
}

void Buy(vector<string> w){
    string date = w[1];
    Record newRecord;
    newRecord.setDate(date);
    string name = w[2];
    for(int j=0;j<stoi(w[3]);j++){
        string line;
        getline(cin,line);
        istringstream iss(line);
        string productName;
        int price,count;
        iss >> productName >> price >> count;
        Product newProduct;
        newProduct.setName(productName);
        newProduct.setPrice(price);
        newProduct.setCount(count);
        newRecord.products.push_back(newProduct);
    }
    for (auto &m : members) {
        if (m.getName() == name) {
            m.records.push_back(newRecord);
            return;
        }
    }
}

void checkDetail(vector<string> w){
    int reco = stoi(w[2]);
    string name = w[1];
    for (auto &m : members) {
        if (m.getName() == name) {
            int total = 0;
            for(int j = 0;j<m.records[reco].products.size();j++){
                total += m.records[reco].products[j].getTotal();
            }
            cout<<m.records[reco].getDate()<<" "<<total<<endl;
            for(int j = 0;j<m.records[reco].products.size();j++){
                m.records[reco].products[j].display();
            }
        }
    }
}

void checkSummary(vector<string> w){
    for(auto& m : members){
        if(m.getName()==w[1]){
            int numRecord = m.records.size();
            int totalMoney = 0;
            for(int k =0;k<numRecord;k++){
                for(int h = 0;h<m.records[k].products.size();h++){
                    totalMoney += m.records[k].products[h].getTotal();
                }
            }
            cout<<numRecord<<" "<<totalMoney<<endl;
        }
    }
}

int main(){
    string Words;
    while(getline(cin, Words)) {
        if(Words.empty())
            continue;

        word.clear();
        istringstream iss(Words);
        string ele;
        while(getline(iss, ele, ' ')) {
            if(!ele.empty())
                word.push_back(ele);
        }
        
        if(word.empty())
            continue;

        string f = word[0];
        
        if(f=="register") {
            Rigister(word);
        } else if(f=="update") {
            Update(word);
        } else if(f=="search") {
            Search(word);
        } else if(f=="buy") {
            Buy(word);
        } else if(f=="detail") {
            checkDetail(word);
        } else if(f=="summary") {
            checkSummary(word);
        } else {
            continue;
        }
    }
    return 0;
}