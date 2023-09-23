/*
 * @lc app=leetcode.cn id=面试题 16.25 lang=cpp
 * @lcpr version=21913
 *
 * [面试题 16.25] LRU 缓存
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class LRUCache {
    int _capacity=0;
    int _curr_capacity=0;
    bool _not_full = true;
    list<pair<int,int>> link_list={};
    unordered_map<int,list<pair<int,int>>::iterator> dict;
    void move_to_head(list<pair<int,int>>::iterator node){
        link_list.splice(link_list.begin(),link_list,node);
    }
public:
    LRUCache(int capacity):_capacity(capacity) {

    }
    
    int get(int key) {
        if(dict.count(key)==0){
            return -1;
        }
        list<pair<int,int>>::iterator curr = dict[key];
        move_to_head(curr);
        return (*curr).second;
    }
    
    void put(int key, int value) {
        if(dict.count(key)==0){
            link_list.push_front(make_pair(key,value));
            dict[key]=link_list.begin();
            ++_curr_capacity;
            if(_not_full==false ||_curr_capacity>_capacity){
                dict.erase(link_list.back().first);
                link_list.pop_back();
                --_curr_capacity;
            }
        }
        else{
            list<pair<int,int>>::iterator curr = dict[key];
            move_to_head(curr);
            (*curr).second=value;
        }
    }
    // void pget(int key){
    //     cout<<get(key)<<endl;
    // }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

int main(){
    LRUCache cache(2);
    cache.put(1,1);
    cache.put(2,2);
    cout<<cache.get(1);
    cache.put(3,3);
    cout<<cache.get(2);
    cache.put(4,4);
    cout<<cache.get(1);
    cout<<cache.get(3);
    cout<<cache.get(4);
    cout<<endl;
}



