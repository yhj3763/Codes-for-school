#include <iostream>
#include <cassert>

using namespace std;

template <typename T>
class Lnode
{
    public :
    T data;
    Lnode *lptr;
    Lnode *rptr;
};

template <typename T>
class Mlist
{ public :
    typedef Lnode<T>* iterator;
    Mlist();
    void add(T x); // add to back
    void del(); // delete front
    void del(T x); //deletes nodes with value x;
    T getfront();
    T operator[] (unsigned int i);
    void insert(iterator ix, T x);
    void erase(iterator ix);
    void insert(int i, T x);
    void erase(int i);
    int size(){return lsize;}
    iterator begin(){return first;}
    iterator end(){return end;}
    
    private :
    Lnode<T> *first;
    Lnode<T> *last;
    int lsize;
};

template <typename T>
Mlist<T>::Mlist()
{
    first=NULL;
    last=0;
    lsize=0;
  
}

template <typename T>
void Mlist<T>::add(T x)
{
    Lnode<T>* ptr=new Lnode<T>();
    ptr->data=x;
    if(lsize==0)
    {
        first=ptr;
        last=ptr;
        ptr->lptr=0;
        ptr->rptr=0;
    }
    else
    {
        last->rptr=ptr;
        ptr->lptr=last;
        ptr->rptr=0;
        last=ptr;
    }
    lsize++;

}

template <typename T>
void Mlist<T>::del()
{
    assert(lsize>0);
    if(lsize==0)
    {
        return;
    }
    if(lsize==1)
    {
        delete first;
        first=0;
        last=0;
        lsize--;
        return;
    }

    first=first->rptr;
    delete first->lptr;
    first->lptr=0;
    lsize--;

}

template <typename T>
void Mlist<T>::del(T x)
{
    assert(lsize>0);
    if(lsize==0)
    {
        return;
    }
    if(lsize==1 and first->data==x)
    {
        delete first;
        first=0;
        last=0;
        lsize--;
        return;

    }

    Lnode<T>* ptr=new Lnode<T>();
    Lnode<T>* temp=new Lnode<T>();
    ptr=first;
    temp=first;
    for(int i=0;i<lsize;i++)
    {
        if(first->data==x)
        {
            first=first->rptr;
            delete first->lptr;
            first->lptr=0;
            lsize--;
            return;
        }
        if(last->data==x)
        {
            last=last->lptr;
            delete last->rptr;
            last->rptr=0;
            lsize--;
            return;
        }
        if(ptr->data==x)
        {
            temp=ptr->lptr;
            temp->rptr=ptr->rptr;
            ptr->rptr->lptr=temp;
            lsize--;

        }

        ptr=ptr->rptr;
        temp=ptr->rptr;
    }
}

template <typename T>
T Mlist<T>::getfront()
{
    assert(lsize>0);
    return first->data;
}

template <typename T>
T Mlist<T>::operator[](unsigned int i)
{
    Lnode<T>* ptr1=new Lnode<T>();
    ptr1=first;
    for(int j=0;j<i;j++)
    {
        ptr1=ptr1->rptr;
    }
    return ptr1->data;
}

template <typename T>
void Mlist<T>::insert(iterator ix, T x)
{   
    assert(ix!=NULL);
    if(ix==0)
    {
        this->add(x);
        return;
    }
    Lnode<T> *ptr=new Lnode<T>();
    ptr->data=x;
    if(ix==first)
    {
        ptr->rptr=first;
        ptr->lptr=0;
        first->lptr=ptr;
        first=ptr;
        lsize++;
        return;
    }
    if(ix==last)
    {
        ptr->rptr=ix->rptr;
        ptr->lptr=ix;
        ix->rptr=ptr;
        lsize++;
        return; 
    }
    ptr->lptr=ix->lptr;
    ptr->rptr=ix;
    ix->lptr->rptr=ptr;
    ix->lptr=ptr;
    lsize++;
    return;
}

template <typename T>
void Mlist<T>::erase(iterator ix)
{
    assert(ix!=NULL and lsize>0);
    if(ix==first)
    {
        ix->rptr->lptr=0;
        first=ix->rptr;
        delete ix;
        lsize--;
        return;
    }
    if(ix==last)
    {
        last->lptr->rptr=0;
        last=ix->lptr;
        delete ix;
        lsize--;
        return;
    }
    ix->lptr->rptr=ix->rptr;
    ix->rptr->lptr=ix->lptr;
    delete ix;
    lsize--;
    return;
}

template <typename T>
void Mlist<T>::insert(int i, T x)
{
    iterator ix=first;
    for(int j=0;j<i;j++)
    {
        ix=ix->rptr;
    }
    insert(ix,x);
}

template <typename T>
void Mlist<T>::erase(int i)
{
    iterator ix=first;
    for(int j=0;j<i;j++)
    {
        ix=ix->rptr;
    }
    erase(ix);
}


  int main()
{
 Mlist<int> li;
 li.add(10);
 li.add(20);
 li.add(30);
 li.add(40);
 li.add(50);
 li.add(60);
 
 for (int i=0; i<li.size(); i++)
 { cout << li[i] << " ";
 }
 cout << endl;

 li.insert(3,35);
 for (int i=0; i<li.size(); i++)
 { cout << li[i] << " ";
 }
 cout << endl;

 li.erase(3);
 for (int i=0; i<li.size(); i++)
 { cout << li[i] << " ";
 }
 cout << endl;
}


 


