#include <stdio.h>
#include<iostream>



struct node
{
int data;
struct node * left;
struct node * right;
};

int div1(int match[],int s,int e,int matchto[],int ms,int me)
{ int max=-1;
for(int i=s;i<=e;i++)
{
    for(int j=ms;j<=me;j++)
    {
            if(match[i]==matchto[j])
            {
             if(j>max)
                    max=j;

            break;


            }
    }

}
return max;


}
int pos1(int a[],int ele,int s,int e)
{
    for(int i=s;i<=e;i++)
        if(a[i]==ele)
        return i;
    return -1;


}

struct node * build_tree(int inorder[],int is,int ie,int preorder[],int ps,int pe)
{

   struct node * temp=new node;
    temp->data=preorder[ps];
    if(ie==is)
    {
        temp->left=NULL;
        temp->right=NULL;

    }
    else
    {

        int pos=pos1(inorder,preorder[ps],is,ie);
        printf(" pos returned is %d for %d \n",pos,preorder[ps]);
        if(pos==is)
        {
            temp->left=NULL;
            temp->right=build_tree(inorder,is+1,ie,preorder,ps+1,pe);
        }
        else if(pos==ie)
        {
            temp->right=NULL;
            temp->left=build_tree(inorder,is,ie-1,preorder,ps+1,pe);

        }
        else
        {

            int div=div1(inorder,is,pos-1,preorder,ps+1,pe);
            printf(" div returned is %d for \n",div);

            temp->left=build_tree(inorder,is,pos-1,preorder,ps+1,div);
            temp->right=build_tree(inorder,pos+1,ie,preorder,div+1,pe);
        }



    }




}



void tree(struct node * root)
{
    if(root)
    {
        printf("%d ",root->data);
        tree(root->left);
        tree(root->right);
    }
}


int main()
{
int in[]={4,2,5,1,6,3};
int pre[]={1,2,4,5,3,6};

struct node * root=build_tree(in,0,5,pre,0,5);

tree(root);
return 1;
}
