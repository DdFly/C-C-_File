#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define PROCESS_NAME_LEN 32   /*����������*/
#define MIN_SLICE    10             /*��С��Ƭ�Ĵ�С*/
#define DEFAULT_MEM_SIZE 1024     /*�ڴ��С*/
#define DEFAULT_MEM_START 0       /*��ʼλ��*/
/* �ڴ�����㷨 */
#define MA_FF 1
#define MA_BF 2
#define MA_WF 3
int mem_size=DEFAULT_MEM_SIZE; /*�ڴ��С*/
int ma_algorithm = MA_FF;           /*��ǰ�����㷨*/
static int pid = 0;                                      /*��ʼpid*/
int flag = 0;                             /*�����ڴ��С��־*/
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
    if(flag!=0){  //��ֹ�ظ�����
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
    //�����в���
    struct free_block_type *position, *min, *current;
    int size;
    int start_addr;
    printf("Rearrange free blocks for FF \n\n");
    position = free_block;

    //���п鰴��ַ˳����м�ѡ������
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
/*��BF�㷨���������ڴ���п�����*/
void rearrange_BF(){
    //�����в���
    struct free_block_type *position, *min, *current;
    int size;
    int start_addr;
    printf("Rearrange free blocks for BF\n\n");
    position = free_block;

    //���п鰴��С������м�ѡ������
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
    //�����в���
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
    //��ָ���㷨�������п���������
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
    
    fb1 = free_block->next;        //������ֻ��һ�����п飬��������
    while(fb1 != NULL){            //�������п��ͷ�
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
    //���ݵ�ǰ�㷨�ڿ��з����������������ʿ��з������з��䣬����ʱע�����������
    // 1. �ҵ���������з����ҷ����ʣ��ռ��㹻����ָ�
    // 2. �ҵ���������з����ҵ������ʣ��ռ�Ƚ�С����һ�����
    // 3. �Ҳ���������Ҫ�Ŀ��з��������з���֮����������Ҫ��������ڴ�������������п���
//�����ĺϲ���Ȼ���ٷ���
    // 4. �ڳɹ������ڴ��Ӧ���ֿ��з���������Ӧ�㷨����
    // 5. ����ɹ��򷵻�1�����򷵻�-1
    //�����в��䡣��������
    while(fbt!=NULL){

        if( (fbt->size - request_size) >= MIN_SLICE ){    //�������пռ��㹻����ָ�
         
            ab->start_addr = fbt->start_addr;
            fbt->size = fbt->size - request_size;
            fbt->start_addr = fbt->start_addr + request_size;
            rearrange(ma_algorithm);
            return 1;
        }
        else if( (fbt->size > request_size) && (fbt->size - request_size < MIN_SLICE) ){    //�ָ���������ΪС��Ƭ��һ�����
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
    ret = allocate_mem(ab);  /* �ӿ����������ڴ棬ret==1��ʾ����ok*/
    if((ret==1) &&(allocated_block_head == NULL)){
        allocated_block_head=ab;
        return 1;
    }
    /*����ɹ��������ѷ��������������ѷ�������*/
    else if (ret==1) {
        ab->next=allocated_block_head;
        allocated_block_head=ab;
        return 2;
    }
else if(ret==-1){ /*���䲻�ɹ�*/
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
    // ���п��ܵĺϲ���������������
    // 1. �����ͷŵĽ����뵽���з�������ĩβ
    // 2. �Կ��������յ�ַ��������
    // 3. ��鲢�ϲ����ڵĿ��з���
    // 4. �������������°��յ�ǰ�㷨����
   // �����в��䡭��
    fbt->start_addr = ab->start_addr; //��������Ϣ�����ͷŽ����뵽���ж��п�ͷ
    fbt->size = ab->size;
    fbt->next = free_block;
    free_block = fbt;

    rearrange_FF();    //����ַ��������
    printf("free block was sorted according to address\n");

    pre = free_block;    //�ϲ����ڿ��з���
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
    rearrange(ma_algorithm);    //����ǰ�㷨��������
    return 1;
}

int dispose(struct allocated_block *free_ab){
    struct allocated_block *pre, *ab;
    if(free_ab == allocated_block_head) { /*���Ҫ�ͷŵ�һ���ڵ�*/
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
  //�ж�����������p�Ƿ�Ϊ�ղ�����p->next,��Ϊ���ֻ��һ���ڵ�ʱp->next=NULL����ʱ���ܷ���Ҫɾ���Ľڵ�
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
        free_mem(ab); /*�ͷ�ab����ʾ�ķ�����*/
        dispose(ab);  /*�ͷ�ab���ݽṹ�ڵ�*/
    }
}
int display_mem_usage(){
    struct free_block_type *fbt=free_block;
    struct allocated_block *ab=allocated_block_head;
    if(fbt==NULL) return(-1);
    printf("----------------------------------------------------------\n");

    /* ��ʾ������ */
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
void do_exit(){        //�ͷſռ�
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
    free_block = init_free_block(mem_size); //��ʼ��������
    while(1) {
        display_menu(); //��ʾ�˵�
        fflush(stdin);
        fflush(stdin) ; 
        choice=getchar();   //��ȡ�û�����
        switch(choice){
            case '1': set_mem_size(); break;    //�����ڴ��С
            case '2': set_algorithm();flag=1; break;//�����㷨
            case '3': new_process(); flag=1; break;//�����½���
            case '4': kill_process(); flag=1;   break;//ɾ������
            case '5': display_mem_usage();    flag=1; break;    //��ʾ�ڴ�ʹ��
            case '0': do_exit(); exit(0);   //�ͷ������˳�
            default: break;
 }
    }
}


