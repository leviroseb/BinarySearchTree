#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "dsexceptions.h"
#include <iostream>
using namespace std;


template <typename Comparable>
class BinarySearchTree
{
  public:
    BinarySearchTree( ) :root( NULL )
    {
    }

    BinarySearchTree( const BinarySearchTree & rhs ) : root( NULL )
    {
        *this = rhs;
    }


    ~BinarySearchTree( )
    {
        makeEmpty( );
    }


    const Comparable & findMin( ) const
    {
        if( isEmpty( ) )
            throw UnderflowException( );
        return findMin( root )->element;
    }


    const Comparable & findMax( ) const
    {
        if( isEmpty( ) )
            throw UnderflowException( );
        return findMax( root )->element;
    }


    bool contains( const Comparable & x ) const
    {
        return contains( x, root );
    }


    bool isEmpty( ) const
    {
        return root == NULL;
    }


    void printTree( ostream & out = cout ) const
    {
        if( isEmpty( ) )
            out << "Empty tree" << endl;
        else
            printTree( root, out );
    }


    void makeEmpty( )
    {
        makeEmpty( root );
    }


    void insert( const Comparable & x )
    {
        insert( x, root );
    }


    void remove( const Comparable & x )
    {
        remove( x, root );
    }

    /**
     * Copia.
     */
    const BinarySearchTree & operator=( const BinarySearchTree & rhs )
    {
        if( this != &rhs )
        {
            makeEmpty( );
            root = clone( rhs.root );
        }
        return *this;
    }

  private:
    struct BinaryNode
    {
        Comparable element;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode( const Comparable & theElement, BinaryNode *lt, BinaryNode *rt )
            : element( theElement ), left( lt ), right( rt ) { }
    };

    BinaryNode *root;



    void insert( const Comparable & x, BinaryNode * & t )
    {
        if( t == NULL )
            t = new BinaryNode( x, NULL, NULL );
        else if( x < t->element )
            insert( x, t->left );
        else if( t->element < x )
            insert( x, t->right );
        else
            ;
    }


    void remove( const Comparable & x, BinaryNode * & t )
    {
        if( t == NULL )
            return;
        if( x < t->element )
            remove( x, t->left );
        else if( t->element < x )
            remove( x, t->right );
        else if( t->left != NULL && t->right != NULL ) //2 hijos
        {
            t->element = findMin( t->right )->element;
            remove( t->element, t->right );
        }
        else
        {
            BinaryNode *oldNode = t;
            t = ( t->left != NULL ) ? t->left : t->right;
            delete oldNode;
        }
    }


    BinaryNode * findMin( BinaryNode *t ) const
    {
        if( t == NULL )
            return NULL;
        if( t->left == NULL )
            return t;
        return findMin( t->left );
    }


    BinaryNode * findMax( BinaryNode *t ) const
    {
        if( t != NULL )
            while( t->right != NULL )
                t = t->right;
        return t;
    }



    bool contains( const Comparable & x, BinaryNode *t ) const
    {
        if( t == NULL )
            return false;
        else if( x < t->element )
            return contains( x, t->left );
        else if( t->element < x )
            return contains( x, t->right );
        else
            return true;
    }

    void makeEmpty( BinaryNode * & t )
    {
        if( t != NULL )
        {
            makeEmpty( t->left );
            makeEmpty( t->right );
            delete t;
        }
        t = NULL;
    }


    void printTree( BinaryNode *t, ostream & out ) const
    {
        if( t != NULL )
        {
            printTree( t->left, out );
            out << t->element << endl;
            printTree( t->right, out );
        }
    }


    BinaryNode * clone( BinaryNode *t ) const
    {
        if( t == NULL )
            return NULL;
        else
            return new BinaryNode( t->element, clone( t->left ), clone( t->right ) );
    }
};

#endif
