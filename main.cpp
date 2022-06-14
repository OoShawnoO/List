#include <iostream>
#include <fstream>

#include "main.h"

using namespace std;

template <class type>
void LinearList<type>::EmptyList() {
    for(auto & x:this->list){
        x = NULL;
    }
}

template <class type>
int LinearList<type>::Length() {
    return this->length;
}

template <class type>
type LinearList<type>::Get(int index) {
    if(index>=0&&index<=Len){
        return this->list[index];
    }
    else {
        printf("Out of List!");
        return NULL;
    }
}

template <class type>
type LinearList<type>::Pre(int index) {
    if(index-1>=0){return this->list[index];}
    else{printf("Out of List!");return NULL;}
}

template <class type>
type LinearList<type>::Next(int index) {
    if(index+1<=Len&&index+1>=0){return this->list[index+1];}
    else{
        printf("Out of List!");
        return NULL;
    }
}

template <class type>
int LinearList<type>::Index(type x) {
    int index = 0;
    for(;index<Len;index++){
        if(x==this->list[index]){return index;}
    }
    return -1;
}

template <class type>
int LinearList<type>::Insert(type x,int index) {
    if(this->length+1>Len){return -1;}
    else{
        this->length++;
        for(;index<=this->length;index++){
            int temp = this->list[index];
            this->list[index] = x;
            x = temp;
        }
        return 1;
    }
}

template <class type>
int LinearList<type>::DeleteByIndex(int index) {
    if(index>=0&&index<=Len){
        for(int i=index;i<this->length;i++){
            this->list[i] = this->list[i+1];
        }
        this->length--;
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
    for(int i=0;i<this->length;i++){
        this->list[i] = NULL;
    }
    this->length = 0;
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
void LinearList<type>::Traverse() {
    for(int i=0;i<this->length;i++){
        cout<<i<<' ';
    }
    printf("\n");
    for(int i=0;i<this->length;i++){
        cout<<list[i]<<' ';
    }
    printf("\n");
}

template <class type>
int LinearList<type>::Update(int index, type x) {
    if(index>=0&&index<=Len){
        this->list[index] = x;
        return 1;
    }
    else{
        return -1;
    }
}

template <class type>
int LinearList<type>::Sort() {
    for(int i=0;i<this->length-1;i++){
        for(int j=i+1;j<this->length;j++){
            if(this->list[i]<this->list[j]){
                int temp = this->list[j];
                this->list[j] = this->list[i];
                this->list[i] = temp;
            }
        }
    }
    return 1;
}

/* Link List Define*/

template<class type>
LinkList<type>::LinkList(const LinkList & obj){
    head = obj.head;
    length = obj.length;
}

template<class type>
LinkList<type>::~LinkList(){
//    auto ptr = head;
//    while(ptr){
//        auto temp = ptr->next;
//        delete ptr;
//        ptr = temp;
//    }
}

template<class type>
int LinkList<type>::GetLength() {
    return length;
}

template<class type>
type LinkList<type>::Get(int index) {
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
type LinkList<type>::Pre(int index) {
    return Get(index-1);
}

template<class type>
type LinkList<type>::Next(int index) {
    return Get(index+1);
}

template<class type>
int LinkList<type>::Index(type x) {
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
void LinkList<type>::Traverse() {
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
    }
    ptr->data = x;
    return 1;
}

template<class type>
void Stack<type>::Push(type x){
    LinearList<type>::Insert(x,LinearList<type>::length);
}

template<class type>
void Stack<type>::Pop(type* x){
    *x = LinearList<type>::Get(LinearList<type>::length-1);
    LinearList<type>::DeleteByIndex(LinearList<type>::length-1);
}

template<class type>
int Stack<type>::GetTop(){return LinearList<type>::length;}

template<class type>
void Queue<type>::InQueue(type x){
    LinearList<type>::Insert(x,LinearList<type>::length);
}

template<class type>
void Queue<type>::OutQueue(type* x){
    *x = LinearList<type>::Get(0);
    LinearList<type>::DeleteByIndex(0);
}

template<class type>
void LinkList<type>::operator+(const LinkList<type> & linkList){
    auto ptr = linkList.head->next;
    while(ptr){
        Add(ptr->data);
        ptr = ptr->next;
    }
}


int main() {
    /*---????---*/
//    LinearList<int> ls;
//    for(int j=0;j<20;j++){
//        ls.Insert(rand()%100,j);
//    }
//    ls.Traverse();
//    printf("%d %d",ls.Length(),ls.Get(2));
//    ls.Sort();
//    ls.Traverse();
//    LinearList<int> l2 = ls;
//    l2.Update(0,100);
//    l2.Traverse();
//    ls.Traverse();
//    ls.Clear();
//    ls.Traverse();
    /*---????---*/
//    LinkList<int> ls;
//    ls.Insert(2,0);
//    LinkList<int> l2 = ls;
//
//    ls.Add(4);
//    ls.Traverse();
//    cout << ls.GetLength()<<'\n';
//    cout << l2.GetLength()<<'\n';
    /*---?---*/
    /*
     * 1
Out of List!0
     * */
//    Stack<int> stack;
//    stack.Push(1);
//    int x;
//    stack.Pop(&x);
//    cout<<x<<endl;
//    stack.Pop(&x);
//    cout<<x<<endl;
    /*---????---*/
    /*  1
        2   */
//    Queue<int> queue;
//    queue.InQueue(1);
//    queue.InQueue(2);
//    int x;
//    queue.OutQueue(&x);
//    cout<<x<<endl;
//    queue.OutQueue(&x);
//    cout<<x<<endl;

    /*---???---*/
    /*  1
        2

        2
        1
    */
//    LinearList<int>* ls;
//    Queue<int> queue;
//    Stack<int> stack;
//    ls = &queue;
//    int x=0;
//    ls->In(1);
//    ls->In(2);
//    ls->Out(&x);
//    cout<<x<<endl;
//    ls->Out(&x);
//    cout<<x<<endl;
//
//    cout<<""<<endl;
//
//    ls = &stack;
//    ls->In(1);
//    ls->In(2);
//    ls->Out(&x);
//    cout<<x<<endl;
//    ls->Out(&x);
//    cout<<x<<endl;

    /*---?????????---*/
    /*0 1 2 3 4 10 9 8 7*/
//    LinkList<int> linkList1;
//    LinkList<int> linkList2;
//    for(int i=0;i<5;i++){linkList1.Add(i);}
//    for(int i=10;i>6;i--){linkList2.Add(i);}
//    linkList1+linkList2;
//    linkList1.Traverse();

    /*---??---*/
    /*2*/
//    try{
//        throw 2;
//    }catch(int x){
//        printf("%d",x);
//    }

    /*---?????????---*/
    ofstream file1("D://C_Learn/List/123.txt");
    ifstream file("D://C_Learn/List/123.txt");

    for(int i=0;i<100;i++){
        cout<<i<<endl;
        file1<< 'a';
    }
    file1.close();
    char x=' ';
    while(file.get(x)){
        cout<<x<<endl;
    }
    file.close();

}




