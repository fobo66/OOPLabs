
using namespace BST;

template<class T>
void Tree<T>::insert(T data)
{
	Node<T>* tmp = new Node<T>;
	tmp->key = data;
	tmp->left = nullptr;
	tmp->right = nullptr;

	if (this->_root == nullptr)
	{
		tmp->parent = nullptr;
		this->_root = tmp;
	}
	else {
		Node<T>* cElem = this->_root;
		Node<T>* parent = nullptr;

		while (cElem != nullptr)
		{
			parent = cElem;
			cElem = (data < cElem->key) ? cElem->left : cElem->right;
		}

		tmp->parent = parent;

		if (data < parent->key)
			parent->left = tmp;
		else
			parent->right = tmp;
	}
}

template<class T>
void Tree<T>::preorderWalk(Node<T>* p)
{
	if (p != nullptr)
	{
		cout << p->key << " ";
		this->preorderWalk(p->left);
		this->preorderWalk(p->right);
	}
}

template<class T>
void Tree<T>::preorderWalk()
{
	cout << "Preorder walk: ";
	this->preorderWalk(this->_root);
	cout << endl;
}

template<class T>
void Tree<T>::postorderWalk(Node<T>* p)
{
	if (p != nullptr) 
	{
		this->postorderWalk(p->left);
		this->postorderWalk(p->right);
		cout << p->key << " ";
	}
}

template<class T>
void Tree<T>::postorderWalk()
{
	cout << "Postorder walk: ";
	this->postorderWalk(this->_root);
	cout << endl;
}

template<class T>
void Tree<T>::inorderWalk(Node<T>* p)
{
	if (p != nullptr)
	{
		this->inorderWalk(p->left);
		cout << p->key << " ";
		this->inorderWalk(p->right);
	}
}

template<class T>
void Tree<T>::inorderWalk()
{
	cout << "Inorder walk: ";
	this->inorderWalk(this->_root);
	cout << endl;
}

template<class T>
Node<T>* Tree<T>::findElem(T val, Node<T>* node)
{
	if (node != nullptr)
	{
		if (val == node->key) return node;

		if (val < node->key)
			return findElem(val, node->left);
		else 
			return findElem(val, node->right);
	}
	else
		return nullptr;
}

template<class T>
void Tree<T>::cleanup(Node<T> * node)
{
	if (node != nullptr)
	{
		cleanup(node->left);
		cleanup(node->right);
		delete node;
	}
}

template<class T>
Node<T>* Tree<T>::findElem(T val)
{
	return this->findElem(val, this->_root);
}

template<class T>
Node<T>* Tree<T>::findSuccessor(T val)
{
	Node<T>* startNode = this->findElem(val);
	Node<T>* parent = startNode;

	startNode = startNode->right;
	while (startNode != nullptr && startNode->left != nullptr)
	{
		parent = startNode;
		startNode = startNode->left;
	}

	return startNode;
}

template<class T>
void Tree<T>::deleteNode(Node<T>* p)
{
	Node<T> *q = nullptr;
	Node<T> *r = nullptr;

	if (p->left == nullptr || p->right == nullptr)
		q = p;
	else 
		q = this->findSuccessor(p->key);

	if (q->left != nullptr)
		r = q->left;
	else 
		r = q->right;

	if (r != nullptr)
		r->p = q->p;

	if (q->p == nullptr)
		this->_root = r;
	else if (q == q->p->left)
		q->p->left = r;
	else
		q->p->right = r;

	if (q != p)
		p->key = q->key;
}

template<class T>
void Tree<T>::show(Node<T>* node, int level)
{
	std::string spacing;
	if (node != nullptr)
	{
		show(node->right, level + 1);
		for (size_t i = 0; i<level; i++)
			spacing += "    ";
		std::cout << spacing + node->key << std::endl;
		show(node->left, level + 1);
	}
}

template<class T>
void Tree<T>::deleteNode(T val)
{
	this->deleteNode(this->findElem(val));
}

template<class T>
int Tree<T>::countLevels(Node<T>* p)
{
	int h1 = 0, h2 = 0;

	if (p == nullptr) return 0;

	if (p->left)
		h1 = countLevels(p->left);


	if (p->right)
		h2 = countLevels(p->right);


	return(max(h1, h2) + 1);
}

template<class T>
int Tree<T>::countLevels()
{
	return this->countLevels(this->_root);
}

template<class T>
int Tree<T>::countNodes(Node<T>* p)
{
	if (p == nullptr)
		return 0;
	else 
		return (countNodes(p->left) + countNodes(p->right) + 1);
}

template<class T>
int Tree<T>::countNodes()
{
	return this->countNodes(this->_root);
}

template<class T>
int Tree<T>::countLeftNodes(Node<T>* p)
{
	if (p == nullptr)
		return 0;
	else 
		return (countLeftNodes(p->left) + countLeftNodes(p->right)) + (p->left != NULL && p->right == NULL) ? 1 : 0;
}

template<class T>
int Tree<T>::countLeftNodes()
{
	return this->countLeftNodes(this->_root);
}

template<class T>
std::ostream & BST::operator<<(std::ostream & stream, const Tree<T> & root)
{
	root.show(root._root, 0);

	return stream;
}
