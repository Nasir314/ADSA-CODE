#ifndef BSTREE_HPP
#define BSTREE_HPP 1
#include "Dictionary.hpp"
#include<cstring>

template <class Key, class Value>
class node{
	public:
	Key key;
	Value value;
	node<Key,Value>	*left;
	node<Key,Value> *right;
	int height;
	};
template <class Key,class Value>
class BSTree : public Dictionary<Key, Value>
 {

 private:
	node<Key,Value> *root;
	int nodes;
 public:
	virtual int getHeight()
	{
		int ld = maxdepleft();
		int rd = maxdepright();
		if(nodes == 0)
		return 0;
		if(rd >= ld)
		return rd;		
		else return ld;
	}
	
	virtual int maxdepright()
	{
		node<Key,Value>* temp;
		temp = root;
		int rd =0;
		while(temp != NULL)
			{
			temp = temp->right;
			rd++;
			} 	
			return rd;
	}

	virtual int maxdepleft()
	{
		node<Key,Value>* temp;
		temp = root;
		int ld =0;
		while(temp != NULL)
			{
			temp = temp->left;
			ld++;
			}	
		return ld;	
	}

	virtual int size()
	{
	return nodes;			
	}

	virtual void print();
	virtual void put(const Key& key, const Value& value);
	virtual node<Key,Value>* newNode(const Key& key, const Value& value);
	virtual node<Key,Value>* insert(node<Key,Value>* root,const Key& key, const Value& value);	
        virtual bool has(const Key& key);
        virtual bool Search(node<Key,Value>* root,const Key& key);
        virtual Value get(const Key& key);

	virtual void print_in_order()
	 {
                         inorder(root);
         }
	virtual void inorder(node<Key,Value>* root);


	virtual void print_pre_order()
	 {
                        preorder(root);
         }
	 virtual void preorder(node<Key,Value>* root);

	virtual void print_post_order()
	 {
                       postorder(root);
         }
	virtual void postorder(node<Key,Value>* root);

	virtual Key minimum();
	virtual Key maximum();
	virtual Key successor(const Key& key);
	virtual node<Key,Value>* getSuccessor( node<Key,Value>* root,const Key& key);
	virtual Key predecessor(const Key& key);
	virtual node<Key,Value>* getpredecessor( node<Key,Value>* root,const Key& key);
	virtual node<Key,Value>* Find(node<Key,Value>* root,const Key& key);
        virtual void remove(const Key& key);
        virtual node<Key,Value>* Delete(node<Key,Value>* root,const Key& key);
	virtual node<Key,Value>* FindMin( node<Key,Value>* root);	
	virtual node<Key,Value>* FindMax(node<Key,Value>* root);
	
	virtual int height(node<Key,Value>* root)
	{
		node<Key,Value>* temp = root ;
		if(temp == NULL)
		 return 0;
		return temp->height;		
	}
	virtual int max(int a,int b)
	{
	return (a>b)? a : b;
	}

	BSTree();
};

template <class Key,class Value>
BSTree<Key,Value> :: BSTree()
{
	root = NULL;
	nodes = 0;	
}

template <class Key,class Value>
void BSTree<Key,Value> :: print()
{
	inorder(root);
}

template <class Key,class Value>
node<Key,Value>* BSTree<Key,Value> :: newNode(const Key& key, const Value& value)
{
	node<Key,Value>* temp = new node<Key,Value>();
	temp->key=key ;
	temp->value = value;
	temp->height =1;
	temp->right = NULL;
	temp->left = NULL;
	return temp;
}

template <class Key,class Value>
bool BSTree<Key,Value> :: has(const Key& key)
{
	if(Search(root,key))
	return true;
	else
	return false;
}	

template <class Key,class Value>
bool BSTree<Key,Value> :: Search(node<Key,Value>* root,const Key& key)
{
	node<Key,Value>* temp = root;
	if(temp == NULL)
	return false;

	else if(temp->key == key)
	return true;

	else if(key <=temp->key)
	return Search(temp->left,key);
	
	else
	return Search(temp->right,key);	
}

template <class Key,class Value> 
node<Key,Value>* BSTree<Key,Value> :: insert(node<Key,Value>* root,const Key& key, const Value& value)
{
	if(root == NULL)
	return newNode(key,value);
	
	if(key < root->key)
	root->left = insert(root->left,key,value);
	
	else if(key > root->key)
	root->key = insert(root->right,key,value);

	root->height = max(height(root->left),height(root->right)) +1;
	return root;
}

template <class Key,class Value> 
void BSTree<Key,Value> :: put(const Key& key, const Value& value)
{
	if(!(has(key)))
	{
		root = insert(root,key,value);
		nodes++;	
	}	
	else 
	std :: cout<<"already have a key"<< std :: endl;
}

template <class Key,class Value> 
node<Key,Value>* BSTree<Key,Value> :: Find(node<Key,Value>* root,const Key& key)

{
	node<Key,Value>* temp = root;
	if(temp == NULL)
	return NULL;
	
	else if(key <= temp->key)
	return Find(temp->left,key);

	else 
	return Find(temp->right,key);
}

template <class Key,class Value> 
Value BSTree<Key,Value> :: get(const Key& key)
{
	node<Key,Value>* temp = root;
	temp = Find(temp,key);
	
	if(temp == NULL)
	return "Key is not present";
	
	return temp->value;
}

template <class Key,class Value>
void BSTree<Key,Value> :: inorder(node<Key,Value>* root)
{
	if(root != NULL)
	{
	inorder(root->left);
	std :: cout << root->key << " :: " << root->value << " : " <<height(root) << std :: endl;
	inorder(root->right); 		
	}


}

template <class Key,class Value>
void BSTree<Key,Value> ::  postorder(node<Key,Value>* root)
{
	if(root != NULL)
	{
	postorder(root->left);	
	postorder(root->right);
	std :: cout << root->key << " :: " << root->value << " : " << height(root) << std::endl;
	
	}

}




template <class Key,class Value> 
void BSTree<Key,Value> :: preorder(node<Key,Value>* root);
{
	if(root != NULL)
	{
	std :: cout << root->key << " :: " << root->value << " : " << height(root) << std :: endl;
	preorder(root->left);
	preorder(root->right);
	}

}

template <class Key,class Value>
Key BSTree<Key,Value> :: minimum()
{
	node<Key,Value>* temp = root;
	while(temp->left != NULL)
	{
		temp = temp->left;

	}
	return temp->key;
}

template <class Key,class Value>
Key BSTree<Key,Value> :: maximum()
{
	node<Key,Value>* temp = root;
	
	while(temp->right != NULL)
	{
		temp = temp->right;

	}
	return temp->key;
	
}

template <class Key,class Value>
Key BSTree<Key,Value> ::  successor(const Key& key)
{
	if(has(key))
	{
		node<Key,Value>* temp ;
		temp = getSuccessor(root,key);
		return temp->key;
	}
	else
	return 0;
}

template <class Key,class Value>
node<Key,Value>* BSTree<Key,Value> :: FindMin( node<Key,Value>* root)
{
	node<Key,Value>* temp = root;
	while(temp != NULL)
	temp = temp->left;
	return temp;

}

template <class Key,class Value>
node<Key,Value>* BSTree<Key,Value> :: FindMax( node<Key,Value>* root)
{
	node<Key,Value>* temp = root;
	while(temp != NULL)
	temp = temp->right;
	return temp;

}


template <class Key,class Value>
node<Key,Value>*  BSTree<Key,Value> ::getSuccessor( node<Key,Value>* root,const Key& key)
{
	node<Key,Value>* temp = root;
	node<Key,Value>* current = Find(temp,key);
	if(current == NULL)
	return NULL;
	if(current->right != NULL)
	  return FindMin(current->right);
	else
	{
	node<Key,Value>* successor = NULL;
	node<Key,Value>* ancestor = temp;
	while(ancestor != current)
	{
	if(current->key < ancestor->key)
		{
			successor = ancestor;
			ancester = ancester->left;			
		}
	else
		ancestor = ancestor->right;
	}
	return successor;

	}
}

template <class Key,class Value>
Key BSTree<Key,Value> :: predecessor(const Key& key)
{
	if(has(key))
	{
		node<Key,Value>* temp;
		temp = getpredecessor(root,key);
		return temp->key;	
	}
	else
		return 0; 
}

template <class Key,class Value>
node<Key,Value>* BSTree<Key,Value> :: getpredecessor( node<Key,Value>* root,const Key& key)
{
	node<Key,Value>* temp = root;
	node<Key,Value>* current = Find(temp,key);
	if(current == NULL)
	return NULL;
	if(current->left != NULL)
	  return FindMax(current->left);
	else
	{
	node<Key,Value>* predecessor = NULL;
	node<Key,Value>* ancestor = temp;
	while(ancestor != current)
	{
	if(current->key > ancestor->key)
		{
			predecessor = ancestor;
			ancester = ancester->right;			
		}
	else
		ancestor = ancestor->left;
	}
	return predecessor;

	}
	

}

template<class Key,class Value>
void BSTree<Key,Value> :: remove(const Key& key)
{
	root = Delete(root,key);
	count--;
}

template<class Key,class Value>
node<Key,Value>* BSTree<Key,Value> :: Delete(node<Key,Value>* root,const Key& key)
{
	node<Key,Value>* temp = root;

	if(temp == NULL)
	return temp;

	else if(key < temp->key)
	temp->left = Delete(temp->left,key);

	else if(key > temp->key)
	temp->right = Delete(temp->right,key);
	
	else 
	{		
	   if(temp->left == NULL && temp->right == NULL)
		 { 
	        	 delete temp;
	         	 temp = NULL;
		 }		
	   else if(temp->left == NULL) 
		{
			 node<Key,Value>* temp1 = temp;
			 temp = temp->right;
			 delete temp1;
	        }
	   else if(temp->right == NULL) 
		{
			 node<Key,Value>* temp1 = root;
			 temp = temp->left;
			 delete temp1;
	        }
           else 
		{ 
	         node<Key,Value>* temp1 = FindMin(temp->right);
		 temp->key = temp1->key;
		 temp->right = Delete(temp->right,temp1->key);
	        }
        }
 	return temp;
}



  
