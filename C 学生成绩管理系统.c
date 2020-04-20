#include<stdio.h>
#include<stdlib.h>
#include<string.h>
enum sexual{male,female}sex;
struct UnderGraduate{
    int num;
    char name[20];
    int sex;
    char major[20];
    int classroom;
    int math;
    int english;
    int C;
    int total;
    int ClassRanking;
    int SchoolRanking;
    struct UnderGraduate *next;
};
struct GraduateStudent{
    int num;
    char name[20];
    int sex;
    char major[20];
    int classroom;
    char target[20];
    char tutor[20];
    int ClassScore;
    int ThesisScore;
    int total;
    int ClassRanking;
    int SchoolRanking;
    struct GraduateStudent *next;
};
struct UnderGraduate *ReadFromFile1(FILE *fp,struct UnderGraduate *head1);
struct GraduateStudent *ReadFromFile2(FILE *fp,struct GraduateStudent *head2);
/*==============================================*/
void weihu(void);
void add_jiben_dange(void);
void add_jiben_piliang(void);
struct UnderGraduate *add_dange_ziliao_UnderGraduate(struct UnderGraduate *head1);
struct UnderGraduate *add_piliang_ziliao_UnderGraduate(struct UnderGraduate *head1);
struct GraduateStudent *add_dange_ziliao_GraduateStudent(struct GraduateStudent *head2);
struct GraduateStudent *add_piliang_ziliao_GraduateStudent(struct GraduateStudent *head2);
void edit(void);
void delete_caidan(void);
void delete_quanbu(void);
void delete_chengji(void);
void delete_benke_quanbu(int num);
void delete_yanjiusheng_quanbu(int num);
struct UnderGraduate *delete_benke_chengji(struct UnderGraduate *head1,int num);
struct GraduateStudent *delete_yanjiusheng_chengji(struct GraduateStudent *head2,int num);
void query_xuehao(void);
void jisuan(void);
void jisuan_output(void);
struct UnderGraduate *ranking_benke(struct UnderGraduate *head1);
struct GraduateStudent *ranking_yanjiusheng(struct GraduateStudent *head2);
void jisuan_zongfen(void);
/*==============================================*/
void query_caidan(void);
void query_UnderGraduate(void);
void query_GraduateStudent(void);
void query_UnderGraduate_fail(void);
void query_GraduateStudent_fail(void);
void query_page(void);
int query_page_shouye(void);
int query_page_weiye(void);
int query_page_putongye(void);
void query_UnderGraduate_class(void);
void query_UnderGraduate_num(void);
void query_UnderGraduate_name(void);
void query_UnderGraduate_C_fail(void);
void query_UnderGraduate_english_fail(void);
void query_UnderGraduate_math_fail(void);
void query_GraduateStudent_class(void);
void query_GraduateStudent_num(void);
void query_GraduateStudent_name(void);
void query_GraduateStudent_ThesisScore_fail(void);
void query_GraduateStudent_ClassScore_fail(void);
/*==============================================*/
void ranking(void);
/*==============================================*/
void paixu(void);
void paixu_all(void);
void paixu_class(void);
void paixu_class_benkesheng(void);
void paixu_class_yanjiusheng(void);
/*==============================================*/
void tongji(void);
void tongji_benke(void);
void tongji_yanjiu(void);
void tongji_benke_banji(void);
void tongji_benke_dengji(void);
void tongji_yanjiu_banji(void);
void tongji_yanjiu_dengji(void);
/*==============================================*/
void SaveToFile1(struct UnderGraduate *head1);
void SaveToFile2(struct GraduateStudent *head2);
/*==============================================*/
struct UnderGraduate *head1=NULL;
struct GraduateStudent *head2=NULL;
int num1=0;
int num2=0;
int zongye=0,dangqianye=0,zongxuesheng=0,benkesheng;
FILE *fp;
int main()
{
    int sel;
    head1=ReadFromFile1(fp,head1);
    head2=ReadFromFile2(fp,head2);
    system("cls");
    while(1){
    printf("            学生成绩管理系统");
    printf("======================================================\n");
    printf("1.学生成绩维护               2.学生数据查询\n");
    printf("3.学生成绩排名               4.学生成绩排序\n");
    printf("5.统计功能                  0.退出程序并将数据保存到文件中\n");
    printf("======================================================\n");
        printf("请选择功能:\n");
        scanf("%d",&sel);
        switch(sel){
            case 1:
                weihu();
                break;
            case 2:
                query_caidan();
                break;
            case 3:
                ranking();
                break;
            case 4:
                paixu();
                break;
            case 5:
                tongji();
                break;
            case 0:
                SaveToFile1(head1);
                SaveToFile2(head2);
                exit(0);
        }
        system("cls");
    }
}

void weihu(){
    int sel;
    printf("           二级菜单-链表维护\n");
    printf("=============================================\n");
    printf("1.单个添加学生资料     2.批量添加学生资料\n");
    printf("3.通过学号修改资料     4.根据学号删除学生资料\n");
    printf("5.通过学号查询资料     6.计算所有学生数据\n");
    printf("0.退出当前菜单\n");
    printf("=============================================\n");
    printf("请选择功能:\n");
    scanf("%d",&sel);
    switch(sel){
        case 1:
            add_jiben_dange();
            break;
        case 2:
            add_jiben_piliang();
            break;
        case 3:
            edit();
            break;
        case 4:
            delete_caidan();
            break;
        case 5:
            query_xuehao();
            break;
        case 6:
            jisuan();
            break;
        case 0:
            break;
    }
    printf("请按任意键继续。。。\n");
    getchar();
}
void add_jiben_dange(){
    int sel;
    printf("           三级菜单-链表维护\n");
    printf("=============================================\n");
    printf("1.单个添加本科生资料     2.单个添加研究生资料\n");
    printf("0.退出当前菜单\n");
    printf("============================================\n");
    printf("请选择功能:\n");
    scanf("%d",&sel);
    switch(sel){
        case 1:
            head1=add_dange_ziliao_UnderGraduate(head1);
            break;
        case 2:
            head2=add_dange_ziliao_GraduateStudent(head2);
            break;
        case 0:
            break;
    }
    getchar();
}
void add_jiben_piliang(){
    int sel;
    printf("           三级菜单-链表维护\n");
    printf("=============================================\n");
    printf("1.批量添加本科生资料     2.批量添加研究生资料\n");
    printf("0.退出当前菜单\n");
    printf("=============================================\n");
    printf("请选择功能:\n");
    scanf("%d",&sel);
    switch(sel){
        case 1:
            head1=add_piliang_ziliao_UnderGraduate(head1);
            break;
        case 2:
            head2=add_piliang_ziliao_GraduateStudent(head2);
            break;
        case 0:
            break;
    }
    getchar();
}
void delete_caidan(){
    int sel;
    printf("           三级菜单-链表维护\n");
    printf("=============================================\n");
    printf("1.删除学生所有资料     2.删除学生成绩资料\n");
    printf("0.退出当前菜单\n");
    printf("=============================================\n");
    printf("请选择功能:\n");
    scanf("%d",&sel);
    switch(sel){
        case 1:
            delete_quanbu();
            break;
        case 2:
            delete_chengji();
            break;
        case 0:
            break;
    }
    getchar();
}

 void query_caidan(){
     int sel;
     printf("       二级菜单-查询学生信息\n");
     printf("=======================================\n");
     printf("1.本科生                     2.研究生\n");
     printf("3.按页显示全部学生信息         0.退出当前菜单\n");
     printf("=======================================\n");
     printf("请选择功能:\n");
     scanf("%d",&sel);
     switch(sel){
         case 1:
             query_UnderGraduate();
             break;
         case 2:
             query_GraduateStudent();
             break;
         case 3:
             query_page();
             break;
         case 0:
             break;
     }
     getchar();
}
 void query_UnderGraduate(){
     int sel;
     printf("       三级菜单-查询本科生信息链表\n");
     printf("=======================================\n");
     printf("1.按班级显示信息         2.按学号查询信息\n");
     printf("3.按姓名查询信息         4.查询不及格学生\n");
     printf("0.退出当前菜单\n");
     printf("=======================================\n");
     printf("请选择功能:\n");
     scanf("%d",&sel);
     switch(sel){
         case 1:
             query_UnderGraduate_class();
             break;
         case 2:
             query_xuehao();
             break;
         case 3:
             query_UnderGraduate_name();
             break;
         case 4:
             query_UnderGraduate_fail();
             break;
         case 0:
             break;
     }
     printf("请按任意键继续...\n");
     getchar();
 }
 void query_GraduateStudent(){
     int sel;
     printf("       三级菜单-查询研究生信息链表\n");
     printf("=======================================\n");
     printf("1.按班级显示信息         2.按学号查询信息\n");
     printf("3.按姓名查询信息         4.查询不及格学生\n");
     printf("0.退出当前菜单\n");
     printf("=======================================\n");
     printf("请选择功能:\n");
     scanf("%d",&sel);
     switch(sel){
         case 1:
             query_GraduateStudent_class();
             break;
         case 2:
             query_xuehao();
             break;
         case 3:
             query_GraduateStudent_name();
             break;
         case 4:
             query_GraduateStudent_fail();
             break;
         case 0:
             break;
     }
     printf("请按任意键继续...\n");
     getchar();
 }
void query_UnderGraduate_fail(){
    int sel;
    printf("     四级菜单-查询本科生不及格\n");
    printf("==============================\n");
    printf("1.高数成绩           2.英语成绩\n");
    printf("3.C语言成绩          0.退出当前菜单\n");
    printf("=============================\n");
    printf("请选择功能:\n");
    scanf("%d",&sel);
    switch(sel){
        case 1:
            query_UnderGraduate_math_fail();
            break;
        case 2:
            query_UnderGraduate_english_fail();
            break;
        case 3:
            query_UnderGraduate_C_fail();
            break;
        case 0:
            break;
    }
}
void query_GraduateStudent_fail(){
    int sel;
    printf("         四级菜单-查询研究生不及格\n");
    printf("=======================================\n");
    printf("1.课程综合成绩                   2.论文成绩\n");
    printf("0.退出当前菜单\n");
    printf("=======================================\n");
    printf("请选择功能:\n");
    scanf("%d",&sel);
    switch(sel){
        case 1:
            query_GraduateStudent_ClassScore_fail();
            break;
        case 2:
            query_GraduateStudent_ThesisScore_fail();
            break;
        case 0:
            break;
    }
}

 void ranking(){
     int sel;
     jisuan_zongfen();
     printf("           二级菜单-学生排名\n");
     printf("==========================================\n");
     printf("1.计算本科生所有排名         2.计算研究生所有排名\n");
     printf("0.退出当前菜单\n");
     printf("=======================================\n");
     printf("请选择功能:\n");
     scanf("%d",&sel);
     switch(sel){
         case 1:
             head1=ranking_benke(head1);
             break;
         case 2:
             head2=ranking_yanjiusheng(head2);
             break;
         case 0:
             break;
     }
     printf("统计完毕...\n");
     printf("请按任意键继续。。。\n");
     getchar();
     getchar();
 }

 void paixu(){
     int sel;
     printf("                     二级菜单-学生排序\n");
     printf("==========================================================\n");
     printf("1.所有学生按成绩排序                         2.班级内部按成绩排序\n");
     printf("0.退出当前菜单\n");
     printf("==========================================================\n");
     printf("请选择功能:\n");
     scanf("%d",&sel);
     switch(sel){
         case 1:
             paixu_all();
             break;
         case 2:
             paixu_class();
             break;
         case 0:
             break;
     }
     printf("请按任意键继续。。。\n");
     getchar();
     getchar();
 }
void paixu_class(){
    int sel;
    printf("                     三级菜单-学生排序\n");
    printf("==========================================================\n");
    printf("1.本科生按班级的成绩排序                  2.研究生按班级的成绩排序\n");
    printf("0.退出当前菜单\n");
    printf("==========================================================\n");
    printf("请选择功能:\n");
    scanf("%d",&sel);
    switch(sel){
        case 1:
            paixu_class_benkesheng();
            break;
        case 2:
            paixu_class_yanjiusheng();
            break;
        case 0:
            break;
    }
    printf("排序完毕...\n");
}
 void tongji(){
     int sel;
     printf("     二级菜单-统计\n");
     printf("==========================\n");
     printf("1.本科生       2.研究生\n");
     printf("0.退出当前菜单\n");
     printf("==========================\n");
     printf("请选择功能:\n");
     scanf("%d",&sel);
     switch(sel){
         case 1:
             tongji_benke();
             break;
         case 2:
             tongji_yanjiu();
             break;
         case 0:
             break;
     }
     printf("请按任意键继续。。。\n");
     getchar();
     getchar();
}
 void tongji_benke(){
     int sel;
     printf("              三级菜单-本科生统计\n");
     printf("=======================================\n");
     printf("1.统计并显示每科班级平均成绩       2.统计不同等级人数\n");
     printf("0.退出当前菜单\n");
     printf("=======================================\n");
     printf("请选择功能:\n");
     scanf("%d",&sel);
     switch(sel){
         case 1:
             tongji_benke_banji();
             break;
         case 2:
             tongji_benke_dengji();
             break;
         case 0:
             break;
     }
 }
 void tongji_yanjiu(){
     int sel;
     printf("     三级菜单-研究生统计\n");
     printf("=========================================\n");
     printf("1.统计并显示班级成绩       2.统计不同等级人数\n");
     printf("0.退出当前菜单\n");
     printf("=========================================\n");
     printf("请选择功能:\n");
     scanf("%d",&sel);
     switch(sel){
         case 1:
             tongji_yanjiu_banji();
             break;
         case 2:
             tongji_yanjiu_dengji();
             break;
         case 0:
             break;
     }
 }

/*==============================================================================*/
/*==============================================================================*/
/*==============================================================================*/
/*==============================================================================*/
/*==============================================================================*/
/*==============================================================================*/
/*==============================================================================*/
/*==============================================================================*/
/*==============================================================================*/
struct UnderGraduate *ReadFromFile1(FILE *fp,struct UnderGraduate *head1)
{
    struct UnderGraduate *p1,*p2;
    int size=sizeof(struct UnderGraduate);
    int n=0;
    int i;
    if ((fp = fopen("student1.dat", "rb")) == NULL) {
        printf("打开文件出错！\n");
        exit(0);
    }
    while(!feof(fp)){
        if((p1=(struct UnderGraduate *)malloc(size))==NULL){
            printf("不能分配空间\n");
            exit(0);
        }
        fread(p1,size,1,fp);
        n++;
    }
    n--;
    printf("正在从文件读取本科生数据到链表，请稍等...\n");
    printf("读取结果如下：\n");
    printf("学号    姓名    性别     专业  班级 数学 英语 C语言 总分 班级排名 校级排名\n");
    fseek(fp,0L,0);
    for(i=0;i<n;i++){
        if((p1=(struct UnderGraduate *)malloc(size))==NULL){
            printf("不能分配空间\n");
            exit(0);
        }
        p1->next=NULL;
        fread(p1,size,1,fp);
        printf("%-8d%-8s",p1->num,p1->name);
        sex=(enum)p1->sex;
        switch(sex){
            case male:{
                printf("male     ");break;}
            case female:{
                printf("female   ");break;}
            default:{
                printf("未录入   ");break;}
        }
        printf("%-6s%d   %-5d%-5d%-5d%-5d%-4d%-4d\n",p1->major,p1->classroom,p1->math,p1->english,p1->C,p1->total,p1->ClassRanking,p1->SchoolRanking);
        if(i==0)
            head1=p1;
        else p2->next=p1;
        p2=p1;
    }
    if (fclose(fp)) {
        printf("不能正常关闭文件！\n");
        exit(0);
    }
    printf("读取结束，共读取了%d名学生数据\n", n);
    printf("请按任意键继续...");
    getchar();
    return head1;
}
struct GraduateStudent *ReadFromFile2(FILE *fp,struct GraduateStudent *head2)
{
    struct GraduateStudent *p1,*p2;
    int size=sizeof(struct GraduateStudent);
    int n=0;
    int i;
    if ((fp = fopen("student2.dat", "rb")) == NULL) {
        printf("打开文件出错！\n");
        exit(0);
    }
    while(!feof(fp)){
        if((p1=(struct GraduateStudent *)malloc(size))==NULL){
            printf("不能分配空间\n");
            exit(0);
        }
        fread(p1,size,1,fp);
        n++;
    }
    n--;
    printf("正在从文件读取研究生数据到链表，请稍等...\n");
    printf("读取结果如下：\n");
    printf("学号    姓名    性别     专业  班级   研究方向 导师 课程成绩 论文成绩 总分 班级排名 校级排名\n");
    fseek(fp,0L,0);
    for(i=0;i<n;i++){
        if((p1=(struct GraduateStudent *)malloc(size))==NULL){
            printf("不能分配空间\n");
            exit(0);
        }
        p1->next=NULL;
        fread(p1,size,1,fp);
        printf("%-8d%-8s",p1->num,p1->name);
        sex=(enum)p1->sex;
        switch(sex){
            case male:{
                printf("male     ");break;}
            case female:{
                printf("female   ");break;}
            default:{
                printf("未录入    ");break;}
        }
        printf("%-6s%d   %-12s%-3s%-5d%-5d%-5d%-4d%-4d\n",p1->major,p1->classroom,p1->target,p1->tutor,p1->ClassScore,p1->ThesisScore,p1->total,p1->ClassRanking,p1->SchoolRanking);
        if(i==0)
            head2=p1;
        else p2->next=p1;
        p2=p1;
    }
    if (fclose(fp)) {
        printf("不能正常关闭文件！\n");
        exit(0);
    }
    printf("读取结束，共读取了%d名学生数据\n", n);
    printf("请按任意键继续...");
    getchar();
    return head2;
}
void SaveToFile1(struct UnderGraduate *head1)
{
    struct UnderGraduate *p1;
    int i=0;
    printf("正在将本科生生信息保存到文件，请稍后...\n");
    if ((fp = fopen("student1(保存后).txt", "w")) == NULL) {
        printf("打开文件出错！\n");
        exit(0);
    }
    p1 = head1;
    while (p1->next != NULL) {
        fprintf(fp, "%-8d%-8s%-3d%-6s%d   %-5d%-5d%-5d%-5d%-4d%-4d\n", p1->num,p1->name,p1->sex,p1->major,p1->classroom,p1->math,p1->english,p1->C,p1->total,p1->ClassRanking,p1->SchoolRanking);
        p1 = p1->next;
        i++;
    }
    fprintf(fp,"%-8d%-8s%-3d%-6s%d   %-5d%-5d%-5d%-5d%-4d%-4d\n", p1->num,p1->name,p1->sex,p1->major,p1->classroom,p1->math,p1->english,p1->C,p1->total,p1->ClassRanking,p1->SchoolRanking);
    i++;
    if (fclose(fp)) {
        printf("不能正常关闭文件！\n");
        exit(0);
    }
    printf("读取结束，共保存了%d名本科生数据\n",i);
}
void SaveToFile2(struct GraduateStudent *head2)
{
    struct GraduateStudent *p1;
    int i=0;
    printf("正在将本科生生信息保存到文件，请稍后...\n");
    if ((fp = fopen("student2(保存后).txt", "w")) == NULL) {
        printf("打开文件出错！\n");
        exit(0);
    }
    p1 = head2;
    while (p1->next != NULL) {
        fprintf(fp,"%-8d%-8s%-3d%-6s%d   %-12s%-3s%-5d%-5d%-5d%-4d%-4d\n", p1->num,p1->name,p1->sex,p1->major,p1->classroom,p1->target,p1->tutor,p1->ClassScore,p1->ThesisScore,p1->total,p1->ClassRanking,p1->SchoolRanking);
        p1 = p1->next;
        i++;
    }
    fprintf(fp,"%-8d%-8s%-3d%-6s%d   %-12s%-3s%-5d%-5d%-5d%-4d%-4d\n", p1->num,p1->name,p1->sex,p1->major,p1->classroom,p1->target,p1->tutor,p1->ClassScore,p1->ThesisScore,p1->total,p1->ClassRanking,p1->SchoolRanking);
    i++;
    if (fclose(fp)) {
        printf("不能正常关闭文件！\n");
        exit(0);
    }
    printf("读取结束，共保存了%d名学生数据\n",i);
    printf("欢迎使用成绩管理系统\n");
    printf("请按任意键退出\n");
    getchar();
}
/*==============================================================================*/
struct UnderGraduate *add_dange_ziliao_UnderGraduate(struct UnderGraduate *head1)
{
    struct UnderGraduate *p1,*p2;
    int size=sizeof(struct UnderGraduate);
    int num;
    p2=head1;
    while(p2->next!=NULL)
        p2=p2->next;
    num=p2->num;
    num++;
    if((p1=(struct UnderGraduate *)malloc(size))==NULL){
        printf("未能分配储存块\n");
        exit(0);
    }
    p1->next=NULL;
    printf("请输入该学生的姓名，性别(0为男，1为女)，专业，班级,高数，英语，C语言成绩）\n");
    scanf("%s%d%s%d%d%d%d",p1->name,&p1->sex,p1->major,&p1->classroom,&p1->math,&p1->english,&p1->C);
    p1->num=num;
    p2->next=p1;
    return head1;
}
struct UnderGraduate *add_piliang_ziliao_UnderGraduate(struct UnderGraduate *head1)
{
    struct UnderGraduate *p1,*p2,*p3,*head2;
    int size=sizeof(struct UnderGraduate);
    int num,i=0;
    p3=head1;
    while(p3->next!=NULL)
        p3=p3->next;
    num=p3->num;
    printf("请输入该学生的姓名，性别(0为男，1为女)，专业，班级,高数，英语，C语言成绩）(以所有成绩为-1结束)\n");
    while(1){
        if((p1=(struct UnderGraduate *)malloc(size))==NULL){
            printf("未能分配储存块\n");
            exit(0);
        }
        p1->next=NULL;
        scanf("%s%d%s%d%d%d%d",p1->name,&p1->sex,p1->major,&p1->classroom,&p1->math,&p1->english,&p1->C);
        if(p1->math<0||p1->english<0||p1->C<0||p1->math>100||p1->english>100||p1->C>100){
            printf("输入错误或者结束输入...\n");
            p1=NULL;
            break;
        }
        else {
            num++;
            p1->num=num;
            if(i==0) head2=p1;
            else p2->next=p1;
            i++;
            p2=p1;
        }
    }
    p3->next=head2;
    return head1;
}
struct GraduateStudent *add_dange_ziliao_GraduateStudent(struct GraduateStudent *head2)
{
    struct GraduateStudent *p1,*p2;
    int size=sizeof(struct GraduateStudent);
    int num;
    p2=head2;
    while(p2->next!=NULL)
        p2=p2->next;
    num=p2->num;
    num++;
    if((p1=(struct GraduateStudent *)malloc(size))==NULL){
        printf("未能分配储存块\n");
        exit(0);
    }
    p1->next=NULL;
    printf("请输入学生的姓名，性别(0为男，1为女)，专业，班级,研究方向，导师，课程综合成绩，论文成绩）\n");
    scanf("%s%d%s%d%s%s%d%d",p1->name,&p1->sex,p1->major,&p1->classroom,p1->target,p1->tutor,&p1->ClassScore,&p1->ThesisScore);
    p1->num=num;
    p2->next=p1;
    return head2;
}
struct GraduateStudent *add_piliang_ziliao_GraduateStudent(struct GraduateStudent *head2)
{
    struct GraduateStudent *p1,*p2,*p3,*head3;
    int size=sizeof(struct GraduateStudent);
    int num,i=0;
    p3=head2;
    while(p3->next!=NULL)
        p3=p3->next;
    num=p3->num;
    printf("请输入学生的姓名，性别(0为男，1为女)，专业，班级,研究方向，导师，课程综合成绩，论文成绩）(以所有成绩为-1结束)\n");
    while(1){
        if((p1=(struct GraduateStudent *)malloc(size))==NULL){
            printf("未能分配储存块\n");
            exit(0);
        }
        p1->next=NULL;
        scanf("%s%d%s%d%s%s%d%d",p1->name,&p1->sex,p1->major,&p1->classroom,p1->target,p1->tutor,&p1->ClassScore,&p1->ThesisScore);
        if(p1->ClassScore<0||p1->ThesisScore<0||p1->ClassScore>100||p1->ThesisScore>100){
            printf("输入错误或者结束输入...\n");
            p1=NULL;
            break;
        }
        else {
            num++;
            p1->num=num;
            if(i==0) head3=p1;
            else p2->next=p1;
            i++;
            p2=p1;
        }
    }
    p3->next=head3;
    return head2;
}
void edit(){
    struct UnderGraduate *p1;
    struct GraduateStudent *p2;
    int num1,num2,num3,num4,num5;
    p1=head1;
    num1=p1->num;
    while(p1->next!=NULL)
        p1=p1->next;
    num2=p1->num;
    p2=head2;
    num3=p2->num;
    while(p2->next!=NULL)
        p2=p2->next;
    num4=p2->num;
    printf("请输入要修改的学生学号:");
    scanf("%d",&num5);
    p1=head1;
    p2=head2;
    if(num5>=num1&&num5<=num2){
        printf("该生为本科生，且学生数据为:\n");
        while(p1->num!=num5&&p1->next!=NULL){p1=p1->next;}
        printf("%-8d%-8s",p1->num,p1->name);
        sex=(enum)p1->sex;
        switch(sex){
            case male:{
                printf("male     ");break;}
            case female:{
                printf("female   ");break;}
            default:{
                printf("未录入    ");break;}
        }
        printf("%-6s%d   %-5d%-5d%-5d%-5d%-4d%-4d\n",p1->major,p1->classroom,p1->math,p1->english,p1->C,p1->total,p1->ClassRanking,p1->SchoolRanking);
        printf("请输入修改后的该生名字，性别（0为男，1为女），专业，班级，高数成绩，英语成绩，C语言成绩：\n");
        scanf("%s%d%s%d%d%d%d",p1->name,&p1->sex,p1->major,&p1->classroom,&p1->math,&p1->english,&p1->C);
        printf("该生修改完毕...\n");
        getchar();
    }
    else if(num5>=num3&&num5<=num4){
        printf("该生为研究生，且学生数据为:\n");
        while(p2->num!=num5&&(p2->next!=NULL)){p2=p2->next;}
        printf("%-8d%-8s",p2->num,p2->name);
        sex=(enum)p2->sex;
        switch(sex){
            case male:{
                printf("male     ");break;}
            case female:{
                printf("female   ");break;}
            default:{
                printf("未录入    ");break;}
        }
        printf("%-6s%d   %-12s%-3s%-5d%-5d%-5d%-4d%-4d\n",p2->major,p2->classroom,p2->target,p2->tutor,p2->ClassScore,p2->ThesisScore,p2->total,p2->ClassRanking,p2->SchoolRanking);
        printf("请输入修改后该学生的姓名，性别(0为男，1为女)，专业，班级,研究方向，导师，课程综合成绩，论文成绩）\n");
        scanf("%s%d%s%d%s%s%d%d",p2->name,&p2->sex,p2->major,&p2->classroom,p2->target,p2->tutor,&p2->ClassScore,&p2->ThesisScore);
        printf("该生修改完毕...\n");
        getchar();
    }
    else
        printf("查无此生...\n");
    getchar();
}
void delete_quanbu(){
    struct UnderGraduate *p1;
    struct GraduateStudent *p2;
    int num1,num2,num3,num4,num5;
    p1=head1;
    num1=p1->num;
    while(p1->next!=NULL)
        p1=p1->next;
    num2=p1->num;
    p2=head2;
    num3=p2->num;
    while(p2->next!=NULL)
        p2=p2->next;
    num4=p2->num;
    printf("请输入你要删除的学生学号:");
    scanf("%d",&num5);
    if(num5>=num1&&num5<=num2)
        delete_benke_quanbu(num5);
    else if(num5>=num3&&num5<=num4)
        delete_yanjiusheng_quanbu(num5);
    else
        printf("查无此生...\n");
}
void delete_chengji(){
    struct UnderGraduate *p1;
    struct GraduateStudent *p2;
    int num1,num2,num3,num4,num5;
    p1=head1;
    num1=p1->num;
    while(p1->next!=NULL)
        p1=p1->next;
    num2=p1->num;
    p2=head2;
    num3=p2->num;
    while(p2->next!=NULL)
        p2=p2->next;
    num4=p2->num;
    printf("请输入你要删除的学生学号:");
    scanf("%d",&num5);
    if(num5>=num1&&num5<=num2)
        head1=delete_benke_chengji(head1,num5);
    else if(num5>=num3&&num5<=num4)
        head2=delete_yanjiusheng_chengji(head2,num5);
    else
        printf("查无此生...\n");
}
void delete_benke_quanbu(int num){
    struct UnderGraduate *p1,*p2;
    p1=head1;
    while (p1->num!=num&&p1->next!=NULL){
        p2 = p1; p1 = p1->next;
    }
    if (head1 == p1) head1 = p1->next;
    else p2->next = p1->next;
    free(p1);
    printf("学生数据删除成功\n");
}
void delete_yanjiusheng_quanbu(int num){
    struct GraduateStudent *p1,*p2;
    p1=head2;
    while (p1->num!=num&&p1->next!=NULL){
        p2 = p1; p1 = p1->next;
    }
    if (head2 == p1) head2 = p1->next;
    else p2->next = p1->next;
    free(p1);
    printf("学生数据删除成功\n");
}
struct UnderGraduate *delete_benke_chengji(struct UnderGraduate *head1,int num){
    struct UnderGraduate *p1,*p2;
    p1=head1;;
    while (p1->num!=num&&p1->next!=NULL){
        p2 = p1; p1 = p1->next;
    }
    p1->math=-1;
    p1->english=-1;
    p1->C=-1;
    p1->total=1;
    printf("学生成绩数据已全部修改为-1...\n");
    printf("请按任意键继续...\n");
    getchar();
    return head1;
}
struct GraduateStudent *delete_yanjiusheng_chengji(struct GraduateStudent *head2,int num){
    struct GraduateStudent *p1,*p2;
    p1=head2;
    while (p1->num!=num&&p1->next!=NULL){
        p2 = p1; p1 = p1->next;
    }
    p1->ClassScore=-1;
    p1->ThesisScore=-1;
    p1->total=-1;
    printf("学生成绩数据已全部修改为-1...\n");
    return head2;
}
void query_xuehao(){
    struct UnderGraduate *p1;
    struct GraduateStudent *p2;
    int num1,num2,num3,num4,num5;
    p1=head1;
    num1=p1->num;
    while(p1->next!=NULL)
        p1=p1->next;
    num2=p1->num;
    p2=head2;
    num3=p2->num;
    while(p2->next!=NULL)
        p2=p2->next;
    num4=p2->num;
    printf("请输入要查询的学生学号:");
    scanf("%d",&num5);
    p1=head1;
    p2=head2;
    if(num5>=num1&&num5<=num2){
        while (p1->num!=num5&&p1->next!=NULL){
            p1 = p1->next;
        }
        printf("学号    姓名    性别     专业  班级 数学 英语 C语言 总分 班级排名 校级排名\n");
        printf("%-8d%-8s",p1->num,p1->name);
        sex=(enum)p1->sex;
        switch(sex){
            case male:{
                printf("male     ");break;}
            case female:{
                printf("female   ");break;}
            default:{
                printf("未录入   ");break;}
        }
        printf("%-6s%d   %-5d%-5d%-5d%-5d%-4d%-4d\n",p1->major,p1->classroom,p1->math,p1->english,p1->C,p1->total,p1->ClassRanking,p1->SchoolRanking);
        printf("请按任意键继续...\n");
        getchar();
    }
    else if(num5>=num3&&num5<=num4){
        while (p2->num!=num5&&p2->next!=NULL){
            p2 = p2->next;
        }
        printf("学号    姓名    性别     专业  班级   研究方向 导师 课程成绩 论文成绩 总分 班级排名 校级排名\n");
        printf("%-8d%-8s",p2->num,p2->name);
        sex=(enum)p2->sex;
        switch(sex){
            case male:{
                printf("male     ");break;}
            case female:{
                printf("female   ");break;}
            default:{
                printf("未录入    ");break;}
        }
        printf("%-6s%d   %-12s%-3s%-5d%-5d%-5d%-4d%-4d\n",p2->major,p2->classroom,p2->target,p2->tutor,p2->ClassScore,p2->ThesisScore,p2->total,p2->ClassRanking,p2->SchoolRanking);
        printf("请按任意键继续...\n");
        getchar();
        
    }
    else{
        printf("查无此生...\n");
        printf("请按任意键继续...\n");
        getchar();}
}
void jisuan(){
    int sel;
    jisuan_zongfen();
    printf("正在计算所有成绩，请稍后...\n");
    head1=ranking_benke(head1);
    head2=ranking_yanjiusheng(head2);
    printf("成绩计算完毕，是否需要输出计算结果？\n");
    printf("1.是         2.否\n");
    printf("输出结果如下:\n");
    scanf("%d",&sel);
    switch(sel){
        case 1:
            jisuan_output();
            printf("请按任意键继续...\n");
            break;
        case 2:
            printf("请按任意键继续...\n");
            break;
    }
    getchar();
}
struct UnderGraduate *ranking_benke(struct UnderGraduate *head1){
    struct UnderGraduate *p1,*p2,*p3;
    int i,j,banji,xiaoji,o;
    p3=head1;o=p3->num;
    while(p3->next!=NULL){
        p3=p3->next;o++;
    }
    p1=head1;
    for(i=head1->num;i<o;i++){
        p2=head1;
        banji=1;
        xiaoji=1;
        for(j=head1->num;j<o;j++){
            if(p1->C!=-1||p1->english!=-1||p1->math!=-1){
                if(p1->classroom==p2->classroom){
                    if(p1->total<p2->total){
                        banji++;
                        p1->ClassRanking=banji;
                    }
                }
                if(p1->total<p2->total){
                    xiaoji++;
                    p1->SchoolRanking=xiaoji;
                }
                p2=p2->next;
            }
            else{
                p1->ClassRanking=0;
                p1->SchoolRanking=0;
                break;
            }
        }
        p1=p1->next;
    }
    p2=head1;
    banji=1;
    xiaoji=1;
    for(j=head1->num;j<o;j++){
        if(p1->C!=-1||p1->english!=-1||p1->math!=-1){
            if(p1->classroom==p2->classroom){
                if(p1->total<p2->total){
                    banji++;
                    p1->ClassRanking=banji;
                }
            }
            if(p1->total<p2->total){
                xiaoji++;
                p1->SchoolRanking=xiaoji;
            }
            p2=p2->next;
        }
        else{
            p1->ClassRanking=0;
            p1->SchoolRanking=0;
            break;
        }
    }
    return head1;
}
struct GraduateStudent *ranking_yanjiusheng(struct GraduateStudent *head2){
    struct GraduateStudent *p1,*p2,*p3;
    int i,j,banji,xiaoji,o;
    p3=head2;o=p3->num;
    while(p3->next!=NULL){
        p3=p3->next;o++;
    }
    p1=head2;
    for(i=head2->num;i<o;i++){
        p2=head2;
        banji=1;
        xiaoji=1;
        for(j=head2->num;j<o;j++){
            if(p1->ClassScore!=-1||p1->ThesisScore!=-1){
                if(p1->classroom==p2->classroom){
                    if(p1->total<p2->total){
                        banji++;
                        p1->ClassRanking=banji;
                    }
                }
                if(p1->total<p2->total){
                    xiaoji++;
                    p1->SchoolRanking=xiaoji;
                }
                p2=p2->next;
            }
            else {
                p1->ClassRanking=0;
                p1->SchoolRanking=0;
                break;
            }
        }
        p1=p1->next;
    }
    p2=head2;
    banji=1;
    xiaoji=1;
    for(j=head2->num;j<o;j++){
        if(p1->ClassScore!=-1||p1->ThesisScore!=-1){
            if(p1->classroom==p2->classroom){
                if(p1->total<p2->total){
                    banji++;
                    p1->ClassRanking=banji;
                }
            }
            if(p1->total<p2->total){
                xiaoji++;
                p1->SchoolRanking=xiaoji;
            }
            p2=p2->next;
        }
        else {
            p1->ClassRanking=0;
            p1->SchoolRanking=0;
            break;
        }
    }
    return head2;
}
void jisuan_output(){
    struct UnderGraduate *p1;
    struct GraduateStudent *p2;
    p1=head1;
    printf("学号    姓名    性别     专业  班级 数学 英语 C语言 总分 班级排名 校级排名\n");
    while(p1->next!=NULL){
        printf("%-8d%-8s",p1->num,p1->name);
        sex=(enum)p1->sex;
        switch(sex){
            case male:{
                printf("male     ");break;}
            case female:{
                printf("female   ");break;}
            default:{
                printf("未录入   ");break;}
        }
        printf("%-6s%d   %-5d%-5d%-5d%-5d%-4d%-4d\n",p1->major,p1->classroom,p1->math,p1->english,p1->C,p1->total,p1->ClassRanking,p1->SchoolRanking);
        p1=p1->next;
    }
    printf("%-8d%-8s",p1->num,p1->name);
    sex=(enum)p1->sex;
    switch(sex){
        case male:{
            printf("male     ");break;}
        case female:{
            printf("female   ");break;}
        default:{
            printf("未录入   ");break;}
    }
    printf("%-6s%d   %-5d%-5d%-5d%-5d%-4d%-4d\n",p1->major,p1->classroom,p1->math,p1->english,p1->C,p1->total,p1->ClassRanking,p1->SchoolRanking);
    p1=p1->next;
    p2=head2;
    printf("学号    姓名    性别     专业  班级   研究方向 导师 课程成绩 论文成绩 总分 班级排名 校级排名\n");
    while (p2->next!=NULL){
        printf("%-8d%-8s",p2->num,p2->name);
        sex=(enum)p2->sex;
        switch(sex){
            case male:{
                printf("male     ");break;}
            case female:{
                printf("female   ");break;}
            default:{
                printf("未录入    ");break;}
        }
        printf("%-6s%d   %-12s%-3s%-5d%-5d%-5d%-4d%-4d\n",p2->major,p2->classroom,p2->target,p2->tutor,p2->ClassScore,p2->ThesisScore,p2->total,p2->ClassRanking,p2->SchoolRanking);
        p2 = p2->next;
    }
    printf("%-8d%-8s",p2->num,p2->name);
    sex=(enum)p2->sex;
    switch(sex){
        case male:{
            printf("male     ");break;}
        case female:{
            printf("female   ");break;}
        default:{
            printf("未录入    ");break;}
    }
    printf("%-6s%d   %-12s%-3s%-5d%-5d%-5d%-4d%-4d\n",p2->major,p2->classroom,p2->target,p2->tutor,p2->ClassScore,p2->ThesisScore,p2->total,p2->ClassRanking,p2->SchoolRanking);
}
void jisuan_zongfen(){
    struct UnderGraduate *p1;
    struct GraduateStudent *p2;
    p1=head1;
    while(p1->next!=NULL){
        if(p1->C!=-1||p1->english!=-1||p1->math!=-1){
            p1->total=p1->C+p1->english+p1->math;
            p1=p1->next;
        }
        else {
            p1->total=-3;
            p1=p1->next;
        }
    }
    if(p1->C!=-1||p1->english!=-1||p1->math!=-1){
        p1->total=p1->C+p1->english+p1->math;
    }
    else {
        p1->total=-3;
    }
    p2=head2;
    while(p2->next!=NULL){
        if(p2->ClassScore!=-1||p2->ThesisScore!=-1){
            p2->total=p2->ClassScore+p2->ThesisScore;
            p2=p2->next;
        }
        else {
            p2->total=-2;
            p2=p2->next;
        }
    }
    if(p2->ClassScore!=-1||p2->ThesisScore!=-1){
        p2->total=p2->ClassScore+p2->ThesisScore;
        p2=p2->next;
    }
    else {
        p2->total=-2;
    }
}
/*==============================================================================*/
/*==============================================================================*/
/*==============================================================================*/
/*==============================================================================*/
/*==============================================================================*/
/*==============================================================================*/
/*==============================================================================*/
/*==============================================================================*/
/*==============================================================================*/
void query_UnderGraduate_class(void){
    struct UnderGraduate *p1;
    int classroom;
    p1=head1;
    printf("请输入要查找的班级号:");
    scanf("%d",&classroom);
    while(p1->next!=NULL){
        if(p1->classroom==classroom){
            printf("%-8d%-8s",p1->num,p1->name);
            sex=(enum)p1->sex;
            switch(sex){
                case male:{
                    printf("male     ");break;}
                case female:{
                    printf("female   ");break;}
                default:{
                    printf("未录入   ");break;}
            }
            printf("%-6s%d   %-5d%-5d%-5d%-5d%-4d%-4d\n",p1->major,p1->classroom,p1->math,p1->english,p1->C,p1->total,p1->ClassRanking,p1->SchoolRanking);
            p1=p1->next;
        }
        else p1=p1->next;
    }
    if(p1->classroom==classroom){
        printf("%-8d%-8s",p1->num,p1->name);
        sex=(enum)p1->sex;
        switch(sex){
            case male:{
                printf("male     ");break;}
            case female:{
                printf("female   ");break;}
            default:{
                printf("未录入   ");break;}
        }
        printf("%-6s%d   %-5d%-5d%-5d%-5d%-4d%-4d\n",p1->major,p1->classroom,p1->math,p1->english,p1->C,p1->total,p1->ClassRanking,p1->SchoolRanking);
    }
    printf("输出完毕...\n");
}
void query_UnderGraduate_name(void){
    struct UnderGraduate *p1;
    char name[20];
    p1=head1;
    printf("请输入要查找的姓名:");
    scanf("%s",name);
    while(p1->next!=NULL){
        if(strcmp(p1->name,name)==0){
            printf("%-8d%-8s",p1->num,p1->name);
            sex=(enum)p1->sex;
            switch(sex){
                case male:{
                    printf("male     ");break;}
                case female:{
                    printf("female   ");break;}
                default:{
                    printf("未录入   ");break;}
            }
            printf("%-6s%d   %-5d%-5d%-5d%-5d%-4d%-4d\n",p1->major,p1->classroom,p1->math,p1->english,p1->C,p1->total,p1->ClassRanking,p1->SchoolRanking);
            p1=p1->next;
        }
        else p1=p1->next;
        }
        if(strcmp(p1->name,name)==0){
        printf("%-8d%-8s",p1->num,p1->name);
        sex=(enum)p1->sex;
        switch(sex){
            case male:{
                printf("male     ");break;}
            case female:{
                printf("female   ");break;}
            default:{
                printf("未录入   ");break;}
        }
        printf("%-6s%d   %-5d%-5d%-5d%-5d%-4d%-4d\n",p1->major,p1->classroom,p1->math,p1->english,p1->C,p1->total,p1->ClassRanking,p1->SchoolRanking);
    }
    printf("输出完毕...\n");
}
void query_UnderGraduate_C_fail(void){
    struct UnderGraduate *p1;
    p1=head1;
    while(p1->next!=NULL){
        if(p1->C<60&&p1->C!=-1){
            printf("%-8d%-8s",p1->num,p1->name);
            sex=(enum)p1->sex;
            switch(sex){
                case male:{
                    printf("male     ");break;}
                case female:{
                    printf("female   ");break;}
                default:{
                    printf("未录入   ");break;}
            }
            printf("%-6s%d   %-5d%-5d%-5d%-5d%-4d%-4d\n",p1->major,p1->classroom,p1->math,p1->english,p1->C,p1->total,p1->ClassRanking,p1->SchoolRanking);
            p1=p1->next;
        }
        else p1=p1->next;
    }
    if(p1->C<60&&p1->C!=-1){
        printf("%-8d%-8s",p1->num,p1->name);
        sex=(enum)p1->sex;
        switch(sex){
            case male:{
                printf("male     ");break;}
            case female:{
                printf("female   ");break;}
            default:{
                printf("未录入   ");break;}
        }
        printf("%-6s%d   %-5d%-5d%-5d%-5d%-4d%-4d\n",p1->major,p1->classroom,p1->math,p1->english,p1->C,p1->total,p1->ClassRanking,p1->SchoolRanking);
    }
    printf("输出完毕...\n");
}
void query_UnderGraduate_english_fail(void){
    struct UnderGraduate *p1;
    p1=head1;
    while(p1->next!=NULL){
        if(p1->english<60&&p1->english!=-1){
            printf("%-8d%-8s",p1->num,p1->name);
            sex=(enum)p1->sex;
            switch(sex){
                case male:{
                    printf("male     ");break;}
                case female:{
                    printf("female   ");break;}
                default:{
                    printf("未录入   ");break;}
            }
            printf("%-6s%d   %-5d%-5d%-5d%-5d%-4d%-4d\n",p1->major,p1->classroom,p1->math,p1->english,p1->C,p1->total,p1->ClassRanking,p1->SchoolRanking);
            p1=p1->next;
        }
        else p1=p1->next;
    }
    if(p1->english<60&&p1->english!=-1){
        printf("%-8d%-8s",p1->num,p1->name);
        sex=(enum)p1->sex;
        switch(sex){
            case male:{
                printf("male     ");break;}
            case female:{
                printf("female   ");break;}
            default:{
                printf("未录入   ");break;}
        }
        printf("%-6s%d   %-5d%-5d%-5d%-5d%-4d%-4d\n",p1->major,p1->classroom,p1->math,p1->english,p1->C,p1->total,p1->ClassRanking,p1->SchoolRanking);
    }
    printf("输出完毕...\n");
}
void query_UnderGraduate_math_fail(void){
    struct UnderGraduate *p1;
    p1=head1;
    while(p1->next!=NULL){
        if(p1->math<60&&p1->math!=-1){
            printf("%-8d%-8s",p1->num,p1->name);
            sex=(enum)p1->sex;
            switch(sex){
                case male:{
                    printf("male     ");break;}
                case female:{
                    printf("female   ");break;}
                default:{
                    printf("未录入   ");break;}
            }
            printf("%-6s%d   %-5d%-5d%-5d%-5d%-4d%-4d\n",p1->major,p1->classroom,p1->math,p1->english,p1->C,p1->total,p1->ClassRanking,p1->SchoolRanking);
            p1=p1->next;
        }
        else p1=p1->next;
    }
    if(p1->math<60&&p1->math!=-1){
        printf("%-8d%-8s",p1->num,p1->name);
        sex=(enum)p1->sex;
        switch(sex){
            case male:{
                printf("male     ");break;}
            case female:{
                printf("female   ");break;}
            default:{
                printf("未录入   ");break;}
        }
        printf("%-6s%d   %-5d%-5d%-5d%-5d%-4d%-4d\n",p1->major,p1->classroom,p1->math,p1->english,p1->C,p1->total,p1->ClassRanking,p1->SchoolRanking);
    }
    printf("输出完毕...\n");
}
void query_GraduateStudent_class(void){
    struct GraduateStudent *p1;
    int classroom;
    p1=head2;
    printf("请输入要查找的班级号:");
    scanf("%d",&classroom);
    while(p1->next!=NULL){
        if(p1->classroom==classroom){
            printf("%-8d%-8s",p1->num,p1->name);
            sex=(enum)p1->sex;
            switch(sex){
                case male:{
                    printf("male     ");break;}
                case female:{
                    printf("female   ");break;}
                default:{
                    printf("未录入    ");break;}
            }
            printf("%-6s%d   %-12s%-3s%-5d%-5d%-5d%-4d%-4d\n",p1->major,p1->classroom,p1->target,p1->tutor,p1->ClassScore,p1->ThesisScore,p1->total,p1->ClassRanking,p1->SchoolRanking);
            p1=p1->next;
        }
        else
            p1=p1->next;
    }
    if(p1->classroom==classroom){
    printf("%-8d%-8s",p1->num,p1->name);
    sex=(enum)p1->sex;
    switch(sex){
        case male:{
            printf("male     ");break;}
        case female:{
            printf("female   ");break;}
        default:{
            printf("未录入    ");break;}
        }
    printf("%-6s%d   %-12s%-3s%-5d%-5d%-5d%-4d%-4d\n",p1->major,p1->classroom,p1->target,p1->tutor,p1->ClassScore,p1->ThesisScore,p1->total,p1->ClassRanking,p1->SchoolRanking);
    }
    printf("输出完毕...\n");
}
void query_GraduateStudent_name(void){
    struct GraduateStudent *p1;
    char name[20];
    p1=head2;
    printf("请输入要查找的姓名:");
    scanf("%s",name);
    while(p1->next!=NULL){
        if(strcmp(p1->name,name)==0){
            printf("%-8d%-8s",p1->num,p1->name);
            sex=(enum)p1->sex;
            switch(sex){
                case male:{
                    printf("male     ");break;}
                case female:{
                    printf("female   ");break;}
                default:{
                    printf("未录入    ");break;}
            }
            printf("%-6s%d   %-12s%-3s%-5d%-5d%-5d%-4d%-4d\n",p1->major,p1->classroom,p1->target,p1->tutor,p1->ClassScore,p1->ThesisScore,p1->total,p1->ClassRanking,p1->SchoolRanking);
            p1=p1->next;
        }
        else p1=p1->next;
    }
    if(strcmp(p1->name,name)==0){
        printf("%-8d%-8s",p1->num,p1->name);
        sex=(enum)p1->sex;
        switch(sex){
            case male:{
                printf("male     ");break;}
            case female:{
                printf("female   ");break;}
            default:{
                printf("未录入    ");break;}
        }
        printf("%-6s%d   %-12s%-3s%-5d%-5d%-5d%-4d%-4d\n",p1->major,p1->classroom,p1->target,p1->tutor,p1->ClassScore,p1->ThesisScore,p1->total,p1->ClassRanking,p1->SchoolRanking);
    }
    printf("输出完毕...\n");
}
void query_GraduateStudent_ClassScore_fail(void){
    struct GraduateStudent *p1;
    p1=head2;
    while(p1->next!=NULL){
        if(p1->ClassScore<60&&p1->ClassScore!=-1){
            printf("%-8d%-8s",p1->num,p1->name);
            sex=(enum)p1->sex;
            switch(sex){
                case male:{
                    printf("male     ");break;}
                case female:{
                    printf("female   ");break;}
                default:{
                    printf("未录入    ");break;}
            }
            printf("%-6s%d   %-12s%-3s%-5d%-5d%-5d%-4d%-4d\n",p1->major,p1->classroom,p1->target,p1->tutor,p1->ClassScore,p1->ThesisScore,p1->total,p1->ClassRanking,p1->SchoolRanking);
            p1=p1->next;
        }
        else
            p1=p1->next;
    }
    if(p1->ClassScore<60&&p1->ClassScore!=-1){
        printf("%-8d%-8s",p1->num,p1->name);
        sex=(enum)p1->sex;
        switch(sex){
            case male:{
                printf("male     ");break;}
            case female:{
                printf("female   ");break;}
            default:{
                printf("未录入    ");break;}
        }
        printf("%-6s%d   %-12s%-3s%-5d%-5d%-5d%-4d%-4d\n",p1->major,p1->classroom,p1->target,p1->tutor,p1->ClassScore,p1->ThesisScore,p1->total,p1->ClassRanking,p1->SchoolRanking);
    }
    printf("输出完毕...\n");
}
void query_GraduateStudent_ThesisScore_fail(void){
    struct GraduateStudent *p1;
    p1=head2;
    while(p1->next!=NULL){
        if(p1->ThesisScore<60&&p1->ThesisScore!=-1){
            printf("%-8d%-8s",p1->num,p1->name);
            sex=(enum)p1->sex;
            switch(sex){
                case male:{
                    printf("male     ");break;}
                case female:{
                    printf("female   ");break;}
                default:{
                    printf("未录入    ");break;}
            }
            printf("%-6s%d   %-12s%-3s%-5d%-5d%-5d%-4d%-4d\n",p1->major,p1->classroom,p1->target,p1->tutor,p1->ClassScore,p1->ThesisScore,p1->total,p1->ClassRanking,p1->SchoolRanking);
            p1=p1->next;
        }
        else
            p1=p1->next;
    }
    if(p1->ThesisScore<60&&p1->ThesisScore!=-1){
        printf("%-8d%-8s",p1->num,p1->name);
        sex=(enum)p1->sex;
        switch(sex){
            case male:{
                printf("male     ");break;}
            case female:{
                printf("female   ");break;}
            default:{
                printf("未录入    ");break;}
        }
        printf("%-6s%d   %-12s%-3s%-5d%-5d%-5d%-4d%-4d\n",p1->major,p1->classroom,p1->target,p1->tutor,p1->ClassScore,p1->ThesisScore,p1->total,p1->ClassRanking,p1->SchoolRanking);
    }
    printf("输出完毕...\n");
}
void query_page(){
    struct UnderGraduate *p1;
    struct GraduateStudent *p2;
    int sel;
    zongxuesheng=0;
    benkesheng=0;
    p1=head1;p2=head2;
    while(p1->next!=NULL){
        zongxuesheng++;
        benkesheng++;
        p1=p1->next;
    }
    benkesheng++;
    zongxuesheng++;
    while(p2->next!=NULL){
        zongxuesheng++;
        p2=p2->next;
    }
    p1=head1;p2=head2;
    zongye=(zongxuesheng-1)/10;
    zongye++;
    dangqianye=1;
    while(sel!=0){
        if(dangqianye==1)
            sel=query_page_shouye();
        else if(dangqianye==zongye)
            sel=query_page_weiye();
        else
            sel=query_page_putongye();
    }
}

int query_page_putongye(){
    struct UnderGraduate *p1;
    struct GraduateStudent *p2;
    int i,j,linshiye,linshixuesheng,sel;
    p1=head1;p2=head2;
    linshiye=dangqianye-1;
    linshixuesheng=linshiye*10;
    if(linshixuesheng<benkesheng){
        for(i=0;i<=linshixuesheng-1;i++)
            p1=p1->next;
    }
    else{
        for(i=0;i<benkesheng-1;i++)
            p1=p1->next;
        for(i=0;i<linshixuesheng-benkesheng;i++)
            p2=p2->next;
    }
    if(benkesheng>linshixuesheng+1)
        printf("学号    姓名    性别     专业  班级 数学 英语 C语言 总分 班级排名 校级排名\n");
    printf("=============================================学生成绩===============================================\n");
    for(i=linshixuesheng;i<dangqianye*10;i++){
        if(benkesheng>i){
            printf("%-8d%-8s",p1->num,p1->name);
            sex=(enum)p1->sex;
            switch(sex){
                case male:{
                    printf("male     ");break;}
                case female:{
                    printf("female   ");break;}
                default:{
                    printf("未录入   ");break;}
            }
            printf("%-6s%d   %-5d%-5d%-5d%-5d%-4d%-4d\n",p1->major,p1->classroom,p1->math,p1->english,p1->C,p1->total,p1->ClassRanking,p1->SchoolRanking);
            p1=p1->next;
        }
        else{
            if(benkesheng==i)
                printf("学号    姓名    性别     专业  班级   研究方向 导师 课程成绩 论文成绩 总分 班级排名 校级排名\n");
            for(j=i;j<dangqianye*10;j++){
                printf("%-8d%-8s",p2->num,p2->name);
                sex=(enum)p2->sex;
                switch(sex){
                    case male:{
                        printf("male     ");break;}
                    case female:{
                        printf("female   ");break;}
                    default:{
                        printf("未录入    ");break;}
                }
                printf("%-6s%d   %-12s%-3s%-5d%-5d%-5d%-4d%-4d\n",p2->major,p2->classroom,p2->target,p2->tutor,p2->ClassScore,p2->ThesisScore,p2->total,p2->ClassRanking,p2->SchoolRanking);
                p2=p2->next;
            }
            break;
        }
    }
    printf("================================================================================================\n");
    printf("第%d/%d页\n",dangqianye,zongye);
    printf("1.上一页                  2.下一页\n");
    printf("3.首页                    4.尾页\n");
    printf("0.退出查询\n");
    printf("请选择功能:\n");
    scanf("%d",&sel);
    switch(sel){
        case 1:
            dangqianye--;
            break;
        case 2:
            dangqianye++;
            break;
        case 3:
            dangqianye=1;
            break;
        case 4:
            dangqianye=zongye;
        default :
            break;
    }
    return sel;
}
int query_page_weiye(){
    struct UnderGraduate *p1;
    struct GraduateStudent *p2;
    int i,j,linshiye,linshixuesheng,sel;
    p1=head1;p2=head2;
    linshiye=zongye-1;
    linshixuesheng=linshiye*10;
    if(linshixuesheng<benkesheng){
        for(i=0;i<=linshixuesheng-1;i++)
            p1=p1->next;
    }
    else{
        for(i=0;i<benkesheng-1;i++)
            p1=p1->next;
        for(i=0;i<linshixuesheng-benkesheng;i++)
            p2=p2->next;
    }
    if(benkesheng>linshixuesheng+1)
        printf("学号    姓名    性别     专业  班级 数学 英语 C语言 总分 班级排名 校级排名\n");
    printf("=============================================学生成绩===============================================\n");
    for(i=linshixuesheng;i<zongxuesheng+1;i++){
        if(benkesheng>i){
            printf("%-8d%-8s",p1->num,p1->name);
            sex=(enum)p1->sex;
            switch(sex){
                case male:{
                    printf("male     ");break;}
                case female:{
                    printf("female   ");break;}
                default:{
                    printf("未录入   ");break;}
            }
            printf("%-6s%d   %-5d%-5d%-5d%-5d%-4d%-4d\n",p1->major,p1->classroom,p1->math,p1->english,p1->C,p1->total,p1->ClassRanking,p1->SchoolRanking);
            p1=p1->next;
        }
        else{
            if(benkesheng==i)
                printf("学号    姓名    性别     专业  班级   研究方向 导师 课程成绩 论文成绩 总分 班级排名 校级排名\n");
            for(j=i;j<zongxuesheng+1;j++){
                printf("%-8d%-8s",p2->num,p2->name);
                sex=(enum)p2->sex;
                switch(sex){
                    case male:{
                        printf("male     ");break;}
                    case female:{
                        printf("female   ");break;}
                    default:{
                        printf("未录入    ");break;}
                }
                printf("%-6s%d   %-12s%-3s%-5d%-5d%-5d%-4d%-4d\n",p2->major,p2->classroom,p2->target,p2->tutor,p2->ClassScore,p2->ThesisScore,p2->total,p2->ClassRanking,p2->SchoolRanking);
                p2=p2->next;
            }
            break;
        }
    }
    printf("================================================================================================\n");
    printf("第%d/%d页\n",dangqianye,zongye);
    printf("1.上一页                  2.首页\n");
    printf("0.退出查询\n");
    printf("请选择功能:\n");
    scanf("%d",&sel);
    switch(sel){
        case 1:
            dangqianye--;
            break;
        case 2:
            dangqianye=1;
            break;
        default :
            break;
    }
    return sel;
}
int query_page_shouye(void){
    struct UnderGraduate *p1;
    struct GraduateStudent *p2;
    int i,j,sel;
    p1=head1;p2=head2;
    printf("===============================================学生成绩==============================================\n");
    printf("学号    姓名    性别     专业  班级 数学 英语 C语言 总分 班级排名 校级排名\n");
    for(i=0;i<10;i++){
        if(p1->next==NULL){
            printf("%-8d%-8s",p1->num,p1->name);
            sex=(enum)p1->sex;
            switch(sex){
                case male:{
                    printf("male     ");break;}
                case female:{
                    printf("female   ");break;}
                default:{
                    printf("未录入   ");break;}
            }
            printf("%-6s%d   %-5d%-5d%-5d%-5d%-4d%-4d\n",p1->major,p1->classroom,p1->math,p1->english,p1->C,p1->total,p1->ClassRanking,p1->SchoolRanking);
            printf("学号    姓名    性别     专业  班级   研究方向 导师 课程成绩 论文成绩 总分 班级排名 校级排名\n");
            for(j=i;j<10;j++){
                printf("%-8d%-8s",p2->num,p2->name);
                sex=(enum)p2->sex;
                switch(sex){
                    case male:{
                        printf("male     ");break;}
                    case female:{
                        printf("female   ");break;}
                    default:{
                        printf("未录入    ");break;}
                }
                printf("%-6s%d   %-12s%-3s%-5d%-5d%-5d%-4d%-4d\n",p2->major,p2->classroom,p2->target,p2->tutor,p2->ClassScore,p2->ThesisScore,p2->total,p2->ClassRanking,p2->SchoolRanking);
                p2=p2->next;
            }
            break;
        }
        else{
            printf("%-8d%-8s",p1->num,p1->name);
            sex=(enum)p1->sex;
            switch(sex){
                case male:{
                    printf("male     ");break;}
                case female:{
                    printf("female   ");break;}
                default:{
                    printf("未录入   ");break;}
            }
            printf("%-6s%d   %-5d%-5d%-5d%-5d%-4d%-4d\n",p1->major,p1->classroom,p1->math,p1->english,p1->C,p1->total,p1->ClassRanking,p1->SchoolRanking);
            p1=p1->next;
        }
    }
        printf("==================================================================================================\n");
        printf("第%d/%d页\n",dangqianye,zongye);
        printf("1.下一页                  2.尾页\n");
        printf("0.退出查询\n");
        printf("请选择功能:\n");
        scanf("%d",&sel);
        switch(sel){
            case 1:
                dangqianye++;
                break;
            case 2:
                dangqianye=zongye;
                break;
            default :
                break;
        }
        return sel;
}
/*==============================================================================*/
/*==============================================================================*/
/*==============================================================================*/
/*==============================================================================*/
/*==============================================================================*/
/*==============================================================================*/
/*==============================================================================*/
/*==============================================================================*/
/*==============================================================================*/
void paixu_all(){
    struct UnderGraduate *p1,*p2;
    struct GraduateStudent *p3,*p4;
    int i,j,temp1;
    char temp2[20];
    int zongxuesheng=0,benkesheng=0;
    p1=head1;p3=head2;
    while(p1->next!=NULL){
        zongxuesheng++;
        benkesheng++;
        p1=p1->next;
    }
    benkesheng++;
    zongxuesheng++;
    while(p3->next!=NULL){
        zongxuesheng++;
        p3=p3->next;
    }
    zongxuesheng++;
    p2=head1;p1=p2->next;
    for(i=1;i<benkesheng;i++){
        if(i>1) {p2=p2->next;p1=p2->next;}
        for(j=i;j<benkesheng;j++)
        {
            if(p1->total>p2->total){
                temp1=p2->num;p2->num=p1->num;p1->num=temp1;
                strcpy(temp2,p2->name);strcpy(p2->name,p1->name);strcpy(p1->name,temp2);
                temp1=p2->sex;p2->sex=p1->sex;p1->sex=temp1;
                strcpy(temp2,p2->major);strcpy(p2->major,p1->major);strcpy(p1->major,temp2);
                temp1=p2->classroom;p2->classroom=p1->classroom;p1->classroom=temp1;
                temp1=p2->math;p2->math=p1->math;p1->math=temp1;
                temp1=p2->english;p2->english=p1->english;p1->english=temp1;
                temp1=p2->C;p2->C=p1->C;p1->C=temp1;
                temp1=p2->total;p2->total=p1->total;p1->total=temp1;
                temp1=p2->ClassRanking;p2->ClassRanking=p1->ClassRanking;p1->ClassRanking=temp1;
                temp1=p2->SchoolRanking;p2->SchoolRanking=p1->SchoolRanking;p1->SchoolRanking=temp1;
            }
            if(p1->next==NULL)break;
            p1=p1->next;
        }
    }
    p4=head2;p3=p4->next;
    for(i=1;i<zongxuesheng-benkesheng;i++){
        if(i>1) {p4=p4->next;p3=p4->next;}
        for(j=i;j<zongxuesheng-benkesheng;j++)
        {
            if(p3->total>p4->total){
                temp1=p4->num;p4->num=p3->num;p3->num=temp1;
                strcpy(temp2,p4->name);strcpy(p4->name,p3->name);strcpy(p3->name,temp2);
                temp1=p3->sex;p4->sex=p3->sex;p3->sex=temp1;
                strcpy(temp2,p4->major);strcpy(p4->major,p3->major);strcpy(p3->major,temp2);
                temp1=p4->classroom;p4->classroom=p3->classroom;p3->classroom=temp1;
                strcpy(temp2,p4->target);strcpy(p4->target,p3->target);strcpy(p3->target,temp2);
                strcpy(temp2,p4->tutor);strcpy(p4->tutor,p3->tutor);strcpy(p3->tutor,temp2);
                temp1=p4->ThesisScore;p4->ThesisScore=p3->ThesisScore;p3->ThesisScore=temp1;
                temp1=p4->ClassScore;p4->ClassScore=p3->ClassScore;p3->ClassScore=temp1;
                temp1=p4->total;p4->total=p3->total;p3->total=temp1;
                temp1=p4->ClassRanking;p4->ClassRanking=p3->ClassRanking;p3->ClassRanking=temp1;
                temp1=p4->SchoolRanking;p4->SchoolRanking=p3->SchoolRanking;p3->SchoolRanking=temp1;
            }
            if(p3->next==NULL)break;
            p3=p3->next;
        }
    }
    printf("排序完毕");
}
void paixu_class_benkesheng(){
    struct UnderGraduate *p1,*p2;
    int i,j,temp1;
    char temp2[20];
    int benkesheng=0,sel,banji=1;
    p1=head1;
    while(p1->next!=NULL){
        benkesheng++;
        p1=p1->next;
    }
    benkesheng++;
    p2=head1;p1=p2->next;
    for(i=1;i<benkesheng;i++){
        if(i>1) {p2=p2->next;p1=p2->next;}
        for(j=i;j<benkesheng;j++)
        {
            if(p1->classroom==p2->classroom&&p1->total>p2->total){
                temp1=p2->num;p2->num=p1->num;p1->num=temp1;
                strcpy(temp2,p2->name);strcpy(p2->name,p1->name);strcpy(p1->name,temp2);
                temp1=p2->sex;p2->sex=p1->sex;p1->sex=temp1;
                strcpy(temp2,p2->major);strcpy(p2->major,p1->major);strcpy(p1->major,temp2);
                temp1=p2->classroom;p2->classroom=p1->classroom;p1->classroom=temp1;
                temp1=p2->math;p2->math=p1->math;p1->math=temp1;
                temp1=p2->english;p2->english=p1->english;p1->english=temp1;
                temp1=p2->C;p2->C=p1->C;p1->C=temp1;
                temp1=p2->total;p2->total=p1->total;p1->total=temp1;
                temp1=p2->ClassRanking;p2->ClassRanking=p1->ClassRanking;p1->ClassRanking=temp1;
                temp1=p2->SchoolRanking;p2->SchoolRanking=p1->SchoolRanking;p1->SchoolRanking=temp1;
            }
            if(p1->next==NULL)break;
            p1=p1->next;
        }
    }
    p1=head1;
    printf("是否需要输出每个班的排名顺序？\n");
    printf("1.是     2.否\n");
    scanf("%d",&sel);
    switch(sel){
        case 1:
            for(i=0;i<benkesheng;i++){
            for(j=0;j<benkesheng;j++){
                if(p1->classroom==banji){
                printf("%-8d%-8s",p1->num,p1->name);
                sex=(enum)p1->sex;
                switch(sex){
                    case male:{
                        printf("male     ");break;}
                    case female:{
                        printf("female   ");break;}
                    default:{
                        printf("未录入   ");break;}
                }
                printf("%-6s%d   %-5d%-5d%-5d%-5d%-4d%-4d\n",p1->major,p1->classroom,p1->math,p1->english,p1->C,p1->total,p1->ClassRanking,p1->SchoolRanking);
                }
                p1=p1->next;
            }
            p1=head1;
            banji++;
        }
            break;
        case 2:
            break;
    }
}
void paixu_class_yanjiusheng(){
    struct GraduateStudent *p3,*p4;
    int yanjiusheng=0,banji=1;
    int i,j,temp1,sel;
    char temp2[20];
    p3=head2;
    while(p3->next!=NULL){
        yanjiusheng++;
        p3=p3->next;
    }
    yanjiusheng++;
    p4=head2;p3=p4->next;
    for(i=1;i<yanjiusheng;i++){
        if(i>1) {p4=p4->next;p3=p4->next;}
        for(j=i;j<yanjiusheng;j++)
        {
            if(p3->total>p4->total&&p3->classroom==p4->classroom){
                temp1=p4->num;p4->num=p3->num;p3->num=temp1;
                strcpy(temp2,p4->name);strcpy(p4->name,p3->name);strcpy(p3->name,temp2);
                temp1=p3->sex;p4->sex=p3->sex;p3->sex=temp1;
                strcpy(temp2,p4->major);strcpy(p4->major,p3->major);strcpy(p3->major,temp2);
                temp1=p4->classroom;p4->classroom=p3->classroom;p3->classroom=temp1;
                strcpy(temp2,p4->target);strcpy(p4->target,p3->target);strcpy(p3->target,temp2);
                strcpy(temp2,p4->tutor);strcpy(p4->tutor,p3->tutor);strcpy(p3->tutor,temp2);
                temp1=p4->ThesisScore;p4->ThesisScore=p3->ThesisScore;p3->ThesisScore=temp1;
                temp1=p4->ClassScore;p4->ClassScore=p3->ClassScore;p3->ClassScore=temp1;
                temp1=p4->total;p4->total=p3->total;p3->total=temp1;
                temp1=p4->ClassRanking;p4->ClassRanking=p3->ClassRanking;p3->ClassRanking=temp1;
                temp1=p4->SchoolRanking;p4->SchoolRanking=p3->SchoolRanking;p3->SchoolRanking=temp1;
            }
            if(p3->next==NULL)break;
            p3=p3->next;
        }
    }
    p3=head2;
    printf("是否需要输出每个班的排名顺序？\n");
    printf("1.是     2.否\n");
    scanf("%d",&sel);
    switch(sel){
        case 1:
            for(i=0;i<yanjiusheng;i++){
                for(j=0;j<yanjiusheng;j++){
                    if(p3->classroom==banji){
                        printf("%-8d%-8s",p3->num,p3->name);
                        sex=(enum)p3->sex;
                        switch(sex){
                            case male:{
                                printf("male     ");break;}
                            case female:{
                                printf("female   ");break;}
                            default:{
                                printf("未录入    ");break;}
                        }
                        printf("%-6s%d   %-12s%-3s%-5d%-5d%-5d%-4d%-4d\n",p3->major,p3->classroom,p3->target,p3->tutor,p3->ClassScore,p3->ThesisScore,p3->total,p3->ClassRanking,p3->SchoolRanking);
                    }
                    p3=p3->next;
                }
                p3=head2;
                banji++;
            }
            break;
        case 2:
            break;
    }
}
/*==============================================================================*/
/*==============================================================================*/
/*==============================================================================*/
/*==============================================================================*/
/*==============================================================================*/
/*==============================================================================*/
/*==============================================================================*/
/*==============================================================================*/
/*==============================================================================*/
void tongji_benke_banji(void){
    struct UnderGraduate *p1;
    float C=0,english=0,math=0;
    int classshu=0,i,member=0;
    p1=head1;
    while(p1->next!=NULL){
        if(p1->classroom>classshu)classshu++;
        p1=p1->next;
    }
    p1=head1;
    for(i=1;i<=classshu;i++){
        while(p1->next!=NULL){
            if(p1->classroom==i&&p1->C!=-1&&p1->math!=-1&&p1->english!=-1){
                C=C+p1->C;
                english=english+p1->english;
                math=math+p1->math;
                member++;
                }
                p1=p1->next;
            }
            if(p1->classroom==i&&p1->C!=-1&&p1->math!=-1&&p1->english!=-1){
            C=C+p1->C;
            english=english+p1->english;
            math=math+p1->math;
            member++;
            }
        printf("第%d个班级的平均成绩:\n",i);
        printf("高数:%f        英语:%f        C语言:%f\n",math/member,english/member,C/member);
        C=0;english=0;math=0;member=0;
        p1=head1;
    }
    printf("统计完毕...\n");
}
void tongji_benke_dengji(void){
    struct UnderGraduate *p1;
    int i;
    int C1=0,C2=0,C3=0,C4=0,C5=0;
    int english1=0,english2=0,english3=0,english4=0,english5=0;
    int math1=0,math2=0,math3=0,math4=0,math5=0;
    int classshu=0;
    p1=head1;
    while(p1->next!=NULL){
        if(p1->classroom>classshu)classshu++;
        p1=p1->next;
    }
    p1=head1;
    for(i=1;i<=classshu;i++){
        while(p1->next!=NULL){
            if(p1->classroom==i){
                if(p1->C>=90&&p1->C<=100)
                    C1++;
                if(p1->C>=80&&p1->C<90)
                    C2++;
                if(p1->C>=70&&p1->C<80)
                    C3++;
                if(p1->C>=60&&p1->C<70)
                    C4++;
                if(p1->C>=0&&p1->C<60)
                    C5++;
                if(p1->english>=90&&p1->english<=100)
                    english1++;
                if(p1->english>=80&&p1->english<90)
                    english2++;
                if(p1->english>=70&&p1->english<80)
                    english3++;
                if(p1->english>=60&&p1->english<70)
                    english4++;
                if(p1->english>=0&&p1->english<60)
                    english5++;
                if(p1->math>=90&&p1->math<=100)
                    math1++;
                if(p1->math>=80&&p1->math<90)
                    math2++;
                if(p1->math>=70&&p1->math<80)
                    math3++;
                if(p1->math>=60&&p1->math<70)
                    math4++;
                if(p1->math>=0&&p1->math<60)
                    math5++;
            }
            p1=p1->next;
        }
        if(p1->classroom==i){
            if(p1->C>=90&&p1->C<=100)
                C1++;
            if(p1->C>=80&&p1->C<90)
                C2++;
            if(p1->C>=70&&p1->C<80)
                C3++;
            if(p1->C>=60&&p1->C<70)
                C4++;
            if(p1->C>=0&&p1->C<60)
                C5++;
            if(p1->english>=90&&p1->english<=100)
                english1++;
            if(p1->english>=80&&p1->english<90)
                english2++;
            if(p1->english>=70&&p1->english<80)
                english3++;
            if(p1->english>=60&&p1->english<70)
                english4++;
            if(p1->english>=0&&p1->english<60)
                english5++;
            if(p1->math>=90&&p1->math<=100)
                math1++;
            if(p1->math>=80&&p1->math<90)
                math2++;
            if(p1->math>=70&&p1->math<80)
                math3++;
            if(p1->math>=60&&p1->math<70)
                math4++;
            if(p1->math>=0&&p1->math<60)
                math5++;
        }
        printf("第%d个班级的各科等级:\n",i);
        printf("高数:\n");
        printf("优:%d   良：%d  中:%d  及格:%d  不及格:%d\n",math1,math2,math3,math4,math5);
        printf("英语:\n");
        printf("优:%d   良：%d  中:%d  及格:%d  不及格:%d\n",english1,english2,english3,english4,english5);
        printf("C语言:\n");
        printf("优:%d   良：%d  中:%d  及格:%d  不及格:%d\n",C1,C2,C3,C4,C5);
        C1=0;C2=0;C3=0;C4=0;C5=0;
        english1=0;english2=0;english3=0;english4=0;english5=0;
        math1=0;math2=0;math3=0;math4=0;math5=0;
        p1=head1;
    }
    printf("统计完毕...\n");
}
void tongji_yanjiu_banji(void){
    struct GraduateStudent *p1;
    float ThesisScore=0,ClassScore=0;
    int classshu=0,i,member=0;
    p1=head2;
    while(p1->next!=NULL){
        if(p1->classroom>classshu)classshu++;
        p1=p1->next;
    }
    p1=head2;
    for(i=1;i<=classshu;i++){
        while(p1->next!=NULL){
            if(p1->classroom==i&&p1->ClassScore!=-1&&p1->ThesisScore!=-1){
                ThesisScore=ThesisScore+p1->ThesisScore;
                ClassScore=ClassScore+p1->ClassScore;
                member++;
                
            }
            p1=p1->next;
        }
        if(p1->classroom==i&&p1->ClassScore!=-1&&p1->ThesisScore!=-1){
            ThesisScore=ThesisScore+p1->ThesisScore;
            ClassScore=ClassScore+p1->ClassScore;
            member++;
        }
        printf("第%d个班级的平均成绩:\n",i);
        printf("课程综合成绩:%f        论文成绩:%f\n",ClassScore/member,ThesisScore/member);
        ThesisScore=0;ClassScore=0;member=0;
        p1=head2;
    }
    printf("统计完毕...\n");
}
void tongji_yanjiu_dengji(void){
    struct GraduateStudent *p1;
    int i;
    int ThesisScore1=0,ThesisScore2=0,ThesisScore3=0,ThesisScore4=0,ThesisScore5=0;
    int ClassScore1=0,ClassScore2=0,ClassScore3=0,ClassScore4=0,ClassScore5=0;
    int classshu=0;
    p1=head2;
    while(p1->next!=NULL){
        if(p1->classroom>classshu)classshu++;
        p1=p1->next;
    }
    p1=head2;
    for(i=1;i<=classshu;i++){
        while(p1->next!=NULL){
            if(p1->classroom==i){
                if(p1->ThesisScore>=90&&p1->ThesisScore<=100)
                    ThesisScore1++;
                if(p1->ThesisScore>=80&&p1->ThesisScore<90)
                    ThesisScore2++;
                if(p1->ThesisScore>=70&&p1->ThesisScore<80)
                    ThesisScore3++;
                if(p1->ThesisScore>=60&&p1->ThesisScore<70)
                    ThesisScore4++;
                if(p1->ThesisScore>=0&&p1->ThesisScore<60)
                    ThesisScore5++;
                if(p1->ClassScore>=90&&p1->ClassScore<=100)
                    ClassScore1++;
                if(p1->ClassScore>=80&&p1->ClassScore<90)
                    ClassScore2++;
                if(p1->ClassScore>=70&&p1->ClassScore<80)
                    ClassScore3++;
                if(p1->ClassScore>=60&&p1->ClassScore<70)
                    ClassScore4++;
                if(p1->ClassScore>=0&&p1->ClassScore<60)
                    ClassScore5++;
            }
            p1=p1->next;
        }
        if(p1->classroom==i){
            if(p1->ThesisScore>=90&&p1->ThesisScore<=100)
                ThesisScore1++;
            if(p1->ThesisScore>=80&&p1->ThesisScore<90)
                ThesisScore2++;
            if(p1->ThesisScore>=70&&p1->ThesisScore<80)
                ThesisScore3++;
            if(p1->ThesisScore>=60&&p1->ThesisScore<70)
                ThesisScore4++;
            if(p1->ThesisScore>=0&&p1->ThesisScore<60)
                ThesisScore5++;
            if(p1->ClassScore>=90&&p1->ClassScore<=100)
                ClassScore1++;
            if(p1->ClassScore>=80&&p1->ClassScore<90)
                ClassScore2++;
            if(p1->ClassScore>=70&&p1->ClassScore<80)
                ClassScore3++;
            if(p1->ClassScore>=60&&p1->ClassScore<70)
                ClassScore4++;
            if(p1->ClassScore>=0&&p1->ClassScore<60)
                ClassScore5++;
        }
        printf("第%d个班级的各科等级:\n",i);
        printf("课程综合成绩等级:\n");
        printf("优:%d   良：%d  中:%d  及格:%d  不及格:%d\n",ClassScore1,ClassScore2,ClassScore3,ClassScore4,ClassScore5);
        printf("论文成绩等级:\n");
        printf("优:%d   良：%d  中:%d  及格:%d  不及格%d\n",ThesisScore1,ThesisScore2,ThesisScore3,ThesisScore4,ThesisScore5);
        ThesisScore1=0;ThesisScore2=0;ThesisScore3=0;ThesisScore4=0;ThesisScore5=0;
        ClassScore1=0;ClassScore2=0;ClassScore3=0;ClassScore4=0;ClassScore5=0;
        p1=head2;
    }
    printf("统计完毕...\n");
}



















