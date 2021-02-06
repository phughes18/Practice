// Largest sum of subarray 
int maxSubArraySum(int a[], int size)
{
    int max_now = INT_MIN;
    int max_here = 0;

    for (int i = 0; i < size; i++)
    {
        max_here = max_here + a[i];
        if (max_now < max_here)
            max_now = max_here;

        if (max_here < 0)
            max_here = 0;
    }
    return max_now;
}

// Reverse an integer
int reverse(int x)
{
    int rev = 0;
    while (x != 0)
    {
        int pop x % 10;
        x /= 10;

        if (rev > INT_MAX/10 || (rev = INT_MAX/10 && pop > 7))
            return 0;

        if (rev < INT_MIN/10 || rev == INT_MIN/10 && pop < -8)
            return 0;
        rev = rev * 10 + pop;
    }
    return rev;
}

// remove element from array by value
 int removeElement(int[] nums, int val)
{
    int i = 0;
    for (int j = 0; j < nums.length; j++)
    {
        if (nums[j] != val)
        {
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
}

// Merge two sorted linked lists
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
    if (l1 == nullptr)
        return l2;
    else if (l2 == nullptr)
        return l1;

    ListNode* mergedHead = nullptr;
    if (l1->val <= l2->val)
    {
        mergedHead = l1;
        l1 = l1->next;
    }
    else
    {
        mergedHead = l2;
        l2 = l2->next;
    }

    ListNode* mergedTail = mergedHead;

    while (l1 != nullptr && l2 != nullptr)
    {
        ListNode* temp = nullptr;
        if (l1->val <= l2->val)
        {
            temp = l1;
            l1 = l1->next;
        }
        else
        {
            temp = l2;
            l2 = l2->next;
        }

        mergedTail->next = temp;
        mergedTail = temp;
    }

    if (head1 != nullptr)
    {
        mergedTail->next = l1;
    }
    else if (l2 != nullptr)
    {
        mergedTail->next = l2;
    }

    return mergedHead;
}

// delete node from linked list by reference key
void deleteNode(Node** head_ref, int key)
{
    Node* temp = *head_ref;
    Node* prev = NULL;

    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next; //changes head
        delete temp; // frees old head
        return;
    }

    // while key is not found
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    // if key isnt present in list
    if(temp == NULL)
        return;

    // unlink node from list
    prev->next = temp->next;
    // free memory
    delete temp;
}



// delete node from linked list by position number
void deleteNode(struct Node **head_ref, int position)
{
    if (*head_ref == NULL)
        return;

    struct Node* temp = *head_ref;

    if (position == 0)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    for (int i = 0; i < position-1; i++)
    {
        temp = temp->next
    }

    if (temp==NULL || temp->next == NULL)
        return;

    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}


// push node to beginning of linked list
void push (Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next =  *head_ref;
    *head_ref = new_node;
}

// insert node after a specific node given by reference key
void insertAfter (Node* prev_node, int new_data)
{
    if (prev_node == NULL)
        return;

    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// insert node at the end of linked list
void insertEnd(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    return;
}

// Reverse linked list
void reverseList(Node** head_ref)
{
    Node* curr = *head_ref;
    Node* temp = NULL
    Node* prev = NULL
    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    *head_ref = prev;
}

// longest common prefix string amongst an array of strings

string longestCommonPrefix(vector<string> &strs)
{
    string result = "";
    if (strs.size() == 0)
        return result;

    result = strs[0];
    for (int i = 0; i<strs.size(); i++)
    {
        for (int j = 0; j <= min(result.length(), strs[i].length()); j++)
        {
            if (j == strs[i].length())
            {
                result = strs[i];
                break;
            }

            if (result[j] != strs[i][j])
            {
                result = result.substr(0, j);
                break;
            }
        }
        return result;
    }
}

// rotate vector certain number of positions
void rotate(vector<int> &vec, int d)
{
    if (d==0)
        return;

    for (int i=0; i<d; i++)
    {
        vec.push_back(vec[0]);

        vec.erase(vec.begin());
    }
}


// merge two sorted arrays
void mergeArrays(int arr1[], int arr2[], int m, int n)
{
    int i = n;
    int j = 0;
    int k = 0;

    while (k < m+n)
    {
        if ((j==n) || i < (m+n) && arr1[i] <= arr2[j])
        {
            arr1[k] = arr1[i];
            k++;
            i++;
        }
        else
        {
            arr1[k] = arr1[j];
            k++;
            j++;
        }
    }
}



int findPairs(int arr[], int size, int target)
{
    int pairs = 0;
    int i = 0;

    int j = size - 1;

    while (i < j)
    {
        if (arr[i] + arr[j] == target)
        {
            while (i < j && arr[i] == arr[i+1])
            {
                i++;
            }
            while (i < j && arr[j] == arr[j-1])
            {
                j--;
            }
            pairs += 1;
            i++;
            j--;
        }
        else if (arr[i] + arr[j] < target)
            i++;
        else
            j--;
    }
    return pairs;
}


// checks if a string is a palindrome
bool checkPalindrome(string str)
{
    int length = str.length();
    for (int i=0; i<length; i++)
    {
        if (str(i) != str(length-i-1))
            return false;
    }
    return true;
}

// prints middle node of linked list
void printMiddleList(struct Node* head)
{
    Node* fast_ptr = head;
    Node* slow_ptr = head;

    if (head != NULL)
    {
        while (fast_ptr != NULL && slow_ptr != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
    }
    cout << slow_ptr->data << endl;
}

// reverses a string in place
void reverseString(string str)
{
    int len = str.length();
    int n = len-1;
    for (i=0; i<len/2; i++)
    {
        swap(str[i], str[n-i]);
    }
}

// removes duplicates from an array
int removeDuplicates(int arr[], int size)
{
    int temp[size];

    int j=0;
    for (int i=0; i<size-1; i++)
    {
        if (arr[i] != arr[i+1])
            temp[j++] =arr[i];
    }

    temp[j++] = arr[n-1];
    for (int i=0; i<j; i++)
        arr[i] = temp[i];
    return j;
}


// removes duplicates from sorted linked list
void removeDuplicateNodes(Node* head)
{
    Node* curr = head;
    Node* next_next;

    if (curr == NULL)
        return;

    while (curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            next_next = curr->next->next;
            free(curr->next);
            curr->next = next_next;
        }

        else
            curr = curr->next;
    }
}

// finds maximum lexicographical substring
string maxLength(string str)
{
    int len = str.length();
    string mx = "";
    for (int i=0; i < len; i++)
    {
        mx = max(mx, str.substr(i));
    }
    return mx;
}

// finds all triplets adding up to given sum
int triplets(int arr[], int val)
{
    int len = arr.length();
    int ans = 0;

    for (int i=0; i < len-2; i++)
    {
        for (int j=0; j<len-1; j++)
        {
            for (int k =0; k < j-1; k++)
            {
                if(arr[i]+arr[j]+arr[k] == val && (i != j != k))
                    ans++;
            }
        }
    }
    return ans;
}


bool checkDelimiters(string expr)
{
    stack<char> s;
    char x;

    for (int i=0; i<expr.length(); i++)
    {
        if (expr[i] == '{' || expr[i]=='(' || expr[i]=='[')
        {
            s.push(expr[i]);
        }

        if (s.empty())
            return false;

        switch (expr[i])
        {
            case '}':
                x=s.top();
                s.pop();
                if (x=='(' || x=='[')
                    return false;
                break;
            case ')':
                x=s.top();
                s.pop();
                if (x=='{' || x=='[')
                    return false;
                break;
            case ']':
                x=s.top();
                s.pop();
                if (x=='{' || x=='(')
                    return false;
                break;
        }
    }
    return(s.empty());
}


// finds duplicates in array

int findDuplicate(int arr[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for (j=1; j<n-1; j++)
        {
            if (arr[i] == arr[j])
                return arr[i];
        }
    }
}

// finds number of words in a string
int numWords(string str)
{
    int w = 0;
    for (int i=0; str[i] != '\n'; i++)
    {
        if (str[i] != ' ')
        {
            w++;
            while(str[i] != ' ')
                i++;
        }
    }
    return w;
}


// finds maximum depth of a binary tree

int maxDepth(Node* root)
{
    if (root==NULL)
        return 0;
    else
    {
        int left_depth = maxDepth(root->left);
        int right_depth = maxDepth(root->right);

        if (left_depth > right_depth)
            return (left_depth + 1);
        else
            return (right_depth + 1);
    }

}



// determines whether two binary trees are identical

bool identical(TreeNode* node1, TreeNode* node2)
{
    if ((node1->data == node2->data) && identical(node1->left, node2->left)
        && identical(node1->right, node2->right))
    {
        return true;
    }
    return false;
}

// inorder traversal of binary tree
void inOrder(Node* root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// preorder traversal of binary tree
void preOrder(Node* root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// postorder traversal of binary tree
void postOrder(Node* root)
{
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data " ";
}

