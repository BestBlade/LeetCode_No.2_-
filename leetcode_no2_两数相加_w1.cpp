/*-------------------------------------------------------------------------------------------------------------------------------
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。|
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。																|
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。																			|
																																|
示例：																															|
																																|
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)																								|
输出：7 -> 0 -> 8																												|
原因：342 + 465 = 807																											|
																																|
来源：力扣（LeetCode）																											|
链接：https://leetcode-cn.com/problems/add-two-numbers																			|
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。															|
-------------------------------------------------------------------------------------------------------------------------------*/

/*	
*	执行用时：28 ms, 在所有 C++ 提交中击败了94.00%的用户
*	内存消耗：9.3 MB, 在所有 C++ 提交中击败了61.90%的用户	
*/

#include <iostream>

using namespace std;

struct ListNode 
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};



ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) 
{
	ListNode *head = new ListNode(0);								/*	建立一个新节点，将值设为0	*/
	ListNode *result = head;										/*	result为中间运算节点	*/

	ListNode *p = l1;
	ListNode *q = l2;

	int overflow = { 0 };
	int sum = { 0 };

	while (p || q)													/*	判断节点p，q的地址是否为空，为空则表明计算结束，否则继续循环	*/
	{
		int l1_elem = (p) ? p->val : 0;								/*	三目运算符，若p不为空，即(p)的结果为1，则l1_elem就被赋为节点p的值	*/
		int l2_elem = (q) ? q->val : 0;

		sum = l1_elem + l2_elem + overflow;							/*	计算和	*/
		overflow = sum / 10;										/*	计算新的进位	*/

		result->next = new ListNode(sum % 10);						/*	以余数作为新的节点的值，head->next才是输出结果链表的开始，因此不对result->val进行赋值，这样会使操作更加麻烦	*/
		result = result->next;

		if (p)
		{
			p = p->next;											/*	如果p的地址为空，则不再操作，节点p的地址不为空，就移动至下一个节点	*/
		}
		if (q)
		{
			q = q->next;
		}
	}
	if (overflow) result->next = new ListNode(overflow);			/*将overflow的判断单独拿出来，少一个循环，加快运行速度*/

	return head->next;
}

int main()
{

}