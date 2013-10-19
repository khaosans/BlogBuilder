//Souriya Khaosanga
//cs202 HW3
//main.cpp

#include "header.h"


//main body of the program exist here
int main()
{
    
    //create a blog
    blog one;
    
    one.addPost(1,"test1");
    //add a post
    
    one.postBlog(1);
    //turn on the post    

    one.addComment(1,"comment1");
    one.addComment(1,"c2");
    one.addReply(1,"Reply1");
    //post comments and reply
    
    
    one.deleteComments(1);
    //delete all the comments for index 1
    

    
    one.addPost(2,"test2");
    //write a post for index 2
    
    one.addComment(2,"comment2");
    one.addReply(2,"reply2");
    //add a reply and post
    
    
    one.addPost(3,"test3");
    //write a post in index 3
    one.postBlog(3);
    //turn it on
    
    one.editPost(3,"TEST3");
    //edit post index 3 to all caps
    
    one.displayList();
    //display everything
    
    
    //Operator overloading test
    
    Comment C;
    C = "Comment test";
    cout << C <<endl;
    
    Reply R;
    
    R = "Reply test";
    
    cout <<R <<endl;
    
    
      
   
    
    
    
    //pause
    cin.get();
    return 0;
}
