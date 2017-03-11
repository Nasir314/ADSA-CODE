#include<iostream>
#include<cstring>
#include "BSTree.hpp"
//#include "AVL.hpp"

using namespace std;

int main(){

     BSTree<int,string> bst;
     //AVL<int,string> avl;
     string inp;
     int choice;
     string value;
     int key,loop=0;
     int flag,flag1=0,flag2;
     while(flag1!=1){
     cout<<"----------------------------------------Dictionary Data Structures---------------------------------------"<<endl;
     cout<<endl;
     cout<<"1).Binary Search Tree\n2).AVL Tree (Height Balancing Tree)\n"<<endl;
     cout<<"choose an option to workout\n\n";
     cin>>inp;
     cout<<endl;
     if(inp=="1"||inp=="2")
           {
               if(inp=="1"){
                         cout<<"--------------------Binary Search Tree-------------------"<<endl;
                         cout<<"---------------------------------------------------------"<<endl;
                         cout<<endl;
                         while(loop!=1){
                         cout<<"1).Insert a key\n2).Search for a key\n3).Delete a key\n4).Display all the keys as obserbed in inorder traversal\n5).Display all the keys as obserbed in preorder traversal\n6).Display all the keys as obserbed in postorder traversal\n7).Display all the keys as obserbed in levelorder traversal\n8).Display the minimum key in a tree\n9).Display the maximum key in a tree\n10).Display the successor of a key\n11).Display the predecessor of a key\n12).Display the height of a tree\n13).Exit\n\n";
                         cout<<"Enter your choice"<<endl;
                         cin>>choice;
                         while(cin.fail()){
                               cout << "Error!" <<endl;
                               cin.clear();
                               cin.ignore(256,'\n');
                               cout<<"Enter your choice"<<endl;
                               cin >> choice;
                          }
                           switch(choice){
  
                               case 1 :
                                          cout<<"Enter key and value (only unique keys will be accepted and should be integer)"<<endl;
                                          cin>>key;
                                          while(cin.fail()){
                                              cout << "Error!" <<endl;
                                              cin.clear();
                                              cin.ignore(256,'\n');
                                              cout<<"Enter key and value (only unique keys will be accepted and should be integer)"<<endl;
                                              cin >> key;
                                          }
                                          cin>>value;
                                          bst.put(key,value);
                                          break;

                               case 2 :
                                          cout<<"Insert key to search"<<endl;
                                          cin>>key;
                                          while(cin.fail()){
                                              cout << "Error!" <<endl;
                                              cin.clear();
                                              cin.ignore(256,'\n');
                                              cout<<"Insert key to search"<<endl;
                                              cin >> key;
                                          }
                                          if(bst.has(key)){
                                               cout<<key<<" : "<<bst.get(key)<<endl;
                                          }
                                          else cout<<"Key is not present"<<endl;
                                          break;

                               case 3 :
                                         cout<<"Insert key to delete"<<endl;
                                         cin>>key;
                                          while(cin.fail()){
                                              cout << "Error!" <<endl;
                                              cin.clear();
                                              cin.ignore(256,'\n');
                                              cout<<"Insert key to delete"<<endl;
                                              cin >> key;
                                          }
                                          if(bst.has(key)){
                                                   bst.remove(key);
                                                   cout<<"Deleted Successfully\n";
                                          }
                                          else cout<<"Key is not present"<<endl;
                                          break;
                                        
                               case 4 :
                                         cout<<"Key-Value pairs through Inorder Traversal\n";
                                         bst.print_in_order();
                                         cout<<endl;
                                         break;

                               case 5 : 
                                         cout<<"Key-Value pairs through Preorder Traversal\n";
                                         bst.print_pre_order();
                                         cout<<endl;
                                         break;

                               case 6 :
                                         cout<<"Key-Value pairs through Postorder Traversal\n";
                                         bst.print_post_order();
                                         cout<<endl;
                                         break;

                               /*case 7 :
                                         cout<<"Key-Value pairs through Levelorder Traversal\n";
                                         bst.print_level_order();
                                         cout<<endl;
                                         break;*/

                               case 8 :
                                         cout<<"Minimum key present is "<<bst.minimum()<<endl;
                                         break;
                         
                               case 9 :
                                         cout<<"Maximum key present is "<<bst.maximum()<<endl;
                                         break;

                               case 10 :
                                        cout<<"Insert key to find its successor"<<endl;
                                        cin>>key;
                                          while(cin.fail()){
                                              cout << "Error!" <<endl;
                                              cin.clear();
                                              cin.ignore(256,'\n');
                                              cout<<"Insert key to find its successor"<<endl;
                                              cin >> key;
                                          }
                                        if(bst.has(key)){
                                               if(key==bst.maximum()){
                                                      cout<<"No successor is present bcoz you entered maximum key in the tree\n";
                                               }
                                               else
                                                      cout<<"Successor of the Key is "<<bst.successor(key)<<endl;
                                        }
                                        else cout<<"Key is not present\n";
                                        break;

                              case 11 : 
                                       cout<<"Insert key to find its predecessor"<<endl;
                                        cin>>key;
                                          while(cin.fail()){
                                              cout << "Error!" <<endl;
                                              cin.clear();
                                              cin.ignore(256,'\n');
                                              cout<<"Insert key to find its predecessor"<<endl;
                                              cin >> key;
                                          }
                                        if(bst.has(key)){
                                               if(key==bst.minimum()){
                                                      cout<<"No predecessor is present bcoz you entered minimum key in the tree\n";
                                               }
                                               else
                                                      cout<<"Predecessor of the Key is "<<bst.predecessor(key)<<endl;
                                        }
                                        else cout<<"Key is not present\n";
                                        break;

                              case 12 :
                                        cout<<"Height of the tree is "<<bst.getHeight()<<endl;
                                        break;
                              
                              case 13 :
                                        loop=1;
                                        break;

                              default :
                                       cout<<"Enter valid Choice\n";
                                       break;
                       }
                       }
                }   

            /*     if(inp=="2"){
                         cout<<"--------------------AVL Tree (Height Balancing Tree)-------------------"<<endl;
                         cout<<"-----------------------------------------------------------------------"<<endl;
                         cout<<endl;     
                         while(loop!=1){
                         cout<<"1).Insert a key\n2).Search for a key\n3).Delete a key\n4).Display all the keys as obserbed in inorder traversal\n5).Display all the keys as obserbed in preorder traversal\n6).Display all the keys as obserbed in postorder traversal\n7).Display all the keys as obserbed in levelorder traversal\n8).Display the minimum key in a tree\n9).Display the maximum key in a tree\n10).Display the successor of a key\n11).Display the predecessor of a key\n12).Display the height of a tree\n13).Exit\n\n";
                         cout<<"Enter your choice"<<endl;
                         cin>>choice;
                         while(cin.fail()){
                               cout << "Error!" <<endl;
                               cin.clear();
                               cin.ignore(256,'\n');
                               cout<<"Enter your choice"<<endl;
                               cin >> choice;
                          }
                         switch(choice){
  
                               case 1 :
                                          cout<<"Enter key and value (only unique keys will be accepted and should be integer)"<<endl;
                                          cin>>key;
                                          while(cin.fail()){
                                               cout << "Error!" <<endl;
                                               cin.clear();
                                               cin.ignore(256,'\n');
                                               cout<<"Enter key and value (only unique keys will be accepted and should be integer)"<<endl;
                                               cin >> key;
                                          }
                                          cin>>value;
                                          avl.put(key,value);
                                          break;

                               case 2 :
                                          cout<<"Insert key to search"<<endl;
                                          cin>>key;
                                          while(cin.fail()){
                                               cout << "Error!" <<endl;
                                               cin.clear();
                                               cin.ignore(256,'\n');
                                               cout<<"Insert key to search"<<endl;
                                               cin >> key;
                                          }
                                          if(avl.has(key)){
                                               cout<<key<<" : "<<avl.get(key)<<endl;
                                          }
                                          else cout<<"Key is not present"<<endl;
                                          break;

                               case 3 :
                                         cout<<"Insert key to delete"<<endl;
                                         cin>>key;
                                          while(cin.fail()){
                                               cout << "Error!" <<endl;
                                               cin.clear();
                                               cin.ignore(256,'\n');
                                               cout<<"Insert key to delete"<<endl;
                                               cin >> key;
                                          }
                                          if(avl.has(key)){
                                                   avl.remove(key);
                                                   cout<<"Deleted Successfully\n";
                                          }
                                          else cout<<"Key is not present"<<endl;
                                          break;
                                        
                               case 4 :
                                         cout<<"Key-Value pairs through Inorder Traversal\n";
                                         avl.print_in_order();
                                         cout<<endl;
                                         break;

                               case 5 : 
                                         cout<<"Key-Value pairs through Preorder Traversal\n";
                                         avl.print_pre_order();
                                         cout<<endl;
                                         break;

                               case 6 :
                                         cout<<"Key-Value pairs through Postorder Traversal\n";
                                         avl.print_post_order();
                                         cout<<endl;
                                         break;

                               case 7 :
                                         cout<<"Key-Value pairs through Levelorder Traversal\n";
                                         avl.print_level_order();
                                         cout<<endl;
                                         break;

                               case 8 :
                                         cout<<"Minimum key present is "<<avl.minimum()<<endl;
                                         break;
                         
                               case 9 :
                                         cout<<"Maximum key present is "<<avl.maximum()<<endl;
                                         break;

                               case 10 :
                                        cout<<"Insert key to find its successor"<<endl;
                                        cin>>key;
                                           while(cin.fail()){
                                               cout << "Error!" <<endl;
                                               cin.clear();
                                               cin.ignore(256,'\n');
                                               cout<<"Insert key to find its successor"<<endl;
                                               cin >> key;
                                          }
                                        if(avl.has(key)){
                                               if(key==avl.maximum()){
                                                      cout<<"No successor is present bcoz you entered maximum key in the tree\n";
                                               }
                                               else
                                                      cout<<"Successor of the Key is "<<avl.successor(key)<<endl;
                                        }
                                        else cout<<"Key is not present\n";
                                        break;

                              case 11 : 
                                       cout<<"Insert key to find its predecessor"<<endl;
                                         cin>>key;
                                           while(cin.fail()){
                                               cout << "Error!" <<endl;
                                               cin.clear();
                                               cin.ignore(256,'\n');
                                               cout<<"Insert key to find its predecessor"<<endl;
                                               cin >> key;
                                          }
                                        if(avl.has(key)){
                                               if(key==avl.minimum()){
                                                      cout<<"No predecessor is present bcoz you entered minimum key in the tree\n";
                                               }
                                               else
                                                      cout<<"Predecessor of the Key is "<<avl.predecessor(key)<<endl;
                                        }
                                        else cout<<"Key is not present\n";
                                        break;

                              case 12 :
                                        cout<<"Height of the tree is "<<avl.getHeight()<<endl;
                                        break;
                              
                              case 13 :
                                        loop=1;
                                        break;

                              default :
                                       cout<<"Enter valid Choice\n";
                                       break;
                       }
                       }
         }*/
         flag1=1; 
      } 

       
       else {
           cout<<"Enter Valid Choice"<<endl;
           cout<<endl;
       }
       

    cout<<"---------------------------------------------THANKS FOR USING-------------------------------------------------------------"<<endl;

  

 } 

return 0;

}  
    
    
         
                                          

                       

