#include<bits/stdc++.h>
using namespace std;

 
class Number{
	private:  
		int value;
	public:
        Number(int v): value(v){};
    
        friend Number tinhtong(Number n1, Number n2);
        // void nhap();
        void in();
	
};



Number tinhtong(Number n1, Number n2){
    return Number(n1.value + n2.value);
}


void Number::in(){
   cout<<this->value<<endl;

}

int main(){
    int x,y; cin>>x>>y;
    Number num1(x);
    Number num2(y);
    Number num3 = tinhtong(num1,num2);
    num3.in();


	
	system("pause");
	return 0; 
	
}




