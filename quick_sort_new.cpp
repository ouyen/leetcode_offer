#include<bits/stdc++.h>

using namespace std;

template <typename T>
class BaseSort{
protected:
    bool (* _c_func)(const T&a,const T&b) = [](const T&a,const T&b){return a<b;};
public:
    virtual void Sort(T* t_list,int start,int end){}
};

template <typename T>
class QuickSort:public BaseSort<T>{
public:
    QuickSort(){};
    QuickSort(bool (* compare_func)(const T&a,const T&b)){
        this->_c_func = compare_func;
    }
    int Part(T* t_list,int start,int end){
        T key=t_list[end];
        int i=0,j=0;
        i=start;
        for(j=start;j<end;++j){
            if(this->_c_func(t_list[j],key)){
                swap(t_list[i],t_list[j]);
                ++i;
            }
        }
        swap(t_list[end],t_list[i]);
        return i;
    }
    void Sort(T* t_list,int start,int end){
        if(start>=end) return;
        int p = Part(t_list,start,end);
        Sort(t_list,start,p-1);
        Sort(t_list,p+1,end);
    }    
};

void test_sort(){
    auto s = QuickSort<int>([](const int&a,const int&b){return a>b;});
    int a[10]={2,3,6,7,8,9,10,-3,100,-10};
    s.Sort(a,0,9);
    for(int i=0;i<10;++i){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){
    test_sort();
}