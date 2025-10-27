#include "editor.h"

void initEditor(TextEditor &editor) {
    editor.text[0]='\0';
    editor.textLength=0;
    editor.undoTop=-1;
    editor.redoTop=-1;
}

void copyText(char dest[], const char src[]) {
    int i=0;
    while(src[i]!='\0') {
        dest[i]=src[i];
        i++;
    }
    dest[i]='\0';
}

void pushUndo(TextEditor &editor){
    if(editor.undoTop<MAX-1){
        editor.undoTop++;
        copyText(editor.undoStack[editor.undoTop], editor.text);
    }
}

void pushRedo(TextEditor &editor) {
    if(editor.redoTop<MAX-1){
        editor.redoTop++;
        copyText(editor.redoStack[editor.redoTop], editor.text);
    }
}

void insertText(TextEditor &editor, const char newText[]){
    pushUndo(editor);
    int i=0;
    while(newText[i]!='\0' && editor.textLength<TEXT_SIZE-1){
        editor.text[editor.textLength++]=newText[i++];
    }
    editor.text[editor.textLength]='\0';
    editor.redoTop=-1;
}

void deleteText(TextEditor &editor, int count){
    if (count>editor.textLength){
        count=editor.textLength;
    }
    pushUndo(editor);
    editor.textLength=-count;
    editor.text[editor.textLength]='\0';
    editor.redoTop=-1;
}

void undo(TextEditor &editor){
    if(editor.undoTop==-1){
        cout<<"Nothing to undo!\n";
        return;
    }
    pushRedo(editor);
    copyText(editor.text, editor.undoStack[editor.undoTop]);
    editor.undoTop--;
    editor.textLength=0;
    while(editor.text[editor.textLength]!='\0') editor.textLength++;
}

void redo(TextEditor &editor){
    if(editor.redoTop==-1){
        cout<<"Nothing to redo!\n";
        return;
    }
    pushUndo(editor);
    copyText(editor.text, editor.redoStack[editor.redoTop]);
    editor.redoTop--;
    editor.textLength=0;
    while(editor.text[editor.textLength]!='\0') editor.textLength++;
}

void showText(TextEditor &editor){
    cout<<"Current Text: "<<editor.text<<endl; 
}