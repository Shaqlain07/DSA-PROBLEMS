//Function to push an integer into the stack1.
void twoStacks :: push1(int x)
{
    top1++;//iterating forward to push in array
    arr[top1]=x;
}
   
//Function to push an integer into the stack2.
void twoStacks ::push2(int x)
{
    top2--;//iterating backward to put element in array from stack 2
    arr[top2]=x;
}
   
//Function to remove an element from top of the stack1.
int twoStacks ::pop1()
{
    if(top1==-1) {//stack is empty
        return -1;
    }
    return arr[top1--];//decrementing pointer and returning the value
}

//Function to remove an element from top of the stack2.
int twoStacks :: pop2()
{
    if(top2==size) {
        return -1;
    }
    return arr[top2++];
}
