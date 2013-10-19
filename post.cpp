//Souriya Khaosanga
//cs202 hw3
//post.cpp

#include "header.h"

//constructor
post::post() 
{
            posted = false;
            number_topics = 0;
            paragraph = NULL; 
                       
              for(int i = 0; i<MAX;++i)
              {
                      topic[i]= NULL;
              }
}


//destructor
post::~post()
{
           removeComments();
}

//copy constructor
post::post(const post & p)
{
             copy(p);
}


//copy function
void post::copy(const post & source)
{
     
              posted = source.posted;
              number_topics = source.number_topics;
              paragraph = new char[strlen(source.paragraph)+1];
              strcpy(paragraph,source.paragraph);
       
              for(int i = 0; i<MAX-1;++i)
              {
                      if(topic[i])
                      {
                       if(typeid(*source.topic[i]) == typeid(Comment))
                       {
                          topic[i] = new Comment();
                          topic[i]->Add(source.topic[i]->Get());
                       }
                       else
                       {
                          topic[i] = new Reply();
                          topic[i]->Add(source.topic[i]->Get());
                       }
                      }
              }
              
              
     
     
}

//remove commennts function
void post::removeComments()
{
     for(int i=0; i<MAX;++i)
             {
                  if(topic[i])
                  {
                     delete [] topic;
                     topic[i] = NULL;
                  }
             }
     
}


//display the comment
void post::dispC()
{
     for(int i =0;i<MAX-1;++i)
     {       
             if(topic[i])
                         topic[i]->Display();
     }
}


//add comment
void post::addC(char * c)
{
     
     topic[number_topics] = new Comment();    
     topic[number_topics]->Add(c);
     ++number_topics;
}

//add reply
void post::addR(char * r)
{
     
     topic[number_topics] = new Reply();    
     topic[number_topics]->Add(r);
     ++number_topics;
}

//write to the paragraph
void post::write(char * to_write)
{
     paragraph = new char[strlen(to_write)+1];
     strcpy(paragraph,to_write);
}

//display the post
void post::displayPost()
{
     if(posted)
     {
             cout<<"Your post: ";
             cout<<paragraph<<endl;
     }
}

//get the number of replies/comments
int post::getTopicNum()
{
    return number_topics;
}

//turn the post on
void post::postOn()
{
     posted = true;
}

//turn the post off
void post::postOff()
{
     posted = false;
}

