#include <iostream>
#include <string>
using namespace std;
struct task
{
    string name;
    bool completed;
    task *link;//linked list
};

class todolist
{
    task *first;
    task *last;
    public:
    todolist()
    {
        first=NULL;
        last=NULL;
    }
    void add(string x)
    {
        task *t=new task;//create a new task
        t->name=x;
        t->completed=0;//initially not completed
        t->link=NULL;
        if(first==NULL)
        first=t;
        else
        {
            last->link=t;
        }
        last=t;
        cout<<"task has been added!!"<<endl;
    }
   void veiw()
   {
       if(first==NULL)
       cout<<"List is empty!!"<<endl;
       task *temp=first;
       while(temp!=NULL)
       {
           cout<<temp->name<<" Completed status: "<<temp->completed<<endl;
           temp=temp->link;
       }
   }
   
   bool mark(string x)//mark successful or not
   {
       if(first==NULL)
       return 0;
       task *temp=first;
       while(temp->name!=x)
       {
           temp=temp->link;//move to loc of task
           if(temp==NULL)
           return 0;//task doesnt exist
       }
       temp->completed=1;//change completed status to done
       return 1;
   }
   
   bool removet(string x)
   { 
       if(first==NULL)
       {
       return 0;
       }
       task *temp=first;
       if(temp->name==x)
       {
       first=temp->link;//handle case when the task is first in list
       return 1;
       }
       task *succ=temp->link;
       while(succ->name!=x)
       {
           temp=temp->link;//move to loc of task-1
           succ=succ->link;
           if(succ==NULL)
           return 0;//task doesnt exist
       }
       temp->link=succ->link;
       delete succ;
       return 1;//task removed
   }
};

int main()
{
    
    int n,y=1;
    todolist d;
    while(y)
    {
    cout<<"Wht operation would u like to perform in the to-do-list";
    cout<<"Pls select the correcponding number for the same:";
    cout<<"(1)add task to list"<<endl<<"(2)veiw tasks"<<endl<<"(3)mark as completed"<<endl<<"(4)remove task"<<endl;
    cin>>n;
    cin.ignore();
    switch(n)
    {
        case 1:
        {
        string x;
        cout<<"Enter the task name:"<<endl;
        getline(cin,x);
        d.add(x);
        break;
        }
        case 2:
        {
        d.veiw();
        break;
        }
        case 3:
        {
        string x;
        cout<<"Enter the task to be marked completed:"<<endl;
        getline(cin,x);
        bool b=d.mark(x);
        if(b)
        cout<<"The task has been marked successfully!!"<<endl;
        else 
        cout<<"The task couldnt be marked due to some error!!"<<endl;
        break;
        }
        case 4:
        {
        string x;
        cout<<"Enter the task to be removed:"<<endl;
        getline(cin,x);
        bool b=d.removet(x);
        if(b)
        cout<<"The task has been removed successfully!!"<<endl;
        else cout<<"The task couldnt be removed due to some error!!"<<endl;
        break;
        }
        default:
        {
        cout<<"Enter a valid operation!!"<<endl;
        break;
        }
    }
    cout<<"Would u like to make any other changes??>>>>if yes press 1 else 0"<<endl;
    cin>>y;
    }
}
