#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct Task{
    string description;
    bool completed;
};
class ToDoList{
    private:
        vector<Task>tasks;
    public:
        void addTask(const string& description){
            tasks.push_back({description, false});
            cout<<"Task added"<<endl;
        }
        void viewTasks(){
            if(tasks.empty()){
                cout<<"No task to display"<<endl;
                return;
            }
            for(size_t i = 0; i < tasks.size(); i++){
                cout << i + 1 << ". " << tasks[i].description << " [ " << (tasks[i].completed ? "Done" : "Pending") << " ]" << endl;
            }
        }
        void markTaskCompleted(int index){
            if(index < 1 || index > static_cast<int>(tasks.size())){
                cout<<"Invalid task number"<<endl;
                return;
            }
            tasks[static_cast<vector<Task>::size_type>(index - 1)].completed = true;
            cout<<"Task marked as completed"<<endl;
        }
        void removeTask(int index){
            if(index < 1 || index > static_cast<int>(tasks.size())){
                cout<<"Invalid task number"<<endl;
                return;
            }
            tasks.erase(tasks.begin() + index - 1);
            cout<<"Task removed"<<endl;
        }
};
int main(){
    ToDoList todo;
    string description;
    int choice;
    while(true){
        cout<<"1. Add task"<<endl;
        cout<<"2. View tasks"<<endl;
        cout<<"3. Mark task as completed"<<endl;
        cout<<"4. Remove task"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
            cout<<"Enter task description: "<<endl;
            cin.ignore();
            getline(cin, description);
            todo.addTask(description);
            break;

            case 2:
            todo.viewTasks();
            break;

            case 3:
            int index;
            cout<<"Enter tasks number to mark as completed: ";
            cin>>index;
            todo.markTaskCompleted(index);
            break;

            case 4:
            int num;
            cout<<"Enter task number to remove: "<<endl;
            cin>>num;
            todo.removeTask(num);
            break;

            case 5:
            cout<<"Exiting..."<<endl;
            return 0;

            default:
            cout<<"Invalid choice"<<endl;
        }  
    }
    return 0;
}