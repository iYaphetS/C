#include "DynamicArray.h"

typedef void * seqStack;
typedef DynamicArray Stack;

seqStack * init_SeqStack();

void push_seqStack(seqStack *stack, void *data);

void pop_seqStack(seqStack *stack);

void* top_seqStack(seqStack *stack);

int size_seqStack(seqStack *stack);

void destory_seqStack(seqStack *stack);