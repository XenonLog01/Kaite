#ifndef INTERPRETER_H_
#define INTERPRETER_H_

#include "lexer.h"
#include "parser.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Variable
{
    const char* id;
    String str;
}Variable;

typedef struct Variable_List
{
    size_t heap;
    size_t size;
    Variable* content;
}Variable_List;

void Variable_List_Init(Variable_List* list);
void Variable_List_Free(Variable_List* list);
void Variable_List_Push(Variable_List* list, Variable var);
void Variable_List_Remove(Variable_List* list, int index);
bool Variable_List_Exist(Variable_List* list, const char* id);
size_t Variable_List_Find(Variable_List* list, const char* id);

void Initialize_Global();

Variable* Get_Variable(Variable_List* variables, const char* variable);
Variable_List* Get_Variable_List(Variable_List* variables, const char* variable);

void Interpret_Conditional(Expr expr);
void Interpret_Set(Variable_List* variables, Expr expr);
void Interpret_Function(Variable_List* variables, Expr expr);
void Interpret_Program(Expr program);

#endif // INTERPRETER_H_