/*
 * @lc app=leetcode.cn id=146 lang=cpp
 * @lcpr version=21913
 *
 * [146] LRU 缓存
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
struct DLinkNode {
    int key,value;
    DLinkNode* prev=nullptr;
    DLinkNode* next=nullptr;
    DLinkNode(int _key,int _value):key(_key),value(_value){}
    DLinkNode(){}
};

class LRUCache {
    unordered_map<int,DLinkNode*> cache;
    DLinkNode* head;
    DLinkNode* tail;
    int _curr_size=0;
    int _capacity=0;
    void add_to_head(DLinkNode* node){
        node->prev=head;
        node->next=head->next;
        head->next->prev=node;
        head->next=node;
    }
    void remove_node(DLinkNode* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }
    void move_to_head(DLinkNode* node){
        remove_node(node);
        add_to_head(node);
    }
public:
    LRUCache(int capacity):_capacity(capacity) {
        head = new DLinkNode();
        tail = new DLinkNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(!cache.count(key)){
            return -1;
        }
        DLinkNode* curr_node = cache[key];
        remove_node(curr_node);
        add_to_head(curr_node);
        return curr_node->value;
    }
    
    void put(int key, int value) {
        if(!cache.count(key)){
            // not exist
            DLinkNode* curr_node = new DLinkNode(key,value);
            cache[key] = curr_node;
            add_to_head(curr_node);
            ++_curr_size;
            if(_curr_size>_capacity){
                DLinkNode* victim = tail->prev;
                remove_node(victim);
                cache.erase(victim->key);
                delete victim;
                --_curr_size;
            }
        }
        else{
            DLinkNode* curr_node = cache[key];
            curr_node->value=value;
            move_to_head(curr_node);
        }
    }
    ~LRUCache(){
        DLinkNode* curr = tail;
        while(curr!=head){
            curr = curr->prev;
            delete curr->next;
        }
        delete head;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end



