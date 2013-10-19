//Souriya Khaosanga
//cs202 hw3
//header.h

//this is the header file
#include <iostream>
#include <cstring>
#include <cctype>
//const exist below
const int MAX = 15;
const int SIZE = 300;

using namespace std;


//This is the abstract class
class Base
{
      public:
             Base();
                          
             //pure virtual function below
             //also known as abstract base class
             virtual ~Base() = 0;
             virtual void Add(char *) = 0;
             virtual void Display() = 0;
             virtual char * Get() =0;
      protected:
             char * test;          
};


//Derived class of Base class
class Comment : public Base
{
      public:
             Comment();
             ~Comment();
             char * Get();
             Comment(const Comment &);
             Comment & operator = (const Comment&);
             Comment & operator = (const char *);
             friend ostream & operator <<(ostream &, const Comment&);
             friend istream & operator >>(istream&, Comment &);
             Comment & operator += (const Comment &);
             void Add(char *);
             void Display();
      protected:
             char * comments;
              
};

//Derived class of Base
class Reply : public Base
{
      public:
             Reply();
             ~Reply();
             Reply(const Reply & copy);
             char * Get();
             void Add(char *);
             void Display();
             Reply & operator = (const Reply&);
             Reply & operator = (const char *);
             friend ostream & operator <<(ostream &, const Reply&);
             friend istream & operator >>(istream&, Reply &);
             Reply & operator += (const Reply &);
      protected:
      
             char * replies;
};



//Post class
class post
{
      public:
             post();
             ~post();
             post(const post &);
             void copy(const post & source);
             char * & Topic();
             void setTopic(Base *);
             void postOn();
             void postOff();
             void write(char *);
             void displayPost();
             int getTopicNum();
             void addC(char *);
             void addR(char *);
             void dispC();
             void removeComments();
      protected:
              bool posted;
              int number_topics;
              char * paragraph;
              Base * topic[MAX];
};             

//Class node for data structure
class node{
      public:
             node();
             ~node();
             node * & Next();
             node * & Previous();
             void setIndex(int number);
             int getIndex();
             void copy(node * ,node *trail);
             post & getPost();
             
      protected:
              int index;
              post a_post;
              node * next;
              node * previous;
};

//Blog contains the head of the blog
class blog{
      public:
             blog();
             ~blog();
             void deleteAll();
             void postBlog(int);
             void addPost(int num, char *);
             void editPost(int num, char *);
             void displayList();
             void displayPrevious();
             void addComment(int num, char *);
             void addReply(int num, char *);
             void deleteComments(int num);
             node * & Head();
      protected:
             void copy(blog * source, node * trail);
             void deleteComments(int num, node * & head);
             void addReply(int num,char*,node *& head);
             void addComment(int num, char *, node * & head);   
             void addPost(int num,char *, node * & head,node * trail);
             void editPost(int num, char * mod, node * head);
             void displayList(node * head);
             void deleteAll(node * & head);
             void postBlog(int, node * &);
             
             
             node * head;
};


