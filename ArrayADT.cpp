#include<bits/stdc++.h>
using namespace std;
class Array
{
    private:
        int capacity;
        int LastIndex;
        int *ptr;
    public:
        Array(int); //parametrised Constructor
        bool isEmpty();// cheak  the array empty or not
        void append(int);//add the array data in last index
        void insert(int,int);//add the data any position of index
        void edit(int ,int);//edit the data any position of index
        void del(int);//del the data any position of index
        bool isFull();//cheak the array isFull or not
        int get(int);//return the index value
        int count();//count the length
        int find(int);//find the numberv in vaild index position
        ~Array();  //  create destructor safe momery leak 


};
int Array::find(int data){
    int i;
    for(i=0;i<=LastIndex;i++)
         if(ptr[i]==data)
             return i;
    cout<<"Invaild Index";
      return -1;   
    
    
}
Array::~Array(){
    delete[]ptr;
}
int Array::count(){
    return LastIndex+1;
}
int Array::get(int index){
    if(index>=0 || index<=LastIndex){
        return ptr[index];
    }
    else{
        cout<<endl<<"invaild Index";
        return -1;// no any sense return this value
    }
}
bool Array::isFull(){
    return LastIndex==capacity-1;
}
void Array::del(int index){
    int i;
    if(isEmpty()){
        cout<<endl<<"Array is Empty";
    }
    else if(index<0 || index>LastIndex){
        cout<<endl<<"Invaild Index";
    }
    else{
        for(i=index;i<LastIndex;i++){
            ptr[i]=ptr[i+1];
        }
        LastIndex--;

    }
}
void Array::edit(int index,int data){
    if(index>=0 && index<=LastIndex){
        ptr[index]=data;
    }
}
void Array::insert(int index,int data){
    int i;
    if(LastIndex==capacity-1){
        cout<<endl<<"Array is already full";
    }
    else if(index<0 || index>LastIndex+1){           // check the data more the lastindex hai ki nahi
        cout<<"Invalid Index";
    }
    else{
        for(i=LastIndex;i>=index;i--){
            ptr[i+1]=ptr[i];
        }
        ptr[index]=data;
        LastIndex++;

    }

}
void Array::append(int data){
    if(LastIndex==capacity-1){
        cout<<endl<<"array is already Full";
    }
    else{
        LastIndex++;//increase the array size
        ptr[LastIndex]=data;
    }
      

}
bool Array::isEmpty(){
    return LastIndex==-1;
}

Array::Array(int cap)//parametrised Constructor not use return type
{
     capacity=cap;
     LastIndex=-1;
     ptr=new int[capacity];
}
// test my code work or not
// int main()
// {
//     Array obj(5);
//     if(obj.isEmpty()){
//         cout<<"Array is Empty"<<endl;
//     }
//     obj.append(20);
//     obj.append(30);
//     obj.append(40);
//     obj.insert(1,60);
//     for(int i=0;i<obj.count();i++){
//         cout<<obj.get(i)<<" ";
//     }
//     obj.del(2);
//     cout<<endl;
//      for(int i=0;i<obj.count();i++){
//         cout<<obj.get(i)<<" ";
//     }
//     cout<<endl;
//     return 0;
}