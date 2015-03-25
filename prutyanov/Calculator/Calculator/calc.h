/**
*   Expression calculator
*
*   @date 11.2014
*
*   @copyright GNU GPL v2.0
*
*   @author Viktor Prutyanov mailto:vitteran@gmail.com 
*/

#include "tree.h"

int GetG0(char *expr, Tree_t *tree);

int GetE(TreeNode_t **node);
int GetT(TreeNode_t **node);
int GetX(TreeNode_t **node);
int GetP(TreeNode_t **node);
int GetN(TreeNode_t **node);

unsigned int pow(unsigned int base, unsigned int power);