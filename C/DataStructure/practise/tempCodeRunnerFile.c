Node* Insert(Node* proot, int data)
{
    if (proot == NULL)
    {
        proot = NewNode(data);
        return proot;
    }
    if (data <= proot->data)
    {
        proot->left = Insert(proot->left, data);
    }else{
        proot->right = Insert(proot->right, data);
    }
    return proot;
}