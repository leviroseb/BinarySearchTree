#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

    // Test program
int main( )
{

    BinarySearchTree<int> t;
    int n,k;
    cout<<"Numero de nodos del arbol: ";
    cin>>n;
    for(int i=0;i<n;i++ ){
        cout<<"dato: ";
        cin>>k;
        t.insert(k);

    }

    t.printTree();
    cout<<"Elemento a remover: ";
    cin>>k;
    t.remove(k);
    t.printTree();

    cout<<"elemento a buscar: ";
    cin>>k;
    cout<<t.contains(k);

    BinarySearchTree<int> t2;
    t2=t;
    cout<<endl;
    t2.printTree();

}
