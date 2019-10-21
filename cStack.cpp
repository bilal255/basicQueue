/*
LAST IN FIRST OUT
The nextNode reference of the last node is always null to avoid GARBAGE ACCESS
*/
#include<iostream>
#include"nodeClass.cpp"
using namespace std;

class cStack {
	//The dynamic memory location that is going to serve as the BASE REFERENCE to the whole STACK
protected:
	cNode *topRef;
public:
	/*
	Default Class Construstor
	Using Initializer list to set the topReference as NULL for the empty STACK
	*/
	cStack() : topRef(NULL) {}

	/*
	Parameterized Class Constructor
	Generating a single node stack using pointer Reference to avoid multiple pointer to same node
	*/
	cStack(cNode *&topPtr) : topRef(topPtr) { topRef->nextNode = NULL; topRef = NULL; }

	/*
	Check the BASE REFERENCE to determin whether the STACK is empty or not
	*/
	bool isNotEmpty() const { if (topRef) return true; else return false; }
	bool isEmpty() const { if (topRef) return false; else return true; }

	/*
	Push a node at the end of the STACK using previousLastNode Next Reference to New node
	Returning Reference will allow cascadeability use
	*/
	cStack& push(cNode *&nodeRef) { nodeRef->nextNode = topRef; topRef = nodeRef; nodeRef = NULL; return *this; }

	/*
	To extract the first node element of the STACK
	*/
	cNode* pop() { cNode *nodeRef = topRef; topRef = topRef->nextNode; nodeRef->nextNode = NULL; return nodeRef; }

	//print function to print the whole stack from top to bottom order
	void printStack() const {
		if (!topRef)
			cout << "\nEMPTY DATA STRUCTURE\n";
		else {
			cout << "The elements from TOP to BOTTOM are \n";
			cNode *nodeRef = topRef;
			//print all elements until last node NULL reference is reached
			while (nodeRef) {
				nodeRef->printData();
				cout << "\n";
				nodeRef = nodeRef->nextNode;
			}
		}
	}

	/*
	The default copy constructor gives shallow copy so default constructor is redefined
	Two tracing pointers "sptr(source pointer) , dptr(destination pointer)" are used for assistance
	*/
	cStack(const cStack &src) {
		this->topRef = src.topRef;
		if (src.topRef) {
			cNode *sptr, *dptr;
			dptr = topRef = new cNode(*src.topRef);
			sptr = src.topRef->nextNode;
			while (sptr) {
				dptr = new cNode(*sptr);
				sptr = sptr->nextNode;
				dptr = dptr->nextNode;
			}
		}
	}

	/*
	Defining the assignment operator for the cStack class
	*/
	cStack& operator = (const cStack &src) {
		if (this == &src) { return *this; }
		if (true) { cStack temp; temp.topRef = this->topRef; }
		if (true) { cStack temp = src; topRef = temp.topRef; temp.topRef = NULL; }
		return *this;
	}


	/*
	Default desstructor wouldn't delete the stack allocated on HEAP so the self defined deletes all nodes in STACK
	*/
	~cStack() {
		cNode *nodeRef = topRef;
		while (nodeRef) {
			nodeRef = nodeRef->nextNode;
			delete topRef;
			topRef = nodeRef;
		}
	}

};
#pragma once
Include Irvine32.inc
.data
arr0 byte "if you have bsc enter 1 otherwise 0",0
arr byte "Enter your age:",0
arr1 byte "The candidate is eligible",0
arr2 byte "The candidate isn't  eligible",0
age dword ?
qual dword ?

.code
main proc

mov edx,offset arr
call writestring
call crlf
mov eax,0
call readint
cmp eax,22

je L3
jg L3
jl L3

L1:
 
    mov edx,offset arr1
	call writestring
	jmp skip
L2:

    mov edx,offset arr1
	call writestring
	jmp skip
L3:
    mov edx,offset arr0
	call writestring
	call readint
	mov qual,eax
	cmp eax,1
	je L1
	jl skip
	jg skip

skip:
	mov edx,offset arr2
	call writeint 

call readint
exit
main endp
end main
