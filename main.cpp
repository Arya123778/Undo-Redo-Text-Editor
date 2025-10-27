#include "editor.h"
int main(){
    TextEditor editor;
    initEditor(editor);

    int choice;
    char input[TEXT_SIZE];
    int count;

    cout<<"----Undo/Redo Text Editor----\n";

    do{
        cout<<"\n1. Insert Text\n2.Delete Text\n3.Undo\n4.Redo\n5.Show Text\n6.Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        cin.ignore();

        switch(choice){
            case 1:
            cout<<"Enter text to insert: ";
            cin.getline(input,TEXT_SIZE);
            insertText(editor,input);
            break;

            case 2:
            cout<<"Enter number of characters to delete: ";
            cin>>count;
            deleteText(editor,count);
            break;

            case 3:
            undo(editor);
            break;

            case 4:
            redo(editor);
            break;

            case 5:
            showText(editor);
            break;

            case 6:
            cout<<"Exiting editor.\n";
            break;

            default:
            cout<<"Invalid choice!\n";
        }
    } while (choice!=0);
    return 0;
}