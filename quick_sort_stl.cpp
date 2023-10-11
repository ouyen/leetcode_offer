#include<bits/stdc++.h>

using namespace std;

typedef vector<int>::iterator it;

it Part(vector<int>& A,const it start,const it end){
    int key=*start;
    it i=start+1;
    it j=start+1;
    for(;j!=end;++j){
        if(*j<key){
            swap(*i,*j);
            ++i;
        }
    }
    return i;
}

void QuickSort(vector<int>& A,const it start,const it end){
    if(start>=end){
        return;
    }
    it p=start;
    if(start!=end){
        p=Part(A,start,end);
    }
    QuickSort(A,start,p);
    QuickSort(A,p+1,end);
}

void QuickSort(vector<int>&A){
    QuickSort(A,A.begin(),A.end());
}

int main(){
    vector<int> A{10,9,8,7,6,5,4,3,2,1};
    QuickSort(A);
    //print A
    for(auto& i:A){
        cout<<i<<" ";
    }
    cout<<endl;
}