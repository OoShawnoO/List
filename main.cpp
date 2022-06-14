#include <iostream>
#include "main.h"

using namespace std;

template <class type>
LinearList<type>::LinearList(int Length):Len(Length),length(0){
    list = new type[Len];
    for(int i=0;i<Len;i++){
        list[i] = NULL;
    }
}

template <class type>
LinearList<type>::LinearList(const LinearList<type>& l):length(l.length){
    for(int i=0;i<l.length;i++){
        list[i] = l.list[i];
    }
    length = l.length;
}

template <class type>
void LinearList<type>::EmptyList() {
    for(int i=0;i<Len;i++){
        list[i] = NULL;
    }
}

template <class type>
int LinearList<type>::Length() const {
    return length;
}

template <class type>
type LinearList<type>::Get(int index) const {
    if(index>=0&&index<=Len){
        return list[index];
    }
    else {
        printf("Out of List!");
        return NULL;
    }
}

template <class type>
type LinearList<type>::Pre(int index) const {
    if(index-1>=0){return list[index];}
    else{printf("Out of List!\n");return NULL;}
}

template <class type>
type LinearList<type>::Next(int index) const {
    if(index+1<=Len&&index+1>=0){return list[index+1];}
    else{
        printf("Out of List!");
        return NULL;
    }
}

template <class type>
int LinearList<type>::Index(type x) const {
    int index = 0;
    for(;index<Len;index++){
        if(x==list[index]){return index;}
    }
    return -1;
}

template<class type>
int LinearList<type>::Insert(type x) {
    return Insert(x,length);
}

template <class type>
int LinearList<type>::Insert(type x,int index) {
    if(length+1>Len){return -1;}
    else{
        length++;
        for(;index<=length;index++){
            int temp = list[index];
            list[index] = x;
            x = temp;
        }
        return 1;
    }
}

template <class type>
int LinearList<type>::DeleteByIndex(int index) {
    if(index>=0&&index<=Len){
        for(int i=index;i<length;i++){
            list[i] = list[i+1];
        }
        length--;
        return 1;
    }
    else{
        return -1;
    }
}

template <class type>
int LinearList<type>::DeleteByVar(type x) {
    return DeleteByIndex(Index(x));
}

template <class type>
void LinearList<type>::Clear() {
    for(int i=0;i<length;i++){
        list[i] = NULL;
    }
    length = 0;
}

template <class type>
int LinearList<type>::IsEmpty() {
    if(Length()!=0){
        return -1;
    }
    else{
        return 1;
    }
}

template <class type>
void LinearList<type>::Traverse() const {
    for(int i=0;i<length;i++){
        cout<<"|"<<i<<"|";
    }
    printf("\n");
    for(int i=0;i<length;i++){
        cout<<"|"<<list[i]<<"|";
    }
    printf("\n");
}

template <class type>
int LinearList<type>::Update(int index, type x) {
    if(index>=0&&index<=Len){
        list[index] = x;
        return 1;
    }
    else{
        return -1;
    }
}

template <class type>
int LinearList<type>::Sort() {
    for(int i=0;i<length-1;i++){
        for(int j=i+1;j<length;j++){
            if(list[i]<list[j]){
                int temp = list[j];
                list[j] = list[i];
                list[i] = temp;
            }
        }
    }
    return 1;
}

template <class type>
void LinearList<type>::operator+(const LinearList<type>& ll){
    for(int i=0;i<ll.Length();i++){
        Insert(ll.Get(i));
    }
}


/* Link List Define*/
template <class type>
LinkList<type>::LinkList(){
    head = new LinkNode;
    length = 0;
}

template<class type>
LinkList<type>::LinkList(const LinkList & obj){
    head = obj.head;
    length = obj.length;
}

template<class type>
LinkList<type>::~LinkList(){
}

template<class type>
int LinkList<type>::GetLength() {
    return length;
}

template<class type>
type LinkList<type>::Get(int index) const {
    if(index<=length&&index>=0){
        auto ptr = head;
        while(index>0){
            ptr = ptr->next;
            index--;
        }
        return ptr->data;
    }
    else{
        return (type)NULL;
    }
}

template<class type>
type LinkList<type>::Pre(int index) const {
    return Get(index-1);
}

template<class type>
type LinkList<type>::Next(int index) const {
    return Get(index+1);
}

template<class type>
int LinkList<type>::Index(type x) const {
    auto ptr = head;
    int count = 0;
    while(ptr->data!=x && ptr != nullptr){
        ptr = ptr->next;
        count++;
    }
    if(ptr!=nullptr)
        return count;
    else
        return -1;
}

template<class type>
int LinkList<type>::Insert(type x, int index) {
    auto node = new LinkNode;
    node->data = x;
    node->next = nullptr;
    length++;
    if(index>length){
        auto ptr = head;
        while(ptr->next!=nullptr){
            ptr = ptr->next;
        }
        ptr->next = node;
        return 1;
    }
    else if(index==0){
        node->next = head->next;
        head->next = node;
        return 1;
    }
    else{
        auto ptr = head;
        while(index>0){
            ptr = ptr->next;
            index--;
        }
        auto temp = ptr->next;
        ptr->next = node;
        node->next = temp;
        return 1;
    }
}

template<class type>
void LinkList<type>::Add(type x){
    Insert(x,9999);
}

template<class type>
int LinkList<type>::DeleteByVar(type x) {
    auto ptr = head;
    while(ptr){
        if(ptr->next->data==x){
            auto temp = ptr->next;
            ptr->next = temp->next;
            delete(temp);
            return 1;
        }
        ptr = ptr->next;
    }
    return 0;
}

template<class type>
int LinkList<type>::DeleteByIndex(int index) {
    if(index>length){
        return 0;
    }
    else{
        auto ptr = head;
        while(index>1){
            ptr = ptr->next;
            index--;
        }
        auto temp = ptr->next;
        ptr->next = temp->next;
        delete(temp);
        return 1;
    }
}

template<class type>
void LinkList<type>::Clear() {
    delete(this);
}

template<class type>
int LinkList<type>::IsEmpty() {
    if(length==0){return 1;}
    else{return 0;}
}

template<class type>
void LinkList<type>::Traverse() const {
    auto ptr = head->next;
    while(ptr){
        cout<<(*ptr).data<<' ';
        ptr = ptr->next;
    }
}

template<class type>
int LinkList<type>::Update(int index, type x) {
    if(index>length){return 0;}
    auto ptr = head;
    while(index>0){
        ptr = ptr->next;
        index--;
    }
    ptr->data = x;
    return 1;
}

template<class type>
void LinkList<type>::operator+(const LinkList<type> & linkList){
    auto ptr = linkList.head->next;
    while(ptr){
        Add(ptr->data);
        ptr = ptr->next;
    }
}

template<class type>
int LinkList<type>::Insert(type x) {
    return Insert(x,length);
}

template<class type>
void Stack<type>::Push(type x){
    LinearList<type>::Insert(x,LinearList<type>::Length());
}

template<class type>
void Stack<type>::Pop(type* x){
    *x = LinearList<type>::Get(LinearList<type>::Length()-1);
    LinearList<type>::DeleteByIndex(LinearList<type>::Length()-1);
}

template<class type>
int Stack<type>::GetTop(){return LinearList<type>::Length();}

template<class type>
void Queue<type>::InQueue(type x){
    LinearList<type>::Insert(x,LinearList<type>::Length());
}

template<class type>
void Queue<type>::OutQueue(type* x){
    *x = LinearList<type>::Get(0);
    LinearList<type>::DeleteByIndex(0);
}





