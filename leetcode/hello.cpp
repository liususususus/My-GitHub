#include <iostream>
using namespace std;

int main(){
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    //冒泡排序
    for(int i=0;i<10;i++){
        for(int j=0;j<10-i-1;j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    cout<<"冒泡排序后："<<endl;
    cout<<"a[0]="<<a[0]<<endl;  //1
    cout<<"a[1]="<<a[1]<<endl;  //2
    cout<<"a[2]="<<a[2]<<endl;  //3
    cout<<"a[3]="<<a[3]<<endl;  //4
    cout<<"a[4]="<<a[4]<<endl;  //5
    cout<<"a[5]="<<a[5]<<endl;  //6
    cout<<"a[6]="<<a[6]<<endl;  //7
    cout<<"a[7]="<<a[7]<<endl;  //8
    cout<<"a[8]="<<a[8]<<endl;  //9
    cout<<"a[9]="<<a[9]<<endl;  //10
    return 0;
}