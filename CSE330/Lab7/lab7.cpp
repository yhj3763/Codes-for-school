#include<iostream>
#include<vector>
#include<cstdlib>
#include<time.h>

using namespace std;

template <typename T>
class Tnode
{
    public :
    T data;
    Tnode *lptr;
    Tnode *rptr;
};

template <typename T>
class Mtree
{ public :
    Mtree();
    void add(T x);
    void add(Tnode<T>* ptr,T x);
    bool find(T x);
    vector<T> inorder();
    vector<T> preorder();
    vector<T> postorder();
    void del(T x);
    int size(){return tsize;}

    private :
    Tnode<T> *root;
    bool find(Tnode<T>* ptr,T x);
    vector<T>v;
    void inorder(Tnode<T>* ptr);
    void preorder(Tnode<T>* ptr);
    void postorder(Tnode<T>* ptr);
    void del(Tnode<T>* ptr,T x);
    int tsize;
};

template <typename T>
Mtree<T>::Mtree()
{
    tsize=0;
    root=0;
}

template <typename T>
void Mtree<T>::add(T x)
{
    if(tsize==0)
    {
        Tnode<T>* ptr=new Tnode<T>();
        root=ptr;
        root->lptr=0;
        root->rptr=0;
        root->data=x;
        tsize++;
        return;
    }
    else
    {
        add(root,x);
    }
}

template <typename T>
void Mtree<T>::add(Tnode<T>* ptr, T x)
{
    if(x<=ptr->data and ptr->lptr==0)
    {
        Tnode<T>* nptr=new Tnode<T>();
        nptr->data=x;
        nptr->lptr=0;
        nptr->rptr=0;
        ptr->lptr=nptr;
        tsize++;
        return;
    }
    if(x>=ptr->data and ptr->rptr==0)
    {
        Tnode<T>* nptr=new Tnode<T>();
        nptr->data=x;
        nptr->lptr=0;
        nptr->rptr=0;
        ptr->rptr=nptr;
        tsize++;
        return;
    }
    if(x<=ptr->data)
    {
        add(ptr->lptr,x);
    }
    else
        add(ptr->rptr,x);
}

template <typename T>
bool Mtree<T>::find(T x)
{
    return find(root,x);
}

template <typename T>
bool Mtree<T>::find(Tnode<T>* ptr,T x)
{
    if(ptr->data==x)
    {
        return true;
    }
    if(ptr==0)
    {
        return false;
    }
    if(x<=ptr->data)
    {
        return find(ptr->lptr, x);
    }
    else
    {
        return find(ptr->rptr, x);
    }
    
}

template <typename T>
vector<T> Mtree<T>::inorder()
{
    v.clear();
    inorder(root);
    return v;
}

template <typename T>
void Mtree<T>::inorder(Tnode<T>* ptr)
{
    if(ptr==0)
    {
        return;
    }
    else
    {
        inorder(ptr->lptr);
        v.push_back(ptr->data);
        inorder(ptr->rptr);
    }
}

template <typename T>
vector<T> Mtree<T>::preorder()
{
    v.clear();
    preorder(root);
    return v;
}

template <typename T>
void Mtree<T>::preorder(Tnode<T>* ptr)
{
    if(ptr==0)
    {
        return;
    }
    v.push_back(ptr->data);
    preorder(ptr->lptr);
    preorder(ptr->rptr);
}

template <typename T>
vector<T> Mtree<T>::postorder()
{
    v.clear();
    postorder(root);
    return v;
}

template <typename T>
void Mtree<T>::postorder(Tnode<T>* ptr)
{
    if(ptr==0)
    {
        return;
    }

    postorder(ptr->lptr);
    postorder(ptr->rptr);
    v.push_back(ptr->data);
}

template <typename T>
void Mtree<T>::del(T x)
{
    if(root->data==x)
    {
        v.clear();
        tsize=0;
        preorder(root);
        for(int i=0;i<v.size();i++)
        {
            if(v[i]!=x)
            {
                add(v[i]);
            }
        }
    }
    else
    {
        del(root,x);
    }
}

template <typename T>
void Mtree<T>::del(Tnode<T>* ptr,T x)
{
    if(ptr==0)
    {
        return;
    }
    if(ptr->lptr->data==x)
    {
        v.clear();
        tsize=0;
        preorder(root);
        for(int i=0;i<v.size();i++)
        {
            if(v[i]!=x)
            {
                add(v[i]);
            }
        }
        return;
    }
    if(x<=ptr->data)
    {
        del(ptr->lptr,x);
    }
    else
    {
        del(ptr->rptr,x);
    }
}


	int main()
{
	clock_t start, finish;
	srand (time(NULL));
	Mtree<int> t;
	int n=0;
	cout << "Enter size of input :" ;
	cin >> n;
	for (int i=0; i<n; i++)
		t.add(rand());
	start=clock();
	vector<int> v=t.inorder();
	finish=clock();
	cout << "time= " << finish-start;

}
