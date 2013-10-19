//Souriya Khaosanga
//CS202 HW3
//comment_reply.cpp

#include "header.h" 


//derived class init list
Base::Base(): test(NULL) {}



// Base class
Base::~Base() { delete [] test; } //destructor

//-----------------------------------------------------------------------

//Comment
Comment::Comment() { comments = NULL;} //constructor

//copy constructor
Comment::Comment(const Comment & source)
{     comments = new char[strlen(source.comments)];
      strcpy(comments,source.comments);
}

//operator overload for assigmnet operator
Comment & Comment:: operator = (const Comment & op2)
{
        //check for self assignment
        if( this == & op2) //same entity
            return *this;
            
        delete [] comments;
        comments = new char[strlen(op2.comments)+1];
        strcpy(comments,op2.comments);
        return *this;
        
        
}

//output operator 
ostream & operator <<(ostream & op1, const Comment& op2)
{
        op1<<op2.comments;
        return op1;
        
}

//input operator
istream & operator >>(istream& op1, Comment & op2)
{
        char temp[SIZE];
        if(op2.comments)
                       delete op2.comments;
        op1 >> temp;
        op2.comments = new char[strlen(temp)+1];
        strcpy(op2.comments, temp);
        return op1;
}

//input operator for char *
Comment & Comment ::operator = (const char * op2)
{
        delete [] comments;
        comments = new char[strlen(op2)+1];
        strcpy(comments,op2);
        return *this;
}

//append the operator 
//adds to the comment list
Comment & Comment::operator += (const Comment & op1)
{
        char * temp = new char[strlen(op1.comments)+strlen(op1.comments)+1];
        strcpy(temp,op1.comments);
        
        strcat(temp,comments);
        
        comments = temp;
        
        return *this;
        
}
                       

Comment::~Comment() { delete [] comments; } //destructor

void Comment::Add(char * to_add) //add a char *
{
     comments = new char[strlen(to_add)+1];
     strcpy(comments, to_add);
}


//display the comments
void Comment::Display() //display that value
{
     cout<<"Comment: ";
     cout<<comments<<endl;
}

//get the comment data member
char * Comment::Get()
{
     return comments;
}



//----------------------------------------------------------------------------
//Reply implemenation exist below here
Reply::Reply() { replies = NULL;} //constructor

Reply::~Reply() { delete [] replies; }//destructor

void Reply::Add(char * to_add) //add a value
{
     replies = new char[strlen(to_add)+1];
     strcpy(replies, to_add);
}

void Reply::Display() //display the value
{
     cout<<"Reply: ";
     cout<<replies<<endl;
}

//get reply
char * Reply::Get()
{
     return replies;
}

//Reply assigment operator
Reply & Reply::operator = (const Reply& op2)
{
      //check for self assignment
        if( this == & op2) //same entity
            return *this;
            
        delete [] replies;
        replies = new char[strlen(op2.replies)+1];
        strcpy(replies,op2.replies);
        return *this;
   
}

//reply assignment operator for char *
Reply & Reply::operator = (const char * op2)
{
      delete [] replies;
      replies = new char[strlen(op2)+1];
      strcpy(replies,op2);
      return *this;
}

//reply output operator
ostream & operator <<(ostream & op1, const Reply& op2) 
{
        op1<<op2.replies;
        return  op1;
}

//reply input operator
istream & operator >>(istream& op1, Reply & op2) 
{
        char temp[SIZE];
        if(op2.replies)
                       delete op2.replies;
        op1 >> temp;
        op2.replies = new char[strlen(temp)+1];
        strcpy(op2.replies, temp);
        return op1;
        
        
}

//reply add to reply operator
Reply & Reply::operator += (const Reply & op1) 
{
        char * temp = new char[strlen(op1.replies)+strlen(op1.replies)+1];
        strcpy(temp,op1.replies);
        
        strcat(temp,replies);
        
        replies = temp;
        
        return *this;
      
}


