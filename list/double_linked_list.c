#include <stdio.h>
#include <stdlib.h>

// TODO 이해 필요

typedef int element;
typedef struct DoublelistNode {
  element data;
  struct DoublelistNode *llink; // 자기참조. 선행 노드를 포인팅
  struct DoublelistNode *rlink; // 자기참조. 후속 노드를 포인팅
} DlistNode;

DlistNode *insert(DlistNode *pre, int value) {
  // create node
  DlistNode *inserted = (DlistNode *)malloc(sizeof(DlistNode));
  inserted->data = value;

  inserted->llink = pre;
  inserted->rlink = pre->rlink;
  pre->rlink->llink = inserted;
  pre->rlink = inserted;

  return inserted;
}

void remove_node(DlistNode *p_head_node, DlistNode *removed) {
  if (removed == p_head_node)
    return;
  // 선행 노드가 removed의 후행 노드를 서로 가리키도록
  removed->llink->rlink = removed->rlink;
  removed->rlink->llink = removed->llink;
  free(removed);
}
