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
    int length;
public:
    LinearList():length(0)
    {
        Initialize();
    }
    LinearList(const LinearList & l):length(l.length){
        for(int i=0;i<l.length;i++){
            list[i] = l.list[i];
        }
//        printf("%p %p",l.list[0],list[0]);
        this->length = l.length;
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
    void Initialize();
    void Traverse();
    int Update(int index,type x);
    int Sort();
};

template<class type>
class LinkList{
private:
    type data;
    LinkList* next;
public:
    LinkList()
    {
        Initialize();
    }
    LinkList(const LinkList & obj){
        auto *ptr = new LinkList<type>;
        while(obj->next){
            ptr->data = obj.data;
            ptr->next = new LinkList;
            ptr = ptr->next;
            obj = obj->next;
        }
    }
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
    void Initialize();
    void Traverse();
    int Update(int index,type x);
    int Sort();
};
#endif //LIST_MAIN_H
