#include <iostream>


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
    return NULL;
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
void LinearList<type>::Initialize() {
    this->length = 0;
    EmptyList();
}

template <class type>
void LinearList<type>::Traverse() {
    for(int i=0;i<this->length;i++){
        printf("%d ",i);
    }
    printf("\n");
    for(int i=0;i<this->length;i++){
        printf("%d ",this->list[i]);
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

int main() {
    LinearList<int> ls;
    for(int j=0;j<20;j++){
        ls.Insert(rand()%100,j);
    }
    ls.Traverse();
//    printf("%d %d",ls.Length(),ls.Get(2));
    ls.Sort();
    ls.Traverse();
    LinearList<int> l2 = ls;
    l2.Update(0,100);
    l2.Traverse();
    ls.Traverse();
    ls.Clear();
    ls.Traverse();

}