/*function declartion*/
#ifndef INTERCEPTION_H
#define INTERCEPTION_H

#define malloc(n) my_malloc(n)
void* my_malloc(int size);

#endif

