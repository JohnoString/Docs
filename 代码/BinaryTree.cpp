# include "BinaryTree.h"

//��ӽڵ�
//keyΪҪ�����ֵ��direction�Ǵ����������뻹�����������룬rootΪ���ĸ��ڵ����
void BinaryTree::AddNode(const ElemType key, int direction, BiTree root)
{
	if (direction == 0)
	{
		//������������
		if (root->left == NULL)
			root->left = new BiNode(key);
		else
			AddNode(key, direction, root->left);
	}
	else if (direction == 1)
	{
		//������������
		if (root->right == NULL)
			root->right = new BiNode(key);
		else
			AddNode(key, direction, root->right);
	}
}

////�������Ľ�������ǰ������ķ�ʽ����������
BiTree BinaryTree::create()
{
	BiTree current = NULL;
	ElemType val;
	cin >> val;//�����ֵ

	if (val == '#')//��ʶ��ǰ����Ϊ�գ�ת����һ�ڵ�
	{
		return NULL;
	}
	else
	{   //�ݹ�Ĵ�����������
		size++;
		current = new BiNode(val);
		current->left = create();
		current->right = create();
		return current;
	}
}

//ɾ��������(private ����)
void BinaryTree::distroy(BiTree root)
{
	if (root)
	{
		distroy(root->left);
		distroy(root->right);
		delete root;
		root = NULL;
		size = 0;
	}
}

//�ݹ�õ����ĸ߶�
int BinaryTree::getHeight(BiTree root)
{
	if (root == NULL)
		return 0;
	int left_height = getHeight(root->left);
	int right_height = getHeight(root->right);
	return (left_height>right_height) ? (left_height + 1) : (right_height + 1);
}

//ǰ�����
void BinaryTree::preOrder(BiTree root)
{
	if (root == NULL)
		return;
	else
	{
		cout << root->data << "  -->  ";     //���ȴ�ӡ���ڵ�
		preOrder(root->left);				 //���ű���������
		preOrder(root->right);				 //���ű���������
	}
}

//�������
void BinaryTree::inOrder(BiTree root)
{
	if (root == NULL)
		return;
	else
	{
		inOrder(root->left);				 //���ȱ���������
		cout << root->data << "  -->  ";     //���Ŵ�ӡ���ڵ�
		inOrder(root->right);				 //���ű���������
	}
}

//�������
void BinaryTree::postOrder(BiTree root)
{
	if (root == NULL)
		return;
	else
	{
		postOrder(root->left);				 //���ȱ���������
		postOrder(root->right);				 //���ű���������
		cout << root->data << "  -->  ";     //���Ŵ�ӡ���ڵ�
	}
}
#pragma endregion


#pragma region
////�������Ľ���
void BinaryTree::Create()
{
	size = 0;
	m_root = create();
}

//ɾ��������
void BinaryTree::distroy()
{
	distroy(m_root);
}

//�ݹ�õ����ĸ߶�
int BinaryTree::getHeight()
{
	return getHeight(m_root);
}

//ǰ�����
void BinaryTree::preOrder()
{
	cout << "ǰ������Ľ�����£�" << endl;
	preOrder(m_root);
	cout << endl;
}

//�������
void BinaryTree::inOrder()
{
	cout << "��������Ľ�����£�" << endl;
	inOrder(m_root);
	cout << endl;
}

//�������
void BinaryTree::postOrder()
{
	cout << "��������Ľ�����£�" << endl;
	postOrder(m_root);
	cout << endl;
}

//��ȡ��С
int BinaryTree::getSize()
{
	//�����Ǵ���ʱ��ֱ�ӽ����˼���
	//Ҳ�������ñ����ķ�ʽ��ȡ�����ڵ���ֵ���ͼ�1
	return size;
}
#pragma endregion