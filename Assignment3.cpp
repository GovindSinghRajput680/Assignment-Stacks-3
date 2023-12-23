#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int val){
        this->val = val;
        next = NULL;
    }
};
//Q-1->LEETCODE->682
 int calPoints(vector<string>& v) {
        stack<int> st;
        for(int i =0;i<v.size();i++){
            if(v[i] == "+") {
                int a = st.top();
                st.pop();
                int ans = st.top()+a;
                st.push(a);
                st.push(ans);
            }
            else if(v[i]== "D") st.push(2*st.top());
            else if(v[i]== "C") st.pop();
            else st.push(stoi(v[i]));
        }
        int sum =0;
        while(st.size()) sum+=st.top(),st.pop();
        return sum;
    }
    //Q-2 ->LEETCODE->2487
    ListNode* reverseList(ListNode* head){
        if(head == NULL || head->next == NULL) return head;
        ListNode *pre = NULL,*curr = head,*Next;
        while(curr){
            Next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = Next;
        }
        return pre;
    }
    ListNode* removeNodes(ListNode* head) {
       stack<int> st;
       ListNode *c = new ListNode(-1);
       ListNode *tempc =c;
       ListNode * temp = reverseList(head);
       while(temp){
           while(st.size() && st.top()<=temp->val) st.pop();
           if(st.size() == 0) tempc->next = temp, tempc = temp;
           st.push(temp->val);
           temp = temp->next;
       }
       tempc->next = NULL;
        return reverseList(c->next);
    }
    //Q-3->LEETCODE->85
     int maximalRectangle(vector<vector<char>>& arr) {
        int m = arr.size();
        int n = arr[0].size();
        int ans = 0;
        vector<vector<int>> v(m,vector<int>(n,0));
        for(int j = 0;j<n;j++) if(arr[m-1][j] == '1') v[m-1][j] = 1;
        for(int i = m-2;i>=0;i--){
            stack<int> st;
            vector<int> psi(n,-1);
            for(int j = 0;j<n;j++){
                if(arr[i][j] == '1') v[i][j] = v[i+1][j]+1;
                while(st.size() && v[i][st.top()]>=v[i][j]) st.pop();
                if(st.size()) psi[j] = st.top();
                st.push(j);
            }
            //Next smaller index
            stack<int> sst;
            for(int j = n-1;j>=0;j--){
                while(sst.size() && v[i][sst.top()]>=v[i][j]) sst.pop();
                if(sst.size()) ans = max(ans,v[i][j]*(sst.top()-psi[j]-1));
                else ans = max(ans,v[i][j]*(n-psi[j]-1));
                sst.push(j);
            }
        }
            int i = m-1;
            //for last row
            stack<int> st;
            vector<int> psi(n,-1);
            for(int j = 0;j<n;j++){
                while(st.size() && v[i][st.top()]>=v[i][j]) st.pop();
                if(st.size()) psi[j] = st.top();
                st.push(j);
            }
            //Next smaller index
            stack<int> sst;
            for(int j = n-1;j>=0;j--){
                while(sst.size() && v[i][sst.top()]>=v[i][j]) sst.pop();
                if(sst.size()) ans = max(ans,v[i][j]*(sst.top()-psi[j]-1));
                else ans = max(ans,v[i][j]*(n-psi[j]-1));
                sst.push(j);
            }
           
        return ans;
    }
int main(){


}