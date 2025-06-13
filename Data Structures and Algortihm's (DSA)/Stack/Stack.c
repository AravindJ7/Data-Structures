Stack using array:
// Online C compiler to run C program online
#include &lt;stdio.h&gt;
#define n 5
int stack[n];
int top=-1;
void push()
{
int data;
printf(&quot;Enter the elements\n&quot;);
scanf(&quot;%d&quot;,&amp;data);
if(top==n-1)
{
printf(&quot;Stack overflow\n&quot;);
}
else
{
top++;
stack[top]=data;
}
}
int pop()
{
int item;
if(top==-1)
{
printf(&quot;Stack underflow\n&quot;);
}
else
{
item=stack[top];
top--;
}
return item;
}
void peek()
{
printf(&quot;The top most element in the stack is %d\n&quot;,stack[top]);
}
void display()
{
printf(&quot;The elements in the stack are \t&quot;);
for(int i=top;i&gt;=0;i--)
{
printf(&quot;%d\t&quot;,stack[i]);
}
}

int main() {
int ch;
do
{
printf(&quot;\nEnter choice:\n1.Push\n2.Pop\n3.Peek\n4.Display\n&quot;);
scanf(&quot;%d&quot;,&amp;ch);
switch(ch)
{
case 1:
push();
break;
case 2:
int deleted=pop();
printf(&quot;The deleted element is %d&quot;,deleted);
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
--------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------
Stack using linked list:
#include&lt;stdio.h&gt;
#include&lt;stdlib.h&gt;
struct node
{
int data;
struct node *next;
};
void push(struct node **,int);
void pop(struct node **);
void peek(struct node**);
void display(struct node *);
void push(struct node **top,int data)
{
struct node *nn=(struct node*)malloc(sizeof(struct node));
nn-&gt;data=data;
nn-&gt;next=*top;

*top=nn;
}
void peek(struct node **top)
{
if(*top==NULL)
printf(&quot;\nStack Underflow\n&quot;);
else
printf(&quot;\nTop element is %d&quot;,(*top)-&gt;data);
}
void pop(struct node **top)
{
struct node *temp=*top;
*top=(*top)-&gt;next;
printf(&quot;\nThe popped element is %d&quot;,temp-&gt;data);
free(temp);
}
void display(struct node *top)
{
struct node *temp=top;
printf(&quot;\nThe elements in the stack are \t&quot;);
while(temp!=NULL)
{
printf(&quot;%d-&gt;&quot;,temp-&gt;data);
temp=temp-&gt;next;
}
printf(&quot;NULL&quot;);
}
int main()
{
struct node *top=NULL;
int n,data;
printf(&quot;Enter the no.of elements in the stack\n&quot;);
scanf(&quot;%d&quot;,&amp;n);
printf(&quot;Enter the elements\n&quot;);
for(int i=0;i&lt;n;i++)
{
scanf(&quot;%d&quot;,&amp;data);
push(&amp;top,data);
}
display(top);
peek(&amp;top);
pop(&amp;top);
display(top);
peek(&amp;top);
return 0;
}