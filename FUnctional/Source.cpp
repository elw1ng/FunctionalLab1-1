#include <iostream>
#include <list>

using namespace std;

template<typename T>
list<T> Singleton(T a) {
    return { a };
}

template<typename T>
bool null(list<T> lst) {
    if (lst.empty())
        return true;
    else
        return false;
}


template<typename T>
list<T> snoc(list<T> lst, T a) {
    if (lst.empty())
        return { a };
    T x = lst.front();
    lst.pop_front();
    list<T> snoced = snoc(lst, a);
    snoced.push_front(x);
    return snoced;
}

template<typename T>
int length(list<T> lst) {
    if (lst.empty())
        return 0;
    else {
        lst.pop_front();
        return 1+length(lst);
    }
}
int main()
{
    
    list<int> mylist = Singleton(232);
    for (auto v : mylist)
        cout << v << "\n";
    cout << "\n\n";
    cout << null(mylist) << "\n\n";
    mylist.pop_back();
    cout << null(mylist) << "\n\n";

    mylist = snoc(mylist, 1);
    mylist = snoc(mylist, 2);
    mylist = snoc(mylist, 3);
    for (auto v : mylist)
        cout << v << "\n";
    cout << "\n\n";
    cout << length(mylist) << "\n\n";
    return 0;

}