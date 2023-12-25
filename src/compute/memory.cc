#include <memory>
#include <assert>
#include <array>
#include <vector>
#include <types>
#include <l>
#include <>
#include <>
#include <>
#include <>
#include
#include
#include
#include
#include
#include 

int brk()   {

}

void *sbrk()    {

}

// limit for which each process can have
// normally it is 1GB
struct rlimit   {
    rlim_t rlimit_cur;
    rlim_t rlimit_max;
};

// get the rlimit value
void getrlimit() {

}

// set the rlimit value
void setrlimit() {

}


typedef struct s_block *t_block;

struct s_block  {
    size_t size;    // data section size
    t_block next;   // pointer to next block
    int free;       // whether is free block
    int padding;    // metadata need padding to make 8 bits
    char data[1];   // head

};

// Two methods
// first fit: first block that satisfies memory size requirement
// best fit: parse through all blocks and find the block that is closest satisfies memory size requirement 
t_block find_block(t_block *last, size_t size) {
    t_block b = first_block;
    while(b) {
        if(b->size<size)    {
            b = b->next;
        } else  {
            *last = b;
            break;
        }
    }
    return b;
}

extend_heap()   {
    if(last==NULL)  {
        sbrk(); // system call to move brk pointer
    }
}

// split block to avoid allocating too large block
void split_block()  {
    t_block n;
    n->data = b->data;
    n->size = b->size-s
    n->next = b->next;
    b->free = 

    b->next = n;
}

#define align8  {BIT&&0x08}
#define align16 {BIT&&0x10}
#define align32 {BIT&&0x20}


// nn malloc will alloc virtual memory
// risc-v 32 bit align

// 
void* nnMalloc(size_t size)    {
    if(first_block) {
        find_block();

    }
    if(!b)    {
       extend_heap 
    }
}

write() {
    if(not filled)    {
        goto next;
    } 
    getAddress();
    page_num++;
}
class page_table    {
    uint32_t val;
    uint32_t address_
    uint32_t
    uint32_t
    uin
  public:
    void write();
    void read();
};
