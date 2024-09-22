#include <stdio.h>
  
  int main() {
  FILE *fp; // 文件指针
  char ch; // 用于存储输入的字符
  
  // 打开一个名为data.txt的文件，以追加模式（"a"）写入
  fp = fopen("data.txt", "a");
  
  if (fp == NULL) {
  printf("无法打开文件。\n");
  return 1;
  }
  
  printf("请输入字符，直到输入'#'结束：\n");
  
  // 循环读取用户输入的字符，直到输入'#'为止
  while ((ch = getchar()) != '#') {
  // 将字符写入文件
  fputc(ch, fp);
  }
  
  // 关闭文件
  fclose(fp);
  
  printf("输入的内容已经保存到data.txt文件中。\n");
  
  return 0;
  }
/* #include <stdio.h>
  
  int main() {
  FILE *source_fp, *dest_fp; // 源文件和目标文件的文件指针
  char ch; // 用于存储读取的字符
  
  // 打开源文件file1.dat，以只读模式（"r"）打开
  source_fp = fopen("file1.dat", "r");
  
  if (source_fp == NULL) {
  printf("无法打开源文件。\n");
  return 1;
  }
  
  // 打开目标文件file2.dat，以写入模式（"w"）打开
  dest_fp = fopen("file2.dat", "w");
  
  if (dest_fp == NULL) {
  printf("无法创建目标文件。\n");
  fclose(source_fp);
  return 1;
  }
  
  // 从源文件读取字符，并逐个写入目标文件
  while ((ch = fgetc(source_fp)) != EOF) {
  fputc(ch, dest_fp);
  }
  
  // 关闭文件
  fclose(source_fp);
  fclose(dest_fp);
  
  printf("文件已成功复制。\n");
  
  return 0;
  }*/
/*#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  
  // 冒泡排序
  void bubbleSort(char *arr[], int n) {
  int i, j;
  char *temp;
  
  for (i = 0; i < n - 1; i++) {
  for (j = 0; j < n - i - 1; j++) {
  if (strcmp(arr[j], arr[j + 1]) > 0) {
  temp = arr[j];
  arr[j] = arr[j + 1];
  arr[j + 1] = temp;
  }
  }
  }
  }
  
  // 选择排序
  void selectionSort(char *arr[], int n) {
  int i, j, min_index;
  char *temp;
  
  for (i = 0; i < n - 1; i++) {
  min_index = i;
  for (j = i + 1; j < n; j++) {
  if (strcmp(arr[j], arr[min_index]) < 0) {
  min_index = j;
  }
  }
  if (min_index != i) {
  temp = arr[i];
  arr[i] = arr[min_index];
  arr[min_index] = temp;
  }
  }
  }
  
  int main() {
  int n, i;
  char **names;
  
  // 输入学生人数
  printf("请输入学生的人数：");
  scanf("%d", &n);
  getchar(); // 吸收换行符
  
  // 分配存储空间
  names = (char **)malloc(n * sizeof(char *));
  if (names == NULL) {
  printf("内存分配失败。\n");
  return 1;
  }
  
  // 输入学生姓名
  printf("请输入学生的姓名：\n");
  for (i = 0; i < n; i++) {
  names[i] = (char *)malloc(100 * sizeof(char));
  printf("姓名 %d: ", i + 1);
  fgets(names[i], 100, stdin);
  }
  
  // 冒泡排序
  bubbleSort(names, n);
  
  // 写入文件
  FILE *fp;
  fp = fopen("sorted_names.txt", "w");
  if (fp == NULL) {
  printf("无法创建文件。\n");
  return 1;
  }
  
  for (i = 0; i < n; i++) {
  fputs(names[i], fp);
  }
  
  fclose(fp);
  
  // 输出排序后的姓名到屏幕上
  printf("\n排序后的姓名：\n");
  for (i = 0; i < n; i++) {
  printf("%s", names[i]);
  }
  
  // 释放内存
  for (i = 0; i < n; i++) {
  free(names[i]);
  }
  free(names);
  
  return 0;
  }*/
/*#include <stdio.h>
  #include <stdlib.h>
  
  //定义学生结构体
  typedef struct {
  int id;
  char name[50];
  int age;
  } Student;
  
  int main() {
  FILE *file;
  Student students[5]; //保存5个学生的数组
  int i; //在循环外部声明变量
  
  //从键盘输入学生信息
  printf("请输入5个学生的信息：\n");
  for (i = 0; i < 5; i++) {
  printf("请输入第%d个学生的学号、姓名和年龄（用空格隔开）：", i+1);
  scanf("%d %s %d", &students[i].id, students[i].name, &students[i].age);
  }
  
  //将学生信息写入磁盘文件
  file = fopen("students.dat", "wb");
  if (file == NULL) {
  printf("无法打开文件。\n");
  exit(1);
  }
  fwrite(students, sizeof(Student), 5, file);
  fclose(file);
  
  //从磁盘文件中读取学生信息并输出到屏幕
  file = fopen("students.dat", "rb");
  if (file == NULL) {
  printf("无法打开文件。\n");
  exit(1);
  }
  printf("\n从文件中读取的学生信息：\n");
  fread(students, sizeof(Student), 5, file);
  for (i = 0; i < 5; i++) {
  printf("学号：%d, 姓名：%s, 年龄：%d\n", students[i].id, students[i].name, students[i].age);
  }
  fclose(file);
  
  return 0;
  }
 */
/*#include <stdio.h>
  #include <stdlib.h>
  
  // 定义学生结构体
  struct Student {
  char name[50];
  int age;
  float score;
  };
  
  int main() {
  FILE *fp;
  struct Student student;
  int i = 0;
  
  // 打开文件
  fp = fopen("stu.dat", "rb");
  if (fp == NULL) {
  printf("无法打开文件。\n");
  return 1;
  }
  
  // 读取并输出第1, 3, 5, 7, 9个学生的数据
  while (fread(&student, sizeof(struct Student), 1, fp) == 1) {
  i++;
  if (i == 1 || i == 3 || i == 5 || i == 7 || i == 9) {
  printf("姓名：%s\n", student.name);
  printf("年龄：%d\n", student.age);
  printf("分数：%.2f\n", student.score);
  printf("--------------------\n");
  }
  }
  
  // 关闭文件
  fclose(fp);
  
  return 0;
  }
