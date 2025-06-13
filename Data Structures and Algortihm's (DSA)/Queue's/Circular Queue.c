Circular queue using array:
// Online C compiler to run C program online
#include &lt;stdio.h&gt;
#define n 5
int cq[n];
int rear=-1;
int front=-1;
void enqueue()
{
int data;
printf(&quot;Enter the element:\t&quot;);
scanf(&quot;%d&quot;,&amp;data);
if((rear+1)%n==front)
{
printf(&quot;Queue overflow\n&quot;);
}
else if(rear==-1 &amp;&amp; front==-1)
{
rear=front=0;
cq[rear]=data;
}
else
{
rear=(rear+1)%n;
cq[rear]=data;
}
}
void dequeue()
{
if(front==-1 &amp;&amp; rear==-1)
{
printf(&quot;\nQueue underflow\n&quot;);
}
else if(front==rear)
{
printf(&quot;\nThe deleted element is %d\t&quot;,cq[front]);
front=rear=-1;
}
else
{
printf(&quot;\nThe deleted element is %d\t&quot;,cq[front]);
front=(front+1)%n;
}
}

void peek()
{
if(front==-1 &amp;&amp; rear==-1)
{
printf(&quot;\nQueue is empty\n&quot;);
}
else
{
printf(&quot;\nThe 1st element is %d\t&quot;,cq[front]);
}
}
void display()
{
int i=front;
printf(&quot;\nThe elements in the queue are \t&quot;);
while(i!=rear)
{
printf(&quot;%d&quot;,cq[i]);
i=(i+1)%n;
}
printf(&quot;%d&quot;,cq[rear]);
}
int main() {
// Write C code here
int ch;
do
{
printf(&quot;\nEnter choice:\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n&quot;);
scanf(&quot;%d&quot;,&amp;ch);
switch(ch)
{
case 1:
enqueue();
break;
case 2:
dequeue();
break;
case 3:
peek();
break;
case 4:
display();
break;
default:
printf(&quot;Invalid choice\n&quot;);
}
}while(ch!=0);

return 0;
}
---------------------------------------------------
---------------------------------------------------
Circular queue using linked list
#include&lt;stdio.h&gt;
#include&lt;stdlib.h&gt;
struct node
{
int data;
struct node *next;
};
struct node *rear=NULL;
struct node *front=NULL;
void enqueue(struct node **,int);
void dequeue(struct node **);
void peek(struct node**);
void display(struct node *);
void enqueue(struct node **rear,int data)
{
struct node *nn=(struct node*)malloc(sizeof(struct node));
nn-&gt;data=data;
if(*rear==NULL)
{
*rear=nn;
front=nn;
nn-&gt;next=front;
}
else
{
(*rear)-&gt;next=nn;
nn-&gt;next=front;
*rear=nn;
}
}
void peek(struct node **front)
{
if(*front==NULL)
printf(&quot;\nQueue Underflow\n&quot;);
else
printf(&quot;\n1st element is %d&quot;,(*front)-&gt;data);
}
void dequeue(struct node **front)
{

struct node *temp=*front;
if(*front==NULL)
{
printf(&quot;\nQueue underflow\n&quot;);
}
else if(*front==rear)
{
printf(&quot;\nThe deleted element is %d&quot;,temp-&gt;data);
*front=rear=NULL;
free(temp);
}
else
{
*front=(*front)-&gt;next;
rear-&gt;next=*front;
printf(&quot;\nThe deleted element is %d&quot;,temp-&gt;data);
free(temp);
}
}
void display(struct node *front)
{
struct node *temp=front;
if(front==NULL)
printf(&quot;\nQueue underflow\n&quot;);
else
{
printf(&quot;\nThe elements in the queue are \t&quot;);
while(temp-&gt;next!=front)
{
printf(&quot;%d-&gt;&quot;,temp-&gt;data);
temp=temp-&gt;next;
}
printf(&quot;%d&quot;,temp-&gt;data);
}
}
int main()
{
int n,data;
printf(&quot;Enter the no.of elements in the queue\n&quot;);
scanf(&quot;%d&quot;,&amp;n);
printf(&quot;Enter the elements\n&quot;);
for(int i=0;i&lt;n;i++)
{
scanf(&quot;%d&quot;,&amp;data);
enqueue(&amp;rear,data);
}
display(front);

peek(&amp;front);
dequeue(&amp;front);
display(front);
peek(&amp;front);
return 0;
}
