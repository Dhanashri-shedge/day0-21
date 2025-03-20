#include<iostream>
using namespace std;
class count_num{
    public:
    int a[7];
    void input(){
        for(int i = 0; i <7; i ++){
            cout<<"Enter number "<<i+1<<" ";
            cin>>a[i];
        }
    }
    void op(){
        cout<<"The numbers are :"<<endl;
        for (int i = 0; i <7; i ++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    void count(){
        int counter = 0,key;
        cout<<"Enter the key to be searched : ";
        cin>>key;
        for(int i = 0;i <7; i++){
            if(a[i]== key){
                counter++;
            }
        }
        cout<<"The number of reptations are :"<<counter;
    }
};
int main(){
    count_num c;
    c.input();
    c.op();
    c.count();
    return 0;
}