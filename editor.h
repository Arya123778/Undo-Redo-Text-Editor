#ifndef EDITOR_H
#define EDITOR_H

#include<iostream>
using namespace std;

#define MAX 100
#define TEXT_SIZE 200

struct TextEditor {
    char text[TEXT_SIZE];
    char undoStack[MAX][TEXT_SIZE];
    char redoStack[MAX][TEXT_SIZE];
    int undoTop;
    int redoTop;
    int textLength;
};

void initEditor(TextEditor &editor);
void insertText(TextEditor &editor,const char newText[]);
void deleteText(TextEditor &editor,int count);
void undo(TextEditor &editor);
void redo(TextEditor &editor);
void showText(TextEditor &editor);

void copyText(char dest[], const char src[]);
void pushUndo(TextEditor &editor);
void pushRedo(TextEditor &editor);

#endif // EDITOR_H
