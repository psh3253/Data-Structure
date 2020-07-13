#ifndef __BINARY_TREE2_H__
#define __BINARY_TREE2_H__

typedef int BTData;

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;
} BTreeNode;

BTreeNode* MakeBTreeNode(void);
BTData GetData(BTreeNode* bt);
void SetData(BTreeNode* bt, BTData data);

BTreeNode* GetLeftSubTree(BTreeNode*);
BTreeNode* GetRightSubTree(BTreeNode*);

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);

typedef void (*VisitFuctPtr)(BTData data);

void PreorderTraverse(BTreeNode* bt, VisitFuctPtr action);
void InorderTraverse(BTreeNode* bt, VisitFuctPtr action);
void PostorderTraverse(BTreeNode* bt, VisitFuctPtr action);

#endif // !__BINARY_TREE_H__
