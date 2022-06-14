//
// Created by Ð¡ºú on 2022/4/25.
//

#ifndef LIST_MAIN_H
#define LIST_MAIN_H
template<class type>
class SequenceList{
public:
    virtual type Get(int) const =0;
    virtual type Pre(int) const =0;
    virtual type Next(int)const =0;
    virtual int Index(type) const =0;
    virtual int Insert(type,int)=0;
    virtual int Insert(type x)=0;
    virtual int DeleteByVar(type)=0;
    virtual int DeleteByIndex(int)=0;
    virtual void Clear()=0;
    virtual int IsEmpty()=0;
    virtual void Traverse() const=0;
    virtual int Update(int,type)=0;
};

template<class type>
class LinearList:public SequenceList<type>{
private:
    int Len;
    type* list;
    int length;
public:
    explicit LinearList(int Length=100);
    LinearList(const LinearList & l);
    virtual void EmptyList();
    int Length() const;
    virtual type Get(int index) const;
    virtual type Pre(int index) const;
    virtual type Next(int index) const;
    virtual int Index(type x) const;
    virtual int Insert(type x,int index);
    virtual int Insert(type x);
    virtual int DeleteByVar(type x);
    virtual int DeleteByIndex(int index);
    virtual void Clear();
    virtual int IsEmpty();
    virtual void Traverse() const;
    virtual int Update(int index,type x);
    virtual int Sort();
    virtual void In(type x){};
    virtual void Out(type* x){};
    void operator+(const LinearList<type>& ll);
};




template<class type>
class LinkList:public SequenceList<type>{
private:
    class LinkNode{
    public:
        type data;
        LinkNode* next;
        explicit LinkNode(int _data=0):next(nullptr),data(data){}
        LinkNode(const LinkNode & obj){
            data = *obj.data;
            next = new LinkNode;
            next = *obj.next;
        }
    };
    LinkNode *head;
    int length;
public:
    LinkList();
    LinkList(const LinkList & obj);
    ~LinkList();
    int GetLength();
    virtual type Get(int index) const;
    virtual type Pre(int index) const;
    virtual type Next(int index) const;
    virtual int Index(type x) const;
    virtual int Insert(type x,int index);
    virtual int Insert(type x);
    virtual void Add(type x);
    virtual int DeleteByVar(type x);
    virtual int DeleteByIndex(int index);
    virtual void Clear();
    virtual int IsEmpty();
    virtual void Traverse() const;
    virtual int Update(int index,type x);
    virtual void operator+(const LinkList<type> & linkList);
};

template<class type>
class Stack:public LinearList<type>
{
public:
    Stack()= default;
    Stack(const Stack<type> & obj): LinearList<type>(obj){}
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
