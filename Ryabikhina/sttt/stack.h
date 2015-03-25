#ifndef STACK_H
#define STACK_H

/** \class stack data structure
 *
 * \field count     number of elements in stack                                             \
 * \field size        amount of memory allocated for stack (sizeof int)             | private
 * \field data       array of elements                                                              /
 *
 * \method stack   ctor - constructs an empty stack
 *   \param size     amount of memory allocated for stack (sizeof int)
 * \method push    puts an element into stack
 *   \param num    the number which is going to stack
 * \method pop     deletes element from the ssstack
 *    \returns int     value of the deleted element
 * \method dump   writes the state and parameters of the stack
 * \method is_ok   checks stack's state
 *    \returns  bool  true or false
 * \method top        returns top element
 *    \returns int      top element
 * \method ~stack   deletes stack
 */

class stack
{
    private: /* is available only to us */
        int count; // ���-�� ���������
        int size; //������ ������ ��� ����
        int* data; // ��� ��������

    public://to all
        stack(int size);//������� ������ ��� ����. ��� �� ������
        void push (int num);
        int pop ();
        bool is_ok();
        void dump();
        ~stack();
        int top();
    //protected:
};

#endif // STACK_H
