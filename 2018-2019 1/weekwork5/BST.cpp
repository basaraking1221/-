#include <iostream>
using namespace std;
int temp;
int m,n;
struct BiTree{
    int value;
    BiTree *left,*right;
};//left is smaller and right is greater
BiTree *Head;
BiTree *t;
void insert(int num,BiTree *head)
{
    if (head->value > num)
        if (head->left != NULL) insert(num,head->left);
        else
        {
            t = head->left = new BiTree;
            t->value = num;t->left = t->right = NULL;
        }
    else if (head->right != NULL) insert(num,head->right);
        else
        {
            t = head->right = new BiTree;
            t->value = num;t->left = t->right = NULL;
        }
}
void cldata(BiTree *Head)
{
    if (Head->left != NULL) cldata(Head->left);
    if (Head->right != NULL) cldata(Head->right);
    delete Head;
}
int main(){
    
    scanf("%d%d",&n,&m);
    scanf("%d",&temp);
    Head = new BiTree;Head->value = temp;Head->left = Head->right = NULL;
    for (int i = 1;i < n;i++)
    {
       scanf("%d",&temp);
       insert(temp,Head);
    }
    cldata(Head);
}