template <class Object>
Stack<Object>::Stack(){
	topOfStack = NULL;
}

template <class Object>
Stack<Object>::~Stack(){
	makeEmpty();
}

template <class Object>
bool Stack<Object>::isEmpty() const{
	return topOfStack == NULL;
}

template <class Object>
bool Stack<Object>::isFull() const{
	return false;
}

template <class Object>
void Stack<Object>::makeEmpty(){
	while(!isEmpty()){
		pop();
	}	
}

template <class Object>
void Stack<Object>::pop(){
	if(isEmpty()){
		std::cout << "Stos jest pusty" << std::endl;
	}
	ListNode* temp = topOfStack;
	topOfStack = topOfStack->next;
	delete temp;
}

template <class Object>
void Stack<Object>::push(const Object &x){
	topOfStack = new ListNode(x, topOfStack);
}

template <class Object>
const Object & Stack<Object>::top() const{
	if(isEmpty()){
		std::cout << "Stos jest pusty" << std::endl;
	}
	return topOfStack->element;
}

template <class Object>
Object Stack<Object>::topAndPop(){
	Object topItem = top();
	pop();
	return topItem;
}

template <class Object>
const Stack<Object> & Stack<Object>::operator=( const Stack & rhs ){
	if(this != &rhs){
		makeEmpty();
		if(rhs.isEmpty()){
			return *this;
		}
		ListNode *rptr = rhs.topOfStack;
		ListNode *ptr = new ListNode(rptr->element);
		topOfStack = ptr;
		for(rptr=rptr->next; rptr!=NULL; rptr=rptr->next){
			ptr = ptr->next = new ListNode(rptr->element);
		}
	}
	return *this;	
}
















