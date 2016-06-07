//
//  main.cpp
//  jinzhi
//
//  Created by jinzhi liu on 15/9/24.
//  Copyright © 2015年 jinzhi liu. All rights reserved.
//

#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

struct TreeLinkNode {
      int val;
      TreeLinkNode *left, *right, *next;
      TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
     };

void connect(TreeLinkNode *root)
{
    if(root != NULL)
    {
    int parent_size = 1;
    int children_size = 0;
    queue<TreeLinkNode*> store;
    TreeLinkNode *temp;
    store.push(root);
    do
    {
        temp = store.front();
        store.pop();
        if(temp->left != NULL)
        {
            store.push(temp->left);
            children_size++;
        }
        if(temp->right != NULL)
        {
            store.push(temp->right);
            children_size++;
        }
        parent_size--;
        if(parent_size == 0&&children_size != 0)
        {
            parent_size = children_size;
            children_size = 0;
            TreeLinkNode* temp2 = store.front();
            queue<TreeLinkNode*> tem;
            tem.push(temp2);
            while(!store.empty())
            {
                TreeLinkNode* temp3;
                if(!store.empty())
                {
                   temp3 = store.front();
                   store.pop();
                }
                temp2->next = temp3;
                tem.push(temp2);
                temp2 = temp3;
            }
            store = tem;
            while(!tem.empty())
                tem.pop();
        }
    }while(!store.empty());
    }
}
int main()
{
    
    return 0;
}
