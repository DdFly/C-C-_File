#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define PROCESS_NAME_LEN 32   /*进程名长度*/
#define MIN_SLICE    10             /*最小碎片的大小*/
#define DEFAULT_MEM_SIZE 1024     /*内存大小*/
#define DEFAULT_MEM_START 0       /*起始位置*/
/* 内存分配算法 */
#define MA_FF 1
#define MA_BF 2
#define MA_WF 3
int mem_size=DEFAULT_MEM_SIZE; /*内存大小*/
int ma_algorithm = MA_FF;           /*当前分配算法*/
static int pid = 0;                                      /*初始pid*/
int flag = 0;                             /*设置内存大小标志*/
struct free_block_type{
    int size;
    int start_addr;
    struct free_block_type *next;
};
struct free_block_type *free_block;
struct allocated_block{
    int pid;    int size;
    int start_addr;
    char process_name[PROCESS_NAME_LEN];
    struct allocated_block *next;
};
struct allocated_block *allocated_block_head = NULL;
struct free_block_type* init_free_block(int mem_size);

void display_menu(){
    printf("\n");
    printf("1 - Set memory size (default=%d)\n", DEFAULT_MEM_SIZE);
    printf("2 - Select memory allocation algorithm\n");
    printf("3 - New process \n");
    printf("4 - Terminate a process \n");
    printf("5 - Display memory usage \n");
    printf("0 - Exit\n");
}


struct free_block_type* init_free_block(int mem_size){
    struct free_block_type *fb;

    fb=(struct free_block_type *)malloc(sizeof(struct free_block_type));
    if(fb==NULL){
        printf("No mem\n");
        return NULL;
        }
    fb->size = mem_size;
    fb->start_addr = DEFAULT_MEM_START;
    fb->next = NULL;
    return fb;
}



int set_mem_size(){
    int size;
    if(flag!=0){  //防止重复设置
        printf("Cannot set memory size again\n");
        return 0;
    }
    printf("Total memory size =");
    scanf("%d", &size);
    if(size>0) {
        mem_size = size;
        free_block->size = mem_size;
    }
    flag=1;  return 1;
}



void rearrange_FF(){
    //请自行补充
    struct free_block_type *position, *min, *current;
    int size;
    int start_addr;
    printf("Rearrange free blocks for FF \n\n");
    position = free_block;

    //空闲块按地址顺序进行简单选择排序
    while (position != NULL) {
    min = position;
                current = position->next;

                while(current != NULL){
        if( current->start_addr < min->start_addr) {
                                         min = current;
                                }
                    current = current->next;
                }

                size = position->size;
                position->size = min->size;
                min->size = size;
                start_addr = position->start_addr;
                position->start_addr = min->start_addr;
                min->start_addr = start_addr;

                position = position->next;
     }
}
/*按BF算法重新整理内存空闲块链表*/
void rearrange_BF(){
    //请自行补充
    struct free_block_type *position, *min, *current;
    int size;
    int start_addr;
    printf("Rearrange free blocks for BF\n\n");
    position = free_block;

    //空闲块按由小到大进行简单选择排序
    while (position != NULL) {                min = position;
    current = position->next;

                while(current != NULL){
        if( current->size < min->size) {
            min = current;
                                }
        current = current->next;
                }

                size = position->size;
    position->size = min->size;
    min->size = size;

    start_addr = position->start_addr;
    position->start_addr = min->start_addr;
    min->start_addr = start_addr;

    position = position->next;
    }
}

void rearrange_WF(){
    //请自行补充
     struct free_block_type *position, *min, *current;
    int size;
    int start_addr;
    printf("Rearrange free blocks for WF \n\n");
    position = free_block;
    while (position != NULL) {                min = position;
    current = position->next;

        while(current != NULL){
        if( current->size > min->size) {
            min = current;
                                }
        current = current->next;
    }

    size = position->size;
    position->size = min->size;
    min->size = size;

    start_addr = position->start_addr;
    position->start_addr = min->start_addr;
    min->start_addr = start_addr;

    position = position->next;
    }
}
void rearrange(int algorithm){
    switch(algorithm){
        case MA_FF:  rearrange_FF(); break;
        case MA_BF:  rearrange_BF(); break;
        case MA_WF: rearrange_WF(); break;
    }
}

void set_algorithm(){
    int algorithm;
    printf("\t1 - First Fit\n");
    printf("\t2 - Best Fit \n");
    printf("\t3 - Worst Fit \n");
    scanf("%d", &algorithm);
    if(algorithm>=1 && algorithm <=3)
        ma_algorithm=algorithm;
    //按指定算法重新排列空闲区链表
    rearrange(ma_algorithm);
}

void compress(struct allocated_block *ab, int request_size, int sum_size){   

    struct allocated_block *ab1, *ab2;
    struct free_block_type *fb1, *fb2;
    ab1 = allocated_block_head;
    ab1->start_addr = 0;
    ab2 = ab1->next;

    while(ab2 != NULL){
        ab2->start_addr = ab1->start_addr + ab1->size;
        ab1 = ab2;
        ab2 = ab2->next;
    }
    printf("free block was compressed\n\n");
    ab->start_addr = ab1->start_addr + ab1->size;
    
    fb1 = free_block->next;        //紧缩后只有一个空闲块，无需排序
    while(fb1 != NULL){            //其他空闲块释放
        fb2 = fb1->next;
        free(fb1);
        fb1 = fb2;
    }
    printf("free block was set free\n\n");
    free_block->start_addr = ab->start_addr + ab->size;
    free_block->size = sum_size - request_size;
    free_block->next = NULL;

    if( (sum_size >= request_size) && (sum_size - request_size < MIN_SLICE) ) {
        ab->size = sum_size;
        free_block->start_addr = -1;
        free_block->size = 0;
    }
}

int allocate_mem(struct allocated_block *ab){
    struct free_block_type *fbt, *pre;
    int request_size=ab->size;
    int sum_size=0;
    fbt = pre = free_block;
    //根据当前算法在空闲分区链表中搜索合适空闲分区进行分配，分配时注意以下情况：
    // 1. 找到可满足空闲分区且分配后剩余空间足够大，则分割
    // 2. 找到可满足空闲分区且但分配后剩余空间比较小，则一起分配
    // 3. 找不可满足需要的空闲分区但空闲分区之和能满足需要，则采用内存紧缩技术，进行空闲
//分区的合并，然后再分配
    // 4. 在成功分配内存后，应保持空闲分区按照相应算法有序
    // 5. 分配成功则返回1，否则返回-1
    //请自行补充。。。。。
    while(fbt!=NULL){

        if( (fbt->size - request_size) >= MIN_SLICE ){    //分配后空闲空间足够大，则分割
         
            ab->start_addr = fbt->start_addr;
            fbt->size = fbt->size - request_size;
            fbt->start_addr = fbt->start_addr + request_size;
            rearrange(ma_algorithm);
            return 1;
        }
        else if( (fbt->size > request_size) && (fbt->size - request_size < MIN_SLICE) ){    //分割后空闲区成为小碎片，一起分配
             ab->start_addr = fbt->start_addr;
            ab->size = fbt->size;
            if(fbt == free_block) {
                free_block = fbt->next;
                free(fbt);
            }
            else{
                pre->next = fbt->next;
                free(fbt);
            }
            rearrange(ma_algorithm);
            return 1;
        }

        sum_size += fbt->size;
        pre = fbt;
        fbt = fbt->next;
    }
    if(sum_size < request_size)
        return -1;
    else {
        compress(ab,request_size,sum_size);
        return 1;
    }
}
int new_process(){
    struct allocated_block *ab;
    int size;    int ret;
    ab=(struct allocated_block *)malloc(sizeof(struct allocated_block));
    if(!ab) exit(-5);
    ab->next = NULL;
    pid++;
    sprintf(ab->process_name, "PROCESS-%02d", pid);
    ab->pid = pid;
    printf("Memory for %s:", ab->process_name);
    scanf("%d", &size);
    if(size>0) ab->size=size;
    ret = allocate_mem(ab);  /* 从空闲区分配内存，ret==1表示分配ok*/
    if((ret==1) &&(allocated_block_head == NULL)){
        allocated_block_head=ab;
        return 1;
    }
    /*分配成功，将该已分配块的描述插入已分配链表*/
    else if (ret==1) {
        ab->next=allocated_block_head;
        allocated_block_head=ab;
        return 2;
    }
else if(ret==-1){ /*分配不成功*/
        printf("Allocation fail\n");
        free(ab);
        return -1;
    }
    return 3;
}


int free_mem(struct allocated_block *ab){
 int algorithm = ma_algorithm;
    struct free_block_type *fbt, *pre, *work;
    fbt=(struct free_block_type*) malloc(sizeof(struct free_block_type));
    if(!fbt) return -1;
    // 进行可能的合并，基本策略如下
    // 1. 将新释放的结点插入到空闲分区队列末尾
    // 2. 对空闲链表按照地址有序排列
    // 3. 检查并合并相邻的空闲分区
    // 4. 将空闲链表重新按照当前算法排序
   // 请自行补充……
    fbt->start_addr = ab->start_addr; //保存结点信息并将释放结点插入到空闲队列开头
    fbt->size = ab->size;
    fbt->next = free_block;
    free_block = fbt;

    rearrange_FF();    //按地址有序排列
    printf("free block was sorted according to address\n");

    pre = free_block;    //合并相邻空闲分区
    fbt = free_block->next;
    while(fbt != NULL){
        if(pre->start_addr + pre->size == fbt->start_addr)
        {
            pre->size = pre->size + fbt->size;
            pre->next = fbt->next;
            free(fbt);
            fbt = pre->next;
        }
        else {
            pre = fbt->next;
            fbt = fbt->next;
        }
    }
    printf("free block combined\n\n");
    rearrange(ma_algorithm);    //按当前算法重新排序
    return 1;
}

int dispose(struct allocated_block *free_ab){
    struct allocated_block *pre, *ab;
    if(free_ab == allocated_block_head) { /*如果要释放第一个节点*/
        allocated_block_head = allocated_block_head->next;
        free(free_ab);
        return 1;
    }
    pre = allocated_block_head;
    ab = allocated_block_head->next;
    while(ab!=free_ab){ pre = ab;  ab = ab->next; }
    pre->next = ab->next;
    free(ab);
    return 2;
}
struct allocated_block *find_process(int pid)
{
 struct  allocated_block *p=allocated_block_head;
 // p=allocated_block_head;struct allocated_block *allocated_block_head = NULL
 while(p)           
  //判断条件必须是p是否为空不能是p->next,因为如果只有一个节点时p->next=NULL，此时不能返回要删除的节点
 {
  if(p->pid==pid)
  {
   return p;
  }
  p=p->next;
 }
 return NULL; 
}
void kill_process(){
    struct allocated_block *ab;
    int pid;
    printf("Kill Process, pid=");
    scanf("%d", &pid);
    ab=find_process(pid);
    if(ab!=NULL){
        free_mem(ab); /*释放ab所表示的分配区*/
        dispose(ab);  /*释放ab数据结构节点*/
    }
}
int display_mem_usage(){
    struct free_block_type *fbt=free_block;
    struct allocated_block *ab=allocated_block_head;
    if(fbt==NULL) return(-1);
    printf("----------------------------------------------------------\n");

    /* 显示空闲区 */
    printf("Free Memory:\n");
    printf("%20s %20s\n", "      start_addr", "       size");
    while(fbt!=NULL){
        printf("%20d %20d\n", fbt->start_addr, fbt->size);
        fbt=fbt->next;
    }
    printf("\nUsed Memory:\n");
    printf("%10s %20s %10s %10s\n", "PID", "ProcessName", "start_addr", " size");
    while(ab!=NULL){
        printf("%10d %20s %10d %10d\n", ab->pid, ab->process_name, ab->start_addr, ab->size);
        ab=ab->next;
    }
    printf("----------------------------------------------------------\n");
    return 0;
}
void do_exit(){        //释放空间
    struct free_block_type *fb1, *fb2;
    struct allocated_block *ab1, *ab2;
    
    fb1 = free_block;
    while(fb1 !=NULL){
        fb2 = fb1->next;
        free(fb1);
        fb1 = fb2;
    }
    printf("free_block_type free\n\n");

    ab1 = allocated_block_head;
    while (ab1 != NULL){
        ab2 = ab1->next;
        free(ab1);
        ab1 = ab2;
    }
    printf("allocated_block free\n\n");
}
main(){
    char choice;      pid=0;
    free_block = init_free_block(mem_size); //初始化空闲区
    while(1) {
        display_menu(); //显示菜单
        fflush(stdin);
        fflush(stdin) ; 
        choice=getchar();   //获取用户输入
        switch(choice){
            case '1': set_mem_size(); break;    //设置内存大小
            case '2': set_algorithm();flag=1; break;//设置算法
            case '3': new_process(); flag=1; break;//创建新进程
            case '4': kill_process(); flag=1;   break;//删除进程
            case '5': display_mem_usage();    flag=1; break;    //显示内存使用
            case '0': do_exit(); exit(0);   //释放链表并退出
            default: break;
 }
    }
}


