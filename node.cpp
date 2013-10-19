//Souriya Khaosanga
//cs202 HW3
//node.cpp

#include "header.h"

//constructor
node::node(): index(0),next(NULL),previous(NULL){}

//destructor
node::~node()
{
             previous = NULL;
             next = NULL;
}

//setter for index
void node::setIndex(int num)
{
     index = num;
}


//getter for next pointer
node * & node::Next()
{
     return next;
}

//getter for previous pointer
node * & node::Previous()
{
     return previous;
}

//get index
int node::getIndex()
{
    return index;
}

//access the post object
post & node::getPost()
{
     return a_post;
}

//copy the node
void node::copy(node * source, node * trail)
{
     if(!source)
     {     
           index = source->index;
           a_post.copy(source->a_post);
           next = NULL;
           if(!trail)
               previous = NULL;
           else
               previous = trail;      
           
     } 
     {
           trail = source;   
           copy(source->next->Next(),trail);
     }
     
}
