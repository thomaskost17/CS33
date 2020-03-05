#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>

struct arguments
{
    int leonardo_number;
    int label;
};

void  *thread_fn (void* arg);
int leonardo_number(unsigned int N);

int main(int argc, char** argv)
{
    //handle the argument
    int N = atoi(*(argv +1)); //assuming the first argument adter executable is our input
    pthread_t tid1;
    
    struct arguments arg;
    arg.label =0;
    arg.leonardo_number = N;
    thread_fn(&arg);//main thread will just call this boi so have L(N) total threads
    //create first thread
   // pthread_create(&tid1, NULL, thread_fn, &arg);
   // pthread_join(tid1, NULL);

}

void  *thread_fn(void *arg)
{
    struct arguments*  x = (struct arguments*)arg;
    if (x -> leonardo_number == 0 || x->leonardo_number == 1) // leafs
    {
        printf("[%d]\n", x->label);
    }
    else
    {
        //print label
        printf("(%d\n",x->label);
        //if not a leaf declare two children threads
        pthread_t tid_left, tid_right;
        //left thread
        //create new argument
        struct arguments left = *x;
        left.leonardo_number--;
        left.label ++;
      
        pthread_create(&tid_left,NULL, thread_fn, &left );
        pthread_join(tid_left, NULL);
        //right thread
        struct arguments right = *x;
        right.leonardo_number -= 2;
        right.label += 1 + leonardo_number(left.leonardo_number);
        pthread_create(&tid_right, NULL, thread_fn, &right);
        pthread_join(tid_right, NULL);

        printf("%d)\n", x->label);
    }
  //printf("%d", x->leonardo_number);
}

int leonardo_number(unsigned int N)
{
    if (N ==0 || N == 1)
        return 1;
    else
    {
        return 1 + leonardo_number(N-1) +leonardo_number(N-2);
    }

}