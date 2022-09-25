#include <iostream>
//����������
struct LinkNode
{
    int val;
    LinkNode *next;
    LinkNode () : val(0), next(nullptr) {}
    LinkNode (int x) : val(x), next(nullptr) {}
    LinkNode (int x, LinkNode *next) : val(x), next(next) {}
};
int LinkLength(LinkNode* head);
class KLinkSolution
{
public:
    LinkNode* reverseKGroup(LinkNode* head, int k)
    {
        //��ʼ����Ҫʹ�õĽڵ�ָ�룬begin:���Ի��Ľڵ㣬end:�Ұ�Ի��Ľڵ��ֱ��ǰ��
        //lastPair:��һ�Խڵ�ӵ���һ�Խڵ���Ǹ��ڵ�
        //lastGroup:��һ��ڵ�ӵ���һ��ڵ���Ǹ��ڵ�
        //newHead:ÿ�Խڵ�Ի�����ǰ��Ľڵ�
        LinkNode* begin, * end, * lastPair, *newHead, *lastGroup;
        begin = end = lastPair = newHead = lastGroup = head;
        //k=2��2���ڵ�һ�飬����Ի�
        if (k == 2) 
        {
            int flag = 0;
            while (begin->next != nullptr) 
            {
                LinkNode* t = begin->next->next;
                begin->next->next = begin;
                newHead = begin->next;
                begin->next = t;
                if (flag != 0) //������һ�����һ��
                {
                    lastGroup->next = newHead;
                }
                else //�����µ�head
                {
                    head = newHead;
                    flag = 1;
                }
                lastGroup = begin;
                begin = t;
            }
        }
        //k>2���������Ԫ�غ��Ұ�Ԫ�ضԻ�
        else if(k > 2) 
        {
            //����һ���ж����飬��Ϊ�����ѭ���Ĵ���
            int n_Group = LinkLength(head) / k;
            for (int i = 0; i < n_Group; i++) 
            {
                begin = end = head;
                for (int j = 0; j < i * k - 1; j++)
                {
                    begin = begin->next;
                }
                if (i > 0) {
                    lastGroup = begin;
                    begin = begin->next;
                }
                end = begin;
                int len = k;
                //����ѭ���Ĵ�����ÿ������Ҫ������pairs����Ŀ
                for (int j = 0; j < k / 2; j++)
                {
                    if (len == 2)
                    {
                        LinkNode* temp = begin->next->next;
                        begin->next->next = begin;
                        newHead = begin->next;
                        begin->next = temp;
                        lastPair->next = newHead;
                    }
                    else
                    {
                        for (int l = 2; l < k - j; l++)
                        {
                            end = end->next;
                        }
                        LinkNode* temp = begin->next;
                        begin->next = end->next->next;
                        end->next->next = temp;
                        newHead = end->next;
                        end->next = begin;
                        if (j > 0) //������һ�Ժ���һ��
                            lastPair->next = newHead;
                        else if (i == 0) //�����µ�head
                            head = newHead;
                        else //�����ϸ���
                            lastGroup->next = newHead;
                        begin = newHead->next;
                        end = newHead;
                        lastPair = newHead;
                        len -= 2;
                    }
                }
            }
        }
        return head;
    }
};
int LinkLength(LinkNode* head) {
    int length = 1;
    LinkNode* p = head;
    while(p->next != nullptr)
    {
        length++;
        p = p->next;
    }
    return length;
}
void ShowLinkList(LinkNode* head) {
    LinkNode* t = head;
    while (t != nullptr) {
        std::cout << t->val << ' ';
        t = t->next;
    }
    std::cout << std::endl;
}
int main(void) {
    KLinkSolution s;
    int n, k;
    LinkNode* head, * rear;
    LinkNode a(1);
    head = rear = &a;
    //����ʱ�����ʼ�����������������У����ڹ۲�
    std::cout << "������˳�������ȣ�";
    std::cin >> n;
    for (int i = 1; i < n; i++) {
        LinkNode* p = nullptr;
        p = new LinkNode;
        p->val = i + 1;
        p->next = nullptr;
        rear->next = p;
        rear = rear->next;
    }
    std::cout << "������ÿ��ĳ���k��";
    std::cin >> k;
    ShowLinkList(s.reverseKGroup(head, k));
    return 0;
}