Queue using Array:
// Online C compiler to run C program online
#include &lt;stdio.h&gt;
#include&lt;stdlib.h&gt;
#define n 5
int q[n];
int front=-1;
int rear=-1;
void enqueue();
void dequeue();
void peek();
void display();
void enqueue()
{
int data;
printf(&quot;Enter the data\n&quot;);
scanf(&quot;%d&quot;,&amp;data);
if(rear==n-1)
{
printf(&quot;Queue overflow\n&quot;);
}
else if(front==-1 &amp;&amp; rear==-1)
{
front=rear=0;
q[rear]=data;
}
else
{
rear++;
q[rear]=data;
}
}
void peek()
{
if(front==rear==-1)
{
printf(&quot;Queue unerflow\n&quot;);
}
else
{
printf(&quot;The 1st element in the queue is %d&quot;,q[front]);

}
}
void dequeue()
{
if(front==rear==-1)
{
printf(&quot;Queue underflow\n&quot;);
}
else if(front==rear)
{
front=rear=-1;
}
else
{
printf(&quot;The deleted element is %d&quot;,q[front]);
front++;
}
}
void display()
{
printf(&quot;The elements in the queue are &quot;);
for(int i=front;i&lt;=rear;i++)
{
printf(&quot;%d\t&quot;,q[i]);
}
}
int main() {
// Write C code here
int ch;
do
{
printf(&quot;\nEnter choice:\n1.Enqueue\n2.Dequue\n3.Peek\n4.Display\n&quot;);
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
return 0;
}
---------------------------------------------------------------------
---------------------------------------------------------------------
Queue using linked list
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
nn-&gt;next=NULL;
if(*rear==NULL)
{
*rear=nn;
front=nn;
}
else
{
(*rear)-&gt;next=nn;
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
else
{
*front=(*front)-&gt;next;
printf(&quot;\nThe deleted element is %d&quot;,temp-&gt;data);
free(temp);
}
}
void display(struct node *front)
{
struct node *temp=front;
if(front==NULL)
printf(&quot;Queue underflow\n&quot;);
else
{
printf(&quot;\nThe elements in the queue are \t&quot;);
while(temp!=NULL)
{
printf(&quot;%d-&gt;&quot;,temp-&gt;data);
temp=temp-&gt;next;
}
printf(&quot;NULL&quot;);
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
