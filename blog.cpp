//Souriya Khaosanga
//CS202 HW3
//blog.cpp


#include "header.h"


//Blog functions exist here

blog::blog() : head(NULL){}
//initialization

blog::~blog()
//destructor
{
             deleteAll(head);
             
}


void blog::copy(blog * source, node * trail)
//Copy function passing in a source and trail
//Doesn't function properly
{
     
     if(!source->head)
              head = NULL;
              
     head = new node();         
     head->copy(source->head,trail);

}

//function used to delete all comments
void blog::deleteComments(int num)
{    
         deleteComments(num, head);
         

}

void blog::deleteComments(int num, node *& head)
{
      if(!head)
              return;
     if(num == head->getIndex())
            head->getPost().removeComments();
     else
         deleteComments(num, head->Next());
}


//Function used to add reply based on a index num
//and a string
void blog::addReply(int num, char * r)
{
     addReply(num, r, head);
}

void blog::addReply(int num, char * r, node * & head)
{
     if(!head)
              return;
     if(num == head->getIndex())
            head->getPost().addR(r);
     else
         addReply(num,r,head->Next());
 
}

//Function used to add a comment
void blog::addComment(int num, char * c)
{
     addComment(num,c, head);
     
}

void blog::addComment(int num, char * c, node * & head)
{
     if(!head)
              return;
     if(num == head->getIndex())
            head->getPost().addC(c);
     else
         addComment(num,c,head->Next());
}

//function used to edit a post
void blog::editPost(int num, char * mod)
{
     editPost(num, mod, head);
}

void blog::editPost(int num, char * mod, node * head)
{
     if(!head)
              return;
     if (num == head->getIndex())
             head->getPost().write(mod);
     else
         editPost(num,mod, head->Next());    
}

//function used to write a post
void blog::addPost(int num, char * in, node * & head, node * trail)
{
     
     if(!head)
     {
              head = new node();
              head->setIndex(num);
              head->getPost().write(in);
              head->Next() = NULL;
              if(trail)
                     head->Previous() = trail;
              else       
                     head->Previous() = NULL;
     }
     else{
         trail = head;
         addPost(num, in, head->Next(), trail);
     }
}

//function is used to turn on a post
void blog::postBlog(int value)
{
     postBlog(value,head);
     
}

void blog::postBlog(int value, node * & head)
{
     if(!head)
              return;
     else if (value == head->getIndex())
             head->getPost().postOn();
     else
         postBlog(value, head->Next());    
     
}


//function is the wrapper function for the post add
void blog::addPost(int num, char * in)
{
    node * trailer = NULL;
    addPost(num,in, head, trailer);
}

//function used to display all of the blog
void blog::displayList()
{
     displayList(head);
}

void blog::displayList(node * head)
{
     if(!head)
              return;
     cout<<"Post index #: ";
     cout<<head->getIndex()<<endl;
     head->getPost().displayPost();
     head->getPost().dispC();
     displayList(head->Next());
}


//Function used to check if the previous pointer is working
void blog::displayPrevious()
{
     node * temp = head;
     while(temp->Next())
                temp=temp->Next();
     while(temp)
     {
                cout<<temp->getIndex()<<endl;
                temp = temp->Previous();
     }
                
}


//function used to delete all
//this is not functioning correctly
void blog::deleteAll()
{
     deleteAll(head);
}
void blog::deleteAll(node * & head)
{


}


