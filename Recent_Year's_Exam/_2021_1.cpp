//
// Created by 10240 on 2024/10/27.
//

//2021年真题1
//把双向链表的每k个节点为一组进行反转，最后不足k的保持不变，最后返回翻转后的链表



/*
* 思路分析：
首先检查链表长度是否足够k个节点，不足则直接返回
每次找到k个节点的起点和终点
对这k个节点进行内部反转
处理与前一组和后一组的连接
移动到下一组继续处理
* 时间复杂度：O(n)，其中n是链表长度   每个节点最多被访问一次进行反转操作
空间复杂度：O(1)   只使用了常数个额外指针变量
*/

#include <stdio.h>

typedef struct DNode {
    int data;
    struct DNode *prior, *next;
} DNode, *DLinklist;

void reverseKGroup(DLinklist head, int k) {  // head是头结点
    if (!head || !head->next || k <= 1) return;  // 空表或只有一个节点或k<=1

    DNode *prev = head;  // 从头结点开始，prev指向待处理组的前一个节点

    while (prev->next) {  // 只要还有节点就继续检查
        // 1.检查剩余节点是否够k个
        DNode *end = prev;
        for (int i = 0; i < k; i++) {
            end = end->next;
            if (!end) {  // 不足k个，保持原样返回
                return;
            }
        }

        // 2.记录下一组的开始位置
        DNode *next_group = end->next;

        // 3.获取当前组的起点
        DNode *start = prev->next;

        // 4.断开与前后组的连接
        prev->next = end;
        if (next_group)
            next_group->prior = start;

        // 5.反转当前k个节点
        DNode *current = start;
        DNode *temp = NULL;
        for (int i = 0; i < k; i++) {
            temp = current->next;
            // 交换前后指针
            current->next = current->prior;
            current->prior = temp;
            current = temp;
        }

        // 6.重新连接与前后组的关系
        start->next = next_group;
        end->prior = prev;

        // 7.移动到下一组
        prev = start;
    }
}


/*简单的例子解释这个反转过程。假设我们要反转的是3个节点：1 ? 2 ? 3

1. 初始状态：
prev    current   temp
 ↓        ↓        ↓
[0] ? [1] ? [2] ? [3] ? [4]

2. 第一次循环(current在节点1):

temp = current->next;        // temp指向节点2
current->next = current->prior;  // 1的next指向prev(0)
current->prior = temp;       // 1的prior指向2
current = temp;             // current移动到2

变成：
     temp
prev  current
 ↓      ↓
[0] ← [1]   [2] ? [3] ? [4]
     ↘→
```

3. 第二次循环(current在节点2):
```
temp = current->next;        // temp指向节点3
current->next = current->prior;  // 2的next指向1
current->prior = temp;       // 2的prior指向3
current = temp;             // current移动到3

变成：
          temp
prev       current
 ↓          ↓
[0] ← [1] ← [2]   [3] ? [4]
     →     →
```

4. 第三次循环(current在节点3):
```
temp = current->next;        // temp指向节点4
current->next = current->prior;  // 3的next指向2
current->prior = temp;       // 3的prior指向4
current = temp;             // current移动到4

最终变成：
               temp
prev           current
 ↓               ↓
[0] ← [1] ← [2] ← [3]   [4]
     →     →     →
```

关键点说明：
1. temp用来保存下一个节点，防止断链
2. 每次循环做三件事：
   - 保存next节点避免丢失
   - 反转当前节点的指针方向
   - 移动到下一个节点继续处理

形象比喻：
- 就像翻转多米诺骨牌，每次翻转一个
- temp就像是一个标记，标记着下一个要处理的骨牌
- 每翻转一个，都需要改变它与前后骨牌的连接方向
*/