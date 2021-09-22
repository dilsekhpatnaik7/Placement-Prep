#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

/*
INORDER TRAVERSAL USING RECURSION
left--->root--->right
*/
void inOrderRec(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrderRec(root->left);
    cout << root->data << " ";
    inOrderRec(root->right);
}

/*
INORDER TRAVERSAL USING ITERATION
*/
void inOrderItr(Node *root)
{
    Node *curr = root;
    stack<Node*> tempS;
    while(curr!=NULL || tempS.empty()==false){
        while (curr != NULL)
        {
            tempS.push(curr);
            curr = curr->left;
        }
        curr = tempS.top();
        tempS.pop();
        cout<<curr->data<<" ";
        curr = curr->right;
    }
}

/*
PREORDER TRAVERSAL USING RECURSION
root--->left--->right
*/
void preOrderRec(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrderRec(root->left);
    preOrderRec(root->right);
}

/*
PREORDER TRAVERSAL USING ITERATION
*/
void preOrderItr(Node *root){
    if(root ==NULL)
        return;

    Node *curr = root;
    stack<Node *> tempS;
    tempS.push(curr);

    while(tempS.empty() == false){

        //pop the top item and print it
        cout<<tempS.top()->data<<" ";
        tempS.pop();

        if(curr->left!=NULL)
            tempS.push(curr->right)
    }
}

/*
POSTORDER TRAVERSAL USING RECURSION
left--->right--->root
*/
void postOrderRec(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrderRec(root->left);
    postOrderRec(root->right);
    cout << root->data << " ";
}

/*
INORDER TRAVERSAL USING ITERATION
*/


/*
LEVEL ORDER TRAVERSAL USING ITERATION
*/
void levelOrder(Node *root){
    if(root == NULL){
        return;
    }else{
        queue<Node *> q;
        Node *curr = root;
        q.push(curr);
        while (!q.empty())
        {
            Node *ptr = q.front();
            cout<<ptr->data<<" ";
            q.pop();

            if(ptr->left!=NULL)
                q.push(ptr->left);

            if(ptr->right!=NULL)
                q.push(ptr->right);
        }
    }
}

int main()
{
    /*
                     10
                   /   \
                20      30
               / \     /  \
            40   50   60   70
    */
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);

    inOrderRec(root);
    cout << endl;
    inOrderItr(root);
    cout << endl;
    preOrderRec(root);
    cout << endl;
    postOrderRec(root);
    cout << endl;
    levelOrder(root);
    cout<<endl;

    return 0;
}