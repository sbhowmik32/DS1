#include<stdio.h>
#include<stdlib.h>

struct node
{
    int num;
    char ch;
    struct node *next;
};

int createNodeList(int n)
{
    struct node *Node =(struct node*)malloc(sizeof(struct node));
    struct node *nextNode, *temp;
    if(Node==NULL)
        {
            return;
        }
    else
        {
            Node->num=1;
            Node->next=NULL;
            temp=Node;
            int i;
            for (i=2; i<=n; i++)
                {
                    nextNode=(struct node*)malloc(sizeof(struct node));
                    if(nextNode== NULL)
                        {
                            return;
                        }
                    else
                        {
                            nextNode->num = i;
                            nextNode->next=NULL;
                            temp->next=nextNode;
                            temp=temp->next;
                        }
                }
        }

    return Node;
}

void print(struct node *Node)
{
    while (Node!=NULL)
        {
            printf("%d ",Node->num);
            Node=Node->next;
        }
    printf("\n");
}


struct node* deleteFirstNode(struct node *temp)
{
    if(temp == NULL)
        {
            return temp;
        }
    temp = temp->next;

    return temp;
}

struct  node* deleteLast(struct node *temp)
{
    if (temp==NULL)
        printf("empty");
    //temp = temp->next;
    else if (temp->next == NULL)
        {

            free(temp);
            temp = NULL;
        }
    else
        {
            struct node *tem = temp;
            struct node *tem2 = temp;

            while(tem->next !=NULL)
                {
                    tem2 = tem;
                    tem = tem->next;
                }

            tem2->next = NULL;
            free(tem);
            tem = NULL;
        }
    return temp;


}



struct node* removeLast(struct node* temp)
{
    if(temp == NULL)
        {
            return temp;
        }
    struct node *cursor = temp;
    struct node *previousOfLast = NULL;
    while(temp->next != NULL)
        {
            previousOfLast = temp;
            temp = temp->next;
        }
    previousOfLast->next = NULL;
    return cursor;
}
struct node* deleteNode(struct node **head_ref, int pos)
{
    if (*head_ref == NULL)
        {
            return NULL;
        }
    //temp to store head
    struct node* temp = *head_ref;
    //Delete head node
    if (pos == 0)
        {
            *head_ref = temp->next;
            free(temp);
            return *head_ref;
        }
    //store previous of to be deleted node
    int i;
    for (i=0; temp!=NULL && i<pos-1; i++)
        {
            temp = temp->next;
        }
    if (temp == NULL || temp->next == NULL)
        {
            return;
        }
    //delete node at pos (next of pos-1)
    struct node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
}




void done(struct node *Node)
{
    while (Node!=NULL)
        {
            printf("%d ",Node->num);
            Node=Node->next;
        }
    printf("\n");
}

int main()
{
    int a = 10;
    int *b = &a;
    int n, i,j;
    scanf("%d",&n);
    struct node *Node = createNodeList(n);
    //struct node *head =(struct node*)malloc(sizeof(struct node));
    print(Node);
    struct node* withoutFirst= deleteFirstNode(Node);
    print(withoutFirst);
    print(Node);
    //head =NULL;
    struct node* nodewithoutlast = removeLast(Node);
    print(nodewithoutlast);
    print(Node);

    int m;
    printf("enter position\n");
    scanf("%d",&m);
    struct node* nthdelete = deleteNode(&Node,m);
    print(nthdelete);
    print(Node);
    return 0;
}



