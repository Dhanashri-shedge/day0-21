#include<iostream>
using namespace std;
class prime{
    public:
        void check_prime(){
            int num;
            cout<<"Enter the number :";
            cin>>num;
            for(int i = 2; i <num-1; i ++){
                if(num % i == 0){
                    cout<<"Not prime";
                    break;
                }
                else{
                    cout<<"Prime ";
                    break;
                }
            }
        }
};
int main(){
    prime p;
    p.check_prime();
    return 0;
}