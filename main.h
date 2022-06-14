//
// Created by Ð¡ºú on 2022/4/25.
//

#ifndef LIST_MAIN_H
#define LIST_MAIN_H
const int Len=100;

template<class type>
class LinearList{
private:
    type list[Len];

public:
    int length;
    LinearList():length(0){
        for(auto & i : list){
            i = -1;
        }
    }
    LinearList(const LinearList & l):length(l.length){
        for(int i=0;i<l.length;i++){
            list[i] = l.list[i];
        }
//        printf("%p %p",l.list[0],list[0]);
        length = l.length;
    }
    void EmptyList();
    int Length();
    type Get(int index);
    type Pre(int index);
    type Next(int index);
    int Index(type x);
    int Insert(type x,int index);
    int DeleteByVar(type x);
    int DeleteByIndex(int index);
    void Clear();
    int IsEmpty();
    void Traverse();
    int Update(int index,type x);
    int Sort();
    virtual void In(type x){};
    virtual void Out(type* x){};
};




template<class type>
class LinkList{
private:
    class LinkNode{
    public:
        type data;
        LinkNode* next;
        LinkNode():next(nullptr),data(0){}
        LinkNode(const LinkNode & obj){
            data = *obj.data;
            next = new LinkNode;
            next = *obj.next;
        }
    };
    LinkNode* head;
    int length;
public:
    LinkList(){
        head = new LinkNode;
        length = 0;
    }
    LinkList(const LinkList & obj);
    ~LinkList();
    int GetLength();
    type Get(int index);
    type Pre(int index);
    type Next(int index);
    int Index(type x);
    int Insert(type x,int index);
    void Add(type x);
    int DeleteByVar(type x);
    int DeleteByIndex(int index);
    void Clear();
    int IsEmpty();
    void Traverse();
    int Update(int index,type x);
    void operator+(const LinkList<type> & linkList);
};

template<class type>
class Stack:public LinearList<type>
{
public:
    Stack()= default;
    Stack(const Stack<type> & obj): LinearList<type>(obj){
    }
    void Push(type x);
    void Pop(type* x);
    void In(type x){Push(x);};
    void Out(type* x){Pop(x);};
    int GetTop();
};

template<class type>
class Queue:public LinearList<type>
{
public:
    Queue()=default;
    Queue(const Queue<type> & obj): LinearList<type>(obj){}
    void InQueue(type x);
    void OutQueue(type *x);
    void In(type x){ InQueue(x);};
    void Out(type* x){ OutQueue(x);};

};


#endif //LIST_MAIN_H
